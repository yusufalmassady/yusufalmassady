#define DDRA *((volatile u8*)0x3A)
#define PORTA *((volatile u8*)0x3B)
#define PINA *((volatile u8*)0x39)

#define DDRB *((volatile u8*)0x37)
#define PORTB *((volatile u8*)0x38)
#define PINB *((volatile u8*)0x36)

#define DDRC *((volatile u8*)0x34)
#define PORTC *((volatile u8*)0x35)
#define PINC *((volatile u8*)0x33)

#define DDRD *((volatile u8*)0x31)
#define PORTD *((volatile u8*)0x32)
#define PIND *((volatile u8*)0x30)

#define SREG  *((volatile u8*)0x5F)
#define MCUCR *((volatile u8*)0x55)
#define GICR  *((volatile u8*)0x5B)


#define ADMUX  *((volatile u8*)0x27)
#define ADCSRA *((volatile u8*)0x26)
#define ADCH   *((volatile u8*)0x25)

#define TCCR0  *((volatile u8*)0x53)
#define TIMSK  *((volatile u8*)0x59)
#define TIFR   *((volatile u8*)0x58)
#define OCR0   *((volatile u8*)0x5C)
#define TCCR1A *((volatile u8*)0x4F)
#define TCCR1B *((volatile u8*)0x4E)
#define OCR1A  *((volatile u16*)0x4A)
#define ICR1   *((volatile u16*)0x46)
#define TCNT1   *((volatile u16*)0x4C)

