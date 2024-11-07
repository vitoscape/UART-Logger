#ifndef __PORT_H
#define __PORT_H

#include <stdint.h>

#define DATA_MAX_SIZE	100
#define BUFFER_SIZE		1

/**
 * Logging port structure.
 */
typedef struct {
	
	uint8_t hasMessage;
	uint8_t index;
	
	uint8_t buffer[BUFFER_SIZE];		// For reciving bytes
	uint8_t receivedData[DATA_MAX_SIZE];
	
} LogPort;

void initLogPort(LogPort* logPort);
void writeByte(LogPort* logPort);

#endif
