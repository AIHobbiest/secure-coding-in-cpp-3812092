// Secure Coding in C++
// Exercise 01_05
// Fixing unsafe expressions, by Eduardo Corpeño

#include <iostream>
#include <vector>

using std::vector;

double average(const vector<double>& numbers){
    double sum = 0;
    for(auto it = std::begin(numbers); it != std::end(numbers); ++it){
        sum += *it;
    }
    return sum / numbers.size();
}

int main(){
    vector<double> numbers = {20, 10, 30, 27, 18};
    double learnerResult = average(numbers);
    
    std::cout << "Your code returned: " << learnerResult << std::endl;
    
    std::cout << std::endl << std::endl;
    return 0;
}
