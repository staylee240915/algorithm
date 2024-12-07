#include<iostream>
#include<vector>

using namespace std;

void dp(vector<vector<int> > &isChk, vector<vector<int> > &color, int idx, int target){
    //탈출조건
    if(idx == target) return;

    isChk[idx][0] = min(isChk[idx-1][1],isChk[idx-1][2]) + color[idx][0];
    
    isChk[idx][1] = min(isChk[idx-1][0],isChk[idx-1][2]) + color[idx][1];

    isChk[idx][2] = min(isChk[idx-1][1],isChk[idx-1][0]) + color[idx][2];

    dp(isChk,color,idx+1,target);

    return;
}
int main(void){

    int n; // 집의 수
    //두번쨰 줄 부터 n개의 수는 각각 r g b를 칠하는 비용.
    //즉, n=1 이란 첫번쨰 집을 r, g, b로 칠하는 경우가 존재하고,
    //이에 대한 비용은 각각 row1에 존재. 이후 진행.
    
    //칠할 수 있는 색에 대한 초기화.
    cin>>n;
    vector<vector<int> >color(n,vector<int>(3,0));
    vector<vector<int> >isChk(n,vector<int>(3,0));

    for(int i=0;i<n;i++){
        cin>>color[i][0]>>color[i][1]>>color[i][2];
    }

    //isChk의 첫번째 값을 초기값으로 세팅.
    isChk[0][0] = color[0][0];
    isChk[0][1] = color[0][1];
    isChk[0][2] = color[0][2];

    dp(isChk,color,1,n);

    //isChk의 마지막 n의 3개의 값 중 최솟값을 찾아서 반환.
    int minv = min(min(isChk[n-1][1],isChk[n-1][2]),isChk[n-1][0]);

    cout<<minv;
    return 0;
}