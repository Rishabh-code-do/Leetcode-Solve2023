//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod=1000000007;
    int solve(long long  i,long long n,vector<int>&dp)
    {
        if(i>n)
        return 0;
        if(i==n)
        return 1;
        
        if(dp[i]!=-1)
        return dp[i];
        
        dp[i]=((solve(i+1,n,dp)%mod)+(solve(i+2,n,dp)%mod))%mod;
        
        return dp[i];
    }
    
    long long numberOfWays(long long N) {
        //code here
        vector<int>dp(N+1,-1);
        int k=solve(0,N,dp);
        return k;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}
// } Driver Code Ends