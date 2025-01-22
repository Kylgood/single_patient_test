
#pragma once
#include <string>
#include <iostream>
class Generators //for testing and simulation
{

public:
	Generators();
	int sys_gen();
	int dia_gen();
	int pulse_gen();
	int resp_gen();
	float temp_gen();
	int ox_gen();
	int loc_gen();
	std::string time_gen();
};