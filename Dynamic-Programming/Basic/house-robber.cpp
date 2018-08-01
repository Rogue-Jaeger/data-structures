// https://leetcode.com/problems/house-robber/description/


class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0 , b = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            if(i%2 == 0){
                a = max(b , nums[i] + a);    // agar yahan max use ho raha hai to vo peechle ke peechle ka use ho raha
                                             // agar a mein b ki value aayegi to jab agla b aayega to vo peechle b ki hi value hogi
                cout << "a " << a << endl;
            }
            else{
                b = max(a , nums[i] + b);
                cout << "b " << b << endl;
            }
        }

        return max( a , b );
    }
};
