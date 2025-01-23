
#include "Provider.h"

//base class Provider definitions


Provider::Provider(Patient* p)
	:p_pt(p)
{}
void Provider::take_vital_signs(int sy, int di, int pu, int re, float te, int ox, int lo)
{
	//now take the first set of vital signs:
	std::cout << "The nurse will now take a set of your vital signs. " << std::endl;
	int systolic = sy;
	int diastolic = di;
	int pulse = pu;
	int resp = re;
	float temp = te;
	int spO2 = ox;
	int loc = lo;
	
	std::string timestamp = p_pt->p_gen->time_gen();

	Vitals* s = new Vitals(systolic, diastolic, pulse, resp, temp, spO2, loc, timestamp);
	p_pt->p_ch->update_chart(s);
}
void Provider::chart_report()
{
	p_pt->print_demographics();
	p_pt->p_ch->print_chart();
}