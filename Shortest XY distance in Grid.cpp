//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool isValid(int x, int y, int n , int m)
    {
        return (x >= 0 and y >= 0 and x < n and y < m);
    }
    
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
        
        queue<pair<pair<int,int> , int> > q;
        vector<vector<bool>> visited(N,vector<bool>(M,false));
        int ans = INT_MAX;
        
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < M; ++j)
            {
                if(grid[i][j] == 'X')
                {
                    q.push({{i,j},0});
                    visited[i][j] = true;
                }
            }
        }
        
        vector<int> dx = {-1,0,0,+1};
        vector<int> dy = {0, -1, +1, 0};
        
        while(!q.empty())
        {
            auto here = q.front();
            int currx = here.first.first;
            int curry = here.first.second;
            int dist = here.second;
            
            q.pop();
            
            if(grid[currx][curry] == 'Y')
            {
                ans = min(ans,dist);
                break;
            }
            for(int i = 0; i < 4; ++i)
            {
                int newx = currx + dx[i];
                int newy = curry + dy[i];
                
                if(isValid(newx,newy, N, M) and !visited[newx][newy])
                {
                    q.push({{newx,newy},dist + 1});
                    visited[newx][newy] = true;
                }
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
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends
