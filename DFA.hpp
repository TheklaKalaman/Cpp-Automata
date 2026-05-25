#pragma once

#include <map>
#include <set>
#include <string>
#include <utility>

using State = std::string;
using Symbol = char;

struct DFA {
    State start; //Startzustand
    std::set<State> accepting; //Menge der Endzustände
    std::map<std::pair<State, Symbol>, State> delta; //Übergangstabelle
};

State step(const DFA& dfa, const State& state, Symbol symbol);

bool accepts(const DFA& dfa, const std::string& word);