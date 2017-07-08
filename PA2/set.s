/*
 * Filename: set.s
 * Author: Hwa Chien Hong
 * Userid cs30xnp
 * Description: sets the lights in the lightBank based on which bits are set in
 * 		the bit patterns passed in. 
 * Date: 1/20/17
 * Sources of Help: tutor, website links on course website
 */

 	.global set	! Declares the symbol to be globally visible so
			! we can call this function from other modules

	.section ".text" 

MASK_SHIFT = 28 
COUNT = 8
LARGE_MASK = 0x00000000
FOUR = 4
OFFSET = 4

/*
 * Function name: set( unsigned int lightBank[], const unsigned int pattern0,
 * 						 const unsigned int pattern1 )
 * Function prototype: void set( unsigned int lightBank[], 
 *	             const unsigned int pattern0, const unsigned int pattern1)
 * Description: sets the lights in the lightBank based on which bits are set in
 *		the bit patterns passed in.
 * Parameters:
 * 	arg 1: unsigned int lightBank[] lightBank to set
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
 *      %l2 - MASK of 0000000000
 *	%l3 - count of number of operations 
 *	%l4 - number of shifts, starting with 28 
 */

 set: 
	save	%sp, -96, %sp	! Save caller's window; if different than -9

	ld	[%i0], %l0	! Gets the first halve of the lightBank 
	ld	[%i0 + OFFSET], %l1	! Gets the second halve of the lightBank 

	mov	LARGE_MASK, %l2	! A mask for all operations 

	mov	COUNT, %l3	! initialize the count of 8 
	
	mov	MASK_SHIFT, %l4 ! initialize MASK_SHIFT of 28 

	cmp	%l3, 0		! compare if count is already 0 
	be	return  
	nop 

lightBank0_Operation: 
	clr	%l2		! Clears the mask 

	or 	%l2, %i1, %l2	! mask pattern0 with mask

	srl	%l2, %l4, %l2	! shifts mask right by n, to clear unwanted bits 
	sll	%l2, %l4, %l2	! shifts mask back by n, recalim bits 

	or	%l0, %l2, %l0 	! mask with lightBank[0], then store back 

	srl 	%l2, FOUR, %l2	! shifts mask right by 4 

	sub	%l4, FOUR, %l4	! subtract number of shifts available by 4 

	dec	%l3		! subtract number of operations by 1 
	
	cmp	%l3, 0		! check if we needed to exit 
	bg	lightBank0_Operation 
	nop 
				!--------------- RESESTS for second bank

					
	mov	LARGE_MASK, %l2	! A mask for all operations 

	mov	COUNT, %l3	! initialize the count of 8 
	
	mov	MASK_SHIFT, %l4 ! initialize MASK_SHIFT of 28 

lightBank1_Operation: 
       	clr	%l2		! Clears the mask 

	or 	%l2, %i2, %l2	! mask pattern0 with mask

	srl	%l2, %l4, %l2	! shifts mask right by n, to clear unwanted bits 
	sll	%l2, %l4, %l2	! shifts mask back by n, recalim bits 

	or	%l1, %l2, %l1 	! mask with lightBank[1], then store back 

	srl 	%l2, FOUR, %l2	! shifts mask right by 4 

	sub	%l4, FOUR, %l4	! subtract number of shifts available by 4 

	dec	%l3		! subtract number of operations by 1 
	
	cmp	%l3, 0		! check if we needed to exit 
	bg	lightBank1_Operation 
	nop 
	
	ba 	return 		! return 
	nop 

return:
	st	%l0, [%i0]
	st	%l1, [%i0 + OFFSET]

	ret 
	restore 


























