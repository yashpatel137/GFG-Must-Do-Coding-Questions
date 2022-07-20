//Method 1
class Solution{
  public:
    string common(string str1, string str2)
    {
        string ans;
        int n=str1.length();
        int m=str2.length();
        for(int i=0,j=0;i<n && j<m;i++,j++)
        {
            if(str1[i]!=str2[j])
            {
                break;
            }
            ans.push_back(str1[i]);
        }
        return ans;
    }
    string longestCommonPrefix (string arr[], int N)
    {
        string prefix=arr[0];
        string negetive="-1";
        for(int i=1;i<N;i++)
        {
            prefix=common(prefix,arr[i]);
        }
        if(prefix.length())
        {
            return prefix;
        }
        else
        {
            return negetive;
        }
    }
};


//Method 2


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}


int longestSubstrDistinctChars (string S)
{
    // your code here
    vector<int> lastIndex(256, -1);
    int i = 0, res = 0;
    for(int j = 0 ; j < S.length() ; j++)
    {
        i = max(i, lastIndex[S[j]] + 1);
        res = max(res, j - i + 1);
        lastIndex[S[j]] = j;
    }
    return res;
}
