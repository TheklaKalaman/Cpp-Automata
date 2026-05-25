#pragma once

#include <string>

enum class State {
    OFF, READY, MEAS, DRY, PUMPING, WET, HI, ERROR
};

enum class Event {
    pow, wake, ohmi, ohmh, ohmn, pumpa, pumpo, hi
};

std::string to_string(State state);

State step(State state, Event event);