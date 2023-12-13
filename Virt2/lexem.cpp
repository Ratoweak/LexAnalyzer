#include "lexem.h"

Lexem::Lexem(string value, LexemType type)
{
	this->value = value;
	this->type = type;
}

string Lexem::getValue() const
{
	return value;
}

LexemType Lexem::getType() const
{
	return type;
}
