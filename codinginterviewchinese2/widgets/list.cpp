#include <iostream>

#include "list.h"

using namespace std;

LN* create_ln(int value);
void con_ln(LN* cur, LN* next);
void print_ln(LN* node);
void print_list(LN* head);
void destroy_list(LN* head);
void add_to_tail(LN** head, int value);
void remove_node(LN** head, int value);

LN* create_ln(int value) {
    LN *n = new LN();
    n->value = value;
    n->next = NULL;
    return n;
}

void con_ln(LN* cur, LN* next) {
    if (cur)
        cur->next = next;
}

void print_ln(LN* node) {
    if (node) {
        cout << node 
             << " => {\"value\": " << node->value << ", \"next\": " << node->next << "}" << endl;
    }
    else {
        cout << "{ NULL NODE }" << endl;
    }
}

LN* create_list(int* values, int len) {
    LN* pre_head = create_ln(0);
    LN* cur = pre_head;
    if (values && len > 0) {
        for(int i=0; i<len; ++i) {
            cur->next = create_ln(values[i]);
            cur = cur->next;
        }
    }

    LN* head = pre_head->next;
    delete pre_head;
    return head;
}

void print_list(LN* head) {
    cout << "---------- LIST BEGIN ----------" << endl;
    LN* cur = head;
    while(cur) {
        print_ln(cur);
        cur = cur->next;
    }
    cout << "----------  LIST END  ----------" << endl;
}

void destroy_list(LN* head) {
    if (head) {
        LN* cur = head;
        LN* next = NULL;
        while(cur) {
            next = cur->next;
            delete cur;
            cur = next;
        }
    }
}

void add_to_tail(LN** head, int value) {
    LN* node = create_ln(value);
    if (head && !(*head)) {
        (*head) = node;
        return;
    }

    if (head) {
        LN* cur = *head;
        while(cur->next) {
            cur = cur->next;
        }
        cur->next = node;
    }
}

void remove_node(LN** head, int value) {
    if (head == NULL || *head == NULL)
        return;
    
    LN *to_del = NULL;
    if ((*head)->value == value)
    {
        to_del = (*head);
        (*head) = (*head)->next;
    }
    else {
        LN* cur = (*head);
        while(cur->next && cur->next->value != value) {
            cur = cur->next;
        }
        if (cur->next) {
            to_del = cur->next;
            cur->next = cur->next->next;
        }
    }

    if (to_del) {
        delete to_del;
        to_del = NULL;
    }

}