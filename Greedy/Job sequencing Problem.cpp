//Striver ... Intuituion : sort on profit basis in descending order then take an array and assign job id's if no more can be assigned then max profit
 //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<pair<int,pair<int,int>>> v;
        
        int maxdead=INT_MIN;
         for(int i=0;i<n;i++)
         maxdead=max(maxdead,arr[i].dead);
        
        vector<int> ans,ap(maxdead+1,-1);
        
         for(int i=0;i<n;i++)
         v.push_back({arr[i].profit,{arr[i].dead,arr[i].id}});
         
         sort(v.begin(),v.end());
         
         reverse(v.begin(),v.end());
         
       
         int cnt=0;
         int maxprofit=0;
         
       
         
         for(int i=0;i<n;i++){
             
             int j=v[i].second.first; //deadline
             while(j>0 && ap[j]!=-1){ //can't be j==0 as in real life no such thing as 0th day
                 j--;
             }
             
             if(j<=0)
             continue;
             
             ap[j]=v[i].second.second; //id
             maxprofit+=v[i].first;
             cnt++;
         }
        
       
       ans.push_back(cnt);
       ans.push_back(maxprofit);
        
        return ans;
    }
