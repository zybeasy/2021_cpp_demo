#include <iostream>

#include <stack>

using namespace std;

/* 判断入栈和出栈顺序能否匹配
 */
bool is_pop_order(int *push, int *pop, int len) {

    if (!push || !pop || len <= 0)
        return false;

    int push_i = 0;
    int pop_i = 0;
    stack<int> s;
    while(pop_i < len) {
        while(s.empty() || s.top() != pop[pop_i]) {
            if (push_i < len)
                s.push(push[push_i++]);
            else
                return false;
        }
        s.pop();
        pop_i++;
    }
    return true;
}


void test_is_pop_order() {
    int push1[] = {1, 2, 3, 4, 5};
    int pop1[] = {4, 5, 3, 2, 1};
    cout << is_pop_order(push1, pop1, 5) << endl;

    int push2[] = {1, 2, 3, 4, 5};
    int pop2[] = {3, 5, 4, 2, 1};
    cout << is_pop_order(push2, pop2, 5) << endl;

    int push3[] = {1, 2, 3, 4, 5};
    int pop3[] = {4, 3, 5, 1, 2};
    cout << is_pop_order(push3, pop3, 5) << endl;

    int push4[] = {1, 2, 3, 4, 5};
    int pop4[] = {3, 5, 4, 1, 2};
    cout << is_pop_order(push4, pop4, 5) << endl;

    int push5[] = {1,};
    int pop5[] = {3};
    cout << is_pop_order(push5, pop5, 1) << endl;

    int push6[] = {1};
    int pop6[] = {1};
    cout << is_pop_order(push6, pop6, 1) << endl;

    cout << is_pop_order(NULL, NULL, 1) << endl;
}