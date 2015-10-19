// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include <cctype>

// ./enigma rotors/I.rot rotors/II.rot plugboard/null.pb
// argc = 4     argv = ["enigma", "rotors/I.rot", "rotors/II.rot", "plugboard/null.pb"]
using namespace std;

int main(int argc, char **argv) {                      //Need to make a rotor array of size argc - 2, then use loop to fill it up :)
                                                       //rotor0 = Rotor(0, argv[1])
  //std::cout << "Hi" << std::endl;
  assert(argc > 1); //Must have at least program name and plugboard file

  //Rotor rotors[argc - 2];
  std::vector<Rotor> rotors(argc - 2, Rotor(0, argv[1]));
  rotors.clear();

//  std::ifstream test;
//  char* testName;
//  for (int i = 1; i < (argc); i++) {
//    testName = argv[i];
//    test.open(testName);
//    if (!test.good()) {
//      test.close();
//      std::cout << "YOU FAILED" << std::endl;
//      return 1;
//    }
//    test.clear();
//    test.close();
//    test.clear();
//  }
//TODO: Invalid rotor file checking
  //char** rotorFileNames = new char*[argc - 2];
//  std::ifstream rotorTestFile(argv[1]);
  for (int i = 1; i < (argc - 1); i++) {
//    std::ifstream rotorTestFile(argv[i]);
//    if (rotorTestFile.good()) {
//      rotorTestFile.close();
//      std::cout << "Invalid rotor file in argument " << (i + 1) << "." << std::endl;
//      return 1;
//    }
//    std::cout << argv[i] << "is a correct file name." << std::endl;
//    rotorTestFile.close();
    //argv[i] = rotorFileNames[i - 1];
    //rotors[i - 1] = Rotor(i - 1, argv[i]);
    rotors.push_back(Rotor(i - 1, argv[i]));
//    std::cout << "Just made Rotor(" << (i - 1) << ", " << argv[i] << ")" << std::endl;
  }



  char* plugboardFileName = argv[argc - 1];

  std::ifstream plugboardTestFile(plugboardFileName);
  std::cout << plugboardTestFile.goodbit << std::endl<< plugboardTestFile.eofbit << std::endl<< plugboardTestFile.badbit << std::endl << plugboardTestFile.failbit << std::endl;
  if (!plugboardTestFile.good()) {
    plugboardTestFile.close();
    std::cout << "Invalid plugboard file." << std::endl;
    return 1;
  }
  plugboardTestFile.close();

  Plugboard plugboard = Plugboard(plugboardFileName);

  Reflector reflector;

  char letterToEncrypt;
  //cin >> ws;
                     //'fclose(stdin)' will close stdin
  while (true) {     //Change to 'while(is_open(stdin))' IF I CAN FIGURE OUT HOW TO DO THIS
    cin >> letterToEncrypt;  //TODO: Check it is a capital letter or character to ignore
    if (!((letterToEncrypt <= 'A' || letterToEncrypt >= 'Z') && !(letterToEncrypt == ' ' || letterToEncrypt == '\n' || letterToEncrypt == '\t' || letterToEncrypt == '\r'))) {
      std::cout << "Invalid character." << std::endl;
      return 1;
    }
    if (!isupper(letterToEncrypt) && !(letterToEncrypt == ' ' || letterToEncrypt == '\n' || letterToEncrypt == '\t' || letterToEncrypt == '\r')) {
      std::cout << "Is a letter" << std::endl;
    }
    if (!isupper(letterToEncrypt)) {
      if (!(letterToEncrypt == ' ')) {
        std::cout << "Invalid character." << std::endl;
        return 1;
      }
      if (!(letterToEncrypt == '\n')) {
        std::cout << "Invalid character." << std::endl;
        return 1;
      }
      if (!(letterToEncrypt == '\t')) {
        std::cout << "Invalid character." << std::endl;
        return 1;
      }
      if (!(letterToEncrypt == '\r')) {
        std::cout << "Invalid character." << std::endl;
        return 1;
      }
    }
    //cin >> ws;  //TODO: GETS RID OF WHITESPACE
//    std::cout << "Entered: " << letterToEncrypt << std::endl;
    letterToEncrypt = plugboard.map(letterToEncrypt);
//    std::cout << "After first plugboard map: " << letterToEncrypt << std::endl;
    for (int i = 0; i < (argc - 2); i++) {
      letterToEncrypt = rotors[i].map(letterToEncrypt);
//      std::cout << "After going through rotor " << i << ": " << letterToEncrypt << std::endl;
    }
    letterToEncrypt = reflector.map(letterToEncrypt);
//    std::cout << "After reflector: " << letterToEncrypt << std::endl;
    for (int i = (argc - 3); i >= 0; i--) {
      letterToEncrypt = rotors[i].reverseMap(letterToEncrypt);
//      std::cout << "After coming back through rotor " << i << ": " << letterToEncrypt << std::endl;
    }
    letterToEncrypt = plugboard.map(letterToEncrypt);
//    std::cout << "After second plugboard map: " << letterToEncrypt << std::endl;
//    std::cout << "Encrypted to " << letterToEncrypt << std::endl; //TODO: Take out this text
    std::cout << letterToEncrypt << std::endl;
  }

  return 0;
}
