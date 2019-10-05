/* Program to find the span of elements
 * S[i] = maximum no of consecutive element A[j] immediately preceding A[i] and such that A[j] <= A[i], i > j.
 */
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> span(vector<int> &inp) {
    vector<int> output(inp.size());
    stack<int> st;
    int temp_span;
    /* Algo:
     * 1. Do for each element:
     * 2. set currentspan = 1.
     * 3. If stack is empty, push current index and move to 5.
     * 4. while current element is greater than element at top index (careful about stack getting empty)
     *    a. add span of top index to currentspan.
     *    b. pop
     * 5. set span[current element] = currentspan
     */
    for (int i = 0; i < inp.size(); i++) {
        temp_span = 1;
        if (st.empty() == true) {
            st.push(i);
        } else {
            while(st.empty() == false && inp[st.top()] <= inp[i]) {
                temp_span += output[st.top()];
                st.pop();
            }
            st.push(i);
        }
        output[i] = temp_span;        
    }
    return output;
}

int main() {
    int n;
    vector<int> inp;
    vector<int> output;
    cout << "No of elements: ";
    cin >> n;
    int elem;
    while (n > 0) {
        n--;
        cin >> elem;
        inp.push_back(elem);
    }
    cout << "\nInput : ";
    for (auto &val: inp) {
        cout << val << " ";
    }
    cout << "\nSpan: ";
    output = span(inp);
    for (auto &val: output) {
        cout << val << " ";
    }
    return 0;
}