//Create 2 hashmap to store sum and their index, if sum encountered again then find length of that segment
int maxLen(vector<int>&arr, int n)
    {   
        map<int,int> mp,mp1; //mp to store sum and and mp1 to store index of sum
        
       
        int mx=0;
        
        int sum=0,ct=0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            mp[sum]++;
            
            if(mp[sum]>1) //sum has repeated it means there was a zero
            mx=max(mx,abs(i-mp1[sum]));
            
            else{
                mp1[sum]=i;
            }
            
             if(sum==0)
            ct=i+1; //sum so far of sub-array is 0 it means the whole array upto i
        }
        
        return max(mx,ct);
    }
