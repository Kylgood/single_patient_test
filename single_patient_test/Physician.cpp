#include <iostream>
#include "Physician.h"

//derived class Physician definitions


Physician::Physician(Patient* pt, Nurse* rn)
	:Provider(pt), p_rn(rn)
{
}
void Physician::see_patient()
{
	const int help = p_pt->show_complaint();

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
		trauma_workup();
		break;
	case 6:
		psych_workup();
		break;
	case 7:
		laceration_workup();
		break;
	case 8:
		assault_workup();
		break;
	case 9:
		trauma_workup();
		break;
	case 10:
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
}
void Physician::respiratory_workup() 
{
	std::cout << "The physician has prescribed an aerosolized albuterol treatment for your respiratory problem."
		<< "Albuterol will help dilate your bronchioles, allowing more air to get to your lungs." << std::endl;
	std::cout << "The physician has also prescribed a steroid to reduce inflammation in your airways." << std::endl;
	order_iv_drugs(("dexamethasone");
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
void Physician::order_lab_tests(const std::string test)
{
	p_rn->draw_labs(test);
	std::cout << "Your ER physician has ordered your nurse to draw some of your blood.  
		<< "This blood will be sent to the lab, where the concentrations of " << test << " will be measured in that sample.  Abnormal levels of " << test << ","
		<< " whether abnormally high or abnormally low, can lead to your symptoms and/or problem." << std::endl;
	
}
void Physician::order_oxygen() 
{
	std::cout << "Your physician has ordered that you receive supplemental oxygen through a mask, which will ensure adequate oxygenation of your blood."
		<< " This is essential to maintain consistent support of all the tissues of your body, especially your brain and vital organs." << std::endl;
	p_rn->give_oxygen();
}
void Physician::order_ekg() 
{
	std::cout << "Your ER physician has ordered an electrocardiogram, also known as an EKG."
		<< "\nAn EKG measures changes in ion flow across your heart which occur just before the cardiac muscle "
		<< "contracts or relaxes when pumping or refilling with blood."
		<< "Another way to say this is that the EKG will trace a two dimensional, carefully measured wave line "
		<< "which will correspond with your heart's natural electrical activity."
		<< "This electrical activity is what determines the rate, regularity, and force of your heartbeat."
		<< " Problems with your heart muscle, which disrupt this electrical activity,"
		<< " can cause serious heart problems and even psychiatric symptoms." << std::endl;
}
void Physician::order_imaging(const std::string method) 
{
	std::cout << "A staff person will be taking you to the Radiology department. Your ER physician "
		<< "has ordered " << method << " imaging to help look for the cause of your problem." << std::endl;
	if (method == "x-ray")
	{
		std::cout << "X-ray films harness electromagnetic radiation and pass the beams through the patient onto a special receiver,"
			<< " the data from which can create an image based on the different rates at which different parts of the beam passed through."
			<< " This usually outlines the patient's skeletal structure in the area imaged, but also can reveal general structural features of other tissues,
			<< " such as the lungs and the organs of the abdomen." << std::endl;
	}
	if (method == "CT scan")
	{
		std::cout << "Computed Tomagraphy uses higher energy x-rays and algorithmic computations to generate more detailed and layered imagery of the area." << std::endl;
	}
	if (method == "MRI")
	{
		std::cout <<"Magnetic Resonance Imaging does not use radiation, but instead uses the recorded vibrations of magnets rotating around the patient's body to create images."
			<<"This technique can be more useful for evaluating the structures of the brain and nervous system." << std::endl;
	}

}
void Physician::order_iv_drugs(const std::string drug)
{
	std::cout << "The ER physician is ordering " << drug << " to be given intravenously to help treat your problem." << std::endl;
	p_rn->give_iv_drugs(drug);
}
void Physician::order_iv_drugs(const std::string drug1, const std::string drug2) 
{
	/*if medication == listed allergic medication*/
	std::cout << "The ER physician is ordering " << drug1 << " to be given intravenously to help treat your problem." << std::endl;
	std::cout << drug2 << " will also be given intravenously to treat the symptoms associated with your problem." << std::endl;
	p_rn->give_iv_drugs(drug1, drug2);
}
void Physician::emergency_procedure(const int which)
{
	if (which == "cardiac arrest")
	{
		explanation = "The physician is now running a 'full code' because your heart has stopped functioning properly."
			<< "This means that hospital staff members are performing cardio-pulmonary rescuscitation (CPR) on you to manually pump your heart"
			<< " which is critical to keeping your vital organs supplied with oxygenated blood."
			<< "Another physician is placing a breathing tube down your throat, since you lost consciousness when your heart stopped pumping."
			<< "The physicians have ordered and the nurse is administering epinephrine to stimulate your heart."
			<< "The most common types of cardiac arrest are 'asystole', 'ventricular fibrillation', and 'ventricular tachycardia.'";
		<< "Asystole is the partial or full absence of any electrical activity in the heart."
			<< "Ventricular fibrillation is when the ventricles of the heart, which pump blood to other parts of the body, are malfunctioning due to abnormal electrical activity."
			<< "Ventricular tachycardia is when the ventricles of the heart are being signaled to contract (pump) at such a high rate that it not enough blood is being pumped."
			<< "For V-Fib and V-Tach, a defibrillator will be charged and paddles applied to your upper right and lower left torso, to send an electrical current through"
			<< "your heart muscle and reset body's electrical activity, which will hopefully reset the heart rhythmn";
	if (which == "rapid sequence intubation")
	{
		explanation = "The physician will place a breathing tube directly down your trachea to help ensure your lungs receive enough air."   
			<< "Your body is not strong enough to take in adequate air on its own." << std::endl;
		p_rn->give_iv_drugs("etomidate", "rocuronium");
	}
	if (which == "cricothyroidotomy")
	{
		explanation = "The physician will make a small incision on your throat and tape a large bore needle in place to deliver air directly to your trachea,"
			<< "bypassing your mouth and pharynx, because those structures are compromised, and adequate air cannot get in." << std::endl;
	}
	if (which == "craniotomy")
	{
		explanation = "The physician will remove a piece of your skull to relieve the pressure on your brain created by pooled blood from your head injury.";
		<< "The pressure is interfering with your brain's ability to regulate your vital functions, and must be cleared." << std::endl;
		p_rn->give_iv_drugs("corticosteroids (like dexamethasone), anticonvulsant drugs, prophylactic antibiotics, osmotic diuretics (like mannitol)")
	}

	std::cout << "The physician will now perform an emergency " << which << " on you."
		<< explanation <<"."
		<<"This should help stabilize the essentials of your body's physiology: airway, breathing, and circulation." << std::endl;
}
void Physician::call_consult(const std::string specialist) 
{
	std::cout << "Your ER physician is paging the " << specialist << " on call to evaluate you." << std::endl;
}// = new surgeon, etc.
void Physician::admit_to_hospital(const std::string reason)
{
	std::cout << "Your ER physician is admitting you to the hospital for " << reason << "."
		<< "An extended stay in the hospital will ensure that you respond well to the treatments you are receiving." << std::endl;
	p_rn->pass_report();
}

//pronounce_death()