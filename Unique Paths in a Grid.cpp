//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int mod = 1e9 + 7;
    
    bool isValid(int i ,int j,int n, int m, vector<vector<int>>& grid)
    {
        return (i < n and j < m and grid[i][j]);
    }
    
    
    int helper(int i, int j, int n,int  m, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
       
       if(i == n-1 and j == m-1 and grid[i][j])
        return 1;
        
       if(dp[i][j] != -1)    
        return dp[i][j];
        
       if(!isValid(i,j,n,m,grid))
        return 0;
        
       int right = helper(i+1,j,n,m,grid,dp);
       int bottom = helper(i,j+1,n,m,grid,dp);
        
       return dp[i][j] = (right + bottom) % mod;
        
    }
  
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        // return helper(0,0,n,m,grid,dp);
        
        for(int i = 0; i<n; ++i)
        {
            for(int j = 0; j<m; ++j)
            {
                if(i == 0 and j == 0 and grid[i][j] == 1)
                    dp[i][j] = 1;
                else
                {
                    if(grid[i][j])
                    {
                        int up = 0, left = 0;
                        if(i > 0 )
                            up = dp[i-1][j];
                        if(j > 0)
                            left = dp[i][j-1];
                            
                        dp[i][j] = (up + left) % mod;
                    }    
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends
