//if a row has 1 set that row and col to 1 , in the end if a row or col array has 1 make the element 1
//Expected Time Complexity: O(n * m)
//Expected Auxiliary Space: O(n + m)
 //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        int row[n]={0};
        int col[m]={0};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]==1||col[j]==1){
                    matrix[i][j]=1;
                }
            }
        }
    }
// can also be done with //Expected Auxiliary Space: O(1)
//using 0th row and col as arrays and extra col0 variable as oth row and oth col element is overlapping
 void booleanMatrix(vector<vector<int> > &matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        //we use oth row and col as row and col arrays
        int col0=0; //this is for the 0th col as oth row and oth col coincide
        // int row[n]={0}; matrix[..][0]
        // int col[m]={0}; matrix[0][..]
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    matrix[i][0]=1;
                    
                    if(j==0)
                    col0=1;
                    
                    else{
                        matrix[0][j]=1;
                    }
                }
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==1||matrix[0][j]==1){
                    matrix[i][j]=1;
                }
            }
        }
        
        if(matrix[0][0]==1){ //make 0th row 1
            for(int i=0;i<m;i++)
            matrix[0][i]=1;
        }
        
        if(col0==1){ //make 0th colmn 1
            for(int i=0;i<n;i++)
            matrix[i][0]=1;
        }
        
    }
