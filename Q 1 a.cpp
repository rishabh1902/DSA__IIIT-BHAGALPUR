class Solution {
public:
    bool ppalindrome(string s ,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    void f(string s,vector<vector<string>>&ans,int index ,vector<string>&sans)
    {
        if(index==s.size())
        {
            ans.push_back(sans);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(ppalindrome(s,index,i))
            {
                sans.push_back(s.substr(index,i-index+1));
                f(s,ans,i+1,sans);
                sans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>sans;
         f(s,ans,0,sans);
        return ans;
    }
};