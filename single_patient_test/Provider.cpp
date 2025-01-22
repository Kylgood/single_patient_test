
#include "Provider.h"

//base class Provider definitions


Provider::Provider(Patient* p)
	:p_pt(p)
{}
void Provider::take_vital_signs()
{

	int systolic = p_pt->p_gen->sys_gen();
	int diastolic = p_pt->p_gen->dia_gen();
	int pulse = p_pt->p_gen->pulse_gen();
	int resp = p_pt->p_gen->resp_gen();
	float temp = p_pt->p_gen->temp_gen();
	 int spO2 = p_pt->p_gen->ox_gen();
	int loc = p_pt->p_gen->loc_gen();
	
	std::string timestamp = p_pt->p_gen->time_gen();

	Vitals* s = new Vitals(systolic, diastolic, pulse, resp, temp, spO2, loc, timestamp);
	p_pt->p_ch->update_chart(s);
}
void Provider::chart_report()
{
	p_pt->print_demographics();
	p_pt->p_ch->print_chart();
}