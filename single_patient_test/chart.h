#pragma once

#include <vector>
#include "vitals.h"

//forward declaration for the chart class's pointer
class Physician;

class Chart
{
private:
	Physician* doc_ptr;
	std::vector<Vitals*> chart;

public:
	Chart();
	void update_chart(Vitals*);
	void check_chart();
	void set_physician(Physician*);
	void combine_info(const int);
	void print_chart();
};