#pragma once
#include "Patient.h"
class Provider
{
protected:
	Patient* p_pt;
	Chart* p_chart;
public:

	Provider(Patient*, Chart*);
	void take_vital_signs();
	void chart_report();

};