#include <iostream>

#include <unistd.h>
#include <sys/syscall.h>

using namespace std;

class A {
public:
    // A(int data_=1000) {
    //     cout << "A Cons " << data_ << endl;
    //     data = data_;
    // }

    A(int data_=999) {
        cout << "A Cons " << data_ << endl;
        data = data_;
    }


    A(const A& a) {
        cout << "A Copy Cons " << a.data << endl; 
        data = a.data + 999;
    }

    int data;
};

class B {
    public:
     A a;

    B() {
        cout << "222222" << endl;
        a = 99;
    }

    //  B(const B& b) {
    //      cout << "B COPY CONS" << endl;
    //  }
};

int main(int, char**) {

    std::shared_ptr<int> si;

    cout << "1111111" << endl;
    B b1;

    cout << b1.a.data << endl;

    cout << syscall(SYS_gettid) << " XXXXXX" << endl;

    const char* FORMAT = "============";
    cout << FORMAT << " END " << FORMAT << endl;
}
