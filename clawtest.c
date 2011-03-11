/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/

int main()
{
	enable_servos(); //enable servos
	set_servo_position(2,1000); //close claw,grab blocks
	sleep(1.0); //wait
	motor(1,100); //lift blocks
	sleep(2.0); //wait
	set_servo_position(2,2047); //open claw, drop blocks
	disable_servos(); //disable servos
	
	//variable declarations go here.

	// uncomment the line below anf put 1s in the appropriate places if using floating sensors (ET and sonar)
	//set_each_analog_state(0,0,0,0,0,0,0,0);// This line sets analog ports to be pullup (0) or floating (1)
	
	// uncomment the line below to have the rest of the program wait for the starting light to turn on
	//wait_for_light(port_number);//replace "port_number" with the analog port number into which the light sensor is connected
	
	// uncomment the line below to have a function run for a specified amount of seconds
	//run_for(num_secs, function_name);//replace num_secs with the amount of time to run and function_name with your function's name
}

/*Function definitions go below.*/
