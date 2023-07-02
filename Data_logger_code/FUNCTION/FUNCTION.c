#include <FUNCTION.h>
#include <SEMIFUNCTION.h>



void	All_MUX_Disable(void)
	{
		MUX1_Disable;
		MUX2_Disable;
		MUX3_Disable;
		MUX4_Disable;
		MUX5_Disable;
	}
void delayUS(uint32_t us)
	{   // Sets the delay in microseconds.
		uint32_t ms_value = us;
		while (ms_value>0)
			{
				__HAL_TIM_SET_COUNTER(&htim2,0);  // set the counter value a 0
				while (__HAL_TIM_GET_COUNTER(&htim2) < 1000);
				ms_value--;
			}
		}		
void	SLAVE_SEND(void)
{
	USART1_T;
	delayUS(2);
	for(uint16_t cnt=0;cnt<60000;cnt++);
	HAL_UART_Transmit(&huart1, slave_to_master.send_data, master_to_slave_size,100);
	delayUS(2);
	USART1_R;
}	
void Channel_Select(uint8_t cell)
{
B0; A0;
HAL_Delay(100);
//delayUS(100);	
Battery_Voltage [0+(cell-1)*4] =Cell_Voltage ();

//	HAL_Delay(150);
A1; B0;
HAL_Delay(100);
//	delayUS(100);	
Battery_Voltage [1+(cell-1)*4] =Cell_Voltage ();

//	HAL_Delay(150);
B1; A0;
HAL_Delay(100);
	//delayUS(100);	
Battery_Voltage [2+(cell-1)*4] =Cell_Voltage ();

//	HAL_Delay(150);
A1; B1;
HAL_Delay(100);
	//delayUS(100);	
Battery_Voltage [3+(cell-1)*4] =Cell_Voltage ();
 // HAL_Delay(150);
//All_MUX_Disable();
}
void MUX_Enable (uint8_t i)
{
All_MUX_Disable();
switch(i){
case(1):
All_MUX_Disable();
MUX1_Enable;
Channel_Select(1);
return;
case(2):
All_MUX_Disable();
MUX2_Enable;
Channel_Select(2);
return;
case(3):
All_MUX_Disable();
MUX3_Enable;
Channel_Select(3);
break;
case(4):
All_MUX_Disable();
MUX4_Enable;
Channel_Select(4);
return;
case(5):
All_MUX_Disable();
MUX5_Enable;
Channel_Select(5);
return;
default:
All_MUX_Disable();
return;
}	
}
uint16_t Cell_Voltage (void)
{


ADSwrite[0] = 0x01;
ADSwrite[1] = 0x85; 
ADSwrite[2] = 0x03; //LSB 
HAL_I2C_Master_Transmit(&hi2c2, ADS1115_ADDRESS << 1, ADSwrite, 3, 100);
ADSwrite[0] = 0x00;
	HAL_Delay(125);	
HAL_I2C_Master_Transmit(&hi2c2, ADS1115_ADDRESS << 1 , ADSwrite, 1,100);
HAL_Delay(125);	
HAL_I2C_Master_Receive(&hi2c2, ADS1115_ADDRESS <<1, ADSwrite, 2, 100);
reading = (ADSwrite[0] << 8 | ADSwrite[1] );
//if(reading < 0) {
////	reading = 0;
//EMG_ON; 
//}
//EMG_OFF;
//return (voltage = reading * (R*ADCConv));
	return (reading );

	
//	
//ADSwrite[0] = 0x01;
//ADSwrite[1] = 0x85; 
//ADSwrite[2] = 0x03; //LSB 
//HAL_I2C_Master_Transmit(&hi2c2, ADS1115_ADDRESS << 1, ADSwrite, 3, 100);
//ADSwrite[0] = 0x00;
//	delayUS(125);	
//	//HAL_Delay(125);	
//HAL_I2C_Master_Transmit(&hi2c2, ADS1115_ADDRESS << 1 , ADSwrite, 1,100);
////HAL_Delay(125);	
//delayUS(125);	
//	HAL_I2C_Master_Receive(&hi2c2, ADS1115_ADDRESS <<1, ADSwrite, 2, 100);
//reading = (ADSwrite[0] << 8 | ADSwrite[1] );
////if(reading < 0) {
//////	reading = 0;
////EMG_ON; 
////}
////EMG_OFF;
////return (voltage = reading * (R*ADCConv));
//	return (reading );
}
float Temperature1 (void)
	{
		ADSwrite[0] = 0x01;
		ADSwrite[1] = 0xE5; 
		ADSwrite[2] = 0x03; //LSB 
		HAL_I2C_Master_Transmit(&hi2c2, ADS1115_ADDRESS << 1, ADSwrite, 3, 100);
		ADSwrite[0] = 0x00;				 
		HAL_I2C_Master_Transmit(&hi2c2, ADS1115_ADDRESS << 1 , ADSwrite, 1,100);
		HAL_Delay(150);							
		HAL_I2C_Master_Receive(&hi2c2, ADS1115_ADDRESS <<1, ADSwrite, 2, 100);
		reading = (ADSwrite[0] << 8 | ADSwrite[1] );
		temp = reading * ADCConv;

		if (0>temp){
		temp_real=Battery_Temperature[0];}

		else if((temp>0) && (0.780573714259319>temp)){

		temp_real=-70.1*pow(temp,4)	+192.6*pow(temp,3) -210.2*pow(temp,2)+154*temp -57.7 ;}//-30-0 °C

		else if((1.578685882340098>temp) && (temp>0.780573714259319)){

		temp_real=9.092*pow(temp,4)	-25.34*pow(temp,3) + 24.45*pow(temp,2)+35.69*temp -34.07 ;}//0-40 °C

		else if((1.964043088386631>temp) && (temp>1.578685882340098)){

		temp_real=476.3*pow(temp,4)	-3141*pow(temp,3) + 7834*pow(temp,2)-8681*temp +3620	;}//40-80 °C

		else if(1.964043088386631<temp){

		temp_real=859.2*pow(temp,2) -3219*temp +3089 ;}//80-120 °C

		return (temp_real);
	}
float Temperature2 (void)
{
ADSwrite[0] = 0x01;
ADSwrite[1] = 0xF5; 
ADSwrite[2] = 0x03; //LSB 
HAL_I2C_Master_Transmit(&hi2c2, ADS1115_ADDRESS << 1, ADSwrite, 3, 100);
ADSwrite[0] = 0x00;				 
HAL_I2C_Master_Transmit(&hi2c2, ADS1115_ADDRESS << 1 , ADSwrite, 1,100);
HAL_Delay(50);							
HAL_I2C_Master_Receive(&hi2c2, ADS1115_ADDRESS <<1, ADSwrite, 2, 100);
reading = (ADSwrite[0] << 8 | ADSwrite[1] );
temp = reading * ADCConv;

if (0>temp){
temp_real=Battery_Temperature[1];}

else if((temp>0) && (0.780573714259319>temp)){

temp_real=-70.1*pow(temp,4)	+192.6*pow(temp,3) -210.2*pow(temp,2)+154*temp -57.7 ;}//-30-0 °C

else if((1.578685882340098>temp) && (temp>0.780573714259319)){

temp_real=9.092*pow(temp,4)	-25.34*pow(temp,3) + 24.45*pow(temp,2)+35.69*temp -34.07 ;}//0-40 °C

else if((1.964043088386631>temp) && (temp>1.578685882340098)){

temp_real=476.3*pow(temp,4)	-3141*pow(temp,3) + 7834*pow(temp,2)-8681*temp +3620	;}//40-80 °C

else if(1.964043088386631<temp){

temp_real=859.2*pow(temp,2) -3219*temp +3089 ;}//80-120 °C

return (temp_real);
}

void	reset_state (void)
	{
		command_counter = 0;
		flag.BIT.flag_ask_for_data =1;
		HAL_TIM_Base_Stop_IT(&htim3);
		HAL_GPIO_WritePin(USART1_GPIO_Port, USART1_Pin, GPIO_PIN_RESET);
		// change direction to recive 
	}

void crc_init(void) {

 RCC->AHBENR |= RCC_AHBENR_CRCEN;  // enable clock for CRC
 CRC->CR |= CRC_CR_RESET;   // Reset calculation
 
}

uint8_t	cal_crc(uint8_t *data,uint8_t *cal_crc)
{
uint8_t compare_condition =0;
CRC->CR = 1;
	
//// second approche
//		uint32_t  CRC_CALCULATED=0;
//		CRC_CALCULATED = HAL_CRC_Calculate(&hcrc,data,66);
	for (uint8_t cnt = 0; cnt <(22 *3) ; cnt++)
		{
		 CRC->DR = *(data+cnt);
		}
  if(CRC->DR == *(cal_crc +0))
		{
				return 1;
		}
	else
		{
				return 0;
		
		}
 
	
		
		
}

//{
///* USER CODE END WHILE */

///* USER CODE BEGIN 3 */
//All_MUX_Disable();
//	EMG_ON;
//for(int j=1; j< 6; j++){

//MUX_Enable (j);
//}



//for(int n=0 ; n<20 ; n++)
//{

////sprintf((char *)str,"\r\n%s %d %s %.4f", "V_Cell",n,"=",Battery_Voltage[n]);
////				sprintf((char *)str,"%.4f %s" ,Battery_Voltage[n], ",");
////				HAL_UART_Transmit(&huart1,str ,strlen((char *)str), 100);

////if (n>7)
////{
////Battery_Voltage[n]=Battery_Voltage[n]+0.06;
////}
////else
////Battery_Voltage[n]=Battery_Voltage[n];
//if (Battery_Voltage[n]>0.06)
//{
//	if (n==0)
//	Battery_Voltage[0]=Battery_Voltage[0]+0.00630;
//	else if (n==1)
//	Battery_Voltage[1]=Battery_Voltage[1]+0.00285;
//	else if (n==2)
//	Battery_Voltage[2]=Battery_Voltage[2]+0.00255;
//	else if (n==3)
//	Battery_Voltage[3]=Battery_Voltage[3]+0.00495;
//	else if (n==4)
//	Battery_Voltage[4]=Battery_Voltage[4]+0.01060;
//	else if (n==5)
//	Battery_Voltage[5]=Battery_Voltage[5]+0.01550;
//	else if (n==6)
//	Battery_Voltage[6]=Battery_Voltage[6]+0.01740;
//	else if (n==7)
//	Battery_Voltage[7]=Battery_Voltage[7]+0.02880;
//	else if (n==8)
//	Battery_Voltage[8]=Battery_Voltage[8]+0.03920;
//	else if (n==9)
//	Battery_Voltage[9]=Battery_Voltage[9]+0.03305;
//	else if (n==10)
//	Battery_Voltage[10]=Battery_Voltage[10]+0.03320;
//	else if (n==11)
//	Battery_Voltage[11]=Battery_Voltage[11]+0.04985;
//	else if (n==12)
//	Battery_Voltage[12]=Battery_Voltage[12]+0.04930;
//	else if (n==13)
//	Battery_Voltage[13]=Battery_Voltage[13]+0.05040;
//	else if (n==14)
//	Battery_Voltage[14]=Battery_Voltage[14]+0.04750;
//	else if (n==15)
//	Battery_Voltage[15]=Battery_Voltage[15]+0.04403;
//	else if (n==16)
//	Battery_Voltage[16]=Battery_Voltage[16]+0.05195;
//	else if (n==17)
//	Battery_Voltage[17]=Battery_Voltage[17]+0.03650;
//	else if (n==18)
//	Battery_Voltage[18]=Battery_Voltage[18]+0.03290;
//	else if (n==19)
//	Battery_Voltage[19]=Battery_Voltage[19]+0.03655;
//}
//	
//sprintf((char *)str,"%.4f \r\n" ,Battery_Voltage[n]*R );
//HAL_UART_Transmit(&huart1,str ,strlen((char *)str), 100);	
////EMG_Toggle;
//EMG_OFF;
//}	
////Battery_Temperature[0]=Temperature1();
////Battery_Temperature[1]=Temperature2();
////sprintf((char *)str,"%.2f \r\n %.2f \r\n" ,Battery_Temperature[0],Battery_Temperature[1] );
////HAL_UART_Transmit(&huart1,str ,strlen((char *)str), 100);	

////				sprintf((char *)str,"\n" );	
////				HAL_UART_Transmit(&huart1,str ,strlen((char *)str), 100);		
////		 HAL_Delay(8800); //every MUX has 4*10ms (select) + 4*50ms (ADC) Delay >> 5 MUX = 5 * (4*10ms+ 4*50ms)=1200ms

////		A0; B0;
////		MUX1_Enable;
////		Battery_Voltage [0]=Cell_Voltage ();
////		HAL_Delay(50);
////		A1; B0;
////		MUX1_Enable;
////		Battery_Voltage [1]=Cell_Voltage ();
////		HAL_Delay(50);
////		A0; B1;
////		MUX1_Enable;
////		Battery_Voltage [2]=Cell_Voltage ();
////		HAL_Delay(50);
////		A1; B1;
////		MUX1_Enable;
////		Battery_Voltage [3]=Cell_Voltage ();
////		HAL_Delay(50);
////		A0; B0;
////		MUX2_Enable;
////		Battery_Voltage [4]=Cell_Voltage ();
////		HAL_Delay(50);
//}
