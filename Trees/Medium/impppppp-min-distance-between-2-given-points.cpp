// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1


int find(Node * root , int a , int b , bool &reached){
    if(root==NULL) return -1;

    int left = find(root->left , a , b , reached);
    int right = find(root->right , a , b , reached);

    //cout << root->data << "left " << left << " right " << right << "reached " << reached <<endl;

    if(root->data == a || root->data == b ){ // case if a & b lie in the same path
        if(left != -1 || right != -1){
            reached = true;
            return max( left , right );
        }
        else return 1;
    }
    if( left != -1 && right != -1 ){
        reached = true; // this test case fails it so we had to include this 0 1 L 0 2 R  1 3 L 1 4 R  2 5 L 2 6 R  3 7 L 3 8 R  4 9 L 4 10 R  5 11 L 5 12 R  6 13 L 6 14 R  7 15 L 7 16 R  8 17 L 8 18 R  9 19 L 9 20 R  10 21 L 10 22 R  11 23 L 11 24 R  12 25 L 12 26 R  13 27 L 13 28 R  14 29 L 14 30 R
        return left+right;
    }
    if( left != -1 && !reached) return left + 1;
    if( left != -1 ) return left;
    if( right != -1 && !reached) return right + 1;
    if( right != -1 ) return right;

    return -1;
}


int findDist(Node* root, int a, int b){
    if(!root) return 1;
    if( a == b ) return 0;

    bool reached = false;
    int res = find(root , a , b , reached);

    if( res == -1 ) return 0;
    else return res;

}
