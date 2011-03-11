int main()

{
	int x = 0;
	enable_servos();
	sleep(2);
	set_servo_position(0,0);
	set_servo_position(2, 2047);
	sleep(2);
	
	while (get_servo_position(0) < 2047)
	{
	set_servo_position(0,x);
	set_servo_position(2,2000-x);
	x= x+100;
	
	printf("Servo Position is %d\n", get_servo_position(2));
	sleep (.5);
	}
		disable_servos();

}
	
