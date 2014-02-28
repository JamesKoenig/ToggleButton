// ToggleButton library for Arduino
// By Jester <jester@jestah.net>
// Provides a simple means of using a pushbutton as a toggle switch

#ifndef ToggleButton_h
#define ToggleButton_h

#include "Arduino.h"

class ToggleButton
{
    public:
        ToggleButton(int buttonPin, int buttonActiveState, 
                bool beginState = false, int debounceDuration = 100);
        void setDebounce(int duration);
        void checkButton(void);
        bool state(void);
    
    private:
        void flipState(void);
        bool debounce(int pinState);
        bool currentState;
        int activeState;
        int button;

        //used in switch debouncing, requires more than local (because of
        // duration) or static (because multiple buttons accessing the same 
        // static var would be bad. So they have to be in the class.
        //      It's a struct beause of reasons.
        static struct  //static to prevent external linkage of anonymous struct
        {
            int prevState;      //snapshot to reset our timer if changed
            int debounceLength; //delta-t used in tf - ti > dt calculation
            //this var has to be a long as it takes the time in ms
            long  timeInitial;  //our initial intial value (ti in above eq)
            //end val comes from millis() so a var is not required
        } debouncer;
};

#endif
