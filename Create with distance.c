/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/
int look_for_color_green() { 
  int x, y, color=2;  // set up for color channel 2 (green)
  while (black_button() == 0) //run till button is pressed
    { 
      track_update(); // process the most recent image
      if (track_count(color) > 0)
        { // get  x, y for the biggest blob the channel sees
           x = track_x(color,2); y = track_y(color,2); 
	        printf("Biggest blob at (%d,%d)\n",x,y); 
        }
	   else
        { printf("No color match in Frame\n"); }
      sleep(0.2);  // give print time to register
    }
    printf("Program is done.\n");
}

int resetd()
{
	set_create_distance(0);
}

int reseta()
{
	set_create_total_angle(0);
}

int drive(x)
{
	create_drive_straight(x);
}

int go(y,x) //I don't quite get this part... seems like some braces missing
{ 
	if (y>0)
	{while (get_create_distance(5) < y)
		{drive(x);}
	}
	if (y<0)
	{while (get_create_distance(5) > y)
		{drive(-x);}
	}
}

int turnl(x)
{
	create_spin_CCW(x);
}

int turnr(x)
{
	create_spin_CW(x);
}

int pick_up_green()
{
	look_for_color_green();
}


int main()
{
	create_connect();
	go(457.2,250);
	resetd();
	while (get_create_total_angle(10) < 90)
		{turnl(250);}
	reseta();
	go(457.2,250);
	resetd();
	while (get_create_total_angle(10) > -90)
		{turnr(250);}
	reseta();
	go(250,250);
	while (get_create_total_angle(10) > -90)//Riddhi..your job is to write a 
		//function like mine, go, that makes an easy command to turn the robot.
		{turnr(250);}
	reseta();
	go(400,250);
	resetd();
	motor(3,50);
	sleep(1.5);//this is to lower the cage thing for the green 
		//and pink containers. might have to go forward or backward.
	go(-400,250);//to go backwards
	resetd();
	while (get_create_total_angle(10) < 90)
		{turnl(250);}
	reseta();
	go(-457.2,250);
	resetd();
	//need help with steps 13-21 on the pseudocode.
	while (analog(2) < 100)
		{create_drive_straight(250);} //to raise the cage, and leave the filled containers of luggage.
	motor(3,50);
	sleep(1.5);
	enable_servos();
	get_servo_position(2);
	if (get_servo_position(2) > 1023)
		{set_servo_position(2,get_servo_position(2)-1023);}
	if (get_servo_position(2) < 1023)
		{set_servo_position(2,get_servo_position(2)+1023);}
	

}

/*Function definitions go below.*/
