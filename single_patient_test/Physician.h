#pragma once
#include "Nurse.h"


class Physician : public Provider
{
private:
	Nurse* p_rn;

public:
	Physician(Patient*, Nurse*);
	void see_patient();

	//workups
	void cardiac_workup();
	void respiratory_workup();
	void gastro_workup();
	void neuro_workup();
	void psych_workup();
	void trauma_workup();
	void laceration_workup();
	void assault_workup();
	void medical_workup();



	//these go inside other functions
	void order_lab_tests(const int);
	void order_oxygen();
	void order_imaging(const int);
	void order_ekg(const int);
	void order_iv_drugs(const int);
	void emergency_procedure(const int);
	void call_consult(const int);// = new surgeon, etc.
	void admit_to_hospital();
	void pronounce_death();
};