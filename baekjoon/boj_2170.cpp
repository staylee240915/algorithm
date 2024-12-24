#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
//#include<bits/stdc++.h>
//기본적인 헤더파일 구비, 메모리 낭비 존재.
using namespace std;

//정렬과 스위핑을 이용.
bool operation(pair<int,int> &a, pair<int,int> &b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
int main(void){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<pair<int,int> >arr;

    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        arr.push_back(make_pair(a,b));
    }
    sort(arr.begin(),arr.end(),operation);

    int start = arr[0].first;
    int end = arr[0].second;
    int sum = 0;
    for(int i=1;i<arr.size();i++){

        int nextStart = arr[i].first;
        int nextEnd = arr[i].second;

        // s<ns는 보장 (정렬)
        //따라서 nextEnd가 더 크다면, 
        if(nextStart<end){
            end = max(end,nextEnd);
        }else{
            sum+=end-start;
            start = nextStart;
            end = nextEnd;
        }

    }
    sum+=end-start;
    cout<<sum;

    return 0;
}