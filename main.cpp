#include <iostream>
#include "Test.h"


using namespace std;


void print(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void sort() {
	system("cls");
	int n = 5;
	cout << "Insert sort\n\n";
	vector<int> arr;
	cout << "Source array:\n";
	create_random(arr, n);
	print(arr);
	insert_sort(arr);
	cout << "Sorted array:\n";
	print(arr);

	cout << "\n\nShell sort\n\n";
	vector<int> arr2;
	cout << "Source array:\n";
	create_random(arr2, n);
	print(arr2);
	shell_sort(arr2);
	cout << "Sorted array:\n";
	print(arr2);
	next();
}
int menu() {
	int key;
	while (true) {
		system("cls");
		cout << "Choose one's point of menu:\n";
		cout << "\n   1   - Test random arrays ";
		cout << "\n   2   - Test sorted arrays";
		cout << "\n   3   - Test reverse sorted array";
		cout << "\n   4   - Check sort";
		cout << "\n [esc] - Exit ";
		key = _getch();
		if (key == 27 || key == 49 || key == 50 || key == 51 || key == 52) { return key; }
	}
}



int main() {
	setlocale(LC_ALL, "ru");
	system("cls");
	while (main)
	{
		int key = menu();
		switch (key)
		{
		case 49:
			test_random();
			break;
		case 50:
			test_sorted_array();
			break;
		case 51:
			test_reverse_sorted_array();
			break;
		case 52:
			sort();
			break;
		case 27:
			return 0;
		}
	}
}