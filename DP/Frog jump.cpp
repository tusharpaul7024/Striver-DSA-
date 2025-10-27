// Recursion -- top down
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





// bottom up approach
#include <bits/stdc++.h>



int frogJump(int a, vector<int> &arr)
{
  int n=arr.size()-1;
    int dp[n];
    dp[0]=0;
    for (int i=1;i<=n;i++){
      int l=dp[i-1]+abs(arr[i]-arr[i-1]);
      int r= INT_MAX;
      if(i>1){
        r=dp[i-2]+abs(arr[i]-arr[i-2]);
    }
    dp[i]=min(l,r);
    }
    return dp[n];
}


//space optimization
#include <bits/stdc++.h>



int frogJump(int a, vector<int> &arr)
{
  int n=arr.size()-1;
  int prev=0,prev2=0;
  int curr;
  for (int i=1;i<=n;i++){
     int l=prev+abs(arr[i]-arr[i-1]);
     int r= INT_MAX;
     if(i>1){
        r=prev2+abs(arr[i]-arr[i-2]);
     }
      curr=min(l,r);
     prev2=prev;
     prev=curr;
     
  }
  
   return prev; //taking this because its n-1
}
