#ifndef CODINGINTERVIEWCHINERSE2_TREE_H
#define CODINGINTERVIEWCHINERSE2_TREE_H

typedef struct BinaryTreeNode {
    int data;
    BinaryTreeNode* parent;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
}BTN;

BTN* create_btn(int value);

BTN* create_tree_by_pre_mid_order(BTN **pre, BTN **mid, int len) {
    if (!pre || !mid || len <= 0)
        return NULL;
    
    // BTN *root = create_btn(pre[0]->data);
    BTN *root = pre[0];

    int index = 0;
    for (; index<len; ++index) {
        if (pre[0] == mid[index]) {
            break;
        }
    }
    if (index == len)
        throw("FUCK ERROR");

    return root;

}

#endif