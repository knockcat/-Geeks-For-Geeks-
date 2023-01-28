//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    
    bool compare(string S1, string S2, unordered_map<string,bool>& mp)
    {
            
        int n = S1.size();
        
        if(S1 == S2)
        {
            mp.insert({S1 + S2,true});
            return true;
        }
        
        if(mp.find(S1 + S2) != mp.end())
            return mp[S1 + S2];
        
        for(int i = 1; i < n; ++i)
        {
            // first Case
            string a = S1.substr(0,i);
            string b = S2.substr(0,i);
            string c = S1.substr(i, n);
            string d = S2.substr(i, n);
            
            if(compare(a,b, mp) and compare(c,d, mp))
            {
                mp.insert({S1 + S2,true});
                return true;
            }    
            
            // second Case
            string e = S1.substr(0,i);
            string f = S2.substr(n-i,n);
            string g = S1.substr(i, n);
            string h = S2.substr(0, n-i);
            
            if(compare(e,f, mp) and compare(g,h, mp))
            {
                mp.insert({S1 + S2,true});
                return true;
            }
        }
        
        mp.insert({S1+S2, false});
        return false;
        
        
    }
    
    
    bool isScramble(string S1, string S2){
        //code here
        
        unordered_map<string,bool> mp;
        
        return compare(S1, S2, mp);

    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
