#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <limits> // Required for numeric_limits
#include <list> // For Question 7

// --- Question 1 ---
// Implements the function to return the longest string matching the given conditions:
// 1. Non-repetitive identical characters (e.g., 'AABCD' is not valid due to 'AA').
// 2. Contains only characters from a given list of valid characters.
std::string getLongestString(const std::string& validCharacters, const std::vector<std::string>& strings) {
    // Use a set for efficient lookup of valid characters.
    std::set<char> validCharsSet(validCharacters.begin(), validCharacters.end());
    std::string longestValidString = ""; // Initialize with an empty string

    // Iterate through each string in the input array.
    for (const std::string& s : strings) {
        bool isValid = true; // Flag to track if the current string is valid

        // Condition 1: Check for repetitive identical characters.
        for (size_t i = 0; i < s.length(); ++i) {
            // If the current character is the same as the next character, it's invalid.
            if (i + 1 < s.length() && s[i] == s[i+1]) {
                isValid = false;
                break; // No need to check further, move to the next string.
            }
        }

        // If the string failed condition 1, skip to the next string.
        if (!isValid) {
            continue;
        }

        // Condition 2: Check if all characters are in the valid characters list.
        for (char c : s) {
            // If a character is not found in the valid characters set, it's invalid.
            if (validCharsSet.find(c) == validCharsSet.end()) {
                isValid = false;
                break; // No need to check further, move to the next string.
            }
        }

        // If the string is valid (passed both conditions).
        if (isValid) {
            // Compare its length with the current longest valid string.
            if (s.length() > longestValidString.length()) {
                longestValidString = s; // Update if the current string is longer.
            }
        }
    }
    return longestValidString; // Return the longest valid string found.
}