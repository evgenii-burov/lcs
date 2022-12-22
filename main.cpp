#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include <random>
#include <chrono>

#include "lcs.h"

std::string random_string(int size) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(97, 122);
    std::string result;
    int num;
    for (int i = 0; i < size; i++) {
        result.push_back(char(distribution(generator)));
    }
    return result;
}

int main(int argc, char* argv[]) {
    int result = Catch::Session().run(argc, argv);
    return result;
    //int size = (argc > 1 ? std::stoi(argv[1]) : 10);
    //std::string first = random_string(size);
    //std::string second = random_string(size);
    //
    //auto t1 = std::chrono::high_resolution_clock::now();
    //std::string result = lcs(first, second);
    //auto t2 = std::chrono::high_resolution_clock::now();
    //auto time = std::chrono::duration<double>(t2 - t1).count();
    //std::cout << result << '\n';
    //std::cout << "SIZE: " << size << '\n';
    //std::cout << "TIME: " << time;
}