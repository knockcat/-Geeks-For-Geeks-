//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        
        int i = 0 , j = 0;
        int ans = 0, cnt = 0;
        // map<char,int> mp;
        
        while(j < n)
        {
            
            // ++mp[arr[j]];
            
            // if(mp['O'] <= m)
            //     ans = max(ans,j- i + 1);
            
            // while(i < n and mp['O'] > m)
            // {
            //     --mp[arr[i]];
            //     if(mp[arr[i]] == 0)
            //         mp.erase(arr[i]);
            //     ++i;
            // }
            // ++j;
            
            if(arr[j] == 'O')
                ++cnt;
            while(i < n and cnt > m)
            {
                if(arr[i] == 'O')
                    --cnt;
                ++i;
            }
            
            ans = max(ans,j - i + 1);
            
            ++j;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
