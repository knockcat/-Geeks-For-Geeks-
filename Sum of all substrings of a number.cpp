// naive Approach TLE
class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here

       // Time Complexity -> O(n*n)
       // Space Complexity -> O(1)
        
       const int mod = 1e9+7;
       
       int n = s.size();
       
       long long res = 0;
       
       for(int i = 0; i < n; ++i)
       {
           long long num = 0;
           for(int j = i; j < n; ++j)
           {
               num = (num * 10) + (s[j] - '0');
               num %= mod;
               res = (res + num) % mod;
           }
       }
       
       return res;
    }
};

// Approach 2 O(n) dp
class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here

       // Time Complexity -> O(n)
       // Space Complexity -> O(n)
        
        const int mod = 1e9+7;
        
        int n = s.size();
        
        vector<long long> dp(n, 0);
        
        dp[0] = s[0] - '0';
        
        long long res = dp[0];
        
        for(int i = 1; i < n; ++i)
        {
            long long curr = ((s[i] - '0') * (i+1)) + (10 * dp[i-1]);
            
            curr %= mod;
            
            res = (res + curr) % mod;
            
            dp[i] = curr;
        }
        
        return res;
    }
};

// Approach 3 constant space

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here

       // Time Complexity -> O(n)
       // Space Complexity -> O(1)
        
        const int mod = 1e9+7;
        
        int n = s.size();
    
        long long prev = s[0] - '0';
        
        long long res = prev;
        
        for(int i = 1; i < n; ++i)
        {
            long long curr = ((s[i] - '0') * (i+1)) + (10 * prev);
            
            curr %= mod;
            
            res = (res + curr) % mod;
            
            prev = curr;
        }
        
        return res;
    }
};
