#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int n;
//상향식 필요.
int findMinCost(int node,int level, vector<vector<int> > &arr, vector<vector<int> > &dp){

    if(level == 0){
        if(node==0) return arr[0][0];
        if(node==1) return arr[0][1];
        if(node==2) return arr[0][2];
    }

    if(dp[level][node]!=-1) return dp[level][node];

    if(node==0) dp[level][node] = arr[level][node]+ min(findMinCost(1,level-1,arr,dp),findMinCost(2,level-1,arr,dp));

    if(node==1) dp[level][node] = arr[level][node]+ min(findMinCost(0,level-1,arr,dp),findMinCost(2,level-1,arr,dp));
    
    if(node==2) dp[level][node] = arr[level][node]+ min(findMinCost(0,level-1,arr,dp),findMinCost(1,level-1,arr,dp));

    return dp[level][node];
}
int main(void){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    vector<vector<int> >arr(n,vector<int>(3,0)); //초기화 배열
    vector<vector<int> >dp(n,vector<int>(3,-1)); //합 배열
    //배열 초기화.
    for(int i=0;i<n;i++){
        int temp = 0;
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }

    int minf = findMinCost(0,n-1,arr,dp);
    int mins = findMinCost(1,n-1,arr,dp);
    int mint = findMinCost(2,n-1,arr,dp);

    int answer = min(minf,mins);
    answer = min(answer, mint);

    cout<<answer;
    return 0;
}