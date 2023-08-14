//reverse list , multiply each element by 2 and take carry and if carry is at the end digit  then add another node
class Solution {
public:
    //Brute-Force :TLE
    ListNode * reverse(ListNode* head){
         ListNode * cur=head;
         ListNode * dummy=head;
        ListNode* prev=nullptr;
        
        while(cur){
            ListNode * nxt=cur->next;
            // cout<<cur->val<<"...";
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
       
//         long long int mod=1e9+7;
//         ListNode * cur=head;
        
//         int n=0; //get size of LL
//         while(cur){
//             n++;
//             cur=cur->next;
//         }
        
//        long long int num=0; int cnt=n;
        
//         cur=head;
        
//         while(cur){
//             if(cnt-1==0)
//                 num+=cur->val;
//             else
//             num+=(cur->val*(long long int)pow(10,cnt-1));
//             cnt--;
//             cur=cur->next;
//         }
        
//         num=num*2;
        
//          int i=num%10;
//             num=num/10;
        
//          ListNode * c=new ListNode(i);
//        ListNode * temp=c;
        
//         while(num){
//              int  k=num%10;
//             num=num/10;
//             ListNode * d=new ListNode(k);
//             c->next=d;
//             c=c->next;
            
//         }
        
        
//          ListNode * ans=reverse(temp);
        
//         return ans;
        
        ListNode * l=reverse(head);
        
        int p=0;
        
        ListNode * cur=l;
        
        ListNode * prev=nullptr;
        while(cur){
            int n=cur->val;
            
            cur->val=(n*2)%10 + p;
            
            p=(n*2 + p)/10;
            
            //cout<<p<<" .. ";
            
            prev=cur;
            cur=cur->next;
        }
        
        if(p!=0){
           ListNode * c= new ListNode(p);
            prev->next=c;
        }
        
        ListNode * ans=reverse(l);
        
        return ans;
        
    }
