/*
 * pelican.h
 *
 *  Created on: Feb 19, 2021
 *      Author: 1948462_snhu
 */

#ifndef PELICAN_H_
#define PELICAN_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <sstream>
#include "oviparous.h"

struct PELICAN_ERROR {
	enum ERROR {
		SUCCESS = 0,
		UNKNOWN_ERROR = INT_MIN
	};
};

class Pelican: public Oviparous {
private:
	const std::string SUBTYPE = "Pelican        ";
public:
	Pelican();
	Pelican(int t_trackNum, std::string t_name, int t_numberOfEggs);
	std::string getInfo() const;

};

#endif /* PELICAN_H_ */
