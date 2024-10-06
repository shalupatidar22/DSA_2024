#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>>& grid, int i, int j){
        //base case
         int n,m;
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0'){
            return;
        }


        grid[i][j]='0';
        solve(grid,i-1,j-1);//left upper diagonal
        solve(grid,i-1,j+1);//right upper diagonal
        solve(grid,i+1,j-1);//left lower diagonal
        solve(grid,i+1,j+1);//right lower diagonal
        solve(grid,i,j-1);//left
        solve(grid,i,j+1);//right
        solve(grid,i-1,j);//up
        solve(grid,i+1,j);//down
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
         int n,m;
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    solve(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
int main(){
    
     vector<vector<char>> grid = {
        {'0', '1'},
        {'1', '0'},
        {'1', '1'},
        {'1', '0'}
    };

    // Call the function and print the result
    int result = numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}