/*
 * crocodile.h
 *
 *  Created on: Feb 19, 2021
 *      Author: 1948462_snhu
 */

#ifndef CROCODILE_H_
#define CROCODILE_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>
#include "oviparous.h"

struct CROCODILE_ERROR {
	enum ERROR {
		SUCCESS = 0,
		UNKNOWN_ERROR = INT_MIN
	};
};

class Crocodile: public Oviparous {
private:
	const std::string SUBTYPE = "Crocodile      ";
public:
	Crocodile();
	Crocodile(int t_trackNum, std::string t_name, int t_numberOfEggs);
	std::string getInfo() const;

};

#endif /* CROCODILE_H_ */
