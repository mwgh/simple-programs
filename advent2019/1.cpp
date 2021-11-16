#include <iostream>
#include <vector>
#include <cassert>

int calculate_fuel(int mass) {
    const int fuel = mass / 3 - 2;
    if (fuel <= 0) {
        return 0;
    }
    return fuel + calculate_fuel(fuel);
}

void test_calculate_fuel() {
    assert(calculate_fuel(14) == 2);
    assert(calculate_fuel(1969) == 966);
    assert(calculate_fuel(100756) == 50346);
}

std::vector<int> get_input() {
    std::vector<int> input;
    std::string line;
    while (std::getline(std::cin, line)) {
        input.push_back(std::stoi(line));
    }
    return input;
}

int main()
{
    test_calculate_fuel();

    int fuel_sum = 0;
    std::vector<int> input = get_input();
    for (int module_mass: input) {
        fuel_sum += calculate_fuel(module_mass);
    }
  
    std::cout << "total fuel needed is " << fuel_sum << std::endl;
}
