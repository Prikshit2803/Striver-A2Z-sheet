int gcd(int a,int b){
        if(b==0)
            return a;
        if(a<b)
            return gcd(b,a);
        
        return gcd(b,a%b);
        
        
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode * cur=head;
        ListNode* nxt=NULL;
        
        while(cur->next!=NULL){
            nxt=cur->next;
            
            int val=gcd(cur->val,nxt->val);
            
            ListNode * x= new ListNode(val);
            cur->next=x;
            x->next=nxt;
            
            cur=nxt;
        }
        
        return head;
    }
