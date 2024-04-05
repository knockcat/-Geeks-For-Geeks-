
// Recursive Solution

// Time Complexity -> O(2^n)
// Space Complexity -> O(n) recursion stack

class Solution {
  public:

    int helper(int idx, int prev, vector<int>& nums)
    {
        if(idx == nums.size())
            return 0;
        
        int notTake = helper(idx+1, prev, nums);
        int take = 0;
        
        if(prev == -1 or (nums[idx] > nums[prev] and (nums[idx] -  nums[prev]) > (idx -  prev - 1)))
            take = 1 + helper(idx+1, idx, nums);
        
        return max(take, notTake);
    }

    int min_operations(vector<int>& nums) {
        // Code here
        
        int n = nums.size();
        
        return n - helper(0, -1, nums);
    }
};

// Memoized Solution

// Time Complexity -> O(N^2)
// Space Complexity -> O(N^2) + O(N) recursion stack

int helper(int idx, int prev, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(idx == nums.size())
            return 0;
            
        if(dp[idx][prev+1] != -1)
            return dp[idx][prev+1];
        
        int notTake = helper(idx+1, prev, nums, dp);
        int take = 0;
        
        if(prev == -1 or (nums[idx] > nums[prev] and (nums[idx] -  nums[prev]) > (idx -  prev - 1)))
            take = 1 + helper(idx+1, idx, nums, dp);
        
        return dp[idx][prev+1] = max(take, notTake);
    }

    int min_operations(vector<int>& nums) {
        // Code here
        
        int n = nums.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return n - helper(0, -1, nums, dp);
    }

// Iterative Solution

// Time Complexity -> O(n^2)
// Space Complexity -> O(n)

class Solution {
  public:

    int min_operations(vector<int>& nums) {
        // Code here
        
        int n = nums.size();
        
        vector<int> dp(n+1, 1);
        
        int maxLis = 1;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[i] > nums[j] and (nums[i] - nums[j] > (i - j - 1)))
                    dp[i] = max(dp[i], 1 + dp[j]);
                maxLis = max(maxLis, dp[i]);
            }
        }
        
        return n - maxLis;
    }
};
