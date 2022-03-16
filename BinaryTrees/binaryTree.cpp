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

// Level order traversal
void printLevelOrder(BinaryTreeNode* root) {
  if(root == NULL) return;
  queue<BinaryTreeNode*> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()) {
    BinaryTreeNode* node = q.front();
    q.pop();

    if(node != NULL) {
      if(node->left) q.push(node->left);
      if(node->right) q.push(node->right);
    } else{ 
      if(!q.empty()) q.push(NULL);
    }
  }
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

int getPosition(int in[], int start, int end, int curr) {
  for(int i = start; i <= end; i++) {
    if(in[i] == curr) return i;
  }
  return -1;
}

// Buid Tree from inorder and preorder
BinaryTreeNode* buildTree(int pre[], int in[], int start, int end) {
  static int index = 0;
  
  if(start > end) return NULL;

  int curr = pre[index];
  index++;
  BinaryTreeNode* currNode = new BinaryTreeNode(curr);
  int position = getPosition(in, start, end, curr);
  currNode->left = buildTree(pre, in, start, position-1);
  currNode->right = buildTree(pre, in, position+1, end);
  return currNode;
}

int getPositionOther(int inorder[], int start, int end, int curr) {
  for(int i = start; i <= end; i++) if(inorder[i] == curr) return i;
}

// Build Tree from postorder and inorder
BinaryTreeNode* buildTreeOther(int pos[], int in[], int start, int end) {
  static int index = end;

  if(start > end) return NULL;
  int curr = pos[index];
  index--;

  BinaryTreeNode* currNode = new BinaryTreeNode(curr);
  int position = getPositionOther(in, start, end, curr);
  currNode->right = buildTreeOther(pos, in, position+1, end);
  currNode->left = buildTreeOther(pos, in, start, position-1);
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

void leftTraversal(BinaryTreeNode* root, vector<int>& ans) {
  if(root == NULL) return;
  if(root->left == NULL && root->right == NULL) return;

  ans.push_back(root->data);
  if(root->left) leftTraversal(root->left, ans);
  else leftTraversal(root->right, ans);
}

void leafTraversal(BinaryTreeNode* root, vector<int>& ans) {
  if(root == NULL) return;
  if(root->left == NULL && root->right == NULL) {
    ans.push_back(root->data);
    return;
  }
  
  leafTraversal(root->left, ans);
  leafTraversal(root->right, ans);
}

void rightTraversal(BinaryTreeNode* root, vector<int>& ans) {
  if(root == NULL) return;
  if(root->left == NULL && root->right == NULL) return;

  if(root->right) rightTraversal(root->right, ans);
  else rightTraversal(root->left, ans);
  ans.push_back(root->data);
}

// Boundary Traversal
vector<int> boundaryTraversal(BinaryTreeNode* root) {
  vector<int> ans;
  if(root == NULL) return ans;

  leftTraversal(root->left, ans);
  leafTraversal(root->left, ans);
  leafTraversal(root->right, ans);
  rightTraversal(root->right, ans);
  return ans;
}

// Top view of binary Tree
void topView(BinaryTreeNode* root) {
  if(root == NULL) return;

  map<int, int> mapp;
  queue<pair<BinaryTreeNode*, int>> q;
  q.push({root, 0});

  while(!q.empty()) {
    BinaryTreeNode* tempNode = q.front().first;
    int height = q.front().second;
    q.pop();

    if(!mapp[height]) mapp[height] = tempNode->data;
    if(tempNode->left) q.push({tempNode->left, height-1});
    if(tempNode->right) q.push({tempNode->right, height+1});
  }

  for(auto i : mapp) cout << i.second << " ";
}

vector<int> leftView(BinaryTreeNode* root) {
  vector<int> ans;
  if(root == NULL) return ans;

  queue<BinaryTreeNode*> q;
  q.push(root);

  while(!q.empty()) {
    int size = q.size();
    BinaryTreeNode* frontNode = q.front();
    ans.push_back(frontNode->data);
    while(size--) {
      BinaryTreeNode* front = q.front();
      q.pop();
      if(front->left) q.push(front->left);
      if(front->right) q.push(front->right);
    }
  }
  return ans;
}

vector<int> rightView(BinaryTreeNode* root) {
  vector<int> ans;
  if(root == NULL) return ans;

  queue<BinaryTreeNode*> q;
  q.push(root);

  while(!q.empty()) {
    int size = q.size();
    BinaryTreeNode* frontNode = q.front();
    ans.push_back(frontNode->data);
    while(size--) {
      BinaryTreeNode* front = q.front();
      q.pop();
      if(front->right) q.push(front->right);
      if(front->left) q.push(front->left);
    }
  }
  return ans;
}

vector<int> bottomView(BinaryTreeNode* root) {
  vector<int> ans;
  if(root == NULL) return ans;
  
  map<int, int> mapp;
  queue<pair<BinaryTreeNode*, int>> q;
  q.push({root, 0});

  while(!q.empty()) {
    BinaryTreeNode* frontNode = q.front().first;
    int height = q.front().second;
    q.pop();

    mapp[height] = frontNode->data;
    if(frontNode->left) q.push({frontNode->left, height-1});
    if(frontNode->right) q.push({frontNode->right, height+1});
  }
  for(auto i : mapp) ans.push_back(i.second);
  return ans;
}

int main() {
  BinaryTreeNode* root = new BinaryTreeNode(1);
  root->left = new BinaryTreeNode(2);
  root->left->left = new BinaryTreeNode(4);
  root->left->left->right = new BinaryTreeNode(8);
  root->left->right = new BinaryTreeNode(5);
  root->right = new BinaryTreeNode(3);
  root->right->right = new BinaryTreeNode(7);
  root->right->left =  new BinaryTreeNode(6);
  vector<int> result = bottomView(root);
  for(auto i : result) cout << i << " ";
  // vector<int> result = rightView(root);
  // for(int i = 0; i < result.size(); i++) cout << result[i] << " ";  
  // vector<int> result = leftView(root);
  // for(int i = 0; i < result.size(); i++) cout << result[i] << " ";
  // topView(root);
  // cout << "Height Of Binary Tree is: " << maxDepth(root) << endl;
  // cout << balancBinaryTree(root);
  // cout << endl;
  // cout << "The diameter of binary tree is: " << diameter(root) << endl;
  // pair<int, int> p = heightDiameter(root);
  // cout << "Height: " << p.first << endl <<  "Diameter: " << p.second << endl;
  // printLevelOrder(root);
  // vector<int> boundaryNodes = boundaryTraversal(root);
  // for(int i = 0; i < boundaryNodes.size(); i++) cout << boundaryNodes[i] << " ";
  // int preOrder[] = {1, 2, 4, 3, 5};
  // int inOrder[] = {4, 2, 1, 5, 3};
  // BinaryTreeNode* newRoot = buildTree(preOrder, inOrder, 0, 4);
  // inOrderTraversal(newRoot);
  // cout << endl;
  // int postOrder[] = {1, 2, 4, 3, 5};
  // int inorder[] = {4, 2, 1, 5, 3};
  // BinaryTreeNode* newRootOther = buildTreeOther(postOrder, inorder, 0, 4);
  // inOrderTraversal(newRootOther);
  // BinaryTreeNode* newRoot = buildTree(preOrder, inOrder, 0, 4);
  // vector<int> result = preOrderIterative(root);
  // for(int i = 0; i < result.size(); i++) cout << result[i] << " ";
  // inOrderTraversal(root);
  // preOrderTraversal(root);
  // postOrderTraversal(root);
  return 0;
}