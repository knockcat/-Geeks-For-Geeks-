//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    void dfs(vector<vector<int>>&mat, vector<vector<bool>>& visited,int i, int j, int r, int c)
    {
        if(i < 0 or i >= r or j < 0 or j >= c or visited[i][j])
            return;
        visited[i][j] = true;
        if(j + 1 < c and !visited[i][j+1] and mat[i][j+1] >= mat[i][j])
            dfs(mat,visited,i,j+1,r,c);
        if(i + 1 < r and !visited[i+1][j] and mat[i+1][j] >= mat[i][j])
            dfs(mat,visited,i+1,j,r,c);
        if(j - 1 >= 0 and !visited[i][j-1] and mat[i][j-1] >= mat[i][j])
            dfs(mat,visited,i,j-1,r,c);
        if(i - 1 >= 0 and !visited[i-1][j] and mat[i-1][j] >= mat[i][j])
            dfs(mat,visited,i-1,j,r,c);
    }

    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
    
    vector<vector<bool>> indian(N,vector<bool>(M,false));
    vector<vector<bool>> arabian(N,vector<bool>(M,false));
    
    // dfs for 1 st row and 1st col
    for(int i = 0; i<N; ++i)
        dfs(mat,indian,i,0,N,M);
    for(int j = 0; j<M; ++j)
        dfs(mat,indian,0,j,N,M);
    
    // dfs for last row and last col
    for(int j = 0; j<N; ++j)
        dfs(mat,arabian,N-1,j,N,M);
    for(int i = 0; i<M; ++i)
        dfs(mat,arabian,i,M-1,N,M);
    
    int ans = 0;
    
    
    for(int i = 0; i<N ; ++i)
    {
        for(int j = 0; j < M ;  ++j)
        {
            if(indian[i][j] and arabian[i][j])
                ++ans;
        }
    }
    
    return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends
