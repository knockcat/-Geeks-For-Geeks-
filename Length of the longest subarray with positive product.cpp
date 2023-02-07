//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           
           int pos = 0, neg = 0, res = 0;
           
           for(int i = 0; i<n; ++i)
           {
                if(arr[i] == 0)
                {
                   pos = neg = 0;
                }
                else if(arr[i] < 0)
                {
                   swap(pos,neg);
                   if(pos != 0)
                        pos += 1;
                   neg += 1;
                }
                else
                {
                    pos += 1;
                    if(neg != 0)
                        neg += 1;
                }
                res = max(res,pos);
           }
           
           return res;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends
