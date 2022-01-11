struct Node* reverseList(struct Node *head)
    {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        Node* newHead = reverseList(head->next);
        Node* headNext = head->next;
        headNext->next = head;
        head->next = NULL;
        return newHead;
    }