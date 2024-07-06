#include <iostream>
#include <regex>
#include <string>
#include "TokenTypes.h"


using std::string;
using std::vector;

string custom_trim(const string& input) {
    int length = input.length();
    if (length <= 2) {
        return "";
    } 
    return input.substr(1, length - 2);
}

vector<Token> tokenize_helper(const string& input, const string& match, vector<Token>& tokens, int last_index) {
    if (match.length() > last_index) {
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
        std::cout << "Boolean: " << match.str() << std::endl;
        // func(input.substr(match.str().length(), last_index));
    } else if (std::regex_search(input_begin, input_end, match, re_int)) {
        std::cout << "Integer: " << match.str() << std::endl;
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