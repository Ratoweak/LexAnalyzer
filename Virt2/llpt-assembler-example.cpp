#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#include "parser.h"

int main()
{
    map<LexemType, string> types {
        { LexemType::KEYWORD,            "KEYWORD" },
        { LexemType::IDENTIFIER,         "ID"      },
        { LexemType::DECIMAL_NUMBER,     "DEC_NUM" },
        { LexemType::HEXADECIMAL_NUMBER, "HEX_NUM" },
        { LexemType::STRING,             "STR"     },
        { LexemType::COMMA_SEPARATOR,    "COMMA"   },
        { LexemType::COLON_SEPARATOR,    "COLON"   }
    };
    ifstream fin("program.txt");
    if (fin.is_open())
    {
        cout << "file is opened" << endl;
        string line;
        cout << "[" << endl << " ";
        while(!fin.eof())
        {
            getline(fin, line);
            vector<Lexem> lexems = parse(line);
            cout << " {" << endl;
            cout << "    src: '" << line << "'," << endl;
            cout << "    lexems: [" << endl << "     ";
            for (Lexem lexem : lexems)
            {
                cout << " {" << endl;
                cout << "        type: " << types[lexem.getType()] << "," << endl;
                cout << "        lexem: '" << lexem.getValue() << "'" << endl;
                cout << "      },";
            }
            cout << endl << "    ]" << endl;
            cout << "  },";
        }
        cout << endl << "]" << endl;
        fin.close();
    }
    else
    {
        cout << "there is no such file" << endl;
    }
}
