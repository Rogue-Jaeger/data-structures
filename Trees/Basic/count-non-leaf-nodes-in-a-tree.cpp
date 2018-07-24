// https://practice.geeksforgeeks.org/problems/count-non-leaf-nodes-in-tree/1

int countNonLeafNodes(Node* root)
{
    if(root == NULL) return 0;
    if(root -> left == NULL && root -> right == NULL /*write this combined*/) return 0;
    /* if(root -> right == NULL) return 0; imp dont write this separately cause will return even if the node has only left or right child*/

    return 1 + countNonLeafNodes(root -> left) + countNonLeafNodes(root -> right); // cause if it has no left root or right root it will return 1
}
