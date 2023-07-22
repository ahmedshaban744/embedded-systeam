/*
 * util.h
 *
 * Created: 7/20/2023 10:23:20 PM
 *  Author: Ahmed
 */ 


#ifndef UTIL_H_
#define UTIL_H_
#define set_bit(reg,bit) reg|=1<<bit
#define clear_bit(reg,bit) reg&=~(1<<bit)
#define read_bit(reg,bit) ((reg>>bit)&1)
#define toggle_bit(reg,bit) reg^=1<<bit
#endif /* UTIL_H_ */