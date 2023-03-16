// EDIT DISTANCE
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   int f(int i,int j,string s ,string t ,vector<vector<int>>&dp)
   {
       if(i<0) return j+1; //if s is exhausted insert j+1 characters in it;
       if(j<0)return i+1; //if(t is exhausted  delete i+1 characters from s;
       if(dp[i][j]!=-1) return dp[i][j];
       if(s[i]==t[j]) return dp[i][j]=f(i-1,j-1,s,t,dp);
       else
       {
           int a=1+f(i-1,j,s,t,dp); //deletion;
           int b=1+f(i,j-1,s,t,dp);//insertion;
           int c=1+f(i-1,j-1,s,t,dp);//replacement
           return dp[i][j]=min(a,min(b,c));}
   }
    int editDistance(string s, string t) {
        // Code here
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends