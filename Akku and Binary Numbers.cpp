//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long int
class Solution{
public:
    void precompute()
    {
        // Code Here
    }
    
    long long solve(long long l, long long r){
        // Code Here
        ll ans = 0;
        for(int i = 0; i<63; ++i)
        {
            for(int j = i+1; j < 63; ++j)
            {
                for(int k = j+1; k < 63; ++k)
                {
                    ll curr = 0;
                    curr |= (1L<<i);
                    curr |= (1L<<j);
                    curr |= (1L<<k);
                    
                    if(curr >= l and curr <= r)
                        ++ans;
                }
            }
        }
        return ans;
    }
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends
