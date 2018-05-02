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

//********************************** Frog *************************************

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
        virtual string TypeStr() const;
        
        /*
        Narrative: Adds the frog type string to the stream and sends it to
        Venom's Write function
        Precondition: Player and Venom output streams are correct
        Postcondition: Type string has been added to the stream and returned
        */
        void Write(ostream &out) const;
        
        virtual bool IsMyEnemy(const PlayerClass *p) const;

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

//******************************** Spider *************************************

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
        virtual string TypeStr() const;
        
        /*
        Narrative: Adds the spider type string to the stream and sends it to
        Venom's Write function
        Precondition: Player and Venom output streams are correct
        Postcondition: Type string has been added to the stream and returned
        */
        void Write(ostream &out) const;
        
        virtual bool IsMyEnemy(const PlayerClass *p) const;

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

//******************************** Viper **************************************

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
        virtual string TypeStr() const;
        
        /*
        Narrative: Adds the viper type string to the stream and sends it to
        Venom's Write function
        Precondition: Player and Venom output streams are correct
        Postcondition: Type string has been added to the stream and returned
        */
        void Write(ostream &out) const;
        
        virtual bool IsMyEnemy(const PlayerClass *p) const;

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
