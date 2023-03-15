//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
    
    int minOpPalindrome(string& temp, int s, int e)
    {
        int start = 0, end = temp.size()-1;
        
        int op = 0;
        
        while(start <= end)
        {
            if(temp[start] != temp[end])
            {
                if(start >= s and end <= (s + e -1))
                    return 1e9;
                ++op;
            }
            ++start, --end;
        }
        return op;
    }
    
    int specialPalindrome(string s1, string s2){
        //Code Here
        
        int ans = 1e9;
        int n = s1.size(), m = s2.size();
        for(int i = 0; i<=n-m; ++i)
        {
            int op = 0;
            string temp = s1;
            for(int j = 0; j<m; ++j)
            {
                if(temp[i+j] != s2[j])
                    ++op;
                temp[i+j] = s2[j];
            }
            
            ans = min(ans,op + minOpPalindrome(temp,i,m));
        }
        
        return (ans == 1e9 ? -1 : ans);
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
