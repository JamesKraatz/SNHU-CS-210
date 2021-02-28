/*
 * thezoo.h
 *
 *  Created on: Feb 21, 2021
 *      Author: 1948462_snhu
 */

#ifndef THEZOO_H_
#define THEZOO_H_

#include <iostream>
#include <jni.h>
#include <fstream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <map>
#include "animal.h"
#include "mammal.h"
#include "oviparous.h"
#include "bat.h"
#include "whale.h"
#include "sealion.h"
#include "crocodile.h"
#include "goose.h"
#include "pelican.h"
#include "tests.h"

int main();
void GenerateData();
void AddAnimal();
void RemoveAnimal();
void LoadDataFromFile();
void SaveDataToFile();
void DisplayAnimalData();
void DispalyMenu();

Animal* MakeNewAnimal(int t_trackNum, std::string t_name, std::string t_type,
		std::string t_subType, int t_eggs, int t_nurse);
int GetAnimalTrackNum();
std::string GetAnimalName();
int GetAnimalEggsOrNursingInfo(std::string t_animalType);
std::string ToLowerCase(std::string t_inputString);
void PrintAnimalDisplayLine(Animal* t_Animal);
void PrintAnimalDisplayTitle();


#endif /* THEZOO_H_ */
