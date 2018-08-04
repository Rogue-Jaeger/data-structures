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

        int bottomup[size] , topdown[size];

        int val = 1;
        for(int i = 0 ; i < size ; i++ ){
            val *= nums[i];
            bottomup[i] = val;
        }

        val = 1;
        for(int i = size-1 ; i > -1 ; i-- ){
            val *= nums[i];
            topdown[i] = val;
        }

        vector <int> res(size , 1);

        for(int i = 0 ; i < size ; i++){
            if( i-1 > -1 ) res[i] *= bottomup[i-1];
            if( i+1 < size ) res[i] *= topdown[i+1];
        }

        return res;
    }
};
