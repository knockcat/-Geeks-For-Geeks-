// Brute

char nthCharacter(string s, int r, int n) {
        //code here
        
        string newStr = s;
        
        while(r--)
        {
            string here;
            
            for(int i = 0; i < newStr.size(); ++i)
            {
                if(newStr[i] == '0')
                    here += "01";
                else
                    here += "10";
            }
            
            newStr = here;
            here.clear();
        }
        
        return newStr[n];
    }

// Optimal

 /*
  
      0         1
    /  \       / \
    0   1     1   0
    ev  od   ev   odd
    
  */
//   Time Complexity -> O(r)
//   Space Complexity -> O(r)
  
    char helper(string& s, int r, int n)
    {
        if(r == 0)
            return s[n];
        
        char curr = helper(s, r-1, n/2);
        
        if(n & 1)
        {
            if(curr == '0')
                return '1';
            else
                return '0';
        }
        else
        {
            if(curr == '0')
                return '0';
            else
                return '1';
        }
    }
  
    char nthCharacter(string s, int r, int n) {
        //code here
        
        return helper(s, r, n);
    }
