// https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

// please try to do in spare time

// please see how to integrate vector in map

// the question here was if there is a tree existing even with one child node then all the child nodes must be same


bool solve(Node * root , map<int , vector <Node *> > &m){
    if(!root) return false;

    if( m.find(root->data) ==  m.end() ) m[root->data].push_back(root);
    else{
        for(int i = 0 ; i < m[root->data].size() ; i++){

            if( !m[root->data][i]->left && root->left || m[root->data][i]->left && !root->left ) continue;
            if( !m[root->data][i]->right && root->right || m[root->data][i]->right && !root->left ) continue;

            int count = 0 , val = 0;

            if(root->left){ if( m[root->data][i]->left->data == root->left->data ) count++; }
            else{ count++; val++; }
            if(root->right){ if( m[root->data][i]->right->data == root->right->data ) count++; }
            else{ count++; val++; }

            //cout<<count<<" "<<val<<endl;
            if( count==2 && val!=2 ) return true;

        }
    }

    return solve(root->left , m) || solve(root->right , m);

}

bool dupSub(Node *root)
{
    if(!root) return false;
    map <int , vector<Node *> > m;
    return solve(root , m);
}
