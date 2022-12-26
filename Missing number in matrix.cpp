//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long int
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
        // Code here
        
        
        ll n = matrix.size(), m = matrix[0].size();
        
        ll sum1, sum2 , sum3 , sum4;
        sum1 = sum2 = sum3 = sum4 = 0;
        set<ll> first, second;
        
        for(int i = 0; i < n; ++i)
        {
            bool ok = false;
            sum1 = sum2 = 0;
            for(int j = 0; j < m; ++j)
            {
                if(matrix[i][j] == 0)
                    ok = true;
                sum1 += matrix[i][j];
                sum2+= matrix[j][i];
            }
            if(ok)
            {
                second.insert(sum2);
                second.insert(sum1);
            }
            else
            {
                first.insert(sum1);
                first.insert(sum2);
            }
        }
        
        bool ok = false;
        for(int i = 0; i<n; ++i)
        {
            if(matrix[i][i] == 0)
                ok = true;
            sum3 += matrix[i][i];
        }
        if(ok)
            second.insert(sum3);
        else
            first.insert(sum3);
        
        bool ok2 = false;    
        for(int i = 0, j = n - 1; j >= 0; ++i,--j)
        {
            if(matrix[i][j] == 0)
                ok2 = true;
            sum4 += matrix[i][j];
        }
        if(ok2)
            second.insert(sum4);
        else
            first.insert(sum3);
            
        if(first.size() == 1 and second.size() == 1)
        {
            ll one = *first.begin();
            ll two = *second.begin();
            
            if(one <= two)
                return -1;
            return one - two;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
