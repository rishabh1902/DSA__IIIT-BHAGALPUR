int f(int i,int t,vector<int>&a,int b)
  {
       if(i==0)
       {
           if(t%a[i]==0) return t/a[i];
           return b+5;
       }
       int notake=f(i-1,t,a,b);
       int take=INT_MAX;
       if(t>=a[i]) take=1+f(i,t-a[i],a,b);
       return min(take,notake);
  }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        int a= f(n-1,amount,coins,amount);
        if(a>amount) return -1;
        return a;
    }