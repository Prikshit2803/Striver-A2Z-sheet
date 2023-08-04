//Find's Nth row of pascal's triangle
vector<ll> nthRowOfPascalTriangle(int n) {
        
        vector<ll> row;
        ll ans = 1;
         row.push_back(ans);
        ll m=1e9+7;
        for(ll i=1;i<n;i++){
            ans = ans * (n-i) ;
            ans = ans / i;
            ans %= m;
            row.push_back(ans);
        }
        return row;
    }


vector<ll> nthRowOfPascalTriangle(int n) {
        
        ll m=1e9 +7;
         vector<ll> dp(n,0);
         dp[0]=1;
         
         for(int i=1;i<n;i++){
             for(int j=i;j>0;j--){
                 dp[j]+=dp[j-1]%m;
             }
         }
         
         return dp;
    }

vector<ll> nthRowOfPascalTriangle(int n) {
        
        ll mod=1e9 +7;
          vector<vector<int>>ans;
        vector<ll>res;
        for(int i=0;i<n;i++){
            vector<int>temp(i+1);
            temp[0]=1;
            temp[i]=1;
            for(int j=1;j<i;j++){
                temp[j]=(ans[i-1][j-1]+ans[i-1][j])%mod;
            }
            ans.push_back(temp);
        }
        for(auto it:ans[n-1]) res.push_back(it);
        return res;
    }
