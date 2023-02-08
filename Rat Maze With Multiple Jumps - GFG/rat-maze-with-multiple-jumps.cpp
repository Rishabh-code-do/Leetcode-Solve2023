//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
     bool isSafe(int x, int y, int &m, int &n, vector<vector<int>> &matrix)
    {
    return x >= 0 && y >= 0 && x < m && y < n && matrix[x][y] != 0;
    }
    bool solve(vector<vector<int>> &matrix, int x, int y, int &m, int &n, vector<vector<int>> &ans)
    {
        if (x == m - 1 && y == n - 1)
        { 
            ans[x][y] = 1;
            return true;
        }
        if (isSafe(x, y, m, n, matrix))
        {
            ans[x][y] = 1;
            for (int i = 1; i <= matrix[x][y]; i++)
            {
                if (solve(matrix, x, y + i, m, n, ans))
                    return true;
                if (solve(matrix, x + i, y, m, n, ans))
                    return true;
            }
            ans[x][y] = 0;
            return false;
        }
        return false;
    }
    vector<vector<int>> ShortestDistance(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        if (solve(matrix, 0, 0, m, n, ans))
            return ans;
        return {{-1}};
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends