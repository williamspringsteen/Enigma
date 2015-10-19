#include "Reflector.hpp"
#include <iostream>
#include <fstream>

const int LETTERS_IN_ALPHABET = 26;

char Reflector::map(char input) {
  int inputNumber = Mapper::convertCharToInt(input);
  int outputNumber = (inputNumber + 13) % LETTERS_IN_ALPHABET;
  return Mapper::convertIntToChar(outputNumber);
}
