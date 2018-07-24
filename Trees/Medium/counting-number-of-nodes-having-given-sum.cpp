// https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1


int countSubtreesWithSum(Node* root, int x, int * count)
{
	if (!root) return 0;

	int left = countSubtreesWithSum( root->left , x , count);
	int right = countSubtreesWithSum( root->right , x , count);

	if( (left + right + root -> data) == x) *count = *count + 1; // never do here *count++ it will yeild an garbage value

	//cout<<*count<<endl;
	//cout<<left + right + root -> data<<endl;
	return (left + right + root -> data);

}

int countSubtreesWithSumX(Node * root, int x){
    int count = 0;
    countSubtreesWithSum(root , x , &count); // most impppppppppppppppppppppppppppppppppppppppp yes the value of count changes here and gets returned
    return count;
}
