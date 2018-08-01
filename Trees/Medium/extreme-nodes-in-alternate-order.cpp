// https://practice.geeksforgeeks.org/problems/extreme-nodes-in-alternate-order/1


void printExtremeNodes(Node* root)
{
    if(!root) return;

    Node * temp;
    queue <Node *> q;

    q.push(root);
    q.push(NULL);

    int val = 1;

    while(true){
        if(q.size() == 1 && q.front() == NULL) break;

        while(q.front() != NULL){
            temp = q.front();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            q.pop();
        }

        q.pop();
        q.push(NULL);

        if(val%2 == 1){
            cout << temp->data << " ";
            if( q.front() ) cout << q.front()->data << " ";
        }

        val++;
    }

}
