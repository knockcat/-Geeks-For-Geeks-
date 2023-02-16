//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:

    int helper(int idx, vector<int>& arr, vector<int>& visited, vector<int>& dp)
    {
        if(idx < 0 or idx >=arr.size())
            return 1;
        if(dp[idx] != -1)
            return dp[idx];
        if(visited[idx])
            return 0;
        visited[idx] = 1;
        if(arr[idx] == 0)
            return 0;
        return dp[idx] = helper(idx+arr[idx] ,arr, visited, dp);
        visited[idx] = 0;
        
    }

    int goodStones(int n,vector<int> &arr){
        // Code here
        
        
        int ans = 0;
        
        vector<int> visited(n+1,false);
        vector<int> dp(n+1, -1);
        for(int i = 0; i < n; ++i)
        {
            ans += helper(i,arr,visited,dp);
        }
        
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
