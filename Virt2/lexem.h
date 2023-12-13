#ifndef LEXEM_H
#define LEXEM_H

#include <string>

using namespace std;

enum class LexemType
{
	KEYWORD,
	IDENTIFIER,
	DECIMAL_NUMBER,
	HEXADECIMAL_NUMBER,
	STRING,
	COMMA_SEPARATOR,
	COLON_SEPARATOR,
	DOLLAR_SIGN
};

class Lexem
{
	string value;
	LexemType type;
public:
	Lexem(string value, LexemType type);
	string getValue() const;
	LexemType getType() const;
};

#endif // LEXEM_H
