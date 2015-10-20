#include "Plugboard.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>

const int LETTERS_IN_ALPHABET = 26;

//Constructor just sets up the char[] plugboardMappings
Plugboard::Plugboard(char* plugboardFileName) {

  this->plugboardMappings = new char[LETTERS_IN_ALPHABET];

  std::ifstream plugboardFile;
  plugboardFile.open(plugboardFileName);

  //Set up identity mapping for all letters, will add in any other mapping
  //later in constructor
  for (int i = 0; i < LETTERS_IN_ALPHABET; i++) {
    plugboardMappings[i] = Mapper::convertIntToChar(i);
  }

  std::string firstNumInPairStr;
  std::string secondNumInPairStr;

  int firstNumInPair;
  int secondNumInPair;

  //Adds plugboard mappings that aren't identity mapping
  while ((plugboardFile >> firstNumInPairStr) && (plugboardFile >> secondNumInPairStr)) {
    std::istringstream (firstNumInPairStr) >> firstNumInPair;
    std::istringstream (secondNumInPairStr) >> secondNumInPair;
    plugboardMappings[secondNumInPair] = Mapper::convertIntToChar(firstNumInPair);
    plugboardMappings[firstNumInPair] = Mapper::convertIntToChar(secondNumInPair);
  }


}

char Plugboard::map(char input) {
  return this->plugboardMappings[Mapper::convertCharToInt(input)];
}

//Deletes the arrays declared with the 'new' keyword
void Plugboard::deleteArrays() {
  delete[] plugboardMappings;
}
