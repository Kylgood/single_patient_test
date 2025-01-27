#pragma once
#include "Patient.h"
class Provider
{
protected:
	Patient* p_pt;
public:

	Provider(Patient*);
	void take_vital_signs(int, int, int, int, double, int, int);
	void chart_report();
	void pause_continue();

};