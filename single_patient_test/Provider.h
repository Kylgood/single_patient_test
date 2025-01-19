#pragma once
#include "Patient.h"
class Provider
{
protected:
	Patient* p_pt;
public:

	Provider(Patient*);
	void take_vital_signs();
	void chart_report();

};