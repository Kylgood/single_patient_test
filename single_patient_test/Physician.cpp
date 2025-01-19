#include <iostream>
#include "Physician.h"

//derived class Physician definitions


Physician::Physician(Patient* pt, Nurse* rn)
	:Provider(pt), p_rn(rn)
{
}
const int Physician::see_patient()
{
	//p_pt->will_see_you_now();
	const int x = 1;
	return x;
}
void Physician::order_lab_tests(const int t)
{
	p_rn->draw_labs();
}
void Physician::order_ekg(const int) {}
void Physician::order_imaging(const int) {}
void Physician::order_iv_drugs(const int) {}
void Physician::emergency_procedure(const int);
void Physician::call_consult(const int);// = new surgeon, etc.
void Physician::admit_to_hospital();
void Physician::pronounce_death();