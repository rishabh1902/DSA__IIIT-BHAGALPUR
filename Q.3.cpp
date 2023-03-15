//recursive
int f(int i,int w,vector<int> &value, vector<int> &weight)
{
    if(i==0)
    {
         return value[i]*(w/weight[i]);
        
    }
    int notake=f(i-1,w,value,weight);
    int take=INT_MIN;
    if(w>=weight[i]) take=value[i]+f(i,w-weight[i],value,weight);
     return max(take,notake);
    }
int cutRod(vector<int> &price, int n)
{
	
	vector<int>weight(n);
	for(int i=0;i<n;i++) weight[i]=i+1;
	return f(n-1,n,price,weight);
}
//memoization
int f(int i,int w,vector<int> &value, vector<int> &weight,vector<vector<int>>&dp)
{
    if(i==0)
    {
         return value[i]*(w/weight[i]);
        
    }
	if(dp[i][w]!=-1) return dp[i][w];
    int notake=f(i-1,w,value,weight,dp);
    int take=INT_MIN;
    if(w>=weight[i]) take=value[i]+f(i,w-weight[i],value,weight,dp);
     return dp[i][w]=max(take,notake);
    }
int cutRod(vector<int> &price, int n)
{
	
	vector<int>weight(n);
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
	for(int i=0;i<n;i++) weight[i]=i+1;
	return f(n-1,n,price,weight,dp);
}

