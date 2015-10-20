#include "Plugboard.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>

const int LETTERS_IN_ALPHABET = 26;

Plugboard::Plugboard(char* plugboardFileName) {

  this->plugboardMappings = new char[LETTERS_IN_ALPHABET];

  std::ifstream plugboardFile;
  plugboardFile.open(plugboardFileName);

  for (int i = 0; i < LETTERS_IN_ALPHABET; i++) {
    plugboardMappings[i] = Mapper::convertIntToChar(i); //TODO: THIS IS WRONG, THIS WILL SWAP A AND B, C AND D, E AND F
  }

  std::string firstNumInPairStr;
  std::string secondNumInPairStr;

  int firstNumInPair;
  int secondNumInPair;

  //char firstNumInPairChar;
  //char secondNumInPairChar;

  while ((plugboardFile >> firstNumInPairStr) && (plugboardFile >> secondNumInPairStr)) {
    std::istringstream (firstNumInPairStr) >> firstNumInPair;
    std::istringstream (secondNumInPairStr) >> secondNumInPair;
    plugboardMappings[secondNumInPair] = Mapper::convertIntToChar(firstNumInPair);
    plugboardMappings[firstNumInPair] = Mapper::convertIntToChar(secondNumInPair);
    //firstNumInPairStr.clear();
    //secondNumInPairStr.clear();
  }


}

char Plugboard::map(char input) {
  return this->plugboardMappings[Mapper::convertCharToInt(input)];
}

void Plugboard::deleteArrays() {
  delete[] plugboardMappings;
}
