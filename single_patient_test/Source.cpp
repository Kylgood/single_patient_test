//EMERGENCY ROOM SINGLE PATIENT EXPERIENCE
//by Kyle Goodale
//CS50 Final Project
//part educational (ex: explain what a nonrebreather is)
//part entertainment
#pragma once
#include <random>
#include "chart.h"
#include "vitals.h"
#include "generators.h"
#include "Provider.h"
#include "Nurse.h"
#include "Patient.h"
#include "Physician.h"





int main()
{
	int sp_seed = 117;
	int dp_seed = 77;
	int hr_seed = 79; 
	int rr_seed = 18;
	
	int ox_seed = 95;
	float temp_seed = 37.9;
	//sys bp generator
	std::default_random_engine sys_bp_engine;
	std::normal_distribution<> sys_bp_distr(120, 5);
	
    
	//dia bp generator
	std::default_random_engine dia_bp_engine;
	std::normal_distribution<> dia_bp_distr(80, 2);
	

	//heart rate bp generator
	std::default_random_engine pulse_engine;
	std::normal_distribution<> pulse_distr(75, 10);
	
	

	//resp generator
	std::default_random_engine resp_engine;
	std::normal_distribution<> resp_distr(16, 2);
	

	//temp generator
	std::default_random_engine temp_engine;
	std::normal_distribution<> temp_distr(37.0, .5);
	

	//ox generator
	std::default_random_engine ox_engine;
	std::normal_distribution<> ox_distr(98, 1);
	

	//loc generator
	std::default_random_engine loc_engine;
	std::normal_distribution<> loc_distr(13, 2);
	int loc_seed = 14;
	
	for (int i = 0; i < 5; ++i)
	{
		
		/*std::cout << lround(sys_bp_distr(sys_bp_engine)) << std::endl;
		std::cout << lround(dia_bp_distr(dia_bp_engine)) << std::endl;
		std::cout << lround(pulse_distr(pulse_engine)) << std::endl;
		std::cout << lround(resp_distr(resp_engine)) << std::endl;
		std::cout << temp_distr(temp_engine) << std::endl;*/
		std::cout << lround(loc_distr(loc_engine)) << std::endl;
		//std::cout << lround(ox_distr(ox_engine)) << std::endl;

		loc_engine.seed(loc_seed);
		
	}


	//create roles
	/*Patient user;
	user.get_set_demographics();
	Nurse nurse(&user);
	Physician doctor(&user, &nurse);
	int cc = user.chief_complaint();
	user.set_complaint(cc);
	nurse.triage();
	nurse.take_vital_signs(sys_bp_distr(sys_bp_engine), dia_bp_distr(dia_bp_engine), pulse_distr(pulse_engine),
		resp_distr(resp_engine), temp_distr(temp_engine), ox_distr(ox_engine), loc_distr(loc_engine));
	doctor.see_patient();
	*/
}



























