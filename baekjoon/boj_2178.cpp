#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<string>
using namespace std;

int dx[4] = {0,1,-1,0};
int dy[4] = {-1,0,0,1};

int main(void){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int m, n;
    int cnt = 0;
    cin>>n>>m;
    vector<vector<int> >board(n,vector<int>(m,0));
    vector<vector<int> >isChk(n,vector<int>(m,0));

    isChk[0][0]=1;
    // 영역 초기화.
    for(int i=0;i<n;i++){
        string s = "";
        cin>>s;
        for(int j=0;j<m;j++){
            board[i][j] = s[j]-'0';
        }
    }

    queue<pair<int,int> >q;
    q.push(make_pair(0,0));
    while(!q.empty()){

        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // 상하좌우 확인
        for(int k=0;k<4;k++){
            int curx = x+dx[k];
            int cury = y+dy[k];
            //범위를 벗어나면 pass
            if(curx<0 || cury<0 || curx>= n|| cury>= m) continue;
            //방문할 수 없는 곳이면 pass
            if(board[curx][cury]==0) continue;
            //이미 방문한 곳이면 pass
            if(isChk[curx][cury]) continue;

            //4가지 조건을 모두 통과하면 방문 가능한 곳.
            isChk[curx][cury]=isChk[x][y]+1;
            q.push(make_pair(curx,cury));
        }
    }
    cout<<isChk[n-1][m-1];
    return 0;
}