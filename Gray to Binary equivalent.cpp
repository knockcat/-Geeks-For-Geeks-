class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        
        // Your code here
        
        // Time Complexity -> O(32)
        // Space Complexity ->  O(1)
        
        int ans = 0;
        
        bool firstSet = 0, prev = 0;
        
        for(int i = 31; i >= 0; --i)
        {
            if(n & (1 << i) and !firstSet)
            {
                ans = (1 << i);
                prev = firstSet = 1;
                continue;
            }
            
            bool curr = (n & (1 << i) ? 1 : 0);
            
            if(curr ^ prev)
                ans |= (1 << i);
            
            prev = curr ^ prev;
        }
        
        return ans;
    }
};
