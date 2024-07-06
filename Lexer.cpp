#include <iostream>
#include <regex>
#include <string>
#include "TokenTypes.h"
#include "Utils.h"

using std::string;
using std::vector;

string custom_trim(const string& input) {
    int length = input.length();
    if (length <= 2) {
        return "";
    } 
    return input.substr(1, length - 2);
}

vector<Token> tokenize_helper(const string& input, const string& match, vector<Token>& tokens) {
    if (match.length() >= input.length()) {
        return tokens;
    } 
    string new_input = input.substr(match.length(), input.length());
    return tokenize(new_input, tokens);
}


vector<Token> tokenize(const string& input, vector<Token>& tokens) {
    std::regex re_bool("true|false");
    std::regex re_int("[0-9]+|(-[0-9]+)");
    std::regex re_string("\"[^\"]*\"");
    std::regex re_id("[a-zA-Z][a-zA-Z0-9]*");

    auto input_begin = input.begin();
    auto input_end = input.begin() + input.length();

    std::smatch match;
    if (std::regex_search(input_begin, input_end, match, re_bool)) {
        string token = match.str();
        int boolValue = stringToBool(token);
        tokens.push_back(tok(Tok_Bool, boolValue));
        return tokenize_helper(input, token, tokens);
    } else if (std::regex_search(input_begin, input_end, match, re_int)) { // handle positive and negative
        string token = match.str();
        int intValue = std::stoi(token);
        tokens.push_back(tok(Tok_Int, intValue));
        return tokenize_helper(input, token, tokens);
    } else if (std::regex_search(input_begin, input_end, match, re_string)) {
        std::cout << "String: " << match.str() << std::endl;
    } else if (std::regex_search(input_begin, input_end, match, re_id)) {
        std::cout << "Identifier: " << match.str() << std::endl;
    } else {
        std::cout << "No match found" << std::endl;
    }

}

int main() {
    return 0;
}