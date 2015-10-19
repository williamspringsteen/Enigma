#include "Rotor.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>

const int LETTERS_IN_ALPHABET = 26;

Rotor::Rotor(int rotorNum, char* rotorFileName) { //need to do rotorFile.open

  this->rotorNum = rotorNum;
  this->numEncrypted = 0;

  //TODO: NEED to free these arrays at some point, maybe use a shared or unique ptr
  this->numOfLetterToMapTo = new int[LETTERS_IN_ALPHABET];
  this->numOfLetterToMapToReversed = new int[LETTERS_IN_ALPHABET];
  for (int i = 0; i < 26; i++) {
    this->numOfLetterToMapTo[i] = 0;
    this->numOfLetterToMapToReversed[i] = 0;
  }
  //displacementToMapTo = new int[26];
  //letterToMapTo = new char[26];

  /*std::string number;
  number.clear();
  int i = 0;
  std::stringstream convert;
  while (rotorFile >> number) {
    if (!(convert >> number)) {
      number = 0;
      std::cout << "Error reading number" << std::endl;
    }
    numOfLetterToMapTo[i] = number;        //CHECK EVERY ELEMENT ISN'T SAME
                                           //AS NUMBER IS ALWAYS USED
    number.clear();
    i++
  }*/

  std::ifstream rotorFile;
  rotorFile.open(rotorFileName);

  //Reads each number from rotor file and puts into an array of size 26
  int i = 0;
  int number;
  std::string stringNumber;
//  std::cout << "numOfLetterToMapTo = [";
  while ((rotorFile >> stringNumber) && (i < LETTERS_IN_ALPHABET)) {
    std::istringstream ( stringNumber ) >> number;
    this->numOfLetterToMapTo[i] = number;
    if (i != 25) {
//      std::cout << number << ", ";
    } else {
//      std::cout << number << "]" << std::endl;
    }
    //stringNumber.clear();
    i++;
  }

//  std::vector <std::string> stringNumbers;
//  std::string stringNumber;
//  std::ifstream rotorFile(rotorFileName);
//  int i = 0;
//  while (rotorFile >> stringNumber) {
//    stringNumbers.push_back(stringNumber);
//    std::cout << "numOfLetterToMapTo[" << i << "] == " << stringNumber << std::endl;
//    i++;
//  }
//  rotorFile.close();

  //Makes the array like the one above, but for going backwards from the
  //reflector back to the plugboard
  this->numOfLetterToMapToReversed[0] = 1;
  //int a = sizeof(this->numOfLetterToMapTo); int b = sizeof(this->numOfLetterToMapTo[0]); int c = a / b; int d = sizeof(this->numOfLetterToMapToReversed); int e = sizeof(this->numOfLetterToMapToReversed[0]); int f = d / e;
  for (int i = 0; i < LETTERS_IN_ALPHABET; i++) {
    this->numOfLetterToMapToReversed[this->numOfLetterToMapTo[i]] = i;
  }

}

char Rotor::map(char input) {
//  std::cout << "\nIN ROTOR MAPPING FUNCTION. MAPPING: " << input << std::endl;
  int inputNumber = Mapper::convertCharToInt(input);
//  std::cout << "This corresponds to the number " << inputNumber << std::endl;
  //int offset = (int) (numEncrypted / (26 * (rotorNum + 1)));
  int offset = ((int) (numEncrypted / pow(LETTERS_IN_ALPHABET, rotorNum))) % LETTERS_IN_ALPHABET;
//  std::cout << "Offset is " << offset <<", because this rotor has encrypted " << numEncrypted << " letters so far." << std::endl;
  //inputNumber += offset;
  int outputNumber = this->numOfLetterToMapTo[(inputNumber + offset) % LETTERS_IN_ALPHABET];
//  std::cout << "Output number is " << outputNumber << " before offset added." << std::endl;
  outputNumber -= offset;
//  std::cout << "Output number is " << outputNumber << " after offset added." << std::endl;
  if (outputNumber < 0) {
    outputNumber += LETTERS_IN_ALPHABET;
//    std::cout << "ACTUALLY, outputNumber was negative, so new output number is " << outputNumber << std::endl;
  }
//  std::cout << "Output letter is: " << Mapper::convertIntToChar(outputNumber) << "\n" << std::endl;
  return Mapper::convertIntToChar(outputNumber);
}

char Rotor::reverseMap(char input) {
  int inputNumber = Mapper::convertCharToInt(input);
  //int offset = (int) (numEncrypted / (26 * (rotorNum + 1)));
  int offset = ((int) (numEncrypted / pow(LETTERS_IN_ALPHABET, rotorNum))) % LETTERS_IN_ALPHABET;
  //inputNumber += offset;
  int outputNumber = this->numOfLetterToMapToReversed[(inputNumber + offset) % LETTERS_IN_ALPHABET];
  outputNumber -= offset;
  if (outputNumber < 0) {
    outputNumber += LETTERS_IN_ALPHABET;
  }
  numEncrypted++; //Letter is only fully encrypted by a rotor once it passes back through that rotor
  return Mapper::convertIntToChar(outputNumber);
}

