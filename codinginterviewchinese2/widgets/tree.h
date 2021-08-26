#ifndef CODINGINTERVIEWCHINERSE2_TREE_H
#define CODINGINTERVIEWCHINERSE2_TREE_H

typedef struct BinaryTreeNode {
    int data;
    BinaryTreeNode* parent;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
}BTN;

BTN* create_btn(int value);

void print_bintree_as_fulltree(BTN *root);

BTN* create_tree_by_pre_mid_order(BTN **pre, BTN **mid, int len);

#endif