//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        
        int n = s.size();
        
        int i = 0, j = n-1;
        
        auto posConvert = [&](){
            while(i <= j)
            {
                if(s[i] != '?' and s[j] != '?' and s[i] != s[j])
                    return false;
                if(s[i] == '?' and s[j] != '?')
                    s[i] = s[j];
                else if(s[i] != '?' and s[j] == '?')
                    s[j] = s[i];
                
                ++i, --j;
            }
            
            return true;
        };
        
        if(!posConvert())
        {
            return -1;
        }
            
        i = 0;
        
        while(i < n and s[i] == '?')
            ++i;
        
        if(i == n)
            return 0;
        
        char prev = s[i];
        
        int ans = 0;
        
        for(int j = i+1; j < n; ++j)
        {
            if(s[j] == '?')
                s[j] == prev;
            
            ans += abs(s[j] - prev);
            
            prev = s[j];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
