#pragma once
#include "Provider.h"
class Nurse : public Provider
{

public:
	Nurse(Patient*);
	void triage();
	void draw_labs(std::string test);
	void give_oxygen();
	void give_iv_drugs(std::string drugs);
	void give_iv_drugs(std::string drug1,  std::string drug2);
	void perform_ekg();
	void pass_report();
	void discharge();
};