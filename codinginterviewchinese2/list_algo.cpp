#include <iostream>

#include "widgets/list.h"

using namespace std;

void delete_duplication(LN* head) {
    if (!head)
        return;

    LN* cur = head;
    LN* tmp = NULL;
    while(cur) {
        while(cur->next && cur->next->value == cur->value) {
            tmp = cur->next->next;
            delete cur->next;
            cur->next = tmp;
        }
        cur = cur->next;
    }
}

LN* get_kth_to_tail(LN* head, unsigned int k) {
    if (!head || k == 0) 
        return NULL;

    LN* cur = head;
    for(unsigned int i = 0; i < k-1 && cur; i++) {
        cur = cur->next;
    }
    if (!cur)
        return NULL;
    
    LN* result = head;
    while(cur->next) {
        cur = cur->next;
        result = result->next;
    }

    return result;
}

LN* reverse_list(LN* head) {
    LN* pre = NULL;
    LN* cur = head;
    LN* tmp = NULL;
    while(cur) {
        tmp = cur;
        cur = cur->next;
        tmp->next = pre;
        pre = tmp;
    }
    return pre;
}

LN* merge_sorted_list(LN* h1, LN* h2) {
    LN* h = create_ln(0);
    LN* little = NULL;
    LN *tmp = h;
    while(h1 && h2) {
        if (h1->value < h2->value) {
            little = h1;
            h1 = h1->next;
        }
        else {
            little = h2;
            h2 = h2->next;
        }
        tmp->next = little;
        tmp = little;
    }

    LN *left = h1 ? h1 : h2;
    tmp->next = left;

    return h->next;
}

void test_delete_duplication() {
    cout << endl << "**************************************" << endl;
    int data1[] = {1, 2, 3, 3, 4, 4, 5};
    LN* head1 = create_list(data1, sizeof(data1)/sizeof(int));
    print_list(head1);
    delete_duplication(head1);
    print_list(head1);

    cout << endl << "**************************************" << endl;
    int data2[] = {1, 2, 3, 4, 5};
    LN* head2 = create_list(data2, sizeof(data2)/sizeof(int));
    print_list(head2);
    delete_duplication(head2);
    print_list(head2);

    cout << endl << "**************************************" << endl;
    int data3[] = {};
    LN* head3 = create_list(data3, sizeof(data3)/sizeof(int));
    print_list(head3);
    delete_duplication(head3);
    print_list(head3);
}

void test_get_kth_to_tail() {
    cout << endl << "**************************************" << endl;
    int data1[] = {1, 2, 3, 4, 5};
    LN* head1 = create_list(data1, sizeof(data1)/sizeof(int));
    print_ln(get_kth_to_tail(head1, 2));
    print_ln(get_kth_to_tail(head1, 1));
    print_ln(get_kth_to_tail(head1, 5));
    print_ln(get_kth_to_tail(head1, 6));
    print_ln(get_kth_to_tail(head1, 0));
    print_ln(get_kth_to_tail(NULL, 199));

    destroy_list(head1);
}

void test_reverse_list() {
    cout << endl << "test_reverse_list **************" << endl;
    cout << "**************************************" << endl;
    int data1[] = {1, 2, 3, 4, 5};
    LN* head1 = create_list(data1, sizeof(data1)/sizeof(int));
    print_list(head1);
    head1 = reverse_list(head1);
    print_list(head1);

    cout << "**************************************" << endl;
    LN* head2 = create_list(data1, 1);
    print_list(head2);
    head2 = reverse_list(head2);
    print_list(head2);

    cout << "**************************************" << endl;
    LN* head3 = create_list(NULL, 1);
    print_list(head3);
    head3 = reverse_list(head3);
    print_list(head3);

    destroy_list(head1);
    destroy_list(head3);
}

void test_merge_sorted_list() {
    cout << endl << "test_merge_sorted_list **************" << endl;
    cout << "**************************************" << endl;
    int data1[] = {1, 3, 5};
    LN* head1 = create_list(data1, sizeof(data1)/sizeof(int));
    int data2[] = {2, 4, 6};
    LN* head2 = create_list(data2, sizeof(data2)/sizeof(int));
    LN* merged = merge_sorted_list(head1, head2);
    print_list(merged);

    cout << "**************************************" << endl;
    head1 = create_list(data1, sizeof(data1)/sizeof(int));
    head2 = create_list(data1, sizeof(data1)/sizeof(int));
    merged = merge_sorted_list(head1, head2);
    print_list(merged);

    cout << "**************************************" << endl;
    head1 = create_list(data1, 1);
    head2 = create_list(data2, 1);
    merged = merge_sorted_list(head1, head2);
    print_list(merged);

    cout << "**************************************" << endl;
    head1 = create_list(data1, sizeof(data1)/sizeof(int));
    merged = merge_sorted_list(head1, NULL);
    print_list(merged);

    cout << "**************************************" << endl;
    merged = merge_sorted_list(NULL, NULL);
    print_list(merged);
}




