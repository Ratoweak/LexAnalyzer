#include "state-separator-simple.h"

#include "lexical-analyser.h"

State* SimpleSeparatorState::processLetter(char c)
{
	lexicalAnalyser->addCharacter(c);
	return lexicalAnalyser->getIdentifierState();
}

State* SimpleSeparatorState::processDigit(char c)
{
	lexicalAnalyser->addCharacter(c);
	return lexicalAnalyser->getDecimalNumberState();
}

State* SimpleSeparatorState::processMinus(char c)
{
	lexicalAnalyser->addCharacter(c);
	return lexicalAnalyser->getDecimalNumberState();
}

State* SimpleSeparatorState::processQuote(char c)
{
	return lexicalAnalyser->getStringState();
}

State* SimpleSeparatorState::processComma(char c)
{
	lexicalAnalyser->addCharacter(c);
	return lexicalAnalyser->getCommaSeparatorState();
}

State* SimpleSeparatorState::processColon(char c)
{
	lexicalAnalyser->addCharacter(c);
	return lexicalAnalyser->getColonSeparatorState();
}

State* SimpleSeparatorState::processSeparator(char c)
{
	return this;
}

void SimpleSeparatorState::finish() {}
