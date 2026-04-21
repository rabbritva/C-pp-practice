#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

const short N = 7;
const short M = 5;

void sorted(int*, short);
void show(int*, short);
int* concat(int*, short, int*, short, short&);

int main() {
	system("chcp 1251 > nul");
	srand(time(0));
	int m1[N], m2[M];
	for (unsigned i = 0; i < N; i++) m1[i] = rand() % 101; 
	for (unsigned i = 0; i < M; i ++) m2[i] = rand() % 11;

	int* p1{ m1 }, * p2{ m2 };
	show(p1, N);
	sorted(p1, N);
	show(p1, N); cout << endl;
	show(p2, M);
	sorted(p2, M);
	show(p2, M); cout << endl;
	short r;
	int* rmas = concat(p1, N, p2, M, r);
	show(rmas, r);
}

void show(int* ptr, short k){
	for (unsigned i = 0; i < k; i++) {
		printf("%2i |", ptr[i]);
	}
	cout << endl;
}

void sorted(int* mas, short x) {
	unsigned i, j, k;
	for (i = 0; i < x; i++) {
		for (j = x - 1; j > i; j--) {
			if (mas[j] < mas[j - 1]) {
				k = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = k;
			}
		}
	}
}

int* concat(int* mas1, short a, int* mas2, short b, short& r) {
	r = a + b;
	int* rmas = new int[r];
	for (short x = 0; x < a; x++) {
		rmas[x] = mas1[x];
	}
	for (short x = 0; x < b; x++) {
		rmas[x + a] = mas2[x];
	}
	return rmas;
}
