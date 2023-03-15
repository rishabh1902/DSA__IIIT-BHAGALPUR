

//recursive
 int f(string str1,string str2,int i,int j)
    {
        if(i<0 || j<0) return 0;
        
        if(str1[i]==str2[j])
        {
            return 1+f(str1,str2,i-1,j-1);
        }
        else
        {
            return max(f(str1,str2,i,j-1) ,f(str1,str2,i-1,j) );
        }
    } 
int getLengthOfLCS(string & text1, string & text2) {
  
    int n1=text1.length();
        int n2=text2.length();
        
        return f(text1,text2,n1-1,n2-1);

}
//memoized
 int f(string str1,string str2,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(str1[i]==str2[j])
        {
            return dp[i][j]=1+f(str1,str2,i-1,j-1,dp);
        }
        else
        {
            return dp[i][j]=max(f(str1,str2,i,j-1,dp) ,f(str1,str2,i-1,j,dp) );
        }
    } 
int getLengthOfLCS(string & text1, string & text2) {
  
    int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return f(text1,text2,n1-1,n2-1,dp);

}