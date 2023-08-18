//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

//Approach :create binary array , reverse it to represent actual binary representationa nd then count the different bits

int hammingDistance(int x, int y) {
        
        int ans=0;
        
        vector<int> bx,by;
        
        int n1=x,n2=y;
        
        while(n1){
            int i=(n1)%2;
            bx.push_back(i);
            n1=(n1)/2;
        }
        
        while(n2){
            int i=(n2)%2;
            by.push_back(i);
            n2=(n2)/2;
        }
        
        reverse(by.begin(),by.end());
        reverse(bx.begin(),bx.end());
        
//         for(int i=0;i<by.size();i++){
//          cout<<by[i]<<"..";
            
//         }
        
       // cout<<by.size();
        if(by.size()>bx.size()){
        for(int i=0;i<(by.size()-bx.size());i++){
            //cout<<by[i]<<"..";
            if(by[i]==1)
                ans++;
        }
            
            int j=(by.size()-bx.size());
            for(int i=0;i<bx.size();i++){
                //cout<<by[i+j];
                if(by[i+j]!=bx[i])
                    ans++;
            }
            
            return ans;
        }
        
        if(by.size()<=bx.size()){
        for(int i=0;i<(bx.size()-by.size());i++){
            if(bx[i]==1)
                ans++;
        }
            
            int j=bx.size()-by.size();
            for(int i=0;i<by.size();i++){
                if(bx[i+j]!=by[i])
                    ans++;
            }
            
            return ans;
        }
        
       return -1; 
    }
