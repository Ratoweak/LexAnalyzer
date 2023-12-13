#include "state-separator-special.h"

#include "lexical-analyser.h"

SpecialSeparatorState::SpecialSeparatorState(LexicalAnalyser* lexicalAnalyser, LexemType lexemType) : State(lexicalAnalyser)
{
	this->lexemType = lexemType;
}

State* SpecialSeparatorState::processLetter(char c)
{
	lexicalAnalyser->addCurrentLexem(lexemType);
	lexicalAnalyser->addCharacter(c);
	return lexicalAnalyser->getIdentifierState();
}

State* SpecialSeparatorState::processDigit(char c)
{
	lexicalAnalyser->addCurrentLexem(lexemType);
	lexicalAnalyser->addCharacter(c);
	return lexicalAnalyser->getDecimalNumberState();
}

State* SpecialSeparatorState::processMinus(char c)
{
	lexicalAnalyser->addCurrentLexem(lexemType);
	lexicalAnalyser->addCharacter(c);
	return lexicalAnalyser->getDecimalNumberState();
}

State* SpecialSeparatorState::processQuote(char c)
{
	lexicalAnalyser->addCurrentLexem(lexemType);
	return lexicalAnalyser->getStringState();
}

State* SpecialSeparatorState::processSeparator(char c)
{
	return this;
}

void SpecialSeparatorState::finish()
{
	lexicalAnalyser->addCurrentLexem(lexemType);
}
