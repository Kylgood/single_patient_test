#pragma once
#include "Patient.h"
class Provider
{
protected:
	Patient* p_pt;
public:

	//Gemini suggests a virtual destructor for the base class
	Provider(Patient*);
	virtual ~Provider() = default;
	

	void take_vital_signs(int, int, int, int, double, int, int);
	//Gemini: make const
	void chart_report() const;
	void pause_continue() const;

};