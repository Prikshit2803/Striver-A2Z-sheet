//DFS gives TLE , so we use bfs/Djikstra's
//   int dfssolve(int i,int j,int a,int b,vector<vector<int>> &grid,int dx[],int dy[]){
//       if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0)
//       return 1e9; //not INT_MAX as addition of it to some int can cause segmentation fault
      
      
//       if(i==a && j==b)
//       return 0;
      
     
      
//       grid[i][j]=0; //to mark it as visited and stop infinite calls to it
      
//       int mini=INT_MAX;
//       for(int k=0;k<4;k++){
//           int x=i+dx[k];
//           int y=j+dy[k];
          
//          mini=min(mini,1+solve(x,y,a,b,grid,dx,dy));
//       }
      
//       grid[i][j]=1; //now it can be visited after leaving
//       return mini;
      
//   }
  
  bool check(int i,int j,vector<vector<int>> &grid){
      
       if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0)
      return false;
      
      return true;
  }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         
  vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),1e9));
        
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1}; //dx and dy consititue all four up,down,right left path
        
        if(grid[source.first][source.second]==0||grid[destination.first][destination.second]==0)
        return -1;
        
        
        if(source.first==destination.first && source.second==destination.second)
        return 0;
        
       queue<pair<int,pair<int,int>>> q; //pq not needed as unit-distance increase
       
       q.push({0,{source.first,source.second}});
       
       dist[source.first][source.second]=0;
       
       while(!q.empty()){
           auto it=q.front();
           q.pop();
           
           int w=it.first;
           int i=it.second.first;
           int j=it.second.second;
           
           for(int k=0;k<4;k++){
               int x=i+dx[k];
                int y=j+dy[k];
                
                if(check(x,y,grid)){
                
                
                if(w+1<dist[x][y]){
                   dist[x][y]= w+1;
                   
                   if(x==destination.first && y==destination.second)
                   return w+1;
                   
                   q.push({w+1,{x,y}});
                }
                }
           }
       }
       
       return -1;
    }
