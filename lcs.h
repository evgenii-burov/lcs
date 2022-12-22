#pragma once

#include <string>

// Iterate to the next choice of letters that are to be included in a subsequence.
void iterate(std::string& choice);

// Determine if {subsqn} is a subsequence of {str}.
bool is_subsequence(std::string subsqn, const std::string& str);

// Find the longest common subsequence of two strings.
std::string lcs(const std::string &first, const std::string &second);
