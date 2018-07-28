// https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

// most optimised approach it will result in O(1) here if right gets selected left will not get selected so it will search in only one path
void solve(Node * root , int k ,  int &res){
    if(!root ) return;

    if(root -> data < k){
        if( abs( res - k ) > abs( root->data - k ) ) res = root->data;
        solve(root -> right , k , res);
    }
    else{
        if( abs( res - k ) > abs( root->data - k ) ) res = root->data;
        solve(root -> left , k , res);
    }

    return;
}

int maxDiff(Node *root, int k)
{
    int res = INT_MAX;
    solve(root , k , res);
    return res;
}
