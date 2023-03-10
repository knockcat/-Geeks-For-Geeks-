//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Complete the function
    	
        long long mx1,mx2,mx3,mn1,mn2;
        mx1 = mx2 = mx3 =  INT_MIN;
        mn1 = mn2 = INT_MAX;
        
        for(int i = 0; i<n; ++i)
        {
            if(arr[i] > mx1)
            {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = arr[i];
            }
            else if(arr[i] > mx2)
            {
                mx3 = mx2;
                mx2 = arr[i];
            }
            else if(arr[i] > mx3)
            {
                mx3 = arr[i];
            }
            
            if(arr[i] < mn1)
            {
                mn2 = mn1;
                mn1 = arr[i];
            }
            else if(arr[i] < mn2)
            {
                mn2 = arr[i];
            }
        }
        
        return max(mx1*mx2 *mx3, mn1*mn2*mx1);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends
