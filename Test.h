#pragma once
#include "Sorts.h"

size_t lcg() 
{
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

void next() {
	cout << "\n\nPress any key to continue";
	_getch();
}

void create_random(vector<int>& arr, int n) 
{
	for (int i = 0; i < n; i++) { arr.push_back(lcg()); }
}


//random
void test_random_insert_sort(int n) 
{
	stats res;
	for (int i = 0; i < 100; i++) 
	{
		vector<int>arr;
		create_random(arr, n);
		res+=insert_sort(arr);
	}
	cout << n << "  - Number of comparisons: " << res.comparison_count / 100 << "\tNumber of copying objects: " << res.copy_count / 100;
}

void test_random_shell_sort(int n) {
	stats res;
	for (int i = 0; i < 100; i++) {
		vector<int>arr;
		create_random(arr, n);
		res+=shell_sort(arr);
	}
	cout << n << "  - Number of comparisons: " << res.comparison_count / 100 << "\tNumber of copying objects: " << res.copy_count / 100;
}


void test_random() {
	system("cls");
	cout << "Test Insert sort:" << endl;
	for (int i = 1000; i <= 10000; i += 1000) {
		test_random_insert_sort(i);
		cout << endl;
	}
	test_random_insert_sort(25000);
	cout << endl;
	test_random_insert_sort(50000);
	cout << endl;
	test_random_insert_sort(100000);
	cout << endl;
	
	cout << "Test Shell sort:" << endl;
	for (int i = 1000; i <= 10000; i += 1000) {
		test_random_shell_sort(i);
		cout << endl;
	}
	test_random_shell_sort(25000);
	cout << endl;
	test_random_shell_sort(50000);
	cout << endl;
	test_random_shell_sort(100000);
	cout << endl;
	next();
}

//sorted array
void test_sorted_insert(int n) {
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		arr.push_back(i);
	}
	stats res;
	res+=insert_sort(arr);
	cout << n << " - Number of comparisons: " << res.comparison_count << "\tNumber of copying objects: " << res.copy_count;
}

void test_sorted_shell(int n) {
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		arr.push_back(i);
	}
	stats result;
	result+=shell_sort(arr);
	cout << n << " - Number of comparisons: " << result.comparison_count << "\tNumber of copying objects: " << result.copy_count;
}

void test_sorted_array() {
	system("cls");
	cout << "Test sorted array (Insert Sort): " << endl;
	for (int i = 1000; i <= 10000; i += 1000) {
		test_sorted_insert(i);
		cout << endl;
	}
	test_sorted_insert(25000);
	cout << endl;
	test_sorted_insert(50000);
	cout << endl;
	test_sorted_insert(100000);
	cout << "\n\n";

	cout << "Test sorted array (Shell Sort): " << endl;
	for (int i = 1000; i <= 10000; i += 1000) {
		test_sorted_shell(i);
		cout << endl;
	}
	test_sorted_shell(25000);
	cout << endl;
	test_sorted_shell(50000);
	cout << endl;
	test_sorted_shell(100000);
	cout << "\n\n";
	next();
}

//reverse sorted array
void test_reverse_insert_sort(int n) {
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		arr.push_back(n - i);
	}
	stats result;
	result+=insert_sort(arr);
	cout << n << " - Number of comparisons: " << result.comparison_count << "\t   Number of copying objects: " << result.copy_count;
}
void test_reverse_shell_sort(int n) {
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		arr.push_back(n - i);
	}
	stats result;
    result+=shell_sort(arr);
	cout << n << " - Number of comparisons: " << result.comparison_count << "\t   Number of copying objects: " << result.copy_count;
}

void test_reverse_sorted_array() {
	system("cls");
	cout << "Test reverse sorted array (Insert Sort): " << endl;
	for (int i = 1000; i <= 10000; i += 1000) {
		test_reverse_insert_sort(i);
		cout << endl;
	}
	test_reverse_insert_sort(25000);
	cout << endl;
	test_reverse_insert_sort(50000);
	cout << endl;
	test_reverse_insert_sort(100000);
	cout << "\n\n";

	cout << "Test reverse sorted array  (Shell Sort): " << endl;
	for (int i = 1000; i <= 10000; i += 1000) {
		test_reverse_shell_sort(i);
		cout << endl;
	}
	test_reverse_shell_sort(25000);
	cout << endl;
	test_reverse_shell_sort(50000);
	cout << endl;
	test_reverse_shell_sort(100000);
	cout << "\n\n";
	next();
}