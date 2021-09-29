#ifndef CPPDEMO_TREE_TEST_H
#define CPPDEMO_TREE_TEST_H

#include "bin_tree.h"

extern Node n1;

Node* create_bintree();

void bintree_print(Node* root);

void test_bt_bfs();
void test_bt_print_in_zigzag();

void test_bt_find_path();

void test_bst_to_sorted_deque();

void test_bt_deserialize();

void test_bt_find_node_path();


#endif