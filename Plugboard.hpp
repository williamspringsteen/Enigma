#include "Mapper.hpp"
#ifndef PLUGBOARD
#define PLUGBOARD

class Plugboard : public Mapper {
  public:
    Plugboard(char* plugboardFileName);
    char map(char input);
  private:
    char* plugboardMappings;
};

#endif
