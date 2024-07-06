#ifndef TOKENTYPES_H
#define TOKENTYPES_H

#include <string>

using std::string;

enum TokenType {
    Tok_RParen,
    Tok_LParen,
    Tok_RCurly,
    Tok_LCurly,
    Tok_Dot,
    Tok_Equal,
    Tok_NotEqual,
    Tok_Greater,
    Tok_Less,
    Tok_GreaterEqual,
    Tok_LessEqual,
    Tok_Or,
    Tok_And,
    Tok_Not,
    Tok_If,
    Tok_Then,
    Tok_Else,
    Tok_Add,
    Tok_Sub,
    Tok_Mult,
    Tok_Div,
    Tok_Concat,
    Tok_Let,
    Tok_Rec,
    Tok_In,
    Tok_Def,
    Tok_Fun,
    Tok_Arrow,
    Tok_DoubleSemi,
    Tok_Semi,
    Tok_Int,
    Tok_Bool,
    Tok_String,
    Tok_ID,
};

struct Token {
    TokenType type;
    int intValue; // Only used if type is Tok_Int
    string strValue;

    // Used for most primative types
    Token(TokenType t) : type(t), intValue(0), strValue("") {}
    // Used for Tok_Bool.  0 = false. 1 = true
    Token(TokenType t, int boolVal) : type(Tok_Bool), intValue(boolVal), strValue("") {}
    // Used for Tok_Int
    Token(int value) : type(Tok_Int), intValue(value), strValue("") {}
    // Used for ID or String
    Token(TokenType t, string value) : type(t), intValue(0), strValue(value) {}
};

#endif