#pragma once

#include <vector>
#include "vitals.h"

//forward declaration for the chart class's pointer
class Physician;

class Chart
{
private:
	//Google Gemini suggested that I explicitly initialize 
	//doc_ptr to null_ptr
	Physician* doc_ptr = nullptr;

	//Gemini suggests that I use a unique_ptr as it will automatically 
	//handle destruction of objects
	std::vector<Vitals*> chart;

public:
	//Gemini suggests to add destructors
	Chart() = default;
	~Chart() = default;
	void update_chart(Vitals*);
	void check_chart();
	void set_physician(Physician*);
	//eliminate useless function
	//void combine_info(const int);

	//Gemini: make const
	void print_chart() const;
};