#include <iostream>

#include "test.h"

using namespace std;

Node* create_bintree() {
    int pre[] = {1, 2, 3, 4, 5, 6};
    int mid[] = {3, 2, 5, 4, 1, 6};

    // int pre[] = {1, 2, 4, 5, 3, 6, 7};
    // int mid[] = {4, 2, 5, 1, 6, 3, 7};
    Node* tree = createBinTreeByPreAndMidOrder(pre, mid, sizeof(pre)/sizeof(int));
    return tree;
}