//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        // code here
        
        // (an - a)/d  + 1 = n;
        
        if(C == 0)
            return A == B;
            
        int n = ((B - A)/C) + 1;
        
        if(n <= 0)
            return 0;
        
        int term = A + (n-1)*C;
        
        // cout<<n<<" "<<term<<endl;
        
        return (B == term) ? 1 : 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends
