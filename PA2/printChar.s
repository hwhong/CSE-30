/*
 * Filename: printChar.s
 * Author: Hwa Chien Hong
 * Userid cs30xnp
 * Description: Example SPARC assembly routine to print the character
 *		argumnet to stdout. 
 *	        Called from main()
 * Date: 1/27/17
 * Sources of Help: tutor, website links on course website
 */

 	.global printChar	! Declares the symbol to be globally visible so
				! we can call this function from other modules
	.section ".data" 
fmt:
	.asciz "%c"

	.section ".text"

/*
 * Function name: printChar( long val )
 * Function prototype: long printChar( long val );
 * Description: prints the character argyment to stdout 
 * Parameters:
 * 	arg 1: long num -- the character to be printed 
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: None
 * -------------- Check nop -------------- 
 * Registers Used:
 *
 */

printChar: 
	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value was calculated.
	
	set	fmt, %o0	! Format String
	mov	%i0, %o1	! Copy of formal parameter to print 
	call	printf		! Make the function call 
	nop 
	
	ret			! Return from subroutine 
	restore			! Restore caller's windwow; in "ret" delay slot 


