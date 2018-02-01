/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int Q, L, R;
    cin >> Q;
    while (Q) {
        Q--;
        cin >> L;
        cin >> R;
        int correct = 0;
        for (int i = L; i <= R; i++) {
            int sum = 0;
            int temp = i;
            vector <int> values;
            values.clear();
            int rem;
            while (temp > 0) {
                rem = temp%10;
                temp = temp/10;
                if (rem != 0) {
                sum = sum + pow(rem, rem);
                    values.push_back(rem);
                    }
            }
            int not_correct = 0;
            for (int j = 0; j < values.size(); j ++)
                if (sum % values[j] != 0) {
                    not_correct = 1;
                    break;
                }
                    
            if (not_correct != 1)
                correct++;
        }
        cout << correct << endl;
    }
    return 0;    
}
