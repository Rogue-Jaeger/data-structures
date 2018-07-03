#include<bits/stdc++.h>
using namespace std;


vector<vector<int> > threeSum(vector<int> &num) {

	vector<vector<int> > res;

	std::sort(num.begin(), num.end()); //we'll have to sort this array

	for (int i = 0; i < num.size(); i++) {

		int target = -num[i]; // we have to make sum of the rest 2 numbers equal to -ve of num 1

		int front = i + 1; // seeing from one greater than number 1
		int back = num.size() - 1;

		cout <<"pehla "<< target << " " << front << " "<< back <<endl;

		while (front < back) {

			int sum = num[front] + num[back];


			cout <<"doosra "<< target << " " << front << " "<< back <<endl;

			// Finding answer which start from number num[i]
			if (sum < target)
			front++;

			else if (sum > target)
			back--;

			else /*if sum == target*/ {
				vector<int> triplet(3, 0);
				triplet[0] = num[i];
				triplet[1] = num[front];
				triplet[2] = num[back];
				res.push_back(triplet); //see how vector got pushed

				cout<< "added "<<endl;

				// not considering duplicates of Number 2
				while (front < back && num[front] == triplet[1]) front++;

				// not considering duplicates of Number 3
				while (front < back && num[back] == triplet[2]) back--;


				cout <<"teesra "<< target << " " << front << " "<< back <<endl;
			}



		}

		// at this point all the numbers generated from number 1 will be tested so no need to check for its duplicates
		// Processing duplicates of Number 1
		while (i + 1 < num.size() && num[i + 1] == num[i])
		i++;

	}

	return res;

}


int main(){
	vector <int > v;

	v.push_back(-1);
	v.push_back(-2);
	v.push_back(-1);
	v.push_back(-1);
	v.push_back(-4);
	v.push_back(1);
	v.push_back(-5);
	v.push_back(-3);
	v.push_back(2);
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);
	v.push_back(0);
	v.push_back(2);

	vector <vector <int> > v1 = threeSum(v);

	cout << endl << endl;
	for(int i = 0; i<v1.size() ; i++){
		for(int j = 0 ; j<3 ; j++){
			cout<<v1[i][j]<<" ";
		}
		cout << endl;
	}

}
