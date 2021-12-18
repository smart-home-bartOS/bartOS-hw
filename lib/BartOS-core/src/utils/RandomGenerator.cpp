
#include "utils/RandomGenerator.h"

#include <unistd.h>

#include <ctime>
#include <random>

const char *RandomGenerator::NUMBERS = "0123456789";
const char *RandomGenerator::ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const char *RandomGenerator::ALPHANUM =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

/* Copied from https://stackoverflow.com/a/440240 */
std::string RandomGenerator::random(const int len, const char *set) {
    std::string tmp_s;

    srand((unsigned)time(NULL) * rand());

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i)
        tmp_s += set[rand() % (sizeof(set) - 1)];

    return tmp_s;
}

std::string RandomGenerator::randomNumber(const int len) {
    return random(len, NUMBERS);
}

std::string RandomGenerator::randomAlpha(const int len) {
    return random(len, ALPHA);
}

std::string RandomGenerator::randomAlphanum(const int len) {
    return random(len, ALPHANUM);
}