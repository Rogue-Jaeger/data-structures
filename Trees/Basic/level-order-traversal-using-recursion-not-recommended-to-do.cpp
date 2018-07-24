// https://practice.geeksforgeeks.org/problems/level-order-traversal/1/?ref=self

queue <Node *> q;

void print(queue <Node *> q){
    if(q.empty()) return;

    Node * temp = q.front();
    cout << temp->data << " ";
    if(temp -> left) q.push(temp -> left);
    if(temp -> right) q.push(temp -> right);

    //cout<<"[ "<< q.front()->data <<endl;

    q.pop();
    return print(q);

}

void levelOrder(Node* node)
{
    // q.clear(); // there is no method named q.clear()
    if(node) q.push(node);
    else return;
    print(q);

    while (!q.empty()) // will have to do this cause at this point q will have root of the tree
    {
        q.pop();
    }

    return;
}
