/*
 * Filename: isInBounds.s
 * Author: Hwa Chien Hong
 * Userid cs30xnp
 * Description: Example SPARC assembly routine to check if num is within min
 *		and min + dist, inclusive on both ends.
 *	        Called from main()
 * Date: 1/20/17
 * Sources of Help: 
 */

 	.global isInBounds	! Declares the symbol to be globally visible so
				! we can call this function from other modules
	.section ".text"	! the text segment begins here

/*
 * Function name: isInBounds( long min, long dist, long num )
 * Function prototype: long isInBounds( long min, long dist, long num );
 * Description: Determines if num is within min and min + dist, inclusive 
 *		on both ends.
 * Parameters:
 * 	arg 1: long min -- the minimum bound to the interval 
 *	arg 2: long dist -- the distance from min that is still in bound
 *	arg 3: long num -- the number to check if is in bound 
 *
 * Side Effects: None.
 * Error Conditions: dist is negative, return -1 
 *		     overflow occurs in computing min + dist, return -1
 * Return Value: any error occurs, return -1 
 *               return 1 to represent true 
 *		 return 0 to represent false
 *
 * Registers Used:
 * 	%i0 - arg 1 -- min bound to interval 
 *	%i1 - arg 2 -- dist which i can add min to
 *	%i2 - arg 3 -- the num to be checked 
 *	%l0 : arg 1 copied 
 * 	%l1 : arg 2 copied
 *	%l2 : arg 3 copied
 *
 *	%l3 : the output value
 *	%l4 : the overflow value for second condition
 * 	%l5 : min + dist value 
 *	
 *	%g0 : the zero value which represents false
 */

isInBounds: 
	save	%sp, -96, %sp	! Save Caller's window; if different than -96
				! then comment on how that value was calculated 
	
	mov	%i1, %l1	! stores the value of dist in register %l0
	cmp	%l1, %g0	! compares min to 0, see if it is negative 
	bl	error		! if its less than 0, branch to error
	nop 
	
	mov	%i0, %l0	! stores the min to %l0
	mov	%i2, %l2	! stores the num to be checked to %l2

	addcc	%l0, %l1, %l4	! checks if there is overflow in addition 
	bvs	error		! branch to part where -1 is returned
	nop
				
				!--------checked the error conditions
				

	add	%l0, %l1, %l5 	! stores the value of min+dist in %l5

	cmp	%l0, %l2	! compares the min and number, if min > number
 	bg	badbound	! branches to the not in bound 
	nop

	cmp	%l2, %l5	! compares the upperto number, if num > up
	bg 	badbound	! branches to the not in bound
	nop

				!--------checked if number is in bound

				! if moved to this point then means, 
				! the num is in bound
	mov	1, %i0 		! move 1 (value we want to return) to %i0
	
	ba return
	nop

error: 
	mov	-1, %i0		! outputs the error value of -1 
	
	ba 	return
	nop

badbound:
	mov	%g0,%i0		! outputs the false value of %i0
	
	ba	return
	nop


return:
	ret
	restore



























