#include "Mapper.hpp"
#ifndef REFLECTOR
#define REFLECTOR

//Don't need a custom constructor for Reflector as it doesn't need
//information read from a file, so doesn't need to be constructed
//with a filename.
class Reflector : public Mapper {
  public:
    char map(char input);
};

#endif
