#include <iostream> 
#include <vector>
using namespace std;

class Seq{
    vector <vector <int>> seqList;
    int lastAns;
    int N;
    public:
        Seq(int n): seqList(n, vector<int>(0)), lastAns(0), N(n) { }
        void perform_query(int a, int x, int y) {
            int index;
            switch(a) {
                case 1:
                    index = ((x^lastAns) % N);
                    seqList[index].push_back(y);
                    break;
                case 2:
                    index = ((x^lastAns) % N);
                    lastAns = seqList[index][y % seqList[index].size()];
                    cout << lastAns << endl;
                    break;
                default:
                    break;
            }
        }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    Seq sequences(N);
    int a, y, x;
    for (int i = 0; i < Q; i++) {
        cin >> a >> x >> y;
        sequences.perform_query(a, x, y);
    }
    return 0;
}
