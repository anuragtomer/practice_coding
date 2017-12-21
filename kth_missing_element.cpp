#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	int T, n1, n2, k;
	cin >> T;
	while(T--){
		cin >> n1 >> n2 >> k;
		map <int, int> hashmap;
		vector <int> sorted_arr;
		vector <int> random_arr;
		for (int i = 0; i < n1; i++) {
			cin >> sorted_arr[i];
			hashmap.insert({sorted_arr[i], 1});
		}
		for (int i = 0; i < n2; i++) {
			cin >> random_arr[i];
			if (hashmap.find(random_arr[i]) != hashmap.end())
				hashmap.erase(random_arr[i]);
		}
		if (k <= hashmap.size()) {
			cout << hashmap[k] << endl;
		}
	}
	return 0;
}
