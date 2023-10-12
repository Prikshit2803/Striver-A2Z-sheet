
    void dpmemo(int i,int B,vector<int> &A,vector<int> &arr, vector<vector<int>> &ans){
        int n=A.size();
        
        if(B==0){
          
        ans.push_back(arr);
        return;
        }
        
        if(B<0||i<0){
            
            return ;
        }
        
        
       // Take, notTake approach
        
        if(A[i]<=B){
            
            arr.push_back(A[i]);
            dpmemo(i,B-A[i],A,arr,ans);
            arr.pop_back(); //remove A[i];
        }
        
         while(i>0 && A[i]==A[i-1] )
        {
            i--;
        }  //handle unique cases
        
        dpmemo(i-1,B,A,arr,ans);
        
        return;
    }
    
    


    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        int n=A.size();
        
       
        sort(A.begin(),A.end());
        
     reverse(A.begin(),A.end()); //or just start from 0
        
        vector<vector<int>> ans;
        
        vector<int> arr;
        
         dpmemo(n-1,B,A,arr,ans);
         
        //  sort (ans.begin(), ans.end());
        //  ans.erase(unique(ans.begin(), ans.end()), ans.end());

        
         return ans;
    }
