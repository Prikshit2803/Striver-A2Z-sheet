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

Using Dijkstra: Leetcode

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        int cityno,mincitycount=1e9;
        
        for(int i=0;i<n;i++)
        {
            vector<int> dist(n,1e9);
            pq.push({0,i});
            dist[i]=0;
            while(!pq.empty())
            {
                int distance=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(auto it:adj[node])
                {
                    int adjNode=it.first;
                    int adjWeight=it.second;
                    if(distance + adjWeight < dist[adjNode])
                    {
                        dist[adjNode] = distance + adjWeight;
                        pq.push({dist[adjNode],adjNode});
                    }
                }
            }
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(dist[j]<=distanceThreshold)
                    count++;
            }
            if(count<=mincitycount)
            {
                mincitycount=count;
                cityno = i;
            }
        }
        return cityno;
    }
