
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>


//EMERGENCY ROOM SINGLE PATIENT EXPERIENCE
//by Kyle Goodale
//CS50 Final Project

//PROVIDERS
class Patient
{
private:
	const int complaint;
	Body_System* p_body;
public:
	Patient();
	int chief_complaint();
	void set_complaint(const int);
	void set_system(Body_System*);
	int will_see_you_now(const int);

};

class Provider
{

protected:
	Patient* p_pt;
public:
	Provider(Patient*);
	void take_vital_signs();
	
};

class Nurse : public Provider
{

public:
	Nurse(Patient*);
	void triage(const int);
	void draw_labs(const int);
	void place_iv();
	void perform_ekg();
	void pass_report();
};

class Physician : public Provider
{
private:
	Nurse* p_rn;
	Surgeon* p_doc_surg = NULL;
	Psychiatrist* p_doc_psych = NULL;
	Anesthesio* p_doc_sleep = NULL;
	HemOnc* p_doc_blood = NULL;
public:
	Physician(Patient*, Nurse*);
	int see_patient(const int);
	void order_lab_tests(const int);
	void order_imaging(const int);
	void order_iv_drugs(const int);
	void emergency_procedure(const int);
	void call_consult(const int);// = new surgeon, etc.
	void admit_to_hospital();
	void pronounce_death();
};

//SPECIALISTS
class Surgeon : public Physician
{
public:
	Surgeon();
	void reduce_and_cast_fracture();
	void remove_foreign_body();
	void goto_operating_room();


}

class Anesthesio : public Physician
{
public:
	Anethesio();
	void intubate_advanced();
	void give_anesthesia();
	void give_analgesia();
}

class Psychiatrist : public Physician
{
public:
	Psychiatrist();
	void order_involuntary_commit();
	void prescribe();

}

class HemOnc : public Physician
{
public:
	HemOnc();
	void diagnose();
	void begin_chemo();
	void order_biopsy();

}


//DATA
class Vitals {

private:

	//push a map of vitals onto the vector
	std::map<std::string, const int> v_set{
	{"systolic", 0}, {"diastolic", 0},
	{"pulse", 0}, {"resps", 0}, {"temp", 0},
	{"LOC", 0}
	};

	std::vector<std::map<std::string, const int>> chart;
public:
	Vitals();
	std::map<std::string, const int> take_vital_signs(const int value);
	void update_chart();
	void shock();

};

class Body_System
{

public:
	Vitals* p_vs;
	Body_System();


};

class Neuro : public Body_System {};


class Pulmo : public Body_System {};


class Cardiac : public Body_System {
public:
	Cardiac();
};

class Gastro : public Body_System {};

class Skeletal : public Body_System {};
class Psycho : public Body_System {};


int main()
{
	Patient user;
	Nurse nurse(&user);
	Physician doctor(&user, &nurse);
	const int cc = user.chief_complaint();
	user.set_complaint(cc);
	nurse.take_vital_signs();
	nurse.triage(cc);
	doctor.nurse_interface(doctor.see_patient(cc));

}

Patient::Patient()
	:p_body(NULL)
{
}

int Patient::chief_complaint()
{
	int input;
	std::cout << "What brings you into the emergency room?" << std::endl;
	std::cout << "Please select your complaint by typing the corresponding number and pressing enter:" << std::endl;
	std::cout << "1 - You are having chest pain." << std::endl;
	std::cout << "2 - You are having trouble breathing or are choking." << std::endl;
	std::cout << "3 - You have a headache or you think you had a seizure." << std::endl;
	std::cout << "4 - You have abdominal pain, vomiting, nausea, or diarrhea." << std::endl;
	std::cout << "5 - You fell and hit the ground or an outside force hit you, such as in a vehicular accident." << std::endl;
	std::cout << "6 - Some part of your body is not working, weak, or just 'hurting'." << std::endl;
	std::cout << "7 - You were assaulted." << std::endl;
	std::cout << "8 - You feel very sick, but none of the above." << std::endl;
	std::cout << "9 - You think you might hurt yourself on purpose." << std::endl;
	std::cin >> input;
	while (input <= 0 || input > 10)
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid entry." << std::endl;
			std::cin >> input;
		}
	}
	return input;
}

void Patient::set_complaint(const int com)
{
	complaint = com;
}

void Patient::set_system(Body_System* bs)
{
	p_body = bs;
}

int Patient::will_see_you_now(const int cc)
{
	int diagnosis;

	switch (cc) {
	case 1:
		//heart attack, anxiety, indigestion()
		break;
	case 2:
		//choking, anaphylaxis, asthma, infection
		break;
	case 3:
		//stroke, migraine, post-seizure
		break;
	case 4:
		//food poisoning, infection, ingestion, parasite, pregnancy
		break;
	case 5:
		//vehicular accident, fall, assault, gunshot, stabbing
		break;
	case 6:
		//stroke, tumor, infection, bone break
		break;
	case 7:
		//rape kit, social worker, laceration, bone break
		break;
	case 8:
		//infection, flu/covid test, blood work
		break;
	case 9:
		//psychiatry
		break;
	}

	return diagnosis;
}

Provider::Provider(Patient* p)
	:p_pt(p)
{}
Nurse::Nurse(Patient* q)
	:Provider(q)
{}
void Nurse::triage(const int cc) //maybe it should be nurse doing the triage
{
	switch (cc) {
	case 1:
		Cardiac heart;
		p_pt->set_system(&heart)
		break;
	case 2:
		Pulmo lungs;
		p_pt->set_system(&lungs)
		break;
	case 3:
		Neuro head;
		p_pt->set_system(&head)
		break;
	case 4:
		Gastro gut;
		p_pt->set_system(&gut)
		break;
	case 5:
		Skeletal bones;
		p_pt->set_system(&bones)
		break;
	case 6:
		Body_System body;
		p_pt->set_system(&body)
		break;
	case 7:
		Body_System body;
		p_pt->set_system(&body)
		break;
	case 8:
		Body_System body;
		p_pt->set_system(&body)
		break;
	case 9:
		Psycho mind;
		p_pt->set_system(&mind)
		break;
	default:
		break;

	}



}
Physician::Physician(Patient* pt, Nurse* rn) 
	:Provider(pt), p_rn(rn)
{
}
int Physician::see_patient(const int cc) 
{
	return (p_pt->will_see_you_now(cc));
}
void Physician::order_lab_tests(const int t) {}


Body_System::Body_System()
{
	p_vs = new Vitals;
}

Cardiac::Cardiac()
{}

Pulmo::Pulmo() {}
Neuro::Neuro() {}
Gastro::Gastro() {}
Skeletal::Skeletal() {}
Psycho::Psycho() {}


