#ifndef STATE_STRING_END_H
#define STATE_STRING_END_H

#include "state.h"

class EndStringState : public State
{
public:
	EndStringState(LexicalAnalyser* lexicalAnalyser) : State(lexicalAnalyser) {}
	State* processComma(char c);
	State* processColon(char c);
	State* processSeparator(char c);
	void finish();
};

#endif // STATE_STRING_END_H
