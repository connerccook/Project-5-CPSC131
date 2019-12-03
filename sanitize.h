#pragma once
#include <string>
#include <iostream>

void sanitize(std::string &);
bool shouldFilter(const char &);

// Sanitizes a given word by removing non-essential characters from the start
// and end.
void sanitize(std::string & word) {
    size_t start_index = 0;
    size_t end_index = word.size() - 1;

    while(shouldFilter(word[start_index])) {
        start_index++;
    }

    while(shouldFilter(word[end_index])) {
        end_index--;
    }

    if (start_index != 0 || end_index != word.size() - 1) {
        word = word.substr(start_index, end_index);
    }
}


// Returns true if character should be filtered out.
bool shouldFilter(const char & target) {
    char bad_char[] = { ' ', '_', '-', '\"', '\'', '(', ')' };

    for (unsigned int i = 0; i < 7; ++i) {
        if (target == bad_char[i]) {
            return true;
        }
    }

    return false;
}
