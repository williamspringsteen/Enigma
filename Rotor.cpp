#include "Rotor.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>

const int LETTERS_IN_ALPHABET = 26;

Rotor::Rotor(int rotorNum, char* rotorFileName) {

  this->rotorNum = rotorNum;
  this->numEncrypted = 0;

  //TODO: NEED to free these arrays at some point, maybe use a shared or unique ptr
  this->numOfLetterToMapTo = new int[LETTERS_IN_ALPHABET];
  this->numOfLetterToMapToReversed = new int[LETTERS_IN_ALPHABET];
  for (int i = 0; i < 26; i++) {
    this->numOfLetterToMapTo[i] = 0;
    this->numOfLetterToMapToReversed[i] = 0;
  }

  std::ifstream rotorFile;
  rotorFile.open(rotorFileName);

  //Reads each number from rotor file and puts into an array of size 26
  int i = 0;
  int number;
  std::string stringNumber;
  while ((rotorFile >> stringNumber) && (i < LETTERS_IN_ALPHABET)) {
    std::istringstream ( stringNumber ) >> number;
    this->numOfLetterToMapTo[i] = number;
    i++;
  }

  //Makes the array like the one above, but for going backwards from the
  //reflector back to the plugboard
  for (int i = 0; i < LETTERS_IN_ALPHABET; i++) {
    this->numOfLetterToMapToReversed[this->numOfLetterToMapTo[i]] = i;
  }

}

char Rotor::map(char input) {
  int inputNumber = Mapper::convertCharToInt(input);
  int offset = ((int) (numEncrypted / pow(LETTERS_IN_ALPHABET, rotorNum))) % LETTERS_IN_ALPHABET;
  int outputNumber = this->numOfLetterToMapTo[(inputNumber + offset) % LETTERS_IN_ALPHABET];
  outputNumber -= offset;
  //The below if statement ensures that if outputNumber was made negative by
  //above line, it will now be positive, and will 'wrap around' when going
  //past zero.
  if (outputNumber < 0) {
    outputNumber += LETTERS_IN_ALPHABET;
  }
  return Mapper::convertIntToChar(outputNumber);
}

char Rotor::reverseMap(char input) {
  int inputNumber = Mapper::convertCharToInt(input);
  int offset = ((int) (numEncrypted / pow(LETTERS_IN_ALPHABET, rotorNum))) % LETTERS_IN_ALPHABET;
  int outputNumber = this->numOfLetterToMapToReversed[(inputNumber + offset) % LETTERS_IN_ALPHABET]; //TODO: Make each line less than 80 characters
  outputNumber -= offset;
  if (outputNumber < 0) {
    outputNumber += LETTERS_IN_ALPHABET;
  }
  //Letter is only fully encrypted by a rotor once
  //it passes back through that rotr
  numEncrypted++;
  return Mapper::convertIntToChar(outputNumber);
}

//Deletes the arrays declared with the 'new' keyword
void Rotor::deleteArrays() {
  delete[] numOfLetterToMapTo;
  delete[] numOfLetterToMapToReversed;
}
