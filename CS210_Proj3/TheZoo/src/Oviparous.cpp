///*
// * Oviparous.cpp
// *
// *  Created on: Feb 10, 2021
// *      Author: 1948462_snhu
// */

#include "oviparous.h"

Oviparous::Oviparous(){
	m_numberOfEggs = 0;
}

Oviparous::Oviparous(int t_trackNum, std::string t_name, int t_numberOfEggs){
	Animal::setTrackNum(t_trackNum);
	Animal::setName(t_name);
	Oviparous::setNumberOfEggs(t_numberOfEggs);
}

Oviparous::~Oviparous() = default;

int Oviparous::getNumberOfEggs() const {
	return this->m_numberOfEggs;
}

void Oviparous::setNumberOfEggs(int t_numberOfEggs){
	try {
		if(t_numberOfEggs < 0){
			throw OVIPAROUS_ERROR::INVALID_NUMBER_OF_EGGS;
		}
	} catch (int thrownError) {
		switch(thrownError) {
		case OVIPAROUS_ERROR::INVALID_NUMBER_OF_EGGS:
			std::cerr << NUMBER_OF_EGGS_RANGE_STRING << std::endl;
			throw std::out_of_range(NUMBER_OF_EGGS_RANGE_STRING);
			break;
		default:
			std::cerr << "Unknown Error in Oviparous::setNumberOfEggs" << std::endl;
			throw std::runtime_error("UNKNOW");
			break;
		}
	}
	this->m_numberOfEggs = t_numberOfEggs;
}

std::string Oviparous::getInfo() const{
	std::stringstream ss;
	std::string parentInfo;

	parentInfo = Animal::getInfo();
	ss << parentInfo << TYPE << m_numberOfEggs;
	return ss.str();
}
