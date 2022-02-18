#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
      this->data = data;
      this->next = NULL;
      this->prev = NULL;
    }
};

void printLinkedList(Node* head) {
  Node* temp = head;
  while(temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  } cout << endl;
}

int getLength(Node* head) {
  Node* temp = head;
  int count = 0;
  while(temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

void insertAtHeadNode(Node* &head, int data) {
  Node* newNode = new Node(data);
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

void insertAtTail(Node* &tail, int data) {
  Node* newNode = new Node(data);
  tail->next = newNode;
  newNode->prev = tail;
  tail = newNode;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int pos) {
  if(pos == 1) {
    insertAtHeadNode(head, data);
    return;
  }
  Node* temp = head;
  int count = 1;
  while(count < pos-1) {
    temp = temp->next;
    count++;
  }

  if(temp->next == NULL) {
    insertAtTail(tail, data);
    return;
  }
  Node* newNode = new Node(data);
  newNode->next = temp->next;
  temp->next->prev = newNode;
  temp->next = newNode;
  newNode->prev = temp;
}

int main() {
  Node* node1 = new Node(10);
  // Node* node2 = new Node(20);
  // Node* node3 = new Node(30);
  // Node* node4 = new Node(40);
  Node* head = node1;
  Node* tail = node1;
  // node1->next = node2;
  // node2->next = node3;
  // node3->next = node4;
  // node2->prev = node1;
  // node3->prev = node2;
  // node4->prev = node3;
  printLinkedList(head);
  // cout << "The length of linked list is: " << getLength(head) << endl;
  insertAtHeadNode(head, 50);
  insertAtHeadNode(head, 40);
  insertAtHeadNode(head, 30);
  insertAtHeadNode(head, 20);
  printLinkedList(head);
  // insertAtTail(tail, 100);
  insertAtPosition(head, tail, 200, 1);
  printLinkedList(head);
  return 0; 
}