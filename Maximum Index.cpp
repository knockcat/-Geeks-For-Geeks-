// Brute Force

int maxIndexDiff(int A[], int N) 
    { 
        // Your code here

        // Time Complexity -> O(n)
        // Space Complexity -> O(1)
        
        int ans = INT_MIN;
        
        for(int i = 0; i< N; ++i)
        {
            for(int j = i+1; j<N; ++j)
            {
                if(A[i] <= A[j])
                {
                    ans = max(ans, j - i);
                }
            }
        }
        
        return (ans == INT_MIN ? 0 : ans);
    }

// Optimal

int maxIndexDiff(int a[], int n) 
    { 
        // Your code here

        // Time Complexity -> O(n)
        // Space Complexity -> O(n)
        
        vector<int> pref(n, INT_MAX);
        vector<int> suff(n, INT_MIN);
        
        int ans = 0;
        
        pref[0] = a[0], suff[n-1] = a[n-1];
        
        for(int i = 1; i < n; ++i)
        {
            pref[i] = min(pref[i-1] , a[i]);
        }
        
        for(int i = n-2; i >= 0; --i)
        {
            suff[i] = max(suff[i+1], a[i]);
        }
        
        int i = 0, j = 0;
        
        while(j < n)
        {
            if(pref[i] <= suff[j])
            {
                ans = max(ans, j - i);
                ++j;
            }
            else
            {
                ++i;
            }
        }
        
        return ans;
        
    }
