#pragma once

#include <vector>
#include "vitals.h"

class Chart
{
private:
	//abnormal vital signs flags:
	bool bp_abnormal = false;
	bool pulse_abnormal = false;
	bool low_sat = false;
	bool resp_abnormal = false;
	bool temp_abnormal = false;
	bool low_loc = false;

	std::vector<Vitals*> chart;
public:
	Chart();
	void update_chart(Vitals*);
	void check_chart();
	std::string combine_info(const int);
	void print_chart();
};