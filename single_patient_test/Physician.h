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
	//Gemini caught a situation where I was creating new variables
   //within the scope of the function, which 
   //will result in the abnormal vitals flags not working
   //properly
	//these functions must activate the existing class members for the 
	//flags to work

	void set_bp_flag() { bp_abnormal = true;}
	void set_pulse_flag() { pulse_abnormal = true; }
	void set_sat_flag() { low_sat = true; }
	void set_resp_flag() { resp_abnormal = true; }
	void set_temp_flag() { temp_abnormal = true; }
	void set_loc_flag() { low_loc = true; }

	//workups
	void cardiac_workup();
	void respiratory_workup();
	void abd_workup();
	void neuro_workup();
	void trauma_workup();

	//systempause

	//these go inside other functions
	//GEMINI: make const references to save memory
	void order_lab_tests(const std::string& test);
	void order_oxygen();
	void order_imaging( const std::string& method);
	void order_ekg();
	void order_iv_drugs( const std::string& drug, const std::string& symptom);
	void explanation(const std::string& proc);
	void emergency_procedure( const std::string& w);
	void call_consult( const std::string& specialist);// = new surgeon, etc.
	void admit_to_hospital( const std::string& reason);
	
	//void pronounce_death(/*time of death?*/);
};