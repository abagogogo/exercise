#include <iostream>

using namespace std;

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct Node {
    Node *left;
    Node *right;
    int   id;

    Node(int id) {
        this->id = id;
        left = right = nullptr;
    }
    ~Node(void) {
        delete left;
        delete right;
    }
};


void preorder(Node *root) {
    if (!root) return;

    cout << root->id << ",";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if (!root) return;

    inorder(root->left);
    cout << root->id << ",";
    inorder(root->right);
}

Node *bst_search(Node *root, int value) {
    if (!root) return nullptr;

    if (value == root->id) {
        return root;
    } else if (value < root->id) {
        return bst_search(root->left, value);
    } else {
        return bst_search(root->right, value);
    }
}

void bst_insert(Node *root, Node *node) {
    if (!root) {
        cout << "[ERROR] empty root, drop node " << endl;
        return;
    }
    if (!node) {
        cout << "[ERROR] empty node to insert" << endl;
        return;
    }

    if (node->id == root->id) {
        cout << "[ERROR] drop duplicated node " << endl;
    } else if (node->id < root->id) {
        if (root->left) bst_insert(root->left, node);
        else root->left = node;
    } else {
        if (root->right) bst_insert(root->right, node);
        else root->right = node;
    }
}

void bst_swap(Node *x, Node *y) {
    if (!x || !y) return;

    int tmp = x->id;
    x->id = y->id;
    y->id = tmp;
}

Node *bst_leftmost(Node *curr) {
    if (!curr) return nullptr;

    while (curr->left) {
        curr = curr->left;
    }
    return curr;
}

void bst_delete_r(Node *parent, Node *curr, int value) {
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
        bst_swap(curr, successor);
        bst_delete_r(curr, curr->right, value);
    } else {
        Node *only_child = (curr->left ? curr->left : curr->right);
        if (curr == parent->left) {
            parent->left = only_child;
        } else {
            parent->right = only_child;
        }
        curr->left = curr->right = nullptr; // To avoid its children deleted unexpected.
        delete curr;
        cout << value << " found and deleted" << endl; 
    }
}

void bst_delete(Node *root, int value) {
    if (!root) return;

    Node dummy(value - 1);
    dummy.right = root;
    bst_delete_r(&dummy, root, value);
    dummy.right = nullptr;
}

int main(void) {
    // Tree1 for preorder ////////
    Node *t1 = new Node(0);

    t1->left = new Node(1);
    t1->right = new Node(4);
    t1->left->left = new Node(2);
    t1->left->right = new Node(3);
    t1->right->left = new Node(5);

    cout << "t1 preorder..." << endl;
    preorder(t1);
    cout << endl;
    delete t1;

    // Tree2 for BST /////////
    Node *t2 = new Node(3);

    t2->left = new Node(1);
    t2->right = new Node(5);
    t2->left->left = new Node(0);
    t2->left->right = new Node(2);
    t2->right->left = new Node(4);

    cout << "t2 inorder..." << endl;
    inorder(t2);
    cout << endl;

    Node *found = bst_search(t2, 4);
    cout << "t2 search 4 => " << (found ? "found" : "[ERROR] NOT found") << endl;
    found = bst_search(t2, 2);
    cout << "t2 search 2 => " << (found ? "found" : "[ERROR] NOT found") << endl;
    found = bst_search(t2, 6);
    cout << "t2 search 6 => " << (found ? "[ERROR] found" : "NOT found") << endl;

    bst_insert(t2, new Node(6));
    found = bst_search(t2, 6);
    cout << "t2 search 6 => " << (found ? "found" : "[ERROR] NOT found") << endl;

    bst_insert(t2, new Node(-1));
    bst_insert(t2, new Node(-2));
    bst_insert(t2, new Node(7));
    bst_insert(t2, new Node(8));
    cout << "t2 inorder after insertion..." << endl;
    inorder(t2);
    cout << endl;

    bst_delete(t2, -2);
    bst_delete(t2, -1);
    bst_delete(t2, -3);
    bst_delete(t2, 7);
    bst_delete(t2, 8);
    bst_delete(t2, 1);
    cout << "t2 inorder after deletion..." << endl;
    inorder(t2);
    cout << endl;

    delete t2;
    return 0;
}
