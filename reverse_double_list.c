Node * Reverse(Node * head) {
    if (head == NULL || head->next == NULL) 
        return head;
    if (head->next) {
        Node * new_head = Reverse(head->next);
        Node * temp = new_head;
        while (temp->next) {
            temp = temp->next;
        }

    }
    
}
