
#include "Provider.h"
#include <iostream>
#include <iomanip>
#include <string>
//base class Provider definitions


// --- Provider Class Definitions ---
Provider::Provider(Patient* p) : p_pt(p) {}

void Provider::take_vital_signs(int sy, int di, int pu, int re, double te, int ox, int lo) {
	std::cout << "\nThe provider will now take a set of your vital signs. " << std::endl;
	int systolic = sy;
	pause_continue();
	std::cout << "Your systolic blood pressure was " << systolic << " millimeters of mercury." << std::endl;
	std::cout << "This is the pressure against the walls of your arteries when " << std::endl;
	std::cout << "your heart contracts and sends blood through them to the rest of your body." << std::endl;
	pause_continue();
	std::cout << "It is the 'lub' of the 'lub-dub' sound of a single heartbeat." << std::endl;
	pause_continue();
	int diastolic = di;
	std::cout << "Your diastolic blood pressure was " << diastolic << " millimeters of mercury." << std::endl;
	std::cout << "This is the pressure in your arteries when your heart is refilling. It is the 'dub' sound of the 'lub-dub'." << std::endl;
	pause_continue();
	int pulse = pu;
	std::cout << "\nYour heart is beating at " << pulse << " beats per minute." << std::endl;
	pause_continue();
	int resp = re;
	std::cout << "\nYour lungs inhale and exhale at a rate of " << resp << " cycles per minute." << std::endl;
	pause_continue();
	double temp = te;
	std::cout << "\nYour temperature was " << std::fixed << std::setprecision(1) << temp << " degrees Celsius." << std::endl;
	std::cout << "Normal human body temperature in celsius is 37 degrees." << std::endl;
	pause_continue();
	int spO2 = ox;
	std::cout << "\nYour oxygen saturation was " << spO2 << "%. This is the percentage of oxygen in your blood." << std::endl;
	pause_continue();
	int loc = lo;
	std::cout << "\nYour level of consciousness was " << loc << std::endl;
	std::cout << "On the Glasgow Coma Scale, we want a healthy person to be at or just under 15." << std::endl;
	std::cout << std::endl;

	std::string timestamp = p_pt->p_gen->time_gen();

    //Gemini added the make_unique function
	// Create a unique_ptr and pass it to update_chart
	p_pt->p_ch->update_chart(std::make_unique<Vitals>(systolic, diastolic, pulse, resp, temp, spO2, loc, timestamp));
}

void Provider::chart_report() const {
	p_pt->print_demographics();
	std::cout << std::endl;
	p_pt->print_all_vax_meds();
	std::cout << std::endl;
	p_pt->p_ch->print_chart();
}

//Gemini insured that my input buffers were flushed below
//Gemini also added const to my functions

void Provider::pause_continue() const {
	std::cout << "\nPress Enter to continue..." << std::endl;
	// Clear any leftover characters in the buffer before waiting for Enter
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get(); // Wait for a single character (Enter key press)
}
