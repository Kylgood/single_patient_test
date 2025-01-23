

#include <iostream>
#include <sstream>
#include "Nurse.h"


//derived class Nurse definitions


Nurse::Nurse(Patient* q)
	:Provider(q)
{}
int Nurse::triage()
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
	std::cout << "Answering these questions will be helpful to the nurse in the triage process: " << std::endl;
	std::cout << "Please enter any foods or medications to which you are ALLERGIC.  If there are none, type q on a new line and press enter." << std::endl;
	while (getline(std::cin, line_allerg))
	{
		if (line_allerg == "q")
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
	std::cout << "Please list all of the vaccines that you have received. If there are none, type q on a new line and press enter. " << std::endl;
	while (getline(std::cin, line_vax))
	{
		if (line_vax == "q")
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
	std::cout << "Please list any medications you are CURRENTLY TAKING. If there are none, type q on a new line and press enter. " << std::endl;
	while (getline(std::cin, line_meds))
	{
		if (line_meds == "q")
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
	std::cout << "How many hours ago did you last eat or drink anything? " << std::endl;
	std::cin >> last_po;
	if (std::cin.fail())//if non-numeric...
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid entry. Please speak with the nurse. " << std::endl;
		std::cin >> last_po;
		
		
	}
	p_pt->set_last_po(last_po);
	return last_po;
}
void Nurse::draw_labs( std::string test) 
{
	if (test == "cerebrospinal fluid")
	{
		std::cout << "The physician will need to do a special procedure called a lumbar puncture to draw some of your cerebrospinal fluid. " << std::endl;
		std::cout << "cerebrospinal fluid is a normally clear fluid which is circulated through your spinal cord and fills the ventricles of your brain. " << std::endl;
		std::cout << "It provides cushioning and nourishment exclusive to the central nervous system. " << std::endl;
		std::cout << "The physician will numb an area in the small of your back, between the protuberances of two of the lumbar vertebrae, and " << std::endl;
		std::cout << " push a sterile needle to the center of your spinal cord.  The opening inside the hollow needle will fill with your " << std::endl;
		std::cout << "cerebrospinal fluid, and the physician will collect a small amount in vials.  If the fluid is cloudy or bloody, " << std::endl;
		std::cout << " it indicates dangerous inflammation in the central nervous system and/or possible brain swelling from injury or infection. " << std::endl;
	}
	if (test == "sexual assault panel")
	{
		std::cout << "The nurse will draw labs relevant to sexual assault and ask you to provide a urine sample.  If applicable, a pregnancy test done on this urine. " << std::endl;
		std::cout << "Prophylactic (medically preventive) sexually transmitted infection treatment will also be offered." << std::endl;
		std::cout << "A social worker and counselor will be summoned to help you deal with this crisis emotionally and psychologically. " << std::endl;
	}
	else
	{
		std::cout << "Your nurse will now draw the blood for the " << test << " studies and send the vials to the lab for analysis. " << std::endl;
	}
	
}
void Nurse::give_oxygen() 
{
	std::cout << "The nurse is placing a nonrebreather oxygen mask on your face, " << std::endl;
	std::cout << " at a rate of 12 liters per minute." << std::endl;
}
void Nurse::give_iv_drugs( std::string drugs) 
{
	std::cout << "The nurse is placing an IV in your arm and giving you " << drugs << " as ordered by the physician. " << std::endl;
}

void Nurse::give_iv_drugs( std::string drug1,  std::string drug2) 
{
	std::cout << "The nurse is placing an IV in your arm and giving you " << drug1 << " as ordered by the physician." << std::endl;
	std::cout << "The nurse will also give you hydration fluids for general support, including " << drug2 << "." << std::endl;
}
void Nurse::perform_ekg() 
{
	std::cout << "The nurse is now placing electrodes in a specific conformation on your skin to measure the signals from your heart. " << std::endl;
	std::cout << "Six electrodes will go on the left side of your torso, " << std::endl;
	std::cout << "where the strongest part of your heart is, and one electrode will go on each arm and leg. " << std::endl;
	std::cout << "The ten electrodes, if read in different sequences, will allow " << std::endl;
	std::cout << " the EKG equipment to capture the electrical pattern of your heart muscle from several different angles. " << std::endl;
	std::cout << "You will not feel any pain or other sensation from the machine during this procedure. " << std::endl;
}
void Nurse::pass_report()
{
	std::cout << "The nurse is calling report upstairs, which means the nurse is passing a " << std::endl;
	std::cout << "verbal summary of your condition and profile to the nurse counterpart " << std::endl;
	std::cout << "on one of the inpatient floors of this hospital, where your stay will be.  A staff member will bring you upstairs shortly. " << std::endl;
	std::cout << "Here is your chart: " << std::endl;
	chart_report();
}
void Nurse::discharge() 
{
	std::cout << "The nurse has given you your discharge paperwork and you are cleared to go home.  Here is a copy of the chart from your visit. " << std::endl;
	chart_report();
}