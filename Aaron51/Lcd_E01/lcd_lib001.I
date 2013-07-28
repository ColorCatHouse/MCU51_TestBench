
#line 1 "lcd_lib001.c" /0




























 
  
#line 1 "C:\KEIL4\C51\INC\STC\STC89.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 sfr  PSW        =   0xd0;        
 
 
 
 sbit CY         =   PSW^7;       
 sbit AC         =   PSW^6;       
 sbit F0         =   PSW^5;       
 sbit RS1        =   PSW^4;       
 sbit RS0        =   PSW^3;       
 sbit OV         =   PSW^2;       
 sbit P          =   PSW^0;       
 
 
 
 sfr  ACC        =   0xe0;        
 
 
 sbit ACC7       =   ACC^7;       
 sbit ACC6       =   ACC^6;       
 sbit ACC5       =   ACC^5;       
 sbit ACC4       =   ACC^4;       
 sbit ACC3       =   ACC^3;       
 sbit ACC2       =   ACC^2;       
 sbit ACC1       =   ACC^1;       
 sbit ACC0       =   ACC^0;       
 
 
 
 sfr  B          =   0xf0;        
 
 
 
 
 sfr  SP         =   0x81;        
 
 
 
 
 sfr  DPL        =   0x82;        
 
 
 sfr  DPH        =   0x83;        
 
 
 
 
 sfr  PCON       =   0x87;        
 
 
 
 
 
 
 
 
 
 
 
 
 
 sfr  WDT_CONTR  =   0xe1;        
 
 
 
 
 
 
 
 
 
 sfr  AUXR       =   0x8e;        
 
 
 
 
 
 
 
 
 sfr  AUXR1      =   0xa2;        
 
 
 
 
 
 
 
 
 sfr  P0         =   0x80;        
 
 
 
 sbit P07        =   P0^7;        
 sbit P06        =   P0^6;        
 sbit P05        =   P0^5;        
 sbit P04        =   P0^4;        
 sbit P03        =   P0^3;        
 sbit P02        =   P0^2;        
 sbit P01        =   P0^1;        
 sbit P00        =   P0^0;        
 
 
 
 sfr  P1         =   0x90;        
 
 
 
 sbit P17        =   P1^7;        
 sbit P16        =   P1^6;        
 sbit P15        =   P1^5;        
 sbit P14        =   P1^4;        
 sbit P13        =   P1^3;        
 sbit P12        =   P1^2;        
 sbit P11        =   P1^1;        
 sbit P10        =   P1^0;        
 
 sbit T2         =   P1^0;        
 sbit T2CLKO     =   P1^0;        
 sbit T2EX       =   P1^1;        
 
 
 
 sfr  P2         =   0xa0;        
 
 
 
 sbit P27        =   P2^7;        
 sbit P26        =   P2^6;        
 sbit P25        =   P2^5;        
 sbit P24        =   P2^4;        
 sbit P23        =   P2^3;        
 sbit P22        =   P2^2;        
 sbit P21        =   P2^1;        
 sbit P20        =   P2^0;        
 
 
 
 sfr  P3         =   0xb0;        
 
 
 
 sbit P37        =   P3^7;        
 sbit P36        =   P3^6;        
 sbit P35        =   P3^5;        
 sbit P34        =   P3^4;        
 sbit P33        =   P3^3;        
 sbit P32        =   P3^2;        
 sbit P31        =   P3^1;        
 sbit P30        =   P3^0;        
 
 sbit RXD        =   P3^0;        
 sbit TXD        =   P3^1;        
 sbit INT0       =   P3^2;        
 sbit INT1       =   P3^3;        
 sbit T0         =   P3^4;        
 sbit T1         =   P3^5;        
 sbit WR         =   P3^6;        
 sbit RD         =   P3^7;        
 
 
 
 sfr  P4         =   0xc0;        
 
 
 
 sbit P43        =   P4^3;        
 sbit P42        =   P4^2;        
 sbit P41        =   P4^1;        
 sbit P40        =   P4^0;        
 
 
 
 sfr  IE         =   0xa8;        
 
 
 
 sbit EA         =   IE^7;        
 sbit ET2        =   IE^5;        
 sbit ES         =   IE^4;        
 sbit ET1        =   IE^3;        
 sbit EX1        =   IE^2;        
 sbit ET0        =   IE^1;        
 sbit EX0        =   IE^0;        
 
 
 
 sfr  IPH        =   0xb7;        
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 sfr  IP         =   0xb8;        
 
 
 
 sbit PT2        =   IP^5;        
 sbit PS         =   IP^4;        
 sbit PT1        =   IP^3;        
 sbit PX1        =   IP^2;        
 sbit PT0        =   IP^1;        
 sbit PX0        =   IP^0;        
 
 
 
 sfr  XICON      =   0xe8;        
 
 
 
 sbit PX3        =   XICON^7;     
 sbit EX3        =   XICON^6;     
 sbit IE3        =   XICON^5;     
 sbit IT3        =   XICON^4;     
 sbit PX2        =   XICON^3;     
 sbit EX2        =   XICON^2;     
 sbit IE2        =   XICON^1;     
 sbit IT2        =   XICON^0;     
 
 
 
 
 
 
 
 
 
 
 
 
 sfr  TCON       =   0x88;        
 
 
 
 sbit TF1        = TCON^7;        
 sbit TR1        = TCON^6;        
 sbit TF0        = TCON^5;        
 sbit TR0        = TCON^4;        
 sbit IE1        = TCON^3;        
 sbit IT1        = TCON^2;        
 sbit IE0        = TCON^1;        
 sbit IT0        = TCON^0;        
 
 
 
 sfr  TMOD       =   0x89;        
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 sfr  TL0        = 0x8a;          
 
 
 
 
 sfr  TL1        = 0x8b;          
 
 
 
 
 sfr  TH0        = 0x8c;          
 
 
 
 
 sfr  TH1        = 0x8d;          
 
 
 
 
 sfr  T2CON      =   0xc8;        
 
 
 
 sbit TF2        = T2CON^7;       
 sbit EXF2       = T2CON^6;       
 sbit RCLK       = T2CON^5;       
 sbit TCLK       = T2CON^4;       
 sbit EXEN2      = T2CON^3;       
 sbit TR2        = T2CON^2;       
 sbit C_T2       = T2CON^1;       
 sbit CP_RL2     = T2CON^0;       
 
 
 
 sfr  T2MOD      =   0xc9;        
 
 
 
 
 
 
 
 
 sfr  RCAP2L     = 0xca;          
 
 
 
 
 sfr  RCAP2H     = 0xcb;          
 
 
 
 
 sfr  TL2        = 0xcc;          
 
 
 
 
 sfr  TH2        = 0xcd;          
 
 
 
 
 sfr  SCON       =   0x98;        
 
 
 
 sbit FE         =   SCON^7;      
 sbit SM0        =   SCON^7;      
 sbit SM1        =   SCON^6;      
 sbit SM2        =   SCON^5;      
 sbit REN        =   SCON^4;      
 sbit TB8        =   SCON^3;      
 sbit RB8        =   SCON^2;      
 sbit TI         =   SCON^1;      
 sbit RI         =   SCON^0;      
 
 
 
 sfr  SBUF       =   0x99;        
 
 
 
 
 sfr  SADDR      =   0xa9;        
 
 
 
 
 sfr  SADEN      =   0xb9;        
 
 
 
 
 sfr  ISP_DATA   =   0xe2;        
 
 
 
 
 sfr  ISP_ADDRH  =   0xe3;        
 
 
 
 
 sfr  ISP_ADDRL  =   0xe4;        
 
 
 
 
 sfr  ISP_CMD    =   0xe5;        
 
 
 
 
 
 
 
 
 
 sfr  ISP_TRIG   =   0xe6;        
 
 
 
 
 
 
 
 sfr  ISP_CONTR  =   0xe7;        
 
 
 
 
 
 
 
 
 
 
#line 30 "lcd_lib001.c" /0
 
  
#line 1 "lib_uty001.h" /0










 
 
 void delay(unsigned int delaycount);
#line 31 "lcd_lib001.c" /0
 
  
#line 1 "hw_rz51v2.h" /0


























 
 
 
 
 
 
 
 
#line 32 "lcd_lib001.c" /0
 
  
#line 1 "hw_lcd1602.h" /0












 
 
 
 
 
 
 
 
 
 
#line 33 "lcd_lib001.c" /0
 
  
#line 1 "lcd_lib001.h" /0



























 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void lcdWriteData(unsigned char dData);
 void lcdWriteString(char *str);
 
 unsigned char lcdSelectDDRAMAddr(unsigned addr);	 
 unsigned char lcdSelectCGRAMAddr(unsigned addr);	 
 
 unsigned char lcdGetCursorAddress(void);
 unsigned char lcdGetCurrentRow(void);
 unsigned char lcdGetCursorCurrentPos(void);
 
 void lcdPutCharAtPos(unsigned char row, unsigned char pos, char c);
 
 void lcdClearRow(unsigned char row);
 void lcdClearCurrentRow(void);
 void lcdClearRestOfRow(unsigned char row);
 void lcdClearRestOfCurrentRow(void);
 
 void lcdCursorReset(void);
 
 void lcdClearScreen(void);
 void lcdSelectRow(unsigned char row);
 void lcdSelectRowPosition(unsigned char row, unsigned char pos);
 void lcdSelectPosition(unsigned char row, unsigned pos);
 
 
 void lcdSetInputShiftOn(void);
 void lcdSetInputShiftOff(void);
 void lcdSetInputInc(void);
 void lcdSetInputDec(void);
 
 void lcdSetDisplay(unsigned char mode);
 void lcdSetDisplayOn(void);
 void lcdSetDisplayOff(void);
 void lcdSetDisplayCursorOn(void);
 void lcdSetDisplayCursorOff(void);
 void lcdSetDisplayCursorBlinkOn(void);
 void lcdSetDisplayCursorBlinkOff(void);
 
 void lcdSetShifting(unsigned char mode);
 void lcdSetShiftingMsg(void);
 void lcdSetShiftingCursor(void);
 void lcdSetShiftingRight(void);
 void lcdSetShiftingLeft(void);
 
 void lcdSetFunction(unsigned char mode);
 void lcdSetFunction2Lines(void);
 void lcdSetFunction1Line(void);
 void lcdSetFunctionFont5x7(void);
 void lcdSetFunctionFont5x10(void);
 







 
 unsigned char lcdMakeRawFont(unsigned char c, unsigned char row0,
 unsigned char row1, 
 unsigned char row2, 
 unsigned char row3, 
 unsigned char row4,
 unsigned char row5,
 unsigned char row6,
 unsigned char row7);
 







 
 unsigned char lcdMakeFont(unsigned char c, char *row);
 void lcdInit(void);							 
 
 void lcdEfxBounce(unsigned char row, char *str, unsigned int speed);
 void lcdEfxRoll(unsigned char row, char *str, unsigned char dir, unsigned int speed);
#line 34 "lcd_lib001.c" /0
 
 
 
 
 unsigned char	lcdCurrentModeInput;			 
 unsigned char	lcdCurrentModeDisplay;		  	 
 unsigned char	lcdCurrentModeShifting;			 
 unsigned char	lcdCurrentModeFunction;			 
 
 unsigned char lcdCheckBusy(void)
 {
 unsigned char bf;
 
  P07 = 1;					 
 
  P22 = 0;					 
  P20 = 0;
  P21 = 1;
  P22 = 1;	
 delay(10);		 
 bf = P07;
  P22 = 0;
  P20 = 1;				 
  P21 = 1;				 
 
 return bf;
 
 }  
 
 void lcdWaitUntilReady(void)
 {
 while (lcdCheckBusy() == 1);
 
 }  
 
 void lcdWriteCmd(unsigned char cmd)
 {
 lcdWaitUntilReady();
 
  P22 = 0;					 
  P20 = 0;
  P21 = 0;
  P0 = cmd;
 delay(10);		 
  P22 = 1;
 delay(10);		 
  P22 = 0;
  P20 = 1;
  P21 = 1;
 
 }  
 
 void lcdWriteData(unsigned char dData)
 {
 lcdWaitUntilReady();
 
  P22 = 0;					 
  P20 = 1;
  P21 = 0;
  P0 = dData;
 delay(10);		 
  P22 = 1;
 delay(10);		 
  P22 = 0;
  P20 = 1;
  P21 = 1;
 
 }  
 
 void lcdWriteString(char *str)
 {
 unsigned int n;
 
 for (n=0; *(str+n)!=0; n++)
 {
 lcdWriteData(*(str+n));
 }
 
 }  
 
 void lcdSetDisplay(unsigned char mode)
 {
 lcdCurrentModeDisplay = mode;
 
 lcdWriteCmd(0x08 | lcdCurrentModeDisplay);
 
 }  
 
 void lcdSetInput(unsigned char mode)
 {
 lcdCurrentModeInput = mode;
 
 lcdWriteCmd(0x04 | lcdCurrentModeInput);
 
 }  
 
 void lcdSelectRow(unsigned char row)	 
 {
 if (row == 0)
 {
 lcdWriteCmd(0x80); 			 
 }
 else
 {
 lcdWriteCmd(0x80 | 0x40); 		 
 }
 
 }  
 
 void lcdClearRow(unsigned char row)
 {
 unsigned char n;
 unsigned char currentModeInput;
 
 currentModeInput = lcdCurrentModeInput;
 
 lcdSetInputInc();
 
 lcdSelectRow(row);
 
 for (n=0; n<40; n++)
 {
 lcdWriteData(' ');
 }
 
 lcdSetInput(currentModeInput);
 
 lcdSelectRow(row);
 
 }  
 
 void lcdClearScreen(void)
 {
 lcdWriteCmd(0x01);			 
 
 }  
 
 void lcdInit(void)
 {
 lcdCurrentModeFunction = 0x08;		 
 
 lcdWriteCmd(0x20 | 0x10 | 
 lcdCurrentModeFunction);
 
 }  
 
 void lcdSetInputShiftOn(void)
 {
 lcdCurrentModeInput |= 0x01;
 
 lcdWriteCmd(0x04 | lcdCurrentModeInput);
 
 }  
 
 void lcdSetInputShiftOff(void)
 {
 lcdCurrentModeInput &= ~0x01;
 
 lcdWriteCmd(0x04 | lcdCurrentModeInput);
 
 }  
 
 void lcdSetInputInc(void)
 {
 lcdCurrentModeInput |= 0x02;
 
 lcdWriteCmd(0x04 | lcdCurrentModeInput);
 
 }  
 
 void lcdSetInputDec(void)
 {	
 lcdCurrentModeInput &= ~0x02;
 
 lcdWriteCmd(0x04 | lcdCurrentModeInput);
 
 }  
 







 
 unsigned char lcdMakeRawFont(unsigned char c, unsigned char row0,
 unsigned char row1, 
 unsigned char row2, 
 unsigned char row3, 
 unsigned char row4,
 unsigned char row5,
 unsigned char row6,
 unsigned char row7)
 {																 
 unsigned char	cgAddr;
 unsigned char	error;
 
 if (c > 8)
 {
 error = 1;
 }
 else
 {
 cgAddr = c * 8;							   
 
 lcdWriteCmd(0x40 |  cgAddr);
 lcdWriteData(row0);
 
 lcdWriteCmd(0x40 | (cgAddr+1));
 lcdWriteData(row1);
 
 lcdWriteCmd(0x40 | (cgAddr+2));
 lcdWriteData(row2);
 
 lcdWriteCmd(0x40 | (cgAddr+3));
 lcdWriteData(row3);
 
 lcdWriteCmd(0x40 | (cgAddr+4));
 lcdWriteData(row4);
 
 lcdWriteCmd(0x40 | (cgAddr+5));
 lcdWriteData(row5);
 
 lcdWriteCmd(0x40 | (cgAddr+6));
 lcdWriteData(row6);
 
 lcdWriteCmd(0x40 | (cgAddr+7));
 lcdWriteData(row7);
 
 error = 0;
 }
 
 
 return error;
 
 }  
 







 
 unsigned char lcdMakeFont(unsigned char c, char *row)
 {
 unsigned char	cgAddr;
 unsigned char	error;
 unsigned char	n;
 
 if (c > 8)
 {
 error = 1;
 }
 else
 {
 cgAddr = c * 8;
 
 for (n=0; n<8; n++)
 {
 lcdWriteCmd(0x40 | cgAddr + n);
 lcdWriteData(row[n]);
 }
 error = 0;
 }
 return error;
 
 }  
 
 
 
