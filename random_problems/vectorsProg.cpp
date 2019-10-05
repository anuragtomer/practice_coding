#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Solution {
public:
    bool isSafe(int i, int j, vector <vector <int> >  visited) {
        /*
         * If knight has not visited this position and this position is possible on the board,
         * then we return true, else return false.
         */
        if (i >= 0 && j >= 0 && i < 8 && j < 8 && visited[i][j] == -1)
            return true;
        else return false;
    }
    bool knightPath(vector <int> possiblei, vector <int> possiblej, int fromi, int fromj, vector <vector <int> > &visited, int path) {
        int toi, toj;
        if (path == 65)
             /* We have placed all the knights on the board, hence return true. */
            return true;
        /* Loop through all the possibilites, and then see if that position is possible. If it is,
         *  place the knight at the position and see if further placements are possible.
         */
        for (int i = 0; i < 8; i++) {
            toi = fromi + possiblei[i];
            toj = fromj + possiblej[i];
            if (isSafe(toi, toj, visited)) {
                visited[toi][toj] = path;
                if (knightPath(possiblei, possiblej, toi, toj, visited, path + 1) == true)
                    return true;
                else
                    /*
                     * If we place the knight at (toi, toj) position, we could not fill all the places. So it was not desirable.
                     * So we do not place knight at (toi, toj) position and try for next position.
                     */
                    visited[toi][toj] = -1;
            }
        }
        return false;
    }
    bool kP(vector <vector <int> > &visited) {
        /* (possiblei[x], possiblej[x]) is the location where (i, j) can go next.
         *  Knight can move only 2.5 moves from current position.
         */
        vector <int> possiblei {-2, -2, -1, -1, 1, 1, 2, 2};
        vector <int> possiblej {-1, 1, -2, 2, -2, 2, -1, 1};
        int path = 1;
        visited[0][0] = path; /* We start from placing knight at 0,0 to begin-with. */
        return knightPath(possiblei, possiblej, 0, 0, visited, path + 1);
    }
};

int main(){
    Solution sol;
    vector <vector <int> > visited(8, vector <int> (8, -1));
    /*
     * for (int i = 0; i < 8; i++)
     *     for (int j = 0; j < 8; j++)
     *         visited[i][j] = -1;
     */
    if(sol.kP(visited)) {
        for (vector <int> row: visited) {
            for (int path: row) {
                cout << setw(2);
                cout << path << " ";
            }
            cout << endl;
        }
        /*
         * for(int i = 0; i < 8; i++) {
         *     for (int j = 0; j < 8; j++) {
         *         cout << setw(2);
         *         cout << visited[i][j] << " ";
         *     }
         *     cout << endl;
         * }
         */
    } else {
        cout << "No path exists";
    }
    return 0;
}

