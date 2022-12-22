#include "lcs.h"
#include <vector>

using namespace std;

bool is_subsequence(string subsqn, const string& str) {
    if (str == "" || subsqn == "")
        return true;
    for (int i = int(str.size()) - 1; i > -1; i--) {
        if (str[i] == subsqn.back())
            subsqn.pop_back();
        if (subsqn == "")
            return true;
    }
    return false;
}

void iterate(std::string& choice) {
    for (int i = 0; i < choice.size(); i++) {
        if (choice[i] == '0') {
            choice[i] = '1';
            break;
        }
        else {
            choice[i] = '0';
        }
    }
}

string lcs(const string &first, const string &second) {
    // Naive algorithm
    string subsqn; 
    string str;
    if (first.size() <= second.size()) {
        subsqn = first;
        str = second;
    }
    else {
        subsqn = second;
        str = first;
    }
    const int size = subsqn.size();
    string choice; // String that indicates which letters are to be included in a subsequence
    choice.assign('0', size);
    const long long iterations = pow(2, size) + 1;
    string subsqn_i = ""; // String that goes through all possible subsequences of {subsqn}
    string result = "";
    for (long long i = 0; i < iterations; i++) {
        for (int j = 0; j < size; j++) {
            if (choice[j] == '1') {
                subsqn_i += subsqn[j];
            }
        }
        if (subsqn_i.size() > result.size()) {
            if (is_subsequence(subsqn_i, str))
                result = subsqn_i;
        }
        subsqn_i = "";
        iterate(choice);
    }
    return result;
     
    // Using dynamic programming
    /*if (first == "" || second == "")
        return "";
    string o_first = '0' + first;
    string o_second = '0' + second;
    int N = int(o_first.size());
    int M = int(o_second.size());
    vector<string> LCS(N*M, "");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 || j == 0)
                LCS[i * M + j] = "";
            else {
                if (o_first[i] == o_second[j])
                    LCS[i * M + j] = LCS[i * M - M + j - 1] + o_first[i];
                if (o_first[i] != o_second[j]) {
                    if (LCS[i * M - M + j].size() >= LCS[i * M + j - 1].size())
                        LCS[i * M + j] = LCS[i * M - M + j];
                    else
                        LCS[i * M + j] = LCS[i * M + j - 1];
                }
            }
        }
    }
    return LCS[M * N - 1];*/
    
}