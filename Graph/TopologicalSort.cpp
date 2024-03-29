//Method 1
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans(V,0),ind(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            ind[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        if(ind[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    int indg=0;
	    while(!q.empty())
	    {
	        int temp=q.front();
	        q.pop();
	        ans[indg++]=temp;
	        for(auto it:adj[temp])
	        {
	            ind[it]--;
	            if(ind[it]==0)
	            {
	                q.push(it);
	            }
	        }
	    }
	    return ans;
	}
};

//Method 2
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> res;
	void dfs(int V, vector<int> adj[], vector<bool> &vis, vector<int> &res)
	{
	    if(vis[V])
	        return;
	    vis[V] = true;
	    for(int i : adj[V])
	        dfs(i, adj, vis, res);
	    res.push_back(V);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> res;
	    vector<bool> vis(V, false);
	    for(int i = 0 ; i < V ; i++)
	    {
	        if(!vis[i])
	            dfs(i, adj, vis, res);
	    }
	    reverse(res.begin(), res.end());
	    return res;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
