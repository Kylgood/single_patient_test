
#include <random>
#include <ctime>
#include "generators.h"


//Generators attempt to simulate vitals signs for testing purposes

Generators::Generators()
{}
int Generators::sys_gen()
{
	std::uniform_int_distribution<unsigned> sys_range(60, 200);
	std::default_random_engine x;
	int k = sys_range(x);
	int final = k;

	return final;

}
int Generators::dia_gen()
{
	std::uniform_int_distribution<unsigned> dia_range(40, 90);
	std::default_random_engine x;
	int k = dia_range(x);
	int final = k;

	return final;

}
int Generators::pulse_gen()
{
	std::uniform_int_distribution<unsigned> pulse_range(40, 130);
	std::default_random_engine x;
	int k = pulse_range(x);
	int final = k;

	return final;

}
int Generators::resp_gen()
{
	std::uniform_int_distribution<unsigned> resp_range(8, 30);
	std::default_random_engine x;
	int k = resp_range(x);
	int final = k;

	return final;
}
 float Generators::temp_gen()
{
	std::uniform_real_distribution<float> temp_range(34.0, 41.0);
	std::default_random_engine x;

	float k = temp_range(x);
	 float final = k;

	return final;
}

int Generators::ox_gen()
{
	std::uniform_int_distribution<unsigned> ox_range(75, 100);
	std::default_random_engine ox;
	int k = ox_range(ox);
	int final = k;

	return final;


}
int Generators::loc_gen()
{
	std::uniform_int_distribution<unsigned> loc_range(3, 15);
	std::default_random_engine x;
	int k = loc_range(x);
	int final = k;

	return final;
}
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