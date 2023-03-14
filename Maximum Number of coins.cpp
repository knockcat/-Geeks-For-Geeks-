//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
        int helper(int i, int j , vector<int>& arr, vector<vector<int>>& dp)
    {
        if(i > j)
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int ans = INT_MIN;
        for(int idx = i; idx <= j; ++idx)
        {
            int cost = arr[i-1] * arr[idx] * arr[j+1] + helper(i, idx-1, arr, dp) + helper(idx+1, j, arr, dp);
            ans = max(ans,cost);
        }
        
        return dp[i][j] = ans;
    }

    int maxCoins(int N, vector<int> &arr) {
        // code here
        
        int n = N;
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        
        // vector<vector<int>> dp(n+2, vector<int>(n+2,-1));
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        for(int i = n; i >= 1; --i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(i > j)
                    continue;
                int ans = INT_MIN;
                for(int idx = i ; idx <= j; ++idx)
                {
                    int cost = arr[i-1] * arr[idx] * arr[j+1] + dp[i][idx-1] + dp[idx+1][j];
                    ans = max(ans,cost);
                }
                dp[i][j] = ans;
            }
        }
        
        // return helper(1,N,arr, dp);
        return dp[1][n];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends
