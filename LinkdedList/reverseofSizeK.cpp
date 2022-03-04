#include<bits/stdc++.h>
using namespace std;

class ListNode {
  public:
    int val;
    ListNode* next;

    ListNode(int val) {
      this->val = val;
      this->next = NULL;
    }
};

ListNode* reverseOfKSize(ListNode* head, int k) {
  if(head == NULL) return NULL;

  ListNode* prevNode = NULL;
  ListNode* currNode = head;
  ListNode* nextNode = NULL;
  int count = 0;

  while(currNode != NULL && count < k) {
    nextNode = currNode->next;
    currNode->next = prevNode;
    prevNode = currNode;
    currNode = nextNode;
    count++;
  }

  if(nextNode != NULL) head->next = reverseOfKSize(nextNode, k);
  return prevNode;
}

void printLinkedList(ListNode* head) {
  ListNode* temp = head;
  while(temp != NULL) {
    cout << temp->val << "->";
    temp = temp->next;
  } cout << "NULL" << endl;
}

int main() {
  ListNode* node1 = new ListNode(10);
  ListNode* node2 = new ListNode(20);
  ListNode* node3 = new ListNode(30);
  ListNode* node4 = new ListNode(40);
  ListNode* node5 = new ListNode(50);
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;

  ListNode* head = node1;
  printLinkedList(head);
  ListNode* newHead = reverseOfKSize(head, 2);
  printLinkedList(newHead);
  return 0;
}