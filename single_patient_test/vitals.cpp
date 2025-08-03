
#include "vitals.h"

//class Vitals definitions

//Gemini added const to my functions for best practice
// --- Vitals Class Definitions ---
Vitals::Vitals(int sys, int dia, int hr, int rr, double t, int ox, int lc, std::string clock)
	: systolic(sys), diastolic(dia), pulse(hr), resps(rr), temp(t), o2_sat(ox), loc(lc), time_taken(std::move(clock))
{
}

int Vitals::show_heart() const { return pulse; }
int Vitals::show_resps() const { return resps; }
int Vitals::show_systolic() const { return systolic; }
int Vitals::show_diastolic() const { return diastolic; }
double Vitals::show_temp() const { return temp; }
int Vitals::show_o2_sat() const { return o2_sat; }
int Vitals::show_loc() const { return loc; }
std::string Vitals::show_time() const { return time_taken; }