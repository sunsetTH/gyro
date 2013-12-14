/*----------------------------------------------------------------------
  File Name          : ADIS16405.h
  Author             : Neil Zhao - CAST
  Version            : V1.0
  Date               : 04/19/2010
  Description        : ADIS16405 Registers Address

  Analog Devices ADIS16405 is a complete triple axis gyroscope
  and triple axis accelerometer inertial sensing system

  China Applications Support Team.
  china.support@analog.com
----------------------------------------------------------------------

  The present firmware which is for guidance only aims at providing
  customers with coding information regarding their products in order
  for them to save time.  As a result, Analog Devices shall not be
  held liable for any direct, indirect or consequential damages with
  respect to any claims arising from the content of such firmware and/or
  the use made by customers of the coding information contained herein
  in connection with their products.

----------------------------------------------------------------------*/

#define FLASH_CNT 		0X00
#define SUPPLY_OUT 		0X02

#define XGYRO_OUT		0X04
#define YGYRO_OUT 		0X06
#define ZGYRO_OUT 		0X08

#define XACCL_OUT 	 	0X0A
#define YACCL_OUT 		0X0C
#define ZACCL_OUT 		0X0E

#define XMAGN_OUT 	 	0X10
#define YMAGN_OUT 		0X12
#define ZMAGN_OUT 		0X14

#define TEMP_OUT		0X16
#define AUX_ADC 		0X18

#define XGYRO_OFF		0X1A
#define YGYRO_OFF		0X1C
#define ZGYRO_OFF		0X1E

#define XACCL_OFF		0X20
#define YACCL_OFF		0X22
#define ZACCL_OFF		0X24

#define XMAGN_HIF		0X26
#define YMAGN_HIF		0X28
#define ZMAGN_HIF		0X2A

#define XMAGN_SIF		0X2C
#define YMAGN_SIF		0X2E
#define ZMAGN_SIF		0X30

#define GPIO_CTRL		0X32
#define MSC_CTRL		0X34
#define SMPL_PRD		0X36
#define SENS_AVG		0X38
#define SLP_CNT			0X3A
#define DIAG_STAT		0X3C
#define GLOB_CMD		0X3E

#define ALM_MAG1		0X40
#define ALM_MAG2		0X42
#define ALM_SMPL1		0X44
#define ALM_SMPL2		0X46
#define ALM_CTRL		0X48
#define AUX_DAC			0X4A

#define PRODUCT_ID		0X56





