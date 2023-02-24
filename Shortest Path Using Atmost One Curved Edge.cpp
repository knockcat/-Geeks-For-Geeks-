//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    vector<int> dijistra(int a, int b, int n, vector<pair<int,int> > adj[])
    {
        vector<int> dist(n+1,1e9);
        
        priority_queue<pair<int,int>, vector<pair<int, int > >, greater<pair<int,int> > > pq;
        
        dist[a] = 0;
        pq.push({0,a});
        
        while(!pq.empty())
        {
            auto curr = pq.top();
            int v = curr.second;
            pq.pop();
            
            for(auto child : adj[v])
            {
                int u = child.first;
                int wt = child.second;
                
                if(dist[v] + wt < dist[u] )
                {
                    dist[u] = wt + dist[v] ;
                    pq.push({dist[u],u});
                }
            }
        }
        
        return dist;
    }
  
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        // code here
        
        vector<pair<int,int> > adj[n+1];
        vector<vector<int> > curved;
        
        
        for(auto itr : edges)
        {
           adj[itr[0]].push_back({itr[1],itr[2]});
           adj[itr[1]].push_back({itr[0],itr[2]});
           
           curved.push_back({itr[0],itr[1],itr[3]});
        }
        
        vector<int> dist = dijistra(a,b,n,adj);
        vector<int> dist2 = dijistra(b,a,n,adj);
        
        int ans = 1e9;
        ans = dist[b];
        
        for(int i = 0; i < m; ++i)
        {
            int u = curved[i][0];
            int v = curved[i][1];
            int wt = curved[i][2];
            
            ans = min(ans, dist[u] + dist2[v] + wt);
            ans = min(ans, dist[v] + dist2[u] + wt);
        }
        
        return (ans == 1e9 ? -1 : ans);
        return 0;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends
