#include <iostream>

#include "widgets/tree.h"

using namespace std;

bool _is_same_tree(BTN *root1, BTN *root2) {
    if (!root2)
        return true;
    if (!root1)
        return false;
    if (root1->data == root2->data)
        return _is_same_tree(root1->left, root2->left) && _is_same_tree(root1->right, root2->right);
    else
        return false;
}

bool is_sub_tree(BTN* root1, BTN* root2) {
    if (!root2)
        return true;
    
    if (!root1)
        return false;

    if (root1->data == root2->data) {
        if(_is_same_tree(root1->left, root2->left) && _is_same_tree(root1->right, root2->right))
            return true;
    }
    return is_sub_tree(root1->left, root2) || is_sub_tree(root1->right, root2);
}

void tree_is_sub_tree() {
    int a[] = {8, 8, 9, 2, 4, 7, 7};
    BTN **btns = (BTN**)malloc(sizeof(BTN*)*sizeof(a)/sizeof(int));
    for(int i=0; i<sizeof(a)/sizeof(int); i++)
        btns[i] = create_btn(a[i]);
    BTN *(pre[]) = {btns[0], btns[1], btns[2], btns[3], btns[4], btns[5], btns[6]};
    BTN *(mid[]) = {btns[2], btns[1], btns[4], btns[3], btns[5], btns[0], btns[6]};
    BTN *root = create_tree_by_pre_mid_order(pre, mid, sizeof(a)/sizeof(int));
    print_bintree_as_fulltree(root);

    int b[] = {9, 8, 2};
    BTN **btns2 = (BTN**)malloc(sizeof(BTN*)*sizeof(b)/sizeof(int));
    for(int i=0; i<sizeof(b)/sizeof(int); i++)
        btns2[i] = create_btn(b[i]);
    BTN *(pre2[]) = {btns2[1], btns2[0], btns2[2]};
    BTN *(mid2[]) = {btns2[0], btns2[1], btns2[2]};
    BTN *root2 = create_tree_by_pre_mid_order(pre2, mid2, sizeof(b)/sizeof(int));
    print_bintree_as_fulltree(root2);

    cout << is_sub_tree(root, root2) << endl;
    
}