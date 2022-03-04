#include<bits/stdc++.h>
#include "BinaryTree.h"
using namespace std;

void inOrderTraversal(BinaryTreeNode* root) {
  if(root == NULL) return;
  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}

void preOrderTraversal(BinaryTreeNode* root) {
  if(root == NULL) return;
  cout << root->data << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

void postOrderTraversal(BinaryTreeNode* root) {
  if(root == NULL) return;
  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->data << " ";
}

int main() {
  BinaryTreeNode* root = new BinaryTreeNode(10);
  root->left = new BinaryTreeNode(20);
  root->left->left = new BinaryTreeNode(40);
  root->left->right = new BinaryTreeNode(50);
  root->right = new BinaryTreeNode(30);
  root->right->left = new BinaryTreeNode(60);
  // inOrderTraversal(root);
  // preOrderTraversal(root);
  postOrderTraversal(root);
  return 0;
}