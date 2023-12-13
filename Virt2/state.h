#ifndef STATE_H
#define STATE_H

class LexicalAnalyser;

class State
{
protected:
	LexicalAnalyser* lexicalAnalyser;
public:
	State(LexicalAnalyser* lexicalAnalyser);
	virtual State* processLetter(char c);
	virtual State* processDigit(char c);
	virtual State* processMinus(char c);
	virtual State* processQuote(char c);
	virtual State* processComma(char c);
	virtual State* processColon(char c);
	virtual State* processSeparator(char c);
	virtual State* processCharacter(char c);
	virtual State* processDollar(char c);
	virtual void finish() = 0;
};

#endif // STATE_H
