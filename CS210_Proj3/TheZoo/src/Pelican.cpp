/*
 * Pelican.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: 1948462_snhu
 */

#include "pelican.h"

Pelican::Pelican() {
	// Default Constructor
}

Pelican::Pelican(int t_trackNum, std::string t_name, int t_numberOfEggs) {
	Oviparous::setTrackNum(t_trackNum);
	Oviparous::setName(t_name);
	Oviparous::setNumberOfEggs(t_numberOfEggs);
}

std::string Pelican::getInfo() const{
	std::stringstream ss;
	std::string stringBuffer;

	stringBuffer = Oviparous::getInfo();
	ss << stringBuffer.substr(0,36);
	ss << SUBTYPE;
	stringBuffer = stringBuffer.substr(36,(stringBuffer.length() - 36));
	ss << stringBuffer;
	return ss.str();
}
