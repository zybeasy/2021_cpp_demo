#include <iostream>
#include <iomanip>

#include <queue>

#include "bin_tree.h"

using namespace std;

Node n1 = {99, NULL, NULL, NULL};

ostream& operator<<(ostream& out, const Node &node) {
    out << node.data << " " << node.left << " " << node.right << " " << node.parent;
    return out;
}

Node* _createBinTreeByPreAndMidOrder(int* pre, int pre_begin, int pre_end, 
                                     int* mid, int mid_begin, int mid_end) {
    Node* node = new Node();
    memset(node, 0, sizeof(Node));
    node->data = pre[pre_begin];

    int index = mid_begin;
    for(; mid[index] != pre[pre_begin] and index <= mid_end; index++)
        ;

    if (index > mid_end)
        throw "[ERROR] Fail to construct binary tree.";
    
    if (index - mid_begin > 0) {
        node->left = _createBinTreeByPreAndMidOrder(pre, pre_begin+1, pre_begin+index-mid_begin, 
                                                    mid, mid_begin, index-1);
    }
    if (mid_end - index > 0) {
        node->right = _createBinTreeByPreAndMidOrder(pre, pre_begin+index-mid_begin+1, pre_end, 
                                                    mid, index+1, mid_end);
    }

    return node;
}

Node* createBinTreeByPreAndMidOrder(int* pre, int* mid, int len) {
    if(not pre || not mid || len <= 0)
        return NULL;
    return _createBinTreeByPreAndMidOrder(pre, 0, len-1, mid, 0, len-1);
}

void bt_bfs(Node* root) {
    if (!root)
        return;
    
    queue<Node*> q;
    q.push(root);

    Node* tmp;
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        
        cout << tmp->data << " ";

        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right)
            q.push(tmp->right);
    }

    cout << endl;
}

void bt_bfs_as_full_bt(Node* root) {
    if (!root)
        return;
    
    queue<Node*> q;
    q.push(root);

    Node* tmp;
    bool is_deepest = false;
    int len = 0;
    int level = 0;
    while(!q.empty() && !is_deepest) {
        level += 1;
        len = q.size();
        is_deepest = true;
        while(len--) {
            tmp = q.front();
            q.pop();
            if(tmp) {
                cout << tmp->data << " ";
                q.push(tmp->left);
                q.push(tmp->right);
            }
            else {
                cout << "NULL ";
                q.push(NULL);
                q.push(NULL);
            }
            cout.flush();

            if (tmp && (tmp->left || tmp->right))
                is_deepest = false;    
        }
        cout << endl;
    }

    is_deepest = false;
    q = queue<Node*>();
    q.push(root);
    int FMT_LEN = (2 << (level - 1)) * 3;
    int FMT_PER_LEN;
    while(!q.empty() && !is_deepest) {
        level += 1;
        len = q.size();
        is_deepest = true;
        FMT_PER_LEN = FMT_LEN / (len + 1);
        while(len--) {
            tmp = q.front();
            q.pop();
            if(tmp) {
                cout << setw(FMT_PER_LEN) << setiosflags(ios::right) << tmp->data;
                q.push(tmp->left);
                q.push(tmp->right);
            }
            else {
                cout << setw(FMT_PER_LEN) << setiosflags(ios::right) << "X";
                q.push(NULL);
                q.push(NULL);
            }
            cout.flush();

            if (tmp && (tmp->left || tmp->right))
                is_deepest = false;    
        }
        cout << endl;
    }

    for(int i=0; i<FMT_LEN; i++)
        cout << "-";
    cout << endl;
}

void bt_print(Node* root) {
    if (! root)
        return;

    queue<Node*> q;
    q.push(root);

    int depth = 0;


    while (! q.empty()) {
        
    }

    cout << "DEPTH " << depth << endl;
}