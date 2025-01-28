
#include <vector>
#include <iostream>
#include "chart.h"


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
			pulse_abnormal = true;
		}

		if (i->show_systolic() < 90 || i->show_diastolic() < 50)
		{
			bp_abnormal = true;
		}
		if (i->show_systolic() > 135 || i->show_diastolic() > 89)
		{
			bp_abnormal = true;
		}
		if (i->show_o2_sat() < 95)
		{
			low_sat = true;
		}

		if (i->show_temp() < 35.0)
		{
			temp_abnormal = true;
		}
		if (i->show_temp() > 38.0)
		{
			temp_abnormal = true;
		}
		if (i->show_resps() < 10)
		{
			resp_abnormal = true;
		}
		if (i->show_resps() > 22)
		{
			resp_abnormal = true;
		}
		if (i->show_loc() < 13)
		{
			low_loc = true;
		}
	}
}
std::string Chart::combine_info(const int c)
{
	//pulse_abnormal && bp_abnormal && low_sat && temp_abnormal && resp_abnormal && low_loc
	if (low_loc && resp_abnormal && low_sat)
	{
		return "rapid_sequence_intubation";
	}

	if (low_loc && bp_abnormal && c == 6)
	{
		return "blood transfusion";
	}
	if (low_loc && temp_abnormal && (c == 3 || c== 8))
	{
		return "IV antibiotics for life-threatening infection";
	}
	if (low_loc && (c == 8 || c == 4))
	{
		return "check blood sugar, check blood ETOH";

	}
	if (bp_abnormal)
	{
		return "fluids";
	}
	if (pulse_abnormal)
	{
		return "ekg for cardiac arrythmia";
	}
	if (temp_abnormal)
	{

		return "tylenol for fever control";

	}
	if (low_sat)
	{
		return "supplemental oxygen mask";
	}
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