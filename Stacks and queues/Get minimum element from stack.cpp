//Intuition : we have stack s and Create a separate stack s2 to keep track of min element and push element only if it is empty or element is min and pop it's 
//top if min element getting popped from s

class Solution{
    int minEle=-1,min;
    stack<int> s,s2;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           if(s2.empty())
           return -1;
           
          return s2.top();
       }
       
       /*returns poped element from stack*/
       int pop(){
          
          if(s.empty())
          return -1;
          
          int x=s.top(); 
          
          if(x==s2.top())//min element
          s2.pop();
         
          
          s.pop();
          return x;
          
           
       }
       
       /*push element x into the stack*/
       void push(int x){
           
          
           
        if( s2.empty() || x<=s2.top()){
           s2.push(x);
        }
           
          
           
            s.push(x);
           
       }
};

