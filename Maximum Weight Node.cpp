//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
        vector<int>weight(N,0);
       for(int i=0;i<N;i++)
       {
            if(Edge[i]!=-1)
            {
                weight[Edge[i]]+=i;
            }
       }
       
       for(auto itr : weight)
        cout<<itr<<" ";
        cout<<endl;
       
       int mx=INT_MIN;
       int ans=0;
       for(int i=0;i<N;i++)
       {
            if(weight[i]>=mx)
            {
                 ans=i;
                 mx=weight[i];
            }
          
       }
       return ans;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends
