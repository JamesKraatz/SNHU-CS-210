/*
 * SeaLion.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: 1948462_snhu
 */

#include "sealion.h"

SeaLion::SeaLion() {
	// Default Constructor
}

SeaLion::SeaLion(int t_trackNum, std::string t_name, int _t_nurse) {
	Mammal::setTrackNum(t_trackNum);
	Mammal::setName(t_name);
	Mammal::setNurse(_t_nurse);
}

std::string SeaLion::getInfo() const{
	std::stringstream ss;
	std::string stringBuffer;

	stringBuffer = Mammal::getInfo();
	ss << stringBuffer.substr(0,36);
	ss << SUBTYPE;
	stringBuffer = stringBuffer.substr(36,(stringBuffer.length() - 36));
	ss << stringBuffer;
	return ss.str();
}
