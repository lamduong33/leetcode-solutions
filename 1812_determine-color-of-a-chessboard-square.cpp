#include<iostream>
#include <string>

class Solution
{
public:
    bool squareIsWhite(std::string coordinates)
    {
        bool result = false;
        int columnIndex = coordinates[0] - 'a'; // = 1
        int rowIndex = coordinates[1] - '0' + 1; // = 1
        if ((rowIndex + columnIndex) % 2 != 0)
        {
            result = true;
        }
        return result;
    }
};
