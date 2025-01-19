#pragma once
#include "generators.h"
#include "vitals.h"
#include "chart.h"
class Patient
{
private:
	int complaint;
	std::string last_name;
	std::string first_name;
	std::string sex_at_birth;
	std::string dob;
	std::vector<std::string> allergies;
	std::vector<std::string> vax;
	std::vector<std::string> meds;
	unsigned int last_po;
public:
	Generators* p_gen;
	Chart* p_ch;
	Patient();
	void get_set_demographics();
	int chief_complaint();
	void set_allergies(std::string s);
	void set_vax(std::string s);
	void set_meds(std::string s);
	void set_last_po(unsigned int n);
	void end_program();
	void set_complaint(const int);
	void will_see_you_now();
	void print_demographics();


};