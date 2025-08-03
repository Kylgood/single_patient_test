

#include <iostream>
#include "Patient.h"


//Gemini made the expected const and reference adjustments for memory efficiency
//and error protection

// --- Patient Class Definitions ---
Patient::Patient()
	: complaint(0), age(0), last_po(0),
	p_gen(std::make_unique<Generators>()), // Initialize unique_ptrs
	p_ch(std::make_unique<Chart>())
{
	std::cout << "Welcome to the Emergency Room!" << std::endl;
}

void Patient::get_set_demographics() {
	std::cout << "Please enter your last name." << std::endl;
	std::cin >> last_name;
	std::cout << "Please enter your first name." << std::endl;
	std::cin >> first_name;
	std::cout << "Please enter your biological sex at birth." << std::endl;
	std::cin >> sex_at_birth;
	std::cout << "Please enter your age." << std::endl;
	std::cin >> age;
	std::cout << "Please enter your date of birth. (Format: MM/DD/YY)" << std::endl;
	std::cin >> dob;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer after numeric/single-word inputs
}

int Patient::chief_complaint() {
	int input;
	do {
		std::cout << "\nWhat brings you into the emergency room? (Choose your disease!)" << std::endl;
		std::cout << "Please select what is wrong by typing the corresponding number and pressing enter." << std::endl;
		std::cout << "\n1 - You are having chest pain and/or palpitations." << std::endl;
		std::cout << "\n2 - You are having trouble breathing or you are choking." << std::endl;
		std::cout << "\n3 - You have severe abdominal pain with or without nausea, vomiting, diarrhea." << std::endl;
		std::cout << "\n4 - You have a severe headache, vision changes, hearing loss, speech changes, or sudden weakness." << std::endl;
		std::cout << "\n5 - You were in a vehicular accident." << std::endl;
		std::cout << "\nEnter your choice: ";
		std::cin >> input;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid entry. Please enter a number." << std::endl;
			input = -1; // Set to an invalid value to repeat loop
		}
		else if (input <= 0 || input >= 6) {
			std::cout << "Invalid choice. Please select a number between 1 and 5." << std::endl;
		}
	} while (input <= 0 || input >= 6);

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
	std::cout << "Thank you for your patience. A nurse will be with you shortly." << std::endl;
	return input;
}

void Patient::end_program() {
	std::cout << "Exiting program. The nurse will input your information." << std::endl;
	exit(3); // Standard library function to exit program
}

void Patient::set_allergies(const std::string& s) { allergies.push_back(s); }
void Patient::set_vax(const std::string& s) { vax.push_back(s); }
void Patient::set_meds(const std::string& s) { meds.push_back(s); }
void Patient::set_last_po(unsigned int n) { last_po = n; }

void Patient::set_complaint(int com) {
	if (com != -999) { // -999 was a placeholder for invalid input, now handled by chief_complaint loop
		complaint = com;
	}
	else {
		end_program();
	}
}

int Patient::show_age() const { return age; }
std::string Patient::show_sex() const { return sex_at_birth; }
int Patient::show_complaint() const { return complaint; }

void Patient::print_demographics() const {
	std::cout << "Name: " << last_name << ", " << first_name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Sex at Birth: " << sex_at_birth << std::endl;
	std::cout << "Date of Birth: " << dob << std::endl;
}

void Patient::print_all_vax_meds() const {
	std::cout << "\nALLERGIES" << std::endl;
	if (allergies.empty()) {
		std::cout << "None reported." << std::endl;
	}
	else {
		for (const auto& i : allergies) {
			std::cout << i << std::endl;
		}
	}

	std::cout << "\nVACCINATIONS" << std::endl;
	if (vax.empty()) {
		std::cout << "None reported." << std::endl;
	}
	else {
		for (const auto& k : vax) {
			std::cout << k << std::endl;
		}
	}

	std::cout << "\nMEDICATIONS" << std::endl;
	if (meds.empty()) {
		std::cout << "None reported." << std::endl;
	}
	else {
		for (const auto& m : meds) {
			std::cout << m << std::endl;
		}
	}
}