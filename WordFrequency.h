#pragma once
#include <string>
#include <unordered_map>

using std::string;

class WordFrequency {
private:
    // TO BE COMPLETED

public:
    WordFrequency(); // default constructor
    void readIn(const string & filename); // add words from file to hash table
    size_t numberOfWords(); // return the number of unique words
    size_t wordCount(const string & word); // return the number of occurrences of the given word
    string mostFrequentWord(); // return the most frequent word
    size_t maxBucketSize(); // return the size of the largest bucket in the hash table
};
