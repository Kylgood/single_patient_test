
#include "vitals.h"

//class Vitals definitions

Vitals::Vitals(int sys, int dia, int hr, int rr, double t, int ox, int lc, std::string clock) //systolic, diastolic, heart rate, resp, temp, level conciousness
	:systolic(sys), diastolic(dia), pulse(hr), resps(rr), temp(t), o2_sat(ox), loc(lc), time_taken(clock)
{

}
int Vitals::show_heart()
{
	return pulse;

}
int Vitals::show_resps()
{
	return resps;
}
int Vitals::show_systolic()
{
	return systolic;
}
int Vitals::show_diastolic()
{
	return diastolic;
}

double Vitals::show_temp()
{
	return temp;
}

int Vitals::show_o2_sat()
{
	return o2_sat;
}
int Vitals::show_loc()
{
	return loc;
}

std::string Vitals::show_time() {

	return time_taken;


}