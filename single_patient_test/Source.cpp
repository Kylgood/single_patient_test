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
	
	//sys bp generator
	const int sys_norm = 120;
	std::default_random_engine sys_bp_engine;
	std::normal_distribution<> sys_bp_distr(sys_norm, 5);
	
    
	//dia bp generator
	const int dia_norm = 80;
	std::default_random_engine dia_bp_engine;
	std::normal_distribution<> dia_bp_distr(dia_norm, 2);
	

	//heart rate bp generator
	const int pulse_norm = 75;
	std::default_random_engine pulse_engine;
	std::normal_distribution<> pulse_distr(pulse_norm, 10);
	
	

	//resp generator
	const int resp_norm = 16;
	std::default_random_engine resp_engine;
	std::normal_distribution<> resp_distr(resp_norm, 2);
	

	//temp generator
	const float temp_norm = 37.0;
	std::default_random_engine temp_engine;
	std::normal_distribution<> temp_distr(temp_norm, .5);
	

	//ox generator
	const int ox_norm = 98;
	std::default_random_engine ox_engine;
	std::normal_distribution<> ox_distr(ox_norm, 1);
	

    //loc generator
	const int loc_norm = 13;
	std::default_random_engine loc_engine;
	std::normal_distribution<> loc_distr(loc_norm, 2);
	
	
	
	Patient user;
	user.get_set_demographics();
	Nurse nurse(&user);
	Physician doctor(&user, &nurse);
	int cc = user.chief_complaint();
	user.set_complaint(cc);
	int tri = nurse.triage();
	int gap = ( tri > cc) ? tri : cc ;
	sys_bp_engine.seed(sys_norm + gap);
	dia_bp_engine.seed(dia_norm + gap);
	pulse_engine.seed(pulse_norm + gap);
	resp_engine.seed(resp_norm + gap);
	temp_engine.seed(temp_norm + gap);
	ox_engine.seed(ox_norm + gap);
	loc_engine.seed(loc_norm + gap);
	nurse.take_vital_signs(lround(sys_bp_distr(sys_bp_engine)), lround(dia_bp_distr(dia_bp_engine)), lround(pulse_distr(pulse_engine)),
		lround(resp_distr(resp_engine)), temp_distr(temp_engine), lround(ox_distr(ox_engine)), lround(loc_distr(loc_engine)));
	doctor.see_patient();
	
}






























