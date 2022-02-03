#include <string>
#include <iostream>
#include <variant>

class Solution
{
public:
    std::string longestNiceSubstring(std::string s)
    {
        std::string result;
        return result;
    }
};

struct Entry
{
    std::string name;
    std::variant<std::string, int> v;
};

int main(int argc, char *argv[]) {
    std::cout << "This worked fine";
    return 0;
}
