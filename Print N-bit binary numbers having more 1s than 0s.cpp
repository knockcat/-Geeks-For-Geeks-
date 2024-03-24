 void helper(int one, int zero, int n, string ds, vector<string>& res)
    {
        if(one + zero == n)
        {
            res.push_back(ds);
            return;
        }
        
        if(one < n)
            helper(one + 1, zero, n, ds + '1', res);
        if(zero < one)
            helper(one, zero+1, n, ds + '0', res);
    }

	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    
	   // Time Complexity -> O(2^n)
	   // Space Complexity -> O(2^n)
	    
	    vector<string> res;
	    
	    string ds;
	    
	    helper(0, 0, n, ds, res);
	    
	    return res;
	}
