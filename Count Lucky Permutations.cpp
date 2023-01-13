//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define ll long long
const ll MAX = 15;
ll dp[1<<MAX][MAX];
class Solution {
  public:
    long long int luckyPermutations(int N, int M, vector<int> arr,
                                    vector<vector<int>> graph) {
        // Code here
        vector<vector<ll>> adj(N);
        for(auto& edge : graph) {
            adj[edge[0]-1].push_back(edge[1]-1);
            adj[edge[1]-1].push_back(edge[0]-1);
        }
        
        vector<ll> pos(N, 0), npos(N, 0);
        for(ll i=0; i<N; i++) {
            pos[--arr[i]] |= 1<<i;
        }
        
        for(ll i=0; i<N; i++) {
            for(ll v : adj[arr[i]]) {
                npos[i] |= pos[v];
            }
        }
        
        for(ll i=0; i<(1<<N); i++) {
            for(ll j=0; j<N; j++) {
                dp[i][j] = i ? 0 : 1;
            }
        }
        
        for(ll i=1; i<(1<<N)-1; i++) {
            for(ll j=0; j<N; j++) {
                if(!(i&(1<<j))) {
                    ll k = i&npos[j];
                    while(k) {
                        ll p = log2(k);
                        dp[i][j] += dp[i^(1<<p)][p];
                        k ^= 1<<p;
                    }
                }
            }
        }
        
        ll res = 0, i = (1<<N)-1;
        for(ll j=0; j<N; j++) {
            dp[i][j] += dp[i^(1<<j)][j];
            res += dp[i][j];
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<int> arr(N);
        vector<vector<int>> graph(M, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> graph[i][j];
            }
        }
        Solution obj;
        cout << obj.luckyPermutations(N, M, arr, graph) << endl;
    }
}

// } Driver Code Ends
