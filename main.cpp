#include <iostream>
#include <vector>
#include "plantMachine.hpp"
#include "lexerMachine.hpp"

int main() {

    DFA lexer = makeLexerMachine();
    DFA plantMachine = makePlantMachine();

    std::cout << accepts(lexer, "lud") << "\n"; // accepting
    std::cout << accepts(lexer, "dll") << "\n"; // not accepting
    std::cout << accepts(plantMachine, "pwi") << "\n"; // accepting
    std::cout << accepts(plantMachine, "pwlx") << "\n"; // not accepting

    return 0;
}