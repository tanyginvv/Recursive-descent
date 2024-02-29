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
