// Intuition : me make each row and col equal to max row/col and each row and col need
   //to incremented by certain amount and row sum needed can be distributed for col also
   //video link : https://www.youtube.com/watch?v=RkShpbEBbHg

//basically row ka sum col mein distribute ho skata hai
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int> values(n);
        
        int need=INT_MIN;
        
        for(int i=0;i<n;i++){
            
            
            int row=0,col=0;
            
            for(int j=0;j<n;j++){
                row+=matrix[i][j];
                col+=matrix[j][i]; ///i remains constant
            }
            
            need=max(need,max(row,col));
            
            values[i]=row; //can store any row or col here
        }
        
        
        int ans=0;
        
        for(auto it : values){
            ans+=need-it;
        }
        
        return ans;
    } 
