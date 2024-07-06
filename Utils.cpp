#include <string>
#include "Utils.h"

int stringToBool(const std::string& str) {
    if (str == "true") {
        return 1;
    } 
    return 0;
}