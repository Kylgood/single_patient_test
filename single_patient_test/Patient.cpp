#include <iostream>
#include "Patient.h"

//class Patient definitions

Patient::Patient()
	:complaint(0), last_name("default"), first_name("default"), sex_at_birth("default"), dob("default"), last_po(0)
{
	p_ch = new Chart;
	p_gen = new Generators;
	std::cout << "Welcome to the Emergency Room!" << std::endl;
}
void Patient::get_set_demographics()
{
	std::cout << "Please enter your last name." << std::endl;
	std::cin >> last_name;
	std::cout << "Please enter your first name." << std::endl;
	std::cin >> first_name;
	std::cout << "Please enter your biological sex at birth." << std::endl;
	std::cin >> sex_at_birth;
	std::cout << "Please enter your date of birth.  (Format: MM/DD/YY)" << std::endl;
	std::cin >> dob;
}
int Patient::chief_complaint()
{
	int count = 0;
	int input;

	std::cout << "What brings you into the emergency room?" << std::endl;
	std::cout << "Please select what is wrong by typing the corresponding number and pressing enter." << std::endl;
	std::cout << "1 - You are having chest pain and/or palpitations." << std::endl;
	std::cout << "2 - You are having trouble breathing or you are choking." << std::endl;
	std::cout << "3 - You have severe abdominal pain with or without nausea, vomiting, diarrhea." << std::endl;
	std::cout << "4 - You have a severe headache, vision changes, hearing loss, speech changes, or sudden weakness." << std::endl;
	std::cout << "6 - You were in a vehicular accident." << std::endl;
	std::cout << "7 - You think you might hurt or kill yourself." << std::endl;
	std::cout << "8 - You have a laceration or a nosebleed." << std::endl;
	std::cout << "9 - You were physically or sexually assaulted." << std::endl;
	std::cout << "10 - You fell or something hit you." << std::endl;
	std::cout << "11 - You just feel very sick, and at-home treatment is not working." << std::endl;
	std::cout << "12 - You do not know what is wrong, but you need help." << std::endl;
	std::cin >> input;
	while (input <= 0 || input > 12)
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid entry." << std::endl;
			std::cin >> input;
			++count;
			if (count >= 3) {
				std::cout << "Stay where you are.  A nurse is coming to get you." << std::endl;
				return -999;//follow this up
			}
		}
	}
	std::cout << "Thank you for your patience. A nurse will be with you shortly." << std::endl;
	return input;
}
void Patient::end_program()
{
	std::cout << "Exiting program. The nurse will input your information." << std::endl;
	exit(3);
}
void Patient::set_allergies(std::string s)
{
	allergies.push_back(s);
}
void Patient::set_vax(std::string s)
{
	vax.push_back(s);
}
void Patient::set_meds(std::string s)
{
	meds.push_back(s);
}
void Patient::set_last_po(unsigned int n)
{
	last_po = n;
}
void Patient::set_complaint(const int com)
{
	if (com != -999)
	{
		complaint = com;
	}
	else
	{
		end_program();
	}
}
void Patient::will_see_you_now()
{//stdcout the physician has seen you
	//part educational explain the equipment part entertainment
	//if (complaint == 3)
	//{

	//}

}
void Patient::print_demographics()
{
	std::cout << "Name: " << last_name << ", " << first_name << std::endl;
	std::cout << "Sex at Birth: " << sex_at_birth << std::endl;
	std::cout << "Date of Birth: " << dob << std::endl;

}