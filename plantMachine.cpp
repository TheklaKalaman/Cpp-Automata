#include "plantMachine.hpp"
#include <map>
#include <utility>

DFA makePlantMachine() {
    DFA plantMachine;

    plantMachine.start = "OFF";
    plantMachine.accepting = {"OFF", "READY"};

    plantMachine.delta = {
        {{"OFF", 'p'}, "READY"}, //p = power
        {{"READY", 'p'}, "OFF"},
        {{"READY", 'w'}, "MEAS"}, //w = wake
        {{"MEAS", 'i'}, "READY"}, //i = ideal ohm
        {{"MEAS", 'h'}, "DRY"}, //h = high ohm
        {{"MEAS", 'l'}, "WET"}, //l = low ohm 
        {{"DRY", 'a'}, "PUMPING"}, //a = pump activated
        {{"PUMPING", 'o'}, "MEAS"}, //o = pump off
        {{"WET", 'x'}, "HI"} //x = drowning plant, need human intervention
    };

    return plantMachine;
}