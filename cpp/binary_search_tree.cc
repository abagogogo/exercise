#include <algorithm>
#include <climits>
#include <iostream>
#include <memory> // for smart pointers

using namespace std;

struct Node {
    std::unique_ptr<Node> left = nullptr;
    std::unique_ptr<Node> right = nullptr;
    int id;

    Node(int id) : id(id) {}
};

void preorder(const Node *root) {
    if (!root) return;

    cout << root->id << ", ";
    preorder(root->left.get());
    preorder(root->right.get());
}

void inorder(const Node *root) {
    if (!root) return;

    inorder(root->left.get());
    cout << root->id << ", ";
    inorder(root->right.get());
}

std::unique_ptr<Node> makeTree1() {
  auto root = std::make_unique<Node>(0);

  root->left = std::make_unique<Node>(1);
  root->right = std::make_unique<Node>(4);
  root->left->left = std::make_unique<Node>(2);
  root->left->right = std::make_unique<Node>(3);
  root->right->left = std::make_unique<Node>(5);
  return root;
}

std::unique_ptr<Node>makeTree2() {
  auto root = std::make_unique<Node>(3);

  root->left = std::make_unique<Node>(1);
  root->right = std::make_unique<Node>(5);
  root->left->left = std::make_unique<Node>(0);
  root->left->right = std::make_unique<Node>(2);
  root->right->left = std::make_unique<Node>(4);
  return root;
}

const Node *bst_search(std::unique_ptr<Node> &root, int value) {
  if (!root) return nullptr;

  if (value == root->id) {
    return root.get();
  } else if (value < root->id) {
    return bst_search(root->left, value);
  } else {
    return bst_search(root->right, value);
  }
}

void bst_insert(std::unique_ptr<Node> &root, std::unique_ptr<Node> node) {
  if (!node) {
    cout << "[ERROR] empty node to insert" << endl;
    return;
  }

  if (node->id == root->id) {
    cout << "[ERROR] drop duplicated node " << node->id << endl;
  } else if (node->id < root->id) {
    if (root->left)
      bst_insert(root->left, std::move(node));
    else
      root->left = std::move(node);
  } else {
    if (root->right)
      bst_insert(root->right, std::move(node));
    else
      root->right = std::move(node);
  }
}

void bst_swap(Node *x, Node *y) {
  if (!x || !y) return;

  swap(x->id, y->id);
}

Node *bst_leftmost(std::unique_ptr<Node> &curr) {
  if (!curr) return nullptr;

  Node *ptr = curr.get();
  while (ptr->left.get()) {
    ptr = ptr->left.get();
  }
  return ptr;
}

void bst_delete_r(std::unique_ptr<Node> &parent, std::unique_ptr<Node> &curr, int value) {
  if (!parent || !curr) {
    cout << "[WARNING] value to delete is not found!" << value << endl;
    return;
  }

  if (value < curr->id) {
    bst_delete_r(curr, curr->left, value);
    return;
  }
  if (value > curr->id) {
    bst_delete_r(curr, curr->right, value);
    return;
  }

  // Delete key here
  if (curr->left && curr->right) {
    Node *successor = bst_leftmost(curr->right);
    bst_swap(curr.get(), successor);
    bst_delete_r(curr, curr->right, value);
  } else {
    std::unique_ptr<Node> &only_child = (curr->left ? curr->left : curr->right);
    if (curr.get() == parent->left.get()) {
      parent->left = std::move(only_child);
    } else {
      parent->right = std::move(only_child);
    }
    curr.reset();
    cout << value << " found and deleted" << endl;
  }
}

void bst_delete(std::unique_ptr<Node> &root, int value) {
  if (!root) return;

  auto dummy = std::make_unique<Node>(value - 1);
  dummy->right = std::move(root);
  bst_delete_r(dummy, dummy->right, value);
  root = std::move(dummy->right);
}

int main() {
  // Tree1 for preorder ////////
  auto t1 = makeTree1();
  cout << "t1 preorder..." << endl;
  preorder(t1.get()); // Method 1: pass a raw pointer.
  cout << endl;

  // Tree2 for BST /////////
  auto t2 = makeTree2();
  cout << "t2 inorder..." << endl;
  inorder(t2.get());
  cout << endl;

  // Method 2: Pass a reference of a smart pointer for BST operations.
  auto found = bst_search(t2, 4);
  cout << "t2 search 4 => " << (found ? "found" : "[ERROR] NOT found") << endl;
  found = bst_search(t2, 2);
  cout << "t2 search 2 => " << (found ? "found" : "[ERROR] NOT found") << endl;
  found = bst_search(t2, 6);
  cout << "t2 search 6 => " << (found ? "[ERROR] found" : "NOT found") << endl;

  cout << "inserting 6..." << endl;
  bst_insert(t2, std::make_unique<Node>(6));
  found = bst_search(t2, 6);
  cout << "t2 search 6 => " << (found ? "found" : "[ERROR] NOT found") << endl;

  bst_insert(t2, std::make_unique<Node>(-1));
  bst_insert(t2, std::make_unique<Node>(-2));
  bst_insert(t2, std::make_unique<Node>(7));
  bst_insert(t2, std::make_unique<Node>(8));
  cout << "t2 inorder after insertion..." << endl;
  inorder(t2.get());
  cout << endl;

  bst_delete(t2, -2);
  bst_delete(t2, -1);
  bst_delete(t2, -3);
  bst_delete(t2, 7);
  bst_delete(t2, 8);
  bst_delete(t2, 1);
  cout << "t2 inorder after deletion..." << endl;
  inorder(t2.get());
  cout << endl;

  return 0;
}
