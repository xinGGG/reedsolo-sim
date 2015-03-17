#ifndef OPS_H
#define OPS_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#include "Stuff.h"

std::string promptMessage() {
	std::string msg;
	std::cout << "Enter a message: ";
	std::cin >> msg;
	return msg;
}

std::vector<unsigned char> toBits(std::string str) {
	std::vector<unsigned char> bits;
	const char* bytes = str.c_str();
	int len = strlen(bytes);

	for (int i = 0; i < len; i++) {
		unsigned char byte = (unsigned char)bytes[i];

		for (int j = 7; j >= 0; j--) {
			bits.push_back((byte >> j) & 0x01);
		}
	}

	return bits;
}

std::vector<Symbol> toSymbols(std::vector<unsigned char> bits) {
	std::vector<Symbol> symbols;

	while (bits.size() >= 3) {
		bool _0, _1, _2;
		Symbol temp;

		_0 = (bits[0] == 0x01);
		_1 = (bits[1] == 0x01);
		_2 = (bits[2] == 0x01);

		temp._0 = _0;
		temp._1 = _1;
		temp._2 = _2;

		temp = fixSymbol(temp);
		symbols.push_back(temp);

		bits.erase(bits.begin(), bits.begin() + 3);
	}

	return symbols;
}

#endif // OPS_H
