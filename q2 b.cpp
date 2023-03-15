//recursive
int f(int i,int target,vector<int>&a)
  {
      if(i==0)
      {
          return (target%a[i]==0);
      }
      int notake=f(i-1,target,a);
      int take=0;
      if(a[i]<=target) take=f(i,target-a[i],a);
      return take+notake;
  }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return f(n-1,amount,coins);
    }
    //memoized
    int f(int i,int target,vector<int>&a, vector<vector<int>>&dp)
  {
      if(i==0)
      {
          return (target%a[i]==0);
      }
      if(dp[i][target]!=-1) return dp[i][target];
      int notake=f(i-1,target,a,dp);
      int take=0;
      if(a[i]<=target) take=f(i,target-a[i],a,dp);
      return dp[i][target]=take+notake;
  }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }