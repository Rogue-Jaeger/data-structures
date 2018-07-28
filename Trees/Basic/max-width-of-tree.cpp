// https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1/?ref=self


int getMaxWidth(Node* root)
{
    if(!root) return 0;

    queue <Node *> q;

    int globalmax = 1;
    int localmax;

    q.push(root);
    q.push(NULL);

    while(true){
        if( q.front() == NULL && q.size() == 1) break;
        if( q.front() == NULL ){
            q.pop();
            q.push(NULL);
            localmax = 0;
        }

        localmax++;
        if(localmax > globalmax) globalmax = localmax;

        if(q.front()->left) q.push( q.front() -> left );
        if(q.front()->right) q.push( q.front() -> right );

        q.pop();
    }

    return globalmax;
}
