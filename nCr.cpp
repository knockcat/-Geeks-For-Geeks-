//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define ll long long int
int mod = 1e9+7;

class Solution{
public:
    int nCr(int n, int r){
        // code here
        
        // nCr = n-1 C r + n-1 C r-1
        
        // TC = O(n*r)
        // SC = O(r)
        
        ll dp[r+1] = {0};
        
        dp[0] = 1;
        
        for(int i = 1; i <= n; ++i)
        {
            for(int j = min(i,r); j > 0; --j)
                dp[j] = (dp[j] + dp[j-1]) % mod;
        }
        
        return dp[r];
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends
