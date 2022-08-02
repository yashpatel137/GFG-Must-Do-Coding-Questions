//Method 1
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>> vec;
	    int count=0;
	    for(int i=0;i<nums.size();i++)
	    {
	        vec.push_back({nums[i],i});
	    }
	    sort(vec.begin(),vec.end());
	    for(int i=0;i<nums.size();i++)
	    {
	        while(vec[i].second!=i)
	        {
	            int tmp=vec[i].second;
	            swap(vec[i],vec[tmp]);
	            count++;
	        }
	    }
	    return count;
	}
};

//Method 2
int minimumSwaps(int arr[],int n)
{
    // Initialise count variable
    int count = 0;
    int i = 0;
     
    while (i < n)
    {
 
        // If current element is
        // not at the right position
        if (arr[i] != i + 1)
        {
 
            while (arr[i] != i + 1)
            {
                int temp = 0;
 
                // Swap current element
                // with correct position
                // of that element
                temp = arr[arr[i] - 1];
                arr[arr[i] - 1] = arr[i];
                arr[i] = temp;
                count++;
            }
        }
 
        // Increment for next index
        // when current element is at
        // correct position
        i++;
    }
    return count;
}

//Method 3
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int, int>> v;
	    for(int i = 0 ; i < nums.size() ; i++)
	        v.push_back({nums[i], i});
	    sort(v.begin(), v.end());
	    vector<bool> vis(nums.size(), false);
	    int count = 0;
	    for(int i = 0 ; i < nums.size() ; i++)
	    {
	        if(vis[i] || v[i].second == i)
	            continue;
	        int j = i;
	        int cycles = 0;
	        while(!vis[j])
	        {
	            vis[j] = true;
	            j = v[j].second;
	            cycles++;
	        }
	        if(cycles)
	            count += cycles - 1;
	    }
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
