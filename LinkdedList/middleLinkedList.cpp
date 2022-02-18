#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int data) {
      this->data = data;
      this->next = NULL;
    }
};

int findLength(Node* head) {
  int len = 0;
  while(head != NULL) {
    len++;
    head = head->next;
  }
  return len;
}

Node* findMiddleOfLinkedList(Node* head) {
  int length = findLength(head);
  int middle = (length/2);
  Node* temp = head;
  int count = 0;
  while(count < middle) {
    temp = temp->next;
    count++;
  }
  return temp;
}

Node* findMiddleOfLinkedList2(Node* head) {
  if(head == NULL || head->next == NULL) return head;
  if(head->next->next == NULL) return head->next;

  Node* fast = head->next;
  Node* slow = head;
  while(fast != NULL) {
    fast = fast->next;
    if(fast != NULL) {
      fast = fast->next;
    }
    slow = slow->next;
  }
  return slow;
}

void printLinkedList(Node* head) {
  Node* temp = head;
  while(temp != NULL) {
    cout << temp->data << "->";
    temp = temp->next;
  } cout << "NULL" << endl;
}

int main() {
  Node* node1 = new Node(10);
  Node* node2 = new Node(20);
  Node* node3 = new Node(30);
  Node* node4 = new Node(40);
  Node* node5 = new Node(50);
  Node* node6 = new Node(60);
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = node6;
  Node* head = node1;
  printLinkedList(head);
  // Node* middleNode = findMiddleOfLinkedList(head);
  Node* middleNode = findMiddleOfLinkedList2(head);
  cout << "The middle node of linked list is: " << middleNode->data << endl;
  return 0;
}