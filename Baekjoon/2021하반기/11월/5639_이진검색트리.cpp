#include<iostream>
#include<vector>

#define endl '\n'
typedef long long ll;

using namespace std;
vector<vector<int>> nodes(1000005, vector<int> (2,-1)); //parent, left, right
void createTree(int crnt, int target){
    if(crnt>target){
        if(nodes[crnt][0]==-1) nodes[crnt][0] = target;
        else createTree(nodes[crnt][0],target);
    }
    else if(crnt<target){
        if(nodes[crnt][1]==-1) nodes[crnt][1] = target;
        else createTree(nodes[crnt][1],target);
    }
}

void printPostorder(int crnt){ // left->right=>root
    if(nodes[crnt][0]!=-1) printPostorder(nodes[crnt][0]);
    if(nodes[crnt][1]!=-1) printPostorder(nodes[crnt][1]);
    cout << crnt << endl;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int root = 0;
    while(cin >> n){
        if(root==0) root = n;
        else createTree(root,n);
    }

    if(root!=0) printPostorder(root);
    return 0;
}