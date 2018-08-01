// https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1


void connect(Node *root)
{
    if(!root) return;

    queue <Node * > q;
    q.push(root);
    q.push(NULL);
    Node * temp;

    while(true){
        if(q.front() == NULL && q.size() == 1) break;

        while(q.front()){
            temp = q.front();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            q.pop();
            temp->nextRight = q.front();
        }

        q.pop();
        q.push(NULL);

    }

    return;

}
