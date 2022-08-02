// Method 1
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int n,stack<int> &st,vector<int> &vis, vector<int> adj[])
	{
	    vis[n]=1;
	    for(auto x:adj[n])
	    {
	        if(!vis[x])
	        {
	            dfs(x,st,vis,adj);
	        }
	    }
	    st.push(n);
	}
	void redfs(int node, vector<int> &vis,vector<int> trans[])
	{
	    vis[node]=1;
	    for(auto x:trans[node])
	    {
	        if(!vis[x])
	        {
	            redfs(x,vis,trans);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,st,vis,adj);
            }
        }
        vector<int> trans[V];
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
            for(auto x:adj[i])
            {
                trans[x].push_back(i);
            }
        }
        int count=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(!vis[node])
            {
                redfs(node,vis,trans);
                count++;
            }
        }
        return count;
    }
};

//Method 2
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int v, vector<bool> &vis, stack<int> &st, vector<int> adj[])
	{
	    vis[v] = true;
	    for(auto it = adj[v].begin() ; it != adj[v].end() ; it++)
	    {
	        if(!vis[*it])
	            dfs(*it, vis, st, adj);
	    }
	    st.push(v);
	}
	void revDfs(int v, vector<bool> &vis, vector<int> adj[])
	{
	    vis[v] = true;
	    for(auto it = adj[v].begin() ; it != adj[v].end() ; it++)
	    {
	        if(!vis[*it])
	            revDfs(*it, vis, adj);
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> st;
        vector<bool> vis(V, false);
        for(int i = 0 ; i < V ; i++)
        {
            if(!vis[i])
                dfs(i, vis, st, adj);
        }
        vector<int> transposeGraph[V];
        for(int i = 0 ; i < V ; i++)
        {
            for(auto it : adj[i])
                transposeGraph[it].push_back(i);
        }
        for(auto it : vis)
            it = false;
        int count = 0;
        while(!st.empty())
        {
            int current = st.top();
            st.pop();
            if(!vis[current])
            {
                count++;
                revDfs(current, vis, transposeGraph);
            }
        }
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
