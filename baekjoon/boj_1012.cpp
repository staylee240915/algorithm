#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

int ix[4]={0,1,-1,0};
int iy[4]={1,0,0,-1};
int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int testCase = 0;
    cin>>testCase;
    for(int i=0;i<testCase;i++){
        int n, m, num;
        int answer = 0;
        cin>>m>>n>>num;
        vector<vector<int> >arr(n,vector<int>(m,0));
        vector<vector<bool> >isChk(n,vector<bool>(m,0));

        //배추벌레의 위치
        for(int a=0;a<num;a++){
            int f,s;
            cin>>f>>s;
            arr[s][f]=1;
        }

        
        //그래프 탐색 (bfs)
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){

                //배추벌래가 없는 위치는 pass
                if(arr[a][b]==0) continue;
                //이미 방문한 점은 pass
                if(isChk[a][b])continue;
                queue<pair<int,int> >q;
                q.push(make_pair(a,b));
                isChk[a][b]=true;
                while(!q.empty()){
                    int curx = q.front().first;
                    int cury = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){

                        int areax = curx +ix[k];
                        int areay = cury+iy[k];
                        //범위를 벗어나면 pass
                        if(areax<0 || areay<0 || areax>=n || areay>=m) continue;
                        //이미 방문한 장소이면 pass
                        if(isChk[areax][areay]) continue;
                        //arr에서 없는 구역이면 pass
                        if(arr[areax][areay]==0) continue;
                        q.push(make_pair(areax,areay));
                        isChk[areax][areay]=true;
                    }
                }
                answer++;
            }
        }
        cout<<answer<<"\n";
    }
    
    return 0;
}