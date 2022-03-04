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
};

ListNode* reverseLinkedList(ListNode* head) {
  ListNode* currNode = head;
  ListNode* nextNode = NULL;
  ListNode* prevNode = NULL;

  while(currNode != NULL) {
    nextNode = currNode->next;
    currNode->next = prevNode;
    prevNode = currNode;
    currNode = nextNode;
  }
  return prevNode;
}

ListNode* addOneToNumber(ListNode* head) {
  if(head == NULL || head->next == NULL) return head;
  
  head = reverseLinkedList(head);
  ListNode* currNode = head;
  while(currNode != NULL) {
    if(currNode->data == 9 && currNode->next == NULL) {
      currNode->data = 1;
      ListNode* tempNode = new ListNode(0);
      tempNode->next = head;
      head = tempNode;
      currNode = currNode->next;
    } else if(currNode->data == 9) {
      currNode->data = 0;
      currNode = currNode->next;
    } else {
      currNode->data = currNode->data + 1;
      break;
    }
  }
  head = reverseLinkedList(head);
  return head;
}

void printLinkedList(ListNode* head) {
  ListNode* temp = head;
  while(temp != NULL) {
    cout << temp->data << "->";
    temp = temp->next;
  } cout << "NULL";
}

int main() {
  ListNode* node1 = new ListNode(4);
  ListNode* node2 = new ListNode(5);
  ListNode* node3 = new ListNode(6);
  ListNode* node4 = new ListNode(7);
  ListNode* node5 = new ListNode(9);

  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;

  ListNode* head = node1;
  printLinkedList(head);
  ListNode* newHead = addOneToNumber(head);
  cout << endl;
  printLinkedList(newHead);
  return 0;
}