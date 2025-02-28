#ifndef NUMBERGENERATOR_H
#define NUMBERGENERATOR_H

class NumberGenerator {
private:
    int number;
public:
    NumberGenerator(int min, int max);
    ~NumberGenerator();
    int getNumber();
};

#endif