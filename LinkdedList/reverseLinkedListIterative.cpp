
// Iterative Method
Node* reverseLinkedList(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
        
    while(curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
}
    
//Function to reverse a linked list.
struct Node* reverseList(struct Node *head)
{
  return reverseLinkedList(head);
}

