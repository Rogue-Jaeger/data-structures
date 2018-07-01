// https://leetcode.com/problems/unique-paths-ii/description/


int finder( auto v, int currrow , int currcol , int rows , int cols, int count = 0){
    int nextrow[] = {1,0};
    int nextcol[] = {0,1};

    if(currrow == rows || currcol == cols) return 0;

    //cout<<"pehla   "<<currrow<<" "<<currcol<<"    "<<count<<endl;

    if(v[0][0] == 1) return 0;

    if(currrow == rows-1 && currcol == cols-1 && v[rows-1][cols-1]!=1/*|| currrow == rows-1 && currcol == cols*/){
        count++;
        //cout<<"oopsy "<<count<<endl;
        return count;
    }
    //cout<<"doosra   "<<currrow<<" "<<currcol<<"    "<<count<<endl;

    for(int i = 0; i<2 ; i++){
        if(currrow+nextrow[i] < rows && currcol+nextcol[i] < cols && v[currrow+nextrow[i]][currcol+nextcol[i]] == 0){
            //v[currrow+nextrow[i]][currcol+nextcol[i]] = 1;
            count += finder(v, currrow+nextrow[i], currcol+nextcol[i], rows, cols);
        }
        //else return count;
    }

    return count;
}
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        int count = finder(obstacleGrid, 0 , 0 , rows , cols);

        return count;

    }
};
