// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1/?ref=self

Node* LCA(Node *root, int n1, int n2){
    if(!root) return NULL;

    Node * left = LCA(root->left , n1 , n2);
    Node * right = LCA(root->right , n1 , n2);

    if( root->data == n1 || root->data == n2 ) return root;
    if( left && right ) return root;
    if( left ) return left;
    if( right ) return right;

    return NULL;
}
