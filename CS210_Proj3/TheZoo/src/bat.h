/*
 * bat.h
 *
 *  Created on: Feb 19, 2021
 *      Author: 1948462_snhu
 */

#ifndef BAT_H_
#define BAT_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <sstream>
#include "mammal.h"

struct BAT_ERROR {
	enum ERROR {
		SUCCESS = 0,
		UNKNOWN_ERROR = INT_MIN
	};
};

class Bat: public Mammal {
private:
	const std::string SUBTYPE = "Bat            ";
public:
	Bat();
	Bat(int t_trackNum, std::string t_name, int t_nurse);
	std::string getInfo() const;
};

#endif /* Bat_H_ */
