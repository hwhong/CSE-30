/*
 * Filename: displayLights.s
 * Author: Hwa Chien Hong
 * Userid cs30xnp
 * Description: displays the lights based om what bits are set in the lightBank
 * array
 * Date: 1/20/17
 * Sources of Help: tutor, website links on course website
 */

 	.global displayLights	! Declares the symbol to be globally visible so
				! we can call this function from other modules
	.section ".data" 
fmt:
	.section ".text"

OFFSET = 4
SPACE_COUNT = 0
COUNTER = 0 
RIGHT = 31
LEFT = 0
SPACE_TERMINATE = 4 
STOP_CONDITION = 32 

SPACE = ' '
ON = '*' 
OFF = '-'
NEXT_LINE = '\n' 

/*
 * Function name: displayLights( unsigned int lightBank[] )
 * Function prototype: void displayLights( unsigned int lightBank[] )
 * Description: displays the lights based om what bits are set in the lightBank
 * Parameters:
 * 	arg 1: unsigned int lightBank[] lightBank to displayLights
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: None
 *
 * Registers Used:
 * 	%i0 - arg1, lightBank 
 * 
 *	%l0 - lightBank[0]
 *	%l1 - lightBank[1]
 *  	%l2 - space_count
 *	%l3 - R (Number of right shifts)
 *	%l4 - L (Number of left shifts)
 *	%l5 - temp storer 
 *	%l6 - counter 
 *
 *	%o0 - input to printChar 
 */

 displayLights: 
	save	%sp, -96, %sp	! Save caller's window; if different than -9

	ld	[%i0], %l0	! Gets the first halve of the lightBank 
	ld	[%i0 + OFFSET], %l1	! Gets the second halve of the lightBank 

	mov 	SPACE_COUNT, %l2! SPACE_COUNT is 4 

	mov	LEFT, %l4 	! initialize LEFT of 0   <------- 
	mov	RIGHT, %l3	! initialize RIGHT of 31 ------->

	mov	%l0, %l5	! temp stored, to manipulate 
	mov	COUNTER, %l6	! initialize COUNTER of 0 

printing: 
	cmp	%l2, SPACE_TERMINATE 
	be	print_space 
	nop 

repeat: 
	mov	%l0, %l5 
	sll	%l5, %l4, %l5	! shift temp stored left by LEFT
	srl 	%l5, %l3, %l5	! shift temp stored right by RIGHT,to clear bits

	cmp	%l5, 0 
	ble	print_off
	nop 


	ba 	print_on
	nop 


print_space: 
	clr	%l2 		! clear the space counter 
	
	mov	SPACE, %o0	! moves space to output 
	call 	printChar
	nop

	ba	printing	
	nop

print_off:
	mov 	OFF, %o0	! move OFF to output regsiter 
	call	printChar
	nop 
	
	inc	%l6		! increase counter 
	inc	%l4		! increase shifts to left by 1 
	inc	%l2		! increase space_count

	cmp	%l6, STOP_CONDITION
	bl	printing 
	nop 

	ba 	second_bank
	nop

print_on: 
	mov 	ON, %o0	! move OFF to output regsiter 
	call	printChar
	nop 
	
	inc	%l6		! increase counter 
	inc	%l4		! increase shifts to left by 1 
	inc	%l2		! increase space_count

	cmp	%l6, STOP_CONDITION
	bl	printing 
	nop 

	ba 	second_bank
	nop
!----------------------------Print the Second Bank----------- -------------
second_bank: 
	mov	SPACE, %o0
	call	printChar 
	nop

	mov 	SPACE_COUNT, %l2! SPACE_COUNT is 0

	mov	LEFT, %l4 	! initialize LEFT of 0   <------- 
	mov	RIGHT, %l3	! initialize RIGHT of 31 ------->

	mov	%l1, %l5	! temp stored, to manipulate 
	mov	COUNTER, %l6	! initialize COUNTER of 0 

printing1: 
	cmp	%l2, SPACE_TERMINATE 
	be	print_space1 
	nop 

repeat1: 
	mov	%l1, %l5 
	sll	%l5, %l4, %l5	! shift temp stored left by LEFT
	srl 	%l5, %l3, %l5	! shift temp stored right by RIGHT,to clear bits

	cmp	%l5, 0 
	ble	print_off1
	nop 


	ba 	print_on1
	nop 


print_space1: 
	clr	%l2 		! clear the space counter 
	
	mov	SPACE, %o0	! moves space to output 
	call 	printChar
	nop

	ba	printing1	
	nop

print_off1:
	mov 	OFF, %o0	! move OFF to output regsiter 
	call	printChar
	nop 
	
	inc	%l6		! increase counter 
	inc	%l4		! increase shifts to left by 1 
	inc	%l2		! increase space_count

	cmp	%l6, STOP_CONDITION
	bl	printing1 
	nop 

	ba 	end
	nop

print_on1: 
	mov 	ON, %o0	! move OFF to output regsiter 
	call	printChar
	nop 
	
	inc	%l6		! increase counter 
	inc	%l4		! increase shifts to left by 1 
	inc	%l2		! increase space_count

	cmp	%l6, STOP_CONDITION
	bl	printing1 
	nop 

	ba	end 
	nop 

end:
	mov	SPACE, %o0
	call	printChar 
	nop 

	mov	NEXT_LINE, %o0
	call	printChar 
	nop 

	ret 
	restore 









