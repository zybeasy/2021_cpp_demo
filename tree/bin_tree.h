#ifndef CPPDEMO_TREE_BINTREE_H
#define CPPDEMO_TREE_BINTREE_H

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

// 二叉树遍历，将二叉树当成一颗满二叉树，缺失的节点输出NULL
void bt_bfs_as_full_bt(Node* root);

// 二叉树深度
void bt_depth(Node* root);


#endif