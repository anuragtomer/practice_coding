#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;
/* A binary tree node has data, pointer to left child
 *  and a pointer to right child */
struct Node
{
    int data;
    Node * left;
    Node * right;
    Node(int x) : data(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector <int> leftView(Node * root) {
        vector <int> result;
        result.clear();
        list <Node *> li;
        li.clear();
        list <Node *> li2;
        li2.clear();
        li.push_back(root);

        Node * current;
        while(!li.empty()) {
            result.push_back(li.front()->data);
            while(!li.empty()) {
                current = li.front();
                if (current->left)
                    li2.push_back(current->left);
                if (current->right)
                    li2.push_back(current->right);
                li.pop_front();
            }
            li = li2;
            li2.clear();
        }
        return result;
    }
};
/* Driver program to test size function*/
int main()
{
    int t;
    struct Node *child;
    Solution sol;
    cin >> t;
    while (t--)
    {
        map <int, Node *> m;
        int n;
        cin >> n;
        struct Node *root = NULL;
        while (n--)
        {
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end())
            {
                parent = new Node(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            }
            else
                parent = m[n1];
            child = new Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2]  = child;
        }
        vector <int> solu;
        solu.clear();
        solu = sol.leftView(root);
        for (int i: solu)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}



/*
 * int main(){
 *     Solution sol;
 *     int T;
 *     cin >> T;
 *     while(T) {
 *         int num;
 *         cin >> num;
 *         vector <string> arr;
 *         arr.clear();
 *         while(num) {
 *             int val;
 *             cin >> val;
 *             arr.push_back(itos(val));
 *             num--;
 *         }
 *         root = createTree(arr);
 *         cout << sol.leftView(root) << endl;
 *         T--;
 *     }
 *     return 0;
 * }
 */
