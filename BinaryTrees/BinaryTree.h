#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
  public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data) {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
    }
};  