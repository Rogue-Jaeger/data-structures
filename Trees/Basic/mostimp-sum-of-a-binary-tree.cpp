// https://practice.geeksforgeeks.org/problems/sum-of-binary-tree/1

long int sumBT(Node* root)
{
    if(root == NULL) return 0;
    //else return root->key; // dont write this
    if(!root->left && !root->right) return root->key;

    return root->key + sumBT(root -> left) + sumBT(root -> right); // here root key is the main part as it fetches the data of all the nodes
}
