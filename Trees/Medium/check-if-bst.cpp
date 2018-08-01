// https://practice.geeksforgeeks.org/problems/check-for-bst/1

// there is an inorder traversal technique which otpimises it check it


void solve(Node * root , bool & val , int min , int max){
    if(!root) return;
    if(val == false) return;

    if( root->data >= max || root->data <= min){
        val = false;
        return;
    }

    solve(root->left , val , min , root->data);
    solve(root->right , val , root->data , max);

    return;
}


bool isBST(Node* root) {
    bool val = true;
    solve(root , val , INT_MIN , INT_MAX);
    return val;
}
