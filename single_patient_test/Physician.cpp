
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
	order_oxygen();
	order_ekg();
	order_lab_tests("troponin");
	order_iv_drugs("normal saline", "beta blocker");
	admit_to_hospital("observation");
}
void Physician::respiratory_workup() 
{
	std::cout << "The physician has prescribed an aerosolized albuterol treatment for your respiratory problem. " << std::endl;
	std::cout << "Albuterol will help dilate your bronchioles, allowing more air to get to your lungs. " << std::endl;
	std::cout << "The physician has also prescribed a steroid to reduce inflammation in your airways. " << std::endl;
	order_iv_drugs("dexamethasone");
	admit_to_hospital("observation");
}
void Physician::abd_workup() 
{
	order_imaging("x-ray");
	order_lab_tests("Complete Blood Count, Electrolytes, Lipase");
	order_iv_drugs("normal_saline");
	p_rn->discharge();

}
void Physician::neuro_workup() 
{
	order_imaging("mri");
	order_lab_tests("cerebrospinal fluid");
	order_iv_drugs("keppra", "toradol");
	call_consult("neurologist");
	admit_to_hospital("observation");
	
}

void Physician::psych_workup() 
{
	order_lab_tests("complete blood count, Electrolyte panel");
	order_ekg();
	order_iv_drugs("ativan");
	call_consult("psychiatrist");
	admit_to_hospital("observation");
}
void Physician::trauma_workup() 
{
	order_lab_tests("complete blood count, type and screen for possible transfusion");
	order_imaging("ct scan");
	order_iv_drugs("normal saline", "platelets");
	call_consult("surgeon");
	admit_to_hospital("surgery");
}
void Physician::assault_workup() 
{
	order_lab_tests("sexual assault panel");
	order_iv_drugs("tylenol", "prophylaxis");
	call_consult("gynecologist and/or social worker");
	admit_to_hospital("observation");
}
void Physician::medical_workup() 
{
	order_lab_tests("complete blood count, inflammatory markers, metabolic panel w/blood glucose, electrolyte panel");
	order_iv_drugs("normal saline", "antibiotics");
	p_rn->discharge();
	
}





//these go inside other functions
void Physician::order_lab_tests(std::string test)
{
	p_rn->draw_labs(test);
	std::cout << "Your ER physician has ordered your nurse to draw some of your blood. " << std::endl;
	std::cout << "This blood will be sent to the lab, where the concentrations of " << test << std::endl;
	std::cout << " will be measured in that sample. Abnormal levels of " << test << ", " << std::endl;
	std::cout << " whether abnormally high or abnormally low, can lead to your symptoms and/or problem. " << std::endl;
	
}
void Physician::order_oxygen() 
{
	std::cout << "Your physician has ordered that you receive supplemental oxygen through a mask, which will ensure adequate oxygenation of your blood."
		<< " This is essential to maintain consistent support of all the tissues of your body, especially your brain and vital organs." << std::endl;
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
	std::cout << "This electrical activity is what determines the rate, regularity, and force of your heartbeat. " << std::endl;
	std::cout << " Problems with your heart muscle, which disrupt this electrical activity, " << std::endl;
	std::cout << " can cause serious heart problems and even psychiatric symptoms. " << std::endl;
}
void Physician::order_imaging(std::string method) 
{
	std::cout << "A staff person will be taking you to the Radiology department. Your ER physician " << std::endl;
	std::cout << "has ordered " << method << " imaging to help look for the cause of your problem." << std::endl;
	if (method == "x-ray")
	{
		std::cout << "X-ray films harness electromagnetic radiation and pass the beams " << std::endl;
		std::cout << "through the patient onto a special receiver, " << std::endl;
		std::cout << " the data from which can create an image based on the different rates at " << std::endl;
		std::cout << "which different parts of the beam passed through. " << std::endl;
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
		std::cout << "Another physician is placing a breathing tube down your throat, since you lost consciousness when your heart stopped pumping. " << std::endl;
		std::cout << "The physicians have ordered and the nurse is administering epinephrine to stimulate your heart." << std::endl;
		std::cout << "The most common types of cardiac arrest are 'asystole', 'ventricular fibrillation', and 'ventricular tachycardia.' " << std::endl;
		std::cout << "Asystole is the partial or full absence of any electrical activity in the heart." << std::endl;
		std::cout << "Ventricular fibrillation is when the ventricles of the heart, which pump blood to other parts of the body, " << std::endl;
		std::cout << "are malfunctioning due to abnormal electrical activity." << std::endl;
		std::cout << "Ventricular tachycardia is when the ventricles of the heart are being signaled to contract (pump) at " << std::endl;
		std::cout << "such a high rate that not enough blood is being pumped." << std::endl;
		std::cout << "For V-Fib and V-Tach, a defibrillator will be charged and paddles applied to your upper right and " << std::endl;
		std::cout << "lower left torso, to send an electrical current through" << std::endl;
		std::cout << "your heart muscle and reset body's electrical activity, which will hopefully reset the heart rhythmn " << std::endl;
		std::cout << std::endl;
	}
	if (proc == "rapid sequence intubation")
	{
		std::cout << "The physician will place a breathing tube directly down your trachea to ensure your lungs receive enough air. " << std::endl;
		std::cout << "Your body is not strong enough to take in adequate air on its own. " << std::endl;

	}
	if (proc == "cricothyroidotomy")
	{
		std::cout << "The physician will make a small incision on your throat and " << std::endl;
		std::cout << "tape a large bore needle in place to deliver air directly to your trachea, " << std::endl;
		std::cout << "bypassing your mouth and pharynx, because those structures are compromised.  Without this tube, adequate air cannot get in. " << std::endl;
	}
	if (proc == "craniotomy")
	{
		std::cout << "The physician will remove a piece of your skull to relieve the pressure on your brain created by pooled blood from your head injury. " << std::endl;
		std::cout << "The pressure is interfering with your brain's ability to regulate your vital functions, and must be cleared. " << std::endl;
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

}
void Physician::call_consult( std::string specialist) 
{
	std::cout << "Your ER physician is paging the " << specialist << " on call to evaluate you." << std::endl;
}// = new surgeon, etc.
void Physician::admit_to_hospital( std::string reason)
{
	std::cout << "Your ER physician is admitting you to the hospital for " << reason << "." << std::endl;
	std::cout << "An extended stay in the hospital will ensure that you respond well to the treatments you are receiving. " << std::endl;
	p_rn->pass_report();
}

