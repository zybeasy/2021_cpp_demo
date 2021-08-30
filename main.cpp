#include <iostream>

#include <unistd.h>
#include <sys/syscall.h>

#include "tree/tree_test.h"
#include "test.h"

#include "codinginterviewchinese2/codinginterview.h"

using namespace std;

int main(int, char**) {

    // create_bintree();
    // bt_bfs(create_bintree());
    // bt_bfs_as_full_bt(create_bintree());
    // test_bt_bfs();
    // test_bt_print_in_zigzag();

    // test_quick_sort();
    // test_get_path();
    // test_cutting_rope();

    // test_delete_duplication();
    // test_get_kth_to_tail();
    // test_reverse_list();
    // test_merge_sorted_list();

    // tree_is_sub_tree();

    // test_print_matrix();

    // test_is_pop_order();

    // test_bt_find_path();

    // test_bst_to_sorted_deque();

    test_bt_deserialize();

    const char* FORMAT = "============";
    cout << FORMAT << " END " << FORMAT << endl;

}
