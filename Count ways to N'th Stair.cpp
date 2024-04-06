
// Intuition Building Approach

class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        // your code here
        
        // Time Complexity -> O(n)
        // Space Complexity -> O(1)
        
        long long ways = 0;
        
        for(int i = 0; i <= n/2; ++i)
        {
            long long occupiedBy2 = (2*i);
            long long remaining = n - occupiedBy2; // occupiedBy1
            
            // even we just count ways without this condition it will work
            // already explained in video solution
            
            if(occupiedBy2 + remaining == n) 
                ++ways;
        }
        return ways;
    }
};

// Observative Approach from above one

class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        // your code here
        
        // Time Complexity -> O(1)
        // Space Complexity -> O(1)
        
        return (n/2) + 1;
    }
};
