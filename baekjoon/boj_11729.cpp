#include<iostream>
#include<cmath>
using namespace std;

//하노이탑, 이동이 최소가 되도록, 원판을 이동하는 과정을 출력.
//원판은 첫번쨰 장대에 있으며, 이 원판을 세번쨰 장대에 옮기려 한다.
void hanoi(int n, int first, int second, int third){

    //탈출조건 남은 원판의 갯수가 1개일떄
    if(n==1) {cout<<first<<" "<<third<<"\n"; return;}

    hanoi(n-1,first,third,second);
    cout<<first<<" "<<third<<"\n";
    hanoi(n-1,second,first,third);

}
int main(void){

    //n은 원판의 갯수.
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    cout << (1 << n) - 1 << "\n"; // 최소 이동 횟수 계산
    hanoi(n,1,2,3);
    return 0;
}