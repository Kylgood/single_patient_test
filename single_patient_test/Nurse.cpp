

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
	std::cout << "Please enter any foods or medications to which you are ALLERGIC." << std::endl;
	std::cout << "If there are none, or you are finished, type q on a new line and press enter." << std::endl;
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
	std::cout << "Please list all of the vaccines that you have received." << std::endl;
	std::cout << "If there are none, or you are finished, type q on a new line and press enter. " << std::endl;
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
	std::cout << "Please list any medications you are CURRENTLY TAKING. " << std::endl;
	std::cout << "If there are none, or you are finished, type q on a new line and press enter. " << std::endl;
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
	
	
	if (test == "std screen")
	{
		pause_continue();
		std::cout << "The nurse will draw labs relevant to sexual assault and ask you to provide a urine sample.  " << std::endl;
		std::cout << "If applicable, a pregnancy test will be done on this urine. " << std::endl;
		pause_continue();
		std::cout << "Prophylactic (medically preventive) sexually transmitted infection treatment will also be offered." << std::endl;
		std::cout << "A social worker and counselor will be summoned to help you deal with this crisis emotionally and psychologically. " << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Your nurse will now draw the blood for the " << test << std::endl; 
		std::cout << "studies and send the vials to the lab for analysis. " << std::endl;
		pause_continue();
	}
	
}
void Nurse::give_oxygen() 
{
	
	std::cout << "The nurse is placing a nonrebreather oxygen mask on your face, " << std::endl;
	std::cout << " at a rate of 12 liters per minute." << std::endl;
	pause_continue();
	std::cout << "Normal room air is a mixture composed mostly of oxygen and nitrogen." << std::endl;
	std::cout << "We breathe the air in and our lungs take the oxygen from this mixture." << std::endl;
	pause_continue();
	std::cout << "Using a tank full of pure oxygen and delivered with a mask and connecting tube, " << std::endl;
	std::cout << "we can maximize the nourishment which the cells of your body receive with each breath." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

}
void Nurse::give_iv_drugs( std::string drugs) 
{
	
	std::cout << "The nurse is placing an IV in your arm and giving you " << drugs << ", as ordered by the physician. " << std::endl;
	std::cout << "Administering medications and hydration fluids intravenously with sterile equipment is a safe " << std::endl;
	std::cout << "and efficient way to treat your symptoms and/or illness.  Try to keep the site on your body, " << std::endl;
	std::cout << "(usually the arm) where the nurse placed the angiocatheter uncovered and dry." << std::endl;
	pause_continue();
	std::cout << "Notify the nurse if you experience pain, itching, redness, swelling, or leakage near or at the IV site." << std::endl;
	std::cout << "IV infiltration is when the catheter becomes dislodged from the vein, and begins dumping fluid into the" << std::endl;
	std::cout << "superficial layers of the skin of your arm." << std::endl;
	std::cout << "This can create a dangerous bubble under your skin which can become infected." << std::endl;
}
void Nurse::perform_ekg() 
{
	
	std::cout << "The nurse is now placing electrodes in a specific conformation on your skin to measure the signals from your heart. " << std::endl;
	pause_continue();
	std::cout << "Six electrodes will go on the left side of your torso, " << std::endl;
	std::cout << "where the strongest part of your heart is, and one electrode will go on each arm and leg. " << std::endl;
	std::cout << "The ten electrodes, if read in different sequences, will allow " << std::endl;
	std::cout << " the EKG equipment to capture the electrical pattern of your heart muscle from several different angles. " << std::endl;
	pause_continue();
	std::cout << "You will not feel any pain or other sensation from the machine during this procedure. " << std::endl;
}
void Nurse::pass_report()
{
	
	std::cout << "The nurse is calling report upstairs, which means the nurse is passing a " << std::endl;
	std::cout << "detailed verbal summary of your condition and profile to the nurse counterpart " << std::endl;
	std::cout << "on one of the inpatient floors of this hospital, where your stay will be." << std::endl;
	std::cout << "A staff member will bring you upstairs shortly. " << std::endl;
	pause_continue();
	std::cout << "Here is your chart: " << std::endl;
	chart_report();
}
void Nurse::discharge() 
{
	std::cout << "Your condition has improved enough that your life is not in danger and you will recover safely on your own!" << std::endl;
	std::cout << "Congratulations!" << std::endl;
	pause_continue();
	std::cout << "The nurse has given you your discharge paperwork and you are cleared to go home.  Here is a copy of the chart from your visit. " << std::endl;
	std::cout << "Don't forget to validate your parking at the checkout desk!" << std::endl;
	chart_report();
}