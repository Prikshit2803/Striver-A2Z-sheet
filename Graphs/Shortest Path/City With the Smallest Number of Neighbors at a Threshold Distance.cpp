 //Floyd-warshall as we need to find shortest distance from each node to every other node
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                vector<vector<int>> matrix(n, vector<int>(n, 1e9));
                     
                     for(auto it: edges){
                         matrix[it[0]][it[1]]=it[2];
                          matrix[it[1]][it[0]]=it[2]; //as undirected edges
                     }
                     
                     for(int i=0;i<n;i++)
                     matrix[i][i]=0;
                     
                     
                     for(int via=0;via<n;via++){
                         for(int i=0;i<n;i++){
                             for(int j=0;j<n;j++){
                                matrix[i][j]=min(matrix[i][j],matrix[i][via] + matrix[via][j]);
                             }
                         }
                     }
                     
                     int mincnt=INT_MAX,minNode=0;
                     
                      for(int i=0;i<n;i++){
                          int cnt=0;
                             for(int j=0;j<n;j++){
                                if(matrix[i][j]<=distanceThreshold)
                                cnt++;
                             }
                             
                             if(cnt<=mincnt){
                                 mincnt=cnt;
                                 minNode=i;
                             }
                         }
                         
                         return minNode;
                 }
