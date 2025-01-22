//EMERGENCY ROOM SINGLE PATIENT EXPERIENCE
//by Kyle Goodale
//CS50 Final Project
//part educational (ex: explain what a nonrebreather is)
//part entertainment
#pragma once
#include "chart.h"
#include "vitals.h"
#include "generators.h"
#include "Provider.h"
#include "Nurse.h"
#include "Patient.h"
#include "Physician.h"





int main()
{
    Patient user;
	user.get_set_demographics();
	Nurse nurse(&user);
	Physician doctor(&user, &nurse);
	int cc = user.chief_complaint();
	user.set_complaint(cc);
	nurse.triage();
	doctor.see_patient();
	
}



























