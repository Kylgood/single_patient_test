#pragma once
#include "generators.h"
#include "chart.h"


class Patient
{
private:
	
	int complaint;
	std::string last_name;
	std::string first_name;
	std::string sex_at_birth;
	std::string dob;
	unsigned int age;
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
	void set_complaint( int);
	int show_age();
	std::string show_sex();
	int show_complaint();
	void print_demographics();
	void print_all_vax_meds();


};