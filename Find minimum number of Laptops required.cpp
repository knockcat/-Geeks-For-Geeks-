//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        // Code here
        
        vector<pair<int,int>> vp;
        for(int i= 0; i<N; ++i)
        {
            vp.push_back({start[i],end[i]});
        }
        
        sort(vp.begin(),vp.end());
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        int ans = 0;
        for(int i= 0; i<N; ++i)
        {
            if(pq.empty() or pq.top() > vp[i].first)
            {
                ans++;
                pq.push(vp[i].second);
            }
            else
            {
                pq.pop();
                pq.push(vp[i].second);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends
