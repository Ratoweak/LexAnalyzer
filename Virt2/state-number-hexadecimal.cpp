#include"state-number-hexadecimal.h"

#include "lexical-analyser.h"

State* HexadecimalNumberState::processLetter(char c)
{
	if (('A' <= c && c <= 'F') || ('a' <= c && c <= 'f'))
	{
		lexicalAnalyser->addCharacter(c);
		return this;
	}
	else
	{
		throw LexicalAnalyserError();
	}
}
