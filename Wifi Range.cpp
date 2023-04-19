//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        
        int prev = 0, curr = -1;
        
        int start = S.find_first_of('1');
        
        if(start - X > 0 or start == -1)
            return false;
        
        for(int i = 0; i < N; ++i)
        {
            if(S[i] == '1')
            {
                curr = i;
                
                int diff = curr - prev - 1;
                
                if(diff > (2*X))
                    return false;
               prev = curr;
            }
        }
        
        if((curr + X) < N-1)
            return false;
        
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends
