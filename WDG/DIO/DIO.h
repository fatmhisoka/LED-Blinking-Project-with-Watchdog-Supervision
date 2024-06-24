
#ifndef DIO_H_
#define DIO_H_

#include "std_types.h"



void DIO_init(void);
void DIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);




#endif /* DIO_H_ */
