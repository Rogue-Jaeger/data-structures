#include<bits/stdc++.h>
using namespace std;


int main(){

	//Declaring the map data structure
	map<pair<int, int>, int> map_name;

	// To create one entry in the map
	map_name.insert(make_pair(make_pair(1,2), 5343));
	map_name.insert(make_pair(make_pair(2,2), 25));
	map_name.insert(make_pair(make_pair(1,2), 35));
	map_name.insert(make_pair(make_pair(4,2), 56));
	// To iterate the map create an iterator object first like this and then apply a for loop like this
	cout<<map_name[{1,2}]<<endl;

	map<pair<int, int>, int> :: iterator iterator_name;
	for(iterator_name = map_name.begin(); iterator_name != map_name.end(); iterator_name++)
	{
		//Do whatever you want. To access the first part of pair(pair is the key of the map here) you should write

		cout<<(iterator_name->first).first<<" ";

		// To access second part of pair
		cout<<(iterator_name->first).second<<" ";

		// To access the second part(value part) of the map simply use
		cout<<iterator_name->second<<endl;

	}

	// To find if a key exists simply use find method like this. It returns a pointer to the end of the map if the key doesn't exist

	//if(map_name.find(key) == map_name.end())

	// If the above if is true then make a new entry with that key as the key doesn't exist in the map

}
