#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
enum{
    VISITED,
    UNVISITED
};

class search_region {
    public:
        int val;
        int status;
        int i;
        int j;
};

vector <vector<search_region>> enter_element_into_other_grid(vector< vector <int>> grid) {
    vector <vector<search_region>> other_grid (grid.size(), vector<search_region> (grid[0].size()));
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            other_grid[i][j].i = i;
            other_grid[i][j].j = j;
            other_grid[i][j].val = grid[i][j];
            other_grid[i][j].status = UNVISITED;
        }
    }
    return other_grid;
}

void find_one(vector <vector<search_region> > other_grid, int * i, int * j) {
    for (int ii = 0; ii < other_grid.size(); ii++) {
        for (int jj = 0; jj < other_grid[ii].size(); jj++) {
            if (other_grid[ii][jj].val == 1 && other_grid[ii][jj].status == UNVISITED) {
                *i = ii;
                *j = jj;
                return;
            }
        }
    }
}

void put_one_neighbors_into_stack(queue <search_region> *S, vector <vector <search_region>> &other_grid, int i, int j) {
    if (i > 0 && j > 0 && other_grid[i - 1][j - 1].val == 1 && other_grid[i - 1][j - 1].status == UNVISITED) {
        other_grid.at(i - 1).at(j - 1).status = VISITED;
        cout << "inserting " << i - 1 << " " << j - 1 << endl;  
        S->push(other_grid[i - 1][j - 1]);
    }
    if (i > 0 && other_grid[i - 1][j].val == 1 && other_grid[i - 1][j].status == UNVISITED) {
        other_grid.at(i - 1).at(j).status = VISITED;
        cout << "inserting " << i - 1 << " " << j << endl;  
        S->push(other_grid[i - 1][j]);
    }
    if (i > 0 && j < (other_grid[i].size() - 1) && other_grid[i - 1][j + 1].val == 1 && other_grid[i - 1][j + 1].status == UNVISITED) {
        other_grid.at(i - 1).at(j + 1).status = VISITED;
        cout << "inserting " << i - 1 << " " << j + 1 << endl;  
        S->push(other_grid[i - 1][j + 1]);
    }
    if (j < (other_grid[i].size() - 1) && other_grid[i][j - 1].val == 1 && other_grid[i][j - 1].status == UNVISITED) {
        other_grid.at(i).at(j - 1).status = VISITED;
        cout << "inserting " << i << " " << j - 1 << endl;  
        S->push(other_grid[i][j - 1]);
    }
    if (j < (other_grid[i].size() - 1) && other_grid[i][j + 1].val == 1 && other_grid[i][j + 1].status == UNVISITED) {
        other_grid.at(i).at(j + 1).status = VISITED;
        cout << "inserting " << i << " " << j + 1 << endl;  
        S->push(other_grid[i][j + 1]);
    }
    if (i < other_grid.size() - 1 && j > 0 && other_grid[i + 1][j - 1].val == 1 && other_grid[i + 1][j - 1].status == UNVISITED) {
        other_grid.at(i + 1).at(j - 1).status = VISITED;
        cout << "inserting " << i + 1 << " " << j - 1 << endl;  
        S->push(other_grid[i + 1][j - 1]);
    }
    if (i < (other_grid.size() - 1) && other_grid[i + 1][j].val == 1 && other_grid[i + 1][j].status == UNVISITED) {
        other_grid.at(i + 1).at(j).status = VISITED;
        cout << "inserting " << i + 1 << " " << j << endl;  
        S->push(other_grid[i + 1][j]);
    }
    if (i < (other_grid.size() - 1) && j < (other_grid[i].size() - 1) && other_grid[i + 1][j + 1].val == 1 && other_grid[i + 1][j + 1].status == UNVISITED) {
        other_grid.at(i + 1).at(j + 1).status = VISITED;
        cout << "inserting " << i + 1 << " " << j + 1 << endl;  
        S->push(other_grid[i + 1][j + 1]);
    }
}

int get_biggest_region(vector< vector<int> > grid) {
    int max_count = 0;
    int count = 0;
    int i = -1, j = -1;
    queue<search_region> S;
    vector<vector <search_region>> other_grid;
    other_grid = enter_element_into_other_grid(grid);
    find_one(other_grid, &i, &j);
    if (i == -1)
        return max_count;
    other_grid[i][j].status = VISITED;
    cout << "inserting " << i << " " << j << endl;  
    S.push(other_grid[i][j]);
    while(!S.empty()) {
        other_grid[S.front().i][S.front().j].status = VISITED;
        count++;
        cout << "finding neighbors of " << S.front().i << " " << S.front().j << endl;
        put_one_neighbors_into_stack(&S, other_grid, S.front().i, S.front().j);
        cout << "deleting " << S.front().i << " " << S.front().j << endl;  
        S.pop();
        if (S.empty()) {
            cout << "count before reset" << count << endl;
            i = -1;
            j = -1;
            find_one(other_grid, &i, &j);
            max_count = max_count < count ? count : max_count;
            count = 0;
            if (i != -1) {
                other_grid[i][j].status = VISITED;
                cout << "inserting " << i << " " << j << endl;  
                S.push(other_grid[i][j]);
            }
        }
    }
    return max_count;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
        for(int grid_j = 0;grid_j < m;grid_j++){
            cin >> grid[grid_i][grid_j];
        }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}

