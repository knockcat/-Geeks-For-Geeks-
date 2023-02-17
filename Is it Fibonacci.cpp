//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        
        
        if(N <= GeekNum.size())
            return GeekNum[N-1];
            
        vector<long long> pref = GeekNum;
        long long sum =0 ;
        
        for(auto itr : GeekNum)
            sum += itr;
            
        pref.push_back(sum);
        
        for(int i = K + 1; i <= N; ++i)
        {
            sum += pref[i-1];
            sum -= pref[i-K-1];
            pref.push_back(sum);
        }
        
        return pref[N-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends
