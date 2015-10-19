#include "Mapper.hpp"
#ifndef ROTOR
#define ROTOR

class Rotor : public Mapper {
  public:
    Rotor(int rotorNum, char* rotorFileName);
    char map(char input);
    char reverseMap(char input);
  private:
    int rotorNum;
    int* numOfLetterToMapTo;
    int* numOfLetterToMapToReversed;
    int numEncrypted;
};

#endif
