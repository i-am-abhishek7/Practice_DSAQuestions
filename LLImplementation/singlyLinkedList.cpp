#include<bits/stdc++.h>
using namespace std;

class LinkdedListNode {
  public:
    int data;
    LinkdedListNode* next;

    LinkdedListNode(int data) {
      this->data = data;
      this->next = NULL;  
    }
};

// Insert At Head
LinkdedListNode* insertAtHead(LinkdedListNode* head ,int data) {
  LinkdedListNode* newNode = new LinkdedListNode(data);
  newNode->next = head;
  head = newNode;
  return head;
}

void insertAtTail(LinkdedListNode* &tail, int data) {
  LinkdedListNode* newNode = new LinkdedListNode(data);
  tail->next = newNode;
  tail  = tail->next;
}

LinkdedListNode* insertAtPosition(LinkdedListNode* head, int pos, int data) {
  LinkdedListNode* newNode = new LinkdedListNode(data);
  LinkdedListNode* temp = head;

  if(pos == 1) {
    newNode->next = temp;
    head = newNode;
    return head;
  }

  int count = 1;
  while(count < pos-1) {
    temp = temp->next;
    count++;
  }
  newNode->next = temp->next;
  temp->next = newNode;
  return head;
}

LinkdedListNode* deleteAtHead(LinkdedListNode* head) {
  LinkdedListNode* temp = head;
  head = head->next;
  delete temp;
  return head;
}

LinkdedListNode* deleteAtTail(LinkdedListNode* head) {
  LinkdedListNode* temp = head;
  while(temp->next->next != NULL) {
    temp = temp->next;
  }
  LinkdedListNode* deletedNode = temp->next;
  temp->next = NULL;
  delete deletedNode;
  return head;
}

LinkdedListNode* deleteAtPosition(LinkdedListNode* head, int pos) {
  LinkdedListNode* temp = head;
  if(pos == 1) {
    return deleteAtHead(head);
  }
  int count = 1;
  while(count < pos-1) {
    temp = temp->next;
    count++;
  }
  LinkdedListNode* deleteNode = temp->next;
  temp->next = temp->next->next;
  delete deleteNode;
  return head;
}

void printLinkedList(LinkdedListNode* &head) {
  LinkdedListNode* temp = head;
  while(temp != NULL) {
    cout << temp->data << "->";
    temp = temp->next;
  } cout << "NULL" << endl;
}

int main() {
  // LinkdedListNode* node1 = new LinkdedListNode(10);
  // LinkdedListNode* head = node1;
  // LinkdedListNode* newHead1 = insertAtHead(head, 20);
  // printLinkedList(newHead1);
  // LinkdedListNode* node1 = new LinkdedListNode(10);
  // LinkdedListNode* head = node1;
  // LinkdedListNode* tail = node1;
  // insertAtTail(tail, 20);
  // printLinkedList(tail);
  LinkdedListNode* node1 = new LinkdedListNode(10);
  LinkdedListNode* node2 = new LinkdedListNode(20);
  LinkdedListNode* node3 = new LinkdedListNode(30);
  LinkdedListNode* node4 = new LinkdedListNode(40);
  LinkdedListNode* node5 = new LinkdedListNode(50);
  LinkdedListNode* node6 = new LinkdedListNode(60);
  LinkdedListNode* head = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = node6;
  printLinkedList(head);
  // LinkdedListNode* newHead = insertAtPosition(head, 7, 100);
  // LinkdedListNode* newHead = deleteAtHead(head);
  // LinkdedListNode* newHead = deleteAtTail(head);
  LinkdedListNode* newHead = deleteAtPosition(head, 3);
  printLinkedList(newHead);
  return 0;
}