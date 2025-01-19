#pragma once

#include <vector>
#include "vitals.h"

class Chart
{
private:
	std::vector<Vitals*> chart;
public:
	Chart();
	void update_chart(Vitals*);
	void print_chart();
};