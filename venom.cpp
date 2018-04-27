// Neve Laughery
// CS330

#include "venom.h"

//********************************* Venom *************************************

Venom::Venom():
    PlayerClass("", NULL, NULL) {
}

Venom::Venom(const string initName, const int INIT_VAR_STATS[], const int INIT_CONST_STATS[]):
    PlayerClass(initName, INIT_VAR_STATS, INIT_CONST_STATS) {
}

void Venom::Write(ostream &out) const{
    PlayerClass::Write(out);
}

//********************************** Frog *************************************

const string Frog::TYPE_STR = "FROG";

const int Frog::INIT_VAR_STATS[PC_NUM_STATS] = {
    61, 10, 9, 9, 11, 9, -1, -1, 0, 0
};

const int Frog::INIT_CONST_STATS[PC_NUM_CONST_STATS] = {
    61, 9, 3, 6
};

Frog::Frog(const string initName):
    Venom(initName, INIT_VAR_STATS, INIT_CONST_STATS) {
}

string Frog::TypeStr() {
    return TYPE_STR;
}

Frog::Frog(): 
    Venom("", NULL, NULL) {
}

void Frog::Write(ostream &out) const {
    out << TypeStr() << '#';
    Venom::Write(out);
}

//******************************** Spider *************************************

const string Spider::TYPE_STR = "SPIDER";

const int Spider::INIT_VAR_STATS[PC_NUM_STATS] = {
    51, 9, 16, 16, 12, 8, -1, -1, 0, 0
};

const int Spider::INIT_CONST_STATS[PC_NUM_CONST_STATS] = {
    51, 16, 2, 6
};

Spider::Spider(const string initName):
    Venom(initName, INIT_VAR_STATS, INIT_CONST_STATS) {
}

string Spider::TypeStr() {
    return TYPE_STR;
}

Spider::Spider(): 
    Venom("", NULL, NULL) {
}

void Spider::Write(ostream &out) const {
    out << TypeStr() << '#';
    Venom::Write(out);
}

//********************************* Viper *************************************

const string Viper::TYPE_STR = "VIPER";

const int Viper::INIT_VAR_STATS[PC_NUM_STATS] = {
    21, 8, 3, 3, 6, 11, -1, -1, 0, 0
};

const int Viper::INIT_CONST_STATS[PC_NUM_CONST_STATS] = {
    21, 3, 2, 6
};

Viper::Viper(const string initName):
    Venom(initName, INIT_VAR_STATS, INIT_CONST_STATS) {
}

string Viper::TypeStr() {
    return TYPE_STR;
}

Viper::Viper(): 
    Venom("", NULL, NULL) {
}

void Viper::Write(ostream &out) const {
    out << TypeStr() << '#';
    Venom::Write(out);
}
