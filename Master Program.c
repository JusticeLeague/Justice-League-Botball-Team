int main()
{
	motor(0,100);
	motor(3,100);
	sleep(2.5);
	ao();
	sleep(3.0);// first blocks
	motor(0,100);
	motor(3,100);
	sleep(2.5);
	ao();
	sleep(3.0);// second blocks
	motor(0,100);
	motor(3,100);
	sleep(0.5);
	ao();
	sleep(0.5);// stop next to runway
	motor(0,-100);
	motor(3,-100);
	sleep(0.5);// reverse
	motor(0,100);
	motor(3,-100);
	sleep(0.1);// turn to the right
	motor(0,100);
	motor(3,100);
	sleep(2.5);// go straight
	motor(3,100);
	motor(0,-100);
	sleep(0.5);// turn to biofuel storage
	motor(0,100);
	motor(3,100);
	sleep(0.4);
	ao();
	sleep(3.0);// go to biofuel storage, dump biofuel
	motor(0,-100);
	motor(3,-100);
	sleep(1.0);// reverse out of biofuel area
	motor(3,100);
	motor(0,-100);
	sleep(0.2);// turn to blocks
	ao();
	printf("done");
}
