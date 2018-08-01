// https://practice.geeksforgeeks.org/problems/check-if-subtree/1

// solve it and try to optimize it

bool check(Node * a , Node * b){
    if(!a && !b) return true;
    if(!a) return false;
    if(!b) return false;
    if(a->key != b->key) return false;

    return check(a->left , b->left) && check(a->right , b->right);
}

void solve(Node * a , Node * b , bool &val){
    if( !a ) return;
    if(val == true) return;


    bool ch = false;
    if(a->key == b->key) ch = check(a , b);
    if(ch == true) val = true;

    solve(a->left , b , val);
    solve(a->right , b , val);

    return;
}

bool isSubtree(Node*  T1 ,Node * T2){
    bool val = false;
    solve(T1 , T2 , val);
    return val;
}
