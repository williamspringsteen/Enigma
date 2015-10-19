#ifndef MAPPER
#define MAPPER

class Mapper {
  public:
    virtual char map(char input) = 0;
    int convertCharToInt(char letter);
    char convertIntToChar(int number);

};

#endif
