//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int cnt = 0;
    
    bool dfs(int sv, vector<int>& visited, vector<int> adj[] ){
        
        visited[sv] = true;
        bool ok = false;
        
       for(auto itr : adj[sv])
       {
           if(!visited[itr])
           {
              bool here  = dfs(itr,visited,adj);
                
           if(!here)
            ok = true;
           }
       }
       
       if(ok)
        ++cnt;
        
        return ok;
    }
  
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        
        vector<int> adj[N+1];
 
        for(auto itr : edges){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        
        
        vector<int> visited(N+1,false);
        
        dfs(1,visited,adj);
        
        return cnt;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
