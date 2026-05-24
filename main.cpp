#include <iostream>
#include <map>
#include <utility>
#include <string>

enum class State {
    OFF, READY, MEAS, DRY, PUMPING, WET, HI, ERROR
};

enum class Event {
    pow, wake, ohmi, ohmh, ohmn, pumpa, pumpo, hi
};

std::map<std::pair<State, Event>, State> delta = {
    {{State::OFF, Event::pow}, State::READY},
    {{State::READY, Event::pow}, State::OFF},
    {{State::READY, Event::wake}, State::MEAS},
    {{State::MEAS, Event::ohmi}, State::READY},
    {{State::MEAS, Event::ohmh}, State::DRY},
    {{State::MEAS, Event::ohmn}, State::WET},
    {{State::DRY, Event::pumpa}, State::PUMPING},
    {{State::PUMPING, Event::pumpo}, State::MEAS},
    {{State::WET, Event::hi}, State::HI},
};

std::string to_string(State state) {
    switch (state) {
        case State::OFF:    return "OFF";
        case State::READY:  return "READY";
        case State::MEAS:   return "MEAS";
        case State::DRY:    return "DRY";
        case State::PUMPING:return "PUMPING";
        case State::WET:    return "WET";
        case State::HI:     return "HI";
        case State::ERROR:  return "ERROR";
    }
    return "UNKNOWN";
}

State step(State state, Event event) {
    auto key = std::make_pair(state, event);

    auto result = delta.find(key);

    if (result != delta.end()) {
        return result->second;
    }

    return State::ERROR;
}


int main() {

    State state = step(State::OFF, Event::pow);

    std::cout << to_string(state) << std::endl;

    return 0;
}