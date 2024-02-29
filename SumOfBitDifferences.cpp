// Approach 1

long long sumBitDifferences(int arr[], int n) {
	    // code here

     // Tc -> O(n * 32) + O(32)
	   // Sc -> O(32)
	    vector<int> bits(32, 0);
	    
	    for(int i = 0; i < n; ++i)
	    {
	        for(int j = 0; j < 32; ++j)
	        {
	            if(arr[i]  & (1 << j))
	                ++bits[j];
	        }
	    }
	    
	    long long diffPairs = 0;
	    
	    for(int i = 0; i < 32; ++i)
	    {
	        long long oneCnt = bits[i];
	        long long zeroCnt = n - bits[i];
	        
	        if(oneCnt == 0 or oneCnt == n)  // all 1 or all 0
	            continue;
	           
	        diffPairs += (oneCnt * zeroCnt * 2);
	       
	    }
	    
	    return diffPairs;
	}

// Approach 2 (Expected)

long long sumBitDifferences(int arr[], int n) {
	   // code here
	    
	   // Tc -> O(32 * n)
	   // Sc -> O(1)
	    
	    long long ans = 0;
	    
	    for(int i = 0; i < 32; ++i)
	    {
	        long long setBit = 0, unSetBit = 0;
	        
	        for(int j = 0; j < n; ++j)
	        {
	            if(arr[j] & (1 << i)) 
	                ++setBit;
	            else
	                ++unSetBit;
	        }
	        
	        ans += (setBit * unSetBit * 2);
	    }
	    
	    return ans;
	}
