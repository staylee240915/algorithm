#include<iostream>
using namespace std;

//3, 5키로 설탕봉지를 최소로 하여 정확하게 무게를 맞추려면 몇개 가져가면 되는가.
int *arr;

int main(void){

    int n;
    int answer = 0;
    arr = new int[5001];
    fill(arr,arr+5001,-1);
    arr[3] = 1;
    arr[5] = 1;

    //buttom up으로, 초기값이 3과 5인 경우에만 계산에 사용하도록 함.
    for(int i=6;i<5001;i++){
        if(arr[i-3]!=-1) arr[i] = arr[i-3]+1; //값이 있다면 해당 값에서 +1한 것이 답
        if(arr[i-5]!=-1) {
            if(arr[i]==-1) arr[i] = arr[i-5]+1; //i-3을 만족하지 못한 경우 -5한 값이 있다면 +1한것이 답.
            else arr[i] = min(arr[i],arr[i-5]+1) ;// arr[i]값이 있는 경우 3에 해당 하는 값이 있으므로 5와 비교하여 작은 것이 답.
        }
    }
    
    cin>>n;
    answer = arr[n];
    delete[] arr;
    cout<<answer;
    return 0;
}