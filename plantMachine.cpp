#include "plantMachine.hpp"
#include <map>
#include <utility>


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
