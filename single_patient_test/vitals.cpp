
#include "vitals.h"

//class Vitals definitions

Vitals::Vitals(int sys, int dia, int hr, int rr, double t, int ox, int lc, std::string clock) //systolic, diastolic, heart rate, resp, temp, level conciousness
	:systolic(sys), diastolic(dia), pulse(hr), resps(rr), temp(t), o2_sat(ox), loc(lc), time_taken(clock)
{

}
int Vitals::show_heart()
{
	return Vitals::pulse;

}
int Vitals::show_resps()
{
	return Vitals::resps;
}
int Vitals::show_systolic()
{
	return Vitals::systolic;
}
int Vitals::show_diastolic()
{
	return Vitals::diastolic;
}

double Vitals::show_temp()
{
	return Vitals::temp;
}

int Vitals::show_o2_sat()
{
	return Vitals::o2_sat;
}
 int Vitals::show_loc()
{
	return Vitals::loc;
}

std::string Vitals::show_time() {

	return time_taken;


}