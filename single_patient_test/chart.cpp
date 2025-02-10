
#include <vector>
#include <iostream>
#include "chart.h"
#include "Physician.h"

//class Chart definitions


Chart::Chart() {}
void Chart::update_chart(Vitals* s)
{
	chart.push_back(s);
}

void Chart::check_chart()
{
	//search chart for abnormal vital signs
	for (auto i : chart)
	{
		if (i->show_heart() < 60 || i->show_heart() > 120)
		{
			
			std::cout << "\nAbnormal heart rate." << std::endl;
			doc_ptr->set_pulse_flag();
		}

		if (i->show_systolic() < 90 || i->show_diastolic() < 50)
		{
			std::cout << "\nAbnormal blood pressure." << std::endl;
			doc_ptr->set_bp_flag();
		}
		if (i->show_systolic() > 135 || i->show_diastolic() > 89)
		{
			std::cout << "\nAbnormal blood pressure.\n" << std::endl;
			doc_ptr->set_bp_flag();
		}
		if (i->show_o2_sat() < 95)
		{
			
			std::cout << "\nAbnormal oxygen saturation.\n" << std::endl;
			doc_ptr->set_sat_flag();
		}

		if (i->show_temp() < 35.0)
		{
			std::cout << "\nAbnormal body temperature.\n" << std::endl;
			doc_ptr->set_temp_flag();
		}
		if (i->show_temp() > 38.0)
		{
			std::cout << "\nAbnormal body temperature.\n" << std::endl;
			doc_ptr->set_temp_flag();
		}
		if (i->show_resps() < 10)
		{
			std::cout << "\nAbnormal respiratory rate.\n" << std::endl;
			doc_ptr->set_resp_flag();
		}
		if (i->show_resps() > 22)
		{
			std::cout << "\nAbnormal respiratory rate.\n" << std::endl;
			doc_ptr->set_resp_flag();
		}
		if (i->show_loc() < 13)
		{
			std::cout << "\nLevel of consciousness is below normal.\n" << std::endl;
			std::cout << std::endl;
			doc_ptr->set_loc_flag();
		}
	}
}

void Chart::set_physician(Physician* p)
{
	doc_ptr = p;
}

void Chart::print_chart()
{
	for (auto i : chart)
	{
		std::cout << std::endl;
		std::cout << i->show_time() << std::endl;
		std::cout << "Heart Rate: " << i->show_heart() << std::endl;
		std::cout << "Respiration Rate: " << i->show_resps() << std::endl;
		std::cout << "Blood Pressure: " << i->show_systolic() << "/" << i->show_diastolic() << std::endl;
		std::cout << "Temperature: " << i->show_temp() << " degrees Celsius" << std::endl;
		std::cout << "Oxygen Saturation: " << i->show_o2_sat() << " percent" << std::endl;
		std::cout << "Level of Consciousness: " << i->show_loc() << "/15" << std::endl;		

	}


}