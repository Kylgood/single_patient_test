#pragma once
#include "Provider.h"
class Nurse : public Provider
{

public:
	Nurse(Patient*);
	void triage();
	void draw_labs(const std::string test);
	void give_oxygen(const std::string lpm, const std::string mask);
	void place_iv_give_drugs( const std::string drugs);
	void perform_ekg();
	void pass_report();
};