#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <list>

using namespace std;

vector <string>  topological(map <string, string> dataset) {
    map <string, string> reve;
    reve.clear();
    map <string, string> :: iterator it;
    for(it = dataset.begin(); it != dataset.end(); it++) {
        reve[it->second] = it->first;
    }
    list <string> starting;
    starting.clear();
    set <string> um;
    um.clear();
    for(it = dataset.begin(); it != dataset.end(); it++) {
        if (reve.find(it->first) == reve.end()) {

        }
    }
    return {};
}
int main() {
    int pairs = 0;
    cin >> pairs;
    map <string, string> dataset;
    dataset.clear();
    while(pairs) {
        string src, dest;
        cin >> src >> dest;
        dataset[src] = dest;
        pairs--;
    }
    vector <string> topoSort = topological(dataset);
    for(string str: topoSort)
        cout << str << " ";
    return 0;
}
