#include <iostream>
#include <string>
#include <cmath>    // abs()

#include "WordFrequency.h"
using std::string;
using std::cout;
using std::endl;

// Global static variables
static int testCount = 0;
//static const int testTotal = 7;
static const string GREEN = "\033[32m";
static const string RED = "\033[31m";
static const string RESET = "\033[0m";

// Prototypes
bool assertTrue(const string& nameOfTest, bool actual);
bool assertEquals(const string & nameOfTest, double expected, double actual);

template <typename T, typename U>
bool assertEquals(const string & nameOfTest, const T & expected, const U & actual);

template <typename T, typename U>
bool assertEquals(const string & nameOfTest, const T & expected, const U & actual, unsigned delta);

// Main
int main() {

    WordFrequency Spot;
    Spot.readIn("spot.txt");
    assertEquals("numberOfWords: Spot", 3, Spot.numberOfWords());
    assertEquals("wordCount: spot", 3, Spot.wordCount("spot"));
    assertEquals("wordCount: run", 4, Spot.wordCount("run"));
    assertEquals("mostFrequentWord: Spot", "run", Spot.mostFrequentWord());
    assertEquals("maxBucketSize: Spot", 3, Spot.maxBucketSize(), 2);

    WordFrequency Frankenstein;
    Frankenstein.readIn("Frankenstein or The Modern Prometheus by Mary Shelley.txt");
    assertEquals("numberOfWords: Frankenstein", 9787, Frankenstein.numberOfWords());
    assertEquals("wordCount: Frankenstein", 16, Frankenstein.wordCount("Frankenstein"));
    assertEquals("wordCount: life", 90, Frankenstein.wordCount("life"));
    assertEquals("wordCount: feared", 13, Frankenstein.wordCount("feared"));
    assertEquals("wordCount: the", 3903, Frankenstein.wordCount("the"));
    assertEquals("mostFrequentWord: Frankenstein", "the", Frankenstein.mostFrequentWord());
    assertEquals("maxBucketSize: Frankenstein", 7, Frankenstein.maxBucketSize(), 1);

    WordFrequency SleepyHollow;
    SleepyHollow.readIn("The Legend of Sleep Hollow by Washington Irving.txt");
    assertEquals("numberOfWords: Sleep Hollow", 3811, SleepyHollow.numberOfWords());
    assertEquals("wordCount: Ichabod", 36, SleepyHollow.wordCount("Ichabod"));
    assertEquals("wordCount: the", 865, SleepyHollow.wordCount("the"));
    assertEquals("mostFrequentWord: Sleep Hollow", "the", SleepyHollow.mostFrequentWord());
    assertEquals("maxBucketSize: Sleep Hollow", 6, SleepyHollow.maxBucketSize(), 1);

    return 0;
}

// Helper Functions
bool assertTrue(const string& nameOfTest, bool actual) {
    if (actual == true) {
        // Green colored text
        cout << GREEN << "PASSED "
             << RESET << nameOfTest << ": test successfully resulted in 'true'" << endl;
        testCount++;
        return true;
    }
    // Red colored text
    cout << RED << "FAILED "
         << RESET << nameOfTest << ": test unsuccessfully resulted in 'false'" << endl;
    return false;
}

bool assertEquals(const string& nameOfTest, double expected, double actual) {
    if (std::abs(expected - actual) < 0.005)  {
        // Green colored text
        cout << GREEN << "PASSED "
             << RESET << nameOfTest << ": expected and actual '" << actual << "'" << endl;
        testCount++;
        return true;
    }
    // Red colored text
    cout << RED << "FAILED "
         << RESET << nameOfTest << ": expected '" << expected << "'' but actual '" << actual << "'" << endl;
    return false;
}

template <typename T, typename U>
bool assertEquals(const string& nameOfTest, const T& expected, const U& actual) {
    if (expected == actual) {
        // Green colored text
        cout << GREEN << "PASSED "
             << RESET << nameOfTest << ": expected and actual '" << actual << "'" << endl;
        testCount++;
        return true;
    }
    // Red colored text
    cout << RED << "FAILED "
         << RESET << nameOfTest << ": expected '" << expected << "' but actually '" << actual << "'" << endl;
    return false;
}

template <typename T, typename U>
bool assertEquals(const string& nameOfTest, const T& expected, const U& actual, unsigned delta) {
    T minValue = (expected < delta)? 0: (expected-delta);
    T maxValue = expected+delta;
    if ((actual >= minValue) && (actual <= maxValue)) {
        // Green colored text
        cout << GREEN << "PASSED "
          << RESET << nameOfTest << ": expected '" << expected << "' close to actual '" << actual << "'" << endl;
        testCount++;
        return true;
    }
    // Red colored text
    cout << RED << "FAILED "
         << RESET << nameOfTest << ": expected '" << expected << "' but actually '" << actual << "'" << endl;
    return false;
}
