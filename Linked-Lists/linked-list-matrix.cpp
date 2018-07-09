// https://practice.geeksforgeeks.org/problems/linked-list-matrix/1


// firstly making all the rows with down joining only the first elements of each row
// then joining all the down ones by another for loop


Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
	Node *head = NULL, *headers = NULL , *clomers = NULL;

	for(int i = 0 ; i < n ; i++){ // joining only the nodes of the rows and the first element of each node with first element of another node

		Node *newnode = new Node();
		newnode->data = mat[i][0];
		newnode->right = NULL;
		newnode->down = NULL;

		Node *ptr = newnode;
		if( i > 0 ){
			headers->down = newnode;
			headers = newnode;
		}
		if(i == 0){
			head = newnode;
			headers = head;
		}

		for(int j = 1 ; j < n ; j++){

			Node * newcolnode = new Node();
			newcolnode -> data = mat[i][j];
			newcolnode -> right = NULL;
			newcolnode -> down = NULL;

			//cout<<"oopsy 4"<<endl;
			ptr -> right = newcolnode;
			ptr = newcolnode;

		}
	}

	headers = head;

	Node * ptr1 , *ptr2;

	for(int i = 0 ; i < n-1 ; i++){ // joining all the down ones with respective nodes
		ptr1 = headers;
		ptr2 = headers->down;
		for(int j = 0 ; j<n ; j++){
			ptr1 -> down = ptr2;
			ptr1 = ptr1 -> right;
			ptr2 = ptr2 -> right;
		}
		headers = headers -> down;
	}
	return head;
}
