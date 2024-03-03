#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;
enum class Token {
    Const = 0,
    Var,
    Ident,
    Type,
    Assignment,
    Semicolon,
    Relation,
    Numb,
    Minus,
    Mul,
    Div,
    Mod,
    Divine,
    Not,
    LParen,
    RParen,
    Plus,
    Or,
    Comma,
    Noc,
    Rav,
    If,
    Then,
    Else,
    Fi,
    Endm,
    While,
    For,
    Write,
    Read,
    Do,
    Od,
    Rof,
    OpBracket,
    ClBracket,
    OBracket,
    CBracket,
    Quote,
    Daer,
    Tirw,
    Eof,
    String,
    Char,
    Main
};
map<Token, string> tokenToString = {
    {Token::Const, "Const"},
    {Token::Var, "Var"},
    {Token::Ident, "Ident"},
    {Token::Type, "Type"},
    {Token::Assignment, "Assignment"},
    {Token::Semicolon, "Semicolon"},
    {Token::Relation, "Relation"},
    {Token::Numb, "Numb"},
    {Token::Minus, "Minus"},
    {Token::Mul, "Mul"},
    {Token::Div, "Div"},
    {Token::Mod, "Mod"},
    {Token::Divine, "Divine"},
    {Token::Not, "Not"},
    {Token::LParen, "LParen"},
    {Token::RParen, "RParen"},
    {Token::Plus, "Plus"},
    {Token::Or, "Or"},
    {Token::Comma, "Comma"},
    {Token::Noc, "Noc"},
    {Token::Rav, "Rav"},
    {Token::If, "If"},
    {Token::Then, "Then"},
    {Token::Else, "Else"},
    {Token::Fi, "Fi"},
    {Token::Endm, "Endm"},
    {Token::While, "While"},
    {Token::For, "For"},
    {Token::Write, "Write"},
    {Token::Read, "Read"},
    {Token::Do, "Do"},
    {Token::Od, "Od"},
    {Token::Rof, "Rof"},
    {Token::OpBracket, "OpBracket"},
    {Token::ClBracket, "ClBracket"},
    {Token::OBracket, "OBracket"},
    {Token::CBracket, "CBracket"},
    {Token::Quote, "Quote"},
    {Token::Daer, "Daer"},
    {Token::Tirw, "Tirw"},
    {Token::String, "String"},
    {Token::Char, "Char"},
    {Token::Noc, "Noc"},
    {Token::Eof, "EOF"},
    {Token::Main, "Main" }
};

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

std::map<std::string, Token> keywords = {
    std::make_pair(toLower("main"), Token::Main),
    std::make_pair(toLower("int"), Token::Type),
    std::make_pair(toLower("char"), Token::Type),
    std::make_pair(toLower("float"), Token::Type),
    std::make_pair(toLower("string"), Token::Type),
    std::make_pair(toLower("for"), Token::For),
    std::make_pair(toLower("rof"), Token::Rof),
    std::make_pair(toLower("while"), Token::While),
    std::make_pair(toLower("if"), Token::If),
    std::make_pair(toLower("fi"), Token::Fi),
    std::make_pair(toLower("else"), Token::Else),
    std::make_pair(toLower("then"), Token::Then),
    std::make_pair(toLower("const"), Token::Const),
    std::make_pair(toLower("noc"), Token::Noc),
    std::make_pair(toLower("read"), Token::Read),
    std::make_pair(toLower("dear"), Token::Daer),
    std::make_pair(toLower("endm"), Token::Endm),
    std::make_pair(toLower("write"), Token::Write),
    std::make_pair(toLower("tirw"), Token::Tirw),
    std::make_pair(toLower("do"), Token::Do),
    std::make_pair(toLower("od"), Token::Od),
    std::make_pair(toLower("div"), Token::Div),
    std::make_pair(toLower("mod"), Token::Mod),
    std::make_pair(toLower("var"), Token::Var),
    std::make_pair(toLower("rav"), Token::Rav),
    std::make_pair(toLower("/"), Token::Divine)
};

std::map<std::string, Token> separators = {
    std::make_pair(toLower("("), Token::OpBracket),
    std::make_pair(toLower(")"), Token::ClBracket),
    std::make_pair(toLower("{"), Token::OBracket),
    std::make_pair(toLower("}"), Token::CBracket),
    std::make_pair(toLower(";"), Token::Semicolon),
    std::make_pair(toLower(","), Token::Comma),
    std::make_pair(toLower("/"), Token::Divine),
    std::make_pair(toLower("*"), Token::Mul),
    std::make_pair(toLower("+"), Token::Plus),
    std::make_pair(toLower("-"), Token::Minus),
    std::make_pair(toLower("or"), Token::Or),
    std::make_pair(toLower(":="), Token::Assignment)
};
std::map<std::string, Token> Relation = {
    std::make_pair("==", Token::Relation),
    std::make_pair("<=", Token::Relation),
    std::make_pair(">=", Token::Relation),
    std::make_pair("=<", Token::Relation),
    std::make_pair("<", Token::Relation),
    std::make_pair(">", Token::Relation)
};



string tokenToStringFunc(Token token) {
    if (tokenToString.find(token) != tokenToString.end()) {
        return tokenToString[token];
    }
    else {
        return "Unknown Token";
    }
}
bool Lexer::MakeToken(string & word, int indexStr, size_t position, deque<string>&vectorOfStringAndChar, ofstream & outputFile, vector<Token>&tokenList)
{
    if (word == "")
    {
        return false;
    }

    for (auto& item : keywords)
    {
        size_t index = word.find(item.first);
        if (index != string::npos)
        {
            word.erase(index, item.first.size());
            string secondStr = word.substr(index, word.size() - index);
            word = word.substr(0, index);
            MakeToken(word, indexStr, position, vectorOfStringAndChar, outputFile, tokenList);
            tokenList.push_back(item.second);
            MakeToken(secondStr, indexStr, position + index + word.size(), vectorOfStringAndChar, outputFile, tokenList);
            return true;
        }
    }

    for (auto& item : separators)
    {
        size_t index = word.find(item.first);
        if (index != string::npos)
        {
            word.erase(index, item.first.size());
            string secondStr = word.substr(index, word.size() - index);
            word = word.substr(0, index);
            MakeToken(word, indexStr, position, vectorOfStringAndChar, outputFile, tokenList);
            tokenList.push_back(item.second);
            MakeToken(secondStr, indexStr, position + index + word.size(), vectorOfStringAndChar, outputFile, tokenList);
            return true;
        }
    }

    for (auto& item : Relation)
    {
        size_t index = word.find(item.first);
        if (index != string::npos)
        {
            word.erase(index, item.first.size());
            string secondStr = word.substr(index, word.size() - index);
            word = word.substr(0, index);
            MakeToken(word, indexStr, position, vectorOfStringAndChar, outputFile, tokenList);
            tokenList.push_back(item.second);
            MakeToken(secondStr, indexStr, position + index + word.size(), vectorOfStringAndChar, outputFile, tokenList);
            return true;
        }
    }

    if (word.front() == '\"' && word.back() == '\"')
    {
        tokenList.push_back(Token::String);
        return true;
    }
    else if (word.front() == '\'' && word.back() == '\'')
    {
        tokenList.push_back(Token::Char);
        return true;
    }


    //numbers
    if (word.find_first_not_of("0123456789.") == string::npos)
    {
        tokenList.push_back(Token::Numb);
        return true;
    }

    Token output;
    if (keywords.find(word) != keywords.end())
    {
        output = keywords[word];
        tokenList.push_back(output);
        return true;
    }

    if (separators.find(word) != separators.end())
    {
        output = separators[word];
        tokenList.push_back(output);
        return true;
    }

    if (word == "\"" && !vectorOfStringAndChar.empty())
    {
        word = vectorOfStringAndChar[0];
        vectorOfStringAndChar.pop_front();
        size_t i = word.find("\"") + 1;
        if (i < word.size() && word.find("\"", i) != string::npos)
        {
            tokenList.push_back(Token::Type);
        }
        else
        {
            outputFile << word << indexStr << " --- position " << position << "\n";
        }
        return true;
    }

    if (word == "\'" && !vectorOfStringAndChar.empty())
    {
        word = vectorOfStringAndChar[0];
        vectorOfStringAndChar.pop_front();
        size_t i = word.find("\'") + 1;
        if (i < word.size() && word.find("\'", i) != string::npos && word.size() == 3)
        {
            tokenList.push_back(Token::Type);
        }
        else
        {
            outputFile << word << indexStr << " --- position " << position << "\n";
        }
        return true;
    }

    if (isalpha(word[0]) || word[0] == '_') {
        for (auto i = 1; i < word.size(); i++) {
            if (!isalnum(word[i]) && word[i] != '_') {
                outputFile << word << indexStr << " --- position " << position << "\n";
                return true;
            }
        }

        tokenList.push_back(Token::Ident);
        return true;
    }

    outputFile << word << indexStr << " --- position " << position << "\n";
}

void Lexer::processStringAndChar(deque<string>& vectorOfStringAndChar, string& inputStr, size_t indexStart)
{
    if (inputStr.find("\"", indexStart) != string::npos)
    {
        string str;
        size_t start = inputStr.find("\"", indexStart);
        size_t end = inputStr.size() - 1;
        if (start + 1 < inputStr.size() && inputStr.find("\"", start + 1) != string::npos)
        {
            end = inputStr.find("\"", start + 1);
        }
        str = inputStr.substr(start, end - start + 1);
        vectorOfStringAndChar.push_back(str);
        inputStr.erase(start + 1, end - start);

        processStringAndChar(vectorOfStringAndChar, inputStr, start + 1);
    }
    if (inputStr.find("\'", indexStart) != string::npos)
    {
        string str;
        size_t start = inputStr.find("\'", indexStart);
        size_t end = inputStr.size() - 1;
        if (start + 1 < inputStr.size() and inputStr.find("\'", start + 1) != string::npos)
        {
            end = inputStr.find("\'", start + 1);
        }
        str = inputStr.substr(start, end - start + 1);
        vectorOfStringAndChar.push_back(str);
        inputStr.erase(start + 1, end - start);

        processStringAndChar(vectorOfStringAndChar, inputStr, start + 1);
    }
}

void Lexer::ProcessStr(ifstream& inputFile, string& inputStr, int& indexStr, ofstream& outputFile, vector<Token>& tokenList)
{
    deque<string> vectorOfStringAndChar;
    processStringAndChar(vectorOfStringAndChar, inputStr, 0);

    size_t position = 1;
    if (!inputStr.empty())
    {
        vector<string> words;
        string item;
        istringstream strStream(inputStr);
        while (getline(strStream, item, ' '))
        {
            MakeToken(item, indexStr, position, vectorOfStringAndChar, outputFile, tokenList);
            position += item.size() + 1;
        }
    }
}