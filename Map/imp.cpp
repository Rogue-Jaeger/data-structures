// insert doesnt input the value if the same key comes again

#include<bits/stdc++.h>
using namespace std;


int main(){
	map <int ,int > map;

	map.insert(make_pair(1,2));

		map.insert(make_pair(2,12));

			map.insert(make_pair(1,2));

				map.insert(make_pair(11,2));

					map.insert(make_pair(1,5));

						map.insert(make_pair(1,7));

							map.insert(make_pair(1,8));

								map.insert(make_pair(1,9));

									map.insert(make_pair(1,10));


	for( auto i : map){
		cout<<i.first<<" "<<i.second<<endl;
	}

}
