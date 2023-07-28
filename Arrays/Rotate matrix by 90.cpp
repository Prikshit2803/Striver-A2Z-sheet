
void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        vector<vector<int> > m(n,(vector<int>(n,0)));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m[n-1-j][i]=matrix[i][j];
            }
        }
       
       for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=m[i][j];
            }
        }
    } 

//Rotate by 90 clockwise
 //we transpose thee matrix then reverse each row
       
       for(int i=0;i<n-1;i++){
           for(int j=i+1;j<n;j++){
               swap(matrix[i][j],matrix[j][i]);
           }
       }
       
       for(int i=0;i<n;i++)
       reverse(matrix[i].begin(),matrix[i].end());
    } 

//Rotate by 90 anti-clockwise
void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
      
       
       for(int i=0;i<n-1;i++){
           for(int j=i+1;j<n;j++){
               swap(matrix[i][j],matrix[j][i]);
           }
       }
       
       
       reverse(matrix.begin(),matrix.end());
    } 
