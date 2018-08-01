// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/?ref=self



void printright(Node * root){
    if(!root) return;
    if(!root->right && !root->left) return;

    if(root->right) printright(root->right); // left chal gaya to right nahi chalega
    else if(root->left) printright(root->left); // this type of code is made so that in the left vicinity all are printed even if it comes onto the roght

    cout << root->data << " ";
}

void printleaf(Node * root){
    if(!root) return;
    if(!root->left && !root->right){
        cout << root->data << " ";
        return;
    }
    printleaf(root->left);
    printleaf(root->right);
}

void printleft(Node * root){
    if(!root) return;
    if(!root->left && !root->right) return;

    cout<<root->data<<" ";
    if(root->left) printleft(root->left);
    else if(root->right) printleft(root->right);  // left chal gaya to right nahi chalega
}

void printBoundary(Node *root){
    if(!root) return;

    cout << root->data << " ";
    if(root->left) printleft(root->left); // this line was updated for case 1 2 R 2 4 R 4 5 R 5 6 R 6 7 R 7 8 L
    printleaf(root);
    if(root->right) printright(root->right);
}
