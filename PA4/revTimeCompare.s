/*
 * Filename: revTimeCompare.s
 * Author: Hwa Chien Hong
 * Userid cs30xnp
 * Description: sort based on the modification time (newest first) of the two
 * struct fileInfo
 * Date: 2/17/17
 * Sources of Help: tutor, website links on course website
 */

 	.global revTimeCompare	! Declares the symbol to be globally visible so
				! we can call this function from other modules

/*
 * Function name: revTimeCompare( void const * p1, void const * p2 )
 * Function prototype: int revTimeCompare( void const * p1, void const * p2 )
 * Description: sort based on modification time of structs
 * Parameters:
 * 	arg 1: the first pointer to struct
 *	arg 2: the second pointer to struct
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: -1 if first mod time is newer
 *               0  mod times are the same
 *		 +1 if first mod time is older
 *
 * Registers Used:
 * 	%o0 - arg 1 -- the first pointer 
 *	%o1 - arg 2 -- the second pointer
 */
 
revTimeCompare:
	set	mtimeOffset, %o2		! grabs the offset val
	ld	[%o2], %o2			! load the actual offset val

	add	%o0, %o2, %o0
	add	%o1, %o2, %o1	
	
	ld	[%o0], %o0			! load the strings to compare
	ld	[%o1], %o1
						!depending on result return 0,
						!1, -2
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
	mov	-1, %o0
	retl
	nop 

	! Since first time is older, -1 returned
neg_return:
	mov	1, %o0
	retl
	nop

