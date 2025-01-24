
#include <iostream>
#include "Physician.h"

//derived class Physician definitions


Physician::Physician(Patient* pt, Nurse* rn)
	:Provider(pt), p_rn(rn)
{
}
void Physician::see_patient()
{
	int help = p_pt->show_complaint();

	switch (help)
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
		psych_workup();
		break;
	case 6:
		trauma_workup();
		break;
	case 7:
		assault_workup();
		break;
	case 8:
		medical_workup();
		break;
	default:
		break;
		

	}



	
}

void Physician::cardiac_workup() 
{	
	std::cout << "Does it feel like someone is sitting on your chest?" << std::endl;
	std::string answer;
	std::cin >> answer;
	if (answer == "y")
	{
		if (p_pt->show_age() > 55 && (p_pt->show_sex() == "male" || p_pt->show_sex() == "m" || p_pt->show_sex() == "Male"))
		{
			emergency_procedure("cardiac arrest");
		}
		else
		{
			order_oxygen();
			order_ekg();
			order_lab_tests("troponin");
			order_iv_drugs("normal saline", "beta blocker");
			std::cout << "Your EKG is normal and your troponin result is negative." << std::endl;
			pause_continue();
			std::cout << "We will check for other causes." << std::endl;
			pause_continue();
			std::cout << "Has your pain resolved?" << std::endl;
			std::cin >> answer;
			if (answer == "y")
			{
				p_rn->discharge();
			}
			else
			{
				call_consult("psychiatrist");
				order_iv_drugs("ativan");
				admit_to_hospital("observation");
			}


		}
	}
}
void Physician::respiratory_workup()
{
	std::cout << "Are you having trouble breathing because something hit you in the throat and your airway has collapsed? Type 'y' for yes, 'n' for no." << std::endl;
	std::string answer;
	std::cin >> answer;
	if (answer == "y")
	{
     	emergency_procedure("cricothyroidotomy");
	}
	else
	{
		std::cout << "The physician has prescribed an aerosolized albuterol treatment for your respiratory problem. " << std::endl;
		std::cout << "Albuterol will help dilate your bronchioles, allowing more air to get to your lungs. " << std::endl;
		pause_continue();
		std::cout << "The physician has also prescribed a steroid to reduce inflammation in your airways. " << std::endl;
		pause_continue();
		if (p_pt->show_age() > 55 )
		{
			std::cout << "Your condition has deteriorated." << std::endl;
			pause_continue();
			emergency_procedure("rapid sequence intubation");
		}
		else
		{
			order_iv_drugs("dexamethasone");
			pause_continue();
			std::cout << "Your bronchiolitic episode has improved.  Your respirations are full and unlabored, and your other vitals are stable." << std::endl;
			p_rn->discharge();
		}
	}
}
void Physician::abd_workup() 
{
	
	order_imaging("x-ray");
	order_lab_tests("Complete Blood Count, Electrolytes, Lipase");
	order_iv_drugs("normal_saline");
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
		call_consult("surgeon");
		pause_continue();
		admit_to_hospital("observation");

	}
}
void Physician::neuro_workup() 
{
	order_imaging("mri");
	pause_continue();
	order_lab_tests("cerebrospinal fluid");
	order_iv_drugs("keppra", "toradol");
	call_consult("neurologist");
	pause_continue();
	std::cout << "You have meningitis and we need to treat you aggressively." << std::endl;
	order_iv_drugs("antibiotics");
	pause_continue();
	admit_to_hospital("observation");

	
}

void Physician::psych_workup() 
{
	order_lab_tests("complete blood count, Electrolyte panel");
	order_ekg();
	order_iv_drugs("ativan");
	call_consult("psychiatrist");
	pause_continue();
	std::cout << "We want you to feel safe with a plan before you go home." << std::endl;
	admit_to_hospital("observation");
}
void Physician::trauma_workup() 
{
	//std::cout << "How fast were you going?" << std::endl;
	order_lab_tests("complete blood count, type and screen");
	order_imaging("ct scan");
	pause_continue();
	order_iv_drugs("normal saline", "platelets");
	if (p_pt->show_age() > 30 && p_pt->show_age() < 60)
	{
		emergency_procedure("craniotomy");
	}
	else
	{
		p_rn->discharge();
	}
}
void Physician::assault_workup() 
{
	order_lab_tests("std screen");
	order_iv_drugs("tylenol", "prophylaxis");
	call_consult("gynecologist and/or social worker");
	std::cout << "The police will also be here to speak with you shortly." << std::endl;
	pause_continue();
	pause_continue();
	std::string answer;
	std::cout << "Do you feel safe enough to go home?  Type 'y' or 'n'" << std::endl;
	if (answer == "y")
	{
		p_rn->discharge();
	}
	else
	{
		admit_to_hospital("observation");
	}
}
void Physician::medical_workup() 
{
	order_lab_tests("complete blood count, inflammatory markers, metabolic panel w/blood glucose, electrolyte panel");
	order_iv_drugs("normal saline", "antibiotics");
	std::cout << "Have your symptoms resolved?" << std::endl;
	std::string answer;
	std::cin >> answer;
	if (answer == "y" || answer == "yes")
	{
		p_rn->discharge();
	}
	else
	{
		order_imaging("x-ray");
		//take_vital_signs();
		pause_continue();
		std::cout << "We found something on X ray." << std::endl;
		call_consult("surgery");
		std::cout << "You will need to go to the OR." << std::endl;
		pause_continue();
		admit_to_hospital("surgery");
	}
	
}





//these go inside other functions
void Physician::order_lab_tests(std::string test)
{
	p_rn->draw_labs(test);
	std::cout << "Abnormal levels of " << test << ", whether abnormally high or abnormally low, can lead to your symptoms and/or problem. " << std::endl;
	
}
void Physician::order_oxygen() 
{
	std::cout << "Your physician has ordered that you receive supplemental oxygen through a mask, " << std::endl;
	std::cout << "which will ensure adequate oxygenation of your blood." << std::endl;
	std::cout << "his is essential to maintain consistent support of all the tissues of your body, " << std::endl;
	std::cout << "especially your brain and vital organs." << std::endl;
	p_rn->give_oxygen();
}
void Physician::order_ekg() 
{
	std::cout << "Your ER physician has ordered an electrocardiogram, also known as an EKG." << std::endl;
	std::cout << "\nAn EKG measures changes in ion flow across your heart which occur just " << std::endl;
	std::cout << "before the cardiac muscle " << std::endl;
	std::cout << "contracts or relaxes when pumping or refilling with blood. " << std::endl;
	std::cout << "Another way to say this is that the EKG will trace a two dimensional, " << std::endl;
	std::cout << "carefully measured wave line " << std::endl;
	std::cout << "which will correspond with your heart's natural electrical activity. " << std::endl;
	pause_continue();
	std::cout << "This electrical activity is what determines the rate, regularity, and force of your heartbeat. " << std::endl;
	std::cout << " Problems with your heart muscle, which disrupt this electrical activity, " << std::endl;
	std::cout << " can cause serious heart problems and even psychiatric symptoms. " << std::endl;
}
void Physician::order_imaging(std::string method) 
{
	std::cout << "A staff person will be taking you to the Radiology department. Your ER physician " << std::endl;
	std::cout << "has ordered " << method << " imaging to help look for the cause of your problem." << std::endl;
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
		std::cout << " the data from which can create an image based on the different rates at " << std::endl;
		std::cout << "which different parts of the beam passed through. " << std::endl;
		pause_continue();
		std::cout << " This usually outlines the patient's skeletal structure in the area imaged, but also can " << std::endl;
		std::cout << "reveal general structural features of other tissues, " << std::endl;
		std::cout << " such as the lungs and the organs of the abdomen. " << std::endl;
	}
	if (method == "CT scan")
	{
		std::cout << "Computed Tomagraphy uses higher energy x-rays and algorithmic computations " << std::endl;
		std::cout << "to generate more detailed and layered imagery of the area. " << std::endl;
	}
	if (method == "MRI")
	{
		std::cout << "Magnetic Resonance Imaging does not use radiation, but instead uses the recorded " << std::endl;
			std::cout << "vibrations of magnets rotating around the patient's body to create images. " << std::endl;
			pause_continue();
		std::cout <<"This technique can be more useful for evaluating the structures of the brain and nervous system. " << std::endl;
	}

}
void Physician::order_iv_drugs( std::string drug)
{
	std::cout << "The ER physician is ordering " << drug << " to be given intravenously to help treat your problem. " << std::endl;
	p_rn->give_iv_drugs(drug);
}
void Physician::order_iv_drugs(std::string drug1,  std::string drug2) 
{
	/*if medication == listed allergic medication*/
	std::cout << "The ER physician is ordering " << drug1 << " to be given intravenously to help treat your problem. " << std::endl;
	std::cout << drug2 << " will also be given intravenously to treat the symptoms associated with your problem. " << std::endl;
	p_rn->give_iv_drugs(drug1, drug2);
}
void Physician::explanation( std::string proc)
{
	if (proc == "cardiac arrest")
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
		std::cout << "We got your heart into a regular rhythm.  You will need to go to the ICU but you seem to be stabilizing.  Rest easy." << std::endl;
	}
	if (proc == "rapid sequence intubation")
	{
		std::cout << "The physician will place a breathing tube directly down your trachea to ensure your lungs receive enough air. " << std::endl;
		pause_continue();
		std::cout << "Your body is not strong enough to take in adequate air on its own. " << std::endl;
		std::cout << "The procedure was successful. We will take a chest X-ray to ensure that the tube is positioned properly." << std::endl;
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
		pause_continue();
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
		std::cout << "A neurosurgeon has been called to follow up as soon as she gets out of the OR, but your ER physician is trained in this procedure" << std::endl;
		std::cout << "and we must move forward.  Sterile surgical drapes are being placed over your body." << std::endl;
		pause_continue();
		std::cout << "The area of your skull which needs to be removed is directly over the bleed.  It is covered in hair." << std::endl;
		std::cout << "The nurse will shave this area of your head." << std::endl;
		pause_continue();
		std::cout << "A mixture of povidone and iodine, extremely powerful sterilizing agents, is being used to make the scalp ready for incisions." << std::endl;
		pause_continue();
		std::cout << "Lidocaine is being used to thoroughly numb the area." << std::endl;
		pause_continue();
		std::cout << "You cannot feel or read this.  There is nothing to fear." << std::endl;
		pause_continue();
		pause_continue();
		pause_continue();
		std::cout << "The procedure was successful. You will need to stay in the hospital to recover, but your prognosis looks good.  Rest easy." << std::endl;
		
	}
}

void Physician::emergency_procedure(std::string w)
{
	if (w == "cardiac arrest")
	{
		explanation(w);
		p_rn->give_iv_drugs("epinephrine");
	}
	if (w == "rapid sequence intubation")
	{
		explanation(w);
		p_rn->give_iv_drugs("etomidate", "rocuronium");
			
	}
	if (w == "cricothyroidotomy")
	{
		explanation(w);
	}
	if (w == "craniotomy")
	{
		explanation(w);
		p_rn->give_iv_drugs("corticosteroids, anticonvulsant drugs, prophylactic antibiotics");
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

