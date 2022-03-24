#include<bits/stdc++.h>
#include"binaryTree.h"
using namespace std;

BinaryTreeNode* insertIntoBST(BinaryTreeNode* &root, int data) {
  if(root == NULL) {
    root = new BinaryTreeNode(data);
    return root;
  }

  // go to right part
  if(data > root->data) root->right = insertIntoBST(root->right, data);
  // go to left part
  else root->left = insertIntoBST(root->left, data);
  return root;
}

void takeInput(BinaryTreeNode* &root) {
  int data;
  cin >> data;

  while(data != -1) {
    root = insertIntoBST(root, data);
    cin >> data;
  }
}

void inorderTraversal(BinaryTreeNode* &root) {
  if(root == NULL) return;
  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}

int main() {
  BinaryTreeNode* root = NULL;
  takeInput(root);
  inorderTraversal(root);
}