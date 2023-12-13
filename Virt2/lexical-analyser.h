#ifndef LEXICAL_ANALYSER_H
#define LEXICAL_ANALYSER_H

#include <string>
#include <vector>
#include <set>

using namespace std;

#include "lexem.h"
#include "state.h"
#include "state-identifier.h"
#include "state-number-decimal.h"
#include "state-number-hexadecimal.h"
#include "state-separator-simple.h"
#include "state-separator-special.h"
#include "state-string.h"
#include "state-string-end.h"
#include "dollar_state.h"

class LexicalAnalyser
{
	string currentLexem;
	vector<Lexem> lexems;
	IdentifierState*        identifierState;
	DecimalNumberState*     decimalNumberState;
	HexadecimalNumberState* hexadecimalNumberState;
	ColonSeparatorState*    colonSeparatorState;
	CommaSeparatorState*    commaSeparatorState;
	SimpleSeparatorState*   simpleSeparatorState;
	StringState*            stringState;
	EndStringState*         endStringState;
	DollarState*            dollarState;
public:
	LexicalAnalyser();
	void addCharacter(char c);
	void addCurrentLexem(LexemType type);
	string getCurrentLexem() const;
	vector<Lexem> getLexems() const;
	IdentifierState*        getIdentifierState()        const;
	DollarState*            getDollarState()            const;
	DecimalNumberState*     getDecimalNumberState()     const;
	HexadecimalNumberState* getHexadecimalNumberState() const;
	ColonSeparatorState*    getColonSeparatorState()    const;
	CommaSeparatorState*    getCommaSeparatorState()    const;
	SimpleSeparatorState*   getSimpleSeparatorState()   const;
	StringState*            getStringState()            const;
	EndStringState*         getEndStringState()         const;
	~LexicalAnalyser();
};

const set<string> keywords {
	// structural directives
	"data",
	"code",
	"end",
	// variables declaration directives
	"db",
	"dd",
	// addressing directive
	"offset",
	// instructions
	"exit",
	"push",
	"pop",
	"add",
	"sub",
	"mul",
	"div",
	"mod",
	"in",
	"out"
};

class LexicalAnalyserError {};

#endif // LEXICAL_ANALYSER_H
