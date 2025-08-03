//EMERGENCY ROOM SINGLE PATIENT EXPERIENCE
//by Kyle Goodale
//CS50 Final Project


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
	
	//Gemini suggests I seed the random number generator once

	std::random_device rd;

	//Gemini suggests the Mersenne Twister engine
	std::mt19937 gen(rd());
			
	Patient user;
	user.get_set_demographics();
	
	Nurse nurse(&user);
	Physician doctor(&user, &nurse);

	//Gemini suggests to set the physician for the chart
	user.p_ch->set_physician(&doctor);

	int cc = user.chief_complaint();
	user.set_complaint(cc);
	
	int tri = nurse.triage();
	
	//use the more efficient Gemini severity function
	int gap = ( tri > cc) ? tri : cc;
	user.p_gen->seed_vitals_by_severity(gap);

	
		/* Gemini reorganized my activating functions around
		* a central random engine...this commented list of seed function calls is 
		* my original code:
	
	sys_bp_engine.seed(sys_norm + gap);
	dia_bp_engine.seed(dia_norm + gap);
	pulse_engine.seed(pulse_norm + gap);
	resp_engine.seed(resp_norm + gap);
	temp_engine.seed(temp_norm + gap);
	ox_engine.seed(ox_norm + gap);
	loc_engine.seed(loc_norm + gap);
	nurse.take_vital_signs(lround(sys_bp_distr(sys_bp_engine)), lround(dia_bp_distr(dia_bp_engine)), lround(pulse_distr(pulse_engine)),
		lround(resp_distr(resp_engine)), temp_distr(temp_engine), lround(ox_distr(ox_engine)), lround(loc_distr(loc_engine))); */
	
	//and here is the improved version from Gemini:

	nurse.take_vital_signs(user.p_gen->generate_systolic(),
		user.p_gen->generate_diastolic(),
		user.p_gen->generate_pulse(),
		user.p_gen->generate_resps(),
		user.p_gen->generate_temp(),
		user.p_gen->generate_o2_sat(),
		user.p_gen->generate_loc());


	doctor.see_patient(&doctor);

	return 0;
	
}






























