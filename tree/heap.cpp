#include <iostream>

using namespace std;

void _build_max_heap(int *data, int len, int index) {
    int max = index;
    if (2 * index + 1 < len && data[2*index+1] > data[max])
        max = 2 * index + 1;
    if (2 * index + 2 < len && data[2*index+2] > data[max])
        max = 2 * index + 2;
    
    if (max != index) {
        int tmp = data[index];
        data[index] = data[max];
        data[max] = tmp;
        _build_max_heap(data, len, max);
    }
}

void build_max_heap(int *data, int len) {
    if (data == NULL || len < 2)
        return;
    
    int index = (len - 1) >> 1;
    while(index >= 0) {
        _build_max_heap(data, len, index);
        index--;
    }
}

void max_heap_insert(int *data, int len, int value) {
    if (!data || len < 0)
        return;
    data[len] = value;
    int index = len;
    while(index != 0) {
        int parent = (index - 1) / 2;
        if (data[parent] < data[index])
        {
            int tmp = data[parent];
            data[parent] = data[index];
            data[index] = tmp;
            index = parent;
        }
        else
            break;
    }
}

void max_heap_delete(int *data, int len, int index) {
    if (!data || len <= 0 || index < 0 || index >= len)
        return;
    int tmp = data[index];
    data[index] = data[len-1];
    _build_max_heap(data, len-1, index);
}

void test_build_max_heap() {
    int data1[] = {1, 2, 3, 4, 5};
    int data1_len = sizeof(data1)/sizeof(int);
    build_max_heap(data1, data1_len);
    for(int i=0; i<data1_len; i++)
        cout << data1[i] << " ";
    cout << endl;

    max_heap_delete(data1, data1_len, 0);
    for(int i=0; i<data1_len-1; i++)
        cout << data1[i] << " ";
    cout << endl;

    max_heap_insert(data1, data1_len-1, 5);
    for(int i=0; i<data1_len; i++)
        cout << data1[i] << " ";
    cout << endl;
    cout << "=====" << endl;
    for (int i=1; i<=5; i++) {
        max_heap_insert(data1, i-1, i);
        for(int j=0; j<i; j++)
            cout << data1[j] << " ";
        cout << endl;
    }

    // max_heap_insert(data, 0, )

}