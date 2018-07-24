// https://practice.geeksforgeeks.org/problems/sum-of-leaf-nodes/1/?ref=self

int sumLeaf(Node* root)
{
    if(root == NULL) return 0; // we have to write this condition no matter what
    if(root -> left == NULL && root -> right == NULL) return root->data; //characteristic of leaf node

    return sumLeaf(root -> left) + sumLeaf(root -> right);

}
