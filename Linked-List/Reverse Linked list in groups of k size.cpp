struct node *reverse (struct node *head, int k)
    { 
        
        if(k==1 || head->next==NULL)
        return head;
        
        node *dummy = new node(0);
        dummy->next=head;
        
        node* prev=dummy;
        node *cur=dummy;
        node *nex=dummy;
        
        int cnt=0;
        cur=head;
        while(cur){
            cnt++;
            cur=cur->next;
        }
        
        while(cnt>=k){
            cur=prev->next;
            nex=cur->next;
           
            
            for(int i=1;i<k;i++){
                cur->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=cur->next;
            }
            
            prev=cur;
            cnt-=k;
            
        }
        
        if(cnt<k && cnt>0){
             cur=prev->next;
            nex=cur->next;
            
            for(int i=1;i<cnt;i++){
                cur->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=cur->next;
            }
        }
        
        return dummy->next;
    }
