//n번쨰 피보나치수를 구하기
#include<iostream>
#include<cstring>
#include<string.h>
#include<algorithm>

using namespace std;

// 피보나치수는 fibo n = fibo n-1 + fibo n-2
// 재귀의 경우 dp (메모이제이션도 필요)
int *arr;
int fibo(int num){
    // 종료조건 1. 0보다 작으면 종료
    if(num<0) return 0;

    // 종료조건 2. 미리 구한 값에 있으면 해당 값을 반환하고 종료
    if(arr[num]!=-1) return arr[num];

    arr[num] = fibo(num-1) + fibo(num-2);
    
    return arr[num];
}
int main(void){


    int n;
    cin>>n;
    //메모이제이션을 위한 배열 채우기. n = 0일때, 
    //문제는 memset의 경우 메모리 블록을 채우는 것이기 때문에, int형의 변수값으로 채우게 되면 재대로 초기화 되지 않음.
    //0~255 사이의 unsigned char 값으로 채워야함.
    //메모리 블록 할당의 기준은 1byte
    //따라서 c++ algorithm 헤더파일의 fill을 대체로 사용함.
    
    //c의 경우 동적할당은 malloc을 이용 또한 free를 이용해야함.
    arr = (int*)malloc(sizeof(int)*n);

    memset(arr,-1,sizeof(int)*(n+2));
    //fill(arr,arr+n+2,-1);
    arr[0] = 0;
    arr[1] = 1;

    cout<< fibo(n);
    free(arr);
    return 0;
}