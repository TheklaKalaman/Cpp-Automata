#include "DFA.hpp"

State step(const DFA& dfa, const State& state, Symbol symbol) {
    auto result = dfa.delta.find({state, symbol});

    if (result != dfa.delta.end()) {
        return result->second;
    }

    return "ERROR";
}

bool accepts(const DFA& dfa, const std::string& word) {
    State current = dfa.start;

    for (Symbol symbol : word) {
        current = step(dfa, current, symbol);
    }

    return dfa.accepting.find(current) != dfa.accepting.end();
}