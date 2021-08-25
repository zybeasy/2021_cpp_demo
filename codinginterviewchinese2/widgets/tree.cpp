#include <iostream>

#include "tree.h"

using namespace std;


BTN* create_btn(int value) {
    BTN *node = new BTN();
    node->data = value;
    node->parent = node->left = node->right = NULL;
    return node;
}
