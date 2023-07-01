#include "Header.h";
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "test1:" << endl;
	fileInput("test1.txt");
	cout << "test2:" << endl;
	fileInput("test2.txt");
	cout << "test3:" << endl;
	fileInput("test3.txt");
	cout << "test4:" << endl;
	fileInput("test4.txt");
	cout << "test5:" << endl;
	fileInput("test5.txt");
	bool check = true;
	while (check)
	{
		cout << "Введите строку: ";
		string str;
		cin >> str;
		ArrSuf a(str);
		cout << "Выберите действие: \n	1. Найти суффиксный массив строки \n	2. Найти минимальный циклический сдвиг \n	3. Найти наибольший общий префикс двух подстрок \n	4. Выйти из программы: ";
		int choose;
		cin >> choose;

		switch (choose)
		{
		case 1:
			a.get_suf(str.length(), a);
			break;
		case 2:
			a.get_shift(a);
			break;
		case 3:
			a.get_MaxPref(a);
			break;
		case 4:
			check = !check;
			break;

		}
	}

}