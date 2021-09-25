#include <iostream>
#include <cstring>

#include "sort.h"

using namespace std;

/* 快速排序 */

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

/* 归并排序 */

void merge(int *data, int begin, int mid, int end) {
    int *tmp = new int[end - begin + 1];
    int i = begin, j = mid+1, index=0;
    while(i <= mid && j <= end) {
        if (data[i] > data[j]) {
            tmp[index] = data[j];
            j++;
        }
        else {
            tmp[index] = data[i];
            i++;
        }
        index++;
    }
    while(i <= mid)
        tmp[index++] = data[i++];
    while(j <= end)
        tmp[index++] = data[j++];
    memcpy(data+begin, tmp, sizeof(int)*(end-begin+1));
    delete[] tmp;
}

void _merge_sort(int *data, int begin, int end) {
    if (begin < end) {
        int mid = (begin + end) / 2;
        _merge_sort(data, begin, mid);
        _merge_sort(data, mid+1, end);
        merge(data, begin, mid, end);
    }

}

void merge_sort(int *data, int len) {
    if (!data || len <= 1)
        return;
    
    _merge_sort(data, 0, len-1);
}