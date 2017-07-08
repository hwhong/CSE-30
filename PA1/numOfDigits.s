/*
 * Filename: numOfDigits.s
 * Author: Hwa Chien Hong
 * Userid cs30xnp
 * Description: Example SPARC assembly routine to count the number
 *		of digits in num. return -1 if negative 
 *	        Called from main()
 * Date: 1/20/17
 * Sources of Help: Tutor, website links on the course website
 */
	
 	.global numOfDigits	! Declares the symbol to be globally visible so
				! we can call this function from other modules

	.section ".text"	! The text segment begins here
TEN = 10			! The number to divide num with
COMP = 9			! The stardard for single digit

/*
 * Function name: numOfDigits( long num )
 * Function prototype: long numOfDigits( long num );
 * Description: Counts the number of digits in num
 * Parameters:
 * 	arg 1: long num -- number to count the digits
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: the number of digits in num
 *               or -1 if number is negative
 *
 * Registers Used:
 * 	%i0 : arg1 -- the number which the digits will be counted, also 
 *		      the return value of count
 *	%l0 : copied number from i0
 *	
 *	%o0 : the number to be divided 
 *	%o1 : 2, the number to divide 
 */

numOfDigits: 			! Idea: divide by 10, until output equals to 0
	save	%sp, -96, %sp	! Save caller's window; if different than -96

	mov	%i0, %l0	! put a copy of parameter in the register 

	cmp	%l0,%g0		! compares number to zero, if less than 0, its 
				! negative, which returns -1
	bl	error		! strictly less than
	nop

	cmp	%l0, COMP	! compares num to nine
	ble	end_loop	! branch, only single digit, less than/equal to
	nop

	mov	%l0, %o0	! moves the number to %o0 to go into loop
	
	clr	%i0		! clear the register %i0 before going into loop

	ba 	loop		! Branch to the loop, since is not less than 9
	nop

loop:
	inc	%i0		! increment count 
	mov	%o0, %o0	! move the number to still be divided to %o0
	mov	TEN, %o1		! move 2 to %o1
	call	.div
	nop
				! -----DIVISION INSTRUCTION ABOVE------
				
	cmp	%o0, %g0
	bne 	loop		! if it is not equal to 0, loop again 
	nop
				
				!-----OUTSIDE OF THE LOOP-----
			

	mov	%i0, %i0	! move return value to itself
	
	ba	return
	nop

error: 
	mov	-1, %i0		! move -1 to output register 

	ba	return
	nop
	
end_loop:
	
	mov	1, %i0		! only single digit
	
	ba	return
	nop

return:
	ret
	restore
