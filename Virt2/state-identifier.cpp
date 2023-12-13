#include "state-identifier.h"

#include "lexical-analyser.h"

State* IdentifierState::processLetter(char c)
{
	lexicalAnalyser->addCharacter(c);
	return this;
}

State* IdentifierState::processDigit(char c)
{
	lexicalAnalyser->addCharacter(c);
	return this;
}

State* IdentifierState::processComma(char c)
{
	lexicalAnalyser->addCurrentLexem(LexemType::IDENTIFIER);
	lexicalAnalyser->addCharacter(c);
	return lexicalAnalyser->getCommaSeparatorState();
}

State* IdentifierState::processColon(char c)
{
	lexicalAnalyser->addCurrentLexem(LexemType::IDENTIFIER);
	lexicalAnalyser->addCharacter(c);
	return lexicalAnalyser->getColonSeparatorState();
}

State* IdentifierState::processSeparator(char c)
{
	lexicalAnalyser->addCurrentLexem(LexemType::IDENTIFIER);
	return lexicalAnalyser->getSimpleSeparatorState();
}

/*State* IdentifierState::processDollar(char c)
{
	lexicalAnalyser->addCurrentLexem(LexemType::IDENTIFIER);
	return lexicalAnalyser->getDollarState();
}*/

void IdentifierState::finish()
{
	lexicalAnalyser->addCurrentLexem(LexemType::IDENTIFIER);
}
