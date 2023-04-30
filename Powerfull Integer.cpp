//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        // Code here
        
        int maxi = 0;
        
        for(int i = 0; i < n; ++i)
            maxi = max(maxi, intervals[i][1]);
            
        int ans = -1;
        
        vector<int> freq(maxi + 2, 0);
        
        for(int i = 0; i < n; ++i)
        {
            ++freq[intervals[i][0]];
            --freq[intervals[i][1] + 1];
        }
        
        int prefSum = 0;
        
        for(int i = 0; i < maxi + 1; ++i)
        {
            prefSum += freq[i];
            
            if(prefSum >= k)
                ans = max(ans, i);
        }
        
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
