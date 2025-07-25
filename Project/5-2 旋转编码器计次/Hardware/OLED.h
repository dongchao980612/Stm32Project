#ifndef __OLED_H
#define __OLED_H

typedef struct{
	/* Tx Pin */
	uint32_t             txClock;
	uint16_t             txPin;
	GPIO_TypeDef*        txPort;
	/* Rx Pin */         
	uint32_t             rxClock;
	uint16_t             rxPin;
	GPIO_TypeDef*        rxPort;
} OledCfg_t;


void OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

#endif
