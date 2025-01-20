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
		gastro_workup();
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
	
	order_oxygen(/*lpm, mask*/);
	order_ekg();
	order_lab_tests(/*test*/);
	order_iv_drugs(/*drugs*/);
}
void Physician::respiratory_workup() {}
void Physician::gastro_workup() {}
void Physician::neuro_workup() {}
void Physician::psych_workup() {}
void Physician::trauma_workup() {}
void Physician::laceration_workup() {}
void Physician::assault_workup() {}
void Physician::medical_workup() {}





//these go inside other functions
void Physician::order_lab_tests(const std::string test)
{
	p_rn->draw_labs(test);
	std::cout << "Your ER physician has ordered your nurse to draw some of your blood.  
		<< "This blood will be sent to the lab, where the amounts of " << test << " will be measured.  Abnormal levels of " << test << ","
		<< " whether abnormally high or abnormally low, can lead to your symptoms and/or problem." << std::endl;
	//if test a, explanation a
	//if test b, explanation b
}
void Physician::order_oxygen(const std::string lpm, const std::string mask) 
{
	std::cout << "Your physician has ordered that you receive supplemental oxygen, which will ensure adequate oxygenation of your blood"
		<< ", which is essential to maintain consistent support of all the tissues of your body, especially your brain and vital organs." << std::endl;
	p_rn->give_oxygen();
}
void Physician::order_ekg() 
{
	std::cout << "Your ER physician has ordered an electrocardiogram, also known as an EKG."
		<< "\nAn EKG measures changes in ion flow across your heart which occur just before the cardiac muscle "
		<< "contracts or relaxes when pumping or refilling with blood."
		<< "Another way to say this is that the EKG will trace a two dimensional, carefully measured line "
		<< "which will correspond with your heart's natural electrical activity."
		<< "This electrical activity is what determines the rate, regularity, and force of your heartbeat."
		<< " Problems with your heart muscle, which disrupt this electrical activity,"
		<< " can cause the symptoms you are experiencing." << std::endl;
}
void Physician::order_imaging(const std::string method) 
{
	std::cout << "A staff person will be taking you to the Radiology department. Your ER physician "
		<< "has ordered " << method << " imaging to help look for the cause of your problem." << std::endl;
	//explain each method?
	//if X-Ray
	//if CT scan
	//if MRI
}
void Physician::order_iv_drugs(const std::string drug1, const std::string drug2) 
{
	std::cout << "The ER physician is ordering " << drug1 << " to be given intravenously to help treat your problem." << std::endl;
	std::cout << drug2 << " will also be given intravenously to treat the symptoms associated with your problem." << std::endl;
}
void Physician::emergency_procedure(const int which)
{
	if (which == "rapid sequence intubation")
	{
		explanation = "The physician will place a breathing tube directly down your trachea to help ensure your lungs receive enough air."   
			<< "Your body is not strong enough to take in adequate air on its own." << std::endl;
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
	}

	std::cout << "Your ER physician will now do an emergency procedure on you.  The physician will perform an emergency " << which << "."
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
}
void Physician::pronounce_death(/*timeofdeath*/) 
{
	std::cout << "Your ER physician has pronounced you dead. Your time of death was " << explanation /*not really*/ << "."
		<< "The hospital expresses the most sincere condolences to your family."
		<< " Your condition progressed too rapidly/ was too far along for the staff to successfully treat you." << std::endl;
}