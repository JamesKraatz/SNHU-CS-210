/*
 * mammal.h
 *
 *  Created on: Feb 10, 2021
 *      Author: 1948462_snhu
 */

#ifndef MAMMAL_H_
#define MAMMAL_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <sstream>
#include "animal.h"

struct MAMMAL_ERROR {
	enum ERROR {
		SUCCESS = 0,
		INVALID_NURSE_VALUE = -1,
		UNKNOWN_ERROR = INT_MIN
	};
};

const std::string NURSE_RANGE_STRING =
	"nurse must be either 0 or 1 for wither false or true respectively.";

class Mammal: public Animal {
private:
	const std::string TYPE = "Mammal         ";
	int m_nurse;

public:
	Mammal();
	Mammal(int t_trackNum, std::string t_name, int t_nurse);
	virtual ~Mammal();
	int getNurse() const;
	void setNurse(int t_nurse);
	virtual std::string getInfo() const;

};

#endif /* MAMMAL_H_ */
