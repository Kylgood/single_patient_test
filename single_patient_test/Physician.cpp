#include <iostream>
#include "Physician.h"

//derived class Physician definitions


Physician::Physician(Patient* pt, Nurse* rn)
	:Provider(pt), p_rn(rn)
{
}
void Physician::see_patient()
{
	const int help = p_pt->show_complaint();

	switch (help)
	{
	case 1:
		cardiac_workup();
		break;
	case 2:
		respiratory_workup();
		break;
	case 3:
		gastro_workup();
		break;
	case 4:
		neuro_workup();
		break;
	case 5:
		trauma_workup();
		break;
	case 6:
		psych_workup();
		break;
	case 7:
		laceration_workup();
		break;
	case 8:
		assault_workup();
		break;
	case 9:
		trauma_workup();
		break;
	case 10:
		medical_workup();
		break;
	default:
		break;
		

	}



	
}

void Physician::cardiac_workup() 
{
	//check vital signs
	//check age
	//check gender
	//order triponin level
	//if pain, give nitroglycerin
	//if arrest, CPR and defibrillator and intubate and epinephrine
	//give oxygen 
}
void Physician::respiratory_workup() {}
void Physician::gastro_workup() {}
void Physician::neuro_workup() {}
void Physician::psych_workup() {}
void Physician::trauma_workup() {}
void Physician::laceration_workup() {}
void Physician::assault_workup() {}
void Physician::medical_workup() {}





//these go inside other functions
void Physician::order_lab_tests(const int t)
{
	p_rn->draw_labs(t);
}
void Physician::order_oxygen();
void Physician::order_ekg(const int) {}
void Physician::order_imaging(const int) {}
void Physician::order_iv_drugs(const int) {}
void Physician::emergency_procedure(const int);
void Physician::call_consult(const int);// = new surgeon, etc.
void Physician::admit_to_hospital();
void Physician::pronounce_death();