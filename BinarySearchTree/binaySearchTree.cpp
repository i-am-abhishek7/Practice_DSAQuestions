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

bool hasNode(BinaryTreeNode* &root, int data) {
  if(root == NULL) return false;
  if(root->data == data) return true;
  if(data > root->data) return hasNode(root->right, data);
  else return hasNode(root->left, data);
}

BinaryTreeNode* nodeToDelete(BinaryTreeNode* &root, int data) {
  if(root == NULL) return root;
  if(root->data == data) {
    if(root->left == NULL && root->right == NULL) {
      delete root;
      return NULL;
    } 
    if(root->left != NULL && root->right == NULL) {
      BinaryTreeNode* temp = root->left;
      delete root;
      return temp;
    }
    if(root->left == NULL && root->right != NULL) {
      BinaryTreeNode* temp = root->right;
      delete root;
      return temp;
    }
    if(root->left != NULL && root->right != NULL) {
      int mivVal = minVal(root->right)->data;
      root->data = minVal;
      root->right = nodeToDelete(root->right, minVal);
      return root;
    }
  } else if(root->data > data) {
    root->left = nodeToDelete(root->left, data);
    return root;
  } else {
    root->right = nodeToDelete(root->right, data);
    return root;
  }
}

BinaryTreeNode* minVal(BinaryTreeNode* &root) {
  BinaryTreeNode* temp = root;
  while(temp->left != NULL) {
    temp = temp->left;
  }
  return temp;
}

BinaryTreeNode* maxVal(BinaryTreeNode* &root) {
  BinaryTreeNode* temp = root;
  while(temp->right != NULL) {
    temp = temp->right;
  }
  return temp;
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
  cout << hasNode(root, 8);
  // inorderTraversal(root);
}