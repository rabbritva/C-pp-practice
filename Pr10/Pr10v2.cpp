#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;

const int SIZE = 20;
const int SIZE_STRUCT = 6;
enum sex { male, femal };
const char sex_names[2][6] = { "male", "femal" };
struct tdata {
	short day;
	short month;
	short year;
};
struct questionnaire {
	char name[15];
	sex pol;
	tdata birthd;
	short height;
};

void display(questionnaire* arr, short size) {
	//Функция отображающая полный список
	printf("\n*\t*\t*\t*\t*\nDISPLAY:\n");
	for (short t = 0; t < size; t++) {
		printf("# %i\nName: %s\nSex: %s\nBirthday: %i.%i.%i\nHieght: %i\n*\t*\t*\n",
			t + 1, arr[t].name, sex_names[arr[t].pol], arr[t].birthd.day,
			arr[t].birthd.month, arr[t].birthd.year, arr[t].height);
	}
	printf("*\t*\t*\t*\t*\n");
}

void mean_height(questionnaire* arr, short size, const char* pol) {
	//Функция отображающая среднее значение роста из списка
	short mh = 0, c = 0;
	for (short i = 0; i < size; i++) {
		if (strcmp(sex_names[arr[i].pol], pol) == 0) {
			mh += arr[i].height;
			c++;
		}
	}
	if (c < 1) c++;
	mh /= c;
	printf("Mean height %s: %i\n", pol, mh);
}

void show(questionnaire* student) {
	//Функция отображающая человека по индексу из списка
	printf("\n*\t*\t*\t*\t*\nSHOW:\n");
	printf("Name: %s\nSex: %s\nBirthday: %i.%i.%i\nHieght: %i\n",
		student->name, sex_names[student->pol], student->birthd.day,
		student->birthd.month, student->birthd.year, student->height);
	printf("*\t*\t*\t*\t*\n");
}

void show_name(questionnaire* arr, short size, const char* name) {
	//Функция отображающая информацию о человеке из списка по имени
	printf("\n*\t*\t*\t*\t*\nSHOW_NAME: %s\n", name);
	for (short t = 0; t < size; t++) {
		if (strcmp(arr[t].name, name) == 0) {
			printf("№ %i\nName: %s\nSex: %s\nBirthday: %i.%i.%i\nHieght: %i\n*\t*\t*\n",
				t + 1, arr[t].name, sex_names[arr[t].pol], arr[t].birthd.day,
				arr[t].birthd.month, arr[t].birthd.year, arr[t].height);
			break;
		}
		else if (t == size - 1 && strcmp(arr[t].name, name) != 0) printf("Данного человека нет в списке\n");
	}
	printf("*\t*\t*\t*\t*\n");
}


void sorter(questionnaire* arr, short size, int (*f)(questionnaire* x1, questionnaire* x2), bool reverse);

int bool_height(questionnaire* x1, questionnaire* x2) {
	if (x1->height < x2->height) return 1;
	return 0;
}
int bool_lex(questionnaire* x1, questionnaire* x2) {
	if (strcmp(x1->name, x2->name) < 0) return 1;
	return 0;
}


int replace(questionnaire* student);
char replace_menu();
void replace_name(questionnaire* student);
void replace_sex(questionnaire* student);
void replace_date(questionnaire* student);
void replace_date_day(questionnaire* student);
void replace_date_month(questionnaire* student);
void replace_date_year(questionnaire* student);
void replace_date_all(questionnaire* student);
void replace_height(questionnaire* student);

questionnaire* find_my(questionnaire* arr, short size, short& count, int (*f)(questionnaire* x), bool reverse);
int bool_april_birthded(questionnaire* x) {
	if (x->birthd.month == 4) return 1;
	return 0;
}

void file_print(string filename);
questionnaire* file_read(string filename, short& size);
questionnaire split_init(string str, char del);
void binary_write(string filename, questionnaire* arr, short size);
questionnaire* binary_read(string filename, short& size);

questionnaire* init() {
	questionnaire* mas = new questionnaire[SIZE];
	mas[0] = { "Elza", femal, {5, 5, 2005}, 165 };
	mas[1] = { "Elena", femal, {2, 7, 2002}, 163 };
	mas[2] = { "Olga", femal, {10, 11, 2001}, 158 };
	mas[3] = { "Vlada", femal, {15, 4, 2005}, 166 };
	mas[4] = { "Katerina", femal, {9, 12, 2004}, 170 };
	mas[5] = { "Eliza", femal, {28, 9, 2004}, 165 };
	mas[6] = { "Sofia", femal, {6, 6, 2007}, 163 };
	mas[7] = { "Natalia", femal, {1, 1, 2001}, 161 };
	mas[8] = { "Maria", femal, {13, 3, 2003}, 153 };
	mas[9] = { "Zirilla", femal, {7, 7, 2007}, 170 };
	mas[10] = { "Karolina", femal, {8, 8, 2008}, 168 };
	mas[11] = { "Marina", femal, {11, 11, 2011}, 161 };
	mas[12] = { "Alina", femal, {16, 4, 2004}, 165 };
	mas[13] = { "Irina", femal, {5, 5, 2005}, 165 };
	mas[14] = { "Samira", femal, {23, 2, 2009}, 165 };
	mas[15] = { "Sveta", femal, {5, 4, 2007}, 167 };
	mas[16] = { "Victoria", femal, {28, 2, 2007}, 170 };
	mas[17] = { "Tatiana", femal, {31, 5, 2005}, 170 };
	mas[18] = { "Oksana", femal, {17, 7, 2005}, 165 };
	mas[19] = { "Diana", femal, {1, 9, 2007}, 172 };
	return mas;
}

int main() {
	setlocale(LC_ALL, "");
	string filename = "list.txt";
	string filenameb = "binary.txt";
	file_print(filename); //Отображение данных файла

	questionnaire* data2;
	short size;
	data2 = file_read(filename, size); //Считывание данных из файла
	display(data2, size);
	binary_write(filenameb, data2, size); //Бинарная запись структуры в файл
	delete[] data2;

	questionnaire* arr; //Создаём новый массив структур для проверки функции чтения бин. файлов
	size = 0;
	arr = binary_read(filenameb, size); //Чтение бин. файла
	display(arr, size); //Результат
	delete[] arr;

	return 0;
}

questionnaire* binary_read(string filename, short& size) {
	fstream file;
	file.open(filename, ios::in | ios::binary);
	questionnaire* arr = nullptr;
	if (file.is_open()) {
		printf("\nReading binary file %s\n", filename.c_str());
		file.read((char*)&size, sizeof(size));
		arr = new questionnaire[size];
		file.read((char*)arr, sizeof(questionnaire) * size);
		file.close();
	}
	else printf("\nFile not founded\n");
	return arr;
}
void binary_write(string filename, questionnaire* arr, short size) {
	fstream file;
	file.open(filename, ios::out | ios::binary | ios::trunc);
	if (file.is_open()) {
		printf("\nWriting binary file %s\n", filename.c_str());
		file.write((char*)&size, sizeof(size));
		file.write((char*)arr, sizeof(arr[0]) * size);
		file.close();
	}
	else printf("\nFile not founded\n");
}

short count_string(fstream& file) {
	//Считаем количество записей в файле
	string str;
	short count = 0;
	while (getline(file, str)) {
		count++;
	}
	file.clear(); //что-то там с какими-то битами состояния; ф-ия их сбрасывает
	file.seekg(0, ios::beg); //ios::beg - положения отсчета нового индекса коретки. Аналогично seek
	return count;
}
questionnaire split_init(string str, char del) {
	/*Сплитуем строку с данными по заданному разделителю*/
	const char* ptr = str.c_str();
	char mas[SIZE_STRUCT][SIZE] = { "" };
	for (short i = 0; *ptr; ptr++) {
		if (*ptr == del) {
			i++;
		}
		else {
			mas[i][strlen(mas[i])] += *ptr;
		}
	}
	questionnaire student;
	strcpy_s(student.name, mas[0]);
	student.pol = (atoi(mas[1]) == 0) ? male : femal;
	student.birthd.day = atoi(mas[2]);
	student.birthd.month = atoi(mas[3]);
	student.birthd.year = atoi(mas[4]);
	student.height = atoi(mas[5]);

	return student;
}
questionnaire* file_read(string filename, short& size) {
	/*Считываем данные из файла*/
	printf("\nReading data from file %s\n", filename.c_str());
	string str;
	fstream file; file.open(filename);
	questionnaire* arr = nullptr;
	if (file.is_open()) {
		size = count_string(file);

		arr = new questionnaire[size];

		for (short i = 0; i < size; i++) {
			getline(file, str);
			arr[i] = split_init(str, ' ');
		}

		file.close();
	}
	else printf("\nFile not founded\n");
	return arr;
}
void file_print(string filename) {
	/*Смотрим содержимое файла построчно*/
	printf("\nRead file %s:\n", filename.c_str());
	fstream file; file.open(filename);
	if (file.is_open()) {
		string str;
		while (!file.eof()) {
			getline(file, str);
			cout << str << endl;
		}
	}
	else printf("\nFile not founded\n");
	file.close();
}

void sorter(questionnaire* arr, short size, int (*f)(questionnaire* x1, questionnaire* x2), bool reverse) {
	questionnaire temp;
	for (short i = 0; i < size; i++) {
		for (short j = 0; j < size - 1 - i; j++) {
			if (reverse ? !f(&arr[j + 1], &arr[j]) : f(&arr[j + 1], &arr[j])) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int replace(questionnaire* student) {
	char ch;
	cout << "Replace for " << student->name << endl;
	show(student);
	for (;;) {
		ch = replace_menu();
		switch (ch) {
		case 'n': replace_name(student);
			break;
		case 's': replace_sex(student);
			break;
		case 'd': replace_date(student);
			break;
		case 'h': replace_height(student);
			break;
		case 'q': show(student);
			return 0;
		}
	}
}
char replace_menu() {
	char ch;
	cout << "\nChoise struct to replace:" << endl;
	cout << "(N)ame (S)ex (D)ate of birthd (H)eight (Q)uit\n" << endl;
	do {
		cout << "Input comand: "; cin >> ch;
	} while (!strchr("nsdhq", tolower(ch)));
	return ch;
}
void replace_height(questionnaire* student) {
	short h;
	cout << "Input new height: "; cin >> h;
	student->height = h;
}
void replace_date(questionnaire* student) {
	printf("\nBirthday now: %i.%i.%i", student->birthd.day, student->birthd.month, student->birthd.year);
	char ch;
	cout << "\nInput key to replace:\n(D)ay (M)onth (Y)ear (A)ll (Q)uit\n";
	do {
		cout << "Input key: "; cin >> ch;
	} while (!strchr("dmyaq", tolower(ch)));
	switch (ch) {
	case 'd': replace_date_day(student);
		break;
	case 'm': replace_date_month(student);
		break;
	case 'y': replace_date_year(student);
		break;
	case 'a': replace_date_all(student);
		break;
	case 'q': break;
	}
}
void replace_date_all(questionnaire* student) {
	replace_date_day(student);
	replace_date_month(student);
	replace_date_year(student);
}
void replace_date_year(questionnaire* student) {
	short year;
	cout << "\nInput new month: "; cin >> year;
	student->birthd.year = year;
}
void replace_date_month(questionnaire* student) {
	short month;
	cout << "\nInput new month: "; cin >> month;
	student->birthd.month = month;
}
void replace_date_day(questionnaire* student) {
	short day;
	cout << "\nInput new day: "; cin >> day;
	student->birthd.day = day;
}
void replace_sex(questionnaire* student) {
	sex s = student->pol;
	printf("\nSex now: %s", sex_names[s]);
	if (s == male) s = femal;
	else s = male;
	student->pol = s;
	printf("\nSex new: %s", sex_names[s]);
}
void replace_name(questionnaire* student) {
	char name[15];
	cout << "\nInput new name: "; cin >> name;
	strcpy_s(student->name, sizeof(student->name), name);
}

questionnaire* find_my(questionnaire* arr, short size, short& count, int (*f)(questionnaire* x), bool reverse) {
	short* mas = new short[size];
	count = 0;
	for (short x = 0; x < size; x++) mas[x] = -1;

	for (short x = 0; x < size; x++) {
		if (reverse ? !f(&arr[x]) : f(&arr[x])) {
			mas[x] = x;
			count++;
		}
	}

	questionnaire* r_mas = new questionnaire[count];
	for (short x = 0, y = 0; x < size; x++) {
		if (mas[x] >= 0) {
			r_mas[y] = arr[x];
			y++;
		}
	}
	delete[] mas;

	return r_mas;
}