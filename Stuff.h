#ifndef STUFF_H
#define STUFF_H

// Code symbols
struct Symbol {
	bool _0, _1, _2;
	int expo;
};

const Symbol ZERO    = {0, 0, 0, -1};
const Symbol ALPHA_0 = {1, 0, 0, 0};
const Symbol ALPHA_1 = {0, 1, 0, 1};
const Symbol ALPHA_2 = {0, 0, 1, 2};
const Symbol ALPHA_3 = {1, 1, 0, 3};
const Symbol ALPHA_4 = {0, 1, 1, 4};
const Symbol ALPHA_5 = {1, 1, 1, 5};
const Symbol ALPHA_6 = {1, 0, 1, 6};

bool operator==(Symbol left, Symbol right) {
	if (left._0 != right._0) return false;
	if (left._1 != right._1) return false;
	if (left._2 != right._2) return false;

	return true;
}

Symbol getSymFromExpo(int expo) {
	switch (expo) {
		case -1: return ZERO;
		case 0:  return ALPHA_0;
		case 1:  return ALPHA_1;
		case 2:  return ALPHA_2;
		case 3:  return ALPHA_3;
		case 4:  return ALPHA_4;
		case 5:  return ALPHA_5;
		case 6:  return ALPHA_6;
	}

	return ZERO;
}

Symbol fixSymbol(Symbol sym) {
	if (sym == ALPHA_0) return ALPHA_0;
	if (sym == ALPHA_1) return ALPHA_1;
	if (sym == ALPHA_2) return ALPHA_2;
	if (sym == ALPHA_3) return ALPHA_3;
	if (sym == ALPHA_4) return ALPHA_4;
	if (sym == ALPHA_5) return ALPHA_5;
	if (sym == ALPHA_6) return ALPHA_6;
	return ZERO;
}

Symbol operator+(Symbol left, Symbol right) { // Symbol XOR
	Symbol rtr;

	rtr._0 = left._0 != right._0;
	rtr._1 = left._1 != right._1;
	rtr._2 = left._2 != right._2;

	return fixSymbol(rtr);
}

Symbol operator*(Symbol left, Symbol right) { // Symbol Multiply
	int expo = (left.expo + right.expo) % 7;
	return getSymFromExpo(expo);
}



// LFSR Register
struct LFSR_Reg {
	Symbol newValue;
	Symbol oldValue;

	Symbol feedback;
	bool useFeedback; // do a xor on the right-hand side of the register

	Symbol coeficient;
	bool useCoef;

	LFSR_Reg() {
		newValue = ZERO;
		oldValue = ZERO;

		feedback = ZERO;
		useFeedback = false;

		coeficient = ZERO;
		useCoef = false;
	}

	Symbol tick(Symbol newval, Symbol fback) {
		oldValue = newValue;
		newValue = newval;

		feedback = fback;

		if (useFeedback) {

			if (useCoef)
				return (feedback * coeficient) + oldValue;

			else
				return feedback + oldValue;

		}

		else {
			return oldValue;
		}
	}
};

#endif // STUFF_H
