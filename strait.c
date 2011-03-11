int touch_sensor()
{
	while (digital(8)==0 && digital(15)==0)
	{	create_drive_direct(-250,-250);}
	create_stop();
	
}
	
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

int sort_color()
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
}

int main() 
{
	printf("Drive Straight");
sleep(1.0); 
create_connect();
while (get_create_distance(0.1) < 480) 
{
	create_drive_direct(250,250); 
} 
create_stop();

while (get_create_total_angle(0.1) < 45)
{
create_drive_direct (100,-100);
}
create_stop();	
while (get_create_distance(0.1) < 1220) 
{
	create_drive_direct(250,250); 
} 
create_stop();
while (get_create_total_angle(0.1) < 85)
{
create_drive_direct (100,-100);
}
create_stop();
touch_sensor();
motor(2,50);
sleep(2);
ao();
while (get_create_distance(.1) < 1500)
{
	create_drive_direct(250,250);
}
while (get_create_total_angle(.1) < 160)
{
	create_drive_direct(100,-100);
}
while (get_create_distance(.1) < 1800)
{
	create_drive_direct(250,250);
}
findpoms();
enable_servos();
sort_color();
create_stop();
}

