#include<iostream>
#include<vector>
#include<string.h>

#define endl '\n'
typedef long long ll;

using namespace std;
vector<vector<int>> nodes(26, vector<int> (2,-1));

void preorder_traverse(int crnt){ // Root -> left -> right
    cout << (char)(crnt+'A');
    if(nodes[crnt][0]!=-1) preorder_traverse(nodes[crnt][0]);
    if(nodes[crnt][1]!=-1) preorder_traverse(nodes[crnt][1]);
}

void inorder_traverse(int crnt){ // left -> root -> right
    if(nodes[crnt][0]!=-1) inorder_traverse(nodes[crnt][0]);
    cout << (char)(crnt+'A');
    if(nodes[crnt][1]!=-1) inorder_traverse(nodes[crnt][1]);
}

void postorder_traverse(int crnt){ // left -> right -> root
    if(nodes[crnt][0]!=-1) postorder_traverse(nodes[crnt][0]);
    if(nodes[crnt][1]!=-1) postorder_traverse(nodes[crnt][1]);
    cout << (char)(crnt+'A');
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    string inputLine;
    char crnt, left,right;
    for(int i=0;i<N;i++){
        cin >> crnt >> left >> right;
        if(left!='.') nodes[crnt-'A'][0] = (left-'A');
        if(right!='.') nodes[crnt-'A'][1] = (right-'A');
    }
    preorder_traverse(0);
    cout << endl;
    inorder_traverse(0);
    cout << endl;
    postorder_traverse(0);
    cout << endl;
    return 0;
}