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
wait_for_light(3) //light sensor in analog port 3
	while (analog(3)<800)
	{
		printf("It's working!!!/n");
	}
	printf("I see the light!/n");
}
