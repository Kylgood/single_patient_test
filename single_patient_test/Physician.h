#pragma once
#include "Nurse.h"


class Physician : public Provider
{
private:
	Nurse* p_rn;

public:
	Physician(Patient*, Nurse*);
	const int see_patient();
	void order_lab_tests(const int);
	void order_imaging(const int);
	void order_ekg(const int);
	void order_iv_drugs(const int);
	void emergency_procedure(const int);
	void call_consult(const int);// = new surgeon, etc.
	void admit_to_hospital();
	void pronounce_death();
};