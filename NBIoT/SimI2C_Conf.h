#ifndef __SIMI2C_Conf_h__
#define __SIMI2C_Conf_h__

#include "main.h"

#define SIMI2C_SCL_OUT() TRISD7=0
#define SIMI2C_SDA_OUT() TRISD6=0
#define SIMI2C_SDA_IN() TRISD6=1

#define SIMI2C_SCL_Low() LATD7=0
#define SIMI2C_SCL_High() LATD7=1

#define SIMI2C_SDA_Low() LATD6=0
#define SIMI2C_SDA_High() LATD6=1

#define SIMI2C_SDA_Read() RD6
#endif


