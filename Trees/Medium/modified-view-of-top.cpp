// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// 1 2 L 1 3 R 2 4 R 4 5 R 5 6 R  this was an important case


void solve(Node * root ,int val , int pos, map <int , pair<int , int > > & ma){
    if(!root) return;
    if( ma.find(pos) == ma.end() || ma.find(pos) != ma.end() && val < ma[pos].first){ // imp these 2 things cancel out we onlt have to write ma.find(pos) == ma.end()
        ma[pos] = make_pair(val , root->data);
        //cout<<val<<" "<<root->data<<endl;
    }
    solve(root -> left , val+1 ,  pos-1 , ma);
    solve(root -> right , val+1 , pos+1 , ma);
    return;
}


// the return type is bool
bool compare( pair<int , int> &i , pair<int , int> &j){ // we included this cause sort was sorting for even second element when the first one was same in pair
    return i.first < j.first;
}

void topView(struct Node *root){
    map <int , pair<int , int > > ma;
    vector < pair <int , int> > v;
    solve(root, 1 , 0 , ma);
    for(auto i : ma){
        v.push_back( make_pair(i.second.first , i.second.second) ) ;
    }
    sort( v.begin() , v.end() , compare);
    for(auto i : v) cout<<i.second<<" ";
}
