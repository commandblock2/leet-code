#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

std::pair<int, int> top2(std::stack<int> &stack_) {
	int lhs = stack_.top();
	stack_.pop();
	int rhs = stack_.top();
	stack_.pop();
	return std::make_pair(lhs, rhs);
}

int evalRPN(std::vector<std::string> &tokens) {

	std::stack<int> operands;

	for (auto const &elem : tokens) {

		if (elem.size() != 1) {
			operands.push(std::stoi(elem));
		} else {
			switch (elem[0]) {
			case '+': {
				auto [lhs, rhs] = top2(operands);
				operands.push(rhs + lhs);
			} break;

			case '-': {
				auto [lhs, rhs] = top2(operands);
				operands.push(rhs - lhs);
			} break;

			case '*': {
				auto [lhs, rhs] = top2(operands);
				operands.push(rhs * lhs);
			} break;

			case '/': {
				auto [lhs, rhs] = top2(operands);
				operands.push(rhs / lhs);
			}

			break;

			default:
				operands.push(std::stoi(elem));
			}
		}
	}

	return operands.top();
}

int main() {
	std::vector<std::string> a{
			{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}};
	std::cout << evalRPN(a);
}