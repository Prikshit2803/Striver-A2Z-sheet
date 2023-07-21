//Striver
 //Function to find largest rectangular area possible in a given histogram.
    long long mod=1e9 +7;
    long long getMaxArea(long long arr[], int n)
    {
       vector<long long> rightsmall(n,0),leftsmall(n,0); //to find index of leftsmaller and rightsmaller element
       
       stack<long long> st;
       
       for(int i=0;i<n;i++){
           while(!st.empty() && arr[st.top()]>=arr[i]){
               st.pop();
           }
           
           if(st.empty())
           leftsmall[i]=0;
           
           else
           leftsmall[i]=st.top()+1;  //to find the limit upto which arr[i] is max on left sise
           
           st.push(i);
       }
       
       while(!st.empty())
       st.pop(); //emptying the stack
       
       
       for(int i=n-1;i>=0;i--){
           while(!st.empty() && arr[st.top()]>=arr[i]){
               st.pop();
           }
           
           if(st.empty())
           rightsmall[i]=n-1;
           
           else
           rightsmall[i]=st.top()-1;  //to find the limit upto which arr[i] is max on left sise
           
           st.push(i);
       }
       
       
       long long maxi=0; 
       
       for(int i=0;i<n;i++){
         // long long area=((rightsmall[i]-leftsmall[i]+1)*arr[i]);//this gives max area for each element i
           
           maxi=max(maxi,(rightsmall[i]-leftsmall[i]+1)*arr[i]);
       }
       
       return maxi;
    }

