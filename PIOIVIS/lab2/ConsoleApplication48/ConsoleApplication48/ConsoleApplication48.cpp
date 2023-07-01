#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct UnorderedSet {
	set<string> set;
};

void building(UnorderedSet& myset, int n) {
	vector<string> elements(myset.set.begin(), myset.set.end());
	sort(elements.begin(), elements.end());
	do {
		for (int i = 0; i < n; i++) {
			cout << elements[i] << "->";
		}
		cout << "end" << endl;
	} while (next_permutation(elements.begin(), elements.end()));
}

void creating(UnorderedSet& myset) {
	string element;
	cout << "Enter elements (enter 'q' to stop):\n";
	while (cin >> element && element != "q") {
		myset.set.insert(element);
	}
}

void building_file(set<string> myset, int n) {
	vector<string> elements(myset.begin(), myset.end());
	sort(elements.begin(), elements.end());
	do {
		for (int i = 0; i < n; i++) {
			cout << elements[i] << "->";
		}
		cout << "end" << endl;
	} while (next_permutation(elements.begin(), elements.end()));
}

void read(const string& fileName)
{
	ifstream inf(fileName);
	set<string> file;
	if (inf.is_open()) {
		int n;
		inf >> n;
		inf.ignore();
		string line;
		getline(inf, line);
		cout << "Входные данные:" << endl << n << endl << line << endl << "Выходные данные:" << endl;
		istringstream iss(line);
		string word;
		while (iss >> word) {
			file.insert(word);
		}
		building_file(file, n);
		inf.close();
	}
	else {
		cout << "Error opening file " << fileName << endl;
	}
}
void testcase() {
	cout << "Test 1" << endl;
	read("Test1.txt");
	cout << "Test 2" << endl;
	read("Test2.txt");
	cout << "Test 3" << endl;
	read("Test3.txt");
	cout << "Test 4" << endl;
	read("Test4.txt");
	cout << "Test 5" << endl;
	read("Test5.txt");
}

int main() {
	setlocale(LC_ALL, "rus");
	testcase();
	while (true) {
		UnorderedSet myset;
		creating(myset);
		int n;
		cout << "Enter permutation size: ";
		cin >> n;
		building(myset, n);
	}
	return 0;
}