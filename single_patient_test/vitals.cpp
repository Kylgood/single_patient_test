#include "vitals.h"

//class Vitals definitions

Vitals::Vitals(const int sys, const int dia, const int hr, const int rr, const float t, const int ox, const int lc, std::string t) //systolic, diastolic, heart rate, resp, temp, level conciousness
	:systolic(sys), diastolic(dia), pulse(hr), resps(rr), temp(t), o2_sat(ox), loc(lc), time_taken(t)
{

}
const int Vitals::show_heart()
{
	return Vitals::pulse;

}
const int Vitals::show_resps()
{
	return Vitals::resps;
}
const int Vitals::show_systolic()
{
	return Vitals::systolic;
}
const int Vitals::show_diastolic()
{
	return Vitals::diastolic;
}

const float Vitals::show_temp()
{
	return Vitals::temp;
}

const int Vitals::show_o2_sat()
{
	return Vitals::o2_sat;
}
const int Vitals::show_loc()
{
	return Vitals::loc;
}

std::string Vitals::show_time() {

	return time_taken;


}