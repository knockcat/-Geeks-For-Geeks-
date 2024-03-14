vector<vector<int>> getVerticalPrefix(int n, vector<vector<char>>& a)
    {
        vector<vector<int>> verticalPrefix(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                 if(i == 0)
                    verticalPrefix[i][j] = (a[i][j] == 'X' ? 1 : 0);
                 else
                    verticalPrefix[i][j] = (a[i][j] == 'X' ? (1 + verticalPrefix[i-1][j]) : 0);
            }
        }
        
        return verticalPrefix;
    }
    
    vector<vector<int>> getHorizontalPrefix(int n, vector<vector<char>>& a)
    {
        vector<vector<int>> horizontalPrefix(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                 if(j == 0)
                    horizontalPrefix[i][j] = (a[i][j] == 'X' ? 1 : 0);
                 else
                    horizontalPrefix[i][j] = (a[i][j] == 'X' ? (1 + horizontalPrefix[i][j-1]) : 0);
            }
        }
        
        return horizontalPrefix;
    }
  
    int largestSubsquare(int n, vector<vector<char>> a) {
        // code here
        
        // Time Complexity -> O(n^2);
        // Space Complexity -> O(n^2);
        
        vector<vector<int>> verticalPrefix = getVerticalPrefix(n, a);
        vector<vector<int>> horizontalPrefix = getHorizontalPrefix(n, a);
        
        int largestSquareSubgrid = 0;
        
        for(int i = n-1; i >= 0; --i)
        {
            for(int j = n-1; j >= 0; --j)
            {
                int currPossibleValue = min(verticalPrefix[i][j], horizontalPrefix[i][j]);
                
                while(currPossibleValue > largestSquareSubgrid)
                {
                    int verticalHorizontal = horizontalPrefix[i - currPossibleValue + 1][j];
                    int horizontalVertical = verticalPrefix[i][j - currPossibleValue + 1];
                    
                    if(verticalHorizontal >= currPossibleValue and horizontalVertical >= currPossibleValue)
                    {
                        largestSquareSubgrid = max(largestSquareSubgrid, currPossibleValue);
                        break;
                    }
                    --currPossibleValue;
                }
            }
        }
           
        return largestSquareSubgrid;
        
    }
