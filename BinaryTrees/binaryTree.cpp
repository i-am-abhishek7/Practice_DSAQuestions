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

vector<vector<int>> levelOrderTraversal(BinaryTreeNode* root) {
  vector<vector<int>> ans;
  if(root == NULL) return ans;
  queue<BinaryTreeNode*> q;
  q.push(root);

  while(!q.empty()) {
    int size = q.size();
    vector<int> levels;
    for(int i = 0; i < size; i++) {
      BinaryTreeNode* frontNode = q.front();
      q.pop();
      if(frontNode->left != NULL) q.push(frontNode->left);
      if(frontNode->right != NULL) q.push(frontNode->right);
      levels.push_back(frontNode->data);
    }
    ans.push_back(levels);
  }
  return ans;
}

vector<int> preOrderIterative(BinaryTreeNode* root) {
  vector<int> ans;
  if(root == NULL) return ans;
  stack<BinaryTreeNode*> st;
  st.push(root);

  while(!st.empty()) {
    root = st.top();
    st.pop();
    ans.push_back(root->data);
    if(root->right != NULL) st.push(root->right);
    if(root->left != NULL) st.push(root->left);
  }
  return ans;
}

int maxDepth(BinaryTreeNode* root) {
  if(root == NULL) return 0;
  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int dfsHeight(BinaryTreeNode* root) {
  if(root == NULL) return 0;
  int leftHeight = dfsHeight(root->left);
  if(leftHeight == -1) return -1;
  int rightHeight = dfsHeight(root->right);
  if(rightHeight == -1) return -1;
  if(abs(rightHeight - leftHeight) > 1) return -1;
  return 1 + max(leftHeight, rightHeight);
}

bool balancBinaryTree(BinaryTreeNode* root) {
  return dfsHeight(root) != -1;
}

int main() {
  BinaryTreeNode* root = new BinaryTreeNode(10);
  root->left = new BinaryTreeNode(20);
  root->right = new BinaryTreeNode(30);
  root->right->left = new BinaryTreeNode(40);
  root->right->left->left = new BinaryTreeNode(50);
  root->right->right = new BinaryTreeNode(60);
  cout << "Height Of Binary Tree is: " << maxDepth(root) << endl;
  cout << balancBinaryTree(root);
  // vector<int> result = preOrderIterative(root);
  // for(int i = 0; i < result.size(); i++) cout << result[i] << " ";
  // inOrderTraversal(root);
  // preOrderTraversal(root);
  // postOrderTraversal(root);
  return 0;
}