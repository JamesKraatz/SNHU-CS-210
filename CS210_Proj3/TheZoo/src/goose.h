/*
 * goose.h
 *
 *  Created on: Feb 19, 2021
 *      Author: 1948462_snhu
 */

#ifndef GOOSE_H_
#define GOOSE_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <sstream>
#include "oviparous.h"

struct GOOSE_ERROR {
	enum ERROR {
		SUCCESS = 0,
		UNKNOWN_ERROR = INT_MIN
	};
};

class Goose: public Oviparous {
private:
	const std::string SUBTYPE = "Goose          ";
public:
	Goose();
	Goose(int t_trackNum, std::string t_name, int t_numberOfEggs);
	std::string getInfo() const;
};

#endif /* GOOSE_H_ */
