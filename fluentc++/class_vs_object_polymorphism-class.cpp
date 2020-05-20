#include <iostream>
#include <vector>

using namespace std;

/* Defines some double input for our calculators. */
struct Input {
    double value;
};
/* Defines output from calculator. */
struct Output {
    double value;
};
/*
 * Our problem is, given an `Input`:
 * - determine what calculator to invoke.
 * - produce an output
 * - print some kind of log what was entered, what was returned.
 *
 * So, basically, have polymorphic implementation for compute and logging based on input.
 */
/*
 * Need to implement the following:
 * - bool handles(Input const &input);
 * - Output compute(input const &input);
 * = void log(Input const &input, Output const &output);
 */

/*
 * First implementation: "CLASS POLYMORPHISM".
 */
struct BigCalculator {
    static bool handles(Input const &input) {
        return input.value > 10;
    }
    static Output compute(Input const &input) {
        return Output{input.value * 5};
    }
    static void log(Input const &input, Output const &output) {
        cout << "BigCalculator took an input of " << input.value << " and returned " << output.value << '\n';
    }
};
struct SmallCalculator {
    static bool handles(Input const &input) {
        return input.value <= 10;
    }
    static Output compute(Input const &input) {
        return Output{input.value + 3};
    }
    static void log(Input const &input, Output const &output) {
        cout << "SmallCalculator took an input of " << input.value << " and returned " << output.value << "\n";
    }
};
/*
 * Lets connect the above to 'Parent' Calculator class using object polymorphism
 */
struct Calculator {
    bool (*handles)(Input const &input);
    Output (*compute)(Input const &input);
    void (*log)(Input const &input, Output const &output);
    template <typename CalculatorImplementation>
    static Calculator createFrom() {
        return Calculator{&CalculatorImplementation::handles, &CalculatorImplementation::compute,
                          &CalculatorImplementation::log};
    }
};

/*
 * Instantiating Calculators
 */
vector<Calculator> getCalculators() {
    return {Calculator::createFrom<BigCalculator>(), Calculator::createFrom<SmallCalculator>()};
}
int main() {
    /*
     * Using the Calculators
     */
    auto input = Input{50};
    auto const calculators = getCalculators();
    auto calculator = find_if(begin(calculators), end(calculators),
                              [&input](auto &&calculator) { return calculator.handles(input); });
    if (calculator != end(calculators)) {
        auto const output = calculator->compute(input);
        calculator->log(input, output);
    }
    input = Input{5};
    calculator = find_if(begin(calculators), end(calculators),
                         [&input](auto &&calculator) { return calculator.handles(input); });
    if (calculator != end(calculators)) {
        auto const output = calculator->compute(input);
        calculator->log(input, output);
    }
    return 0;
}
