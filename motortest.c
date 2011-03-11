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
	int angle=100;//variable for setting servo positions
	enable_servos();
	while(1)
	{
		if(a_button()==1)// when a button is pressed
		{
			motor(0,50);//run motor at 50%
		sleep(2);
		motor(0,100);//run motor at 100%
		sleep(2);
		ao();
			}
			else if (b_button()==1)//when b button is pressed
			{
				while(angle<2000)//cycle through different servo positions and reset to 100
				{
				set_servo_position(0,angle);
				sleep(.5);
				angle=angle+200;
				}
				angle=100;
				set_servo_position(0,angle);//reset servo to 100 position
			}
	}
	
}

/*Function definitions go below.*/
