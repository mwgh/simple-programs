#include <iostream>
#include <vector>
#include <cassert>

#define NUMBER_OF_VALUES_IN_INSTRUCTION 4

std::vector<int> get_input() {
    std::vector<int> input;
    int value;
    std::cin >> value;
    if (std::cin) {
	input.push_back(value);
	char separator;
        while (std::cin >> separator >> value && separator == ',') {
          input.push_back(value);
        }
    }
    if (!std::cin.eof()) {
	std::cerr << "format error in input" << std::endl;
    }
    return input;
}

int find_output(std::vector<int> input) {
    unsigned int instruction_ptr = 0;
    while (instruction_ptr < input.size()) {
	int opcode = input[instruction_ptr];
	int parameter1 = input[instruction_ptr + 1];
	int parameter2 = input[instruction_ptr + 2];
	int result_address = input[instruction_ptr + 3];

	if (opcode == 99) {
	    return input[0];
	} else if (opcode == 1) {
	    input[result_address] = input[parameter1] + input[parameter2];
	} else if (opcode == 2) {
	    input[result_address] = input[parameter1] * input[parameter2];
	} else {
	    return input[0];
	}
	instruction_ptr += NUMBER_OF_VALUES_IN_INSTRUCTION;
    }
    return input[0];
}

int main()
{
    const std::vector<int> input = get_input();
    std::vector<int> copy;
    const int LIMIT = 100;

    for (int noun = 0; noun < LIMIT; ++noun) {
	for (int verb = 0; verb < LIMIT; ++verb) {
	    copy = input;
	    copy[1] = noun;
	    copy[2] = verb;
	    int result = find_output(copy);
	    if (result == 19690720) {
		std::cout << "result is " << 100 * noun + verb << std::endl;
		return 0;
	    }
	}
    }
    std::cout << "no result" << std::endl;
    return 0;
}
