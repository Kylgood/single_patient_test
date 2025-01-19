//EMERGENCY ROOM SINGLE PATIENT EXPERIENCE
//by Kyle Goodale
//CS50 Final Project
//part educational (ex: explain what a nonrebreather is)
//part entertainment

#include "Physician.h"




int main()
{
	Patient user;
	Nurse nurse(&user);
	Physician doctor(&user, &nurse);
	user.get_set_demographics();
	const int cc = user.chief_complaint();
	user.set_complaint(cc);
	nurse.triage();
	doctor.see_patient();

}



























