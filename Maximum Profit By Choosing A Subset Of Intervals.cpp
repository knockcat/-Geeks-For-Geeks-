//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
   
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        
        
        sort(intervals.begin(),intervals.end());
        vector<int>dp(n,0); 
        int maxi=0;
        for(int i=0;i<n;i++)
        {
           dp[i]=intervals[i][2];
           maxi=max(maxi,dp[i]);
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
               if(intervals[i][0] >= intervals[j][1])
                {
                    if( dp[i] < dp[j]+intervals[i][2])
                    {
                        dp[i]=intervals[i][2]+dp[j];
                    }
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends
