#include <fstream>
#include <iostream>
#include <random>
#include<cstring>

using namespace std;

void createMillionRecords(const string &filename) {
    ofstream ofs;
    ofs.open(filename, ios::binary);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> distribution(1, 999'999'999);
    
    //generating 300'000'000 random integers and write them into file.
    for (unsigned int i = 0; i < 300'000'000; ++i) {
        unsigned int random = distribution(gen);
        ofs << random << ' ';
    }
    ofs.flush();
    ofs.close();
}

int searchMissing(const string &filename) {
    ifstream ifs;
    ifs.open(filename, ios::binary);
    unsigned int num;    
    bool *arr = (bool *)calloc(999'999'999, sizeof(bool));    
    if (arr == NULL)
        return -1;
    while (ifs>>num) {
        arr[num] = true;
    }
    for (unsigned int i = 1; i <= 999'999'999; ++i) {
        if (arr[i] == false)
            return i;
    }
    free(arr);
    return -1;
}
int main() {
    string filename;
    cin >> filename;
    createMillionRecords(filename);
    cout << searchMissing(filename);
    return 0;
}
