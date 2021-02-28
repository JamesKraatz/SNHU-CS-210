/*
/ * Animal.cpp
 *
 *  Created on: Feb 10, 2021
 *      Author: 1948462_snhu
 */

#include "animal.h"

/**
 * Animal parent class
 */

/**
 * Default initialization
 */
Animal::Animal(){
	m_name = "               ";
	m_trackNum = "000000";
}

/**
 * overload constructor; initialize with non-default dat
 */
Animal::Animal(int t_trackNum, std::string t_name) {
	try {
		setTrackNum(t_trackNum);
	} catch (const std::exception& e) {
		std::cerr << "Unable to set Animal::trackNum" << std::endl;
		throw std::runtime_error(e.what());
	}

	try {
		setName(t_name);
	} catch (const std::exception& e) {
		std::cerr << "Unable to set Animal::name" << std::endl;
		throw std::runtime_error(e.what());
	}
}

/**
 * default destructor
 */
Animal::~Animal() = default;

/**
 * m_name Accessor
 */
std::string Animal::getName() const {
	return this->m_name;
}

/**
 * m_trackNum Accessor
 */
int Animal::getTrackNum() const {
	int trackNumVal;							// int to return for tracking number
	std::string trackNumStr;					// working variable to store m_trackNum in
	std::stringstream ss;						// string stream used format string m_trakcnum to int
	trackNumStr = this->m_trackNum;				// assign m_trackNum to working variable
	ss << trackNumStr;							// load string into stream ss
	ss >> trackNumVal;							// get int from stream ss
	return trackNumVal;							// return int
}

/**
 * m_name Mutator
 * Input t_name must be from 1 to 15 charscters long.
 * t_string will be padded on the right with spaces to make the
 * whole string 15 characters long.
 */
void Animal::setName(std::string t_name) {
	try {
		if (t_name.length() > NAME_LENGTH_MAX) {
			throw ANIMAL_ERROR::NAME_TOO_LONG;	// throw error if input string too long
		}
		if (t_name.length() < NAME_LENGTH_MIN) {
			throw ANIMAL_ERROR::NAME_TOO_SHORT;	// throw error if input string too short
		}
	} catch (int thrownError){
		// Catch Errors and output message to std::cerr.
		// Rethrow new message for caller error management
		switch(thrownError){
		case ANIMAL_ERROR::NAME_TOO_LONG:
			std::cerr << "Name is too long." << std::endl;
			std::cerr << "Maximum name length is " << NAME_LENGTH_MAX << " characters." << std::endl;
			throw std::out_of_range("NAME_TOO_LONG");
			break;
		case ANIMAL_ERROR::NAME_TOO_SHORT:
			std::cerr << "Name is too short." << std::endl;
			std::cerr << "Minimum name length is " << NAME_LENGTH_MIN << " characters." << std::endl;
			throw std::out_of_range("NAME_TOO_SHORT");
			break;
		default:
			std::cerr << "Unknown Error in Animal::setName" << std::endl;
			throw std::runtime_error("UNKNOWN");
			break;
		}
	}

	std::stringstream ss;						// declare string stream to format t_name
	std::string name;							// declare string working variable

	// put string into stream ss with formatting
	ss << std::left << std::setw(NAME_COL_WIDTH ) << std::setfill(' ') << t_name;
	this->m_name = ss.str();					// output formatted string to m_name
}

/**
 * t_trackNum Mutator
 * Input t_trackNum is converted to a six digit 0 left padded string
 */
void Animal::setTrackNum(int t_trackNum) {
	try {
		if(t_trackNum > TRACKING_NUMBER_MAX) {
			throw ANIMAL_ERROR::TRACKING_NUMBER_TOO_HI;	// Throw error if t_trackNum is too hi
		}
		if(t_trackNum < TRACKING_NUMBER_MIN) {
			throw ANIMAL_ERROR::TRACKING_NUMBER_TOO_LO;	// Throw error if t_trackNum is too lo
		}
	} catch (int thrownError){
		// Catch Errors and output message to std::cerr.
		// Rethrow new message for caller error management
		switch(thrownError){
		case ANIMAL_ERROR::TRACKING_NUMBER_TOO_HI:
			std::cerr << "Tracking Number is too large. " << std::endl;
			std::cerr << TRACKING_NUMBER_RANGE_STRING << std::endl;
			throw std::out_of_range("TRACKING_NUMBER_TOO_HI");
			break;
		case ANIMAL_ERROR::TRACKING_NUMBER_TOO_LO:
			std::cerr << "Tracking Number is less than allowed. " << std::endl;
			std::cerr << TRACKING_NUMBER_RANGE_STRING << std::endl;
			throw std::out_of_range("TRACKING_NUMBER_TOO_LO");
			break;
		default:
			std::cerr << "Unknown Error in Animal::setTrackNum" << std::endl;
			throw std::runtime_error("UNKNOWN");
			break;
		}
	}

	std::stringstream ss;						// declare string stream to format t_name
	std::string trackNumStr;					// declare string working variable

	// put string into stream ss with formatting
	ss << std::setw(TRACKING_NUMBER_COL_WIDTH) << std::setfill('0') << t_trackNum << std::endl;
	ss >> trackNumStr;
	this->m_trackNum = trackNumStr;				// output formatted string to t_trackNum
}

/**
 * Outputs Animal data as a formatted string
 */
std::string Animal::getInfo() const {
	std::stringstream ss;
	ss << this->m_trackNum << this->m_name;
	return ss.str();
}
