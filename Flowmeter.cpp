/*PSEUDOCODE FLOWMETER

initTimer();
initGPIO;							als input
initGPIOinterrupt();

GPIO_INTERRUPT(){
	if(gpioPin = 1){
		
		Timestamp = getTimestamp();
		publish(calculate_flow());
	}
}

*/
void initGPIO{
	//refer to page 530 in technical manual for the interrupt registers
	/*
	Output configuration refer to page 533 in technical manual for the interrupt registers
	Input configuration refer to page 533 in technical manual for the interrupt registers
	Intterup configuration refer to page 533 in technical manual for the interrupt registers
	
	*/


	//------------------------------INIT CODE FOR INPUT PINS -----------------------------\\




	//------------------------------INIT CODE FOR OUTPUT PINS -----------------------------\\
	
	
	//GPIO_<Port>_ENABLE_CONFIG_<Num>_0 |= 83;


	//------------------------------INIT CODE FOR INTERRUPTS ------------------------------\\

}
int getTimestamp() {
	//refer to page 527 in technical manual

	
}


int calculate_flow() {


	/*berekenen pulsen per minuut
	1/Tijd tussen pulsen * 60 ---> naar aantal pulse dat er per minuut is
	Aantal pulsen / 2500 ------> uitkomst is flow in Liters
	*/

		int flow = (1 / timeElapsed * 60) / 2500;
	return flow;
}
