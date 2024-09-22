#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void){

    stack<char>st;
    string s = "";
    int answer = 0;
    cin>>s;

    //막대기와 레이저를 표시하는 문자열을 받고 이를 string에 저장
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push('(');
        }
        if(s[i]==')'){
            //레이저의 경우.
            if(s[i-1]=='('){
                //레이저를 만나면, 스택에 들어가있는 막대기의 길이만큼 막대기 추가.
                st.pop();
                answer+=st.size();
            }else{
                //막대기의 끝을 만난 경우 스택에 들어가 있는 상단 막대기 하나를 제외하고
                //막대기의 갯수를 1 추가.
                st.pop();
                answer++;
            }
        }
    }
    cout<<answer;
    return 0;
}