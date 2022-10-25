ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        int n=1;
        ListNode*end=head,*curr=head;
        while(end->next){
            n++;
            end=end->next;
        }
        k=k%n;
        if(k==0) return head;
        k=n-k;
        while(k-- > 1){
            curr=curr->next;
        }
        end->next=head;
        head=curr->next;
        curr->next=NULL;
        return head;
}
