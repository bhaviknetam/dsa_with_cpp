class Solution {
public:
    string intToRoman(int num) {
        std::vector<std::pair<int, std::string>> roman_map = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};
        string roman_numeral;
        for (auto& [val, symbol] : roman_map) {
            while (num >= val) {
                roman_numeral += symbol;
                num -= val;
            }
        }
        return roman_numeral;
    }
};