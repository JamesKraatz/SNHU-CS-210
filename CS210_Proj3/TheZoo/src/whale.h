/*
 * whale.h
 *
 *  Created on: Feb 19, 2021
 *      Author: 1948462_snhu
 */

#ifndef WHALE_H_
#define WHALE_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>
#include "mammal.h"

struct WHALE_ERROR {
	enum ERROR {
		SUCCESS = 0,
		UNKNOWN_ERROR = INT_MIN
	};
};

class Whale: public Mammal {
private:
	const std::string SUBTYPE = "Whale          ";
public:
	Whale();
	Whale(int t_trackNum, std::string t_name, int t_nurse);
	std::string getInfo() const;
};

#endif /* WHALE_H_ */
