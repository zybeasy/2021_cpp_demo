#include <iostream>

#include "test.h"

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
}