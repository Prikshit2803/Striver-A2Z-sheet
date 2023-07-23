   bool check(int i,int j,vector<vector<int>> &grid){
      
       if(i<0||i>=grid.size()||j<0||j>=grid[0].size())
      return false;
      
      return true;
  } 
  
  //Dijkstra's
    int MinimumEffort(vector<vector<int>>& heights) {
        vector<vector<int>> dist(heights.size(),vector<int>(heights[0].size(),1e9));
        
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1}; //dx and dy consititue all four up,down,right left path
        
       int n=heights.size();
       int m=heights[0].size();
       
       if(n==1 && m==1)
       return 0;
        
       priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q; //pq not needed as unit-distance increase
       
       q.push({0,{0,0}});
       
       dist[0][0]=0;
       
       while(!q.empty()){
           auto it=q.top();
           q.pop();
           
           int diff=it.first; //min effort so far
           int i=it.second.first;
           int j=it.second.second;
           
           if(i==n-1 && j==m-1){
               return diff;
           }
           
           for(int k=0;k<4;k++){
               int x=i+dx[k];
                int y=j+dy[k];
                
                if(check(x,y,heights)){
                
                int newEffort=max(abs(heights[x][y]-heights[i][j]),diff);
               
               if(newEffort<dist[x][y]){
                   dist[x][y]=newEffort;
                   q.push({newEffort,{x,y}});
               }
                }
                }
           }
       }
       
