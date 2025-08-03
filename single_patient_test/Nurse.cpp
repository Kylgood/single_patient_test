

#include <iostream>
#include <sstream>
#include "Nurse.h"


//derived class Nurse definitions
// --- Nurse Class Definitions ---

//Gemini added const to my functions and references where appropriate

Nurse::Nurse(Patient* q) : Provider(q) {}

int Nurse::triage() {
	std::string line_allerg;
	std::string line_vax;
	std::string line_meds;
	unsigned int last_po_input;

	pause_continue();
	std::cout << "\nYou are next in line." << std::endl;

	// Allergies
	std::cout << "\nPlease enter any foods or medications to which you are ALLERGIC." << std::endl;
	std::cout << "If there are none, or you are finished, type 'q' on a new line and press enter." << std::endl;
	// The previous std::cin.ignore after chief_complaint should handle clearing the buffer
	while (std::getline(std::cin, line_allerg) && line_allerg != "q") {
		std::istringstream divider(line_allerg);
		std::string a_bridge;
		while (divider >> a_bridge) {
			p_pt->set_allergies(a_bridge);
		}
	}

	// Vaccinations
	std::cout << "\nPlease list all of the vaccines that you have received." << std::endl;
	std::cout << "If there are none, or you are finished, type 'q' on a new line and press enter. " << std::endl;
	while (std::getline(std::cin, line_vax) && line_vax != "q") {
		std::istringstream separate(line_vax);
		std::string v_bridge;
		while (separate >> v_bridge) {
			p_pt->set_vax(v_bridge);
		}
	}

	// Medications
	std::cout << "\nPlease list any medications you are CURRENTLY TAKING. " << std::endl;
	std::cout << "If there are none, or you are finished, type 'q' on a new line and press enter. " << std::endl;
	while (std::getline(std::cin, line_meds) && line_meds != "q") {
		std::istringstream wall(line_meds);
		std::string m_bridge;
		while (wall >> m_bridge) {
			p_pt->set_meds(m_bridge);
		}
	}

	// Last PO (per os)
	do {
		std::cout << "\nHow many hours ago did you last eat or drink anything? " << std::endl;
		std::cin >> last_po_input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid entry. Please enter a number." << std::endl;
		}
		else {
			break; // Valid input, exit loop
		}
	} while (true);

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer after numeric input
	p_pt->set_last_po(last_po_input);
	return last_po_input;
}

void Nurse::draw_labs() const {
	std::cout << "\nYour nurse is now drawing blood from your IV for the required " << std::endl;
	std::cout << "studies and will send the vials to the lab for analysis. " << std::endl;
	pause_continue();
}

void Nurse::give_oxygen() const {
	std::cout << "\nThe nurse is placing a nonrebreather oxygen mask on your face, " << std::endl;
	std::cout << " at a rate of 12 liters per minute." << std::endl;
	pause_continue();
	std::cout << "Normal room air is a mixture composed mostly of oxygen and nitrogen." << std::endl;
	std::cout << "We breathe the air in and our lungs take the oxygen from this mixture." << std::endl;
	pause_continue();
	std::cout << "Using a tank full of pure oxygen and delivered with a mask and connecting tube, " << std::endl;
	std::cout << "we can maximize the nourishment which the cells of your body receive with each breath." << std::endl;
	pause_continue();
}

void Nurse::give_iv_drugs() {
	if (!iv_placed) {
		pause_continue();
		std::cout << "\nThe nurse is placing an intravenous line, a kind of flexible access port to your circulatory system" << std::endl;
		std::cout << "into your arm for medication and fluid delivery, as ordered by the physician. " << std::endl;
		pause_continue();
		std::cout << "You will feel a strong pinch! Do not move your arm or the nurse will have to start over!" << std::endl;
		pause_continue();
		std::cout << "The nurse placed the IV successfully, she will now hook up to a hydration machine or inject the prescribed " << std::endl;
		std::cout << "drug with some liquid solution so that it can enter your bloodstream smoothly." << std::endl;
		std::cout << "\nYou should start feeling at least a little better momentarily!" << std::endl;
		pause_continue();
		std::cout << "Administering medications and hydration fluids intravenously with sterile equipment is a safe " << std::endl;
		std::cout << "and efficient way to treat your symptoms and/or illness. " << std::endl;
		pause_continue();
		std::cout << "Try to keep the area of your skin" << std::endl;
		std::cout << "(usually the arm) where the nurse placed the angiocatheter uncovered and dry." << std::endl;
		pause_continue();
		std::cout << "Notify the nurse if you experience pain, itching, redness, swelling, or leakage near or at the IV site." << std::endl;
		pause_continue();
		std::cout << "IV infiltration is when the catheter becomes dislodged from the vein, and begins dumping fluid into the" << std::endl;
		std::cout << "superficial layers of the skin of your arm." << std::endl;
		pause_continue();
		std::cout << "This can create a dangerous bubble under your skin which can become infected." << std::endl;
		iv_placed = true;
		std::cout << std::endl;
	}
	std::cout << "The medication was successfully given." << std::endl;
	pause_continue();
}

void Nurse::perform_ekg() const {
	std::cout << "\nThe nurse is now placing electrodes in a specific conformation on your skin to measure the signals from your heart. " << std::endl;
	pause_continue();
	std::cout << "Six electrodes will go on the left side of your torso, " << std::endl;
	std::cout << "where the strongest part of your heart is, and one electrode will go on each arm and leg. " << std::endl;
	pause_continue();
	std::cout << "The ten electrodes will allow the EKG equipment to capture the " << std::endl;
	std::cout << "electrical pattern of your heart muscle from several different angles. " << std::endl;
	pause_continue();
	std::cout << "You will not feel any pain or other sensation from the machine during this procedure. " << std::endl;
	pause_continue();
	std::cout << "The EKG has been printed and the doctor will evaluate it." << std::endl;
	std::cout << std::endl;
}

void Nurse::pass_report() const {
	std::cout << "\n";
	pause_continue();
	std::cout << "The nurse is calling report upstairs, which means the nurse is passing a " << std::endl;
	std::cout << "detailed verbal summary of your condition and profile to inpatient nurse upstairs." << std::endl;
	std::cout << "\nA staff member will bring you upstairs shortly. " << std::endl;
	pause_continue();
	std::cout << "Here is your chart: " << std::endl;
	chart_report();
}

void Nurse::discharge() const {
	std::cout << "\nYour condition has improved enough that your life is not in danger and you will recover safely on your own!" << std::endl;
	std::cout << "Congratulations!" << std::endl;
	pause_continue();
	std::cout << "The nurse has given you your discharge paperwork and you are cleared to go home. Here is a copy of the chart from your visit. " << std::endl;
	std::cout << "Don't forget to validate your parking at the checkout desk!" << std::endl;
	chart_report();
}
