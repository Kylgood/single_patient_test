#pragma once
#include "Provider.h"

#include "includes.h"
class Nurse : public Provider
{
private: 
	bool iv_placed = false;
public:
    //Gemini: Make const
	Nurse(Patient*);
	int triage();
	void draw_labs() const;
	void give_oxygen() const;
	void give_iv_drugs();
	void perform_ekg() const;
	void pass_report() const;
	void discharge() const; 
};