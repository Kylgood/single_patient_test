#pragma once
#include "Provider.h"
class Nurse : public Provider
{

public:
	Nurse(Patient*);
	void triage();
	void draw_labs(const std::string test);
	void give_oxygen();
	void give_iv_drugs(const std::string drugs);
	void give_iv_drugs(const std::string drug1, const std::string drug);
	void perform_ekg();
	void pass_report();
	void discharge();
};