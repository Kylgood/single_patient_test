
#include <vector>
#include <iostream>
#include "chart.h"
#include "Physician.h"

//class Chart definitions

//Gemini made some best practice adjustments such as const and use of
//references to save memory, as well as unique pointers



// --- Chart Class Definitions ---
void Chart::update_chart(std::unique_ptr<Vitals> s) {
	chart.push_back(std::move(s)); // Move the unique_ptr into the vector
}

void Chart::check_chart() {
	if (!doc_ptr) {
		std::cerr << "Error: Physician not set for chart. Cannot check vital signs." << std::endl;
		return;
	}
	for (const auto& i : chart) { // Iterate using const reference to unique_ptr
		if (i->show_heart() < 60 || i->show_heart() > 120) {
			std::cout << "\nAbnormal heart rate." << std::endl;
			doc_ptr->set_pulse_flag();
		}
		if (i->show_systolic() < 90 || i->show_diastolic() < 50) {
			std::cout << "\nAbnormal low blood pressure." << std::endl;
			doc_ptr->set_bp_flag();
		}
		if (i->show_systolic() > 135 || i->show_diastolic() > 89) {
			std::cout << "\nAbnormal high blood pressure.\n" << std::endl;
			doc_ptr->set_bp_flag();
		}
		if (i->show_o2_sat() < 95) {
			std::cout << "\nAbnormal oxygen saturation.\n" << std::endl;
			doc_ptr->set_sat_flag();
		}
		if (i->show_temp() < 35.0) {
			std::cout << "\nAbnormal low body temperature.\n" << std::endl;
			doc_ptr->set_temp_flag();
		}
		if (i->show_temp() > 38.0) {
			std::cout << "\nAbnormal high body temperature.\n" << std::endl;
			doc_ptr->set_temp_flag();
		}
		if (i->show_resps() < 10) {
			std::cout << "\nAbnormal low respiratory rate.\n" << std::endl;
			doc_ptr->set_resp_flag();
		}
		if (i->show_resps() > 22) {
			std::cout << "\nAbnormal high respiratory rate.\n" << std::endl;
			doc_ptr->set_resp_flag();
		}
		if (i->show_loc() < 13) {
			std::cout << "\nLevel of consciousness is below normal.\n" << std::endl;
			std::cout << std::endl;
			doc_ptr->set_loc_flag();
		}
	}
}

void Chart::set_physician(Physician* p) {
	doc_ptr = p;
}

void Chart::print_chart() const {
	for (const auto& i : chart) { // Iterate using const reference to unique_ptr
		std::cout << std::endl;
		std::cout << "Time: " << i->show_time() << std::endl;
		std::cout << "Heart Rate: " << i->show_heart() << std::endl;
		std::cout << "Respiration Rate: " << i->show_resps() << std::endl;
		std::cout << "Blood Pressure: " << i->show_systolic() << "/" << i->show_diastolic() << std::endl;
		std::cout << "Temperature: " << std::fixed << std::setprecision(1) << i->show_temp() << " degrees Celsius" << std::endl;
		std::cout << "Oxygen Saturation: " << i->show_o2_sat() << " percent" << std::endl;
		std::cout << "Level of Consciousness: " << i->show_loc() << "/15" << std::endl;
	}
}