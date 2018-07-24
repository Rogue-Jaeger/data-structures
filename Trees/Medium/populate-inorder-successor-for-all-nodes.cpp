// https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

// just apply inverse inorder

void solve(node * root , node ** res){
    if(!root) return;

    solve(root->right , res);
    root -> next = *res;
    *res = root;

    solve(root->left , res);
    return;
}

void populateNext(node * root){
    node * nxt = NULL;
    solve(root , &nxt);
    return;
}
