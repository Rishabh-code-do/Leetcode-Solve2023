//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    long long mod=1000000007;
    int solve(int i,int n, vector<int>&dp)
    {
        if(i==n)
        return 1;
        if(i>n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        
        dp[i]=(solve(i+1,n,dp)%mod +solve(i+2,n,dp)%mod)%mod;
        
        return dp[i];
    }
    int countWays(int n)
    {
        vector<int>dp(n+1,-1);
        // your code here
        int k=solve(0,n,dp);
        return k;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends