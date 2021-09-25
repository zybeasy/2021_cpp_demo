#include <iostream>
#include <cstring>

using namespace std;

void _str_permutation(char *str, int index) {
    if(str[index] == '\0')
        cout << str << endl;
    else {
        int i = index;
        char tmp;
        while(str[i] != '\0') {
            tmp = str[index];
            str[index] = str[i];
            str[i] = tmp;
            _str_permutation(str, index+1);
            str[i] = str[index];
            str[index] = tmp;
            i++;
        }
    }
}

/* 输出字符串所有排列， 字符串中没有相同字符 */
void str_permutation(char *str) {
    if (!str)
        return;
    
    _str_permutation(str, 0);
}

void _str_combination(char *data, char *res, int n, int index) {

    if (strlen(data) < n - index)
        return;

    if (index == n) 
        cout << res << endl;
    else {
        res[index] = data[0];
        _str_combination(data+1, res, n, index+1);
        _str_combination(data+1, res, n, index);
    }
}

/* 输出组合 ，没有相同字符 */
void str_combination(char *data, int n) {
    if (!data || n <= 0 || n > strlen(data))
        return;
    char *res = new char[n+1];
    res[n] = '\0';
    _str_combination(data, res, n, 0);
    delete[] res;
}

void test_str_permutation() {
    char data1[] = {};
    char data2[] = "a";
    char data3[] = "ab";
    char data4[] = "abc";
    str_permutation(data1);
    str_permutation(data2);
    str_permutation(data3);
    str_permutation(data4);
}

void test_str_combination() {
    char data1[] = "abcd";
    str_combination(data1, 2);
}
