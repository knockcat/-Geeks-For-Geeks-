class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here

        // Time Complexity -> O(2^n * n) + O(2^n log 2^n)
        // Space Complexity -> O(2^n)
      
		    int n = s.size();
		    
		    int range = (1 << n) - 1;  // pow(2, n) - 1;
		    
		    vector<string> result;
		    
		    for(int mask = 1; mask <= range; ++mask)
		    {
		        string curr;
		        
		        for(int i = 0; i < n; ++i)
		        {
		            if(mask & ( 1 << i))
		                curr += s[i];
		        }
		        
		        result.push_back(curr);
		    }
		    
		    sort(result.begin(), result.end());
		    
		    return result;
		    
		}
};
