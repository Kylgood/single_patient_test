#pragma once
#include "Provider.h"
class Nurse : public Provider
{

public:
	Nurse(Patient*);
	void triage();
	void draw_labs(const int);
	void give_oxygen();
	void place_iv();
	void perform_ekg();
	void pass_report();
};