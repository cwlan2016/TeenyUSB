/**
  ******************************************************************************
  * @file    usbd_msc_scsi.h
  * @author  MCD Application Team
  * @brief   Header for the usbd_msc_scsi.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics International N.V.
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other
  *    contributors to this software may be used to endorse or promote products
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under
  *    this license is void and will automatically terminate your rights under
  *    this license.
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_MSC_SCSI_H
#define __USBD_MSC_SCSI_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "usbd_def.h"

/** @addtogroup STM32_USB_DEVICE_LIBRARY
  * @{
  */

/** @defgroup USBD_SCSI
  * @brief header file for the storage disk file
  * @{
  */

/** @defgroup USBD_SCSI_Exported_Defines
  * @{
  */

#define SENSE_LIST_DEEPTH                           4U

/* SCSI Commands */
#define SCSI_FORMAT_UNIT                            0x04U
#define SCSI_INQUIRY                                0x12U
#define SCSI_MODE_SELECT6                           0x15U
#define SCSI_MODE_SELECT10                          0x55U
#define SCSI_MODE_SENSE6                            0x1AU
#define SCSI_MODE_SENSE10                           0x5AU
#define SCSI_ALLOW_MEDIUM_REMOVAL                   0x1EU
#define SCSI_READ6                                  0x08U
#define SCSI_READ10                                 0x28U
#define SCSI_READ12                                 0xA8U
#define SCSI_READ16                                 0x88U

#define SCSI_READ_CAPACITY10                        0x25U
#define SCSI_READ_CAPACITY16                        0x9EU

#define SCSI_REQUEST_SENSE                          0x03U
#define SCSI_START_STOP_UNIT                        0x1BU
#define SCSI_TEST_UNIT_READY                        0x00U
#define SCSI_WRITE6                                 0x0AU
#define SCSI_WRITE10                                0x2AU
#define SCSI_WRITE12                                0xAAU
#define SCSI_WRITE16                                0x8AU

#define SCSI_VERIFY10                               0x2FU
#define SCSI_VERIFY12                               0xAFU
#define SCSI_VERIFY16                               0x8FU

#define SCSI_SEND_DIAGNOSTIC                        0x1DU
#define SCSI_READ_FORMAT_CAPACITIES                 0x23U

#define NO_SENSE                                    0U
#define RECOVERED_ERROR                             1U
#define NOT_READY                                   2U
#define MEDIUM_ERROR                                3U
#define HARDWARE_ERROR                              4U
#define ILLEGAL_REQUEST                             5U
#define UNIT_ATTENTION                              6U
#define DATA_PROTECT                                7U
#define BLANK_CHECK                                 8U
#define VENDOR_SPECIFIC                             9U
#define COPY_ABORTED                                10U
#define ABORTED_COMMAND                             11U
#define VOLUME_OVERFLOW                             13U
#define MISCOMPARE                                  14U


#define INVALID_CDB                                 0x20U
#define INVALID_FIELED_IN_COMMAND                   0x24U
#define PARAMETER_LIST_LENGTH_ERROR                 0x1AU
#define INVALID_FIELD_IN_PARAMETER_LIST             0x26U
#define ADDRESS_OUT_OF_RANGE                        0x21U
#define MEDIUM_NOT_PRESENT                          0x3AU
#define MEDIUM_HAVE_CHANGED                         0x28U
#define WRITE_PROTECTED                             0x27U
#define UNRECOVERED_READ_ERROR                      0x11U
#define WRITE_FAULT                                 0x03U

#define READ_FORMAT_CAPACITY_DATA_LEN               0x0CU
#define READ_CAPACITY10_DATA_LEN                    0x08U
#define MODE_SENSE10_DATA_LEN                       0x08U
#define MODE_SENSE6_DATA_LEN                        0x04U
#define REQUEST_SENSE_DATA_LEN                      0x12U
#define STANDARD_INQUIRY_DATA_LEN                   0x24U
#define BLKVFY                                      0x04U

extern  uint8_t Page00_Inquiry_Data[];
extern  uint8_t Standard_Inquiry_Data[];
extern  uint8_t Standard_Inquiry_Data2[];
extern  uint8_t Mode_Sense6_data[];
extern  uint8_t Mode_Sense10_data[];
extern  uint8_t Scsi_Sense_Data[];
extern  uint8_t ReadCapacity10_Data[];
extern  uint8_t ReadFormatCapacity_Data [];
/**
  * @}
  */


/** @defgroup USBD_SCSI_Exported_TypesDefinitions
  * @{
  */

typedef struct _SENSE_ITEM {
  char Skey;
  union {
    struct _ASCs {
      char ASC;
      char ASCQ;
    }b;
    uint8_t	ASC;
    char *pData;
  } w;
} USBD_SCSI_SenseTypeDef;
/**
  * @}
  */

/** @defgroup USBD_SCSI_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup USBD_SCSI_Exported_Variables
  * @{
  */

/**
  * @}
  */
/** @defgroup USBD_SCSI_Exported_FunctionsPrototype
  * @{
  */
int8_t SCSI_ProcessCmd(USBD_HandleTypeDef *pdev, uint8_t lun, uint8_t *cmd);

void SCSI_SenseCode(USBD_HandleTypeDef *pdev, uint8_t lun, uint8_t sKey,
                    uint8_t ASC);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __USBD_MSC_SCSI_H */
/**
  * @}
  */

/**
  * @}
  */

/**
* @}
*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

