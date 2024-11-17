#include<iostream>
#include<vector>

using namespace std;
int n;
vector<vector<char> >tree(26,vector<char>(3,'.'));

void pre(int level){

    if(tree[level][0]=='.')return;
    cout<<tree[level][0];
    if (tree[level][1] != '.')pre(tree[level][1]-'A');
    if (tree[level][2] != '.')pre(tree[level][2]-'A');

}

void inorder(int level){
    
    if(tree[level][0]=='.')return;
    if (tree[level][1] != '.')inorder(tree[level][1]-'A');
    cout<<tree[level][0];
    if (tree[level][2] != '.')inorder(tree[level][2]-'A');

}

void post(int level){

    if(tree[level][0]=='.')return;
    if (tree[level][1] != '.')post(tree[level][1]-'A');
    if (tree[level][2] != '.')post(tree[level][2]-'A');
    cout<<tree[level][0];

}
int main(void){

    //linked list로 트리 구성.(단방향)
    //pre , in, post의 차이는 root를 언제 방문하냐에 따라 달라진다.
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char root;
        char left;
        char right;

        cin>>root>>left>>right;
        tree[root-'A'][0] = root;
        tree[root-'A'][1] = left;
        tree[root-'A'][2] = right;
    }

    pre(0);
    cout<<"\n";
    inorder(0);
    cout<<"\n";
    post(0);

    return 0;

}