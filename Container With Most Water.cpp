//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

#define ll long long int
long long maxArea(long long A[], int len)
{
    // Your code goes here
    
    ll maxArea = 0;
    ll left = 0, right = len-1;
    ll widht;
    
    while(left < right)
    {
        int width = right - left;
        
        int height = min(A[left], A[right]);
        maxArea = max(maxArea, (ll)width * height);
        
        if(A[left] < A[right])
            ++left;
        else if(A[left] > A[right])
            --right;
        else
            ++left, --right;
    }
    
    return maxArea;
    
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends
