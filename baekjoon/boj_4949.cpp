#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(1){
        getline(cin, s);
        if(s == ".") break;
        stack<char> st;

        for(int i = 0; i < s.size(); i++){

            if(s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }
            if(s[i] == ')'){
                if(!st.empty() && st.top() == '(') st.pop();
                else{
                    st.push(s[i]);
                    break;
                }
            }
            if(s[i] == ']'){
                if(!st.empty() && st.top() == '[') st.pop();
                else{
                    st.push(s[i]);
                    break;
                }
            }
        }

        if(st.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}