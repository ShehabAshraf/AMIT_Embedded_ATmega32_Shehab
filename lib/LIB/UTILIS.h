#ifndef UTILIS_H
#define UTILIS_H

#define SET_BIT(REG,Bit_No) (REG |=  (1<<Bit_No))
#define CLR_BIT(REG,Bit_No) (REG &=~ (1<<Bit_No))
#define TOG_BIT(REG,Bit_No) (REG ^=  (1<<Bit_No))
#define GET_BIT(REG,Bit_No) (1   & (REG>>Bit_No))



#endif