void dijistras(int source, vector<int>& distance, vector<pair<int,int>> adj[])
    {
        distance[source] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0, source});
        
        while(!pq.empty())
        {
            auto here = pq.top();
            pq.pop();
            
            int curDist = here.first;
            int node = here.second;
            
            for(auto neigh : adj[node])
            {
                int adjNode = neigh.first;
                int adjWt = neigh.second;
                
                if(curDist + adjWt < distance[adjNode])
                {
                    distance[adjNode] = curDist + adjWt;
                    pq.push({distance[adjNode], adjNode});
                }
            }
            
        }
    }
  
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        
        // Time Complexity -> O(n * (n+m)log(n));
        // Space Complexity -> O(n+m)
        
        vector<pair<int,int>> adj[n+1];
        
        // graph
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        int ans = -1, minCities = 1e9;
        
        for(int i = 0; i < n; ++i)
        {
            vector<int> distance(n, 1e9); // 1e9 maximum value
            
            dijistras(i, distance, adj); // i is source node;
            
            int numberOfNeighbors = 0;
            
            for(auto& dist : distance)
            {
                numberOfNeighbors += (dist <= distanceThreshold);
            }
            
            if(numberOfNeighbors < minCities)
            {
                ans = i;
                minCities = numberOfNeighbors;
            }
            else if(numberOfNeighbors == minCities)
            {
                ans = max(ans, i); // max label
            }
        }
        
        return ans;
    }
