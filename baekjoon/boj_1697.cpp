#include<iostream>
#include<queue>
#include<utility>
using namespace std;

// x+1, x-1로의 이동과 2*x의 위치로 이동가능.
// 가장빠른 시간.

int main(void){

    int n, k;
    cin>>n>>k;
    if(n==k){
        cout<<0;
        return 0;
    };
    queue<pair<int,int> >q;
    vector<bool>isVisit(100001,false);
    q.push(make_pair(n,0));
    while(!q.empty()){
        int pos = q.front().first;
        int time = q.front().second;
        q.pop();
        int nextPos[3]={pos-1,pos+1,pos*2};

        for(int i=0;i<3;i++){
            // 범위를 넘어서면 pass
            if(nextPos[i]<0 || nextPos[i]>100000) continue;
            // 이미 방문한 점이면 pass
            if(isVisit[nextPos[i]]) continue;
            //다음 방문점이 타겟과 동일하면 리턴
            if(nextPos[i]==k){
                cout<<time+1;
                return 0;
            }
            isVisit[nextPos[i]]=1;
            q.push(make_pair(nextPos[i],time+1));
        }
    }

    return 0;
}