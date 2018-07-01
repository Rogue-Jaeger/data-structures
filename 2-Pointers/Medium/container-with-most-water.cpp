// https://leetcode.com/problems/container-with-most-water/description/

// values are only integers not fractions like 1.5
// 1 2 1 here 1 and 1 makes a container just assume 2 is not in between
// only 2 pointer approach gives O(n) answer

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;

        for(int i=0,j=height.size()-1 ; i<j ;){
            int area = min(height[i],height[j])*abs(i-j);
            if(height[i]>height[j]) j--;
            else i++;
            if(area > maxarea) maxarea = area;
        }

        return maxarea;
    }
};
