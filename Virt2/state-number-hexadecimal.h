#ifndef STATE_NUMBER_HEXADECIMAL_H
#define STATE_NUMBER_HEXADECIMAL_H

#include "state-number.h"

class HexadecimalNumberState : public NumberState
{
public:
	HexadecimalNumberState(LexicalAnalyser* lexicalAnalyser) : NumberState(lexicalAnalyser, LexemType::HEXADECIMAL_NUMBER) {}
	State* processLetter(char c);
};

#endif // STATE_NUMBER_HEXADECIMAL_H
