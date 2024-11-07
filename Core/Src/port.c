#include "port.h"

/**
 * Logging port initializer.
 *
 * @param logPort Pointer to logging port instance.
 */
void initLogPort(LogPort* logPort) {
	
	logPort->hasMessage = 0;
	logPort->index = 0;
	
	for (uint8_t i = 0; i < BUFFER_SIZE; i++) logPort->buffer[i] = 0;
	for (uint16_t i = 0; i < DATA_MAX_SIZE; i++) logPort->receivedData[i] = 0;
}

/**
 * Write byte from buffer to data array.
 *
 * @param logPort Pointer to logging port instance.
 */
void writeByte(LogPort* logPort) {
	
	logPort->receivedData[logPort->index] = logPort->buffer[0];	// Write received byte to data array with current index
	logPort->index++;
}

/**
 * Get formatted data array string with its lenght.
 *
 * @param logPort Pointer to logging port instance.
 * @param stringLength Pointer to length of the string that will be printed to USB terminal.
 * @return Formatted string of data with its length.
 */
char* getData(LogPort* logPort) {
	
	uint8_t length = (logPort->index) * 5 + 5;
	
	char* retVal = malloc(length);
	//char retVal[length];
	
	// Add array elements
	for (uint8_t i = 0; i < logPort->index; i++) {
		
		char inputValue[5];
		sprintf(inputValue, "0x%02X ", logPort->receivedData[i]);
		strncat(retVal, inputValue, 5);
	}
	
	// Add data frame length
	char lengthString[3];
	sprintf(lengthString, "%3d", logPort->index);
	strncat(retVal, lengthString, 3);
	
	//char* retValPtr = retVal;
	
	//return retValPtr;
	
	return retVal;
}

uint8_t getLength(LogPort* logPort) {
	
	
}

/**
 * Set message ready flag.
 *
 * @param logPort Pointer to logging port instance.
 * @param value Value to be set.
 */
void setFlag(LogPort* logPort, uint8_t value) {
	logPort->hasMessage = value;
}
