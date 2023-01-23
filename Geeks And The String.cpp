//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        
        stack<char> st;
        string ans;
        
        for(auto itr : s)
        {
            if(!st.empty() and st.top() == itr)
                st.pop();
            else
                st.push(itr);
        }
        
        if(st.empty()) return "-1";
        
        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
