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
      int min = minVal(root->right);
      root->data = min;
      root->right = nodeToDelete(root->right, min);
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

int minVal(BinaryTreeNode* &root) {
  BinaryTreeNode* temp = root;
  while(temp->left != NULL) {
    temp = temp->left;
  }
  return temp->data;
}

int maxVal(BinaryTreeNode* &root) {
  BinaryTreeNode* temp = root;
  while(temp->right != NULL) {
    temp = temp->right;
  }
  return temp->data;
}

bool isBST(BinaryTreeNode* root, int min, int max){
  if(root == NULL) return true;
  if(root->data >= min && root->data <= max) {
    bool leftAns = isBST(root->left, min, root->data);
    bool rightAns = isBST(root->right, root->data, max);
    return leftAns && rightAns;
  } else return false;
}

bool validateBST(BinaryTreeNode* &root) {
  return isBST(root, INT_MIN, INT_MAX);
}

int inorder(BinaryTreeNode* root, int& i, int k) {
  if(root == NULL) return -1;
  int leftAns = inorder(root->left, i, k);
  if(leftAns != -1) return leftAns;
  i++;
  if(i == k) return root->data;
  return inorder(root->right, i, k);
}

int kthSmallestElement(BinaryTreeNode* root, int k) {
  int i = 0;
  return inorder(root, i, k);
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
  root = nodeToDelete(root, 70);
  inorderTraversal(root);
  cout << validateBST(root) << endl;
}