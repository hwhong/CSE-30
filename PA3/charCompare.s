/*
 * Filename: charCompare.s
 * Author: Hwa Chien Hong
 * Userid cs30xnp
 * Description: takes two pointers to characters and compares them.
 * Date: 2/17/17
 * Sources of Help: tutor, website links on course website
 */

 	.global charCompare	! Declares the symbol to be globally visible so
				! we can call this function from other modules

/*
 * Function name: charCompare( void const * p1, void const * p2 )
 * Function prototype: int charCompare( void const * p1, void const * p2 )
 * Description: compares two pointer to characters
 * Parameters:
 * 	arg 1: the first pointer to its character 
 *	arg 2: the second pointer to its character
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: -1 if first char is smaller
 *               0  chars are the same 
 *		 +1 if the first char is larger
 *
 * Registers Used:
 * 	%i0 - arg 1 -- the first pointer 
 *	%i1 - arg 2 -- the second pointer
 *
 */
 
charCompare:
	ldub	[%o0], %o0
	ldub	[%o1], %o1

	cmp	%o0, %o1
	be	same_return
	nop

	bg	pos_return
	nop
	
	ba	neg_return
	nop

	! since both char are the same, 0 returned
same_return:
	mov	0, %o0
	retl
	nop

	! Since second char is bigger, 1 returned 
pos_return: 
	mov	1, %o0
	retl
	nop 

	! Since first char is smaller, -1 returned
neg_return:
	mov	-1, %o0
	retl
	nop
	
