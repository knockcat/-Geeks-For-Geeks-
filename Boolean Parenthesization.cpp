//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define ll long long int
ll mod = 1003;

class Solution{
public:

    int helper(int i, int j, string& s, int isTrue,vector<vector<vector<int>>>& dp)    
    {
        if(i > j)
            return 0;
        if(i == j)
        {
            if(isTrue == 1)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }
        
        if(dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
        
        ll ways = 0;
        for(int idx =  i+1; idx <= j-1; idx += 2)
        {
            ll LT = helper(i, idx-1, s, 1, dp);
            ll LF = helper(i, idx-1, s, 0, dp);
            ll RT = helper(idx+1, j, s, 1, dp);
            ll RF = helper(idx+1, j, s, 0, dp);
            
            if(s[idx] == '&')
            {
                if(isTrue)
                    ways = ( ways + (LT * RT) % mod) % mod;
                else
                    ways = (ways + (LT * RF) % mod + (LF * RT) % mod + (LF * RF) % mod) % mod;
            }
            else if(s[idx] == '|')
            {
                if(isTrue)
                    ways = (ways + (LT * RT) % mod + (LT * RF) % mod + (LF * RT) % mod) % mod;
                else 
                    ways = (ways + (LF * RF) % mod)% mod;
            }
            else
            {
                if(isTrue)
                    ways = (ways + (LT * RF) % mod + (LF * RT) % mod) % mod;
                else
                    ways = (ways + (LT * RT) % mod + (LF * RF) % mod) % mod;
            }
        }
        return dp[i][j][isTrue] = ways;
    }

    int countWays(int N, string S){
        // code here
        
        // vector<vector<vector<int>>> dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        // return helper(0, N-1, S, 1, dp);
        
        
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(N,vector<int>(2,0)));
      
       
        for(int i=0; i<N; i++)
        {
            dp[i][i][1] = S[i] == 'T';
            dp[i][i][0] = S[i] == 'F';
        }
        
        for(int i = N-1; i>= 0; --i)
        {
            for(int j = i+1; j<N; ++j)
            {
                for(int isTrue = 0; isTrue <= 1; ++isTrue)
                {
                    ll ways = 0;
                    for(int idx =  i+1; idx <= j-1; idx += 2)
                    {
                        ll LT = dp[i][idx-1][1];
                        ll LF = dp[i][idx-1][0];
                        ll RT = dp[idx+1][j][1];
                        ll RF = dp[idx+1][j][0];
                        
                        if(S[idx] == '&')
                        {
                            if(isTrue)
                                ways = ( ways + (LT * RT) % mod) % mod;
                            else
                                ways = (ways + (LT * RF) % mod + (LF * RT) % mod + (LF * RF) % mod) % mod;
                        }
                        else if(S[idx] == '|')
                        {
                            if(isTrue)
                                ways = (ways + (LT * RT) % mod + (LT * RF) % mod + (LF * RT) % mod) % mod;
                            else 
                                ways = (ways + (LF * RF) % mod)% mod;
                        }
                        else
                        {
                            if(isTrue)
                                ways = (ways + (LT * RF) % mod + (LF * RT) % mod) % mod;
                            else
                                ways = (ways + (LT * RT) % mod + (LF * RF) % mod) % mod;
                        }
                    }
                    dp[i][j][isTrue] = ways;
                }
            }
        }
        
        return dp[0][N-1][1];
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
