#include <bits/stdc++.h>

using namespace std;

struct SinglyLinkedListNode {
    SinglyLinkedListNode() {}
    SinglyLinkedListNode* next;
};

bool has_cycle(SinglyLinkedListNode *head) {
  SinglyLinkedListNode *fast = head;
  SinglyLinkedListNode *slow = head;

  while ((fast && fast->next) && slow) {
    fast = fast->next->next;
    slow = slow->next;
    if (!fast || !slow) return false;
    if (fast == slow) return true;
  }
  return false;
}

int main() {
  auto head = std::make_unique<SinglyLinkedListNode>();
  auto n1 =  std::make_unique<SinglyLinkedListNode>();
  auto n2 =  std::make_unique<SinglyLinkedListNode>();
  head.get()->next = n1.get();
  n1.get()->next = n2.get();
  n2.get()->next = head.get();

  if (has_cycle(head.get())) {
    cout << "Cycle found in the list" << endl;
  } else {
    cout << "No cycle found in the list" << endl;
  }

  cout << "Removing cycle..." << endl;
  n2.get()->next = nullptr;
  if (has_cycle(head.get())) {
    cout << "Cycle found in the list" << endl;
  } else {
    cout << "No cycle found in the list" << endl;
  }

  return 0;
}
