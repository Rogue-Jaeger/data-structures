// https://leetcode.com/problems/product-of-array-except-self/description/

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();


class Solution {
public:
    /*see the return type first*/vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> v(nums.size());
        int size = nums.size();

        if(size == 1){
            v.clear();
            v.push_back(1);
            return v;
        }

        v[nums.size()-1] = 1;

        //calculating decreasing product

        for(int i = size-2 ; i>=0 ; i--){
            v[i] = nums[i+1] * v[i+1];
        }


        //calculating result with increasing sum

        int num = 1;
        for(int i = 0 ; i<size ; i++){
            if(i == 0) continue;
            num = num * nums[i-1];
            v[i] = v[i] * num;
        }

        return v;

    }
};




//                       A better inmplementation of same code


// static int x=[](){
//     std::ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     return 0;
// }();
//
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//
//         vector<int> result(nums.size(), 1);
//
//         int product = 1;
//         for (int i = 1; i < result.size(); ++i)
//         {
//             product *= nums[i - 1];
//             result[i] = product;
//         }
//
//         product = 1;
//         for (int i = result.size() - 2; i >= 0; --i)
//         {
//             product *= nums[i + 1];
//             result[i] *= product;
//         }
//
//         return result;
//     }
// };
