#ifndef STATE_SEPARATOR_SIMPLE_H
#define STATE_SEPARATOR_SIMPLE_H

#include "state.h"

class SimpleSeparatorState : public State
{
public:
	SimpleSeparatorState(LexicalAnalyser* lexicalAnalyser) : State(lexicalAnalyser) {}
	State* processLetter(char c);
	State* processDigit(char c);
	State* processMinus(char c);
	State* processQuote(char c);
	State* processComma(char c);
	State* processColon(char c);
	State* processSeparator(char c);
	void finish();
};

#endif // STATE_SEPARATOR_SIMPLE_H
