#include "chart.h"

//class Chart definitions

Chart::Chart() {}
void Chart::update_chart(Vitals* s)
{
	chart.push_back(s);
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
		std::cout << "Level of Consciousness: " << i->show_loc() << "/15" << std::endl;
		std::cout << i->show_temp() << " degrees Celsius" << std::endl;

	}


}