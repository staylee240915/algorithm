#include<iostream>

using namespace std;

int main(void){

    int t;
    cin>>t;

    for(int i=0;i<t; i++){

        long long result = 1;
        int n;
        int m;

        cin>>n>>m;
        int r=1;
        for(int j=m;j>m-n;j--){
            result *=j;
            result /=r;
            r++;
        }
        cout<<result<<"\n";
    }

    return 0;
}