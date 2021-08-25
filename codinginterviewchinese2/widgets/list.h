#ifndef CODINGINTERVIEWCHINERSE2_LIST_H
#define CODINGINTERVIEWCHINERSE2_LIST_H

typedef struct ListNode {
    int value;
    ListNode *next;
}LN;

LN* create_ln(int value);
void con_ln(LN* cur, LN* next);
void print_ln(LN* node);
LN* create_list(int *value, int len);
void print_list(LN* head);
void destroy_list(LN* head);
void add_to_tail(LN** head, int value);
void remove_node(LN** head, int value);


#endif