#include <iostream>

#include <unistd.h>
#include <sys/syscall.h>

#include "tree_test.h"
#include "test.h"

using namespace std;

class A {

    public:
    virtual void f() { cout << "A" << endl; }

};


class B: public A {
    public:
    virtual void f() { cout << "B" << endl; }

};

void func(A &a) { cout << &a << endl; a.f(); }

void my_new_handler() {
    cout << "FUCK NEW HANDLER ERROR" << endl;
    exit(255);
}

int main(int, char**) {

    cout << n1 << endl;

    create_bintree();

    bt_bfs(create_bintree());

    bt_bfs_as_full_bt(create_bintree());

    const char* FORMAT = "============";
    cout << FORMAT << " END " << FORMAT << endl;

    test_quick_sort();
}
