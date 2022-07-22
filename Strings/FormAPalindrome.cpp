//Method 1
class Solution{
  public:
    int countMin(string str)
    {
        string str1=str;
        int n=str.size();
        int dp[n+1][n+1];
        reverse(str.begin(),str.end());
        for(int i=0;i<n+1;i++)
        {
        for(int j=0;j<n+1;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(str[i-1]==str1[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        }
        int ans=dp[n][n];
        return n-ans;
    }
};

//Method 2

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int dp[s1.length() + 1][s2.length() + 1];
        for(int i = 0 ; i <= s1.length() ; i++)
        {
            for(int j = 0 ; j <= s2.length() ; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[s1.length()][s2.length()];
    }
    int countMin(string str)
    {
        //complete the function here
        string s1 = str;
        reverse(s1.begin(), s1.end());
        return str.length() - longestCommonSubsequence(str, s1);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends
