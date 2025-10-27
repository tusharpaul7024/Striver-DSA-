//recursion
class Solution {
    long long solve(int i,int j,vector<vector<int>>& g){
        if(i==0 && j==0) return g[i][j];
        if(i<0 || j<0) return INT_MAX;
       
        long long up=INT_MAX;
        long long left=INT_MAX;
        up=g[i][j]+solve(i-1,j,g);
        left= g[i][j]+solve(i,j-1,g);
        return min(up,left);

    }

public:
    int minPathSum(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,g,dp);
    }
};

// top down dp
class Solution {
    long long solve(int i,int j,vector<vector<int>>& g,vector<vector<int>>& dp){
        if(i==0 && j==0) return g[i][j];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        long long up=INT_MAX;
        long long left=INT_MAX;
        up=g[i][j]+solve(i-1,j,g,dp);
        left= g[i][j]+solve(i,j-1,g,dp);
        return dp[i][j]=min(up,left);

    }

public:
    int minPathSum(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,g,dp);
    }
};


// bottom - up dp
class Solution {
   
public:
    int minPathSum(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
       for (int i=0;i<n;i++){
        long long up=INT_MAX;
        long long left=INT_MAX;
        for (int j=0;j<m;j++){
             if(i==0 && j==0) dp[i][j]=g[i][j];
             else{
                if(i>0) up=g[i][j]+dp[i-1][j];
                if(j>0) left= g[i][j]+dp[i][j-1];
                dp[i][j]=min(up,left);
             }
        }
       }
       return dp[n-1][m-1];
    }
};


// space optimization

class Solution {
   
public:
    int minPathSum(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<int> prev(m,-1);
       for (int i=0;i<n;i++){
        long long up=INT_MAX;
        long long left=INT_MAX;
        vector<int> temp(m,-1);
        for (int j=0;j<m;j++){
             if(i==0 && j==0) temp[j]=g[i][j];
             else{
                if(i>0) up=g[i][j]+prev[j];
                if(j>0) left= g[i][j]+temp[j-1];
                temp[j]=min(up,left);
             }
            
        }
        prev=temp;
       }
       return prev[m-1];
    }
};