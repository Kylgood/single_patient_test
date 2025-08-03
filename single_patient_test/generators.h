
#pragma once
#include <string>
#include <iostream>
#include <random>
#include "includes.h"
class Generators //for testing and simulation
{



private:
	//Google Gemini suggested moving the engine and distr
	// objects into the Generators class and removing
	// the arguments to distr
	//sys bp generator
	std::default_random_engine sys_bp_engine;
	std::normal_distribution<> sys_bp_distr;
	//dia bp generator
	std::default_random_engine dia_bp_engine;
	std::normal_distribution<> dia_bp_distr;
	//heart rate bp generator
	std::default_random_engine pulse_engine;
	std::normal_distribution<> pulse_distr;
	//resp generator
	std::default_random_engine resp_engine;
	std::normal_distribution<> resp_distr;
	//temp generator
	std::default_random_engine temp_engine;
	std::normal_distribution<> temp_distr;
	//ox generator
	std::default_random_engine ox_engine;
	std::normal_distribution<> ox_distr;
	//loc generator
	std::default_random_engine loc_engine;
	std::normal_distribution<> loc_distr;

public:
	Generators();
	std::string time_gen();

	//Gemini suggests functions for creating random vital signs
	int generate_systolic();
	int generate_diastolic();
	int generate_pulse();
	int generate_resps();
	double generate_temp();
	int generate_o2_sat();
	int generate_loc();

	//Gemini also suggests a function to re-seed the engines based on severity
	void seed_vitals_by_severity(int severity_gap);
};

