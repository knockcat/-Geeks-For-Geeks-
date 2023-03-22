//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
      //code here
      
      stack<char> st;
      long long ans = 0;
      
      if(X > Y)
      {
        for(int i = 0; i<S.size(); ++i)
        {
            if(st.empty())
                st.push(S[i]);
            else if(st.top() == 'p' and S[i] == 'r')
            {
                st.pop();
                ans += X;
            }
            else
                st.push(S[i]);
        }
        
        vector<char> temp;
        while(!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        for(int i =0 ; i<temp.size(); ++i)
        {
            if(st.empty())
                st.push(temp[i]);
            else if(st.top() == 'r' and temp[i] == 'p')
            {
                st.pop();
                ans += Y;
            }
            else
                st.push(temp[i]);
        }
      }
      else
      {
           for(int i = 0; i<S.size(); ++i)
        {
            if(st.empty())
                st.push(S[i]);
            else if(st.top() == 'r' and S[i] == 'p')
            {
                st.pop();
                ans += Y;
            }
            else
                st.push(S[i]);
        }
        
        vector<char> temp;
        while(!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        for(int i =0 ; i<temp.size(); ++i)
        {
            if(st.empty())
                st.push(temp[i]);
            else if(st.top() == 'p' and temp[i] == 'r')
            {
                st.pop();
                ans += X;
            }
            else
                st.push(temp[i]);
        }
      }
     return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends
