	bool sameFreq(string s)
	{
	    // code here 
	    
	    Time Complexity -> O(n) + O(26) + O(26 * 26) => O(n)
	    Space Complexity -> O(26) 
	    
        vector<int> freq(26, 0);
        int maxCnt = 0;
        
        for(auto& ch : s)
        {
            ++freq[ch - 'a'];  // freq[ch - 'a']++
            maxCnt = max(maxCnt, freq[ch - 'a']);
        }
            
        // if All same
        
        bool flag = true;
        
        for(int i = 0; i < 26; ++i)
        {
            if(freq[i] > 0 and freq[i] != maxCnt)
                flag = false;
        }
        
        if(flag) return true;
        
        
        // atmost 1
        for(int i = 0; i < 26; ++i)
        {
            if(freq[i] > 0)
            {
                int currCnt = freq[i] - 1;
                
                bool ok = true;
                
                for(int j = 0; j < 26; ++j)
                {
                    if(freq[j] > 0 and freq[j] != currCnt and j != i)
                    {
                        ok = false;
                        break;
                    }
                }
                
                if(ok)
                    return true;
            }
        }
        
        return false;
	}
