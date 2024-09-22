#include<iostream>
#include<stack>
#include<string>

using namespace std;

/*커서를 기준으로 왼쪽 스택과 오른쪽 스택으로 나누어서 진행.
문자가 60만이기 때문에, 
*/
int main(void){

    stack<char>st_left;
    stack<char>st_right;
    string s = "";
    int n;
    cin>>s>>n;

    //처음의 커서는 맨 오른쪽, 따라서 맨 왼쪽 스택에 모든 문자가 들어가 있음.
    for(int i=0;i<s.length();i++){
        st_left.push(s[i]);
    }
    //연산 갯수 만큼 연산 시작.
    /* P = 왼쪽에 추가, B = 왼쪽 삭제 L = 커서 왼쪽이동, D = 커서 오른쪽이동 */
    for(int i=0;i<n;i++){
        char OP;
        cin>>OP;
        if(OP == 'L'){
            //커서 왼쪽 이동시 왼쪽스택에서 값을 뺴고, 오른쪽 스택에 값을 넣음
            if(st_left.empty()) continue;
            st_right.push(st_left.top());
            st_left.pop();
        }
        if(OP == 'D'){
            if(st_right.empty()) continue;
            st_left.push(st_right.top());
            st_right.pop();
        }
        if(OP == 'P'){
            char c;
            cin>>c;
            st_left.push(c);
        }
        if(OP == 'B'){
            if(st_left.empty()) continue;
            st_left.pop();
        }
    }
    //연산이 끝나면, left_Stack의 값들을 right_stack에 넣으면 순서대로 출력 가능

    while(!st_left.empty()){
        st_right.push(st_left.top());
        st_left.pop();
    }

    //출력
    while(!st_right.empty()){
        cout<<st_right.top();
        st_right.pop();
    }

    return 0;

}