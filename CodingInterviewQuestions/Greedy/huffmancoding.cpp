#include <iostream>
#include <queue>
#include <vector>
#include <cassert>

using namespace std;

struct TreeNode{
    TreeNode * left;
    string data;
    int count;
    TreeNode * right;
    TreeNode(): TreeNode(nullptr, "", 0, nullptr) {};
    TreeNode(TreeNode *_left, 
             string _data, 
             int _count, 
             TreeNode *_right): left {_left}, 
                                data{_data}, 
                                right{_right}, 
                                count{_count} {};
};

TreeNode * huffmancoding(vector<pair<char, int>> &input) {

    // Lambda function to calculate priority order. Priority is based on minimum count.
    auto comp = [] (TreeNode * a, TreeNode * b) { 
                    return (a->count > b->count);
                    };

    priority_queue<TreeNode *, vector<TreeNode *>, decltype(comp) > heap(comp);
    
    // Put all input chars and their frequency in min heap.
    for (auto &i: input) {
        TreeNode *tn = new TreeNode(nullptr, string(1, i.first), i.second, nullptr);
        heap.push(tn);
    }

    /* Algo:
     * Pull top 2 elements from heap.
     * Merge them like:
     *                        ---------------------------------------------------------
     *                        |  | left_str+ right_str | left_count + right_count |   |
     *                        ---------------------------------------------------------
     *                         /                                                      \
     *   ----------------------------------------                       ------------------------------------------------------
     *   |  | heap_top_str | heap_top_count |   |                       |  | heap_second_top_str | heap_second_top_count |   |
     *   ----------------------------------------                       ------------------------------------------------------
     * 
     * Push back the new node into heap.
     * Repeat till there is only 1 element in heap.
     */
    for (int i = 0; i < input.size() - 1; i++) {
        TreeNode *tn = new TreeNode();
        // Greedily pulling strings with least count.
        tn->left = heap.top();
        heap.pop();
        tn->right = heap.top();
        heap.pop();
        tn->data = tn->left->data + tn->right->data; // This data is not used now. So concatinating the underlying strings
        tn->count = tn->left->count + tn->right->count;
        heap.push(tn);
    }
    assert(heap.size() == 1); // Heap should have only the root of the tree.
    return heap.top();
}

void processTreeNode(TreeNode * const &tn, string str, vector< pair<char, string>> &output) {
    if (tn->left == nullptr && tn->right == nullptr) {
        output.push_back(make_pair(tn->data[0], str));
    } else {
        processTreeNode(tn->left, str+"0", output); // For left node, append '0'
        processTreeNode(tn->right, str+"1", output); // For right node, append '1'
    }
}

int main() {
    // Get input
    vector<pair<char, int>> input;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char ch;
        int num;
        cin >> ch >> num;
        input.push_back(make_pair(ch, num));
    }
    // Get huffman tree.
    TreeNode *tn = huffmancoding(input);
    // Process huffman tree.
    vector<pair<char, string>> output;
    processTreeNode(tn, "", output);
    for (auto &i: output) {
        cout << i.first << " encoded as: " << i.second << endl;
    }
    return 0;
}