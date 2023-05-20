//1. Сортировка вставками
//0. Сортировка Шелла
//2. Пирамидальная сортировка*

#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;




struct stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;
    void operator+=(const stats& rhs)
    {
        comparison_count += rhs.comparison_count;
        copy_count += rhs.copy_count;
    }
};


stats insert_sort(vector<int>& arr) {
    int n = arr.size();
    stats res;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        res.copy_count++;
        res.comparison_count++;
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            res.copy_count++;
            j--;
            res.comparison_count++;
        }
        arr[j + 1] = key;
        res.copy_count++;
    }
    return res;
}


stats shell_sort(vector<int>& arr) {
    int n = arr.size();
    stats res;
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int tmp = arr[i];
            res.copy_count++;
            res.comparison_count++;
            int j = i;
            while (j >= gap && arr[j - gap] > tmp) {
                arr[j] = arr[j - gap];
                res.copy_count++;
                j -= gap;
                res.comparison_count++;
            }
            arr[j] = tmp;
            res.copy_count++;
        }
        gap /= 2;
    }
    return res;
}
