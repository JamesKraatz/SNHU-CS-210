/*
 * Animal.h
 *
 *  Created on: Feb 10, 2021
 *      Author: 1948462_snhu
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <exception>


struct ANIMAL_ERROR {
	enum ERROR {
		SUCCESS = 0,
		NAME_TOO_LONG = -1,
		NAME_TOO_SHORT = -2,
		TRACKING_NUMBER_TOO_HI = -3,
		TRACKING_NUMBER_TOO_LO = -4,
		UNKNOWN_ERROR = INT_MIN};
};

const unsigned int NAME_LENGTH_MAX = 15;
const unsigned int NAME_LENGTH_MIN = 1;

const int NAME_COL_WIDTH = 15;
const int TRACKING_NUMBER_COL_WIDTH = 6;

const int TRACKING_NUMBER_MAX = 999999;
const int TRACKING_NUMBER_MIN = 1;

const std::string TRACKING_NUMBER_RANGE_STRING =
	"Tracking Number must be from 1 to 999999.";


class Animal {
	private:
		std::string m_name;
		std::string m_trackNum;

	public:
		Animal();
		Animal(int t_trackNum, std::string t_name);
		virtual ~Animal();

		std::string getName() const;
		int getTrackNum() const;

		void setName(std::string t_name);
		void setTrackNum(int t_trackNum);

		virtual std::string getInfo() const;
};

#endif /* ANIMAL_H_ */
