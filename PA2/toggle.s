/*
 * Filename: toggle.s
 * Author: Hwa Chien Hong
 * Userid cs30xnp
 * Description: toggles the lights in the lightBank based on which bits are toggle in
 * 		the bit patterns passed in. 
 * Date: 2/10/17
 * Sources of Help: tutor, website links on course website
 */

 	.global toggle	! Declares the symbol to be globally visible so
			! we can call this function from other modules

	.section ".text" 

MASK_SHIFT = 28 
COUNT = 8
LARGE_MASK = 0x00000000
FOUR = 4
OFFSET = 4

/*
 * Function name: toggle( unsigned int lightBank[], const unsigned int pattern0,
 * 						 const unsigned int pattern1 )
 * Function prototype: void toggle( unsigned int lightBank[], 
 *	             const unsigned int pattern0, const unsigned int pattern1)
 * Description: toggles the lights in the lightBank based on which bits are toggle in
 *		the bit patterns passed in.
 * Parameters:
 * 	arg 1: unsigned int lightBank[] lightBank to toggle
 *      arg 2: const unsgined in pattern0
 *	arg 3: const unsigned in pattern1
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: None
 *
 * Registers Used:
 * 	%i0 - arg1, lightBank 
 *      %i1 - arg2, pattern0
 *	%i2 - arg3, pattern1
 * 
 *	%l0 - lightBank[0]
 *	%l1 - lightBank[1]
 *  
 */

 toggle: 
	save	%sp, -96, %sp	! Save caller's window; if different than -9

	ld	[%i0], %l0	! Gets the first halve of the lightBank 
	ld	[%i0 + OFFSET], %l1	! Gets the second halve of the lightBank 

	xor	%l0, %i1, %l0	
	xor	%l1, %i2, %l1	
	
	ba 	return
	nop
return:
	st	%l0, [%i0]
	st	%l1, [%i0 + OFFSET]

	ret 
	restore 


















