#include <iostream>
#include <vector>

#include "Stuff.h"
#include "Ops.h"

int main() {

	// Get syms from an input message
	std::vector<Symbol> symbols = toSymbols(toBits(promptMessage()));

	// Print out
	for (int i = 0; i < symbols.size(); i++) {
		std::cout << symbols[i].expo << std::endl;
	}

	return 0;

}
