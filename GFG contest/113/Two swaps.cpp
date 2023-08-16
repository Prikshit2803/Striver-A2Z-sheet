//MY soln : Find original value at index amd swap value at wrong index with it and then update indexes in map
class Solution{
public: 
    bool checkSorted(int N, vector<int> A)
    {
       if(N==1)
       return false;
       
       map<int,int> mp;
       
       int flag=1;
        for(int i=1;i<N;i++){
            if(A[i]<A[i-1])
            flag=0;
        }
        
        if(flag==1)
        return true;
       
       for(int i=0;i<N;i++)
       mp[A[i]]=i;
       
       int cnt=2;
       
      for(int i=0;i<N;i++){
          if(A[i]!=i+1){
              
              if(cnt==0)
              return false;
              
               mp[A[i]]=mp[i+1];
               
              swap(A[i],A[mp[i+1]]);
              
            
             
             mp[i+1]=i;
             
              cnt--;
          }
      }
      
      if(cnt==1)
      return false;
      
      return true;
    }   
};
