#include <iostream>

#include <queue>

#include "tree.h"

using namespace std;


BTN* create_btn(int value) {
    BTN *node = new BTN();
    node->data = value;
    node->parent = node->left = node->right = NULL;
    return node;
}

void print_bintree_as_fulltree(BTN *root) {
    if (!root)
        return;
    
    queue<BTN*> q;
    q.push(root);

    int level = 0;
    int len = 0;
    BTN* tmp = NULL;
    bool is_deepest = false;
    while(!q.empty() && !is_deepest) {
        len = q.size();
        is_deepest = true;
        while(len--) {
            tmp = q.front();
            q.pop();
            if (tmp) {
                q.push(tmp->left);
                q.push(tmp->right);
                cout << tmp->data << " ";
            }
            else {
                q.push(NULL);
                q.push(NULL);
                cout << "X ";
            }
            if (tmp && (tmp->left || tmp->right))
                is_deepest = false;
        }
        cout << endl;
    }
}

BTN* create_tree_by_pre_mid_order(BTN **pre, BTN **mid, int len) {
    if (!pre || !(*pre) || !mid || !(*mid) || len <= 0)
        return NULL;

    int index = 0;
    for(; index<len; ++index) {
        if (mid[index] == pre[0]) {
            break;
        }
    }

    if (index == len)
        throw "FUCK ERROR";

    if (index > 0)
        pre[0]->left = create_tree_by_pre_mid_order(pre+1, mid, index);
    if (index < len - 1)
        pre[0]->right = create_tree_by_pre_mid_order(pre+index+1, mid+index+1, len-index-1);
    
    return pre[0];
}


