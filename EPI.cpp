#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>
using namespace std;

void populateQuestions(vector<vector<string>> &AllQuestions) {
    vector<string> ChapterWiseQuestions;
    // AllQuestions.push_back(ChapterWiseQuestions); // Chapter 1-4 don't have any questions. Pushing Empty vector.
    AllQuestions.push_back(ChapterWiseQuestions); // Chapter 1-4 don't have any questions.
    AllQuestions.push_back(ChapterWiseQuestions); // Chapter 1-4 don't have any questions.
    AllQuestions.push_back(ChapterWiseQuestions); // Chapter 1-4 don't have any questions.
    AllQuestions.push_back(ChapterWiseQuestions); // Chapter 1-4 don't have any questions.
    // Chapter 5 questions: Primitive types.
    string question =
        "Write a program to count the number of bits that are set to 1 in an integer.\nshort CountBits(unsigned int "
        "x);";
    ChapterWiseQuestions.push_back(question);

    question =
        "How would you compute the parity of a very large number of 64-bit words?\nshort Parity(unsigned long x);\n";
    ChapterWiseQuestions.push_back(question);

    question =
        "Implement code that takes as input a 64-bit integer and swaps the bits at indices i and j.\nlong "
        "SwapBits(long x, int i, int j);";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that takes a 64-bit word and returns the 64-bit word consisting of the bits of the input word "
        "in reverse order.\nlong ReverseBits(long x);";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program which takes as input a non-negative integer x and returns a number y which is not equal to x, "
        "but has the same weight as x and their difference, |y-x|, is as small as possible. You can assume x is not 0, "
        "or all 1s.\nunsigned long ClosestIntSameBitCount(unsigned long x);";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program which takes as input a non-negative integer x and returns a number y which is not equal to x, "
        "but has the same weight as x and their difference, |y-x|, is as small as possible. You can assume x is not 0, "
        "or all 1s. Do this in time and space complexity of O(1).\nunsigned long ClosestIntSameBitCount(unsigned long "
        "x);";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that multiplies two non-negative integers. The only operator you are allowed to use are \n1. "
        "assignment\n2. the bitwise operators >>, <<, |, &, ~, ^\n3. equality checks and boolean combinations "
        "thereof.\n You may use loops and functions that you write yourself. You cannot use increment/decrement/x<y "
        "etc.\nunsigned Multiply(unsigned x, unsigned y);";
    ChapterWiseQuestions.push_back(question);

    question =
        "Given two positive integers, compute their quotient, using only the addition, subtraction and shift "
        "operators.\nunsigned Divide(unsigned x, unsigned y);";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that takes a double x and an integer y and return x^y. You can ignore underflow and "
        "overflow.\ndouble power(double x, int y);";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program which takes an integer and returns the integer corresponding to the digits of the input "
        "written in reverse order. For example, the reverse of 42 is 24, -314 is -413.\nlong Reverse(int x);";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that takes an integer and determines if that integer's representation as a decimal string is "
        "a palindrome.\nbool IsPalindromeNumber(int x);";
    ChapterWiseQuestions.push_back(question);

    question =
        "How would you implement a random number generator that generates a random integer i between a and b, "
        "inclusive, given a random number generator that produces zero or one with equal probability?\nint "
        "UniformRandom(int lower_bound, int upper_bound);";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program which tests if two rectangles have a nonempty intersection. If the intersection is nonempty, "
        "return the rectangle formed by their intersection.\nstruct Rectangle {\n  int x, y, width, "
        "height;\n};\nRectangle IntersectRectangle(const Rectangle& R1, const Rectangle& R2);";
    ChapterWiseQuestions.push_back(question);

    question = "Given four points in the plane, how would you check if they are the vertices of a rectangle?";
    ChapterWiseQuestions.push_back(question);

    question = "How would you check if two rectangle, not necessarily aligned with the X and Y axes, intersect?";
    ChapterWiseQuestions.push_back(question);

    AllQuestions.push_back(ChapterWiseQuestions); // Pushing chapter 5 questions.
    vector<string>().swap(ChapterWiseQuestions);

    // Chapter 6: Arrays
    question =
        "Your input is an array of integers, and you have to reorder its entries so that the even entries appear "
        "first. You are required to solve it without allocating additional storage.\nvoid EvenOdd(vector<int> *A_ptr);";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that takes an array A and an index i into A, and rearranges the elements such that all "
        "elements less than A[i] appears first, followed by elements equal to the pivot, followed by elements greater "
        "than the pivot.\ntypedef enum {RED, WHITE, BLUE } Color;\nvoid DutchFlagPartition(int pivot_index, "
        "vector<Color>*A_ptr);";
    ChapterWiseQuestions.push_back(question);

    question =
        "Assuming that keys take one of three values, reorder the array so that all objects with the same key appear "
        "together. The order of the subarrays is not important. Use O(1) additional space and O(n) time.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Given an array A of n objects with keys that takes one of four values, reorder the array so that all objects "
        "that have the same key appear together. Use O(1) additional space and O(n) time.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Given an array A of n objects with Boolean-valued keys, reorder the array so that objects that have te key "
        "false appear first. Use O(1) additional space and O(n) time.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Given an array A of n objects with Boolean-valued keys, reorder the array so that objects that have te key "
        "false appear first. The relative ordering of objects with key true should not change. Use O(1) additional "
        "space and O(n) time.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program which takes as input an array of digits encoding a decimal number D and updates the array to "
        "represent the number D + 1.\nvector<int> PlusOne(vector<int> A);";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program which takes as input two strings s and t of bits encoding binary numbers Bs and Bt, "
        "respectively, and returns a new string of bits representing the number Bs + Bt.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that takes two arrays representing integers, and returns an integer representing their "
        "product.\nvector<int> Multiply(vector<int> num1, vector<int> num2);";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that takes an array of n integers, where A[i] denote the maximum you can advance from index "
        "i, and returns whether it is possible to advance to the last index starting from the beginning of the "
        "array.\nbool CanReachEnd(const vector<int>& max_advanced_steps);";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program takes an array of n integers, where A[i] denote the maximum you can advance from index "
        "i, and compute the minimum number of steps needed to advace to the last location.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program which takes as input a sorted array and updates it so that all duplicates have been removed "
        "and the remaining elements have been shifted left to fill emptied indices. Return the number of valid "
        "elements.\nint DeleteDuplicates(vector<int> *A_ptr);";
    ChapterWiseQuestions.push_back(question);

    question =
        "Implement a function which takes an input as array and a key, and updates the array so that all occurrences "
        "of "
        "the input key have been removed and the remaining elements have been shifted left to fill the emptied "
        "indices. Return the number of remaining elements.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program which takes as input a sorted array A of integers and a positive integer m, and updates A so "
        "that if x appears m times in A it appears exactly min(2, m) times in A. The update to A should be performed "
        "in one pass, and no additional storage may be allocated.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that takes an array denoting the daily stock price, and returns the maximum profit that "
        "could be made by buying and the selling one share of that stock.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that takes an array of integers and finds the length of a longest subarray all of whose "
        "entries are equal.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program tha computes the maximum profit that can be made by buying and selling a share at  most "
        "twice. The second buy must be made on another date after the first sale.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program tha computes the maximum profit that can be made by buying and selling a share at  most "
        "twice. The second buy must be made on another date after the first sale. Solve the problem in O(n) and O(1) "
        "space.";
    ChapterWiseQuestions.push_back(question);

    question = "Write a program that takes an integer argument and returns all the primes between 1 and that integer.";
    ChapterWiseQuestions.push_back(question);

    question = "Given an array A of n elements and a permutation P, apply P to A.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Given an array A of integers representing a premutation, update A to represent the inverse permutation using "
        "only constant additional storage.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that takes as input a permutation, and returns the next permutation under dictionary "
        "ordering.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Compute the kth permutation under dictionary ordering, starting from the identity permutation (which is the "
        "first permutation in dictionary ordering).";
    ChapterWiseQuestions.push_back(question);

    question =
        "Given a permutation p, return the permutation corresponding to the previous permutation of p under dictionary "
        "ordering.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Implement an algorithm that takes as input an array of distinct elements and a size, and returns a subset of "
        "the given size of the array elements. All subsets should be equally likely. Return the result in input array "
        "itself.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Design a program that takes as input a size k, and reads packets, continuously maintaining a uniform random "
        "subset of size k of the read packets.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Design an algorithm that creates uniformly random permutations of {0, 1, ..., n-1}. You are given a random "
        "number generator that returns integers in the set)0, 1, ..., n-1} with equal probability; use as few calls as "
        "possible.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that takes as input a positive integer n and a size x <= n, and returns a size-k subset of "
        "{0,1,2,...,n-1}. The subset should be represented as an array. All subsets should be equally likely and, in "
        "addition, all permutations of elements of the array should be equally likely. You may assume you have a "
        "function which takes as input a nonnegative integer t and returns an integer in the set {0,1,2,...,t-1} with "
        "uniform probability.";
    ChapterWiseQuestions.push_back(question);

    question =
        "You are given n numbers as well as probabilities p0, p1, p2,...,pn-1, which sum up to 1. Given a random "
        "number generator that produces values in [0,1] uniformly, how would you generate one of the n numbers "
        "acccording to the specified probabilities. For example, if the numbers are 3,5,7,11, and the probabilities "
        "are 9/18, 6/18, 2/18, 1/18, then in 1000000 calls to your program, 3 should appear roughly 500000 times, 5 "
        "should appear roughly 333333 times, 7 should appear roughly 111111 times, and 11 should roughly appear 55555 "
        "times.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Given a random number generator that produces values in [0, 1] uniformly, how would you generate a value X "
        "from T according to a continuous probability distribution, such as the exponential distribution?";
    ChapterWiseQuestions.push_back(question);

    question = "Check whether a 9x9 2D array representing a partially completed Sudoku is valid.";
    ChapterWiseQuestions.push_back(question);

    question = "Write a program which takes an nxn 2D array and returns the spiral ordering of the array.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Given a dimension d, write a program to generate a dxd 2D array which in spiral order is {1,2,3,...,d^2}.";
    ChapterWiseQuestions.push_back(question);

    question = "Given a sequence of integers P, compute a 2D array A whose spiral order is P.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program to enumerate the first n pairs of integers (a, b) in spiral order, starting from (0,0) "
        "followed by (1,0).";
    ChapterWiseQuestions.push_back(question);

    question = "Compute the spiral order for an mxn 2D array A.";
    ChapterWiseQuestions.push_back(question);

    question = "Compute the last element in spiral order for an mxn 2D array A in O(1) time.";
    ChapterWiseQuestions.push_back(question);

    question = "Compute the kth element in spiral order for an mxn 2D array A in O(1) time.";
    ChapterWiseQuestions.push_back(question);

    question = "Write a function that takes as input an nxn 2D array, and rotates the array by 90 degrees clockwise.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Implement an algorithm to reflect A, assuming to be an nxn 2D array, about the horizontal axis of symmetry. "
        "Repeat the same for reflections about the vertical axis, the diagonal from top-left to bottom-right, and the "
        "diagonal from top-right to bottom-left.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program which takes as input a nonnegative integer n and returns the first n rows of Pascal's "
        "Triangle.";
    ChapterWiseQuestions.push_back(question);

    question = "Compute the nth row of Pascal's triangle using O(n) space.";
    ChapterWiseQuestions.push_back(question);

    AllQuestions.push_back(ChapterWiseQuestions); // Chapter 6 questions (Arrays).
    vector<string>().swap(ChapterWiseQuestions);
    // Chapter 7: Strings

    question = "Write a program that checks whether a string is palindromic.";
    ChapterWiseQuestions.push_back(question);

    question = "Implement string/integer inter-conversion functions.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that performs base conversion from base a to base b. Input would be represented as string.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Implement a function that converts a spreadsheet column id to the corresponding integer, with 'A' "
        "corresponding to 1.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Implement a function that converts a spreadsheet column id to the corresponding integer, with 'A' "
        "corresponding to 0.";
    ChapterWiseQuestions.push_back(question);

    question = "Implement a function that converts an integer to the spreadsheet column id.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program which takes as input as array of characters, and removes each 'b' and replaces each 'a' by "
        "two 'd's. Specifically, along with the array, you are provided an integer-valued size. Size denotes the "
        "number of entries of the array that the operation is to be applied to. You can assume there is enough space "
        "in the array to hold the final result.";
    ChapterWiseQuestions.push_back(question);

    question =
        "You have an array C of characters. The characters may be letters, digits, blanks, and punctuation. The "
        "telex-encoding of the array C is an array T of characters in which letters, digits, and blanks appear as "
        "before, but punctuation marks are spelled out. For example, telex-encoding entails replacing the character "
        "'.' by the string 'DOT', and character ',' by 'COMMA', the character '?' by 'QUESTION MARK', and the "
        "character '!' by 'EXCLAMATION MARK'. Design an algorithm to perform telex-encoding with O(1) space.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program which merges two sorted arrays of integers, A and B. Specifically, the final result should be "
        "a sorted array of length m + n, where n and m are the lengths of A and B, respectively. Use O(1) additional "
        "storage -- assume the result is stored in A, which has sufficient space. These arrays are C-style arrays, "
        "i.e., contiguous preallocated blocks of memory.";
    ChapterWiseQuestions.push_back(question);

    question = "Implement a function which takes as input a string s and returns true if s is a palindrom string.";
    ChapterWiseQuestions.push_back(question);

    question = "Implement a function for reversing the words in a string s.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program which takes as input a phone number, specified as a string of digits, and returns all "
        "possible character sequences that correspond to the phone number. The cell phone keypad is specified by a "
        "mapping that takes a digit and returns the corresponding set of characters. The character sequences do not "
        "have to be legal words or phrases.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program which takes as input a phone number, specified as a string of digits, and returns all "
        "possible character sequences that correspond to the phone number. The cell phone keypad is specified by a "
        "mapping that takes a digit and returns the corresponding set of characters. The character sequences do not "
        "have to be legal words or phrases. Don't use recursion.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that takes as input an integer n and returns the nth integer in the look-and-say sequence. "
        "Return the result as a string.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program which takes as input a valid Roman number string s and returns the integer it corresponds to.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that takes as input a string of Roman number symbols and checks whether that string is valid.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that takes as input a positive integer n and returns a shortest valid simple Roman Number "
        "string representing n.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that determines where to add periods to a decimal string so that the resulting string is a "
        "valid IP address. There may be more than one valid IP address corresponding to a string, in which case you "
        "should print all possibilities.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program that determines where to add periods to a decimal string so that the resulting string has k "
        "subsets of 0-255 integers. There may be more than one valid IP address corresponding to a string, in which "
        "case you should print all possibilities.";
    ChapterWiseQuestions.push_back(question);

    question =
        "Write a program which takes as input a string s and returns the snakestring of s. For example, 'Hello_World!' "
        "in snakestring would be represented as:\n   e      _       l\n H   l   o   W   r   d\n        l       o       "
        "!.\nThe output then should read as 'e_lHloWrdlo!'";
    ChapterWiseQuestions.push_back(question);

    question =
        "Implement run-length encoding and decoding functions. Assume the string  to be encoded consists of letters of "
        "the alphabet, with no digits, and the string to be decoded is a valid decoding. For example: RLE of "
        "'aaaabcccaaa' is '4a1b3c2a'. The decoding of '3e4f2e' returns 'eeeffffee'.";
    ChapterWiseQuestions.push_back(question);

    question = "Given two strings s(the 'search string') and t (the 'text'), find the first occurrence of s in t.";
    ChapterWiseQuestions.push_back(question);

    AllQuestions.push_back(ChapterWiseQuestions); // Chapter 7 questions (Strings).
    vector<string>().swap(ChapterWiseQuestions);
}

void printUsage(string argv) {
    cout << "USAGE: " << argv << " [--chapter <number>] [--questions <number>]\n";
    cout << "Default: 5 questions from any chapter.";
}

vector<int> splitOnComma(string questions) {
    vector<int> result;
    string num;
    for (auto c : questions) {
        if (c == ',') {
            result.push_back(stoi(num));
            num = "";
        } else {
            num += c;
        }
    }
    if (num != "")
        result.push_back(stoi(num));
    return result;
}

vector<string> chooseQuestions(const vector<vector<string>> &AllQuestions, int numOfQuestions,
                               vector<int> &chapterNumber) {
    vector<string> selectedQuestions;
    default_random_engine seed((random_device())());

    int hasQuestions = 0;
    int last = chapterNumber.size() - 1;
    for (int i = 0; i <= last; ++i) {
        if (chapterNumber[i] < AllQuestions.size()) {
            auto current_questions = AllQuestions[chapterNumber[i]].size();
            if (current_questions == 0) {
                swap(chapterNumber[i], chapterNumber[last]);
                --last;
                --i;
            }
            hasQuestions += current_questions;
        } else {
            swap(chapterNumber[i], chapterNumber[last]);
            --last;
            --i;
        }
    }
    chapterNumber.resize(last + 1);
    if (hasQuestions == 0) {
        cout << "Selected chapters don't have questions in them.\n";
        return {};
    }
    int chapterSize = static_cast<int>(chapterNumber.size()) - 1;
    while (numOfQuestions--) {
        int chapter = chapterNumber[uniform_int_distribution<int>{0, chapterSize}(seed)];
        int questionSize = static_cast<int>(AllQuestions[chapter].size()) - 1;
        int question = uniform_int_distribution<int>{0, questionSize}(seed);
        selectedQuestions.push_back(AllQuestions[chapter][question]);
    }
    return selectedQuestions;
}

int main(int argc, char **argv) {
    vector<vector<string>> AllQuestions;
    populateQuestions(AllQuestions);
    if (argc < 2) {
        printUsage(argv[0]);
        return 1;
    }
    vector<string> selectedQuestions;
    int numOfQuestions = 5;
    vector<int> chapterNumber;
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if ((arg == "-h") || (arg == "--help")) {
            printUsage(argv[0]);
            return 1;
        }
        if ((arg == "-c") || (arg == "--chapter")) {
            if (i == argc - 1) {
                cout << "No chapter specified." << endl;
                return 1;
            }
            chapterNumber = splitOnComma(argv[i + 1]);
        }
        if ((arg == "-q") || (arg == "--questions")) {
            if (i == argc - 1) {
                cout << "No questions specified." << endl;
                return 1;
            }
            numOfQuestions = stoi(argv[i + 1]);
        }
    }
    selectedQuestions = chooseQuestions(AllQuestions, numOfQuestions, chapterNumber);
    for (auto q : selectedQuestions) {
        cout << q << endl;
        cout << endl;
    }
    return 0;
}
