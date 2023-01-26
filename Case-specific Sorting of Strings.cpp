//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        
        string lower, upper;
        vector<int> lowerIndex, upperIndex;
        
        for(int i = 0; i<str.size(); ++i)
        {
            if(str[i] >= 'a' and str[i] <= 'z')
            {
                lower.push_back(str[i]);
            }
            else
            {
                upper.push_back(str[i]);
            }
        }
        
        sort(lower.begin(),lower.end());
        sort(upper.begin(),upper.end());
        
        int a = 0, b = 0;
        
        for(int i = 0; i <  n; ++i)
        {
            if(str[i] >= 'a' and str[i] <= 'z')
                str[i] = lower[a++];
            else
                str[i] = upper[b++];
        }
        
        
        return str;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends
