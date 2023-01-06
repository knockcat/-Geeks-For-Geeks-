//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    int shortestPath(int Num1,int Num2)
    {   
        // Complete this function using prime vector
        
        vector<int> sieve(10000,1);
        
        for(int i = 2; i<= 9999; ++i)    
        {
            if(sieve[i] == 1)
            {
                for(int j = i*i;  j <= 9999; j += i)
                    sieve[j] = 0;
            }
        }
        
        vector<int> dp(10000,-1);
        vector<bool> visited(10000,false);
        queue<int> q;
        
        q.push(Num1);
        visited[Num1] = true;
        dp[Num1] = 0;
        
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            string here = to_string(curr);
            
            for(int i = 0; i<4; ++i)
            {
                for(char c = '0'; c <= '9'; ++c)
                {
                    if((c == '0' and i == 0) or c == here[i])
                        continue;
                    
                    string str = here.substr(0,i) + c + here.substr(i+1);
                    
                    int temp = stoi(str);
                    
                    if(!visited[temp] and sieve[temp] and dp[temp] == -1)
                    {
                        dp[temp] = 1 + dp[curr];
                        q.push(temp);
                        visited[temp] = true;
                    }
                    
                }
            }
            
        }
        
        return dp[Num2];
        
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends
