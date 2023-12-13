#include "state-number.h"

#include "lexical-analyser.h"

NumberState::NumberState(LexicalAnalyser* lexicalAnalyser, LexemType lexemType) : State(lexicalAnalyser)
{
	this->lexemType = lexemType;
}

State* NumberState::processDigit(char c)
{
	lexicalAnalyser->addCharacter(c);
	return this;
}

State* NumberState::processComma(char c)
{
	lexicalAnalyser->addCurrentLexem(lexemType);
	lexicalAnalyser->addCharacter(c);
	return lexicalAnalyser->getCommaSeparatorState();
}

State* NumberState::processColon(char c)
{
	lexicalAnalyser->addCurrentLexem(lexemType);
	lexicalAnalyser->addCharacter(c);
	return lexicalAnalyser->getColonSeparatorState();
}

State* NumberState::processSeparator(char c)
{
	lexicalAnalyser->addCurrentLexem(lexemType);
	return lexicalAnalyser->getSimpleSeparatorState();
}

void NumberState::finish()
{
	lexicalAnalyser->addCurrentLexem(lexemType);
}
