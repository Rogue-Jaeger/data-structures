#include<bits/stdc++.h>
using namespace std;




int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mindiff = 123456;
        int minvalue = 0;

        for(int i = 0 ; i<nums.size(); i++){
                int front = i+1;
                int back = nums.size()-1;
                int currtarget = target-nums[i];

                while(front < back){
                        if(nums[front]+nums[back] < currtarget){
                                if( abs( currtarget - nums[front] - nums[back]) < mindiff){
                                        mindiff = abs( currtarget - nums[front] - nums[back]);
                                        minvalue = nums[i] + nums[front] + nums[back];
                                }
                                front++;
                        }
                        else if(nums[front]+nums[back] > currtarget){
                                if( abs( currtarget - nums[front] - nums[back]) < mindiff){
                                        mindiff = abs( currtarget - nums[front] - nums[back]); //not depending upon how you write in abs it can be nums-currtarget or currtarget - nums
                                        minvalue = nums[i] + nums[front] + nums[back];
                                }
                                back--;
                        }
                        else{
                                return target;
                        }
                }

                while ( i<nums.size() && nums[i] == nums[i+1]) i++;

        }

        return minvalue;
}





// same function but having lots of cout
//
// int threeSumClosest(vector<int>& nums, int target) {
//
//         sort(nums.begin(), nums.end());
//         int min = 1234567;
//         int mindiffcreated = 0;
//
//         for(int i = 0; i<nums.size(); i++){
//                 int toget = - nums[i] + target;
//                 cout << nums[i] << " " << target << " " << toget <<endl;
//                 int front = i+1;
//                 int back = nums.size()-1;
//
//                 while(front < back){
//                         cout << " front " << front << " back " << back <<endl;
//                         if(nums[front]+nums[back] < toget){
//                                 cout << "               < toget "  <<  toget << " " << nums[front]+nums[back] <<endl;
//                                 if( abs(abs(toget)-abs(nums[front]+nums[back])) < abs(min) ){
//                                         mindiffcreated = nums[front] + nums[back] + nums[i];
//                                         min = abs(abs(toget)-abs(nums[front]+nums[back]));
//                                         cout << "pair is 1 " <<nums[i] << " " << nums[front] <<" "<< nums[back] << " "<<endl;
//                                 }
//                                 front++;
//                                 cout<<"             min prehla "<<min<<endl;
//                         }
//                         else if(nums[front]+nums[back] > toget){
//                                 cout << "                > toget " << toget << " " << nums[front]+nums[back] <<endl;
//                                 if( abs(abs(toget)-abs(nums[front]+nums[back])) < abs(min) ){
//                                         mindiffcreated = nums[front] + nums[back] + nums[i];
//                                         min = abs(abs(toget)-abs(nums[front]+nums[back]));
//
//                                         cout << "pair is 2 " <<nums[i] << " " << nums[front] <<" "<< nums[back] << " "<<endl;
//                                 }
//                                 back--;
//                                 cout<<"             min doosra  "<<min<<endl;
//                         }
//                         else{
//
//                                 cout << "pair is 3 " <<nums[i] << " " << nums[front] <<" "<< nums[back] << " "<<endl;
//                                 return target;
//                         }
//
//                         //while(front < back && nums[front] == nums[front+1] ) front ++;
//                         //while(back > front && nums[back] == nums[back-1] ) back--;
//
//                 }
//                 if(i < nums.size() &&  nums[i] == nums[i+1]) i++;
//         }
//
//         return mindiffcreated;
//
// }


int main(){
        vector <int > v;

        v.push_back(1);
        v.push_back(1);
        v.push_back(-1);
        v.push_back(-1);
        v.push_back(3);
        // v.push_back(1);
        // v.push_back(-5);
        // v.push_back(-3);
        // v.push_back(2);
        // v.push_back(0);
        // v.push_back(1);
        // v.push_back(1);
        // v.push_back(0);
        // v.push_back(2);

        int y = threeSumClosest(v , -1);
        cout<<y<<endl;

        // cout << endl << endl;
        // for(int i = 0; i<v1.size() ; i++){
        // 	for(int j = 0 ; j<3 ; j++){
        // 		cout<<v1[i][j]<<" ";
        // 	}
        // 	cout << endl;
        // }

}
