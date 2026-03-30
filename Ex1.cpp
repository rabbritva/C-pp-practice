#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

const short N = 7;
void sorted(int*);
void show(int*, int);
void concat(int mas[], int*, int*, int);

int main(){
	system("chcp 1251 > nul");
	srand(time(0));
	int m1[N], m2[N];
	for(unsigned i = 0; i<N; i++)  {m1[i] = rand()%101; m2[i] = rand()%11;}
	int* p1{m1}, * p2{m2};
	show(p1, N);
	sorted(p1);
	show(p1, N); cout<<endl;
	show(p2, N);
	sorted(p2);
	show(p2, N); cout<<endl;
	int rmas[2*N];
	concat(rmas, p1, p2, 2*N);
	show(rmas, 2*N);
}

void show(int* ptr, int k){
	for (unsigned i = 0; i < k; i++){
		printf("%2i |", ptr[i]);
	}
	cout<<endl;
}

void sorted(int* mas){
	unsigned i,j,k;
	for(i=0; i<N; i++){
		for(j=N-1; j>i; j--){
			if(mas[j]<mas[j-1]){
				k = mas[j-1];
//				cout<<"j = "<<j<<endl;
//				printf("After: k = %i, mas[j-1] = %i, mas[j] = %i\n", k, mas[j-1], mas[j]);
				mas[j-1] = mas[j];
				mas[j] = k;
//				printf("Before: k = %i, mas[j-1] = %i, mas[j] = %i\n", k, mas[j-1], mas[j]);
			}
		}
	}
//	cout<<"After sorted: ";
//	for(i = 0; i < N; i++){
//		cout<<mas[i]<<" ";
//	}
}

void concat(int rmas[], int* mas1, int* mas2, int k){
	for(unsigned i = 0; i<k; i++){
		if (i<k/2){
			rmas[i] = mas1[i];
		}
		else{
			rmas[i] = mas2[i%(k/2)];
		}
	}
}
