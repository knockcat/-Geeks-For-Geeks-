
// Naive Brute Force

// Time Complexity -> O(n^4)
// Space Complexity -> O(1)

int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    
	    int cnt = 0;
	    
	    for(int i = 0; i < n; ++i)
	    {
	        for(int j = 0; j < n; ++j)
	        {
	            bool flag = false;
	            for(int k = 0; k < n; ++k)
	            {
	                for(int l = 0; l < n; ++l)
	                {
	                    if(mat1[i][j] + mat2[k][l] == x)
	                    {
	                        ++cnt;
	                        flag = true;
	                    }
	                    if(flag) break;
	                }
	                if(flag)
	                    break;
	            }
	        }
	    }
	    
	    return cnt;
	}

// Two Sum Map / Set Solution

// Time Complexity -> O(n^2 log(n))
// Space Complexity -> O(n^2)

int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    
	    set<int> have;
	    
	    for(int i = 0; i < n; ++i)
	    {
	        for(int j = 0; j < n; ++j)
	        {
	            have.insert(mat1[i][j]);
	        }
	    }
	    
	    int cnt = 0;
	    
	    for(int i = 0; i < n; ++i)
	    {
	        for(int j = 0; j < n; ++j)
	        {
	            if(have.count(x - mat2[i][j]))
	                ++cnt;
	        }
	    }
	    
	    return cnt;
	}

// Optimised Two Pointers Solution

// Time Complexity -> O(n^2)
// Space Complexity -> O(1)

int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int target)
	{
	    // Your code goes here
	    
	    int cnt = 0;
	    
	    int i = 0, j = 0;
	    
	    int x = n-1, y = n-1;
	    
	    while(i < n and x >= 0)
	    {
	        int sum = mat1[i][j] + mat2[x][y];
	        
	        if(sum == target)
	        {
	            ++cnt;
	            ++j;
	            
	            if(j == n)
	            {
	                ++i, j = 0;
	            }
	            
	            --y;
	            if(y < 0)
	            {
	                y = n-1;
	                --x;
	            }
	            
	        }
	        else if(sum < target)
	        {
	            ++j;
	            if(j == n)
	            {
	                ++i, j = 0;
	            }
	        }
	        else
	        {
	            --y;
	            if(y < 0)
	            {
	                y = n-1;
	                --x;
	            }
	        }
	    }
	    
	    return cnt;
	}
