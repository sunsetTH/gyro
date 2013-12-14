/*----------------------------------------------------------------------
  File Name          : ADIS16405_IO.h 
  Author             : Neil Zhao - CAST
  Version            : V1.0
  Date               : 4/20/2010
  Description        : ADIS16405 Driver Declaration

  Analog Devices ADIS16405 is a complete triple axis gyroscope
  and triple axis accelerometer and triple magnetometer inertial sensing system

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
//---------------------------------
//WriteToADIS16405ViaSpi();
//---------------------------------
//Function that writes to the ADIS16405 via the SPI port. It sends first the control
//word that includes the start address and then the data to write.
//When writing registers which take up multi-bytes, ADIS16405 must be written one byte by one byte.
//CS must be pulled high and then pulled low before writing the next byte
//--------------------------------------------------------------------------------
void WriteToADIS16405ViaSpi(unsigned char RegisterAddress, unsigned char NumberofRegisters, unsigned char *RegisterData);

//---------------------------------
//ReadFromADIS16405ViaSpi();
//---------------------------------
//Function that reads from the ADIS16405 via the SPI port. ADIS16405 supports full duplex mode operation.
//It first send the control word that includes the start address which you are going to access and then 8 clcoks
//Now,the data on DOUT pin of ADIS16405 is the register which you accessed just before this operation
//Then repeat sending control word and clock, read data at the same time and now
//the data on DOUT pin of ADIS16405 is the register which you are going to read
//CS must be pulled high and then pulled low before reading the next register
//--------------------------------------------------------------------------------
void ReadFromADIS16405ViaSpi(unsigned char RegisterAddress, unsigned char NumberofRegisters, unsigned char *RegisterData);




