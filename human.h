// Neve Laughery
// CS330

//********************************* Human *************************************

#ifndef _HUMAN
#define _HUMAN

#include "player3.h"

class Human: virtual public PlayerClass {

    protected:
        
        /*
        Narrative: Initializes an instance of the Human class
        */
        Human(const string initName, const int INIT_VAR_STATS [PC_NUM_STATS], 
                const int INIT_CONST_STATS [PC_NUM_CONST_STATS]);
        
        /*
        Narrative: Copies all of the data from the given Human into the current
        Human
        Pre-condition: None
        Post-condition: The given Human's data has been copied into this Human
        */
        Human(const Human& h);
        
        /*
        Narrative: Checks to see if this instance is not the same as the given 
        Human then calls CopyIntoMe on the given instance of a Human class to 
        copy into this instance
        Pre-condition: None
        Post-condition: The Human class has been copied into this Human class
        */
        Human& operator=(const Human& h);
        
        /*
        Narrative: 
        Pre-condition: 
        Post-condition: 
        */
        bool SetInitWeaponSkill(Weapon::WpnType wpn, int skill);

    public:
        
        /*
        Narrative: This destructor deallocates the dynamic memory for weapon
        Pre-condition: None
        Post-condition: The dynamic memory has been properly deallocated
        */
        virtual ~Human();
        
        /*
        Narrative: Returns whether or not the Human is holding a weapon
        Pre-condition: None
        Post-condition: Bool representing whether or not the Human is holding 
        a weapon is returned
        */
        bool HasWeapon() const;
        
        /*
        Narrative: Returns the name of the Human's weapon.
        Pre-condition: Weapon class has been properly linked
        Post-condition: The weapon's name is returned. If the Human did not have 
        a weapon an empty string is returned.
        */
        string WeaponName() const;
        
        /*
        Narrative: Returns the Human's current weapon
        Pre-condition: None
        Post-condition: Current weapon has been returned
        */
        Weapon* Wpn() const;
        
        /*
        Narrative: The Human's weapon skill for a given weapon is returned
        Pre-condition: Weapon class has been properly linked
        Post-condition: The weapon skill has been returned
        */
        int WeaponSkill() const;
        
        /*
        Narrative: The Human's weapon skill for their current weapon is returned
        Pre-condition: Weapon class has been properly linked
        Post-condition: Current weapon skill has been returned
        */
        int SkillLookup(int wpnType) const;
        
        bool HasWeaponHistory() const;
        
        /*
        Narrative: The Human's weapon is returned. If the Human is holding a 
        weapon their weapon pointer is set to NULL.
        Pre-condition: None
        Post-condition: Weapon has been set to NULL if the Human was holding 
        one and previous weapon has been returned
        */
        Weapon* DropWeapon();
        
        /*
        Narrative: An active human Human recieves the weapon. If they had no 
        weapon skill for this weapon they now have one weapon skill point for it.
        Pre-condition: None
        Post-condition: The Human now has the given weapon and their previous 
        weapon has been returned.
        */
        Weapon* GrabWeapon(Weapon* weapon);
        
        /*
        Narrative: An amount is added to the Human's skill for their current weapon
        Pre-condition: None
        Post-condition: The weapon skill improvement amount has been added 
        */
        bool ImprovedSkill(int improvement);
        
        /*
        Narrative: Returns the amount of damage done by an active Human. This 
        damage value is found either by weapon damage or power if the Human 
        does not have a weapon. 
        Pre-condition: Weapon class has been properly linked
        Post-condition: The damage is returned
        */
        int HitDamage() const;
        
        /*
        Narrative: Makes an impact roll for an active Human then gets their 
        power from either weapon damage or power if they do not have a weapon. 
        These two values are used to index the impact table which returns the 
        result.
        Pre-condition: Dice class and weapon class have been properly linked.
        Post-condition: Impact table result has been returned
        */
        int Impact() const;
        
        /*
        Narrative: Adds the Human's information to the player stream
        Pre-condition: Player's stream is correct
        Post-condition: Information has been added to stream
        */
        void Write(ostream &out) const;
        
        virtual bool IsMyEnemy(const PlayerClass* p);
        
    private:
        
        /*
        Narrative: Default constructor for the Frog class
        */
        Human();
        
        /*
        Narrative: Copies all of the data from the given Human into the current
        Human
        Pre-condition: None
        Post-condition: The given Human's data has been copied into this Human
        */
        void CopyIntoMe(const Human& h);
        
        // The Human's current weapon
        Weapon* wpn;
        
        // Array of the Human's weapon skill values
        int wpnSkill[Weapon::NUM_DIFF_WEAPONS];

};


//********************************* Hunter ************************************


class Hunter: public Human {

    public:
        
        /*
        Narrative: Initializes an instance of the Human class
        */
        Hunter(const string initName); 
        
        /*
        Narrative: Returns the player's type as a string
        Pre-condition: Human's type has been initialized
        Post-condition: Type string has been returned
        */
        
        /*
        Narrative: Adds the Hunter's information to PlayerClass'
        Write stream
        Precondition: Player and Human output streams are correct
        Postcondition: Type string has been added to the stream and returned
        */
        virtual void Write(ostream &out) const;
        
        // String representing Human's type
        static const string TYPE_STR;

    private:

        static const int NUM_INIT_WPN_SKILL = 1;
        
        /*
        Narrative: Default constructor for the Hunter class
        */
        Hunter();
        
        void InitWeaponSkill();
        
        // Array holding Hunter's initial weapon skills
        static const int INIT_WPN_SKILL[NUM_INIT_WPN_SKILL][2];
        
        // Array holding Hunter's initial variable stats
        static const int INIT_VAR_STATS[PC_NUM_STATS];
        
        // Array holding Hunter's initial constant stats
        static const int INIT_CONST_STATS[PC_NUM_CONST_STATS];

};

//******************************* Scavenger ***********************************

class Scavenger: public Human {

    public:
        
        /*
        Narrative: Initializes an instance of the Human class
        */
        Scavenger(const string initName); 
        
        /*
        Narrative: Returns the player's type as a string
        Pre-condition: Human's type has been initialized
        Post-condition: Type string has been returned
        */
        virtual string TypeStr() const;
        
        /*
        Narrative: Adds the Scavenger's information to PlayerClass'
        Write stream
        Precondition: Player and Human output streams are correct
        Postcondition: Type string has been added to the stream and returned
        */
        virtual void Write(ostream &out) const;
        
        // String representing Human's type
        static const string TYPE_STR;

    private:

        static const int NUM_INIT_WPN_SKILL = 2;
        
        /*
        Narrative: Default constructor for the Scavenger class
        */
        Scavenger();
        
        void InitWeaponSkill();
        
        // Array holding Scavenger's initial weapon skills
        static const int INIT_WPN_SKILL[NUM_INIT_WPN_SKILL][2];
        
        // Array holding Scavenger's initial variable stats
        static const int INIT_VAR_STATS[PC_NUM_STATS];
        
        // Array holding Scavenger's initial constant stats
        static const int INIT_CONST_STATS[PC_NUM_CONST_STATS];

};

//******************************** Paladin ************************************

class Paladin: public Human {

    public:
        
        /*
        Narrative: Initializes an instance of the Paladin class
        */
        Paladin (const string initName); 
        
        /*
        Narrative: Returns the player's type as a string
        Pre-condition: Paladin's type has been initialized
        Post-condition: Type string has been returned
        */
        virtual string TypeStr() const;
        
        /*
        Narrative: Adds the Paladin's information to PlayerClass'
        Write stream
        Precondition: Player and Human output streams are correct
        Postcondition: Type string has been added to the stream and returned
        */
        virtual void Write(ostream &out) const;
        
        // String representing Human's type
        static const string TYPE_STR;

    private:

        static const int NUM_INIT_WPN_SKILL = 0;
        
        /*
        Narrative: Default constructor for the Paladin class
        */
        Paladin();
        
        void InitWeaponSkill();
        
        // Array holding Paladin's initial weapon skills
        static const int INIT_WPN_SKILL[NUM_INIT_WPN_SKILL][2];
        
        // Array holding Paladin's initial variable stats
        static const int INIT_VAR_STATS[PC_NUM_STATS];
        
        // Array holding Paladin's initial constant stats
        static const int INIT_CONST_STATS[PC_NUM_CONST_STATS];

};

#endif
