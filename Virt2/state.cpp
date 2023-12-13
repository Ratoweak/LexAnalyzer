#include "state.h"

#include "lexical-analyser.h"

State::State(LexicalAnalyser* lexicalAnalyser)
{
	this->lexicalAnalyser = lexicalAnalyser;
}

State* State::processLetter(char c)
{
	throw LexicalAnalyserError();
}

State* State::processDollar(char c)
{
	throw LexicalAnalyserError();
}

State* State::processDigit(char c)
{
	throw LexicalAnalyserError();
}

State* State::processMinus(char c)
{
	throw LexicalAnalyserError();
}

State* State::processQuote(char c)
{
	throw LexicalAnalyserError();
}

State* State::processComma(char c)
{
	throw LexicalAnalyserError();
}

State* State::processColon(char c)
{
	throw LexicalAnalyserError();
}

State* State::processSeparator(char c)
{
	throw LexicalAnalyserError();
}

State* State::processCharacter(char c)
{
	throw LexicalAnalyserError();
}
