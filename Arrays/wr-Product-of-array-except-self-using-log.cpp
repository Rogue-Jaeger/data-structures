// wrong cause log of <=0 doesnt exist

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

        double val = 0 , intermediateval = 0;

        for(int i = 0 ; i<size ; i++){
            val += log(nums[i]) / log(10); // see how log is written
            // cout<<log(nums[i]) / log(10)<<endl;
        }
        cout<<val<<endl;

        for(int i = 0 ; i<size ; i++){
            intermediateval = val - log(nums[i]) / log(10);
            nums[i] = pow( 10 , intermediateval ) + 0.1;  // imp.......to round off
        }

        return nums;

    }
};
