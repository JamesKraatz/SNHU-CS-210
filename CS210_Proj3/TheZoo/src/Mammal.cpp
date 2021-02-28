///*
// * Mammal.cpp
// *
// *  Created on: Feb 10, 2021
// *      Author: 1948462_snhu
// */

#include "mammal.h"

Mammal::Mammal(){
	m_nurse = 0;
}

Mammal::Mammal(int t_trackNum, std::string t_name, int t_nurse) {
	Animal::setTrackNum(t_trackNum);
	Animal::setName(t_name);
	Mammal::setNurse(t_nurse);
}

Mammal::~Mammal() = default;

int Mammal::getNurse() const {
	return this->m_nurse;
}

void Mammal::setNurse(int t_nurse){
	try {
		if ((0 > t_nurse) || (t_nurse > 1)){
			throw MAMMAL_ERROR::INVALID_NURSE_VALUE;
		}
	} catch (int thrownError) {
		switch(thrownError) {
		case MAMMAL_ERROR::INVALID_NURSE_VALUE:
			std::cerr << NURSE_RANGE_STRING << std::endl;
			throw std::out_of_range(NURSE_RANGE_STRING);
			break;
		default:
			std::cerr << "Unknown Error in Mammal::setNurse" << std::endl;
			throw std::runtime_error("UNKNOWN");
			break;
		}
	}
	this->m_nurse = t_nurse;
}

std::string Mammal::getInfo() const {
	std::stringstream ss;
	ss << Animal::getInfo() << TYPE << m_nurse;
	return ss.str();
}
