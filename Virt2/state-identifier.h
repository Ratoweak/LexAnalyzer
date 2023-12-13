#ifndef STATE_IDENTIFIER_H
#define STATE_IDENTIFIER_H

#include "state.h"

class IdentifierState : public State
{
public:
	IdentifierState(LexicalAnalyser* lexicalAnalyser) : State(lexicalAnalyser) {}
	State* processLetter(char c);
	State* processDigit(char c);
	State* processComma(char c);
	State* processColon(char c);
	State* processSeparator(char c);
	void finish();
};

#endif // STATE_IDENTIFIER_H
