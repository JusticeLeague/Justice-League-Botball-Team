int main()
{
wait_for_light(3); //light sensor in analog port 3
	printf("I see the light!\n");
	sleep(5);
	printf("Drive Straight");
	sleep(1.0); 
	create_connect();
while (get_create_distance(0.1) < 460) 
{
	create_drive_direct(250,250); 
} 
create_stop();

while (get_create_total_angle(0.1) < 45)
{
create_drive_direct (100,-100);
}
create_stop();	
while (get_create_distance(0.1) < 1200) 
{
	create_drive_direct(250,250); 
} 
create_stop();
while (get_create_total_angle(0.1) < 85)
{
create_drive_direct (100,-100);
}
create_stop();
while (get_create_distance(0.1) >850) 
{
	create_drive_direct(-250,-250); 
} 
}
