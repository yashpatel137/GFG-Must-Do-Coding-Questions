//Method 1
class Solution {
  public:
    void solve(vector<vector<char>> &matrix, int x, int y, int r, int c)
    {
        if(x<0||x>=r||y<0||y>=c||matrix[x][y]!='1')
        {
            return;
        }
        matrix[x][y]='2';
        solve(matrix,x+1,y,r,c);
        solve(matrix,x-1,y,r,c);
        solve(matrix,x,y+1,r,c);
        solve(matrix,x,y-1,r,c);
        solve(matrix,x+1,y+1,r,c);
        solve(matrix,x+1,y-1,r,c);
        solve(matrix,x-1,y-1,r,c);
        solve(matrix,x-1,y+1,r,c);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int r=grid.size();
        int c=grid[0].size();
        if(r==0)
        {
            return 0;
        }
        int cnt=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]=='1')
                {
                    solve(grid,i,j,r,c);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


//Method 2
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find the number of islands.
    bool isSafe(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &vis)
    {
        return (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] == '1' && !vis[i][j]);
    }
    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &vis)
    {
        static int rows[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        static int cols[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        vis[i][j] = true;
        for(int k = 0 ; k < 8 ; k++)
        {
            if(isSafe(grid, i + rows[k], j + cols[k], vis))
                dfs(grid, i + rows[k], j + cols[k], vis);
        }
    }    
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(grid, i, j, vis); 
                    count++;
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends
