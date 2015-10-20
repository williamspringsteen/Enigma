#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include <cctype>

// Example arguments
// ./enigma rotors/I.rot rotors/II.rot plugboard/null.pb
// argc = 4
// argv = ["enigma", "rotors/I.rot", "rotors/II.rot", "plugboard/null.pb"]

int main(int argc, char **argv) {

  assert(argc > 1); //Must have at least program name and plugboard file

  std::vector<Rotor> rotors(argc - 2, Rotor(0, argv[1]));
  if (argc > 2) {
    rotors[0].deleteArrays();
  }
  rotors.clear();

  for (int i = 1; i < (argc - 1); i++) {
    //Check if any rotor file is invalid
    std::ifstream rotorTestFile(argv[i]);
    if (!rotorTestFile.good()) {
      rotorTestFile.close();
      std::cout << "Invalid rotor file in argument " << i << "." << std::endl;
      return 1;
    }
    rotorTestFile.close();
    //Rotor(0, argv[1]) is constructor for the 0th rotor, with filename argv[1]
    rotors.push_back(Rotor(i - 1, argv[i]));
  }

  char* plugboardFileName = argv[argc - 1];

  //Check if plugboard file is invalid
  std::ifstream plugboardTestFile(plugboardFileName);
  if (!plugboardTestFile.good()) {
    plugboardTestFile.close();
    std::cout << "Invalid plugboard file." << std::endl;
    return 1;
  }
  plugboardTestFile.close();

  Plugboard plugboard = Plugboard(plugboardFileName);

  Reflector reflector;

  char letterToEncrypt;

  //cin will strip whitespace, no need here for cin >> ws
  //Breaks out of this loop when 'Ctrl-D' pressed (for stdin)
  //or when end of file is reached.
  while (std::cin >> letterToEncrypt) {

    //Check that input letter is only an upper case letter or
    //a space, carriage return, horizontal tab, or newline
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

    //Letter will go through plugboard, rotors, reflector, back through rotors
    //in reverse order, and then through plugboard again, before being output.
    letterToEncrypt = plugboard.map(letterToEncrypt);
    for (int i = 0; i < (argc - 2); i++) {
      letterToEncrypt = rotors[i].map(letterToEncrypt);
    }
    letterToEncrypt = reflector.map(letterToEncrypt);
    for (int i = (argc - 3); i >= 0; i--) {
      letterToEncrypt = rotors[i].reverseMap(letterToEncrypt);
    }
    letterToEncrypt = plugboard.map(letterToEncrypt);

    //Encrypted message printed as one line of letters, e.g. "URTYVWQUE"
    std::cout << letterToEncrypt;

  }

  plugboard.deleteArrays();
  for (int i = 0; i < (argc - 2); i++) {
    rotors[i].deleteArrays();
  }
  return 0;
}
