#include <iostream>

using namespace std;

/* 和最大的连续子序列 
 * 剑指offer的代码看上去更简单，但是复杂度是一样的
 * 我的实现从动态规划的角度更易于理解
 * 以第i个元素结尾的和最大连续子序列为f(i)，则
 * f(i) = max(f(i-1)+data[i], data[i])
 */
int get_greatest_sum_of_subarray(int *data, int len) {
    if (!data || len < 1)
        return 0x80000000;
    
    int max_sum = data[0];
    int pre_sum = data[0];
    for(int i=1; i<len; i++) {
        if (pre_sum + data[i] > data[i]) 
        {
            if (pre_sum + data[i] > max_sum) {
                max_sum = pre_sum + data[i];
            }
            pre_sum = pre_sum + data[i];
        }
        else {
            if (data[i] > max_sum) {
                max_sum = data[i];
            }
            pre_sum = data[i];
        }
    }
    return max_sum;
}

void test_get_greatest_sum_of_subarray() {
    int data1[] = {1, -2, 3, 10, -4, 7, 2, -5};
    cout << get_greatest_sum_of_subarray(data1, sizeof(data1)/sizeof(int)) << endl;

    int data2[] = {-2, -8, -1, -5, -9};
    cout << get_greatest_sum_of_subarray(data2, sizeof(data2)/sizeof(int)) << endl;

    int data3[] = {2, 8, 1, 5, 9};
    cout << get_greatest_sum_of_subarray(data3, sizeof(data3)/sizeof(int)) << endl;
}

/* 二维数组，从左上角走到右下角的所有路线中，路径节点之和最大的值
 * 为便于理解，每个元素值大于0
 * 到[i][j]的最大路径是f(i, j),则
 * f(i, j) = max(f(i-1, j), f(i, j-1)) + data[i][j];
 * 下述解法创建了一个二维数组，其实计算f(i, j)只需要 f(i-1, j), f(i, j-1)
 * 所以自需要一个col长度的一维数组，假设为res = new int[col]
 * 每次计算到第f(i,j)，res[0..j-1]存储的是f(i, [0, j-1])的值
 * res[j, col-1]存储的是f(i-1, [j, col-1])的值
 */
int get_maxsum_two_dimensional_arrays(int *data, int row, int col) {
    if (!data || row < 0 || col < 0)
        return 0;

    int **res = new int*[row];    
    for (int i=0; i<row; i++)
        res[i] = new int[col];
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int up = 0, left = 0;
            if (i > 0)
                up = res[i-1][j];
            if (j > 0)
                left = res[i][j-1];
            res[i][j] = max(up, left) + data[i * col + j];
        }
    }
    int max_value = res[row-1][col-1];
    for (int i=0; i < row; i++)
        delete[] res[i];
    delete[] res;
    return max_value;
}

void test_get_maxsum_two_dimensional_arrays() {
    int values[][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    cout << get_maxsum_two_dimensional_arrays((int*)values, 3, 3) << endl;

    int values2[][4] = {
        { 1, 10, 3, 8 },
        { 12, 2, 9, 6 },
        { 5, 7, 4, 11 },
        { 3, 7, 16, 5 }
    };
    cout << get_maxsum_two_dimensional_arrays((int*)values2, 4, 4) << endl;

    int values3[][4] = {{ 1, 10, 3, 8 }};
    cout << get_maxsum_two_dimensional_arrays((int*)values3, 1, 4) << endl;

    int values4[][1] = { { 1 }, { 12 }, { 5 }, { 3 } };
    cout << get_maxsum_two_dimensional_arrays((int*)values4, 4, 1) << endl;

    int values5[][1] = {{ 3 }};
    cout << get_maxsum_two_dimensional_arrays((int*)values5, 1, 1) << endl;
}

/* 最长不含重复子字符的子字符串序列的长度，只包含a-z
 * 例如arabcacfr的最长不含重复自负的子字符串是acfr
 * 以data[i]结尾的最长序列为f(i)，则
 * f(i) = f(i-1) + 1  f(i-1)的范围内没有出现过data[i]
 * f(i) = i - f(i-1)  f(i-1)范围内出现过data[i]
 */
int longest_substring_without_duplication(char *data, int len) {
    if (!data || len < 1)
        return -1;
    int pre_index[26]; // 字母最后一次出现的位置
    for (int i = 0; i < 26; i++)
        pre_index[i] = -1;
    
    int pre_result = 1;
    int longest = 1;
    pre_index[data[0]-'a'] = 0;
    for (int i = 1; i < len; i++) {
        int pre = pre_index[data[i] - 'a'];
        if (pre == -1) {
            pre_result++;
        }
        else {
            if (i - pre > pre_result)
                pre_result++;
            else
                pre_result = i - pre;
        }
        if (pre_result > longest)
            longest = pre_result;
        pre_index[data[i] - 'a'] = i;
    }
    return longest;
}

void test_longest_substring_without_duplication() {
    char data1[] = "abcacfrar";
    cout << longest_substring_without_duplication(data1, sizeof(data1)/sizeof(char)-1) << endl;

    char data2[] = "acfrarabc";
    cout << longest_substring_without_duplication(data2, sizeof(data2)/sizeof(char)-1) << endl;

    char data3[] = "arabcacfr";
    cout << longest_substring_without_duplication(data3, sizeof(data3)/sizeof(char)-1) << endl;

    char data4[] = "aaaa";
    cout << longest_substring_without_duplication(data4, sizeof(data4)/sizeof(char)-1) << endl;

    char data5[] = "abcdefg";
    cout << longest_substring_without_duplication(data5, sizeof(data5)/sizeof(char)-1) << endl;

    char data6[] = "aaabbbccc";
    cout << longest_substring_without_duplication(data6, sizeof(data6)/sizeof(char)-1) << endl;

    char data7[] = "abcdcba";
    cout << longest_substring_without_duplication(data7, sizeof(data7)/sizeof(char)-1) << endl;

    char data8[] = "abcdaef";
    cout << longest_substring_without_duplication(data8, sizeof(data8)/sizeof(char)-1) << endl;

    char data9[] = "a";
    cout << longest_substring_without_duplication(data9, sizeof(data9)/sizeof(char)-1) << endl;
}
