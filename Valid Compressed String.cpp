//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        
        int n = S.size();
        int i = 0,j = 0;
   
        while(i < S.length() and j < T.length())
        {
            if(S[i] == T[j])
            {
                ++i;
                ++j; 
                continue;
            }
            if(T[j] - '0' == 0)
            {
                ++j;
                continue;
            }
            int cnt = 0;
            while(j < T.length() and isdigit(T[j]))
            {
                cnt = cnt*10 + (T[j] - '0');
                ++j;
            }
            
            i += cnt;
            
            if(cnt == 0) return 0;
        }
        return i == S.length() and j == T.length();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends
