//Time Complexity O(n*m)
//dp[i][j]=1+dp[i-1][j-1]                if A[j]=B[i]
//dp[i][j]=max(dp[i-1][j],dp[i][j-1])    if A[j]!=B[i]
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int rows=B.size();
        int col=A.size();
        int dp[rows+1][col+1];
        dp[0][0]=0;
        int ans=0;
        for(int i=1;i<=rows;i++) dp[i][0]=0;
        for(int i=1;i<=col;i++)  dp[0][i]=0;
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=col;j++){
                if(B[i-1]==A[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};