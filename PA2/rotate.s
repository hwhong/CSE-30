/*
 * Filename: rotate.s
 * Author: Hwa Chien Hong
 * Userid cs30xnp
 * Description: rotates the current light patterns in the light banks by
 * rotateCnt places. If positive, rotate left, else rotate right. 
 * Date: 1/20/17
 * Sources of Help: tutor, website links on course website
 */

 	.global rotate	! Declares the symbol to be globally visible so
			! we can call this function from other modules

	.section ".text" 

OFFSET = 4
LARGE_MASK = 0x00000000
MASK_SHIFT = 31

/*
 * Function name: rotate( unsigned int lightBank[], const int rotateCnt )
 * Function prototype: void rotate( unsigned int lightBank[], const int rotateCnt );
 * Description: rotates the current light patterns in the light banks by
 * rotateCnt places. Positive --> rotate left, Negative --> rotate right
 *		
 * Parameters:
 * 	arg 1: unsigned int lightBank[] lightBank to rotate
 *      arg 2: const int rotateCnt 
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: None
 *
 * Registers Used:
 * 	%i0 - arg1, lightBank 
 *      %i1 - arg2, the rotateCnt 
 *	
 *	%l0 - lightBank[0]
 *	%l1 - lightBank[1]
 *     
 *	%l2 - mask for bank 1 --> always be 0x00000000 
 * 	%l3 - mask for bank 2 --> always be 0x00000000 
 *
 *	%l4 - the rotateCnt holder var 
 */

 rotate: 
	save	%sp, -96, %sp	! Save caller's window; if different than -9

	ld	[%i0], %l0	! Gets the first halve of the lightBank 
	ld	[%i0 + OFFSET], %l1! Gets the second half of the lightBank 

	mov	%i1, %l4	! moves rotateCnt to a holder register 

	mov	LARGE_MASK, %l2 ! creates mask 1 
	mov 	LARGE_MASK, %l3 ! creates mask 2

	cmp	%i1, 0		! checks whether to shift right or left 
	be	return_condition! since 0, just return 
	nop

	bl	shift_right_neg ! since negative, shift right  
	nop 

	ba	shift_left_pos  ! since positive, shift left 
	nop

shift_left_pos: 
	or	%l2, %l0, %l2	! mask mask 1 with bank 1, to get clone 
	or	%l3, %l1, %l3   ! mask mask 2 with bank 2, to get clone 

				! ------ clears banks MSB by 1

	sll	%l0, 1, %l0	! shifts bank 1 left by 1, clear MSB
	sll	%l1, 1, %l1	! shifts bank 2 left by 1, clear MSB

				! ------ shift mask to only get 1 bit 

	srl	%l2, MASK_SHIFT, %l2 ! shifts mask right by 31, to get MSB
	srl	%l3, MASK_SHIFT, %l3 ! shifts mask right by 31, to get MSB 

				! ------ mask correct rotated bit to bank 

	or	%l0, %l3, %l0	! or bank 1 with mask 1 
	or	%l1, %l2, %l1	! or bank 2 with mask 2 
	
				! ------ Restore old Mask condition 

	sll	%l2, MASK_SHIFT, %l2 ! shifts mask back to org position 
	sll	%l3, MASK_SHIFT, %l3 ! shifts mask back to org position 
	
	clr	%l2 
	clr 	%l3	

	dec	%l4		! decrement count until it gets to zero 
	
	cmp	%l4, 0
	bg	shift_left_pos
	nop
				! if comes down to here, means done with rotate 
	ba	return_condition
	nop

shift_right_neg: 
	or	%l2, %l0, %l2	! mask mask 1 with bank 1, to get clone 
	or	%l3, %l1, %l3   ! mask mask 2 with bank 2, to get clone 

				! ------ clears banks MSB by 1

	srl	%l0, 1, %l0	! shifts bank 1 right by 1, clear MSB
	srl	%l1, 1, %l1	! shifts bank 2 right by 1, clear MSB

				! ------ shift mask to only get 1 bit 

	sll	%l2, MASK_SHIFT, %l2 ! shifts mask left by 31, to get LSB
	sll	%l3, MASK_SHIFT, %l3 ! shifts mask left by 31, to get LSB

				! ------ mask correct rotated bit to bank 

	or	%l0, %l3, %l0	! or bank 1 with mask 1 
	or	%l1, %l2, %l1	! or bank 2 with mask 2 
	
				! ------ Restore old Mask condition 

	srl	%l2, MASK_SHIFT, %l2 ! shifts mask back to org position 
	srl	%l3, MASK_SHIFT, %l3 ! shifts mask back to org position 
	
	clr	%l2 
	clr 	%l3	

	inc	%l4		! decrement count until it gets to zero 
	
	cmp	%l4, 0
	bl	shift_right_neg
	nop
				! if comes down to here, means done with rotate 
	ba	return_condition
	nop

return_condition: 
 	 st	%l0, [%i0]
	st	%l1, [%i0 + OFFSET]

	ret 
	restore 
























