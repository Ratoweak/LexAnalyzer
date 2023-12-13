#include "state-number-decimal.h"

#include "lexical-analyser.h"

State* DecimalNumberState::processLetter(char c)
{
	if ((c == 'x' || c == 'X') && (lexicalAnalyser->getCurrentLexem() == "0" || lexicalAnalyser->getCurrentLexem() == "-0"))
	{
		lexicalAnalyser->addCharacter(c);
		return lexicalAnalyser->getHexadecimalNumberState();
	}
	else
	{
		throw LexicalAnalyserError();
	}
}
