class Solution {
public:
    int calculate(string s) {
        
        stack<int> st;

        int sum=0,sign=1;

        for(int i=0;i<s.length();i++){

            if(s[i]>='0'){ //s[i] is a digit
                 
                 int val=0;

                 while(i<s.length() && s[i]>='0'){
                     val=val*10 + (s[i]-'0');
                     i++;
                 }

                 i--;
                 val=val*sign;
                 sum+=val;
                 sign=1; //reset sign to 1 after digit eg 2 + -3 after  3 set sign =1
            }

           else if(s[i]=='-')
            sign=-1; //only -ve  changes sign

          else  if(s[i]=='('){
              st.push(sum);
              st.push(sign); //store the sum and sign before the brackett

              sum=0;
              sign=1; //reset sign 
          }

          else if(s[i]==')'){
              int sg=st.top(); //pop sign stored
              st.pop();
              sum*=sg;
              int prevsum=st.top(); //pop previous sum stored
              st.pop();
              sum+=prevsum;
          }


        }

        return sum;
    }
};
