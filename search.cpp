#include <iostream>
#include <vector>

using namespace std;

int main() {
	//code
	int T, n;
	cin >> T;
	
	while (T > 0) {
        T--;
	    cin >> n;
	    vector <int> arr(n);
	    for (int i = 0; i < n; i ++)
	        cin >> arr[i];
	    int element;
	    cin >> element;
	    int i;
	    for (i = 0; i < n; i++)
	        if (arr[i] == element) {
	            cout << i;
	            break;
	        }
	    if (i == n)
	        cout << -1;
	}
	return 0;
}
