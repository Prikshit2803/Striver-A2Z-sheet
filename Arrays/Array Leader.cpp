//keep track of right maximum , we can use variable  maxi also to keep track of max ele so far
vector<int> leaders(int a[], int n){
       vector<int> ans;
       
       ans.push_back(a[n-1]);
       
       for(int i=n-2;i>=0;i--){
           if(a[i]>ans.back()) //ans.back() gives latest addded element
           ans.push_back(a[i]);
       }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
