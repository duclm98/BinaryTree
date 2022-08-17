#include <iostream>
using namespace std;

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