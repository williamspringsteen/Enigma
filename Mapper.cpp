#include "Mapper.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const int ASCII_VALUE_OF_A = 65;
const int LETTERS_IN_ALPHABET = 26;

//Converts 'A' to 0, 'B' to 1, 'C' to 2, ..., and 'Z' to 25
int Mapper::convertCharToInt(char letter) {
  int number = letter;
  number -= ASCII_VALUE_OF_A;
  return number;
}

//Converts 0 to 'A', 1 to 'B', 2 to 'C', ..., and 25 to 'Z'
char Mapper::convertIntToChar(int number) {
  int number_ = number;
  number_ += ASCII_VALUE_OF_A;
  char letter = number_;
  return letter;
}
