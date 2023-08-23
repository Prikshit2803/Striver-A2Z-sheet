class Solution {
public:

// Directions for searching in grid
//string cannot be found in zig-zag manner only along one of 8 possible directions
//for each position we check along all 8 directions until non-matching character found (return false) or k==word length(return true)
    int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    

    
    bool dfs(vector<vector<char>>& grid, int row, int col, string &word) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int len=word.size();
        
       
        if(grid[row][col]!=word[0])
        return false;
        
        for(int dir=0;dir<8;dir++){
              int k;
             int r=row + x[dir];
             int c=col + y[dir];
             
             
             for( k=1;k<len;k++){
                 
                 if(r<0 || r>=n || c<0 || c>=m)
                 break;
                 
                 if(grid[r][c]!=word[k])
                 break;
                 
                 r+=x[dir];
                 c+=y[dir]; //go in same direction
             
             }
             
             if(k==len)
             return true;
             
        }
        
        return false;
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    
	    vector<vector<int>> result;

        int n = grid.size();
        int m = grid[0].size();
    
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (dfs(grid, row, col, word)) {
                    result.push_back({row, col});
                }
            }
        }
    
        return result;
	    
	    
	}
};
