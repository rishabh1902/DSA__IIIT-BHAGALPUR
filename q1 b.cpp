//recursive
int f(int i,int w,vector<int>weight,vector<int>value)
{
	
	if(i==0)
	{
		if(weight[i]<=w) return value[i];
		return 0;
	}
	int notake=f(i-1,w,weight,value);
	int take=INT_MIN;
	if(weight[i]<=w) take=value[i]+f(i-1,w-weight[i],weight,value);
	return dp[i][w]=max(take,notake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	
	
	return f(n-1,maxWeight,weight,value);
}
//memoized
int f(int i,int w,vector<int>weight,vector<int>value,vector<vector<int>>&dp)
{
	
	if(i==0)
	{
		if(weight[i]<=w) return value[i];
		return 0;
	}
	if(dp[i][w]!=-1) return dp[i][w];
	int notake=f(i-1,w,weight,value,dp);
	int take=INT_MIN;
	if(weight[i]<=w) take=value[i]+f(i-1,w-weight[i],weight,value,dp);
	return dp[i][w]=max(take,notake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return f(n-1,maxWeight,weight,value,dp);
}