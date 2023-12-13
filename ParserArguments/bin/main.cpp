#include <iostream>
#include <sstream>
#include <iterator>
#include "ArgParser.h"

using namespace ArgumentParser;

std::vector<std::string> SplitString(const std::string& str) {
    std::istringstream iss(str);

    return {std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>()};
}

int main() {
	ArgParser parser("My Parser");
    parser.AddStringArgument("param1");

    std::cout << parser.Parse(SplitString("app --param1=value1")) << '\n';
    std::cout << parser.GetStringValue("param1") << '\n';

}