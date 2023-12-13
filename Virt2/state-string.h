#ifndef STATE_STRING_H
#define STATE_STRING_H

#include "state.h"

class StringState : public State
{
public:
	StringState(LexicalAnalyser* lexicalAnalyser) : State(lexicalAnalyser) {}
	State* processLetter(char c);
	State* processDigit(char c);
	State* processMinus(char c);
	State* processQuote(char c);
	State* processComma(char c);
	State* processColon(char c);
	State* processSeparator(char c);
	State* processCharacter(char c);
	void finish();
};

#endif // STATE_STRING_H
