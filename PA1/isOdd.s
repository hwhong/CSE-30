/*
 * Filename: isOdd.s
 * Author: Hwa Chien Hong
 * Userid cs30xnp
 * Description: Example SPARC assembly routine to check whether 
 *              a given integer is odd or not. 
 *	        Called from main()
 * Date: 1/20/17
 * Sources of Help: tutor, website links on course website
 */

 	.global isOdd	! Declares the symbol to be globally visible so
			! we can call this function from other modules

/*
 * Function name: isOdd( long num )
 * Function prototype: long isOdd( long num );
 * Description: Determines if the provided num is odd or not
 * Parameters:
 * 	arg 1: long num -- number to check is odd or not
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: 1 if num is odd
 *               0 if num is even 
 *
 * Registers Used:
 * 	%o0 - arg 1 -- the number to be checked 
 *	%l0 : the number 1 to AND and check with
 * 	%l1 : stores the result of AND operation 
 *	%i0 : stores the input as well as the output
 * 	%g0 : stores the number 0
 */

 isOdd:
 	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value is calculated 
	
	mov	%i0, %o0	! Put a copy of the parameter in the registers
	mov	1, %l0 

	and	%i0, %l0, %l1 	! bitwise AND num with 1, and result stored
				! in %l1

	cmp	%l1, %l0	! compares the result (either 0 or 1) to 1
	bl	even 		! result is 0, which is an even number, branch
	nop 

	mov	%l1, %i0	! did not branch, meaning result is odd
				! store value 1 in %i0 to return
	ba	return
	nop

even:
	mov	%l1, %i0	! store number 0 to %i0

	ba 	return
	nop

return:
	ret 
	restore


	


				




