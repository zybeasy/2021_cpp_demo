#include <iostream>

#include "sort.h"

using namespace std;

void quick_sort(int *data, int begin, int end) {
    if(begin < end) {
        int i = begin, j = end;
        int tmp = data[i];
        while(i < j) {
            while(i < j && data[j] >= tmp)
                j--;
            if (i < j)
                data[i++] = data[j];
            
            while(i < j && data[i] < tmp)
                i++;
            if (i < j)
                data[j--] = data[i];
        }
        data[i] = tmp;
        quick_sort(data, begin, i-1);
        quick_sort(data, i+1, end);
    }
}

void quick_sort2(int *data, int begin, int end) {
    if (begin < end) {
        int i = begin, j = end;
        int tmp = data[i];

        while(i < j) {
            while(i <= j && data[i] <= tmp)
                i++;
            while(i <= j && data[j] > tmp)
                j--;
            if (i < j)
            {
                int t = data[i];
                data[i] = data[j];
                data[j] = t;
            }
        }
        int t = data[j];
        data[j] = tmp;
        data[begin] = t;
        quick_sort2(data, begin, j-1);
        quick_sort2(data, i, end);
    }
}