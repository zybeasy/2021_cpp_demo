#include <iostream>

using namespace std;
/* 长n的绳子剪成m断，m>1, 分段长度乘积最大多少？

就是至少两段，假设第一次截取有1,2,3...n-1种可能
f(n) = max(1*f(n-1), 2*f(n-2), 3*f(n-3), ... , (n-1)f(1))

当长度为1、2、3时，考虑到至少减成2段，所以最大乘积分别为 0,1,2
当长度至少4时,情况不一样了 
f(1)=1 因为用到f(1)一定是已经至少剪过一次了，同理f(2) f(3)
f(2)=2
f(3)=3
*/

int max_product(int n) {
    if (n <= 1)
        return 0;
    if(n==2)
        return 1;

    int *result = new int[n+1];
    memset(result, 0, sizeof(int)*(n+1));

    // result[0] = 1;
    result[1] = 1;
    result[2] = 2;
    result[3] = 3;
    for(int i=4; i<=n; ++i) {
        for(int j=1; j<i; j++)
            result[i] = max(result[i], (i-j)*result[j]);
    }

    return result[n];
}

int maxProductAfterCutting_solution1(int length)
{
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    int* products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;
    for(int i = 4; i <= length; ++i)
    {
        max = 0;
        for(int j = 1; j <= i / 2; ++j)
        {
            int product = products[j] * products[i - j];
            if(max < product)
                max = product;

            products[i] = max;
        }
    }

    max = products[length];
    delete[] products;

    return max;
}

/* 从1打印n位整数 */
void print_nnn(char *data) {
    char *tmp = data;
    while(*tmp == '0' && *tmp != '\0')
        tmp++;
    if (*tmp != '\0')
        cout << tmp << " ";
}

void _format(char *data, int len, int index) {
    if(index == len) {
        print_nnn(data);
        return;
    }
    for(int i=0; i<10; ++i) {
        data[index] = i - 0 + '0';
        _format(data, len, index+1);
    }
}
void format(int n){
    char *data = new char[n+1];
    memset(data, '0', n);
    data[n] = '\0';
    _format(data, n, 0);
}