// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

int isit(Node * root){

    if(root == NULL) return 0;

    int lh = isit(root -> left); // see how lh and rh are declared not above as lh = 0
    int rh = isit(root -> right);

    if( abs(lh-rh) > 1 ) return -1;
    if( lh == -1 && rh == -1 ) return -1;

    return max(lh , rh) + 1;

}
bool isBalanced(Node *root)
{
    if( isit(root) == -1 ) return false;
    else return true;
}
