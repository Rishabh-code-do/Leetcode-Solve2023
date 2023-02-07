//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

int count=0;
int solve(int i,int j,int m,int n)
{
    if(i==m-1 && j==n-1)
    {
    return 1;
    }
    if(i>m-1 || j>n-1)
    return 0;
    else 
    {
        return solve(i+1,j,m,n)+solve(i,j+1,m,n);
    }
}
long long  numberOfPaths(int m, int n)
{
    // Code Here
    int k=solve(0,0,m,n);
    return k;
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends