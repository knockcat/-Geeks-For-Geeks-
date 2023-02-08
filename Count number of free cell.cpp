//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

#define ll long long int
class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      
      int total = n*n;
      vector<int> row(n,0), col(n,0);
      vector<ll> ans;
      
      int rows = n, cols = n;
      int i = 0;
      while(k--)
      {
         bool one = false, two = false;
       
         if(row[arr[i][0]-1] == 0) 
         {
             one = true;
             row[arr[i][0]-1] = 1;
         }
         if(col[arr[i][1] - 1] == 0)
         {
             two = true;
             col[arr[i][1]-1] = 1;
         }
         if(one and two)
         {
             total -= (rows + cols - 1);
             --rows, --cols;
         }
         else if(!one and two)
         {
             total -= (rows);
             --cols;
         }
         else if(one and !two)
         {
             total -= (cols);
             --rows;
         }
        ans.push_back(total);
        ++i;
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends
