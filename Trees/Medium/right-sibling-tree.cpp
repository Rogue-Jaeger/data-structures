// https://practice.geeksforgeeks.org/problems/right-sibling-in-binary-tree/1

// implementing spcial type of level order traversal

Node* findRightSibling(Node* node)
{
    if(!node) return NULL;

    queue <Node * > q;

    Node * tofind = node;

    while(node -> parent != NULL) node = node -> parent; // getting to the root node of the tree cause the pointer here given was pointing to the number to be found

    q.push(node);
    q.push(NULL);

    while(!q.empty()){
        if(q.front() == NULL && q.size() == 1) break;
        if( !q.front() ){
            q.pop(); q.push(NULL); // imp step here we can find that there is a new level starting
        }


        Node * temp = q.front();
        q.pop();
        temp -> parent = q.front();

        if(temp -> left) q.push(temp -> left);
        if(temp -> right) q.push(temp -> right);
    }

    return tofind -> parent;

}
