// https://practice.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1/?ref=self


// #include<bits/stdc++.h>
// using namespace std;
// struct Node
// {
// 	int data;
// 	struct Node *next;
// };
// void sort(Node **head);
// // A utility function to create a new node
// Node* newNode(int key)
// {
// 	Node *temp = new Node;
// 	temp->data = key;
// 	temp->next = NULL;
// 	return temp;
// }
// void append(struct Node** headRef, int newData)
// {
// 	struct Node* new_node = newNode(newData);
// 	struct Node *last = *headRef;
// 	if (*headRef == NULL)
// 	{
// 		*headRef = new_node;
// 		return;
// 	}
// 	while (last->next != NULL)last = last->next;
// 	last->next = new_node;
// }
// // A utility function to print a linked list
// void printList(Node *head)
// {
// 	while (head != NULL)
// 	{
// 		cout << head->data << " ";
// 		head = head->next;
// 	}
// 	cout << endl;
// }
// int main()
// {
// 	freopen("input.txt" , "r" , stdin);
// 	int test;
// 	cin>>test;
// 	while(test--)
// 	{
// 		struct Node* head = NULL;
// 		int n, k;
// 		cin>>n;
// 		for(int i=0; i<n ;i++){
// 			cin>>k;
// 			append(&head, k);
// 		}
// 		cout<<"head 1 "<<head<<endl;
// 		sort(&head);
// 		printList(head);
// 	}
// 	return 0;
// }


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Structure of Node of the linked list is as
struct Node
{
int data;
struct Node *next;
};
*/
// your task is to complete this function

Node * reverse( Node * head ){
	Node * prev = NULL ,* curr = head;
	while(curr){
		Node * next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	return prev;
}

void sort(Node **head)
{
	//cout<<"head 2 "<<*head<<endl;
	Node *maincurr = *head;
	Node *evenprev = NULL, *oddprev = NULL;
	Node *oddlist = NULL, *evenlist = NULL;
	int count = 0;

	while(maincurr){
		count++;
		if(count%2 == 0){
			if(evenprev == NULL){
				evenlist = maincurr;
				evenprev = evenlist;
				//evenprev -> next = NULL; //iiiiiiiiiiiiiiiiiiiiiiiiiiiiimmmmmmmmmmmmmmmmmmppppppppppppppp here maincurr will become NULL
			}
			else{
				evenprev -> next = maincurr;
				evenprev = evenprev -> next;
				//evenprev -> next = NULL; //iiiiiiiiiiiiiiiiiiiiiiiiiiiiimmmmmmmmmmmmmmmmmmppppppppppppppp here maincurr will become NULL
			}
		}
		else{
			if(oddprev == NULL){
				oddlist = maincurr;
				oddprev = maincurr;
				/*oddprev -> next = NULL;*/ //iiiiiiiiiiiiiiiiiiiiiiiiiiiiimmmmmmmmmmmmmmmmmmppppppppppppppp here maincurr will become NULL
			}
			else{
				oddprev -> next = maincurr;
				oddprev = oddprev -> next;
				//oddprev -> next = NULL; //iiiiiiiiiiiiiiiiiiiiiiiiiiiiimmmmmmmmmmmmmmmmmmppppppppppppppp here maincurr will become NULL
			}

		}
		maincurr = maincurr -> next;
	}


	oddprev -> next = NULL; evenprev -> next = NULL;

	// Node * cou = oddlist;
	// count = 0;
	// while(cou){
	// 	cout<<cou->data<<" poopsy"<<endl;
	// 	cou = cou -> next;
	// }

	evenlist = reverse(evenlist);


	// Node * cou = evenlist;
	// while(cou){
	// 	cout<<cou->data<<"k ";
	// 	cou = cou -> next;
	// }

	Node * oddptr = oddlist;
	Node * evenptr = evenlist;
	Node * mainptr = (oddptr -> data < evenptr -> data) ? oddptr : evenptr ;
	if(mainptr == evenptr){
		evenptr = evenptr -> next;
		maincurr  = mainptr;
	}
	else{
		oddptr = oddptr -> next;
		maincurr = mainptr;
	}
	for(int i = 1 ; i <= count && evenptr && oddptr ; i++){
		if(evenptr -> data < oddptr -> data){
			mainptr -> next = evenptr;
			mainptr = mainptr -> next; // imp to include this line the  main point is to keep
			evenptr = evenptr -> next;
		}
		else{
			mainptr -> next = oddptr;
			mainptr = mainptr -> next; // imp to include this line the  main point is to keep
			oddptr = oddptr -> next;
		}
	}
	if(evenptr){
		mainptr -> next = evenptr;
	}
	if(oddptr){
		mainptr -> next = oddptr;
	}

	// cou = maincurr;
	// while(cou){
	// 	cout<<cou->data<<"d ";
	// 	cou = cou -> next;
	// }

}
