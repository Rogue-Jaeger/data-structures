// https://practice.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1


// most imp thing to get sorted output i included vector and as the main function was supposed to be recursive i had to make a secondary function so as to make it recursive

vector <int> v; //avoid declaring global variables

/*vector<int>*/ void printSiblingme(Node* root /*, vector<int> v*/)
{
    if(root == NULL) return ;
    // if(root -> right == NULL && root -> left == NULL) return; no need to include this line here
    if(root -> left && root -> right == NULL) v.push_back(root -> left -> data);
    if(root -> right && root -> left == NULL) v.push_back(root -> right -> data);

    printSiblingme(root -> left );
    printSiblingme(root -> right );

    return ; // a statement written after it will never run
}

void printSibling(Node* root){

    v.clear(); // imp to write this if declared globally


    //vector <int> v;
    printSiblingme(root );
    sort( v.begin() , v.end() );

    if(v.size() == 0) cout<<-1; // dont write endl here this will give no output

    for(int i = 0 ; i < v.size() ; i++) cout<< v[i] << " ";

    return;
}
