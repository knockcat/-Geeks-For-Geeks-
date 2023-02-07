//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

// } Driver Code Ends

#define ll long long int

class Solution{
    public:
    //You need to complete this fucntion
    
    ll expo(ll x, ll y)
    {
        ll res = 1;
        
        while(y > 0)
        {
            if(y & 1)
                res = (x * res) % mod;
            x = (x*x) % mod;
            
            y >>= 1;
        }
        
        return res;
    }
    
    
    
    long long power(int N,int R)
    {
       //Your code here
        
    //   return expo(N,R);    
    
        if(R == 0)
            return 1;
        if(R == 1)
            return N % mod;
            
        ll ans = 1;
        ll know = power(N,R/2)%mod;
        
        if(R&1)
            ans = (ans*N)%mod;
        
        return(ans*((know * know)%mod))%mod;
        
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends
