//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

template <typename T>
class DSU
{
    public:
        int N;
        vector<T> rank, parent, size;
        DSU(int n)
        {
            N = n;
            rank.resize(n + 1, 0);
            size.resize(n + 1, 1);
            parent.resize(n + 1);
    
            for (T i = 0; i <= n; ++i)
            {
                parent[i] = i;
            }
        }
    
        template <typename X>
        X findParent(X u)
        {
            if (u == parent[u])
                return u;
            return parent[u] = findParent(parent[u]);
        }
    
        // Not be using unionByRank
        // but yes for future reference
        template <typename X>
        void unionByRank(X u, X v)
        {
            int nodeX = findParent(u);
            int nodeY = findParent(v);
    
            if (nodeX == nodeY)
                return;
    
            if (rank[nodeX] < rank[nodeY])
            {
                parent[nodeX] = nodeY;
            }
            else if (rank[nodeY] < rank[nodeX])
            {
                parent[nodeY] = nodeX;
            }
            else
            {
                parent[nodeY] = nodeX;
                ++rank[nodeX];
            }
        }
    
        void unionBySize(int u, int v)
        {
            int nodeX = findParent(u);
            int nodeY = findParent(v);
    
            if (nodeX == nodeY)
                return;
    
            if (size[nodeX] < size[nodeY])
            {
                parent[nodeX] = nodeY;
                size[nodeY] += size[nodeX];
            }
            else
            {
                parent[nodeY] = nodeX;
                size[nodeX] += size[nodeY];
            }
        }
    
        template <typename X>
        bool isSame(X u, X v)
        {
            return findParent(u) == findParent(v);
        }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<tuple<int, int, int>> G;

        for (int i = 0; i < V; ++i)
        {
            for (auto itr : adj[i])
            {
                int u = i;
                int v = itr[0];
                int wt = itr[1];
                G.push_back(make_tuple(wt, u, v));
            }
        }
    
        // sort edges as per waits
        sort(G.begin(), G.end());
    
        int mstWt = 0;
        vector<int> mst;
    
        DSU<int> dsu(V);
    
        for (auto itr : G)
        {
            int wt = get<0>(itr);
            int u = get<1>(itr);
            int v = get<2>(itr);
    
            if (dsu.isSame(u, v))
                continue;
            else
            {
                mstWt += wt;
                dsu.unionBySize(u, v);
                mst.push_back(u);
                mst.push_back(v);
            }
        }
    
        // cout << "Minimum Spanning Tree is : " << endl;
        // for (auto itr : mst)
        //     cout << itr << " ";
        // cout << endl;
        // cout << "Minimum Weight of MST : " << mstWt << endl;
        
        return mstWt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
