
#include <iostream>
#include "Physician.h"

//derived class Physician definitions


Physician::Physician(Patient* pt, Nurse* rn)
	:Provider(pt), p_rn(rn)
{
}

void Physician::see_patient(Physician* g)
{
	int c = p_pt->show_complaint();
	//pulse_abnormal && bp_abnormal && low_sat && temp_abnormal && resp_abnormal && low_loc

	p_pt->p_ch->set_physician(g);

	p_pt->p_ch->check_chart();

	switch (c)
	{
	case 1:
		cardiac_workup();
		break;

	case 2:
		respiratory_workup();
		break;

	case 3:
		abd_workup();
		break;

	case 4:
		neuro_workup();
		break;

	case 5:
		trauma_workup();
		break;

	default:
		break;
	}
	
}

void Physician::set_bp_flag() 
{
	bool bp_abnormal = true;

}
void Physician::set_pulse_flag() 
{
	bool pulse_abnormal = true;
		
}
void Physician::set_sat_flag() 
{
	bool low_sat = true;
}
void Physician::set_resp_flag() 
{
	bool resp_abnormal = true;
}
void Physician::set_temp_flag() 
{
	bool temp_abnormal = true;
}
void Physician::set_loc_flag() 
{
	bool low_loc = true;
}

void Physician::cardiac_workup()
{
	if (pulse_abnormal)
	{
		emergency_procedure("cardiac arrest");
	}
	else
	{
		order_oxygen();
		order_ekg();
		order_lab_tests("troponin");
		order_iv_drugs("nitroglycerin", "chest pain");
		std::cout << "Your EKG is normal and your troponin result is negative." << std::endl;
		pause_continue();
		std::cout << "We will check for other causes." << std::endl;
		pause_continue();
		std::string answer;
		std::cout << "Has your pain resolved?" << std::endl;
		std::cin >> answer;
		if (answer == "y")
		{
			p_rn->discharge();
		}
		else
		{
			call_consult("psychiatrist");
			order_iv_drugs("ativan", " anxiety");
			admit_to_hospital("observation");
		}


	}
}
void Physician::respiratory_workup()
{
	std::cout << "You are wheezing." << std::endl;
	std::cout << "The physician has prescribed an aerosolized albuterol treatment for your respiratory problem. " << std::endl;
	std::cout << "Albuterol will dilate your bronchioles, allowing more air to get to your lungs. " << std::endl;
	pause_continue();
	std::cout << "The physician has also prescribed a steroid to reduce inflammation in your airways. " << std::endl;
	pause_continue();
	if (low_sat)
	{
		std::cout << "Your condition has deteriorated." << std::endl;
		pause_continue();
		emergency_procedure("rapid sequence intubation");
	}
	else
	{
		order_iv_drugs("dexamethasone, a steroid", "inflammation in your lungs");
		pause_continue();
		std::cout << "Your bronchiolitic episode has resolved." << std::endl;
		std::cout << "Your respirations are full and unlabored, and your other vitals are stable." << std::endl;
		p_rn->discharge();
	}
		
	
}
void Physician::abd_workup()
{

	order_imaging("x-ray");
	order_lab_tests("Complete Blood Count, Electrolytes, Lipase");
	if (bp_abnormal)
	{
		order_iv_drugs("normal_saline", "dehydration");
	}
	pause_continue();
	std::string answer;
	std::cout << "Your abdominal x-ray and labs were negative for abnormalities." << std::endl;
	std::cout << "Has your pain resolved?" << std::endl;
	std::cin >> answer;
	if (answer == "y")
	{
		p_rn->discharge();
	}
	else
	{
		order_imaging("ultrasound");
		pause_continue();
		if (temp_abnormal)
		{
			call_consult("surgeon");
			std::cout << "You have appendicitis.  The surgeon will remove your appendix, which you can live without." << std::endl;
			order_iv_drugs("antibiotics", "appendicitis");
			std::cout << "The appendectomy is a very common and routine surgery.  Combined with the antibiotics and a hospital stay," << std::endl;
			std::cout << "you should recover fully.  This is not the late 1800's or before, where appendicitis would likely kill you!" << std::endl;
			admit_to_hospital("surgery");
		}

	}
}
void Physician::neuro_workup()
{
	std::string answer;
	std::cout << "Do you have a horrible headache with aura or light sensitivity?" << std::endl;
	std::cin >> answer;
	if (answer == "y")
	{
		order_iv_drugs("toradol", "migraine");
	}
	order_imaging("MRI");
	call_consult("neurologist");
	if (temp_abnormal)
	{
		emergency_procedure("cerebrospinal fluid");
		std::cout << "You have meningitis, an infection of the nervous system, and we need to treat you aggressively." << std::endl;
		order_iv_drugs("antibiotics", "infection");
	}
	pause_continue();
	admit_to_hospital("observation");


}

void Physician::trauma_workup()
{
	if (resp_abnormal)
	{
		std::cout << "Are you having trouble breathing because something hit you in the throat in the car accident?" << std::endl;
		std::cout << "Type 'y' for yes, 'n' for no." << std::endl;
		std::string answer;
		std::cin >> answer;
		if (answer == "y")
		{
			emergency_procedure("cricothyroidotomy");
		}
	}
	
	order_lab_tests("complete blood count, type and screen");
	order_imaging("CT scan");
	pause_continue();
	order_iv_drugs("lactated ringers", "shock");
	order_iv_drugs("platelets", "blood loss");
	if (pulse_abnormal || bp_abnormal || temp_abnormal)
	{
		emergency_procedure("craniotomy");
	}
	else
	{
		admit_to_hospital("observation and recovery");
	}
}

//these go inside other functions
//change the strings to references!
void Physician::order_lab_tests(std::string test)
{//CSF
	p_rn->draw_labs();	
}
void Physician::order_oxygen()
{
	std::cout << "Your physician has ordered that you receive supplemental oxygen through a mask. " << std::endl;
	std::cout << std::endl;
	p_rn->give_oxygen();
}
void Physician::order_ekg() 
{
	std::cout << "Your ER physician has ordered an electrocardiogram, also known as an EKG." << std::endl;
	pause_continue();
	std::cout << "\nAn EKG measures changes in ion flow across your heart which occur just " << std::endl;
	std::cout << "before the cardiac muscle contracts or relaxes when pumping or refilling with blood. " << std::endl;
	std::cout << "The computer will trace a wave line on the page, which will correspond with your heart's natural electrical activity. " << std::endl;
	pause_continue();
	std::cout << "This electrical activity is what determines the rate, regularity, and force of your heartbeat. " << std::endl;
	pause_continue();
	std::cout << "Problems with your heart muscle, which disrupt this electrical activity, " << std::endl;
	std::cout << "can cause serious heart problems and even psychiatric symptoms. " << std::endl;
	pause_continue();
}
void Physician::order_imaging(std::string method) 
{
	std::cout << "A staff person will take you to the Radiology department. Your ER physician " << std::endl;
	std::cout << "has ordered " << method << " imaging to help look for the cause of your problem." << std::endl;
	pause_continue();
	if (method == "ultrasound")
	{
		std::cout << "Ultrasound is a gentle, non-invasive, fast way to image the contours of the organs in your abdomen" << std::endl;
		std::cout << "and look for blockages, bleeding, or structural abnormalities that could be causing your symptoms." << std::endl;
		std::cout << "Ultrasound uses sound waves passed through the surface of your affected area to create the images." << std::endl;
	}
	if (method == "x-ray")
	{
		std::cout << "X-ray films harness electromagnetic radiation and pass the beams " << std::endl;
		std::cout << "through the patient onto a special receiver, " << std::endl;
		std::cout << "the data from which can create an image based on the different rates at " << std::endl;
		std::cout << "which different parts of the beam passed through. " << std::endl;
		pause_continue();
		std::cout << "This usually outlines the patient's skeletal structure in the area imaged, but also can " << std::endl;
		std::cout << "reveal general structural features of other tissues, " << std::endl;
		std::cout << " such as the lungs and the organs of the abdomen. " << std::endl;
		pause_continue();
	}
	if (method == "CT scan")
	{
		std::cout << "Computed Tomagraphy uses higher energy x-rays and algorithmic computations " << std::endl;
		std::cout << "to generate detailed and layered imagery of the area. " << std::endl;
		pause_continue();
	}
	if (method == "MRI")
	{
		std::cout << "Magnetic Resonance Imaging does not use radiation, but instead uses the recorded " << std::endl;
		std::cout << "vibrations of magnets rotating around the patient's body to create images. " << std::endl;
		pause_continue();
		std::cout << "This technique can be more useful for evaluating the structures of the brain and " << std::endl;
		std::cout << "nervous system than x-rays or ultrasound. " << std::endl;
		pause_continue();
	}

}
void Physician::order_iv_drugs( std::string drug, std::string symptom)
{
	std::cout << "The ER physician is ordering " << drug << " to be given intravenously to help treat your " << symptom << "." << std::endl;
	p_rn->give_iv_drugs();
}
void Physician::explanation( std::string proc)
{
	if (proc == "cerebrospinal_fluid")
	{
		std::cout << "The physician will need to do a special procedure called a lumbar puncture to draw some of your cerebrospinal fluid. " << std::endl;
		std::cout << "Cerebrospinal fluid is a normally clear fluid which is circulated " << std::endl;
		std::cout << "through your spinal cord and fills the ventricles of your brain. " << std::endl;
		std::cout << "The fluid provides cushioning and nourishment exclusive to the central nervous system. " << std::endl;
		pause_continue();
		std::cout << "The physician will numb an area in the small of your back, between the protuberances of two of the lumbar vertebrae, and " << std::endl;
		std::cout << " push a sterile needle to the center of your spinal cord. " << std::endl;
		pause_continue();
		std::cout << "The opening inside the hollow needle will fill with your " << std::endl;
		std::cout << "cerebrospinal fluid, and the physician will collect a small amount in vials.  If the fluid is cloudy or bloody, " << std::endl;
		std::cout << " it indicates dangerous inflammation in the central nervous system" << std::endl;
		std::cout << " or possible brain swelling from injury or infection. The lab will formally analyze it." << std::endl;
	}
	if (proc == "cardiac_arrest")
	{
		
		std::cout << std::endl;
		std::cout << "The physician is now running a 'full code' because your heart has stopped functioning properly. " << std::endl;
		std::cout << "This means that hospital staff members are performing cardio-pulmonary rescuscitation (CPR) on you to manually pump your heart " << std::endl;
		std::cout << " which is critical to keeping your vital organs supplied with oxygenated blood." << std::endl;
		pause_continue();
		std::cout << "Another physician is placing a breathing tube down your throat, since you lost consciousness when your heart stopped pumping. " << std::endl;
		pause_continue();
		std::cout << "The physicians have ordered, and the nurse is administering, epinephrine to stimulate your heart." << std::endl;
		pause_continue();
		std::cout << "The most common types of cardiac arrest are 'asystole', 'ventricular fibrillation', and 'ventricular tachycardia.' " << std::endl;
		std::cout << "Asystole is the partial or full absence of any electrical activity in the heart." << std::endl;
		pause_continue();
		std::cout << "Ventricular fibrillation is when the ventricles of the heart, which pump blood to other parts of the body, " << std::endl;
		std::cout << "are malfunctioning due to abnormal electrical activity." << std::endl;
		pause_continue();
		std::cout << "Ventricular tachycardia is when the ventricles of the heart are being signaled to contract (pump) at " << std::endl;
		std::cout << "such a high rate that not enough blood is being pumped." << std::endl;
		pause_continue();
		std::cout << "For V-Fib and V-Tach, a defibrillator will be charged and paddles applied to your upper right and " << std::endl;
		std::cout << "lower left torso, to send an electrical current through" << std::endl;
		std::cout << "your heart muscle and reset body's electrical activity, which will hopefully reset the heart rhythmn " << std::endl;
		pause_continue();
		std::cout << "We got your heart into a regular rhythm.  You will need to go to the ICU but you seem to be stabilizing." << std::endl;
		std::cout << "Rest easy." << std::endl;
	}
	if (proc == "rapid_sequence_intubation")
	{
		std::cout << "The physician will place a breathing tube directly down your trachea to ensure your lungs receive enough air. " << std::endl;
		pause_continue();
		std::cout << "Your body is not strong enough to take in adequate air on its own. " << std::endl;
		pause_continue();
		std::cout << "The procedure was successful. We will take a chest X-ray to ensure that the tube is positioned properly." << std::endl;
		pause_continue();
		std::cout << "Your situation has improved. Rest easy." << std::endl;
		

	}
	if (proc == "cricothyroidotomy")
	{
		std::cout << "The physician will make a small incision on your throat and " << std::endl;
		std::cout << "tape a large bore needle in place to deliver air directly to your trachea, " << std::endl;
		std::cout << "bypassing your mouth and pharynx, because those structures are compromised. " << std::endl;
		pause_continue();
		std::cout << "Without this tube, adequate air cannot get in. " << std::endl;
		pause_continue();
		std::cout << "We have bypassed the obstruction in your throat." << std::endl;
		std::cout << "Your oxygenation is improving. Rest easy." << std::endl;
		

		
	}
	if (proc == "craniotomy")
	{
		std::cout << "The physician will remove a piece of your skull to relieve the pressure on your brain created by pooled blood from your head injury. " << std::endl;
		pause_continue();
		std::cout << "The pressure from the blood is interfering with your brain's ability to regulate your vital functions, and must be cleared. " << std::endl;
		pause_continue();
		std::cout << "You are unconscious." << std::endl;
		std::cout << "A neurosurgeon has been called to follow up as soon as she gets out of the OR, " << std::endl;
		std::cout << "but your ER physician is trained in this procedure" << std::endl;
		std::cout << "and we must move forward.  Sterile surgical drapes are being placed over your body." << std::endl;
		pause_continue();
		std::cout << "The area of your skull which needs to be removed is directly over the bleed.  It is covered in hair." << std::endl;
		std::cout << "The nurse will shave this area of your head." << std::endl;
		pause_continue();
		std::cout << "A mixture of povidone and iodine, extremely powerful sterilizing agents, is being used to make the scalp ready for incisions." << std::endl;
		pause_continue();
		std::cout << "Lidocaine is being used to thoroughly numb the area." << std::endl;
		pause_continue();
		std::cout << "The procedure was successful. You will need to stay in the hospital to recover, but your prognosis looks good.  Rest easy." << std::endl;
		
	}
}

void Physician::emergency_procedure(std::string w)
{
	if (w == "cerebrospinal_fluid")
	{
		explanation(w);

	}
	if (w == "cardiac_arrest")
	{
		explanation(w);
		order_iv_drugs("epinephrine", "arrested heart");
	}
	if (w == "rapid_sequence_intubation")
	{
		explanation(w);
		order_iv_drugs("etomidate and rocuronium", "compromised airway. Etomidate is a sedative, so you will not feel the procedure. Rocuronium is a muscle relaxant so we can get the tube in.");
		
			
	}
	if (w == "cricothyroidotomy")
	{
		explanation(w);
	}
	if (w == "craniotomy")
	{
		explanation(w);
		order_iv_drugs("mannitol to reduce brain swelling, anticonvulsants to prevent seizures, and prophylactic antibiotics, to prevent infection.", "swollen brain");
	}
	admit_to_hospital("observation");

}
void Physician::call_consult( std::string specialist) 
{
	std::cout << "Your ER physician is paging the " << specialist << " on call to evaluate you." << std::endl;
}// = new surgeon, etc.
void Physician::admit_to_hospital( std::string reason)
{
	std::cout << "Your ER physician is admitting you to the hospital for " << reason << "." << std::endl;
	pause_continue();
	std::cout << "An extended stay in the hospital will ensure that you respond well to the treatments you are receiving. " << std::endl;
	p_rn->pass_report();
}

