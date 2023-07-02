#include<iostream>
#include<fstream>
#include <string>;
#include "Header.h";
#include<conio.h>
using namespace std;

void helper(int* arr_int, string* arr_str, string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		arr_str[i] = str.substr(i, str.length() - i);
		arr_int[i] = i;
	}

	for (int i = 0; i < str.length() - 1; i++)
	{
		for (int j = i + 1; j < str.length(); j++)
		{
			if (arr_str[i] > arr_str[j])
			{
				swap(arr_str[i], arr_str[j]);
				swap(arr_int[i], arr_int[j]);
			}
		}
	}
}


ArrSuf::ArrSuf(string str)
{
	this->str = str;
	this->arr_size = str.length();
	string* arr_str = new string[arr_size];
	int* arr_int = new int[arr_size];
	helper(arr_int, arr_str, str);

	this->arrSuf_int = arr_int;
	this->arrSuf_str = arr_str;

}

int* ArrSuf::ArrSuf_get()
{
	return arrSuf_int;
}

string ArrSuf::Pref(int a, int b)
{
	string pref = "", suf1 = str.substr(a, str.length() - a), suf2 = str.substr(b, str.length() - b);
	int  size = min(suf1.length(), suf2.length());
	for (int i = 0; i < size; i++)
	{
		if (suf1[i] == suf2[i]) pref += suf1[i];
		else break;
	}

	return pref;
}

string ArrSuf::Shift()
{
	string str1;
	str1 = arrSuf_str[0] + str.substr(0, str.length() - arrSuf_str[0].length());
	return str1;
}

void ArrSuf::get_suf(int size, ArrSuf a)
{
	int* suf_int = new int[size];
	suf_int = a.ArrSuf_get();

	for (int i = 0; i < size; i++)
	{
		cout << suf_int[i] << ' ';
	}
	cout << endl;
}

void ArrSuf::get_shift(ArrSuf a)
{
	string str;
	str = a.Shift();
	cout << str << endl;
}

void ArrSuf::get_MaxPref(ArrSuf a)
{
	int pos1, pos2;
	string pref;
	cout << "Введите номера элементов строки, с которых попробуем найти наибольший общий префикс: ";
	cin >> pos1 >> pos2;
	pref = a.Pref(pos1, pos2);
	cout << pref << endl;
}

void fileInput(const string& fileName)
{
	ifstream in;
	in.open(fileName);
	if (in.is_open())
	{
		string str;
		in >> str;
		cout << "Строка:" << str << endl;
		ArrSuf a(str);
		a.get_suf(str.length(), a);
		a.get_shift(a);
		string pref;
		pref = a.Pref(0, 6);
		cout << pref << endl;
	}
}