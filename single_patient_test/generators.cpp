
#include <random>
#include <ctime>
#include "generators.h"




//Generators attempt to simulate vitals signs for testing purposes
//Gemini suggested moving the actual seed function calls into the Generators class

//*my original code
/*
Generators::Generators()
{}

std::string Generators::time_gen()
{
	time_t now = time(0); // Get current time
	char buffer[26];

	if (ctime_s(buffer, sizeof(buffer), &now) == 0) {
		return buffer;
	}
	else
	{
		std::string error = "Error recording time.";
		return error;
	}
}
*/


// my original seeds and parameters have been moved here:
Generators::Generators()
	: sys_bp_distr(120, 10),
	dia_bp_distr(80, 5),
	pulse_distr(75, 15),
	resp_distr(16, 4),
	temp_distr(37.0, 1.5),
	ox_distr(97, 2),
	loc_distr(13, 3)
{
	// Seed all engines upon construction using a random_device
	std::random_device rd;
	sys_bp_engine.seed(rd());
	dia_bp_engine.seed(rd());
	pulse_engine.seed(rd());
	resp_engine.seed(rd());
	temp_engine.seed(rd());
	ox_engine.seed(rd());
	loc_engine.seed(rd());
}

std::string Generators::time_gen() {
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	// Use std::put_time for formatting (C++11 and later)
	// Note: std::put_time requires a tm struct, which can be obtained from time_t
	std::tm tm_buf;
#ifdef _WIN32
	localtime_s(&tm_buf, &now_c); // Windows specific
#else
	localtime_r(&now_c, &tm_buf); // POSIX specific
#endif
	ss << std::put_time(&tm_buf, "%c"); // "%c" is locale's preferred date and time representation
	return ss.str();
}

void Generators::seed_vitals_by_severity(int severity_gap) {
	// Adjust seeds based on severity gap.
	// A larger gap should lead to more deviation from normal.
	// The specific logic for how 'severity_gap' influences the seed/distribution
	// can be refined based on desired simulation behavior.
	sys_bp_engine.seed(120 + (unsigned int)(severity_gap * 5)); // Increase bias for BP
	dia_bp_engine.seed(80 + (unsigned int)(severity_gap * 2));
	pulse_engine.seed(75 + (unsigned int)(severity_gap * 7)); // Increase bias for Pulse
	resp_engine.seed(16 + (unsigned int)(severity_gap * 2));
	temp_engine.seed(37.0 + (unsigned int)(severity_gap * 0.5));
	ox_engine.seed(97 - (unsigned int)(severity_gap * 2)); // Decrease bias for O2 sat
	loc_engine.seed(13 - (unsigned int)(severity_gap * 1)); // Decrease bias for LOC
}

int Generators::generate_systolic() { return lround(sys_bp_distr(sys_bp_engine)); }
int Generators::generate_diastolic() { return lround(dia_bp_distr(dia_bp_engine)); }
int Generators::generate_pulse() { return lround(pulse_distr(pulse_engine)); }
int Generators::generate_resps() { return lround(resp_distr(resp_engine)); }
double Generators::generate_temp() { return temp_distr(temp_engine); }
int Generators::generate_o2_sat() { return lround(ox_distr(ox_engine)); }
int Generators::generate_loc() { return lround(loc_distr(loc_engine)); }

