#include <iostream>

#include "widgets/tree.h"

using namespace std;

bool is_sub_tree(BTN* root1, BTN* root2) {
    if (!root2)
        return true;
    
    if (!root1)
        return false;

    if (root1->data == root2->data) {
        return is_sub_tree(root1->left, root2->left) && is_sub_tree(root1->right, root2->right);
    }
    else {
        return is_sub_tree(root1->left, root2) || is_sub_tree(root1->right, root2);
    }
}