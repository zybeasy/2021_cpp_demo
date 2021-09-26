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


void reverse(char *str, int begin, int end) {
    while(begin < end) {
        char tmp = str[begin];
        str[begin] = str[end];
        str[end] = tmp;
        begin++;
        end--;
    }
}

/* 反转字符串中的单词
 * "I am a student." 翻转为 "student. a am I".
 */
void reverse_sentence(char *str) {
    if (!str)
        return;

    reverse(str, 0, strlen(str)-1);
    int begin = 0;
    int end = begin;
    while(begin < strlen(str)) {
        while(str[begin] == ' ' && begin < strlen(str))
            begin++;
        end = begin;
        while(str[end] != ' ' && str[end] != '\0')
            end++;
        reverse(str, begin, end-1);
        begin = end;
    }
    cout << "\"" << str << "\"" << endl;
}

void test_reverse_sentence() {
    char str1[] = "I am a student.";
    reverse_sentence(str1);

    char str2[] = "Wonderful";
    reverse_sentence(str2);

    reverse_sentence(NULL);

    char str3[] = "";
    reverse_sentence(str3);

    char str4[] = "   ";
    reverse_sentence(str4);
}