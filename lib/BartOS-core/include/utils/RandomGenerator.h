#ifndef NUMBER_GENERATOR_H
#define NUMBER_GENERATOR_H

#include <string>
using std::string;

class RandomGenerator {
   private:
    static string random(const int len, const char *set);

   public:
    static const char *NUMBERS;
    static const char *ALPHA;
    static const char *ALPHANUM;

    static string randomNumber(const int len);

    static string randomAlpha(const int len);

    static string randomAlphanum(const int len);
};

#endif  // NUMBER_GENERATOR_H