//video link :https://www.youtube.com/watch?v=BtdgAys4yMk
class Solution{
    
    //intuition : 'O'  at boundary cannot be surrounded and hence all 'o' aconnected to it 
    //also connot be sorrounded in all directions and we mark these 'O' by dfs
public:

 void dfs(int i,int j,vector<vector<char>> &mat, vector<vector<int>> &vis){
     
     int n=mat.size();
     int m=mat[0].size();
     vis[i][j]=1;
     
     int dx[]={1,0,-1,0};
     int dy[]={0,1,0,-1};
     
     for(int k=0;k<4;k++){
         
         int x=i + dx[k];
         int y=j + dy[k];
         
         if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && mat[x][y]=='O')
         dfs(x,y,mat,vis);
     }
 }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
       vector<vector<int>> vis(n,vector<int>(m,0));
       
       for(int j=0;j<m;j++){
           
           if(!vis[0][j] && mat[0][j]=='O') //first row
           dfs(0,j,mat,vis);
           
           
           if(!vis[n-1][j] && mat[n-1][j]=='O')//last row
           dfs(n-1,j,mat,vis);
       }
       
       
       for(int i=0;i<n;i++){
           
           if(!vis[i][0] && mat[i][0]=='O') //first col
           dfs(i,0,mat,vis);
           
           
           if(!vis[i][m-1] && mat[i][m-1]=='O')//last col
           dfs(i,m-1,mat,vis);
       }
       
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               
               if(!vis[i][j] && mat[i][j]=='O')
               mat[i][j]='X';
           }
       }
       
       return mat;
    }
};
