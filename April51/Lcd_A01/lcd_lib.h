/*******************************************************************************
 Title: 	lcd_lib.h
 Ver:		1.0

 Date:		2012-07-07
 By:		April

 Hardware:	RichMCU RZ-51V2.0 Development Board
			X'tal: 11.0592MHz

 Connection:	LCD pins as below -
 				RS - P20
				RW - P21
				EN - P22
				DATAPORT - P0

 Jumpers:		Remove JPSMG - Disable 7-Segment LEDs
 				Remove JPP0  - Disable LEDs
				Add JPBG     - Enable LCD Back Light

				�� JPSMG ����ܿ������߰ε�ʹ�����ֹͣ������
 				�� JPP0 ���߶˵�����ñ�ε��������1602 Һ����ʾ
				����1602LCDҺ��
				�� JPBG Һ���������߲���

 *******************************************************************************/
// unsigned char lcdCheckBusy(void)
// void lcdWaitNotBusy(void);

// void lcdWriteCmd(unsigned char cmd);
void lcdWriteData(unsigned char dData);
void lcdWriteString(char *str);

void lcdSetInputMode(unsigned char shiftCursor, unsigned char shiftString);
void lcdSetDisplay(unsigned char mode);

// row: 0, 1
void lcdSelectRow(unsigned char row);
void lcdSelectRowPosition(unsigned char pos);
void lcdSelectPosition(unsigned char row, unsigned pos);

// Clear LCD Screen
void lcdClear(void);

// Clear LCD Screen, Display ON, Cursor ON, Blinking ON,
void lcdInit(void);



