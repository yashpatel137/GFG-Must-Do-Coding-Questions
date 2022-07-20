//Method 1

class Solution{
public:	
		
	string removeDups(string S) 
	{
	    string st;
	    int arr[26]={0};
	    int size=S.length();
	    for(int i=0;i<size;i++)
	    {
	        if(arr[S[i]-'a']==0)
	        {
	            arr[S[i]-'a']++;
	            st+=S[i];
	        }
	    }
	    return st;
	}
};

//Method 2

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	string removeDups(string S) 
	{
	    // Your code goes here
	    int map[27] = {0};
	    string res = "";
	    for(int i = 0 ; i < S.length() ; i++)
	    {
	        if(map[S[i] - 97])
	            continue;
	        map[S[i] - 97] = 1;
	        res.push_back(S[i]);
	    }
	    return res;
	}
};

// { Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		
   		Solution ob;
   		cout << ob.removeDups(s) << "\n";
   		
   	}

    return 0;
}  // } Driver Code Ends
