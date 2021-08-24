#include <iostream>

#include <unistd.h>
#include <sys/syscall.h>

#include "tree_test.h"
#include "test.h"

#include "tmp/tmp.h"

using namespace std;

int main(int, char**) {

    cout << n1 << endl;

    create_bintree();
    bt_bfs(create_bintree());
    bt_bfs_as_full_bt(create_bintree());

    const char* FORMAT = "============";
    cout << FORMAT << " END " << FORMAT << endl;

    test_quick_sort();

    test_get_path();

    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 50, 55};
    for(int i=0; i<sizeof(data)/sizeof(int); i++)
        cout << max_product(data[i]) << " " << maxProductAfterCutting_solution1(data[i]) << endl;

    format(5);
}
