#include "lexerMachine.hpp"

DFA makeLexerMachine() {
    DFA lexer;

    lexer.start = "START";
    lexer.accepting = {"ID"};

    lexer.delta = {
        {{"START", 'u'}, "ID"},
        {{"START", 'l'}, "ID"},
        {{"START", 'd'}, "ERROR"},
        {{"START", 'x'}, "ERROR"},

        {{"ID", 'u'}, "ID"},
        {{"ID", 'l'}, "ID"},
        {{"ID", 'd'}, "ID"},
        {{"ID", 'x'}, "ERROR"},

        {{"ERROR", 'u'}, "ERROR"},
        {{"ERROR", 'l'}, "ERROR"},
        {{"ERROR", 'd'}, "ERROR"},
        {{"ERROR", 'x'}, "ERROR"},
    };

    return lexer;
}