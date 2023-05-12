//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        
        
        bool ok = false;
        
        for(int i = 0; i < n; ++i)
        {
            if(arr[i] == 0)
                ok = true;
        }
        
        if(count(arr.begin(),arr.end(),0) == n)
            return 0;
            
        if(!ok)
            return -1;
            
        int operations = 0, cnt = 0;
        
        for(int i = 0; i < n; ++i)
        {
           if(arr[i] != 0)
           {
               ++cnt;
           }
           else 
           {
               if(cnt > 0)
               {
                    ++operations;
                    cnt = 0;
               }
           }
        }
        
        if(cnt > 0)
            ++operations;
            
        return operations;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
