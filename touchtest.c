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
	while(b_button() == 0 )
	{
		if(a_button() == 1)
		{
		printf("%i",digital(11));
		}
	}
	printf("\nDone!");
}

/*Function definitions go below.*/
