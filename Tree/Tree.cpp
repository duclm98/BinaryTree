#include <iostream>
#include <limits.h>
using namespace std;

#define IMAX INT_MAX

struct Node {
    int val;
    Node* left;
    Node* right;
};

Node* CreateNode(int val) {
    Node* node = new Node;
    if (node == NULL)
        return NULL;
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* InsertNode(Node* node, int val) {
    if (node == NULL)
        node = CreateNode(val);
    else {
        if (node->val == val)
            return node;
        else if (val < node->val) {
            Node* left = node->left;
            node->left = InsertNode(left, val);
        }
        else {
            Node* right = node->right;
            node->right = InsertNode(right, val);
        }
    }
    return node;
}

Node* FindNode(Node* node, int val) {
    if (node == NULL)
        return NULL;

    if (val == node->val)
        return node;
    else if (val < node->val)
        FindNode(node->left, val);
    else
        FindNode(node->right, val);
}

Node* FindParentNode(Node* node, int val, int level) {
    if (node == NULL)
        return NULL;
    
    if (val == node->val) {
        if (level == 0)
            return NULL;
        else
            return CreateNode(IMAX);
    }
    else if (val < node->val) {
        Node* left = FindParentNode(node->left, val, level + 1);
        if (left != NULL && left->val == IMAX)
            return node;
    }
    else {
        Node* right = FindParentNode(node->right, val, level + 1);
        if (right != NULL && right->val == IMAX)
            return node;
    }
}

Node* RemoveNode(Node* node, int val) {
    if (node == NULL)
        return NULL;
    if (val == node->val) {
        if (node->left == NULL && node->right == NULL) {
            Node* parent = FindParentNode(node, val, 0);
            if (parent != NULL) {
                if (val < parent->val)
                    parent->left = NULL;
                else {
                    parent->right = NULL;
                }
            }
            delete node;
        }
        else if (node->left != NULL && node->right == NULL) {

        }
        else if (node->left == NULL && node->right != NULL) {

        }
        else
        {

        }
    }
    else if (val < node->val) {
        RemoveNode(node->left, val);
    }
    else {
        RemoveNode(node->right, val);
    }
}

void NLR(Node* node) {
    if (node == NULL)
        return;
    cout << node->val << "\t";
    NLR(node->left);
    NLR(node->right);
}

void LNR(Node* node) {
    if (node == NULL)
        return;
    LNR(node->left);
    cout << node->val << "\t";
    LNR(node->right);
}

void LRN(Node* node) {
    if (node == NULL)
        return;
    LRN(node->left);
    LRN(node->right);
    cout << node->val << "\t";
}

int main()
{
    Node* root = NULL;
    int val;
    bool flag = true;
    while (flag)
    {
        cout << "Nhap vao node: ";
        cin >> val;
        if (val != 0) {
            root = InsertNode(root, val);
        }
        else {
            flag = false;
        }
    }

    cout << "Duyet cay theo thu tu Node-Left-Right: " << endl;
    NLR(root);
    cout << endl;

    cout << "Duyet cay theo thu tu Left-Node-Right: " << endl;
    LNR(root);
    cout << endl;

    cout << "Duyet cay theo thu tu Left-Right-Node: " << endl;
    LRN(root);
    cout << endl;

    return 0;
}