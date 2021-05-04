#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,A;
    cin >> N;
    vector<int> tops(N,0);
    stack<pair<int,int>> s;
    for(int i=0;i<N;i++){
        cin  >> A;
        // cout << "in : " << A << endl;
        if(s.empty()){
            s.push({A,i});
            tops[i]=0;
            // cout << "s is empty ( " << i << ") : " <<  tops[i] << endl;
        }
        else{
            while(s.top().first < A && !s.empty()){
                // cout<<"smaller pop! -> " << s.top().first << "\n";
                s.pop();
                if(s.empty()) break;
            }
            if(s.empty()) tops[i]=0;
            else tops[i]=s.top().second+1;
            // cout << "finally top : " << tops[i] << endl;
            s.push({A,i});
        }
    }

    for(int i=0;i<N;i++) cout << tops[i] << " ";
    return 0;
}

// #include<iostream>
// #include<vector>
// using namespace std;

// int tops[500000][2];

// typedef struct tree{
//     int idx;
//     int data;
//     tree *left;
//     tree *right;
// }tree;

// void insertNode(tree *root, tree *node){
//     tree* tmp;
//     tmp = root;
//     cout << "root Data : " << root->data << "," << "node Data : " << node->data << endl;
//     while(tmp!=NULL){
//         if(tmp->data < node->data){
//             tmp = tmp->right;
//         }
//         else tmp = tmp->left;
//     }
//     tmp = node;
// }

// void preorder(tree *node){
//     if(node->right!=NULL){
//         tops[node->idx][1]=node->right->idx;
//         preorder(node->right);
//     }
//     if(node->left!=NULL) preorder(node->left);
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int N;
//     int input;
//     cin >> N;
//     tree *root;
//     for(int i=0;i<N;i++){
//         cin >> tops[i][0];
//         tops[i][1]=0;
//     }
//     cout << " 탑 값 받음 -------- \n";
//     for(int i=0;i<N;i++){
//         cout << "( " << tops[i][0] << " , " << tops[i][1] << ")\n"; 
//     }
    
//     for(int i=N-1;i>=0;i--){
//         tree *node = new tree();
//         node->idx = i;
//         node->data = tops[i][0];
//         node->left = NULL;
//         node->right = NULL;
//         cout << "insertNOde!\n";
//         insertNode(root,node);
//     }

//     preorder(root);

//     for(int i=0;i<N;i++){
//         cout <<tops[i][1] << " ";
//     }

//     return 0;
// }