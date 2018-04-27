// Neve Laughery
// CS330

//********************************* Venom *************************************

#ifndef _VENOM
#define _VENOM

#include "player3.h"

class Venom: public PlayerClass {

    public:
        Venom(const string initName, const int INIT_VAR_STATS [PC_NUM_STATS], const int INIT_CONST_STATS [PC_NUM_CONST_STATS]);
        void Write(ostream &out) const;
       
    private:
        Venom();

};

#endif

//********************************** Frog *************************************

#ifndef _FROG
#define _FROG

#include "player3.h"

class Frog: public Venom {

    public:
       Frog(const string initName); 
       static string TypeStr();
       void Write(ostream &out) const;

    private:
        Frog();
        static const string TYPE_STR;
        static const int INIT_VAR_STATS[PC_NUM_STATS];
        static const int INIT_CONST_STATS[PC_NUM_CONST_STATS];

};

#endif

//******************************** Spider *************************************

#ifndef _SPIDER
#define _SPIDER

#include "player3.h"

class Spider: public Venom {

    public:
       Spider(const string initName); 
       static string TypeStr();
       void Write(ostream &out) const;

    private:
        Spider();
        static const string TYPE_STR;
        static const int INIT_VAR_STATS[PC_NUM_STATS];
        static const int INIT_CONST_STATS[PC_NUM_CONST_STATS];

};

#endif

//******************************** Viper **************************************

#ifndef _VIPER
#define _VIPER

#include "player3.h"

class Viper: public Venom {

    public:
       Viper(const string initName); 
       static string TypeStr();
       void Write(ostream &out) const;

    private:
        Viper();
        static const string TYPE_STR;
        static const int INIT_VAR_STATS[PC_NUM_STATS];
        static const int INIT_CONST_STATS[PC_NUM_CONST_STATS];

};

#endif
