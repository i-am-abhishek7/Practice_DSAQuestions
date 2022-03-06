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

// The time complexity of this code is O(n^2)
int diameter(BinaryTreeNode* root) {
  if(root == NULL) return 0;
  int option1 = maxDepth(root->left) + maxDepth(root->right);
  int option2 = diameter(root->left);
  int option3 = diameter(root->right);

  return max(option1, max(option2, option3));
}

// Time complexity of this code is O(n).
pair<int, int> heightDiameter(BinaryTreeNode* root) {
  if(root == NULL) {
    pair<int, int> p;
    p.first = 0;
    p.second = 0;
    return p;
  }

  pair<int, int> leftAns = heightDiameter(root->left);
  pair<int, int> rightAns = heightDiameter(root->right);

  int leftHeight = leftAns.first;
  int rightHeight = rightAns.first;
  int leftDiameter = leftAns.second;
  int rightDiameter = rightAns.second;

  int height = 1 + max(leftHeight, rightHeight);
  int diameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));

  pair<int, int> p;
  p.first = height;
  p.second = diameter;
  return p;
}

int main() {
  BinaryTreeNode* root = new BinaryTreeNode(1);
  root->left = new BinaryTreeNode(2);
  root->right = new BinaryTreeNode(7);
  root->left->left = new BinaryTreeNode(3);
  root->left->right = new BinaryTreeNode(5);
  root->left->left->left = new BinaryTreeNode(4);
  root->left->right->right = new BinaryTreeNode(6);
  cout << "Height Of Binary Tree is: " << maxDepth(root) << endl;
  cout << balancBinaryTree(root);
  cout << endl;
  cout << "The diameter of binary tree is: " << diameter(root) << endl;
  pair<int, int> p = heightDiameter(root);
  cout << "Height: " << p.first << endl <<  "Diameter: " << p.second << endl;
  // vector<int> result = preOrderIterative(root);
  // for(int i = 0; i < result.size(); i++) cout << result[i] << " ";
  // inOrderTraversal(root);
  // preOrderTraversal(root);
  // postOrderTraversal(root);
  return 0;
}