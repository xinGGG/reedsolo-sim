#ifndef ENCODER_H
#define ENCODER_H

#include <vector>

#include "Stuff.h"

std::vector<Symbol> encodeMessage(std::vector<Symbol> message) {
	LFSR_Reg reg_0, reg_1;

	reg_0.useFeedback = true;
	reg_1.useFeedback = false;
	reg_0.coeficient = ALPHA_4;
	reg_1.coeficient = ALPHA_0;
	reg_0.useCoef = true;
	reg_1.useCoef = false;

	Symbol feedback;
	Symbol temp = ZERO;

	std::vector<Symbol> codeword;

	for (int i = 4; i >= 0; i--) {
		feedback = temp + message[i];

		temp = feedback * ALPHA_3;
		temp = reg_0.tick(temp, feedback);
		temp = reg_1.tick(temp, feedback);
	}

	codeword.push_back(reg_1.newValue);
	codeword.push_back(reg_0.newValue);
	for (int i = 0; i < 5; i++)
		codeword.push_back(message[i]);

	return codeword;
}

#endif // ENCODER_H
