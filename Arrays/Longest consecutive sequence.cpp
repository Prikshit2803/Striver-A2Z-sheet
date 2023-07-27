//Function to return length of longest subsequence of consecutive integers.
    //If there's no lower element than current then iterate till we can't find element +1 greater
    int findLongestConseqSubseq(int arr[], int n)
    {
        int longest=1, cnt;
      unordered_set<int> st;
      
      for(int i=0;i<n;i++){
          st.insert(arr[i]);
      }
      
      for(auto it : st){
          int x=it;
          if(st.find(it-1)!=st.end())
          continue;
          
          else{
              cnt=1;
              while(st.find(it+1)!=st.end()){
                  it=it+1;
                  cnt=cnt+1;
              }
          }
          
          longest=max(longest,cnt);
      }
      
      return longest;
    }
