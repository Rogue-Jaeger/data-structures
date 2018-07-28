// https://practice.geeksforgeeks.org/problems/foldable-binary-tree/1


//     code written by me a point to remember here is if we return something within && then if at any point the value becomes false then the whole value becomes false


// void isfoldableutil(node * l , node * r , bool & foldable){
//     if( l == NULL && r == NULL ) return;
//     if( l == NULL || r == NULL ){
//         foldable = 0;
//         return;
//     }

//     isfoldableutil(l->left , r->right , foldable);
//     isfoldableutil(l->right , r->left , foldable);
//     return;
// }

// bool isFoldable(struct node *root)
// {
//     bool foldable = 1;
//     if(root == NULL) return 1;
//     isfoldableutil(root->left , root->right , foldable);
//     return foldable;
// }


//           a better approach by not using foldable

bool isfoldableutil(node * l , node * r ){
    if( l == NULL && r == NULL ) return 1;
    if( l == NULL || r == NULL ) return 0;

    return isfoldableutil(l->left , r->right) && isfoldableutil(l->right , r->left);

}

bool isFoldable(struct node *root)
{
    if(root == NULL) return 1;
    return isfoldableutil(root->left , root->right);
}
