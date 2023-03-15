#include <bits/stdc++.h> 
bool f(int target,int i,vector<int> &a)
{
     if(target==0) return 1;
    if(i==0)
    {
        if(a[i]==target) return 1;
        else return 0;
    }
   
    bool notake=f(target,i-1,a);
    bool take=false;
    if(a[i]<=target)
         take= f(target-a[i],i-1,a);
    //cout<<take<<" "<<notake<<endl;
   return (take+notake);
    

}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    return f(k,n-1,arr);
}
//memoized
bool f(int target,int i,vector<int> &a,vector<vector<int>> &dp)
{
     if(target==0) return 1;
    if(i==0)
    {
        if(a[i]==target) return 1;
        else return 0;
    }
    if(dp[i][target]!=-1) return dp[i][target];
    bool notake=f(target,i-1,a,dp);
    bool take=false;
    if(a[i]<=target)
         take= f(target-a[i],i-1,a,dp);
    //cout<<take<<" "<<notake<<endl;
   return dp[i][target]=(take|notake);
    

}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    return f(k,n-1,arr,dp);
}