#include <iostream>
#include <deque>

using namespace std; 

/* 只能被2 3 5 整除的树称为丑数， 1也是丑数 */
int get_ugly_number(int index) {
    return 0;
}

void test_get_ugly_number() {
    cout << get_ugly_number(1500) << endl;
}


int _get_missing_number(int *data, int begin, int end) {
    if (end < begin)
        return -1;
    
    int mid = (begin + end) / 2;
    if (data[mid] == mid) {
        if (mid == end)
            return end + 1;
        return _get_missing_number(data, mid+1, end);
    }
    else {
        if (mid == begin)
            return data[begin] - 1;
        else {
            if (data[mid-1] == mid-1)
                return mid;
            else 
                return _get_missing_number(data, begin, mid-1);
        }
    }
}

/* 长度n-1的数组，递增包含0～n-1间的数字，每个数字只出现一次，找出缺少的那个数 */
int get_missing_number(int *data, int len) {
    if (!data || len <= 0)
        return -1;
    
    return _get_missing_number(data, 0, len-1);
}

int get_missing_number2(int *data, int len) {
    if (!data || len <= 0)
        return -1;
    
    int begin = 0, end = len - 1;
    while(begin <= end) {
        int mid = (begin + end) / 2;
        if (data[mid] == mid)
            begin = mid + 1;
        else {
            if (mid == 0)
                return 0;
            if (data[mid - 1] == mid - 1)
                return mid;
            else 
                end = mid - 1;
        }
    }
    if (begin == len)
        return len;
    
    return -1;
}

void test_get_missing_number() {
    int data1[] = { 1, 2, 3, 4, 5};
    cout << get_missing_number2(data1, sizeof(data1)/sizeof(int)) << endl;

    int data2[] = { 0, 1, 2, 3, 4 };
    cout << get_missing_number2(data2, sizeof(data2)/sizeof(int)) << endl;

    int data3[] = { 0, 1, 2, 4, 5 };
    cout << get_missing_number2(data3, sizeof(data3)/sizeof(int)) << endl;

    int data4[] = { 1 };
    cout << get_missing_number2(data4, sizeof(data4)/sizeof(int)) << endl;

    int data5[] = { 0 };
    cout << get_missing_number2(data5, sizeof(data5)/sizeof(int)) << endl;

    int data6[] = { 1, 7};
    cout << get_missing_number2(data6, sizeof(data6)/sizeof(int)) << endl;
}

/* 递增序列中第一个值和下标相同的值 */
int get_value_sameas_index(int *data, int len) {
    if (!data || len <= 0)
        return -1;
    int begin = 0;
    int end = len - 1;
    while(begin <= end) {
        int mid = (begin + end) / 2;
        if(mid == data[mid])
            return mid;
        else {
            if (data[mid] > mid)
                end = mid - 1;
            else
                begin = mid + 1;
        }
    }
    return -1;
}

void test_get_value_sameas_index() {
    int data1[] = { -3, -1, 1, 3, 5 };
    cout << get_value_sameas_index(data1, sizeof(data1)/sizeof(int)) << endl;

    int data2[] = { 0, 1, 3, 5, 6 };
    cout << get_value_sameas_index(data2, sizeof(data2)/sizeof(int)) << endl;

    int data3[] = { -1, 0, 1, 2, 4 };
    cout << get_value_sameas_index(data3, sizeof(data3)/sizeof(int)) << endl;

    int data4[] = { -1, 0, 1, 2, 5 };
    cout << get_value_sameas_index(data4, sizeof(data4)/sizeof(int)) << endl;

    int data5[] = { 0 };
    cout << get_value_sameas_index(data5, sizeof(data5)/sizeof(int)) << endl;

    int data6[] = { 10 };
    cout << get_value_sameas_index(data6, sizeof(data6)/sizeof(int)) << endl; 
}

/* 实现o(1)返回最大值的队列 */
class QueenWithMax {
public:
    void push(int value) {
        while(max_q.size() && max_q.back() < value)
            max_q.pop_back();
        data_q.push_back(value);
        max_q.push_back(value);
    }
    int pop() {
        if (data_q.empty())
            throw "empty queue";
        int result = data_q.front();
        data_q.pop_front();
        if (result == max_q.front())
            max_q.pop_front();
        return result;
    }
    int max() {
        if (max_q.empty())
            throw "empty queue";
        return max_q.front();
    }
private:
    deque<int> data_q;
    deque<int> max_q;
};

void test_queen_with_max() {
    QueenWithMax q;
    q.push(2);
    cout << q.max() << endl;
    q.push(3);
    cout << q.max() << endl;
    q.push(4);
    cout << q.max() << endl;
    q.push(2);
    cout << q.max() << endl;

    q.pop();
    cout << q.max() << endl;
    q.pop();
    cout << q.max() << endl;
    q.pop();
    cout << q.max() << endl;
    q.push(6);
    cout << q.max() << endl;
    q.push(2);
    cout << q.max() << endl;
    q.push(5);
    cout << q.max() << endl;
    q.pop();
    cout << q.max() << endl;
    q.pop();
    cout << q.max() << endl;
    q.pop();
    cout << q.max() << endl;
    q.push(5);
    cout << q.max() << endl;
    q.push(2);
    cout << q.max() << endl;
    q.pop();
    cout << q.max() << endl;
    q.pop();
    cout << q.max() << endl;
}

/* 长度为win_size的滑动窗口在data上向右逐个滑动，输出每次滑动窗口中的最大值 
 * 解决方法思路参照QueenWithMax
 */
void max_in_windows(int *data, int len, int win_size) {
    if (!data || len <= 0 || win_size <=0 || win_size > len) 
        return;
    
    deque<int> q;
    for (int i=0; i<win_size; i++) {
        while(q.size() && data[q.back()] < data[i])
            q.pop_back();
        q.push_back(i);
    }
    cout << data[q.front()] << " ";

    for (int i=win_size; i<len; i++) {
        if (i-q.front() == win_size)
            q.pop_front();
        while(q.size() && data[q.back()] < data[i])
            q.pop_back();
        q.push_back(i);
        cout << data[q.front()] << " ";
    }
    cout << endl;
}

void test_max_in_windows() {
    int data1[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
    max_in_windows(data1, sizeof(data1)/sizeof(int), 3);

    int data2[] = { 1, 3, -1, -3, 5, 3, 6, 7 };
    max_in_windows(data2, sizeof(data2)/sizeof(int), 3);

    int data3[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
    max_in_windows(data3, sizeof(data3)/sizeof(int), 4);

    int data4[] = { 16, 14, 12, 10, 8, 6, 4 };
    max_in_windows(data4, sizeof(data4)/sizeof(int), 5);

    int data5[] = { 10, 14, 12, 11 };
    max_in_windows(data5, sizeof(data5)/sizeof(int), 1);
    max_in_windows(data5, sizeof(data5)/sizeof(int), 4);
}


