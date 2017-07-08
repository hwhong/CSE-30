/*
 * Filename: hash.s
 * Author: Hwa Chien Hong
 * Userid cs30xnp
 * Description: creates the hash key of an anagram. 
 * Date: 2/17/17
 * Sources of Help: tutor, website links on course website
 */

 	.global hash	! Declares the symbol to be globally visible so
			! we can call this function from other modules

/*
 * Function name: hash( char const * str )
 * Function prototype: int hash( char const * str )
 * Description: this function creates the hash key of the anagram. Creates it by
 *              using an algorithm similar to Java's String.hashCode()
 * Parameters:
 * 	arg 1: the pointer to the first char of the string
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: the hash key of str
 *
 * Registers Used:
 * 	%i0 - hash key of the str
 *	%l0 - HASH_START_VAL/hash variable
 *	%l1 - copy of pointer address
 *	%l2 - counter of length, strLen
 *	%l3 - temp var to store char in strlen/ var i in FOR
 *	%l4 - HASH_PRIME
 *	%l5 - str[i]
 */
 
hash:
 	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value is calculated	

	!--------UNSURE-------
	set	HashStartVal, %l0
	

	!ld	[%fp - 4], %l0	! Grabs the address of the HASH_START_VAL
	ld	[%l0], %l0	! store the value of HASH_START_VAL to hash
	
	mov	%i0, %l1	! copy over address of pointer to new reg
	clr	%l2		! clears the length of counter var 
	
strlen:
	ldub	[%l1], %l3	! loads the character 
	cmp	%l3, 0
	be	fin_strlen	! if reaches nul, branch over to start for-loop
	nop

	inc	%l2		! increment the counter for length
	inc	%l1		! move one char over of pointer 
	ba	strlen	
	nop

fin_strlen:
	clr	%l3		! initialize the var i to 0, for later
	mov	%i0, %l1	! reset the temp pointer for another traversal
	
	!--------UNSURE-------- 
	set	HashPrime, %l4
	!ld	[%fp - 8], %l4	! grab HASH_PRIME value
	ld	[%l4], %l4
	
	!mov	HASH_PRIME, %l4

	cmp	%l3, %l2
	bge	end_loop
	nop

loop:	
	mov	%l0, %o0	! move hash for multiplication
	mov	%l4, %o1	! move HASH_PRIME for multiplication
	call	.mul
	nop			! result now stored in %o0

	ldub	[%l1],%l5	! get the char and store in %l5

	add	%o0, %l5, %l0	! operate and store result in hash

	inc	%l3		! increment i
	inc	%l1		! incrememt pointer 

	cmp	%l3, %l2	! compare i with length of string 
	bl	loop		! less than strlen, loop again
	nop

end_loop: 
	mov	%l0, %i0	! ready to output
	ret 
	restore
