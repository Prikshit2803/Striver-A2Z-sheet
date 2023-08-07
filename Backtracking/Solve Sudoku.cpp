   //Function to find a solved Sudoku. 
    
    bool valid(int grid[N][N],int row,int col,int k){
        for(int i=0;i<9;i++){
            if(grid[i][col]==k) //checks all rows in same col
            return false;
            
            else if(grid[row][i]==k) //check all col 
            return false;
            
            else if(grid[3*(row/3)+ i/3][3*(col/3)+ i%3]==k) //checks the 3*3 matrix
            return false;
        }
        
        return true;
    }
    
    bool solve(int grid[N][N]){
        for(int i=0;i<9;i++){ //AS N is always 9
            for(int j=0;j<9;j++){
                
                if(grid[i][j]==0){
                    
                    for(int k=1;k<=9;k++){ //try all digits
                        if(valid(grid,i,j,k)){
                        grid[i][j]=k;
                        
                        
                        if(solve(grid)==true)
                        return true;
                        
                        else
                        grid[i][j]=0; //backtrack as further iteration return false
                        }
                        
                        
                    }
                return false; //it means no valid digit(as true would have return ed otherwise) found so return false
                }
            }
        }
        
        return true; //no valid integer to add in entire grid hence sudoku complete
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        return solve(grid);
        
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
       for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                cout<<grid[i][j]<<" ";
            }
       }
        
        }
    
