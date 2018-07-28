// https://practice.geeksforgeeks.org/problems/k-sum-paths/1

// please try to do in spare time

void solve(Node * root , int k , vector <int > & v , int &res){
    if(!root) return;

    v.push_back(root->data);

    solve(root->left , k , v , res);
    solve(root->right , k , v , res);

    int val = 0;
    for(int j = v.size() - 1 ; j >= 0 ; j--){
        val += v[j];
        if( val == k ) res++;
    }
    v.pop_back();

    return;
}



int printCount(Node *root,int k)
{
    if(root == NULL) return 0;

    vector <int> v;
    int res = 0;

    solve(root , k , v , res);

    return res;
}
