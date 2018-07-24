// https://practice.geeksforgeeks.org/problems/level-order-traversal/1/?ref=self

void levelOrder(Node* node)
{
    // q.clear(); // there is no method named q.clear()

    queue <Node *> q;

    if(node) q.push(node);
    else return;


    while(!q.empty()){
        Node * temp = q.front();
        cout << temp->data << " ";
        if(temp -> left) q.push(temp -> left);
        if(temp -> right) q.push(temp -> right);
        q.pop();
    }

    return;
}
