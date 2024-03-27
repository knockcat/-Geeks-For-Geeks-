bool isValid(int x, int y, int n, int m)
    {
        return (x >= 0 and y >= 0 and x < n and y < m);
    }

    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
       
       //   Time Complexity -> O(n^m)
       //   Space Complexity -> O(n^m)
       
       int n = mat.size();
       int m = mat[0].size();
       
       vector<vector<bool>> visited(n, vector<bool>(m, false));
       vector<vector<int>> dist(n, vector<int>(m, 1e9));
       
       //   O(n^m)
       for(int i = 0; i < n; ++i)
       {
           for(int j = 0; j < m; ++j)
           {
               if(mat[i][j] == 0)
               {
                   visited[i][j] = 1;
                   if(i-1 >= 0) visited[i-1][j] = 1;
                   if(j-1 >= 0) visited[i][j-1] = 1;
                   if(i+1 < n)  visited[i+1][j] = 1;
                   if(j+1 < m)  visited[i][j+1] = 1;
               }
           }
       }
       
       queue<pair<int,pair<int,int>>> q;  //{step { x, y}}
       
        // multisource bfs
        // O(n)
       for(int i = 0; i < n; ++i)
       {
           if(!visited[i][0])
           {
            q.push({1, {i, 0}});
            dist[i][0] = 1;
           }
       }
       
       vector<int> dx = {1, -1, 0, 0};
       vector<int> dy = {0, 0, -1, +1};
       
       //   O(n*m)
       while(!q.empty()) //{step { x, y}}
       {
           auto here = q.front();
           q.pop();
           
           int steps = here.first;
           int x = here.second.first;
           int y = here.second.second;
           
           for(int i = 0; i < 4; ++i)
           {
               int newx = x + dx[i];
               int newy = y + dy[i];
               
               if(isValid(newx, newy, n, m) and !visited[newx][newy])
               {
                   q.push({steps+1, {newx, newy}});
                   dist[newx][newy] = steps+1;
                   visited[newx][newy] = 1;
               }
           }
       }
       
       int ans = 1e9;
       
       //   O(n)
       for(int i = 0; i < n; ++i)
       {
           ans = min(ans, dist[i][m-1]);
       }
       
        return (ans == 1e9 ? -1 : ans);
    }
