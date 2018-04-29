// Neve Laughery
// CS330

//********************************* Venom *************************************

#ifndef _VENOM
#define _VENOM

#include "player3.h"

class Venom: public PlayerClass {

    public:
        
        /*
        Narrative: Initializes an instance of the venom class
        */
        Venom(const string initName, const int INIT_VAR_STATS [PC_NUM_STATS], 
              const int INIT_CONST_STATS [PC_NUM_CONST_STATS]);
        
        /*
        Narrative: Sends stream up to PlayerClass' Write function
        Precondition: PlayerClass' stream is correct 
        Postcondition: Stream has been sent up the hierarchy
        */
        void Write(ostream &out) const;
       
    private:
        
        /*
        Narrative: Default constructor for the Venom class
        */
        Venom();

};

#endif

//********************************** Frog *************************************

#ifndef _FROG
#define _FROG

#include "player3.h"

class Frog: public Venom {

    public:
        
        /*
        Narrative: Initializes an instance of the frog class
        */
        Frog(const string initName); 
        
        /*
        Narrative: Returns the string representing the type
        Precondition: None
        Postcondition: Type string has been returned
        */
        static string TypeStr();
        
        /*
        Narrative: Adds the frog type string to the stream and sends it to
        Venom's Write function
        Precondition: Human and Venom output streams are correct
        Postcondition: Type string has been added to the stream and returned
        */
        void Write(ostream &out) const;

    private:
        
        /*
        Narrative: Default constructor for the Frog class
        */
        Frog();
        
        // String representing Frog's type
        static const string TYPE_STR;
        
        // Array holding initial variable stats for Frog
        static const int INIT_VAR_STATS[PC_NUM_STATS];
        
        // Array holding constant stats for Frog
        static const int INIT_CONST_STATS[PC_NUM_CONST_STATS];

};

#endif

//******************************** Spider *************************************

#ifndef _SPIDER
#define _SPIDER

#include "player3.h"

class Spider: public Venom {

    public:
        
        /*
        Narrative: Initializes an instance of the spider class
        */
        Spider(const string initName); 
        
        /*
        Narrative: Returns the string representing the type
        Precondition: None
        Postcondition: Type string has been returned
        */
        static string TypeStr();
        
        /*
        Narrative: Adds the frog type string to the stream and sends it to
        Venom's Write function
        Precondition: Human and Venom output streams are correct
        Postcondition: Type string has been added to the stream and returned
        */
        void Write(ostream &out) const;

    private:
        
        /*
        Narrative: Default constructor for the Spider class
        */
        Spider();
        
        // String representing Spider's type
        static const string TYPE_STR;
        
        // Array holding initial variable stats for Spider
        static const int INIT_VAR_STATS[PC_NUM_STATS];
        
        // Array holding constant stats for Spider
        static const int INIT_CONST_STATS[PC_NUM_CONST_STATS];

};

#endif

//******************************** Viper **************************************

#ifndef _VIPER
#define _VIPER

#include "player3.h"

class Viper: public Venom {

    public:
       
        /*
        Narrative: Initializes an instance of the viper class
        */
        Viper(const string initName); 
        
        /*
        Narrative: Returns the string representing the type
        Precondition: None
        Postcondition: Type string has been returned
        */
        static string TypeStr();
        
        /*
        Narrative: Adds the frog type string to the stream and sends it to
        Venom's Write function
        Precondition: Human and Venom output streams are correct
        Postcondition: Type string has been added to the stream and returned
        */
        void Write(ostream &out) const;

    private:
        
        /*
        Narrative: Default constructor for the Viper class
        */
        Viper();
        
        // String representing Viper's type
        static const string TYPE_STR;
        
        // Array holding initial variable stats for Viper
        static const int INIT_VAR_STATS[PC_NUM_STATS];
        
        // Array holding constant stats for Viper
        static const int INIT_CONST_STATS[PC_NUM_CONST_STATS];

};

#endif
