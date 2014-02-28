// ToggleButton library for Arduino
// By Jester <jester@jestah.net>
// Provides a simple means of using a pushbutton as a toggle switch

#include "ToggleButton.h"

// constructor
// Set up input pin, active state of the button (HIGH or LOW),
// the debounce duration, and the starting toggle state
ToggleButton::ToggleButton(int buttonPin, int buttonActiveState, bool beginState,
                            int debounceDuration)
{
    button = buttonPin;
    debouncer.debounceLength = debounceDuration;
    debouncer.prevState = 0;
    debouncer.timeInitial = millis();
    currentState = beginState;
    activeState = buttonActiveState;   
    
    pinMode(button, INPUT);
};

// Check if the button is active (pressed) and flip the toggle if it is
void ToggleButton::checkButton(void)
{    
    int state = digitalRead(button);
    //static local variables are auto-initialized to zero under ISO C++ 

    //if the input has stabilized and is at the requested value
    if(debounce(state) && state == activeState)
    {
        //toggle our little guy
        currentState != currentState;
    }
}

//check if the circuit bounced
bool ToggleButton::debounce(int pinState)
{
    if(pinState != debouncer.prevState)
    {
        //set previous state 
        debouncer.prevState = pinState;
        //reset initial time value 
        debouncer.timeInitial = millis();
        //note: at this point it is impossible for dt > expected 
    }
    //calculate if dt > expected to see if state is stable
    if((millis() - debouncer.timeInitial) > (long) debouncer.debounceLength)
    {
        return true;
    }

    return false;
}

void ToggleButton::setDebounce(int duration)
{
        debouncer.debounceLength = duration;
}

//accessor to protect state flag from external meddling with the switch state
bool ToggleButton::state()
{
    return currentState;
}
