#include "I2C.h"

uint8_t g_master_hour_txBuff[I2C_DATA_LENGTH];
uint8_t g_master_hour_rxBuff[I2C_DATA_LENGTH];
uint32_t sourceClock;
i2c_master_config_t masterConfig;
i2c_master_transfer_t masterXfer;

void I2C_Init(void){
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();
	BOARD_InitPins();
	I2C_MasterGetDefaultConfig(&masterConfig);
	masterConfig.baudRate_Bps = I2C_BAUDRATE;
	sourceClock = CLOCK_GetFreq(kCLOCK_BusClk);
	I2C_MasterInit(I2C0, &masterConfig, sourceClock);
	memset(&masterXfer, 0, sizeof(masterXfer));
}

void Receive_Data(void){
	/* subAddress = 0x01, data = g_master_rxBuff - read from slave.
	start + slaveaddress(w) + subAddress + repeated start + slaveaddress(r) + rx data buffer + stop */
	masterXfer.slaveAddress   = I2C_MASTER_SLAVE_ADDR;
	masterXfer.direction      = kI2C_Read;
	masterXfer.subaddress     = 0x00;
	masterXfer.subaddressSize = 1;
	masterXfer.data           = g_master_hour_rxBuff;
	masterXfer.dataSize       = I2C_DATA_LENGTH;
	masterXfer.flags          = kI2C_TransferDefaultFlag;
	I2C_MasterTransferBlocking(I2C0, &masterXfer);
}

void Transfer_Data(void){
	/* subAddress = 0x01, data = g_master_txBuff - write to slave.
	start + slaveaddress(w) + subAddress + length of data buffer + data buffer + stop*/
	uint8_t deviceAddress     = 0x01U;
	masterXfer.slaveAddress   = I2C_MASTER_SLAVE_ADDR;
	masterXfer.direction      = kI2C_Write;
	masterXfer.subaddress     = 0x00;
	masterXfer.subaddressSize = 1;
	masterXfer.data           = g_master_hour_txBuff;
	masterXfer.dataSize       = I2C_DATA_LENGTH;
	masterXfer.flags          = kI2C_TransferDefaultFlag;
	I2C_MasterTransferBlocking(I2C0, &masterXfer);
}
