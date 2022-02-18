#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    Node(int data) {
      this->data = data;
      this->next = NULL;
    }
};

void reverseLinkedList(Node* &head) {
  Node* prev = NULL;
  Node* curr = head;
  Node* next = NULL;

  while (curr != NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
}

Node* reverseRecursion(Node* head) {
  if(head == NULL || head->next == NULL) return head;
  Node* newHead = reverseRecursion(head->next);
  head->next->next = head;
  head->next = NULL;
  return newHead;
}

void printLinkedList(Node* &head) {
  Node* temp = head;
  while(temp != NULL) {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << "NULL";
}

int main() {
  Node* node1 = new Node(10);
  Node* node2 = new Node(20);
  Node* node3 = new Node(30);
  Node* node4 = new Node(40);
  Node* node5 = new Node(50);
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  Node* head = node1;
  printLinkedList(head);
  // reverseLinkedList(head);
  // printLinkedList(head);
  cout << endl;
  Node* newHead = reverseRecursion(head);
  printLinkedList(newHead);
  return 0;
}