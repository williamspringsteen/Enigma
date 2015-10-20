#ifndef MAPPER
#define MAPPER

//Mapper is an abstract class, and Plugboard, Reflector, and Rotor will
//inherit all functions from Mapper, as they all involve a mapping
class Mapper {
  public:
    virtual char map(char input) = 0;
    int convertCharToInt(char letter);
    char convertIntToChar(int number);
};

#endif
