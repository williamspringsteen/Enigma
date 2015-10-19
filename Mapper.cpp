#include "Mapper.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const int ASCII_VALUE_OF_A = 65;
const int LETTERS_IN_ALPHABET = 26;

int Mapper::convertCharToInt(char letter) {
  int number = letter;
  number -= ASCII_VALUE_OF_A;
  return number;
}

char Mapper::convertIntToChar(int number) {
  int number_ = number;
  number_ += ASCII_VALUE_OF_A;
  char letter = number_;
  return letter;
}
