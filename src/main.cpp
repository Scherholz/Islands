#include <iostream>
#include <vector>
#include <array>

using namespace std;

template<typename T>
void print_islands(T grid){

    try{
        for(auto& y : grid){
            for(auto& x : y){
                cout << x << ' ';
            }
            cout << std::endl;
        }
    }
    catch(...){
        cout << "Default Exception\n"; 
    }
    return;
}

void dfs_fill(vector<vector<int>> &grid,int x,int y){

    if(x<0 || y<0 || x>(grid[0].size()-1) || y>(grid.size()-1)) return;

    if(grid[x][y]==0) return;

    grid[x][y]=0;

    dfs_fill(grid,x+1,y);
    dfs_fill(grid,x-1,y);
    dfs_fill(grid,x,y+1);
    dfs_fill(grid,x,y-1);

    dfs_fill(grid,x+1,y+1);
    dfs_fill(grid,x+1,y-1);
    dfs_fill(grid,x-1,y-1);
    dfs_fill(grid,x-1,y+1);

    return;
}

int iterate_islands_return_cluster_count(vector<vector<int>> &grid){
    int count = 0;

    for(auto y=0;y<grid.size();y++)
        for(auto x=0;x<grid[0].size();x++)
        {
            if(grid[x][y]==1) 
            {
                dfs_fill(grid,x,y);
                count++;
            }
        }

    return count;
}


int main() {

    vector<vector<int>> islandsGrid {{0,1,1,0},
                                     {0,1,0,1},
                                     {0,0,0,0},
                                     {0,0,1,1}};
    print_islands(islandsGrid);

    int count = 0;
    count = iterate_islands_return_cluster_count(islandsGrid);

    cout << std::endl;

    print_islands(islandsGrid);

    cout << "\nCount: " << count << endl << endl;

    system("pause");
}