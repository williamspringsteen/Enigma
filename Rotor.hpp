#include "Mapper.hpp"
#ifndef ROTOR
#define ROTOR

class Rotor : public Mapper {
  public:
    Rotor(int rotorNum, char* rotorFileName);
    char map(char input);
    char reverseMap(char input);
    void deleteArrays(void);
  private:
    //rotor 0 will have rotorNum = 0
    int rotorNum;
    //If 'A' is passed to map, and 'B' should be output (Before the rotors
    //have rotated), index 0 (Corresponding to 'A') of numLetterToMapTo should
    //be the number 1 (Corresponding to 'B').
    int* numOfLetterToMapTo;
    //numOfLeterToMapToReversed is the same as numOfLetterToMapTo, but for
    //the other side of the rotors, for when the letter is being encrypted
    //after hitting the reflector.
    int* numOfLetterToMapToReversed;
    int numEncrypted;
};

#endif
