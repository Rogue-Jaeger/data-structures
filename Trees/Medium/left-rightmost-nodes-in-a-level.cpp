// https://practice.geeksforgeeks.org/problems/leftmost-and-rightmost-nodes-of-binary-tree/1

void printCorner(Node *root)
{
    if(root == NULL) return;
    queue < Node * > q;

    vector < Node * > v;

    q.push(root);
    q.push(NULL);
    v.push_back(root);

    while(!q.empty()){
        if(q.front() == NULL && q.size() == 1) break;

        if(q.front() == NULL){
            q.pop();
            q.push(NULL);
            if( q.front() ) v.push_back(q.front());
        }
        else{
            Node * temp;
            while( q.front() != NULL ){
                temp = q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                q.pop();
            }
            if( v[v.size()-1] != temp ) v.push_back(temp);
        }
    }

    for(auto i : v) cout << i->key << " ";

}
