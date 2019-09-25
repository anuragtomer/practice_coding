#include<iostream>
#include<vector>

using namespace std;
int majority(vector<int> arr) {
    int count = 1;
    int major = INT_MIN;
    for (auto &e: arr) {
        if (e == major) {
            count++;
        } else {
            count--;
            if (count == 0) {
                major = e;
                count = 1;
            }
        }
    }
    return major;
}

int main() {

    return 0;
}