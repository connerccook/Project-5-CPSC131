#include <iostream>
#include <fstream>
#include "WordFrequency.h"
#include "sanitize.h"
using namespace std;

WordFrequency::WordFrequency() {} //default constructor

void WordFrequency::readIn(const string & filename) {
  ifstream fin(filename);
  string word;
  while (fin >> word) { // if there is a word, then read it in
    sanitize(word); //takes out unnecessary punctuations
    char punc = word[word.size() - 1];
    if(punc == '!' || punc == '.' || punc == '?'){ //if word ends with punctuation then take it out
      word = word.substr(0, word.size() - 1);
    }
    if (hash.count(word) == 0) { // if the word is not in the hashtable
      hash[word] = 1;
    } else { //if word exists, increase word frequncy
      hash.at(word) += 1;
    }
  }
}

size_t WordFrequency::numberOfWords() { //return number of words in hashtable
  return hash.size();
}
size_t WordFrequency::wordCount(const string & word) { // return the number of occurrences of the given word
  return hash[word];
}
string WordFrequency::mostFrequentWord() {// return the most frequent word
  unordered_map<string,int>::iterator it = hash.begin();
  string mostFrequent = it->first;
  while (it!=hash.end()) {
    if (hash[mostFrequent] < hash[it->first]) {
      mostFrequent = it->first;
    }
    it++;
  }
  return mostFrequent;
}
size_t WordFrequency::maxBucketSize() {
  size_t largest = 0;
  for (int i = 0; i < hash.bucket_count(); i++) {
    if (hash.bucket_size(i) > largest) {
      largest = hash.bucket_size(i);
    }
  }
  return largest;
}
