// https://practice.geeksforgeeks.org/problems/add-all-greater-values-to-every-node-in-a-bst/1

void solve(Node *root ,int & max){
    if( !root ) return;

    // if( !root->right && !root->left ){
    //     max = root->data + max;                    // this code is redundant here
    //     root->data = max;
    //     return;
    // }

    solve(root->right , max);
    max = max + root->data;
    root->data = max;
    solve(root->left , max);

    return;
}


void modify(Node **root){
    if(!*root) return;
    int max = 0;
    solve(*root , max);
}
