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
 * So, basically, have polymorphic implementation for compute and logging based
 * on input.
 */
/*
 * Need to implement the following:
 * - bool handles(Input const &input);
 * - Output compute(input const &input);
 * = void log(Input const &input, Output const &output);
 */

/*
 * Second implementation: "OBJECT POLYMORPHISM".
 */

/*
 * Lets write parent class Calculator that has only virtual functions which will
 * be defined by respective child classes.
 */
struct Calculator {
    virtual bool handles(Input const &input) const = 0;
    virtual Output compute(Input const &input) const = 0;
    virtual void log(Input const &input, Output const &output) const = 0;
    virtual ~Calculator(){};
};

/*
 * Lets inherit the above parent class.
 */
struct BigCalculator : Calculator {
    bool handles(Input const &input) const override {
        return input.value > 10;
    }
    Output compute(Input const &input) const override {
        return Output{input.value * 5};
    }
    void log(Input const &input, Output const &output) const override {
        cout << "BigCalculator took an input of " << input.value << " and returned " << output.value << '\n';
    }
};

struct SmallCalculator : Calculator {
    bool handles(Input const &input) const override {
        return input.value <= 10;
    }
    Output compute(Input const &input) const override {
        return Output{input.value + 3};
    }
    void log(Input const &input, Output const &output) const override {
        cout << "SmallCalculator took an input of " << input.value << " and returned " << output.value << "\n";
    }
};

/*
 * Instantiating Calculators
 */
vector<unique_ptr<Calculator>> getCalculators() {
    auto calculators = vector<unique_ptr<Calculator>>{};
    calculators.push_back(make_unique<BigCalculator>());
    calculators.push_back(make_unique<SmallCalculator>());
    return calculators;
}

int main() {
    /*
     * Using the Calculators
     */
    auto input = Input{50};
    auto const calculators = getCalculators();
    auto calculator = find_if(begin(calculators), end(calculators),
                              [&input](auto &&calculator) { return calculator->handles(input); });
    if (calculator != end(calculators)) {
        auto const output = (*calculator)->compute(input);
        (*calculator)->log(input, output);
    }
    input = Input{5};
    calculator = find_if(begin(calculators), end(calculators),
                         [&input](auto &&calculator) { return calculator->handles(input); });
    if (calculator != end(calculators)) {
        auto const output = (*calculator)->compute(input);
        (*calculator)->log(input, output);
    }
    return 0;
}
