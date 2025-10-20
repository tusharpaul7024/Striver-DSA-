// Recursion
#include <bits/stdc++.h>

int dp[100001];

int solve(int i, vector<int> &arr){
   if(i==0) return 0;
   if(dp[i]!=-1) return dp[i];
   int right = INT_MAX;
   int left = solve(i-1,arr)+abs(arr[i]-arr[i-1]);
   if(i>1){
     right = solve(i-2,arr)+abs(arr[i]-arr[i-2]);
   }
   return dp[i]=min(left,right);

    
}


int frogJump(int n, vector<int> &heights)
{
    memset(dp, -1, sizeof(dp)); 
    return solve(heights.size()-1,heights);
    
}