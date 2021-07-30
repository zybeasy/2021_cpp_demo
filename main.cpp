#include <iostream>

#include <unistd.h>
#include <sys/syscall.h>

#include "test.h"

using namespace std;

int main(int, char**) {

    cout << n1 << endl;

    create_bintree();

    bt_bfs(create_bintree());

    bt_bfs_as_full_bt(create_bintree());

    const char* FORMAT = "============";
    cout << FORMAT << " END " << FORMAT << endl;
}
