/*
 * Filename: getTableIndex.s
 * Author: Hwa Chien Hong
 * Userid cs30xnp
 * Description: calculate the inedx of the ucSorted in the hashTable of size
 *              tableSize 
 * Date: 2/17/17
 * Sources of Help: tutor, website links on course website
 */

 	.global getTableIndex	! Declares the symbol to be globally visible so
				! we can call this function from other modules

/*
 * Function name: getTableIndex( char const * ucSroted, size_t tableSize )
 * Function prototype: int getTableIndex( char const * ucSorted, sizr_t
 * 									tableSize)
 * Description: this function calculated the idnex of the ucSorted string in the
 *              hashTable of size hashTable
 * Parameters:
 * 	arg 1: the pointer to the first char of the string
 *	arg 2: the hashtable size
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: the index of ucSorted in the hashtable
 *
 * Registers Used:
 * 	%i0 - getTableIndex key of the str
 *	%i1 - the hashtable size
 */
 
getTableIndex:
  	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value is calculated	

	mov	%i0, %o0	! move str to output register to calculate hsah
	call	hash		
	nop

	mov	%o0, %o0	! hashkey in %o0 currently 
	mov	%i1, %o1	! move tablesize to %o1
	call	.rem		! Mod the two
	nop 

	cmp	%o0, %g0
	bl	invert_sign	! change to positive branch logic 
	nop 

	ba	return		! don't need to invert, simply return
	nop	

invert_sign: 
	mov 	%o0, %o0	
	mov	-1, %o1		! multiply the negative number by negative 
	call	.mul
	nop

return:
	mov	%o0, %i0	! move final result to return register

	ret
	restore





