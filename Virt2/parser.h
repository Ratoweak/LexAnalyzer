#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

using namespace std;

#include "lexem.h"

vector<Lexem> parse(string str);

class LexicalError
{
	int index;
	char character;
public:
	LexicalError(int index, char character);
	int getIndex() const;
	char getCharacter() const;
};

#endif // PARSER_H
