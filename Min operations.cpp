//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int a, int b) {
        // code here
        
        if(a==b)
        return 0;
        
        if(a==0 || b==0)
        return 1;
        
        int x = a&b;
        if(a==x || b==x)
        return 1;
        
        return 2;
            
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends
