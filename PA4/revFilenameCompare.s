/*
 * Filename: revFilenameCompare.s
 * Author: Hwa Chien Hong
 * Userid cs30xnp
 * Description: sort based on the modification times of two struct fileInfo
 * (reversed)
 * Date: 3/7/17
 * Sources of Help: tutor, website links on course website
 */

 	.global revFilenameCompare	! Declares the symbol to be globally visible so
				! we can call this function from other modules
	.section ".text"
	
/*
 * Function name: revFilenameCompare( void const * p1, void const * p2 )
 * Function prototype: int revFilenameCompare( void const * p1, void const * p2 )
 * Description: sort based on filename of structs (reversed)
 * Parameters:
 * 	arg 1: the first pointer to struct
 *	arg 2: the second pointer to struct
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: 1 if first filename is smaller
 *               0  filename are the same
 *		 -1 if first is bigger, second filename is older
 *
 * Registers Used:
 * 	%i0 - arg 1 -- the first pointer 
 *	%i1 - arg 2 -- the second pointer
 *
 *	%l1 - arg1 
 *	%l2 - arg2
 *	%l0 - store the value of offset
 */
 
revFilenameCompare:
	save	%sp, -96, %sp		! Caller's Id

	set	filenameOffset, %l0	! Grab the offset address
	ld	[%l0], %l0		! load the address to actualy val

	add	%i0, %l0, %i0		! find correct offset for both pointers
	add	%i1, %l0, %i1		

	ld	[%i0], %l1		! load the values at the struct
	ld	[%i1], %l2		! load values of the struct
	
	mov	%l1, %o0
	mov	%l2, %o1
	call	strcmp
	nop

	cmp	%o0, %g0
	be	same_return
	nop

	bg	pos_return
	nop
	
	ba	neg_return
	nop

	! since both are the same, 0 returned
same_return:
	mov	0, %i0
	ba	return
	nop

pos_return: 
	mov	-1, %i0
	ba	return
	nop

	! Since first filename is smaller, -1 returned
neg_return:
	mov	1, %i0
	ba	return
	nop

return:
	ret 
	restore
