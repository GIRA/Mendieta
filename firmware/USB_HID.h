/** INCLUDES *******************************************************/
#include "GenericTypeDefs.h"
#include "Compiler.h"
#include "usb_config.h"
#include "./USB/usb_device.h"
#include "./USB/usb.h"

#include "HardwareProfile.h"

#include "./USB/usb_function_hid.h"

void USBInit(void);
void USBWriteAt(int, unsigned char);
void USBFlush(void);
BOOL USBDataAvailable(void);
unsigned char USBReadAt(int);
void USBReceiveNextPacket(void);
void USBWordWriteAt(int, WORD_VAL);

