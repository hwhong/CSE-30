/*
 * Filename: drawZ.s
 * Author: Hwa Chien Hong
 * Userid cs30xnp
 * Description: perform the actual outputting of individual characters, using 
 *		the printChar subroutine, such that the 'Z' character is 
 *		displayed with the user-supplied values 
 *	        Called from main()
 * Date: 1/27/17
 * Sources of Help: tutor, website links on course website
 */

 	.global drawZ		! Declares the symbol to be globally visible so
				! we can call this function from other modules
	.section ".data" 
fmt:
	.section ".text"
NEWLINE = '\n'			! new line

/*
 * Function name: drawZ( long width , long zChar , long borderChar,
 						 , long fillerChar )
 * Function prototype: long drawZ( long width ,
 			long zChar , long borderChar , long fillerChar  );
 * Description: prints the letter Z onto the screen
 * Parameters:
 * 	arg 1: long width -- an odd integer representing the width of Z pattern
 *	arg 2: long zChar -- the character used to draw the Z shape 
 *	arg 3: borderChar -- character used to draw the border 
 *	arg 4: fillerChar -- character used to fill inside drawing 
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: None
 * -------------- Check nop -------------- 
 * Registers Used:
 *			%i0 --> width 
 *			%i1 --> zChar 
 *			%i2 --> borderChar 
 *			%i3 --> fillerChar 
 *
 *			%l0 --> numDigits 
 *			%l1 --> totalWidth
 *
 *			%l2 --> i 
 *			%l3 --> j
 *
 *			%l4 --> temp place to printChar 
 *			%l5 --> while condition sum 
 *			%l6 --> temp to calculate conditions
 *
 *			%o0 --> first parameter to input 
 */

 drawZ: 
 	save	%sp, -96, %sp	! Save Caller's window; if different than -96 
				! then comment on how that was calculated 
	mov 	%i0, %o0
	call	numOfDigits	! calls the numOfDigits subroutine 
	nop 

	mov	%o0, %l0	! moves numDigits to l0 register 

	add	%o0, %i0, %l1	! compute totalWidth -> numDigits + width
	add	%l1, %o0, %l1	! totalWidth -> ^ + numDigits 


	mov	%g0, %l2	! sets i to 0, by moving g0 to the register 
	mov	%g0, %l3	! sets j to 0, by moving g0 to the register 

				!------Start of nested FOR-loop
				!------Print the top border 

	cmp	%l2, %l0	! comparing i > numDigits 
	bge	end_first_for 	! branch out if condition false 
	nop 

start_first_for:
	cmp	%l3, %l1	! comparing j > totalWidth
	bge	end_second_for	! go back to first for loop 
	nop 

start_second_for:
	mov	%i2, %o0	! moves border char to l4 to print 
	call	printChar	! prints the char 
	nop

	inc	%l3 		! increment j 

	cmp	%l3, %l1	! comparing j < totalWidth 
	bl	start_second_for! continue second loop
	nop

end_second_for:
	mov	NEWLINE, %o0	! moves newline to temp regsiter 
	call	printChar	! prints the newLine 
	nop 

	inc	%l2		! increments i(l2) variable  

	mov	%g0, %l3	! reset the value of j to 0 for possible loop

	cmp	%l2, %l0	! comparing i < numDigits
	bl	start_first_for
	nop 

				!-------start WHILE-nested FOR loop
				!-------Print the Z with side borders 
end_first_for: 

	mov	%g0, %l2	! resets the variable i (l2) to zero 
				
				! totalWidth - (numDigits - 1) in two lines 
	sub	%l0, 1, %l5	! condition for while (numDigits --> l0)
	sub	%l1, %l5, %l5	! the summed condition for while 

	cmp	%l2, %l5	! comparing i to condition %l5 
	bge	end_while_loop
	nop

start_while_loop:	
	mov	%g0, %l3	! resets the variable j to 0 

	cmp	%l3, %l1	! compares j to totalWidth
	bge	end_inner_for	
	nop
	
start_inner_for:
	
				!------Side borders---------

	cmp	%l3, %l0	! comparing j to numDigits 
	bl	print_border	
	nop
	
	add	%l0, %i0, %l6	! numDigits + width
	sub	%l6, 1, %l6	! numDigits + width - 1 

	cmp	%l3, %l6
	bg	print_border	
	nop
				
				!------Top of z and bottom of z
	cmp	%l2, %l0	! comparing i to numDigits
	bl	print_zChar
	nop

	cmp	%l2, %i0	! comparing i to width 
	bg	print_zChar
	nop
				! Sideways portion of Z
	mov	%g0, %l6	! clears l6 for revaluation 

	sub	%l0, 1, %l6
	sub	%l3, %l6, %l6	! j - (numDigits - 1)

	mov	%g0,%l4		! reuse char placeholder to condition check

	sub	%i0, %l2, %l4	! width - i

	cmp	%l6, %l4
	bg	and_and_check
	nop
				! else block, if it gets to here 
	ba	print_filler
	nop

end_inner_for:
	mov	NEWLINE, %o0	! print newline in while
	call 	printChar	! prints it 
	nop

	inc	%l2 		! increment l2 or i variable 
	cmp	%l2, %l5 	! i compared to while loop condition
	bl	start_while_loop! re run loop
	nop
	
	ba	end_while_loop	! if condition fails to here
	nop

print_border:
	mov	%i2, %o0	! put border to print 
	call	printChar
	nop 

	ba	for_condition_check
	nop

print_zChar:
	mov	%i1, %o0	! put z to print
	call	printChar
	nop

	ba	for_condition_check
	nop

and_and_check:
	mov	%g0, %l4	! clears l4 to reuse for condition check

	sub	%i0, %l2, %l4
	add	%l4, %l0, %l4
	
	cmp	%l6, %l4
	ble	print_zChar
	nop

	ba	print_filler	! condition fails, goes to else in for 
	nop

print_filler:
	mov	%i3, %o0
	call	printChar
	nop

	ba	for_condition_check
	nop

for_condition_check:
	inc	%l3		! increment j to check for condition

	cmp	%l3, %l1	! if j is less than totalWidth
	bl	start_inner_for
	nop

	ba	end_inner_for
	nop

end_while_loop: 
	mov	%l0, %l2	! move numDigits to i
	
	cmp	%l2, 0		! comparing i to 0
	be	first_backward_for_end
	nop


	mov	%l3, %l1	! moves totalWidth to j

	cmp	%l1, 0		! comapring j to 0
	be	second_backward_for_end
	nop
	
				!-------- Print the bottom border------- 

second_backward_for_start:

	mov	%i2, %o0	! prints the borderChar
	call	printChar
	nop

	dec	%l1
	cmp	%l1, 0
	bne	second_backward_for_start
	nop

second_backward_for_end:
	mov	NEWLINE, %o0
	call	printChar 
	nop

	mov	%l3, %l1	! reset the value of j for possible loop
	
	dec	%l2
	cmp	%l2, 0
	bne	second_backward_for_start
	nop

	ba	first_backward_for_end
	nop
	
first_backward_for_end:
	ret 
	restore





































