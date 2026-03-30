#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
/*Дана строка. Определить количсетво слов, равных самому короткому слову в строке.*/

void word_len(const char*, int*);
int delimetr(const char* symbol);

int main(){
	system("chcp 1251>null");
	string str;
	cout<<"Введите вашу строку: "<<endl;
	getline(cin, str);
	int len = str.size();
	int mas[len];
	const char* p_str = str.c_str();
	for(short x = 0; x<len; x++){
		mas[x]=0;
	}
	word_len(p_str, mas);
	
	cout<<endl<<"Длины слов: {";
	for(short x = 0; x<len; x++){
		if(mas[x+1]==0){
			cout<<mas[x]<<"}";
			break;
		}
		else if(mas[x]!=-1){
			cout<<mas[x]<<"; ";
		}
	} 
	cout<<endl;
	
	int res = mas[0], j = 0;
	for(short i = 0; i<len; i++){
		if (res==mas[i] && mas[i]>0){
			j++;
		}
		else if(res>mas[i] && mas[i]>0){
			res = mas[i];
			j=1;
		}
	}
	cout<<"\nКолиечство слов, равных самому короткому в строке: "<<j;	
}
int delimetr(const char symbol){
	const char delim[] = {',','.', '!', '?', ':', ';', ' '};
	for(auto& el : delim){
		if(el == symbol){
			return 1;
		}
	}
	return 0;
}
//Я вас любил... Любовь, ещё быть может, в моей душе угалса не совсем!
void word_len(const char* str, int* mas){
	for(int x = 0, i = 0, k = 0; str[x];){
		
		if (delimetr(*str)==1){
			i++;
			mas[i] = -1;
			k = 0;
		}
		else{
			k++;
			mas[i] = k;
		}
		str++;
	}
}

