/*
 * oviparous.h
 *
 *  Created on: Feb 10, 2021
 *      Author: 1948462_snhu
 */

#ifndef OVIPAROUS_H_
#define OVIPAROUS_H_

#include "animal.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <sstream>


struct OVIPAROUS_ERROR {
	enum ERROR {
		SUCCESS = 0,
		INVALID_NUMBER_OF_EGGS = -1,
		UNKNOWN_ERROR = INT_MIN};
};

const std::string NUMBER_OF_EGGS_RANGE_STRING =
	"Number of eggs cannot be a negative number.";

class Oviparous: public Animal {
private:
	const std::string TYPE = "Oviparous      ";
	int m_numberOfEggs;

public:
	Oviparous();
	Oviparous(int t_trackNum, std::string t_name, int t_numberOfEggs);
	virtual ~Oviparous();
	int getNumberOfEggs() const;
	void setNumberOfEggs(int t_numberOfEggs);
	virtual std::string getInfo() const;
};

#endif /* OVIPAROUS_H_ */
