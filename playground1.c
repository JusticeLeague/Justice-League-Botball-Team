/***************************************************************************
*********  This program runs the main program for bot-man  
*********         it contains subroutines for moving
*********             the bot and sorting poms
***************************************************************************/
/* #defines and constants go below.*/

int go(int distance, int speed);
int spinl(int angle, int speed);
int spinr(int angle, int speed);
int backup(int distance, int speed);
int catcher(int angle);
//Values for distance, angle and speed are always positive.  Subroutines will make sign change as needed

int go(distance,speed)
{
	
   set_create_distance(0); //resets starting distance to zero
	while(get_create_distance(.1)<distance)
	{ 
		create_drive_straight(speed);
	}
	
}

int spinl(angle,speed)
{
	
    set_create_total_angle(0); // resets starting angle
	    while(get_create_total_angle(.1) < angle)
    {
        create_spin_CCW(speed);
    }
}

	
int spinr(angle,speed)
{

    set_create_total_angle(0); // resets starting angle
	    while(get_create_total_angle(.1) > -angle)
    {
        create_spin_CW(speed);
		}
}


int backup(distance,speed)
{
	set_create_distance(0);//resets starting angle
	    while(get_create_distance(.1)>-distance)
    {
        create_drive_straight(-speed);
    }
}

int catcher(angle)
{
	enable_servos();
	set_servo_position(0,angle);
}

/*int sort(color)
{
	int offset, x, y;
	int light=analog(2);//light sensor to see if anything is in the claw
	enable_servos();
	set_servo_position(2,2000);//open the claw all the way
	
	track_update(); // get most recent camera image and process it
	while(light <100) //while light value is low - nothing in the claw
	{
		x = track_x(1,0);  // get image x data
		y = track_y(1,0);  //    and y data
		if(track_count(1) > 0) {  // there is a blob
			printf("Blob is at (%d,%d)\n",x,y);
			offset=5*(x-80);  // amount to deviate servo from center
			set_servo_position(2,1024+offset); 
		}
		else {
			printf("No colored object in sight\n");
		}
		sleep(0.2);      // don't rush print statement update
		track_update();  // get new image data before repeating
	}
	disable_servos();
	printf("All done\n");
	
}*/

int findpoms()
{
	int lift=1;
	track_update();
	int trackblobs=track_count(0)+track_count(2);
	int newtrackblobs;
	int oldtrackblobs;
	enable_servos();
	set_servo_position(lift,1000); //lift the arm with the camera
	while(trackblobs==0) //while there are no blobs in the camera's field of view swing the arm
	{
		track_update();
		mav(0,30);
		oldtrackblobs=trackblobs;
	}
	
	while(1)
	{
		off(0);
		mav(0,30);//shift a little to one the left
		sleep(.3);
		off(0);
		track_update();
		newtrackblobs=trackblobs;
	if(newtrackblobs>oldtrackblobs)//keep shifting to the left as long as the number of trackblobs is increasing
	{	
		mav(0,30);
		sleep(.3);
		off(0);
		oldtrackblobs=newtrackblobs;
	}
	else if(newtrackblobs<oldtrackblobs)//if the track blobs decrease, move back to the previous position and break loop
	{
		mav(0,-30);
		sleep(.3);
		off(0);
		break;
	}
}
}
	
int main()
{
	
	create_connect();
	go(500,100);//go forward at 100 speed
	spinl(40,100);//spin left 40 degrees at 100 speed
	go(550,100);//go forward at 100 speed
	spinl(40,100);// spin left at 40 degrees at 100 speed
	backup(300,100);//back up to containers 
	create_stop();
	catcher(2000);//lower the catcher cage on containers
	sleep(1.0);
	go(200,50);//move the containers away from the divider between them
	spinl(80,100);//spin to face poms
	go (500,100);//move toward the poms
	findpoms();//move arm to find the pile of poms
	create_stop();
}


 
