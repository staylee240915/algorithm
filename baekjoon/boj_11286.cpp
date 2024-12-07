#include<iostream>
#include<queue>
#include<cstdlib>
#include<utility>

using namespace std;
/*
* priority_queue에서:
*
* Max-Heap: 기본적으로 a < b를 비교하여 큰 값이 위에 오도록 정렬.
* Min-Heap: 비교 기준을 a > b로 설정하여 작은 값이 위에 오도록 정렬.
*/
struct cmp{
    bool operator()(pair<int,int>&a, pair<int,int>&b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        
        return a.first>b.first;
    }
};
int main(void){

    int n;
    cin>>n;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int>arr(n);
    priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> pq;


    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]!=0){
            pq.push(make_pair(abs(arr[i]),arr[i]));
        }
        if(arr[i]==0){
            if(pq.empty()) cout<<0<<"\n";
            else{
                cout<<pq.top().second<<"\n";
                pq.pop();
            }
        }
    }

    //0을만나면, 절대값이 가장 작은 수를 모두 pop

    return 0;
}