#include <iostream>
#include <iomanip>

#include <cstring>

#include <queue>
#include <stack>

#include "bin_tree.h"

using namespace std;

Node n1 = {99, NULL, NULL, NULL};

ostream& operator<<(ostream& out, const Node &node) {
    out << node.data << " " << node.left << " " << node.right << " " << node.parent;
    return out;
}


Node* _create_node(int data) {
    Node *node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
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

Node* bt_deserialize(int *data, int len) {
    if (!data || len <= 0 )
        return NULL;

    int IMPOSIBE_LABEL = -99999;
    
    Node *root = _create_node(data[0]);
    stack<Node*> s;
    s.push(root);
    int i = 1;
    Node *tmp = NULL;
    Node *top = s.top();
    while (i < len) {
        if (data[i] != IMPOSIBE_LABEL) {
            tmp = _create_node(data[i]);
            if (s.size()) {
                top = s.top();
                top->left = tmp;
                s.push(tmp);
                i++;
            }
            else 
                return NULL;
        }
        else {
            ++i;
            while(i < len && data[i] == IMPOSIBE_LABEL) {
                if (s.size()) {
                    s.pop();
                    ++i;
                }
                else
                    return NULL;
            }
            if (i < len && s.size()) {
                tmp = _create_node(data[i]);
                s.top()->right = tmp;
                s.push(tmp);
                i++;
            }
        }
    }
    return root;
}

void bt_bfs(Node* root) {
    if (!root)
        return;
    
    queue<Node*> q;
    q.push(root);

    Node* tmp;
    int len = 0;
    while (!q.empty()) {
        len = q.size();
        while(len--) {
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

void bt_print_in_zigzag(Node* root) {
    if (!root)
        return;
    
    queue<Node*> q;
    stack<Node*> s;
    stack<Node*> s2;
    q.push(root);
    int len = 0;
    Node* tmp;
    while(q.size()) {
        len = q.size();
        for(int i=0; i<len; i++) {
            tmp = q.front();
            q.pop();
            cout << tmp->data << " ";
            if (tmp->left)
                s.push(tmp->left);
            if (tmp->right)
                s.push(tmp->right);
        }
        cout << endl;
        while(s.size()) {
            tmp = s.top();
            s.pop();
            cout << tmp->data << " ";
            if (tmp->right)
                s2.push(tmp->right);
            if (tmp->left)
                s2.push(tmp->left);
        }
        while(s2.size()) {
            tmp = s2.top();
            s2.pop();
            q.push(tmp);
        }
        cout << endl;
    }
}

// 输入整数数组，成员各不相同，判断是否是二叉排序树
bool bst_verify_sequence(int *data, int len) {

}

// 二叉树是否有和为sum的路径
stack<Node*>* bt_find_path(Node *root, int sum) {
    stack<Node*> *s = new stack<Node*>();
    if (!root)
        return s;
    
    s->push(root);
    sum -= root->data;
    Node* top = NULL;
    Node* top_parent = NULL;
    while(s->size()) {
        top = s->top();
        if(sum == 0 && top->left == NULL && top->right == NULL)
            return s;
        
        if (top->left) {
            s->push(top->left);
            sum -= top->left->data;
        }
        else if (top->right) {
            s->push(top->right);
            sum -= top->right->data;
        }
        else {
            s->pop();
            sum += top->data;
            if(s->size()) {
                top_parent = s->top();
                while(top_parent->right == top || top_parent->right == NULL) {
                    top = top_parent;
                    s->pop();
                    sum += top->data;
                    if(s->size())
                        top_parent = s->top();
                    else
                        return s;
                }
                s->push(top_parent->right);
                sum -= top_parent->right->data;
            }
            else
                return s;
        }
    }
    return s;
}

Node* bst_to_sorted_deque(Node *root) {
    if (!root)
        return NULL;

    Node *left = bst_to_sorted_deque(root->left);
    Node *right = bst_to_sorted_deque(root->right);

    Node *tmp = left;
    while(tmp && tmp->right)
        tmp = tmp->right;
    root->left = tmp;
    if (tmp)
        tmp->right = root;
    
    root->right = right;
    if (right)
        right -> left = root;
    
    while(root && root->left)
        root = root->left;
    
    return root;
}



