// recursion

class Solution {
public:

    int solve(int i,int j , vector<vector<int>>& o){
        if(i==0 && j==0){
            if(o[i][j]==1) return 0;
            return 1;}
        if( i<0 || j<0) return 0;
        if(o[i][j]==1) return 0;

        int up=0,left=0;
        up=solve(i-1,j,o);
        left=solve(i,j-1,o);

        return up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        
     int m=o.size();
     int n=o[0].size();

        return solve(m-1,n-1,o);
    }
};


// top down dp approach

class Solution {
public:

    int solve(int i,int j , vector<vector<int>>& o,vector<vector<int>>& dp){
        if(i==0 && j==0){
            if(o[i][j]==1) return 0;
            return 1;}
        if( i<0 || j<0) return 0;
        if(o[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];


        int up=0,left=0;
        up=solve(i-1,j,o,dp);
        left=solve(i,j-1,o,dp);

        return dp[i][j]=up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        
     int m=o.size();
     int n=o[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,o,dp);
    }
};



//bottom - up approach

class Solution {
public:

  
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        
     int m=o.size();
     int n=o[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
       for(int i=0;i<m;i++){
        int up=0,left=0;
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                if(o[i][j]==1) dp[i][j]=0;
                else dp[i][j]=1;
            }
            else if(o[i][j]==1) dp[i][j]=0;
            else{
               if(i>0) up=dp[i-1][j];
               if(j>0) left=dp[i][j-1];
               dp[i][j]=up+left; 
            }
        }
       }
       return dp[m-1][n-1];
    }
};



// space optimization

class Solution {
public:

  
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        
     int m=o.size();
     int n=o[0].size();
    vector<int> prev(n,0);
       for(int i=0;i<m;i++){
        int up=0,left=0;
        vector<int> temp(n,0);
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                if(o[i][j]==1) temp[j]=0;
                else temp[j]=1;
            }
            else if(o[i][j]==1) temp[j]=0;
            else{
               if(i>0) up=prev[j];
               if(j>0) left=temp[j-1];
               temp[j]=up+left; 
            }
        }
        prev=temp;
       }
       return prev[n-1];
    }
};