//the size of elements should always be k and operations == number sof non-B i.e. W
int minimumRecolors(string blocks, int k) {
        
        int l=0,r=k-1,cnt =0,ans=INT_MAX;

        while(r<blocks.length()){
               int s=l;
               cnt=0;
               while(s<=r){
                   if(blocks[s]=='W')
                   cnt++;
                   s++;
               }
                ans=min(ans,cnt);
                l++;
                r++;
        }

        return ans;
    }
