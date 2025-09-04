// Secure Coding in C++
// Challenge 02_05
// Secure a data parsing function, by Eduardo Corpeño

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

std::map<std::string, std::string> parseSettings(const std::string& input){
    std::map<std::string, std::string> result;
    std::istringstream ss(input);
    std::string pair;

    while (std::getline(ss, pair, ',')){
        size_t eq = pair.find('=');
        if (eq == std::string::npos || eq == 0 || eq == pair.size() - 1){
            std::cerr << "Invalid pair: " << pair << "\n";
            continue; // skip invalid pairs
        }

        if (result.find(pair.substr(0, eq)) != result.end()){
            std::cerr << "Duplicate key: " << pair.substr(0, eq) << "\n";
            continue; // skip duplicates
        }
        if (pair.find(' ') != std::string::npos){
            std::cerr << "Spaces are not allowed in pair: " << pair << "\n";
            continue; // skip pairs with spaces
        }
        // Check if value is numeric
        std::string num = pair.substr(eq + 1);
        if (!std::all_of(num.begin(), num.end(), ::isdigit)){
            std::cerr << "Non-numeric value: " << num << "\n";
            continue; // skip non-numeric values
        }


        // Unsafe: no check for missing '=', empty keys or values, 
        // duplicate keys, spaces, or non-numeric values.
        std::string key = pair.substr(0, eq);
        std::string value = pair.substr(eq + 1);

        result[key] = value; // silently overwrites
    }
    return result;
}

int main(){
    std::string rawInput;
    std::cout << "Enter settings (key=value,key=value,...): ";
    std::getline(std::cin, rawInput);

    auto settings = parseSettings(rawInput);

    std::cout << "Parsed settings:\n";
    for (const auto& [k, v] : settings)
        std::cout << k << ": " << v << "\n";

    std::cout << std::endl;
    return 0;
}
