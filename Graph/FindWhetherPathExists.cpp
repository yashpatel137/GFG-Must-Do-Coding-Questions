//Method 1
class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    void solveDfs(vector<vector<int>> &grid, vector<vector<bool>> &vis,int x,int y)
    {
        int n=grid.size();
        if(x<0||x>=n||y<0||y>=n||vis[x][y]==true||grid[x][y]==0)
        {
            return;
        }
        vis[x][y]=true;
        solveDfs(grid,vis,x+1,y);
        solveDfs(grid,vis,x,y+1);
        solveDfs(grid,vis,x-1,y);
        solveDfs(grid,vis,x,y-1);
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int sx,sy,dx,dy;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0; i<n; i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    sx=i;
                    sy=j;
                }
                if(grid[i][j]==2)
                {
                    dx=i;
                    dy=j;
                }
            }
        }
        solveDfs(grid,vis,sx,sy);
        return vis[dx][dy];
    }
};


//Method 2
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool isSafe(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &grid)
    {
        return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && !vis[i][j] && grid[i][j];
    }
    bool dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &grid)
    {
        if(grid[i][j] == 2)
            return true;
        vis[i][j] = true;
        bool up = false, down = false, left = false, right = false;
        if(isSafe(i-1, j, vis, grid))
            up = dfs(i-1, j, vis, grid);
        if(isSafe(i, j-1, vis, grid))
            left = dfs(i, j-1, vis, grid);
        if(isSafe(i+1, j, vis, grid))
            down = dfs(i+1, j, vis, grid);
        if(isSafe(i, j+1, vis, grid))
            right = dfs(i, j+1, vis, grid);
        return up || left || down || right;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        bool res = false;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                if(grid[i][j] == 1)
                {
                    if(dfs(i, j, vis, grid))
                        return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends
