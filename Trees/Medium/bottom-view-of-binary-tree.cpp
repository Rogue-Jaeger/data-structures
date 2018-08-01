// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// a good test case    0 1 L 0 2 R  1 3 L 1 4 R  2 5 L 2 6 R

void solve(Node * root , map <int , pair<int , int > > & m , int h , int v){
    if(!root) return;

    if( m.find(h) == m.end() ){
        m[h] = make_pair( v , root->data );
    }
    else{
        if( m[h].first <= v ) m[h] = make_pair( v , root->data );
    }

    solve(root->left , m , h-1 , v+1);
    solve(root->right , m , h+1 , v+1);

    return;
}


void bottomView(Node *root)
{
    map<int , pair <int , int > > m;
    solve(root , m , 0 , 0);
    for(auto i : m) cout << i.second.second << " ";
}
