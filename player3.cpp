// Neve Laughery
// CSCI330

#include "player3.h"

const int PlayerClass::PC_NUM_STATS;
const int PlayerClass::PC_NUM_CONST_STATS;
const int PlayerClass::w = -1;
const int PlayerClass::k = 0;
const string PlayerClass::DEFAULT_NAME = "DEFAULT";

const int PlayerClass::IMPACT_TABLE[MAX_2D6][MAX_PWR] = {   
//                  Power Rating
//    0   1   2   3   4   5   6   7   8   9  10  11  12    Die Roll
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},  // 0
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},  // 1
    {-1, -1,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10},  // 2
    {-1, -1,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10,  w},  // 3
    {-1, -1,  2,  3,  4,  5,  6,  7,  8,  9, 10,  w,  w},  // 4
    {-1, -1,  3,  4,  5,  6,  7,  8,  9, 10,  w,  w,  w},  // 5
    {-1, -1,  4,  5,  6,  7,  8,  9, 10,  w,  w,  w,  w},  // 6
    {-1, -1,  5,  6,  7,  8,  9, 10,  w,  w,  w,  w,  w},  // 7
    {-1, -1,  6,  7,  8,  9, 10,  w,  w,  w,  w,  w,  w},  // 8
    {-1, -1,  7,  8,  9, 10,  w,  w,  w,  w,  w,  w,  w},  // 9
    {-1, -1,  8,  9, 10,  w,  w,  w,  w,  w,  w,  w,  w},  // 10
    {-1, -1,  9, 10,  w,  w,  w,  w,  w,  w,  w,  w,  w},  // 11
    {-1, -1, 10,  w,  w,  w,  w,  w,  w,  w,  w,  w,  w}}; // 12

const int PlayerClass::WOUND_TABLE[MAX_2D6][MAX_WILL] = {
//                  Willpower Rating           
//    0   1   2   3   4   5   6   7   8   9  10  11  12    Die Roll
    {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2},  // 0
    {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2},  // 1
    {-2, -2,  k,  k,  k,  k,  k,  k,  k,  k,  k,  k, -1},  // 2
    {-2, -2,  k,  k,  k,  k,  k,  k,  k,  k,  k, -1, -1},  // 3
    {-2, -2,  k,  k,  k,  k,  k,  k,  k,  k, -1, -1, -1},  // 4
    {-2, -2,  k,  k,  k,  k,  k,  k,  k, -1, -1, -1, -1},  // 6
    {-2, -2,  k,  k,  k,  k,  k,  k, -1, -1, -1, -1, -1},  // 7 
    {-2, -2,  k,  k,  k,  k,  k, -1, -1, -1, -1, -1, -1},  // 8  
    {-2, -2,  k,  k,  k,  k, -1, -1, -1, -1, -1, -1, -1},  // 9  
    {-2, -2,  k,  k,  k, -1, -1, -1, -1, -1, -1, -1, -1},  // 10 
    {-2, -2,  k,  k, -1, -1, -1, -1, -1, -1, -1, -1, -1},  // 11
    {-2, -2,  k, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}}; // 12

PlayerClass::PlayerClass(): NAME(""), STATS(NULL) {

}

PlayerClass::PlayerClass(const string initName, const int INIT_VAR_STATS[], const int INIT_CONST_STATS[]): 
    NAME(ValidateName(initName)), STATS(INIT_CONST_STATS) {

    SetStats(INIT_VAR_STATS); 
}

PlayerClass& PlayerClass::operator=(const PlayerClass &p) {
    if (this != &p)
        CopyIntoMe(p);
    return *this;
}

void PlayerClass::SetStats(const int INIT_VAR_STATS[]) {
    for (int i=0; i<PC_NUM_STATS; i++) {
        varStats[i] = INIT_VAR_STATS[i];
    }
}

void PlayerClass::CopyIntoMe(const PlayerClass &p) {
    *const_cast <string*> (&NAME) = p.NAME; 
    *const_cast <const int**> (&STATS) = p.STATS;

    for (int i=0; i<PC_NUM_STATS; i++) {
        varStats[i] = p.varStats[i];
    }
}

string PlayerClass::ValidateName(string initName) {
    if (initName.size() <= 0)
        initName = DEFAULT_NAME;
    else {
        string trimmed;
        stringstream ss(initName);
        string word;
        while (ss >> word) {
            trimmed += (word + " ");
        }

        trimmed = trimmed.substr(0, trimmed.size()-1);
        if (trimmed.length() > 10)
            trimmed = trimmed.substr(0, 10);
        initName = trimmed;
    }
    return initName;
}

string PlayerClass::Name() const {
    return NAME;
}

int PlayerClass::Row() const{
    return varStats[ROW];
}

int PlayerClass::Col() const {
    return varStats[COL];
}

char PlayerClass::Dir() const {
    return GameSpace::DIR_CHAR[varStats[DIR]];  
}

int PlayerClass::Health() const {
    return varStats[HEALTH];
}

int PlayerClass::WillPower() const {
    return varStats[WILLPOWER];
}

int PlayerClass::MaxSpeed() const {
    return STATS[MAX_SPEED];
}

int PlayerClass::CurrentSpeed() const {
    return varStats[CUR_SPEED];
}

int PlayerClass::Momentum() const {
    return varStats[MOMENTUM];
}

int PlayerClass::Power() const {
    return varStats[POWER];
}

int PlayerClass::RollPhysDam() const {
    return Dice::Roll(Name(), GameSpace::DAMAGE, STATS[PD_NUM_DIE], STATS[PD_FACES]);
}

int PlayerClass::Defense() const {
    return varStats[DEFENSE];
}

bool PlayerClass::IsAlive() const {
    return (varStats[HEALTH] > 0 || varStats[WILLPOWER] > 0);
}

bool PlayerClass::IsDead() const {
    return (varStats[HEALTH] <= 0 || varStats[WILLPOWER] <= 0);
}

bool PlayerClass::IsActive() const { 
    return (varStats[ACTIVE] == 1); 
}

bool PlayerClass::MakeActive() {
    bool set = false;

    if (IsAlive()) {
        varStats[ACTIVE] = 1;
        set = true;
    }
    return set;
}

bool PlayerClass::MakeInActive() {
    varStats[ACTIVE] = 0;
    return true;
}

bool PlayerClass::MakeDead() {
    if (IsActive() || IsDead()) {
        varStats[HEALTH] = 0;
        varStats[WILLPOWER] = 0;
        varStats[CUR_SPEED] = 0;
        varStats[MOMENTUM] = 0;
        varStats[ACTIVE] = 0;
    }
    return IsDead();
}

int PlayerClass::Wounded(int damage) {
    if (IsActive() && damage >= 0) 
        varStats[HEALTH] -= damage;

    if (IsDead())
        MakeDead();

    return varStats[HEALTH];
}

int PlayerClass::Invigorate(int vigor) {
    if ((IsActive()) && (vigor >= 0)) {
        varStats[HEALTH] += vigor;
        if (varStats[HEALTH] > STATS[MAX_HEALTH])
            varStats[HEALTH] = STATS[MAX_HEALTH];
    }
    return varStats[HEALTH];
}

bool PlayerClass::Heal() {
    int healAmount = 10;
    bool healed = false;

    if (IsActive() && IsAlive()) {
        varStats[CUR_SPEED] = STATS[MAX_SPEED];
        varStats[HEALTH] += healAmount;
        if (varStats[HEALTH] > STATS[MAX_HEALTH])
            varStats[HEALTH] = STATS[MAX_HEALTH];
        healed = true;
    }
    return healed;
}

int PlayerClass::WillDamage(int willDmg) {
    if (IsActive() && (willDmg >= 0))
        varStats[WILLPOWER] -= willDmg;

    if (varStats[WILLPOWER] <= 0)
        MakeDead();
}

int PlayerClass::AddWill(int addWill) {
    if (IsActive() && (addWill >= 0))
        varStats[WILLPOWER] += addWill;

    return varStats[WILLPOWER];
}

int PlayerClass::SlowDown(int hazard) {
    if (IsActive() && hazard >= 0) {
        varStats[CUR_SPEED] -= hazard;
        if (varStats[CUR_SPEED] < 0)
            varStats[CUR_SPEED] = 0;
        if (varStats[MOMENTUM] > varStats[CUR_SPEED])
            ResetMomentum();
    }
    return varStats[CUR_SPEED];
}

int PlayerClass::ResetCurrentSpeed() {
    if (IsActive()) 
        varStats[CUR_SPEED] = STATS[MAX_SPEED];
    
    return varStats[CUR_SPEED];
}

int PlayerClass::ResetMomentum() {
    if (IsActive()) 
        varStats[MOMENTUM] = varStats[CUR_SPEED];

    return varStats[MOMENTUM];
}

int PlayerClass::UseMomentum(int num) {
    if (IsActive() && num >= 0) {
        varStats[MOMENTUM] -= num;
        if (varStats[MOMENTUM] < 0) 
            varStats[MOMENTUM] = 0; 
    }
    return varStats[MOMENTUM];
}

bool PlayerClass::SetCell(int newRow, int newCol) {
    bool set = false;

    if ((newRow >= 0 && newCol >= 0) || (newRow == -1 && newCol == -1)) {
        varStats[ROW] = newRow;
        varStats[COL] = newCol;
        set = true;
    }
    return set;
}

bool PlayerClass::SetDir(DirType newDir) {
    bool set = false;
    if (newDir >= GameSpace::NORTH && newDir <= GameSpace::WEST) {
        varStats[DIR] = newDir;
        set = true;
    }
    return set;
}

void PlayerClass::Write(ostream& out) const {
    if (IsActive())
        out << '1';
    else
        out << '0';
    out << '#' << Name() << '#' << '(' << Row() << ',' << Col() << ',' << Dir()
    << ")#" << Health() << '#' << WillPower() << '#' << Power() << '#' 
    << CurrentSpeed() << '#' << Momentum() << '#' << STATS[PD_NUM_DIE] 
    << 'D' << STATS[PD_FACES] << '#' << Defense() << '#' << endl;
    /*
    if (Human()) {
        if (HasWeapon()) {
            out << WeaponName() << '#' <<
            varStats[CUR_WPN_SKILL] << '#' << endl << '\t';
        } else
            out << endl << '\t';
        for (int i=0; i<Weapon::NUM_DIFF_WEAPONS; i++) {
            if (allWeaponSkill[i] > 0) {
                out << Weapon::WpnTypeToStr(Weapon::WpnType(i)) << '#' << allWeaponSkill[i] << '#';
            }
        }
        out << endl;
    */
}

ostream& operator<<(ostream& out, const PlayerClass *p) {
    if (p != NULL)
        p->Write(out);
    return out;
}

int PlayerClass::UpdateDefense(int amount) {
    if (IsActive()) {
        varStats[DEFENSE] += amount;
        if (varStats[DEFENSE] < 0)
            varStats[DEFENSE] = 0;
    }
    return varStats[DEFENSE];
}

int PlayerClass::HitScore() const {
    int score = 0;
    if (IsActive())
        score = Dice::Roll(Name(), GameSpace::HITSCORE, 2, 6); 
    return score;
}

int PlayerClass::HitDamage() const {
    int damage = 0;

    if (IsActive()) {
        //if (HasWeapon()) {
            //damage = varStats[CUR_WPN_SKILL] + playerWeapon->RollWeaponDamage(Name());
        //} else {
            damage = varStats[POWER] + RollPhysDam();
        //}
    }
    return damage;
}

int PlayerClass::Impact() const{
    int impact = 0;
    int power;
    if (IsActive()) {
        int roll = Dice::Roll(Name(), GameSpace::IMPACT, 2, 6);
        if (roll >= 2 && roll <= 12) { 
            if (varStats[POWER] >= 2)
                power = varStats[POWER];
            if ((varStats[POWER] <= 12 && varStats[POWER] >= 2) && (roll >= 2 && roll <= 12))
                impact = ImpactIndex(roll, power); 
        }
    }
    return impact;
}

int PlayerClass::ImpactIndex(int roll, int power) const {
    return IMPACT_TABLE[roll][power];
}

bool PlayerClass::CriticalWound() {
    int damage = 10;
    int willDmg = 1;
    int roll;
    int slowed = varStats[CUR_SPEED] - varStats[CUR_SPEED]/2 ;
    int crit;

    if(IsActive()) {
        Wounded(damage);
        SlowDown(slowed);
        if (IsAlive()) {
            roll = Dice::Roll(Name(), GameSpace::WOUND, 2, 6);
            if ((varStats[WILLPOWER] <= 12 && varStats[WILLPOWER] >= 2) && (roll >= 2 && roll <= 12))
                crit = WOUND_TABLE[roll][varStats[WILLPOWER]];

            if (crit == -1)
                WillDamage(willDmg);
            else
                MakeDead();
        }
    }
    return IsAlive();
}

string PlayerClass::MakeUpper(string str) const {
    string makeUpper = str;
    transform(makeUpper.begin(), makeUpper.end(), makeUpper.begin(), ::toupper);
    return makeUpper;
}

bool PlayerClass::operator==(const PlayerClass &p) const {
    return (MakeUpper(Name()) == MakeUpper(p.Name()));   
}

bool PlayerClass::operator!=(const PlayerClass &p) const {
    return (MakeUpper(Name()) != MakeUpper(p.Name()));   
}

bool PlayerClass::operator<=(const PlayerClass &p) const {
    return (MakeUpper(Name()) <= MakeUpper(p.Name()));   
}

bool PlayerClass::operator<(const PlayerClass &p) const {
    return (MakeUpper(Name()) < MakeUpper(p.Name()));   
}

bool PlayerClass::operator>=(const PlayerClass &p) const {
    return (MakeUpper(Name()) >= MakeUpper(p.Name()));   
}

bool PlayerClass::operator>(const PlayerClass &p) const {
    return (MakeUpper(Name()) > MakeUpper(p.Name()));   
}
