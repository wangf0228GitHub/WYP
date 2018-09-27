#include "WorkMode_History.h"
#include "..\VisualTFT\hmi_driver.h"
#include "..\WirelessProc.h"


_SensorData SensorData4ShowList[History_PageSize];
uint8_t History_SensorIndex;
uint8_t History_ListCount;
uint8_t History_curPageCount;
uint8_t History_Page;