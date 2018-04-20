 /*
* TurnToBeeState.cpp
 *
 *  Created on: 18 avr. 2018
 *      Author: Maxime
 */

#include "TurnToBeeState.h"
#include "LaunchBeeState.h"
#include "ThrowState.h"
#include "../Navigator.h"
#include "Arduino.h"
#include "../params.h"
#include "FSMSupervisor.h"

TurnToBeeState turnToBeeState = TurnToBeeState();

TurnToBeeState::TurnToBeeState() {
	time_start = 0;
}

TurnToBeeState::~TurnToBeeState() {
	// TODO Auto-generated destructor stub
}

void TurnToBeeState::enter() {
	Serial.println("Etat rotation vers l'abeille");
	navigator.turn_to(0,0);
	time_start = millis();
}

void TurnToBeeState::leave() {

}

void TurnToBeeState::doIt() {
	if(navigator.isTrajectoryFinished()){
		fsmSupervisor.setNextState(&launchBeeState);
	}
}

void TurnToBeeState::reEnter(unsigned long interruptTime){
	time_start+=interruptTime;
}

void TurnToBeeState::forceLeave(){

}
