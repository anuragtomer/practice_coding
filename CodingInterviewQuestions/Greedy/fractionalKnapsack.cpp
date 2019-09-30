#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Used for putting into the heap and then pulling from heap to select for knapsack.
struct triplet{
    int weight;
    float value;
    int item;
};

/* Returns total value in knapsack.
 * Input is list of elements with their weight and corresponding value.
 * weight is the max weight knapsack can hold.
 * output is filled with picked up items, picked either wholely or partially.
 */
int 
fractionalKnapsack(vector<pair<int, int>> input, int weight, vector<pair<int, float>> &output) {

    // custom comparator lambda function for our heap.
    auto comp = [] (pair<float, triplet> a, pair<float, triplet> b) { return a.first < b.first;
    };

    // heap saving elements sorted by best value/weight ratio.
    priority_queue<pair<float, triplet>, vector<pair<float, triplet>>, decltype(comp)> heap(comp);
    
    for (int i = 0; i < input.size(); i++) {
        float fraction = input[i].second / input[i].first;
        triplet tr;
        tr.item = i+1;
        tr.value = input[i].second;
        tr.weight = input[i].first;
        heap.push(make_pair(fraction, tr));
    }

    // Now, we have our max heap ready, lets pull items from heap and put them in knapsack.
    float sum = 0.0;
    float value = 0.0;
    while(weight >= sum) {
        if (sum + heap.top().second.weight <= weight) {
            // This current item weight can be accomodated completely. Lets put it in whole.
            output.push_back(make_pair(heap.top().second.item, 1));
            sum += heap.top().second.weight;
            value += heap.top().second.value;
            heap.pop();
        } else {
            // Not enough space in knapsack to keep element in whole. We'll keep it in fraction.
            triplet tr = heap.top().second;
            int topWeight = tr.weight;
            int remainingWeight = (weight - sum);
            float fraction = (float)(remainingWeight)/topWeight;
            output.push_back(make_pair(tr.item, fraction));
            value += (heap.top().second.value*fraction);
            return value;
        }
    }
    return value;
}

int main() {
    vector<pair<int, int>> input;
    int n;
    cin >> n;

    for (int i = 0, weight = 0, value = 0; i < n; i++) {
        cin >> weight >> value;
        input.push_back(make_pair(weight, value));
    }

    int weight;
    cin >> weight;
    vector<pair<int, float>> output;
    int totalValue = fractionalKnapsack(input, weight, output);
    cout << "Total value in my knapsack is: " << totalValue << endl;
    for (auto &i: output) {
        cout << "Picked " << i.first<< "th element with " << i.second << " fraction.\n";
    }

    return 0;
}