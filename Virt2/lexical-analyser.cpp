#include "lexical-analyser.h"

LexicalAnalyser::LexicalAnalyser()
{
	identifierState        = new IdentifierState(this);
	decimalNumberState     = new DecimalNumberState(this);
	hexadecimalNumberState = new HexadecimalNumberState(this);
	colonSeparatorState    = new ColonSeparatorState(this);
	commaSeparatorState    = new CommaSeparatorState(this);
	simpleSeparatorState   = new SimpleSeparatorState(this);
	stringState            = new StringState(this);
	endStringState         = new EndStringState(this);
}

void LexicalAnalyser::addCharacter(char c)
{
	currentLexem += c;
}

void LexicalAnalyser::addCurrentLexem(LexemType type)
{
	if (type == LexemType::IDENTIFIER && keywords.find(currentLexem) != keywords.end())
	{
		type = LexemType::KEYWORD;
	}
	lexems.push_back(Lexem(currentLexem, type));
	currentLexem.clear();
}

string LexicalAnalyser::getCurrentLexem() const
{
	return currentLexem;
}

vector<Lexem> LexicalAnalyser::getLexems() const
{
	return lexems;
}

IdentifierState* LexicalAnalyser::getIdentifierState() const
{
	return identifierState;

}

DollarState* LexicalAnalyser::getDollarState() const
{
	return dollarState;
}

DecimalNumberState* LexicalAnalyser::getDecimalNumberState() const
{
	return decimalNumberState;
}

HexadecimalNumberState* LexicalAnalyser::getHexadecimalNumberState() const
{
	return hexadecimalNumberState;
}

ColonSeparatorState* LexicalAnalyser::getColonSeparatorState() const
{
	return colonSeparatorState;
}

CommaSeparatorState* LexicalAnalyser::getCommaSeparatorState() const
{
	return commaSeparatorState;
}

SimpleSeparatorState* LexicalAnalyser::getSimpleSeparatorState() const
{
	return simpleSeparatorState;
}

StringState* LexicalAnalyser::getStringState() const
{
	return stringState;
}

EndStringState* LexicalAnalyser::getEndStringState() const
{
	return endStringState;
}

LexicalAnalyser::~LexicalAnalyser()
{
	delete identifierState;
	delete decimalNumberState;
	delete hexadecimalNumberState;
	delete colonSeparatorState;
	delete commaSeparatorState;
	delete simpleSeparatorState;
	delete stringState;
	delete endStringState;
}
