#ifndef STATE_NUMBER_DECIMAL_H
#define STATE_NUMBER_DECIMAL_H

#include "state-number.h"

class DecimalNumberState : public NumberState
{
public:
	DecimalNumberState(LexicalAnalyser* lexicalAnalyser) : NumberState(lexicalAnalyser, LexemType::DECIMAL_NUMBER) {}
	State* processLetter(char c);
};

#endif // STATE_NUMBER_DECIMAL_H
