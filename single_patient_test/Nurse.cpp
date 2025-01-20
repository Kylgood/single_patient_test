#include <iostream>
#include <sstream>
#include "Nurse.h"


//derived class Nurse definitions


Nurse::Nurse(Patient* q)
	:Provider(q)
{}
void Nurse::triage()
{
	std::string line_allerg;
	std::string line_vax;
	std::string line_meds;
	std::string a_bridge;
	std::string v_bridge;
	std::string m_bridge;
	int last_po;
	//if complaint = 1, 2, 3, 4, 5, 6, 7, 8, 9 , 10, 11, 12
	//allergies
	std::cout << "You are next in line." << std::endl;
	std::cout << "Answering these questions will be helpful to the nurse in the triage process:" << std::endl;
	std::cout << "Please enter any foods or medications to which you are ALLERGIC.  If there are none, type q on a new line and press enter." << std::endl;
	while (getline(std::cin, line_allerg))
	{
		if (line_allerg == 'q')
		{
			break;
		}
		std::istringstream divider(line_allerg);
		while (divider >> a_bridge)
		{
			p_pt->set_allergies(a_bridge);
		}
	}
	std::cout << std::endl;
	//vaccines
	std::cout << "Please list all of the vaccines that you have received. If there are none, type q on a new line and press enter." << std::endl;
	while (getline(std::cin, line_vax))
	{
		if (line_vax == 'q')
		{
			break;
		}
		std::istringstream separate(line_vax);
		while (separate >> v_bridge)
		{
			p_pt->set_vax(v_bridge);
		}
	}
	std::cout << std::endl;
	//medications
	std::cout << "Please list any medications you are CURRENTLY TAKING. If there are none, type q on a new line and press enter." << std::endl;
	while (getline(std::cin, line_meds))
	{
		if (line_meds == 'q')
		{
			break;
		}
		std::istringstream wall(line_meds);
		while (wall >> m_bridge)
		{
			p_pt->set_meds(m_bridge);
		}
	}
	std::cout << std::endl;
	//last_PO
	std::cout << "How many hours ago did you last eat or drink anything?" << std::endl;
	std::cin >> last_po;
	if (std::cin.fail())//if non-numeric...
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid entry." << std::endl;
		std::cin >> last_po;
		++count;
		if (count >= 3) {
			std::cout << "Too many invalid entries, you will need to tell the nurse." << std::endl;
		}
	}
	p_pt->set_last_po(last_po);

	//now take the first set of vital signs:
	std::cout << "The nurse will now take a first set of vital signs." << std::endl;
	take_vital_signs();

	//next step depends on acuity:
	std::cout << "Your chart has been updated.  Thank you for your patience while we find an available room in the department." << std::endl;

}
void Nurse::draw_labs(const int dx) {}
void Nurse::give_oxygen() {}
void Nurse::place_iv() {}
void Nurse::perform_ekg() {}
void Nurse::pass_report() {}