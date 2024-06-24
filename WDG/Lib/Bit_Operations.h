/**
 * Bit_Operations.h
 *
 *  Created on: Sun Mar 26 2023
 *  Author    : Abdullah Darwish
 */
#ifndef BIT_OPERATIONS_H
#define BIT_OPERATIONS_H

#define SET_BIT(X, BIT)            (X |=  (1 << (BIT)))
#define CLEAR_BIT(X, BIT)          (X &= ~(1 << (BIT))) 
#define READ_BIT(X, BIT)           (((X) >> (BIT)) & 1)
#define TOGGLE_BIT(X, BIT)         (X ^= (1 << (BIT)))
#define ROR(X,BIT) 				   ( X= (X>>BIT) | (X<<(8-BIT)) )
#define ROL(X,BIT) 				   ( X= (X<<BIT) | (X>>(8-BIT)) )
#define BIT_IS_SET(X,BIT) 		   ( X & (1<<BIT) )
#define BIT_IS_CLEAR(X,BIT) 	   ( !(X & (1<<BIT)) )
#endif /* BIT_OPERATIONS_H */
