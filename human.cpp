// Neve Laughery
// CS330

#include "human.h"

//********************************* Human *************************************

Human::Human():
    PlayerClass("", NULL, NULL), wpn(NULL) {
}

Human::Human(const string initName, const int INIT_VAR_STATS[], const int INIT_CONST_STATS[]):
    PlayerClass(initName, INIT_VAR_STATS, INIT_CONST_STATS), wpn(NULL) {

    for (int i = 0; i<Weapon::NUM_DIFF_WEAPONS; i++)
        wpnSkill[i] = 0;
}

Human::Human(const Human& h):
    PlayerClass(h), wpn(NULL) {
    CopyIntoMe(h);
}

Human& Human::operator=(const Human& h) {
    if (this != &h) {
        PlayerClass::operator=(h);
        CopyIntoMe(h);
    }
    return *this;
}

bool Human::SetInitWeaponSkill(Weapon::WpnType wpn, int skill) {
    bool set = false;
    if (wpn != NULL) {
        for (int i = 0; i<Weapon::NUM_DIFF_WEAPONS; i++) {
            wpnSkill[wpn] = skill;
        }
        set = true;
    }
    return set;
}

void Human::CopyIntoMe(const Human& h) {
    if (HasWeapon()) {
        delete wpn;
        wpn = NULL;
    }

    if (h.wpn != NULL)
        wpn = new Weapon(*h.wpn);

    for(int i=0; i<Weapon::NUM_DIFF_WEAPONS; i++) {
        wpnSkill[i] = h.wpnSkill[i];
    }
}

Weapon* Human::Wpn() const {
    return wpn;
}

Human::~Human() {
    delete wpn;
    wpn = NULL;
}

bool Human::HasWeapon() const {
    return (wpn != NULL);
}

string Human::WeaponName() const {
    string wpnString = "";
    if (wpn != NULL)
        wpnString = wpn->WeaponName();

    return wpnString;
}

int Human::WeaponSkill() const {
    int skill = 0;
    if (wpn != NULL && HasWeapon()) {
        skill = wpnSkill[wpn->WeaponType()];
    }
    return skill;
}

int Human::SkillLookup(int wpnType) const {
    return wpnSkill[wpnType];
}

bool Human::HasWeaponHistory() const {
    bool history = false;
    for (int i = 0; i<Weapon::NUM_DIFF_WEAPONS; i++) {
        if (wpnSkill[i] > 0) {
            history = true;
        }
    }
    return history;
}

Weapon* Human::DropWeapon() {
    Weapon* dropped = NULL;

    if (IsActive() && HasWeapon()) {
        dropped = wpn;
        wpn = NULL;
    }
    return dropped;
}

Weapon* Human::GrabWeapon(Weapon* weapon) {
    Weapon* oldWeapon = weapon;

    if (IsActive()) {
        if (weapon != NULL) {
            oldWeapon = DropWeapon();
            wpn = weapon;
            if (wpnSkill[wpn->WeaponType()] == 0)
                ImprovedSkill(1);
        } else {
            throw INVALID_WPN;
        }
    }
    return oldWeapon;
}

bool Human::ImprovedSkill(int improvement) {
    bool improved = false;
    if (IsActive() && HasWeapon() && improvement > 0) {
        wpnSkill[wpn->WeaponType()] += improvement;
        improved = true;
    }
    return improved;
}

int Human::HitDamage() const {
    int damage = 0;

    if (IsActive()) {
        if (HasWeapon())
            damage = wpnSkill[wpn->WeaponType()] + wpn->RollWeaponDamage(Name());
        else
            damage = PlayerClass::HitDamage();
    }
    return damage;
}

int Human::Impact() const {
    int impact = 0;
    if (IsActive() && HasWeapon()) {
        int roll = Dice::Roll(Name(), GameSpace::IMPACT, 2, 6);
        if (roll >= 2 && roll <= 12) {
            impact = ImpactIndex(roll, wpn->WeaponPower());
        }
    } else if (IsActive())
        impact = PlayerClass::Impact();
    
    return impact;
}


bool Human::IsMyEnemy(const PlayerClass* p) {
    bool isEnemy = false;
    const Human* h = dynamic_cast <const Human*>(p);
    if (p != NULL && h == NULL)
        isEnemy = true;
    
    return isEnemy;
}

void Human::Write(ostream &out) const {
    PlayerClass::Write(out);
    if (HasWeapon()) {
        out << WeaponName() << '#';
        out << WeaponSkill() << '#';
    }
    
    if (HasWeaponHistory()) {
        out << endl << '\t';
        for (int i=0; i<Weapon::NUM_DIFF_WEAPONS; i++) {
            if (SkillLookup(i) > 0) {
                out << Weapon::WpnTypeToStr(Weapon::WpnType(i)) 
                    << '#' << SkillLookup(i) << '#';
            }
        }
    }
    out << endl;
}

//********************************* Hunter ************************************

const string Hunter::TYPE_STR = "HUNTER";

const int Hunter::NUM_INIT_WPN_SKILL;

const int Hunter::INIT_VAR_STATS[PC_NUM_STATS] = {
    43, 8, 9, 9, 7, 1, -1, -1, 0, 0
};

const int Hunter::INIT_CONST_STATS[PC_NUM_CONST_STATS] = {
    43, 9, 1, 6
};

const int Hunter::INIT_WPN_SKILL[NUM_INIT_WPN_SKILL][2] = {
    Weapon::RIFLE, 6 
};

Hunter::Hunter(const string initName):
    Human(initName, INIT_VAR_STATS, INIT_CONST_STATS) {

    InitWeaponSkill();
}

string Hunter::TypeStr() const {
    return TYPE_STR;
}

Hunter::Hunter(): 
    Human("", NULL, NULL) {
}

void Hunter::InitWeaponSkill() {
    for (int i = 0; i<NUM_INIT_WPN_SKILL; i++)
        Human::SetInitWeaponSkill(Weapon::WpnType(INIT_WPN_SKILL[i][0]), INIT_WPN_SKILL[i][1]);
}

void Hunter::Write(ostream &out) const {
    out << TypeStr() << '#';
    Human::Write(out);

    return;
}

//******************************* Scavenger ***********************************

const string Scavenger::TYPE_STR = "SCAVENGER";

const int Scavenger::NUM_INIT_WPN_SKILL;

const int Scavenger::INIT_VAR_STATS[PC_NUM_STATS] = {
    82, 10, 6, 6, 10, 9, -1, -1, 0, 0
};

const int Scavenger::INIT_CONST_STATS[PC_NUM_CONST_STATS] = {
    82, 6, 3, 6
};

const int Scavenger::INIT_WPN_SKILL[NUM_INIT_WPN_SKILL][2] = {
    {Weapon::PISTOL, 11},
    {Weapon::GRENADE, 4}};

Scavenger::Scavenger(const string initName):
    Human(initName, INIT_VAR_STATS, INIT_CONST_STATS) {

    InitWeaponSkill();
}

string Scavenger::TypeStr() const {
    return TYPE_STR;
}

Scavenger::Scavenger(): 
    Human("", NULL, NULL) {
}

void Scavenger::InitWeaponSkill() {
    for (int i = 0; i<NUM_INIT_WPN_SKILL; i++)
        Human::SetInitWeaponSkill(Weapon::WpnType(INIT_WPN_SKILL[i][0]), INIT_WPN_SKILL[i][1]);
}

void Scavenger::Write(ostream &out) const {
    out << TypeStr() << '#';
    Human::Write(out);

    return;
}

//******************************** Paladin ************************************

const string Paladin::TYPE_STR = "PALADIN";

const int Paladin::NUM_INIT_WPN_SKILL;

const int Paladin::INIT_VAR_STATS[PC_NUM_STATS] = {
    28, 5, 3, 3, 4, 1, -1, -1, 0, 0
};

const int Paladin::INIT_CONST_STATS[PC_NUM_CONST_STATS] = {
    28, 3, 1, 4
};

const int Paladin::INIT_WPN_SKILL[NUM_INIT_WPN_SKILL][2] = {
};

Paladin::Paladin(const string initName):
    Human(initName, INIT_VAR_STATS, INIT_CONST_STATS) {

    InitWeaponSkill();
}

string Paladin::TypeStr() const {
    return TYPE_STR;
}

Paladin::Paladin(): 
    Human("", NULL, NULL) {
}

void Paladin::InitWeaponSkill() {
    for (int i = 0; i<NUM_INIT_WPN_SKILL; i++)
        Human::SetInitWeaponSkill(Weapon::WpnType(INIT_WPN_SKILL[i][0]), INIT_WPN_SKILL[i][1]);
}

void Paladin::Write(ostream &out) const {
    out << TypeStr() << '#';
    Human::Write(out);

    return;
}
