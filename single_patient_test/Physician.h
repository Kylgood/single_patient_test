#pragma once
#include "Nurse.h"

class Physician : public Provider
{
private:
	Nurse* p_rn;
	//abnormal vital signs flags:
	bool bp_abnormal = false;
	bool pulse_abnormal = false;
	bool low_sat = false;
	bool resp_abnormal = false;
	bool temp_abnormal = false;
	bool low_loc = false;
	

public:
	Physician(Patient*, Nurse*);
	void see_patient(Physician*);
	//abnormal vital signs functions to set
	void set_bp_flag();
	void set_pulse_flag();
	void set_sat_flag();
	void set_resp_flag();
	void set_temp_flag();
	void set_loc_flag();

	//workups
	void cardiac_workup();
	void respiratory_workup();
	void abd_workup();
	void neuro_workup();
	void trauma_workup();

	//systempause

	//these go inside other functions
	void order_lab_tests(std::string test);
	void order_oxygen();
	void order_imaging( std::string method);
	void order_ekg();
	void order_iv_drugs(std::string drug, std::string symptom);
	void explanation(std::string proc);
	void emergency_procedure( std::string w);
	void call_consult( std::string specialist);// = new surgeon, etc.
	void admit_to_hospital( std::string reason);
	
	//void pronounce_death(/*time of death?*/);
};