/*
 * Filename: timeCompare.s
 * Author: Hwa Chien Hong
 * Userid cs30xnp
 * Description: sort based on the modification times of two struct fileInfo
 * Date: 3/7/17
 * Sources of Help: tutor, website links on course website
 */

 	.global timeCompare	! Declares the symbol to be globally visible so
				! we can call this function from other modules

/*
 * Function name: timeCompare( void const * p1, void const * p2 )
 * Function prototype: int timeCompare( void const * p1, void const * p2 )
 * Description: sort based on modification time of structs
 * Parameters:
 * 	arg 1: the first pointer to struct
 *	arg 2: the second pointer to struct
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: -1 if first mod time is older
 *               0  mod times are the same
 *		 +1 if first is newer, second mod time is older
 *
 * Registers Used:
 * 	%o0 - arg 1 -- the first pointer 
 *	%o1 - arg 2 -- the second pointer
 */
 
timeCompare:
	set	mtimeOffset, %o2	! grab the offset value
	ld	[%o2], %o2		! actually get the offset val

	add	%o0, %o2, %o0
	add	%o1, %o2, %o1	
	
	ld	[%o0], %o0		! load the two strings
	ld	[%o1], %o1

					! depending on result, return 0, 1, -1
	cmp	%o0, %o1
	be	same_return
	nop

	bg	pos_return
	nop
	
	ba	neg_return
	nop

	! since both are the same, 0 returned
same_return:
	mov	0, %o0
	retl
	nop

pos_return: 
	mov	1, %o0
	retl
	nop 

	! Since first time is older, -1 returned
neg_return:
	mov	-1, %o0
	retl
	nop

