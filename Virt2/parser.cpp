#include "parser.h"

#include "lexical-analyser.h"
#include "state.h"

vector<Lexem> parse(string str)
{
	LexicalAnalyser lexicalAnalyser;
	State* state = lexicalAnalyser.getSimpleSeparatorState();
	for (unsigned int index = 0; index < str.size(); index++)
	{
		char c = str[index];
		try
		{
			if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
			{
				state = state->processLetter(c);
			}
			else if ('0' <= c && c <= '9')
			{
				state = state->processDigit(c);
			}
			else if (c == '-')
			{
				state = state->processMinus(c);
			}
			else if (c == '"')
			{
				state = state->processQuote(c);
			}
			else if (c == ',')
			{
				state = state->processComma(c);
			}
			else if (c == ':')
			{
				state = state->processColon(c);
			}
			else if (c == ' ' || c == '\t')
			{
				state = state->processSeparator(c);
			}
			else
			{
				state = state->processCharacter(c);
			}
		}
		catch (LexicalAnalyserError&)
		{
			throw LexicalError(index, c);
		}
	}
	state->finish();
	return lexicalAnalyser.getLexems();
}

LexicalError::LexicalError(int index, char character)
{
	this->index = index;
	this->character = character;
}

int LexicalError::getIndex() const
{
	return index;
}

char LexicalError::getCharacter() const
{
	return character;
}
