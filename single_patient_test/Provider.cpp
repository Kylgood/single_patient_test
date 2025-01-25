
#include "Provider.h"
#include <iostream>
#include <string>
//base class Provider definitions


Provider::Provider(Patient* p)
	:p_pt(p)
{}
void Provider::take_vital_signs(int sy, int di, int pu, int re, float te, int ox, int lo)
{
	//now take the first set of vital signs:
	std::cout << "The nurse will now take a set of your vital signs. " << std::endl;
	int systolic = sy;
	std::cout << "Your systolic blood pressure was " << systolic <<" millimeters of mercury"<< std::endl;
	std::cout << "This is the pressure against the walls of your arteries when " << std::endl;
	std::cout << "your heart contracts and sends blood through them to the rest of your body." << std::endl;
	std::cout << "It is the 'lub' of the 'lub-dub' sound of a single heartbeat." << std::endl;
	int diastolic = di;
	std::cout << "Your diastolic blood pressure was " << diastolic << " millimeters of mercury." << std::endl;
	std::cout << "This is the pressure in your arteries when your heart is refilling.  It is the 'dub' sound of the 'lub-dub'." << std::endl;
	int pulse = pu;
	std::cout << std::endl;
	std::cout << "Your heart is beating at " << pulse << " beats per minute." << std::endl;
	int resp = re;
	std::cout << std::endl;
	std::cout << "Your lungs inhale and exhale at a rate of " << resp << " per minute." << std::endl;
	float temp = te;
	std::cout << std::endl;
	std::cout << "Your temperature was " << temp << std::endl;
	std::cout << "Normal human body temperature in celsius is 37 degrees." << std::endl;
	int spO2 = ox;
	std::cout << std::endl;
	std::cout << "Your oxygen saturation was " << spO2 << ".  This is the percentage of oxygen in your blood." << std::endl;
	int loc = lo;
	std::cout << std::endl;
	std::cout << "Your level of consciousness was " << loc << std::endl;
	std::cout << "On the Glasgow Coma Scale, we want a healthy person to be at or just under 15." << std::endl;
	std::cout << std::endl;

	
	
	std::string timestamp = p_pt->p_gen->time_gen();

	Vitals* s = new Vitals(systolic, diastolic, pulse, resp, temp, spO2, loc, timestamp);
	p_pt->p_ch->update_chart(s);
}
void Provider::chart_report()
{
	p_pt->print_demographics();
	p_pt->p_ch->print_chart();
}
void Provider::pause_continue()
{
	std::string in = "1";
	while (in != "c")
	{
		std::cout << "Type 'c' to continue:" << std::endl;
		std::cin >> in;
		if (in == " ")
		{
			break;
		}
	}

}