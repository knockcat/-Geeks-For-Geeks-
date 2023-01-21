//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        
        int cntbit=0;
        for(int i=0;i<32;i++){
            if(b&1<<i)
              cntbit++;
        }
        
          int ans=0;
       for(int i=31;i>=0 && cntbit>0;i--){
           if(a&1<<i){
               ans=ans|1<<i;
               cntbit--;
           }
       }
       
      
       
           for(int i=0;i<32 && cntbit>0;i++){
               if(!(ans&1<<i)){
                   cntbit--;
                   ans=ans|1<<i;
               }
            }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
