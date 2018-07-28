// https://practice.geeksforgeeks.org/problems/largest-bst/1

// imp test case       20 10 L 10 5 L 5 1 L 1 50 R


// vector<int> v has the following members
// v[0]: maximum size of bst in a subtree
// v[1]: whether that subtree is bst or not(val=1 or 0)
// v[2]: maximum value in the left subtree
// v[3]: minimum value in the right subtree
vector<int> lb(Node *root)
{
        if(!root)
        return {0,1,INT_MIN,INT_MAX};
        // a null node is bst with minimum value in the tree INT_MIN and
        //maximum value in the tree INT_MAX. size=0

        int d=root->data;

        if(!root->left && !root->right)
        return {1,1,d,d};// A leaf node is a bst with size=1 and max and min
        // in the tree being the leaf nodes data itself.

        auto v1=lb(root->left); // v1:vector for the left subtree
        auto v2=lb(root->right);// v2:vector for the right subtree

        int mbs=max(v1[0],v2[0]),maxv=max(v1[2],v2[2]),minv=min(v1[3],v2[3]);
        // mbs-maximum bst size in either left or right subtree,
        // maxv-maxvalue in the subtree with root as root
        // minv-minimum value in the subtree with root as root

        cout << root->data << " max val in left " << maxv  << " min val in roght" << minv << endl;
        if(!v1[1] || !v2[1])//if any of the left and right subtree is not a bst

        return {mbs,0,maxv,minv};
        //rest of the subtrees above this subtree would also not be a bst.
        //Hence vector[1]=0  -----Step X

        if(d>v1[2] && d<v2[3])
        // if current subtree root's data d satisfies the condition for a bst

        return {v1[0]+v2[0]+1,1,v2[2],v1[3]};
        //^return size of the whole subtree with maxvalue as max in the right
        //subtree and minvalue as min in the left subtree

        return {mbs,0,maxv,minv};//else return same as before at step X
}
int largestBst(Node *root)
{
        //Your code here
        auto v=lb(root);
        return v[0];
}





// MY CODE BASED ON THE SAME PRINCIPLES PLEASE READ THIS        .......

//v[2] = max val form left
//v[3] = min val from right
vector<int> solve(Node * root){
    if(!root) return { 0, 1, INT_MIN, INT_MAX};
    int temp = root->data;
    if(!root->left && !root->right) return { 1 , 1 , temp , temp };

    auto v1 = solve(root->left);
    auto v2 = solve(root->right);

    int maxres = max(v1[0] , v2[0]) , maxl = max(v2[2] , v1[2]) , minr = min(v1[3] , v2[3]);

    if(!v1[1] || !v2[1]) return { maxres , 0 , 0 , 0 }; // 0 0 CAUSE WE DONT CARE

    if(temp>v1[2] && temp<v2[3]) return { v1[0] + v2[0] + 1 , 1 , maxl , minr };

    return { maxres , 0 , 0 , 0 }; // 0 0 CAUSE WE DONT CARE
}

int largestBst(Node *root){
    vector <int> v = solve(root);
    return v[0];
}
