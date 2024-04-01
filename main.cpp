#include "Cube.h"

/*
*  Every side's index starts at top left as (0,0)
*
*              --------
*              | Back |
*              |      |
*              --------
*              |  Up  |
*              |      |
*      ------------------------
*      | Left  | Front| Right |
*      |       |      |       |
*      ------------------------
*              | Down |
*              |      |
*              --------
*
*
*/

int main()
{
	std::string moves = "";
		Cube c("yrbogbrgo",
			   /*  
			       -> Back face color scheme

			       yellow (0,0) | red   (0,1) | blue   (0,2)
			       orange (1,0) | green (1,1) | blue   (1,2)
			       red    (2,0) | green (2,1) | orange (2,2)
			   */


			   "yryoobwbb",   // -> UP 
			   "ggrwwgryr",   // -> Left
			   "bwowbggyg",   // -> Front
			   "wrgyyooyy",   // -> Right
			   "wowrrbbwo");  // -> Down

	c.print();
	if (!c.check())
		return -1;
	moves = c.solve();
	std::cout << std::endl;
	std::cout << std::endl;
	c.print();

	std::cout << std::endl << std::endl <<  "Moves Made : " << moves << std::endl << std::endl;
	return 0;
}