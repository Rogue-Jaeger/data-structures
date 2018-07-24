// https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/

// only be done by level order traversal and so queue will be used
// even if the return type is vector vector we'll use map (int , vector) and then input in vector inside vector


vector< vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    queue < pair< TreeNode * , int > > q;
    map <int , vector<int> > map;
    vector < vector <int> > v;
    //vector< int > vsmall;

    if(A){
        q.push( make_pair(A , 0) );
        map[0].push_back( A -> val );
    }
    else return v;

    while(!q.empty()){
        TreeNode * temp = q.front().first;
        int var = q.front().second;

        if(temp -> left){
            q.push( make_pair( temp -> left , var - 1 ) );
            map[var - 1].push_back(temp->left->val);
        }

        if(temp -> right){
            q.push( make_pair( temp -> right , var+1 ) );
            map[var + 1].push_back(temp->right->val);
        }

        q.pop();

    }



    int k = 0;
    for(auto i : map){
        v.push_back(i.second); // most impppppppppppppppppppppppppp how to input from map(int, vector) to vector inside a vector.
    }
    return v;

}
