#include "state-string.h"

#include "lexical-analyser.h"

State* StringState::processLetter(char c)
{
	lexicalAnalyser->addCharacter(c);
	return this;
}

State* StringState::processDigit(char c)
{
	lexicalAnalyser->addCharacter(c);
	return this;
}

State* StringState::processMinus(char c)
{
	lexicalAnalyser->addCharacter(c);
	return this;
}

State* StringState::processQuote(char c)
{
	lexicalAnalyser->addCurrentLexem(LexemType::STRING);
	return lexicalAnalyser->getEndStringState();
}

State* StringState::processComma(char c)
{
	lexicalAnalyser->addCharacter(c);
	return this;
}

State* StringState::processColon(char c)
{
	lexicalAnalyser->addCharacter(c);
	return this;
}

State* StringState::processSeparator(char c)
{
	lexicalAnalyser->addCharacter(c);
	return this;
}

State* StringState::processCharacter(char c)
{
	lexicalAnalyser->addCharacter(c);
	return this;
}

void StringState::finish()
{
	throw LexicalAnalyserError();
}
