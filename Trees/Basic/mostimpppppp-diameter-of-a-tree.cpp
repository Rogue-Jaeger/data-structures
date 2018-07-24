// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1/?ref=self


// BY ME (IF DECLARING GLOBAL VARIABLE )
int maxval = 0;

int ret(Node * root){
    if(root == NULL) return 0;

    int left = ret(root -> left);
    int right = ret(root -> right);

    if( left + right + 1 > maxval ) maxval = left + right + 1;

    return max( left , right ) + 1;
}


int diameter(Node* node)
{
    maxval = 0;
    return ret(node) > maxval ? ret(node) : maxval;
}



// BY SOMEBODY(IF NOT DECLARING GLOBAL VARIABLE)


int find(Node *root,int &h)
{
        if(root==NULL)return 0;
        int lh=find(root->left,h);
        int rh=find(root->right,h);
        h=max(h,lh+rh+1);
        return max(lh,rh)+1;
}
int diameter(Node *root)
{
        int h=-1;
        find(root,h);
        return h;
}
