/* Problem Statement:
 * Lets say you are given a csv file with each line having three entities:
 * - url
 * - date on which that url is accessed
 * - No of clicks on that date.
 * 
 * We want the list of urls that have been clicked D no of times in a window of N days(consecutive).
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <cassert>
#include <queue>
using namespace std;

struct lineinfile{
	string url;
	int date;
	int clicks;
};

vector<lineinfile> readdata(string filename) {
    ifstream in(filename);
    vector<lineinfile> data;
    if (in) {
        string line;
        while (getline(in, line)) {
            stringstream sep(line);
            string field;
            vector<string> ln;
            while (getline(sep, field, ',')) {
                ln.push_back(field);
            }
            lineinfile lif;
            lif.url = ln[0];
            lif.date = stod(ln[1]);
            lif.clicks = stod(ln[2]);
            data.push_back(lif);
        }
    }
    return data;
}

bool comp(lineinfile a, lineinfile b) {
    return a.date < b.date;
}

struct queuesum{
    queue<pair<int, int>> q;
    int sum;
};


vector<string> NclicksinDdays(vector<lineinfile> &data, int N, int D) {
    assert(N >= 1);
    assert(D > 0);
    unordered_map<string, queuesum> hash;
    unordered_set<string> tempresult;
    vector<string> result;
    for(auto a: data) {
        if (hash.find(a.url) == hash.end()) {
            // This is a new url. Need to add to hash table and update queue and current sum.
            queuesum qs;
            qs.q.push({a.date, a.clicks});
            qs.sum = a.clicks;
            hash[a.url] = qs; 
        } else {
            /*
             * I have seen this url before. Update the queue and sum. If the queue length 
             * is more than the window, remove the oldest element and update the sum accordingly.
             */
            hash[a.url].q.push({a.date, a.clicks});
            hash[a.url].sum += a.clicks;
            while (abs(hash[a.url].q.front().first - a.date) > N) { // N is the window of consecutive days. Check if we have crossed the window. If so, adjust the sum and queue.
                pair<int, int> date_clicks = hash[a.url].q.front();
                hash[a.url].q.pop();
                hash[a.url].sum -= date_clicks.second;
            }
        }
        if (hash[a.url].sum >= D) { // D is the no of clicks. We have a url which has been hit D times in an N day window.
            tempresult.insert(a.url); // Add it to the set. Set because we don't want to add same url multiple times.
        }
    }
    for (auto a: tempresult) {
        result.push_back(a); // Caller needs the result as vector of strings. Convert the output from set to vector of strings.
    }
    return result;
}

int main() {
	string filename;
	cin >> filename;
	vector<lineinfile> data = readdata(filename);

    /*for(auto a: data)
    	cout << a.url << " " << a.date << " " << a.clicks << "\n";*/
    // Sort based on date so that we can maintain a rolling window.
    sort(data.begin(), data.end(), comp);
    /*for (auto a: data)
        cout << a.url << " " << a.date << " " << a.clicks << "\n";
*/
    int N, D;
    cin >> N >> D;
    vector<string> output = NclicksinDdays(data, N, D);
    for (auto a: output)
        cout << a << "\n";

    return 0;
}