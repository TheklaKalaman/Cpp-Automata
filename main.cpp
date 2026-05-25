#include <iostream>
#include "plantMachine.hpp"


int main() {

    State state = step(State::OFF, Event::pow);
    std::cout << to_string(state) << std::endl;

    return 0;
}