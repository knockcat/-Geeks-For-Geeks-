//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        
        unordered_map<char,int> mp;
        for(auto itr : S)
            ++mp[itr];
            
        int st = 0, end = S.size()-1, dir = 0;
        
        while(st <= end)
        {
            if(dir == 0)
            {
                if(mp[S[st]] == 1)
                    ++st;
                else
                {
                    --mp[S[st]];
                    S[st] = '$';
                    ++st;
                     dir = 1;
                }
            }
            else
            {
                if(mp[S[end]] == 1)
                    --end;
                else
                {
                    --mp[S[end]];
                    S[end] = '$';
                    --end;
                     dir = 0;
                }
            }
        }
        
        string ans = "";
        for(int i = 0; i<S.size(); ++i)
        {
            if(S[i] != '$')
                ans += S[i];
        }
        
         if(dir& 1)
        {
            reverse(ans.begin(),ans.end());
           
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
