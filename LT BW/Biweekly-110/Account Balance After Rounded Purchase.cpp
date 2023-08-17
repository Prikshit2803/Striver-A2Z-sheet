 int accountBalanceAfterPurchase(int p) { //p denotes the purchase amount
        
        if(p%10<=4)
            p=p-p%10;
        
        else
            p=p+(10-p%10);
        
        return 100-p;
    }
