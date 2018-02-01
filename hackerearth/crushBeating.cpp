#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>

using namespace std;

struct bg{
    int crush;
    int beatings;
    unordered_set<int> beater;
};
int main() {
    int T;
    cin >> T;
    while(T) {
        int N;
        cin >> N;
        bg boys[N + 1];
        bg girls[N + 1];
        for (int i = 1; i <= N; i ++)
        {
            int val;
            cin >> val;
            boys[i].crush = val;
            boys[i].beatings = 0;
            boys[i].beater.clear();
        }
        for (int i = 1; i <= N; i++)
        {
            int val;
            cin >> val;
            girls[i].crush = val;
            girls[i].beatings = 0;
            girls[i].beater.clear();
        }
        for (int i = 1; i <= N; i ++) {
            if (girls[boys[i].crush].crush != i) {
                boys[girls[boys[i].crush].crush].beatings++;
                boys[girls[boys[i].crush].crush].beater.insert(i);
            }
            if (boys[girls[i].crush].crush != i) {
                girls[boys[girls[i].crush].crush].beatings++;
                girls[boys[girls[i].crush].crush].beater.insert(i);
            }
        }
        int max = INT_MIN;
        for (int i = 1; i <= N; i ++) {
            if (max < girls[i].beatings)
                max = girls[i].beatings;
            if (max < boys[i].beatings)
                max = boys[i].beatings;
        }
        int count = 0;
        
        for (int i = 1; i <= N; i++) {
            for (auto j = boys[i].beater.begin(); j != boys[i].beater.end(); j++) {
                
            }
        }

        cout << max << " " << count;
        T--;
    }
    return 0; 
}
