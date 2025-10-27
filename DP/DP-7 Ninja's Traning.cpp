// recursion 







// bottom - up dp
int solve(int idx,vector<vector<int>>& points,int d,vector<vector<int>>& dp){
if(idx==0){
    int ans =0;
    for (int i=0;i<3;i++){
        if(d!=i){
            ans=max(ans,points[0][i]);
        }
    }
    return ans;
}
if(dp[idx][d]!=-1) return dp[idx][d]; 

int anss=0;

for (int i=0;i<3;i++){
    
    if(d!=i){
 anss = max(anss,solve(idx-1,points,i,dp)+points[idx][i]);
    }
}
return dp[idx][d]=anss;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
int ans=0;
vector<vector<int>> dp(n,vector<int>(4,-1));

n=points.size();
ans=solve(n-1,points,3,dp);
return ans;
}



//tabulation


int ninjaTraining(int n, vector<vector<int>> &points)
{
int ans=0;
vector<vector<int>> dp(n,vector<int>(4,-1));

dp[0][0]=max(points[0][1],points[0][2]);
dp[0][1]=max(points[0][0],points[0][2]);
dp[0][2]=max(points[0][1],points[0][0]);
dp[0][3]=max(dp[0][0],max(points[0][1],points[0][2]));


n=points.size();
for (int day=1;day<n;day++){
    for (int last=0;last<4;last++){
        for (int i=0;i<3;i++){
            if(last!=i){
            dp[day][last]=max(dp[day][last],points[day][i]+dp[day-1][i]);
    }
}
    }
}
return dp[n-1][3];
}