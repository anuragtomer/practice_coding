#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void print(vector <int> arr) {
        for (int i: arr)
            cout << i << " ";
        cout << endl;
    }
    vector <int> sort012(vector <int> arr) {
        int count0 = 0, count1 = 0, count2 = 0;
        for (int i:arr) {
            if (i == 0) count0++;
            else if (i == 1) count1++;
            else count2++;
        }
        arr.clear();
        while(count0) {
            arr.push_back(0);
            count0--;
        }
        while(count1) {
            arr.push_back(1);
            count1--;
        }
        while(count2) {
            arr.push_back(2);
            count2--;
        }
        return arr;
    }
};

int main() {
    Solution sol;
    int T;
    cin >> T;
    while(T) {
        int num;
        cin >> num;
        vector <int> arr;
        arr.clear();
        int count1 = 0, count2 = 0;
        while(num) {
            int val;
            cin >> val;
            arr.push_back(val);
            num--;
        }
        arr = sol.sort012(arr);
        sol.print(arr);
        T--;
    }
    return 0;
}
#if 0
int main(){
    Solution sol;
    int T;
    cin >> T;
    while(T) {
        int num;
        cin >> num;
        vector <int> arr;
        arr.clear();
        int count1 = 0, count2 = 0;
        while(num) {
            int val;
            cin >> val;
            if (val == 0) {
                cout << val << " ";
            } else if (val == 1)
                count1++;
            else count2++;
            num--;
        }
        while(count1) {
            cout << "1 ";
            count1--;
        }
        while(count2) {
            cout << "2 ";
            count2--;
        }
        cout << endl;
        T--;
    }
    return 0;
}

#endif
/*
 #include <iostream>
 *  using namespace std;
 *
 *  int main(){
 *   int T;
 *   scanf("%d", &T);
 *   while(T){
 *       int num;
 *       scanf("%d", &num);
 *       int count1=0, count2=0;
 *       while(num) {
 *           int val;
 *           scanf("%d", &val);
 *           if (val == 0) {
 *               printf("0 ");
 *           } else if (val == 1)
 *               count1++;
 *           else
 *               count2++;
 *           num--;
 *       }
 *       while(count1) {
 *           printf("1 ");
 *           count1--;
 *       }
 *       while(count2) {
 *           printf("2 ");
 *           count2--;
 *       }
 *       printf("\n");
 *       T--;
 *   }
 *   return 0;
 *  }
 *
 */
