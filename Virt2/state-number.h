#ifndef STATE_NUMBER_H
#define STATE_NUMBER_H

#include "lexem.h"
#include "state.h"

class NumberState : public State
{
protected:
	LexemType lexemType;
public:
	NumberState(LexicalAnalyser* lexicalAnalyser, LexemType lexemType);
	State* processLetter(char c) = 0;
	State* processDigit(char c);
	State* processComma(char c);
	State* processColon(char c);
	State* processSeparator(char c);
	void finish();
};

#endif // STATE_NUMBER_H
