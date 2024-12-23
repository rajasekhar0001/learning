/**
 * 
 */

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int val;
    Node * left;
    Node * right;
    Node(int v) {
        left = nullptr;
        right = nullptr;
        val = v;
    }
};

class Solution {
    public:
    void findLeftBoundaries(Node* root, vector<int> &res) {
        if (root == nullptr)
            return;
        while(root) {
            if (root->left && root->right)
                res.push_back(root->val);
            if (!root->left)
                root = root->right;
            else
                root = root->left;
        }
    }

    void findRightBoundaries(Node* root, vector<int> &res) {
        if (!root)
            return;
        // if ()
        while (root) {
            if (root->left && root->right)
                res.push_back(root->val);
            if (!root->right)
                root= root->left;
            else
                root= root->right;
        }
    }

    void findLeafNodes(Node* root, vector<int> &res) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right== nullptr) {
            res.push_back(root->val);
            return;
        }
        findLeafNodes(root->left, res);
        findLeafNodes(root->right, res);
    }
    vector<int> printBoundary(Node* root) {
        if (!root)
            return {};
        vector<int> res;
        res.push_back(root->val);
        findLeftBoundaries(root->left, res);
        findLeafNodes(root, res);
        findRightBoundaries(root->right, res);
        return res;
    }

    void printResult(vector<int> &arr) {
        for (int i: arr) {
            cout << i << " ";
        } cout << endl;
    }
};

void iterativeTraversalOfTree(Node* root) {
    if (!root)
        return;
    
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Get the boundary traversal
    vector<int> result = solution.printBoundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    solution.printResult(result);
}