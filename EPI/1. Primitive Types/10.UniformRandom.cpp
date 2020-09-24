#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

using namespace std;
int ZeroOneRandom() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(0, 1);
    return distribution(generator);
}

int UniformRandom(int lower_bound, int upper_bound) {
    int number_of_outcomes = upper_bound - lower_bound + 1, result;
    do {
        result = 0;
        for (int i = 0; (1 << i) < number_of_outcomes; ++i) {
            result = (result << 1) | ZeroOneRandom();
        }
    } while (result >= number_of_outcomes);
    return result + lower_bound;
    /**
     * To analyze the time complexity, let t = b - a + 1. The probability tha we succeed in
     * the first try is t/2^i.Since 2^i is the smallest power of 2 greater than or equal to t,
     * it must be less than 2t. This implies that t/2^i > t/2t = 1/2. Hence the probability that
     * we do not succeed on the first try is 1 - t/2^i < 1/2. Since successive tries are independent,
     * the probability that more than k trie are needed is less than or equal to 1/2^k. Hence,
     * the expected number of tries is not more that 1 + 2(1/2) + 3(1/2)^2 + 4(1/2) ... The series
     * converges, so the number of tries is O(1). Each try makes ceil(log(b - a + 1)) calls to the
     * 0/1-value random number generator. Assuming the 0/1-value random number
     * generator takes O(1) time, the time complexity is O(log(b - a + 1)).
     */
}

int main() {
    for (int i = 0; i < 20; ++i) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << UniformRandom(1, 6) << endl;
    }
    return 0;
}
