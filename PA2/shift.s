/*
 * Filename: shift.s
 * Author: Hwa Chien Hong
 * Userid cs30xnp
 * Description: shifts the current light patterns in the light banks by shiftCnt
 *              places
 * Date: 2/3/17
 * Sources of Help: tutor, website links on course website
 */

 	.global shift	! Declares the symbol to be globally visible so
			! we can call this function from other modules

	.section ".text" 
THIRTY_ONE = 31
LARGE_MASK = 0x80000000
OFFSET = 4
LOWER_SIX  = 0x3F
/*
 * Function name: shift( unsigned int lightbank[], const int shiftCnt )
 * Function prototype: void shift( unsigned int lightbank[], const int shiftCnt  );
 * Description: shifts the current light patterns in the light banks by shiftCnt
 *              places 
 * Parameters:
 * 	arg 1: unsigned int lightBank[] lightBank to shift
 *      arg 2: const int shiftCnt, the amount to shift 
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: None
 *
 * Registers Used:
 * 	%i0 - arg1, lightBank 
 *      %i1 - arg2, shiftCnt
 *
 *	%l0 - lightBank 1 local register 
 *	%l1 - lightBank 2 local register 
 *	%l2 - the mask 
 *	%l3 - the temp list to AND 
 *	%l4 - the decrement count of shiftCnt
 *	%l5 - mask for shift right 
 */

shift: 
 	save	%sp, -96, %sp	! Save caller's window; if different than -9

	ld	[%i0], %l0	! Gets the first halve of the lightBank 
	ld	[%i0 + OFFSET], %l1	! Gets the second halve of the lightBank \

	set	LARGE_MASK, %l2	! the mask has binary value 1...000000
				
				! if negative, convert to pos before extraction
	cmp	%i1, 0
	bl	convert_to_pos
	nop
	
				! move count to local var, if positive
	mov	%i1, %l4

back:
				! mask with 0x3F
	and	%l4, LOWER_SIX, %l4

	mov 	1, %l5		! moves 1 to the mask 

	cmp	%i1, 0		! comparing shiftCnt to 0 
	bl	shift_right_neg	! since negative shifts right 
	nop 
	
				! backward logic, if 0 return 
	be	return 
	nop 

	ba	shift_left_pos	! since positive shifts left 
	nop

convert_to_pos: 
	mov	%i1, %o0
	mov	-1,  %o1
	call 	.mul
	nop 

	mov	%o0, %l4

	cmp	%l4, 0
	bg	back
	nop

	ba	return
	nop

shift_right_neg: 
	clr	%l3

	and 	%l0, %l5, %l3	! masks 1 with bank1, then store in l3

	srl	%l0, 1, %l0	! shift bank1 to the right by 1 

	sll	%l3, THIRTY_ONE, %l3	! shifts templist by 31 to the left 

	srl 	%l1, 1, %l1 	! shifts bank2 to the right by 1

	or 	%l1, %l3, %l1	! OR bank2 with the mask 

	srl	%l3, THIRTY_ONE, %l3
	
	dec	%l4		! decrement count, until reaches 0 
	
	cmp	%l4, 0
	bg	shift_right_neg
	nop 

	ba	return
	nop

shift_left_pos:
				! 1010 1010 
				!      1000 %l2, the mask 
				!      1000 %l2, the temp list
				!      temp list shift become 1  
				! 0100 
				!    1
				! 0101    <-- result 
	clr	%l3

	and	%l1, %l2, %l3	! AND bank2 with 1...000, and stored in l3 

	sll	%l0, 1, %l0	! shifts bank 1 bits left by 1 
	srl	%l3, THIRTY_ONE, %l3	! shifts the temp list, until one bit left 
	
	or	%l0, %l3, %l0	! OR the bank 1 with temp list 

	dec	%l4		! decrement the count 

	sll	%l1, 1, %l1	! shifts second bank left by 1

	sll	%l3, THIRTY_ONE, %l3

	cmp	%l4, 0		! compares count again with 0 
	bg	shift_left_pos
	nop

return:
	st	%l0, [%i0]
	st	%l1, [%i0 + OFFSET]

	ret 
	restore 

