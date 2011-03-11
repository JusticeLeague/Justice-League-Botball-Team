void gostraight(int power,float (time))
{
	motor(0,power);
	motor(3,power);
	sleep(time);
}
void turnleft(int power, float (time))
{
	motor(0, -power);
	motor(3, power);
	sleep(time);
}
void turnright(int power, float (time))
{
	motor(0, power);
	motor(3, -power);
	sleep(time);
}
void goback(int power,float (time))
{
	motor(0,-power);
	motor(3,-power);
	sleep(time);
}
void pausemotor(float (time))
{
	ao();
	sleep(time);
}
void turnrightdegrees(float (degrees))
{
	int x;
	for(x = 0; x <= degrees; x++)
	{
		motor(100, 0.01);
		sleep(0.1);
	}
}
int main ()
{
	//gostraight/turnleft/turnright/goback/(power, time)
	


}

