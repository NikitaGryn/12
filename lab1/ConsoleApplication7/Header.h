#pragma once
#include <iostream>
#include <Windows.h>
#include<string>;
#include<conio.h>
#include<fstream>
using namespace std;

class ArrSuf
{
private:
	string str;
	int* arrSuf_int;
	string* arrSuf_str;
	int arr_size;
public:
	ArrSuf(string str);
	int* ArrSuf_get();
	string Pref(int a, int b);
	string Shift();
	void get_suf(int size, ArrSuf a);
	void get_shift(ArrSuf a);
	void get_MaxPref(ArrSuf a);

};
void fileInput(const string& fileName);

