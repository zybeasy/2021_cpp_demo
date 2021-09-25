#include <iostream>

#include "sort_test.h"

using namespace std;

void test_quick_sort() {
    int data[] = {10, 10, 20, 30, 7, 8, 9, 10};
    quick_sort(data, 0, sizeof(data)/sizeof(int)-1);

    for(int i=0; i<sizeof(data)/sizeof(int); ++i)
        cout << data[i] << " ";
    cout << endl;

    int data2[] = {10, 10, 10, 10, 70, 8, 9, 10};
    quick_sort(data2, 0, sizeof(data)/sizeof(int)-1);

    for(int i=0; i<sizeof(data2)/sizeof(int); ++i)
        cout << data2[i] << " ";
    cout << endl;

    cout << "==================" << endl;
}

void test_quick_sort2() {
    int data[] = {10, 10, 20, 30, 7, 8, 9, 10};
    quick_sort2(data, 0, sizeof(data)/sizeof(int)-1);

    for(int i=0; i<sizeof(data)/sizeof(int); ++i)
        cout << data[i] << " ";
    cout << endl;

    int data2[] = {10, 10, 10, 10, 70, 8, 9, 10};
    quick_sort2(data2, 0, sizeof(data2)/sizeof(int)-1);

    for(int i=0; i<sizeof(data2)/sizeof(int); ++i)
        cout << data2[i] << " ";
    cout << endl;

    int data3[] = {10, 10, 10, 10, 10, 10, 10, 10};
    quick_sort2(data3, 0, sizeof(data3)/sizeof(int)-1);

    for(int i=0; i<sizeof(data3)/sizeof(int); ++i)
        cout << data3[i] << " ";
    cout << endl;

    // int data4[] = {3, 2, 1, 5, 4};
    // int data4[] = {1, 2, 3, 4, 5};
    int data4[] = {5, 4, 3, 2, 1};
    quick_sort2(data4, 0, sizeof(data4)/sizeof(int)-1);

    for(int i=0; i<sizeof(data4)/sizeof(int); ++i)
        cout << data4[i] << " ";
    cout << endl;

    cout << "==================" << endl;
}

void test_merge_sort() {
    int data[] = {10, 10, 20, 30, 7, 8, 9, 10};
    merge_sort(data, sizeof(data)/sizeof(int));
    for(int i=0; i<sizeof(data)/sizeof(int); ++i)
        cout << data[i] << " ";
    cout << endl;

    int data2[] = {10, 10, 10, 10, 70, 8, 9, 10};
    merge_sort(data2, sizeof(data2)/sizeof(int));
    for(int i=0; i<sizeof(data2)/sizeof(int); ++i)
        cout << data2[i] << " ";
    cout << endl;

    int data3[] = {10, 10, 10, 10, 10, 10, 10, 10};
    merge_sort(data3, sizeof(data3)/sizeof(int));
    for(int i=0; i<sizeof(data3)/sizeof(int); ++i)
        cout << data3[i] << " ";
    cout << endl;

    int data4[] = {5, 4, 3, 2, 1};
    merge_sort(data4, sizeof(data4)/sizeof(int));
    for(int i=0; i<sizeof(data4)/sizeof(int); ++i)
        cout << data4[i] << " ";
    cout << endl;


}