//Approach : Put a queen in any row of 0th col and from then keep putting , if col==n all queens are place when backtracking remove queen
//check if queen can be place in a position by using isSafe function that checks same row, upper and lower diagonal to see if a queen already exits

//video link:https://www.youtube.com/watch?v=i05Ju7AftcM
//striver also makes isSafe fucntion as O(1)
bool isSafe(int row,int col,vector<vector<int>> &board,int n){
    int duprow=row;
    int dupcol=col;
    
    //check upper diagonal
    
    while(row>=0 && col>=0){
        
        if(board[row][col]==1)
        return false;
        
        row--;
        col--;
    }
    
    //check row
    
    row=duprow;
    col=dupcol;
    while(col>=0){
      
        if(board[row][col]==1)
        return false;
        
        col--;
        
    }
    
    //check lower diagonal
    
    row=duprow;
    col=dupcol;
    
    while(row<n && col>=0){
        
        if(board[row][col]==1)
        return false;
        
        row++;
        col--;
    }
    
    return true;
}


void addAns(vector<vector<int>> &board,vector<vector<int>> &ans,int n){
    
    vector<int> temp;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            if(board[j][i]==1) // check entire col and push the row that has 'Queen' into temp  
            temp.push_back(j+1);
        }
    }
    
    ans.push_back(temp);
}


    
void solve(int col,int n,vector<vector<int>> &board,vector<vector<int>> &ans){
    
    if(col==n){
        addAns(board,ans,n);
        return;
    }
    
    for(int row=0;row<n;row++){
        
        if(isSafe(row,col,board,n)){
            board[row][col]=1;
            
            solve(col+1,n,board,ans);
            
             board[row][col]=0;
        }
    }
}
    vector<vector<int>> nQueen(int n) {
        
        vector<vector<int>> ans;
        
        vector<vector<int>> board(n, vector<int>(n, 0));
        
        solve(0, n, board, ans);
        
        
        return ans;
        
    }
