#include "state-string-end.h"

#include "lexical-analyser.h"

State* EndStringState::processComma(char c)
{
	lexicalAnalyser->addCharacter(c);
	return lexicalAnalyser->getCommaSeparatorState();
}

State* EndStringState::processColon(char c)
{
	lexicalAnalyser->addCharacter(c);
	return lexicalAnalyser->getColonSeparatorState();
}

State* EndStringState::processSeparator(char c)
{
	return lexicalAnalyser->getSimpleSeparatorState();
}

void EndStringState::finish() {}
