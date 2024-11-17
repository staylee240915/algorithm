#include<iostream>
using namespace std;

int arr[6] = {1,6,4,3,5,2};

// 두 배열을 합치는 것.
// 두 배열을 합치기 위해 새로운 배열이 필요.
//본 예제는 오름차순으로 진행.
//본 예제는 sorted라는 새로운 배열에 값을 넣기 떄문에
//k = 0이 되지만, 만약 그렇지 않고 left right 배열을 만들어서
//기존의 배열에 넣는 방식이라면 k = left로 구현되어야함.
void merge(int *arr, int first, int mid, int last){

    int* sorted = new int[last-first+1];
    int i,j,k;
    i = first;//첫번쨰 arr의 첫 요소
    j = mid+1;//두번쨰 arr의 첫 요소
    k = 0;//정렬된 arr의 첫 요소.

    //첫번쨰 배열과 두번쨰 배열의 요소가 마지막까지 가지 않았다면.
    while(i<=mid && j<=last){
        //첫번쨰 배열요소가 두번쨰 배열요소보다 작다면, 넣기.
        if(arr[i]<=arr[j]) sorted[k++] = arr[i++];
        //두번쨰 배열 요소가 더 작다면
        else sorted[k++] = arr[j++];
    }
    // i가 끝까지 왔다면
    if(i>mid){
        //j요소가 마지막까지 가지 않았다면 나머지 j요소를 차례대로 넣음.
        //각 배열은 정렬된 상태일 것임으로 (최소단위로 나누었을때 합치면서 이미 정렬됨.)
        while(j<= last) sorted[k++] = arr[j++];
    }else{
        while(i<=mid) sorted[k++]=arr[i++];
    }

    //divide conquer 이나, 배열을 두개로 물리적으로 나누지 않고
    //idx를 통해서 논리적으로 나눔.
    //이를 통해서 공간복잡도를 줄일 수 있음.
    // 원배열에 정렬된 상태로 집어넣고 반환.
    // 배열의 시작주소가 0이 아닐 수 있기 떄문에, 인덱스를 2개로 시작.
    for(i=first, k=0;i<=last;i++,k++){
        arr[i] = sorted[k];
    }
    delete[] sorted;
}
void mergeSort(int *arr, int first, int last){

    //first가 last보다 작다면 계속 나눔.
    //크기가 1이 된다면 이미 정렬된 상태.
    //예를 들어 크기가 2인 배열이 들어온다면, 
    // 1,2번쨰 mergeSort는 pass되고,
    if(first>=last) return;
    int mid = first + (last-first)/2;
    mergeSort(arr,first,mid);
    mergeSort(arr,mid+1,last);
    merge(arr,first,mid,last);
}
void printArr(int* arr,int len){
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
}
int main(void){

    mergeSort(arr,0,5);
    printArr(arr, 6);
    return 0;
}