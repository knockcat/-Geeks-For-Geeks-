
// 	Time Complexity -> O(N * log(N))
//      Space Complexity -> O(N) auxilliary space for answer
static bool canSwap(string& a, string& b)
    {
          string f = a + b;
          string s = b + a;
    
          return f > s;
    }
	
	string printLargest(int n, vector<string> &arr) {
	    // code here
	    
	    string ans;
	    
	    sort(arr.begin(), arr.end(), canSwap);
	    
	    for(auto& strs : arr)
	        ans += strs;
	        
	    return ans;
	}

// Using Lamda Function

string printLargest(int n, vector<string> &arr) {
	    // code here
	    
	    string ans;
	    
	    sort(arr.begin(), arr.end(), [&](auto& a, auto& b)
	    {
	        string f = a + b;
	        string s = b + a;
	        return f > s;
	    });
	    
	    for(auto& strs : arr)
	        ans += strs;
	        
	    return ans;
	}


// Compartor Working

#include <bits/stdc++.h>
using namespace std;

bool canSwap(string& a, string& b)
{
      string f = a + b;
      string s = b + a;

      return f > s;
}

// void sort(vector<string> &strs)
// {
//     int n = strs.size();
//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = 0; j < n; ++j)
//         {
//             string a = strs[i];
//             string b = strs[j];

//             if (canSwap(a, b))
//                 swap(strs[i], strs[j]);
//         }
//     }
// }

int main()
{
    vector<string> strs = {"3", "30", "34", "5", "9"};
    string ans;

    // sort(strs);

    sort(strs.begin(), strs.end(), canSwap);

    for (auto &ele : strs)
        ans += ele;

    cout << ans << endl;

    return 0;
}


