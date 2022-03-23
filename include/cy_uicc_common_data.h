/******************************************************************************
* File Name:   cy_uicc_common_data_h
*
* Description: This file defines macros used in UICC files.
*
* Related Document: See README.md
*
*
*******************************************************************************
* Copyright 2020-2021, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

/**
 * \file cy_uicc_common_data.h
 * \brief Public interface of UICC related macros.
*/

#ifndef SOURCE_CY_UICC_COMMON_DATA_H_
#define SOURCE_CY_UICC_COMMON_DATA_H_

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif


/*-- Public Definitions -------------------------------------------------*/

/** \brief Maximum Length of serial port name in characters. */
#define MAX_SERIAL_PORT_NAME_LEN    16

/** \brief Length of status word. */
#define SIZE_OF_SW                  0x02

/** \brief Status word that conveys Operation is Successful. */
#define ISO_STATUS_OK               0x9000

/** \brief Read 16bit data from 'Buffer' Array and update 'Value' variable, where
*          Array is input parameter
*          and value is output parameter. */
#define READU16(Ppui1Buffer,Pui2Value)   {\
        Pui2Value = (((*(uint8_t *)Ppui1Buffer) << 8 ) |(*(uint8_t *)(Ppui1Buffer + 1)));}

/** \brief Read 32bit data from 'Buffer' Array and update 'Value' variable, where
*          Array is input parameter
*          and value is output parameter. */
#define READU32(Ppui1Buffer, Pui4Value) {\
        Pui4Value = ((((*(uint8_t *)(Ppui1Buffer )) << 24 ) & 0XFF000000)| \
                (((*(uint8_t *)(Ppui1Buffer + 1)) << 16 )& 0X00FF0000) | \
                (((*(uint8_t *)(Ppui1Buffer + 2)) << 8 ) & 0X0000FF00) | \
                (((*(uint8_t *)(Ppui1Buffer + 3)) & 0X000000FF)));}

/** \brief Read 16bit data 'Value' variable and update 'Buffer' Array, where
*          Array is output parameter
*          and value is input parameter. */
#define UPDATEU16(Ppui1Buffer, Pui2Value) {\
                      *(uint8_t*)Ppui1Buffer = (uint8_t)((Pui2Value >> 8) & 0x00FF);\
                      *(uint8_t*)(Ppui1Buffer + 1) = (uint8_t)(Pui2Value);}

/** \brief Read 32bit data 'Value' variable and update 'Buffer' Array, where
*          Array is output parameter
*          and value is input parameter. */
#define UPDATEU32(Ppui1Buffer, Pui4Value) {\
                      *(uint8_t*)Ppui1Buffer = (uint8_t)((Pui4Value >> 24) & 0xFF);\
                      *(uint8_t*)(Ppui1Buffer + 1) = (uint8_t)((Pui4Value >> 16) & 0xFF);\
                      *(uint8_t*)(Ppui1Buffer + 2) = (uint8_t)((Pui4Value >> 8) & 0xFF);\
                      *(uint8_t*)(Ppui1Buffer + 3) = (uint8_t)(Pui4Value);}

/** \brief Indicates function parameter direction as input. */
#define _in_

/** \brief Indicates function parameter direction as output. */
#define _out_

/** \brief Indicates function parameter direction as input and output. */
#define _inout_


/**
* **Table 4-2: API Result Code Constants**
*/

/** \brief Successful execution of the function. */
#define UICC_NO_ERROR               0

/** \brief Error in function argument. */
#define UICC_ARGUMENT_ERROR         1

/** \brief Invalid device number given as input. */
#define UICC_INVALID_DEVICE_NBR     2

/** \brief Input buffer provided is too small for the data to be returned by the function. */
#define UICC_TOO_SMALL_BUFFER       3

/** \brief Unsupported type given as input. */
#define UICC_UNSUPPORTED_TYPE       4

/** \brief Invalid type given as input. */
#define UICC_INVALID_TYPE           5

/** \brief Invalid context given as input. */
#define UICC_INVALID_CONTEXT        6

/** \brief Unsupported operation given as input. */
#define UICC_UNSUPPORTED_OPERATION  7

/** \brief Invalid operation given as input. */
#define UICC_INVALID_OPERATION      8

/** \brief Maximum number of allowed sessions already in use for the UICC device linked to the 
*          UICC context provided as input. */
#define UICC_MAX_SESSIONS_REACHED   9

/** \brief Function is not supported by the UICC device. */
#define UICC_UNSUPPORTED_FUNCTION   10

/** \brief Not enough memory is available for the function to complete its operation. */
#define UICC_NOT_ENOUGH_MEMORY      11

/** \brief During 3GPP AKA authentication, error in verifying the MAC contained in AUTN. */
#define UICC_AKA_MAC_ERROR          12

/** \brief Synchronization error in 3GPP AKA authentication. */
#define UICC_AKA_SYNC_ERROR         13

/** \brief File is not found. */
#define UICC_FILE_NOT_FOUND         14

/** \brief Invalid file. */
#define UICC_INVALID_FILE           15

/** \brief Invalid transaction identifier. The transaction identifier identifies a profile
*          download and installation transaction (see [SGP.22]). */
#define UICC_INVALID_TRANS_ID       16

/** \brief Invalid object identifier. The object identifier does not match the already
*          stored object identifier for the ongoing transaction (see [SGP.22]). */
#define UICC_INVALID_OID            17

/** \brief The challenge in the provided data structure does not match the challenge
*          returned in UICC_InitiateAuthentication (see [SGP.22]). */
#define UICC_CHALLENGE_MISMATCH     18

/** \brief A certificate in the provided data structure is invalid (see [SGP.22]). */
#define UICC_INVALID_CERTIFICATE    19

/** \brief The elliptic curve in the provided data structure is not supported (see [SGP.22]). */
#define UICC_UNSUPPORTED_CURVE      20

/** \brief The requested Certificate issuer Public Key Identifier is not known/supported
*          (see [SGP.22]). */
#define UICC_UNSUPPORTED_CIPKID     21

/** \brief No GSMA RSP session context, i.e. no ongoing authentication/profile download
*          session (see [SGP.22]). */
#define UICC_NO_RSP_SESSION_CONTEXT 22

/** \brief The provided data structure contains an invalid signature (see [SGP.22]). */
#define UICC_INVALID_SIGNATURE      23

/** \brief The provided data structure contains incorrect input values (see [SGP.22]). */
#define UICC_INCORRECT_INPUT_VALUES 24

/** \brief The remote operation type in the provided data structure is not supported
*        (see [SGP.22]). */
#define UICC_UNSUPPORTED_REMOTE_OPERATION_TYPE  25

/** \brief The Control Reference Template (CRT) values in the provided data structure
*          are not supported (see [SGP.22]). */
#define UICC_UNSUPPORTED_CRT_VALUES 26

/** \brief The ICCID of the provided profile package already exists (see [SGP.22]). */
#define UICC_ICCID_ALREADY_EXISTS   27

/** \brief Profile installation failed because Profile Policy Rule (PPR) is not
*          allowed according to UICC Rules Authorization Table (RAT) (see [SGP.22]). */
#define UICC_INSTALL_FAILED_PPR_NOT_ALLOWED 28

/** \brief Profile installation failed due to data mismatch in provided profile
*          elements (see [SGP.22]). */
#define UICC_INSTALL_FAILED_DATA_MISMATCH   29

/** \brief Profile installation failed due to insufficient memory (see [SGP.22]). */
#define UICC_INSTALL_FAILED_INSUFFICIENT_MEMORY 30

/** \brief Profile installation was interrupted (see [SGP.22]). */
#define UICC_INSTALL_INTERRUPTED    31

/** \brief Profile installation failed due to Profile Element (PE) processing
*          error (see [SGP.22]). */
#define UICC_INSTALL_FAILED_PE_PROCESSING_ERROR 32

/** \brief Profile installation failed due to invalid Network Access Application
*          (NAA) key (see [SGP.22]). */
#define UICC_INSTALL_FAILED_INVALID_NAA_KEY     33

/** \brief The profile class of the provided profile is not supported (see [SGP.22]). */
#define UICC_UNSUPPORTED_PROFILE_CLASS          34

/** \brief SCP03T structural error (see [SGP.22]). */
#define UICC_SCP03T_STRUCT_ERROR  35

/** \brief SCP03T security error (see [SGP.22]). */
#define UICC_SCP03T_SEC_ERROR     36

/** \brief Nothing to delete matching the provided input parameters (see [SGP.22]). */
#define UICC_NOTHING_TO_DELETE    37

/** \brief Error due to UICC is busy (see [SGP.22]). */
#define UICC_ERROR_BUSY           38

/** \brief No profile could be found that matches the ICCID or ISD-P AID given
*          as input (see [SGP.22]). */
#define UICC_ICCID_OR_AID_NOT_FOUND 39

/** \brief The selected profile is not disabled, which prevents the requested
*          operation (see [SGP.22]). */
#define UICC_PROFILE_NOT_DISABLED   40

/** \brief The selected profile is not enabled, which prevents the requested
*          operation (see [SGP.22]). */
#define UICC_PROFILE_NOT_ENABLED    41

/** \brief The requested operation is not allowed according to Profile Policy
*          Rules (see [SGP.22]). */
#define UICC_NOT_ALLOWED_BY_POLICY  42

/** \brief The requested enable operation is blocked because the currently
*          enabled profile A (e.g. a test profile) forces a previously enabled
*          profile B to be re-enabled, and the selected profile is not the previously
*          enabled profile B (see [SGP.22]). */
#define UICC_WRONG_PROFILE_REENABLE 43

/** \brief The conditions of use are not satisfied. */
#define UICC_UNSATISFIED_CONDITIONS 44

/* Reserved:  45 - 99 Reserved for future GlobalPlatform use */

/** \brief Profile download and installation completed successfully. */
#define UICC_LOAD_PROFILE_COMPLETED 100

/* Reserved: 101 - 126 Reserved for future GlobalPlatform use */

/** \brief Undefined error. */
#define UICC_UNDEFINED_ERROR        127

/* Reserved: 128 - 255 Reserved for implementation-specific use */
/* Reserved: 256 - 65535 Reserved for future GlobalPlatform use */


/**
 * @typedef UICC_Result_t
 * \brief Contains the result of invoking a UICC API function.
 */
typedef uint32_t UICC_Result_t;

/**
 * @struct UICC_Buffer_t
 * \brief Defines a data buffer.
 */
typedef struct {
    uint8_t *p; /*!< Pointer to the first byte of the buffer. */
  
    size_t len; /*!< Denotes the number of bytes with valid data in the buffer. */
  
    size_t allocated; /*!< Denotes the number of bytes that have been allocated
                      for the buffer. */
} UICC_Buffer_t;


/**
 * @struct Modem_Info_t
 * \brief Denotes modem information.
 */
typedef struct
{ 
    char *portName_p;   /*!< Serial port name. */

    char *modelName_p;  /*!< Modem model name. */

    char *imei_p;       /*!< International Mobile Equipment Identity (IMEI). */

} Modem_Info_t;


/**
 * @struct Modem_List_t
 * \brief Denotes a list of modems.
 */
typedef struct
{
    size_t numModems;  /*!< Number of modems in the array. */

    Modem_Info_t *modems;  /*!< An array of modems. */

} Modem_List_t;


/**
 * @typedef Modem_Handle_t
 * \brief Denotes a modem handle.
 */
typedef void* Modem_Handle_t;

#ifdef __cplusplus
}
#endif

#endif /*SOURCE_CY_UICC_COMMON_DATA_H_ */
