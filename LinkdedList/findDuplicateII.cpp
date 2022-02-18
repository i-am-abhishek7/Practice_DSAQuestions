#include<bits/stdc++.h>
using namespace std;

class ListNode {
  public:
    int data;
    ListNode* next;

    ListNode(int data) {
      this->data = data;
      this->next = NULL;
    }

    ListNode(int data, ListNode* next) {
      this->data = data;
      this->next = next;
    }
};

ListNode* removeDuplicate(ListNode* head) {
  if(head == NULL || head->next == NULL)  return head;

  ListNode* dummy = new ListNode(0, head);
  ListNode* prevNode = dummy;

  while(head != NULL) {
    if(head->next != NULL && head->data == head->next->data) {
      while(head->next != NULL && head->data == head->next->data) {
        head = head->next;
      }
      prevNode->next = head->next;
    } else {
      prevNode = prevNode->next;
    }
    head = head->next;
  }
  return dummy->next;
}

void printLinkedList(ListNode* head) {
  ListNode* temp = head;
  while(temp != NULL) {
    cout << temp->data << "->";
    temp = temp->next;
  } cout << "NULL" << endl;
}

int main() {
  ListNode* node1 = new ListNode(10);
  ListNode* node2 = new ListNode(20);
  ListNode* node3 = new ListNode(20);
  ListNode* node4 = new ListNode(20);
  ListNode* node5 = new ListNode(30);
  ListNode* node6 = new ListNode(40);
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = node6;

  ListNode* head = node1;
  printLinkedList(head);
  ListNode* newHead = removeDuplicate(head);
  printLinkedList(newHead);
  return 0;
}