#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct string_size{
    string str;
    int sz;
};
class Solution{
    public:

        void merge(vector <string_size> &input, int lb1, int ub1, int lb2, int ub2) {
            vector <string_size> _input(input.size());
            int lb = lb1;
            int i = lb1;
            int j = ub2;
            while ((lb1 <= ub1) && (lb2 <= ub2)) {
                if (input[lb1].sz > input[lb2].sz) {
                    _input[lb].sz = input[lb2].sz;
                    _input[lb].str = input[lb2].str;
                    lb++;
                    lb2++;
                } else {
                    _input[lb].sz = input[lb1].sz;
                    _input[lb].str = input[lb1].str;
                    lb++;
                    
                    lb1++;
                }
            }
            while (lb1 <= ub1) {
                _input[lb].sz = input[lb1].sz;
                _input[lb].str = input[lb1].str;
                lb++;
                lb1++;
            }
            while (lb2 <= ub2) {
                _input[lb].sz = input[lb2].sz;
                _input[lb].str = input[lb2].str;
                lb++;
                lb2++;
            }
            for (int k = i; k <= j; k++) {
                input[k].sz = _input[k].sz;
                input[k].str = _input[k].str;
            }
        }
        void mergeSort(vector< string_size> &input, int lb, int ub) {
            if (lb == ub) {
                return;
            } else if (lb + 1 == ub) {
                if (input[lb].sz > input[ub].sz) {
                    int temp = input[lb].sz;
                    string tmpstr = input[lb].str;
                    input[lb].sz = input[ub].sz;
                    input[lb].str = input[ub].str;
                    input[ub].sz = temp;
                    input[ub].str = tmpstr;
                }
            } else {
                int mid = (lb + ub) / 2;
                mergeSort(input, lb, mid);
                mergeSort(input, mid + 1, ub);
                merge(input, lb, mid, mid+1, ub);
            }
        }
};
int main() {
    Solution sol;
    int noOfInputs;
    cin >> noOfInputs;
    string str;
    cin.ignore();
    while(noOfInputs) {
        getline(cin, str);
        stringstream s(str);
        vector<string_size> inputs(50);
        inputs.clear();
        string word;
        while(s >> word) {
            // cout << word << endl;
            inputs.push_back({word, word.size()});
            // cout << inputs.size() << endl;
        }
        /*
        cout << "Inputs taken in \n";
        for (int i = 0; i < inputs.size(); i++) {
            cout << inputs[i].sz << " " << inputs[i].str << endl;
        }
        */
        sol.mergeSort(inputs, 0, inputs.size() - 1 );
        cout << " ";
        for (int i = 0; i < inputs.size(); i++) {
            cout << inputs[i].str << " ";
        }
        cout << endl;
        noOfInputs --;
    }
    return 0;
}


