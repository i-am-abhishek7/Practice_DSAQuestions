bool detectLoop(Node* head)
    {
       Node* slow = head;
       Node* fast = head;
       while(fast->next && fast->next->next) {
           slow = slow->next;
           fast = fast->next->next;
           if(slow == fast) {
               return true;
           }
       }
       return false;
    }