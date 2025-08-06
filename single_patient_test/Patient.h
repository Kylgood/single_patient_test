#pragma once
#include "generators.h"
#include "chart.h"
#include "includes.h"

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
	//Gemini again suggests unique pointers
	std::unique_ptr<Generators> p_gen; // Using unique_ptr for ownership
	std::unique_ptr<Chart> p_ch;
	//Gemini suggests destructor
	Patient();
	~Patient() = default;
	void get_set_demographics();
	int chief_complaint();
	//Gemini: use const references where possible to save memory
	void set_allergies(const std::string& s);
	void set_vax(const std::string& s);
	void set_meds(const std::string& s);
	void set_last_po(unsigned int n);
	void end_program();
	void set_complaint(int);
	//Gemini: make functions const where possible
	int show_age() const;
	std::string show_sex() const;
	int show_complaint() const;
	void print_demographics() const;
	void print_all_vax_meds() const;


};