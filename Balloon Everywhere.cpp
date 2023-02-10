//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        map<char,int> mp;
        
        for(auto  itr : s)
            ++mp[itr];
        
        int count = 0, ans = INT_MAX;
        for(auto itr : mp)
        {
            if(itr.first == 'b' or itr.first == 'a' or itr.first == 'n')
            {
                ans = min(ans,itr.second);
                ++count;
            }
            else if(itr.first == 'l' or itr.first == 'o')
            {
                ans =  min(ans,itr.second/2);
                ++count;
            }
        }
        
        
        if(count == 5)
            return ans;
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
