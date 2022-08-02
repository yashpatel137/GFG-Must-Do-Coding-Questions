//Method 1
class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> a, int X, int Y) {
        if(a[0][0]==0 || a[X][Y]==0)
        {
            return -1;
        }
      queue<pair<int,int>>q;
      q.push({0,0});
      while(!q.empty())
      {
          int p=q.size();
          while(p--)
          {
              int i=q.front().first;
              int j=q.front().second;
              q.pop();
               if(j+1>=0&&j+1<m&&a[i][j+1]==1)
              {
                  a[i][j+1]+=a[i][j];
                  q.push({i,j+1});
              }
              if(i+1>=0&&i+1<n&&a[i+1][j]==1)
              {
                  a[i+1][j]+=a[i][j];
                  q.push({i+1,j});
              }
               if(i-1>=0&&i-1<n&&a[i-1][j]==1)
              {
                  a[i-1][j]+=a[i][j];
                  q.push({i-1,j});
              }
              
              if(j-1>=0&&j-1<m&&a[i][j-1]==1)
              {
                  a[i][j-1]+=a[i][j];
                  q.push({i,j-1});
              }
          }
      }
      if(a[X][Y]-1==0)
      {
          return -1;
      }
      return a[X][Y]-1;
    }
};

//Method 2

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution
{
  public:
    void solve(int N, int M, vector<vector<int>> &A, int X, int Y, int i, int j, int &count, int &res)
    {
        if(i < 0 || j < 0 || i >= N || j >= M || A[i][j] == 0)
            return;
        if(i == X && j == Y)
        {
            res = min(res, count);
            return;
        }
        count++;
        A[i][j] = 0;
        solve(N, M, A, X, Y, i+1, j, count, res);
        solve(N, M, A, X, Y, i, j+1, count, res);
        solve(N, M, A, X, Y, i-1, j, count, res);
        solve(N, M, A, X, Y, i, j-1, count, res);
        A[i][j] = 1;
        count--;
    }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        // code here
        int count = 0, res = INT_MAX;
        solve(N, M, A, X, Y, 0, 0, count, res);
        return res == INT_MAX ? -1 : res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends
