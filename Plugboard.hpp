#include "Mapper.hpp"
#ifndef PLUGBOARD
#define PLUGBOARD

class Plugboard : public Mapper {
  public:
    Plugboard(char* plugboardFileName);
    char map(char input);
    void deleteArrays(void);
  private:
    //plugboardMappings array is 26 chars long.
    //Each index in array is one of the characters between 'A' and 'Z'
    //inclusive. Every letter appears once and only once in array.
    //If only D and F are switched, the array will look like:
    //['A', 'B', 'C', 'F', 'E', 'D', 'G', ..., 'Z'].
    //Since all letters apart from D and F are in the 'correct' place,
    //they will be mapped to themselves by the plugboard, but since
    //D and F are switched, D maps to F, and F maps to D.
    char* plugboardMappings;
};

#endif
