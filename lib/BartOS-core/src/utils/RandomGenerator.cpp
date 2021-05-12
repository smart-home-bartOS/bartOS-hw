
#include "utils/RandomGenerator.h"
#include <ctime>
#include <unistd.h>
#include <random>

const char *RandomGenerator::NUMBERS = "0123456789";
const char *RandomGenerator::ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const char *RandomGenerator::ALPHANUM = "0123456789"
                                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                        "abcdefghijklmnopqrstuvwxyz";

/* Copied from https://stackoverflow.com/a/440240 */
string RandomGenerator::random(const int len, const char *set) {
    string tmp_s;

    srand((unsigned) time(NULL) * rand());

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i)
        tmp_s += set[rand() % (sizeof(set) - 1)];

    return tmp_s;
}

string RandomGenerator::randomNumber(const int len) {
    return random(len, NUMBERS);
}

string RandomGenerator::randomAlpha(const int len) {
    return random(len, ALPHA);
}

string RandomGenerator::randomAlphanum(const int len) {
    return random(len, ALPHANUM);
}