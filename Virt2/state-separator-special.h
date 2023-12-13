#ifndef STATE_SEPARATOR_SPECIAL_H
#define STATE_SEPARATOR_SPECIAL_H

#include "lexem.h"
#include "state.h"

class SpecialSeparatorState : public State
{
	LexemType lexemType;
public:
	SpecialSeparatorState(LexicalAnalyser* lexicalAnalyser, LexemType lexemType);
	State* processLetter(char c);
	State* processDigit(char c);
	State* processMinus(char c);
	State* processQuote(char c);
	State* processSeparator(char c);
	void finish();
};

class ColonSeparatorState : public SpecialSeparatorState
{
public:
	ColonSeparatorState(LexicalAnalyser* lexicalAnalyser) : SpecialSeparatorState(lexicalAnalyser, LexemType::COLON_SEPARATOR) {}
};

class CommaSeparatorState : public SpecialSeparatorState
{
public:
	CommaSeparatorState(LexicalAnalyser* lexicalAnalyser) : SpecialSeparatorState(lexicalAnalyser, LexemType::COMMA_SEPARATOR) {}
};

#endif // STATE_SEPARATOR_SPECIAL_H
