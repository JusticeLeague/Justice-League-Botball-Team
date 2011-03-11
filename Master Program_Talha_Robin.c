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
	mav(0,1000);
	mav(3,1000);
	sleep(3.0); //Drive straight, move blocks
	ao();
	sleep(2.0); //Collect biofuels
	mav(0,1000);
	mav(3,1000);
	sleep(5.0); //Drive straight, move second blocks
	ao();
	sleep(2.0); //Collect biofuels
	mav(0,1000);
	mav(3,1000);
	sleep(1.0); //Move blocks to edge
	ao(); //Stop
	//Tip plane onto runway
	mav(0,0);
    mav(0,1000);	
	sleep(1.25); //Rotate right about 90 degrees
	mav(0,1000);
	mav(3,1000);
    sleep(3.0);	//Drive straight
	mav(0,-1000);
	mav(3,0);
	sleep(1.3);
	mav(0,1000);
	mav(3,1000);//Drive to biofuel bulk storgae
	sleep(1.0);
	ao();
	sleep(3.0); //Deposit biofuel into bulk storage
	mav(0,-1000);
	mav(3,-1000);
	sleep(1.0);//Reverse out of bulk storage
	mav(0,0);
	mav(3,1000);
	sleep(1.0);//turn to blocks
	mav(0,1000);
	mav(3,1000);
	sleep(1.7);
	ao();
	sleep(0.1);//temp. stop
	beep();
	sleep(1.5);//beep
}
