//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

#define ll long long int 
class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        
        stack<pair<ll,ll>> st;
        vector<ll> ans(n,-1);
        
        for(int i= 0; i<n; ++i)
        {
            while(!st.empty() and st.top().first < arr[i])
            {
               ans[st.top().second] = arr[i];
               st.pop();
            }
           st.push({arr[i],i});
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends
