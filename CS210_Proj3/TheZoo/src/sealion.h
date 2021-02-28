/*
 * sealion.h
 *
 *  Created on: Feb 19, 2021
 *      Author: 1948462_snhu
 */

#ifndef SEALION_H_
#define SEALION_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>
#include "mammal.h"

struct SEALION_ERROR {
	enum ERROR {
		SUCCESS = 0,
		UNKNOWN_ERROR = INT_MIN
	};
};

class SeaLion: public Mammal {
private:
	const std::string SUBTYPE = "SeaLion        ";
public:
	SeaLion();
	SeaLion(int t_trackNum, std::string t_name, int t_nurse);
	std::string getInfo() const;
};

#endif /* SEALION_H_ */
