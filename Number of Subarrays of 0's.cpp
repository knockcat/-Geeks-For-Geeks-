// User function Template for C++
#define ll long long int
long long int no_of_subarrays(int n, vector<int> &arr) {
    // Write your code here.
    ll cnt=0, res=0;
    for(int i = 0; i<n;++i)
    {
        if(arr[i] == 0)
        ++cnt;
        else{
            res+=(ll) (cnt*(cnt+1)) /2;
            cnt=0;
        }
    }
    if(cnt)
    res+=(cnt*(cnt+1)) /2;
    
    return res;
}
