#pragma once
#include <string>

class Generators //for testing and simulation
{

public:
	Generators();
	const int sys_gen();
	const int dia_gen();
	const int pulse_gen();
	const int resp_gen();
	const float temp_gen();
	const int ox_gen();
	const int loc_gen();
	std::string time_gen();
};