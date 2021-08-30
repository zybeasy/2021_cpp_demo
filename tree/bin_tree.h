#ifndef CPPDEMO_TREE_BINTREE_H
#define CPPDEMO_TREE_BINTREE_H

#include <stack>

using namespace std;

typedef struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
}Node, *PNode;

ostream& operator<<(ostream& out, const Node &p);

Node* createBinTreeByPreAndMidOrder(int* pre, int* mid, int len);

// 二叉树遍历
void bt_bfs(Node* root);
void bt_dfs(Node* root);

// 二叉树层级Z字形输出
void bt_print_in_zigzag(Node* root);

// 二叉树遍历，将二叉树当成一颗满二叉树，缺失的节点输出NULL
void bt_bfs_as_full_bt(Node* root);

// 二叉树深度
void bt_depth(Node* root);

// 二叉树路径为sum的和是
stack<Node*>* bt_find_path(Node* root, int sum);

// 二叉搜索树转有序双向列表
Node* bst_to_sorted_deque(Node* root);

Node* bt_deserialize(int *data, int len);




#endif