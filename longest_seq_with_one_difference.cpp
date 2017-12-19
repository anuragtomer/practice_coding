#include <iostream>
#include <unordered_map>

using namespace std;
int method1(int arr[], int n) {
    /* Brute force solution.
     * 1. Initialise max array to 1 to denote that each no form longest 
     *    sequence with itself.
     * 2. Iterate through the array and add 1 to current element if it falls
     *    within the range of 1 with the element being compared.
     */
    int max[n];
    for (int i = 0; i < n; i++)
        max[i] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if ((arr[i]-arr[j] == 1) || (arr[j]-arr[i] == 1)) {
                if (max[i] < (1 + max[j]))
                    max[i] = 1 + max[j];
            }
        }
    }
    int m = 0;
    for (int i = 0; i < n; i++)
        if (m < max[i])
            m = max[i];
    return m;
}

int method2(int arr[], int n) {
    /* Hash table implementation
     * 1. Find 1 greater/ 1 smaller no in hash table. 
     * 2. If found, check the len it currently saves. len denotes the 
     *    longest sequence for this 1 greater / 1 smaller entry in hash table.
     * 3. key for this current element will be saved as len.
     * 4. return max len in hashtable across all the entries.
     */
    unordered_map<int, int> hash_table;
    int longlen = 0;
    for (int i = 0; i < n; i++) {
        int len = 0;
        if (hash_table.find(arr[i] - 1) != hash_table.end() &&
                len < hash_table[arr[i] - 1])
            len = hash_table[arr[i] - 1];

        if (hash_table.find(arr[i] + 1) != hash_table.end() &&
                len < hash_table[arr[i] + 1])
            len = hash_table[arr[i] + 1];
        hash_table[arr[i]] = len + 1;

        if (longlen < hash_table[arr[i]])
            longlen = hash_table[arr[i]];
    }
    return longlen;
}

int main()
{    
    int arr[100];
    int input_var;
    cin >> input_var;
    for (int i = 0; i < input_var; i++)
        cin >> arr[i];
    cout << method1(arr, input_var) << endl;
    cout << method2(arr, input_var) << endl;
    return 0; 
}

