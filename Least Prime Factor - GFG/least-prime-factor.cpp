//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        
        bool pr[n+1];
        memset(pr, true, sizeof(pr));
        vector<int>prime(n+1);
        prime[0]=0;
        prime[1]=1;
        for (int p = 2; p<= n; p++) {
            if (pr[p] == true) {
                prime[p]=p;
                for (int i = p*p; i <= n; i += p)
                {
                    if(pr[i]==true)
                    prime[i] = p;
                    pr[i]=false;
                }
            }
        }
        return prime;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends