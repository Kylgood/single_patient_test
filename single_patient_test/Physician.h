#pragma once
#include "Nurse.h"


class Physician : public Provider
{
private:
	Nurse* p_rn;
	std::string explanation;

public:
	Physician(Patient*, Nurse*);
	void see_patient();

	//workups
	void cardiac_workup();
	void respiratory_workup();
	void abd_workup();
	void neuro_workup();
	void psych_workup();
	void trauma_workup();
	void laceration_workup();
	void assault_workup();
	void medical_workup();



	//these go inside other functions
	void order_lab_tests(const std::string test);
	void order_oxygen();
	void order_imaging(const std::string method);
	void order_ekg();
	void order_iv_drugs(const std::string drug);
	void order_iv_drugs(const std::string drug1, const std::string drug2);
	void emergency_procedure(const int);
	void call_consult(const std::string specialist);// = new surgeon, etc.
	void admit_to_hospital(const std::string reason);
	//void pronounce_death(/*time of death?*/);
};