#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node(int a_data) : data(a_data) {}
    Node *prev;
    Node *next;
    int   data;
};

struct DList {
    Node *head;
    Node *tail;
};

void insert(DList *list, Node *node) {
    if (!list->head) {
        list->head = node;
    } else {
        list->tail->next = node;
        node->prev = list->head;
    }
    list->tail = node;
}

Node *reverse(Node *head) {
    if (!head) return nullptr;

    Node *prev = nullptr;
    Node *curr = head;
    Node *next = head->next;

    while (curr) {
        curr->prev = next;
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next) next = next->next;
    }
    return prev;
}

void remove_dup(Node *head) {
    unordered_set<int> set;
    Node *prev = nullptr;
    Node *curr = head;
    while (curr) {
        if (set.find(curr->data) == set.end()) {
            set.insert(curr->data);
            prev = curr;
        } else {
            prev->next = curr->next;
        }
        curr = curr->next;
    }
}

Node *get_kth(Node *head, int k) {
  Node *runner = head;
  for (int i = 0; i < k && runner; ++i) {
    runner = runner->next;
  }
  return runner;
}

Node *get_kth_to_last(Node *head, int k) {
    Node *runner = get_kth(head, k);
    if (!runner) return nullptr;
    
    Node *curr = head;
    while (runner) {
        runner = runner->next;
        curr = curr->next;
    }
    return curr;
}

Node *add_rev_list_helper(Node *l1, Node *l2, int carry) {
    if (!l1 && !l2 && !carry) return nullptr;
    int sum = carry;
    if (l1) sum += l1->data;
    if (l2) sum += l2->data;
    Node *node = new Node(sum % 10);
    node->next = add_rev_list_helper(
                    (l1 ? l1->next : nullptr),
                    (l2 ? l2->next : nullptr),
                    sum / 10);
    return node;
}

Node *add_rev_list(Node *l1, Node *l2) {
        return add_rev_list_helper(l1, l2, 0);
}

int main() {
    return 0;
}
