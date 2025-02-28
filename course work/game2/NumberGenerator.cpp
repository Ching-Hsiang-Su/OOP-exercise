#include "NumberGenerator.h"
#include <cstdlib>
#include <ctime>

NumberGenerator::NumberGenerator(int min, int max) {
    srand(time(NULL));
    number = rand() % (max - min + 1) + min;
}

NumberGenerator::~NumberGenerator() {}

int NumberGenerator::getNumber() {
    return number;
}