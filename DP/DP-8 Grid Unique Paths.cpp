// recursion.

class Solution {
public:
    int solve(int i, int j){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        int up=solve(i-1,j);
        int left=solve(i,j-1);
         
        return left+up;

    }
    int uniquePaths(int m, int n) {
        return solve(m-1,n-1);
    }
};



// recursion dp top-down method;

class Solution {
public:
    int solve(int i, int j,vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1 ) return dp[i][j];

        int up=solve(i-1,j,dp);
        int left=solve(i,j-1,dp);
         
        return dp[i][j]=left+up;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};


// bottom up approach 
    class Solution { 
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        

        for(int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                int up=0;
                int left=0;
                if(i==0 && j==0){ dp[i][j]=1;
                  
                }else{
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                 dp[i][j]=up+left;
            }
            }
        }

        return dp[m-1][n-1];
    }
};


//  space optimization

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        

        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            int up=0,left=0;
            for (int j=0;j<n;j++){
                int up=0;
                int left=0;
                if(i==0 && j==0){ temp[j]=1;
                  
                }else{
                if(i>0) up=prev[j];
                if(j>0) left =temp[j-1];
                temp[j]=up+left;
            }

            }
            prev=temp;
        }

        return prev[n-1];
    }
};