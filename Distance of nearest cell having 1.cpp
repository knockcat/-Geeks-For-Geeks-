//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    
    bool isSafe(int i,int j,vector<vector<bool>>& visited,int n,int m)
    {
        return (i >= 0 and j >= 0 and i < n and j < m and !visited[i][j]);
    }
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    
	    int n = grid.size(), m = grid[0].size();
	    
	    vector<vector<int>> dist(n,vector<int>(m,0));
	    
	    vector<vector<bool>> visited(n,vector<bool>(m,false));
	    
	    queue<pair<pair<int,int>, int>> q;
	    
	    for(int i = 0; i < n; ++i)
	    {
	        for(int j = 0; j < m; ++j)
	        {
	            if(grid[i][j] == 1)
	            {
	                q.push({{i,j},0});
	                visited[i][j] = true;
	            }
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int steps = q.front().second;
	        
	        dist[row][col] = steps;
	        
	        q.pop();
	        
	        vector<int> delrow = {-1, 0 , 0, +1};
	        vector<int> delcol = {0, -1, +1, 0};
	        
	        for(int i = 0; i < 4; ++i)
	        {
	            int currRow = row + delrow[i];
	            int currCol = col + delcol[i];
	            
	            if(isSafe(currRow,currCol,visited,n,m))
	            {
	                q.push({{currRow,currCol}, steps + 1});
	                visited[currRow][currCol] = true;
	            }
	        }
	    }
	    
	    return dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
