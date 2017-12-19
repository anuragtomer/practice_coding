#include <iostream>
using namespace std;
class peak {
    public:
        int find1Dpeak(int arr[], int from, int to) {
            if (from > to) 
                return -1;
            int mid = (from + to) / 2;
            if (arr[mid] >= arr[mid +1] && arr[mid] >= arr[mid -1]) {
                return arr[mid];
            }
            if (arr[mid] < arr[mid +1]) {
                return find1Dpeak(arr, mid+1, to);
            } else {
                return find1Dpeak(arr, from, mid-1);
            }
        }

        int findGlobalpeak(int arr[], int from, int to) {
            if (from == to) {
                return from;
            }
            int mid = (from + to) / 2;
            int j1 = findGlobalpeak(arr, from, mid);
            int j2 = findGlobalpeak(arr, mid +1, to);
            if (arr[j1] > arr[j2]) {
                return j1;
            } else {
                return j2;
            }
        }

        int find2Dpeak(int **arr, int xfrom, int xto, int yfrom, int yto) {
            if (xfrom == xto) {
                int j = findGlobalpeak(arr[xfrom], yfrom, yto);
                return arr[xfrom][j];                
            }
            int midx = (xfrom + xto) / 2;            
            int j = findGlobalpeak(arr[midx], yfrom, yto);
            if (arr[midx][j] >= arr[midx - 1][j] && arr[midx][j] >= arr[midx + 1][j]) {
                return arr[midx][j];
            } else if (arr[midx][j] < arr[midx - 1][j]) {
                return find2Dpeak(arr, xfrom, midx - 1, yfrom, yto);
            } else {
                return find2Dpeak(arr, midx + 1, xto, yfrom, yto);
            }
        }
};

int main() {
    peak odp;
    int N, M;
    cout << "1-D array or 2-D array?"<< endl;
    int x;
    cin >> x;
    switch (x) { 
        case 1: 
            {
            int * arr;
            cin >> N;
            arr = new int[N];
            for (int i = 0; i < N; i ++) {
                cin >> arr[i];
            }
            int peak_value = odp.find1Dpeak(arr, 0, N-1);
            if (peak_value == -1)
                cout << "there is no peak in this array";
            else
                cout << peak_value;
            delete [] arr;
            break;
            }
        case 2:
            {
                int **arr;
            cin >> N >> M;
            arr = new int *[N];
            for (int i = 0; i < N; i++ ) {
                arr[i] = new int [M];
                for (int j = 0; j < M; j++) {
                    cin >> arr[i][j];
                }
            }
            int peak_value = odp.find2Dpeak(arr, 0, N-1, 0, M-1);
            if (peak_value == -1)
                cout << "There is no peak in this 2D array";
            else 
                cout << peak_value;
            for(int i =0; i < N; i++)
                delete [] arr[i];
            delete [] arr;
            break;
            }
        default:
            break;
    }
    return 0;    
}
