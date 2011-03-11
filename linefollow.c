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
	int threshold=500; // set threshold for light conditions
	int high=600,low=200; // set wheel speeds for arc radius
	printf("position robot on tape\nthen press B button\n");
	while(a_button()==0) {} // wait for button press
		while(b_button()==0)
		{ // stop if button is pressed
			if (analog10(1) > threshold) { // continue until not dark
				mav(0,low); mav(3,high); // arc left
			} // or button pressed
			else if (analog10(1) <= threshold){ // continue until dark
				mav(0,high); mav(3,low); // arc right
			} 

}
// or button pressed
ao();
}

/*Function definitions go below.*/
