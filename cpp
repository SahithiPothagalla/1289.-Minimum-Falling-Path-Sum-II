class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX,secondmin=INT_MAX,minindex=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]<mini){
                    secondmin=mini;
                    mini=grid[i][j];
                    minindex=j;
                }
                else if(grid[i][j]<secondmin) secondmin=grid[i][j];
            }
            if(i==0) break;
            for(int j=0;j<n;j++){
                if(j!=minindex){
                    grid[i-1][j]+=mini;
                }
                else grid[i-1][j]+=secondmin;
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,grid[0][i]);
        }
        return mini;
    }
};
