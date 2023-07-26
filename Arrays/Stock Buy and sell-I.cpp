int bestTimeToBuyAndSellStock(vector<int>&prices) {

    //for each elelemnt track minm element
    
    int mini=prices[0],maxprofit=0;
   
    for(int i=1;i<prices.size();i++){
            int cost=prices[i]-mini;

            maxprofit=max(maxprofit,cost);

            mini=min(mini,prices[i]);
        
    }
     
     return maxprofit;
    
}
