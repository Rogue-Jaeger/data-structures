// https://www.geeksforgeeks.org/modify-contents-linked-list/


// #include <bits/stdc++.h>
// using namespace std;
//
// struct Node
// {
//         int data;
//         struct Node* next;
// };
//
// struct Node* modifyTheList(struct Node *head);
//
// void push(struct Node **head_ref, int new_data)
// {
//         struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
//         new_node->data = new_data;
//         new_node->next = *head_ref;
//         *head_ref = new_node;
// }
// void printList(struct Node *head)
// {
//         if (!head)
//         return;
//         while (head->next != NULL)
//         {
//                 //cout << head->data << " ";
//                 head = head->next;
//         }
//         //cout << head->data << endl;
// }
// int main()
// {
//         freopen("input.txt" , "r" , stdin);
//         int t;
//         cin>>t;
//         while(t--){
//                 int n;
//                 cin>>n;
//                 struct Node *head = NULL;
//                 while(n--){
//                         int a;
//                         cin>>a;
//                         push(&head, a);
//                 }
//                 head = modifyTheList(head);
//                 printList(head);
//         }
//         return 0;
// }


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows:
struct Node
{
int data;
struct Node* next;
};
*/
Node* reverse(Node * head){
        Node *curr = head, *prev = NULL;
        while(curr){
                Node * next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
        }
        head = prev;
        return head;
}


struct Node* modifyTheList(struct Node *head)
{
        Node * cou = head;
        int count = 0;
        while(cou){
                count++;
                cou = cou -> next;
        }

        count = count / 2;

        cou = head;
        while(--count){
                cou = cou -> next;
        }

        Node *list2 = cou -> next;
        cou -> next = NULL;

        Node * head2 = reverse(list2);

        // cou = head2;
        // while(cou){
        //         cout<< cou->data << "k " ;
        //         cou = cou -> next;
        // }


        // cou = head;cout<<"head "<<endl;
        // while(cou){
        //         cout<< cou->data << "k " ;
        //         cou = cou -> next;
        // }



        Node *a = head, *b = head2;

        while(a){
                a -> data = a->data - b->data;
                a = a->next;
                b = b->next;
        }



        // cou = head;
        // while(cou){
        //         cout<< cou->data << "k " ;
        //         cou = cou -> next;
        // }

        Node *finalmidhead = reverse(head2);
        Node *finalhead = head;

        // cou = finalhead;cout<<" final "<<endl;
        // while(cou){
        //         cout<< cou->data << "k " ;
        //         cou = cou -> next;
        // }



        while(finalhead -> next != NULL){ //iiiiiiiiiiiiiiiiiiiiiiiiiiiiimmmmmmmmmmmmmmmmmmppppppppppppppp hereit should be finalhead -> next =  null instead of finalhead = NULL
                finalhead = finalhead -> next;
        }
        finalhead -> next = finalmidhead;

        // cou = head;cout<<" final "<<endl;
        // while(cou){
        //         cout<< cou->data << "k " ;
        //         cou = cou -> next;
        // }


        return head;
}
