// https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1

int maxDiffUtil(Node* root , int * maxdif){
    if(root == NULL) return INT_MAX;

    int minimum = min(maxDiffUtil(root -> left , maxdif/*ye pehle hi ek pointer hai so no &maxdif*/), maxDiffUtil(root -> right , maxdif) );

    *maxdif = max(*maxdif , root -> data - minimum);

    return min( minimum , root->data );
}
int maxDiff(Node * root){
    int maxdif = INT_MIN;
    maxDiffUtil(root , &maxdif);
    return maxdif;
}
