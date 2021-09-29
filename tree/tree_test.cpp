#include <iostream>

#include "tree_test.h"

using namespace std;

Node* create_bintree() {
    int pre[] = {1, 2, 3, 4, 5, 6};
    int mid[] = {3, 2, 5, 4, 1, 6};

    // int pre[] = {1, 2, 4, 5, 3, 6, 7};
    // int mid[] = {4, 2, 5, 1, 6, 3, 7};
    Node* tree = createBinTreeByPreAndMidOrder(pre, mid, sizeof(pre)/sizeof(int));
    return tree;
}

void print_deque(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

void test_bt_bfs() {
    bt_bfs(create_bintree());
}

void test_bt_print_in_zigzag() {
    // bt_print_in_zigzag(create_bintree());

    int pre1[] = {8, 6, 5, 7, 10, 9, 11};
    int mid1[] = {5, 6, 7, 8, 9, 10, 11};
    Node *root = createBinTreeByPreAndMidOrder(pre1, mid1, 7);
    bt_print_in_zigzag(root);

    int pre2[] = {5, 4, 3, 2};
    int mid2[] = {2, 3, 4, 5};
    root = createBinTreeByPreAndMidOrder(pre2, mid2, 4);
    bt_print_in_zigzag(root);
    cout << "************************" << endl;

    int pre3[] = {5, 4, 3, 2};
    int mid3[] = {5, 4, 3, 2};
    root = createBinTreeByPreAndMidOrder(pre3, mid3, 4);
    bt_print_in_zigzag(root);
    cout << "************************" << endl;

    bt_print_in_zigzag(NULL);
    cout << "************************" << endl;

    int pre4[] = {100, 50, 150};
    int mid4[] = {50, 150, 100};
    root = createBinTreeByPreAndMidOrder(pre4, mid4, 3);
    bt_print_in_zigzag(root);
    cout << "************************" << endl;

    int pre5[] = {8, 4, 2, 1, 3, 6, 5, 7, 12, 10, 9, 11, 14, 13, 15};
    int mid5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    root = createBinTreeByPreAndMidOrder(pre5, mid5, 15);
    bt_print_in_zigzag(root);
    cout << "************************" << endl;
}

void test_bt_find_path() {
    int pre1[] = {10, 5, 4, 7, 12};
    int mid1[] = {4, 5, 7, 10, 12};
    Node *root = createBinTreeByPreAndMidOrder(pre1, mid1, 5);
    stack<Node*> *s = bt_find_path(root, 22);

    Node* tmp = NULL;
    while(s->size()) {
        tmp = s->top();
        s->pop();
        cout << tmp->data << " ";
    }
    cout << "***********************" << endl;

    s = bt_find_path(root, 12);
    tmp = NULL;
    while(s->size()) {
        tmp = s->top();
        s->pop();
        cout << tmp->data << " ";
    }
    cout << "***********************" << endl;

    // int pre2[] = {5, 4, 3, 2, 1};
    // int mid2[] = {1, 2, 3, 4, 5};
    int pre2[] = {1, 2, 3, 4, 5};
    int mid2[] = {1, 2, 3, 4, 5};
    root = createBinTreeByPreAndMidOrder(pre2, mid2, 5);
    s = bt_find_path(root, 15);
    tmp = NULL;
    while(s->size()) {
        tmp = s->top();
        s->pop();
        cout << tmp->data << " ";
    }
    cout << "***********************" << endl;

    int pre3[] = {1};
    int mid3[] = {1};
    root = createBinTreeByPreAndMidOrder(pre3, mid3, 1);
    s = bt_find_path(root, 1);
    tmp = NULL;
    while(s->size()) {
        tmp = s->top();
        s->pop();
        cout << tmp->data << " ";
    }
    cout << "***********************" << endl;
}

void test_bst_to_sorted_deque() {
    int pre1[] = {10, 6, 4, 8, 14, 12, 16};
    int mid1[] = {4, 6, 8, 10, 12, 14, 16};
    Node *root = createBinTreeByPreAndMidOrder(pre1, mid1, 7);
    print_deque(bst_to_sorted_deque(root));

    int pre2[] = {5, 4, 3, 2, 1};
    int mid2[] = {1, 2, 3, 4, 5};
    root = createBinTreeByPreAndMidOrder(pre2, mid2, 5);
    print_deque(bst_to_sorted_deque(root));

    int pre3[] = {1, 2, 3, 4, 5};
    int mid3[] = {1, 2, 3, 4, 5};
    root = createBinTreeByPreAndMidOrder(pre3, mid3, 5);
    print_deque(bst_to_sorted_deque(root));

    int pre4[] = {1};
    int mid4[] = {1};
    root = createBinTreeByPreAndMidOrder(pre4, mid4, 1);
    print_deque(bst_to_sorted_deque(root));
}

void test_bt_deserialize() {
    int IMPOSIBE_LABEL = -99999;
    int data[] = {1, 2, 4, IMPOSIBE_LABEL, IMPOSIBE_LABEL, IMPOSIBE_LABEL, 3, 5, IMPOSIBE_LABEL, IMPOSIBE_LABEL, 6, IMPOSIBE_LABEL, IMPOSIBE_LABEL};
    bt_bfs_as_full_bt(bt_deserialize(data, sizeof(data)/sizeof(int)));

    int index  = 0;
    bt_bfs_as_full_bt(bt_deserialize_recursive(data, sizeof(data)/sizeof(int), &index));
}

void test_bt_find_node_path() {
    int pre1[] = {10, 6, 4, 8, 14, 12, 16};
    int mid1[] = {4, 6, 8, 10, 12, 14, 16};
    Node *root = createBinTreeByPreAndMidOrder(pre1, mid1, 7);
    // bt_bfs_as_full_bt(root);
    cout << bt_find_node_path(root, 12) << endl;
    cout << bt_find_node_path_recursive(root, 12) << endl;
    cout << "===========================" << endl;

    int pre2[] = {5, 4, 3, 2, 1};
    int mid2[] = {1, 2, 3, 4, 5};
    root = createBinTreeByPreAndMidOrder(pre2, mid2, 5);
    // bt_bfs_as_full_bt(root);
    cout << bt_find_node_path(root, 1) << endl;
    cout << bt_find_node_path_recursive(root, 1) << endl;
    cout << "===========================" << endl;

    int pre3[] = {1, 2, 3, 4, 5};
    int mid3[] = {1, 2, 3, 4, 5};
    root = createBinTreeByPreAndMidOrder(pre3, mid3, 5);
    // bt_bfs_as_full_bt(root);
    cout << bt_find_node_path(root, 3) << endl;
    cout << bt_find_node_path_recursive(root, 3) << endl;
    cout << "===========================" << endl;

    int pre4[] = {1};
    int mid4[] = {1};
    root = createBinTreeByPreAndMidOrder(pre4, mid4, 1);
    // bt_bfs_as_full_bt(root);
    cout << bt_find_node_path(root, 1) << endl;
    cout << bt_find_node_path_recursive(root, 1) << endl;
    cout << "===========================" << endl;
}


