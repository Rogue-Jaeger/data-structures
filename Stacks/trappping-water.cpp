// https://leetcode.com/problems/trapping-rain-water/description/

// solution complexity is n*2 or O(n) not n*n

class Solution {
public:
    int trap(vector<int>& height) {
        stack <int> s;

        //s.push(height[0]); //stack ko initialise karne ki koi Zaroorat nahi hai cause if input is given null as [] it will fail
        //int current = 1;

        int totalarea = 0, current = 0;

        while(current < height.size()){
            while( !s.empty() && height[s.top()] < height[current]){
                // int top = s.pop(); this is wrong as pop returns nothing
                int top = s.top();
                s.pop();
                if(s.empty()) break;
                totalarea += abs( height[top] - min(height[current],height[s.top()]) ) * abs(current - s.top() - 1);
            }
            s.push(current++);
        }

        return totalarea;
    }
};
