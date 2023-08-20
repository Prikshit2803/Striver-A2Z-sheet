//Srtriver uses third method with pure Binary search :https://www.youtube.com/watch?v=hjR1IYVx9lY

//my soln : O(N)
vector<int> find(int arr[], int n , int x )
    {
        
        int l=-1,r=-1;
       for(int i=0;i<n;i++){
           
           if(arr[i]==x){
               l=i;
               r=i;
               
                i++;
           
           while(arr[i]==x){
               r=i;
               i++;
           }
           
           break;
           }
           
          
       }
        
        vector<int> ans;
        
        ans.push_back(l);
        ans.push_back(r);
        
        return ans; 
        
    }

//Lower_bound based soln T.C : O(2*LogN)
//lower_bound gives index of first occurence of element >=x
//upper_bound gives index of first occurence of element >x

vector<int> find(int arr[], int n , int x )
    {
       int lb=lower_bound(arr,arr+n,x)-arr; //index of first element equal or greater than x
       
       if(lb==n||arr[lb]!=x)
     return {-1,-1};
     
     int ub=upper_bound(arr,arr+n,x)-arr; //index of first element greater than x
     
     return {lb,ub-1};
        
    }
