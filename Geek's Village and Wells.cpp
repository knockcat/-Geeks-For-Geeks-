//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here
        
        vector<vector<int>> res(n,vector<int>(m,0));
        
        vector<int> dx = {-1,0,0,+1};
        vector<int> dy = {0,-1,+1,0};
        
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        
        queue<pair<pair<int,int>,int>> q;
                   
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(c[i][j] == 'W')
                {
                    q.push({{i,j},0});
                    visited[i][j] = true;
                }
            }
        }
        
      
                    
        while(!q.empty())
        {
            
            auto here = q.front();
            
            int x = here.first.first;
            int y = here.first.second;
            int step = here.second;
         
            if(c[x][y] == 'H')
            {
                res[x][y] = step * 2;
            }
            
            q.pop();
            
            for(int i = 0; i < 4; ++i)
            {
                int newx = dx[i] + x;
                int newy = dy[i] + y;
                
                if(newx >= 0 and newx < n and newy >= 0 and newy < m and (c[newx][newy] == 'H' or c[newx][newy] == '.') and !visited[newx][newy])
                {
                    q.push({{newx,newy},step+1});
                    visited[newx][newy] = true;
                }
            }
        }
        
        for(int i = 0; i<n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(!visited[i][j] and c[i][j] == 'H')
                    res[i][j] = -1;
            }
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends
