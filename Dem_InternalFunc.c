/*******************************************************************************
**                               QORIX GmbH                                   **
**                                                                            **
** QORIX GmbH owns all the rights to this work. This work shall not be copied,**
** reproduced, used, modified or its information disclosed without the prior  **
** written authorization of QORIX GmbH.                                       **
**                                                                            **
** SRC-MODULE: Dem_InternalFunc.c                                             **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostics Event Manager Module                      **
**                                                                            **
**  PURPOSE   : Provision of getting data from external or internal Dem itself**
**              and maintaining event memory.                                 **
**                                                                            **
** PLATFORM DEPENDANT : No                                                    **
**                                                                            **
** TO BE CHANGED BY USER : No                                                 **
**                                                                            **
** Design ID : DEM_SDD_XXXX                                                   **
*******************************************************************************/
/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Date                Changed By                  Description                **
********************************************************************************
** 19-Jan-2026         Soniya M                  Updated code for Bug#20895   ** 
** 04-Dec-2025         Soniya M                  Updated code for ClearDTC    **
**                                               CP#9281 and SyncUp Bug#10387 **
** 11-Nov-2025         Soniya M                   Updated Code for ObdRelevance*
**                                                Feature                     **
** 06-Oct-2025	       Soniya M                   Updated Code for PB Impl for**
**                                                debouncing                  **
** 05-Sept-2025	       Soniya M                   Updated Code for Nvm        **
**                                                optimization, Tested Cycle  **
**                                                and Affected By control DTC **
**                                                Setting Feature             **
** 22-Jul-2025	       Soniya M                   Initial version             **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                   Parasoft violations Section                              **
*******************************************************************************/
/** 
#section Dem_InternalFunc_c_REF_1
Violates MISRAC2012-RULE_20_1-a-4: Do not precede the #include directive 
with executable code
Justification: This violation is not fixed since the inclusion of MemMap.h is as per AUTOSAR requirement SWS_MemMap_00003.
**/

/** 
#section Dem_InternalFunc_c_REF_2
Violates MISRAC2012-RULE_1_1-b-2: More than 31 initial
characters in an external identifier: ''
Justification: As macros are defined by AUTOSAR standards and internal specifications 
the length of name shall not be restricted. 
**/

/** 
#section Dem_InternalFunc_c_REF_3
Violates MISRAC2012-RULE_1_1-a-2: More than 31 initial characters in an internal identifier: ''
Justification: As macros are defined by AUTOSAR standards and internal specifications 
the length of name shall not be restricted. 
**/

/** 
#section Dem_InternalFunc_c_REF_4
Violates MISRAC2012-DIR_4_4-b-4: Section of code should not be 'commented out'
Justification: As no executable code is commented out. Therefore, this violation is accepted and documented.
**/

/** 
#section Dem_InternalFunc_c_REF_5
Violates CERT_C-DCL19-a-3: Variable "" should be declared as locally as possible
Justification: Coding guidelines suggest the variables are declared on the start of the 
function. Therefore, this violation is accepted and documented.
**/

/** 
#section Dem_InternalFunc_c_REF_6
Violates MISRAC2012-RULE_5_4-c-2: The '' macro has the same name (or the first 31 characters of the name) as the '' macro previously defined in the current file
Justification: As macros are defined by AUTOSAR standards and internal
* specifications the length of name shall not be restricted 
**/

/** 
#section Dem_InternalFunc_c_REF_7
Violates MISRAC2012-RULE_1_1-c-2: More than 31 initial characters in a macro name
Justification: As macros are defined by AUTOSAR standards and internal specifications the 
length of name shall not be restricted. 
**/

/** 
#section Dem_InternalFunc_c_REF_9
Violates CERT_C-DCL00-b-3: Declare parameter '' as const.
Justification: The standard AUTOSAR interface provided cannot be modified to include
the 'const' qualifier. Therefore, this violation is accepted and documented.
**/

/** 
#section Dem_InternalFunc_c_REF_10
Violates CERT_C-API00-a-3: Parameter "" is not validated before use.
Justification: Input prameter to the call already vaildated once in the sequence.
**/


/** 
#section Dem_InternalFunc_c_REF_11
Violates CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 
MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2: Possibly accessing array "" out of bounds at index [0...65534]. Correct index(es): [0...18]
Justification: The Boundaries are validated in another function. Verified manually so it can be suppressed.
**/

/** 
#section Dem_InternalFunc_c_REF_12
Violates CERT_C-MSC12-j-3: Condition "(unsigned int)LucDataElement != 9 LucDataElement != 160 LucDataElement != 176" always evaluates to true and Condition "DTCGroup != LulCurrentDtc" always evaluates to false
Justification: This Generated Value depends upon configuration. The value can be altered in other configurations where it satisfies the other condition, this violation is accepted and documented.
**/

/** 
#section Dem_InternalFunc_c_REF_13
Violates CERT_C-EXP08-a-2 CERT_C-ARR39-b-2: Do not apply pointer arithmetic to pointer
Justification: Pointer addition is required to read data from
specific location. This part of code is manually verified , it has no side-effect.
**/

/** 
#section Dem_InternalFunc_c_REF_14
Violates CERT_C-POS54-a-1: The value returned by the POSIX library function
'memset' should be used Even though the Function is having Void return
type parasoft is asking to use its return type.
**/

/** 
* #section Dem_InternalFunc_c_REF_15
* Violates MISRAC2012-RULE_5_4-d-2: The '' macro has the same name (or the first
* 31 characters of the name) as the '' macro previously defined in the current
* file
* Justification: As macros are defined by AUTOSAR standards and internal
* specifications the length of name shall not be restricted
**/

/** 
* #section Dem_InternalFunc_c_REF_16
* Violates MISRAC2012-RULE_20_9-b-2: The '' macro has the same name (or the first
* 31 characters of the name) as the '' macro previously defined in the current
* file
* Justification: This warning is generated due to undefined MACRO was being used in statement. As per && * operation property, once the first conditions fails it never validates the next condition. So, the *    macro will  not be used before definition. This can be ignored.
**/

/** 
* #section Dem_InternalFunc_c_REF_17
* Violates MISRAC2012-RULE_20_9-b-2: The '' macro has the same name (or the first
* 31 characters of the name) as the '' macro previously defined in the current
* file
* Justification: This warning is generated due to undefined MACRO was being used in statement. As per && * operation property, once the first conditions fails it never validates the next condition. So, the *    macro will  not be used before definition. This can be ignored.
**/

/**
* #section Dem_InternalFunc_c_REF_18
* Violates MISRAC2012-RULE_18_4-a-4: The variable '' used as the left hand side 
* operand of the '+' operator has a pointer type
* Justification: Pointer arithmetic is applied only within defined bounds and 
* fully controlled to access the specific data element from the given address. 
* Functionally correct.
**/

/**
* #section Dem_InternalFunc_c_REF_19
* Violates CERT_C-EXP14-a-3 CERT_C-INT02-b-2: Different types of operands: LHS type 'long', RHS type 'char'
* Justification: Data types for operand is same 
* at both side of operator but tool does not take type casting  
* type casting with bitwise and shift operators.
**/

/**
* #section Dem_InternalFunc_c_REF_20
* Violates MISRAC2012-RULE_17_8-a-4: Parameter is modified in function
* Justification: The input non constant argument is incremented to avoid
* use of another local variable, This doesnot impact functionality.
**/

/**
* #section Dem_InternalFunc_c_REF_21
* Violates MISRAC2012-RULE_8_13-a-4: Pass parameter "" with const specifier
* Justification: Since the function parameters that are pointers to values of standard API are
* provided by AUTOSAR specifications, it cannot be modified.
* It does not impact the module funtionality and hence this violation is suppressed.
**/

/** 
#section Dem_InternalFunc_c_REF_22
Violates MISRAC2012-RULE_14_3-ac-2: Condition "DTCGroup != LulCurrentDtc" always evaluates to false
Justification: This Generated Value depends upon configuration. The value can be altered in other configurations where it satisfies the false condition, this violation is accepted and documented.
**/

/**
* #section Dem_InternalFunc_c_REF_23
* Violates CERT_C-EXP14-a-3 CERT_C-INT02-b-2: Different types of operands: LHS type 'long', RHS type 'char'
* Justification: Data types for operand is same 
* at both side of operator but tool does not take type casting  
* type casting with bitwise and shift operators.
*
* #section Dem_InternalFunc_c_REF_24
* Violates CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2:The left-hand-side operand of bitwise operator '|' should be unsigned,
* The right-hand-side operand of bitwise operator '&' should be unsigned
* Justification: Data types for operand is same at both side of operator but tool 
* does not take type casting with bitwise and shift operators. Same as 2100 previously approved.
* 
* #section Dem_InternalFunc_c_REF_25
* Violates MISRAC2012-RULE_8_7-a-4: The object '' is referenced only in the translation unit where it is defined.
* Justification:  The deviation is applicable in case fo generated files . The extenal linnkage and their use is depednent on the generation and cannot be taken care in the static code hence the deviation.
*
#section Dem_InternalFunc_c_REF_26
Violates CDD-DUPC-3: Duplicated code: 'LucClientId =
Justification: This is not a duplicate code it is fetching the value of structure member in different functions.
Hence, this violation is accepted and documented.
**/

/** 
* #section Dem_InternalFunc_c_REF_27
* Violates CERT_C-DCL13-a-3: Declare parameter '' as const.
* Justification: The function argument is not used in the current function, but inturn passed
to another function to retrieve data. Hence the argument is still used as
pointer to variable instead of pointer to constant. It can be suppressed and
hence does'nt have impact on functionality.
*
* #section Dem_InternalFunc_c_REF_25
* Violates CERT_C-MEM04-a-2: Values "LpEventMemory, LucEntriesInMemory" passed to library function "memcpy" without being checked
* Justification:  Values are validated in the public API, then internal functions need not validate if the data would not change.
*
* #section Dem_InternalFunc_c_REF_26
* Violates CERT_C-EXP33-a-1 MISRAC2012-RULE_9_1-a-1 MISRAC2012-RULE_1_3-b-2: Non-Initialized Local Variable
* Local variable LflLogValue, LflHeightInMeter and LusHeightInFeet is  
* initialized already before using.
* Polyspace_End : Dem_ObdEvtProcsg_c_Poly_REF_4
**/
/** 
#section Dem_InternalFunc_c_REF_27
Violates CERT_C-INT02-a-2: Implicit conversion from 'unsigned long' type to 'unsigned int' type in function's argument
Justification: Verified Manually and then this violation is accepted and documented.
**/

/** 
#section Dem_InternalFunc_c_REF_28
Violates CERT_C-MEM07-a-2: Values "Dem_GpConfigPtr, pEventPreCondition" passed to library function "memcpy" without being checked
Justification: Validate the argument values or memory values before accessing in any of the hierachy of callstack (ie, if the values are validated in the public API, then internal functions need not validate if the data would not change)
**/

/** 
#section Dem_InternalFunc_c_REF_29
Violates CERT_C-MSC12-j-3 MISRAC2012-RULE_14_3-ac-2: Condition "1 == (unsigned int)LucClientFunctionality" always evaluates to true
Justification: This Generated Value depends upon configuration. The value can be altered in other configurations where it satisfies the false condition, this violation is accepted and documented.
**/

/**
* #section Dem_InternalFunc_c_REF_30
* Violates CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2: Possibly accessing array "" out of bounds at index [0...65534]. Correct index(es): [0...18]
* Justification: The Boundaries are validated in another function. Verified manually so it can be suppressed.
**/

/* parasoft-begin-suppress MISRAC2012-RULE_20_1-a-4 
"Reason: Dem_InternalFunc_c_REF_1" */

/* parasoft-begin-suppress MISRAC2012-RULE_5_4-d-2 
"Reason: Dem_InternalFunc_c_REF_15" */

/* parasoft-begin-suppress MISRAC2012-RULE_5_4-c-2 
"Reason: Dem_InternalFunc_c_REF_6" */

/* parasoft-begin-suppress MISRAC2012-RULE_1_1-c-2
"Reason: Dem_InternalFunc_c_REF_7" */

/* parasoft-begin-suppress MISRAC2012-RULE_1_1-b-2
"Reason: Dem_InternalFunc_c_REF_2" */

/* parasoft-begin-suppress MISRAC2012-RULE_1_1-a-2
  "Reason: Dem_InternalFunc_c_REF_3" */
  
/* parasoft-begin-suppress MISRAC2012-DIR_4_4-b-4 
"Refer Dem_InternalFunc_c_REF_4" */

/* parasoft-begin-suppress CERT_C-DCL19-a-3 
"Reason: Dem_InternalFunc_c_REF_5" */

/* parasoft-begin-suppress CERT_C-EXP08-a-2 CERT_C-ARR39-b-2
"Reason: Dem_InternalFunc_c_REF_13" */

/* parasoft-begin-suppress MISRAC2012-RULE_18_4-a-4
"Reason: Dem_InternalFunc_c_REF_18" */

/*******************************************************************************
**                   MISRA-C:2012 violations Section                          **
*******************************************************************************/

/**
* #page misra_violations MISRA-C:2012 violations
*
* #section Dem_InternalFunc_c_REF_QAC_1
* Violates MISRA 2012 Advisory Rule 20.1. This statement has no side-effect.
* #include statements in a file should only be preceded by other
* preprocessor directives or comments.
*
* #section Dem_InternalFunc_c_REF_QAC_2
* Violates MISRA 2012 Required Rule 8.13. This part of code has verified
* manually and has no side-effect.
* This function parameter is a pointer which is never used to modify the data
* which it addresses. In other words, it is an "input" parameter. It would
* therefore improve clarity to declare it as a pointer to a const qualified
* type
*
* #section Dem_InternalFunc_c_REF_QAC_3
* Violates MISRA 2012 Advisory Rule 18.4. This statement has no side-effect.
* An addition or subtraction operation is being performed on an expression of
* pointer type.
*
* #section Dem_InternalFunc_c_REF_QAC_8
* Violates MISRA 2012 Required Rule 2.2. This statement has no side-effect.
* All non-null statements shall either (i) have at least one side-effect
* however executed, or (ii) cause control flow to change.
*
* #section Dem_InternalFunc_c_REF_QAC_9
* Violates MISRA 2012 Message Number 0491. This part of code has verified
* manually and has no side-effect.
* The Array subscripting applied to an object of pointer type.
*
* #section Dem_InternalFunc_c_REF_QAC_10
* Violates MISRA 2012 Message Number 0715. This part of code has verified
* manually and has no side-effect.
*
* #section Dem_InternalFunc_c_REF_QAC_11
* Violates MISRA 2012 Message Number 0489, 0491. This part of code has verified
* manually and has no side-effect.
* The integer value 1 is being added or subtracted from a pointer.
* The Array subscripting applied to an object of pointer type.
*
* #section Dem_InternalFunc_c_REF_QAC_12
* Violates MISRA 2012 Required DIR 1.1, Message Number 0380.
* The included and defined macros values exceed 4095 count.
* This macors are part of AUTOSAR Specific defintions for inclusion of
* memory map files for Code and Global data secions and configuration Specific
* macros present in Cfg.h files
* This part of code has verified manually and also tested in Different Platforms
* and has no side-effect.
*
* #section Dem_InternalFunc_c_REF_QAC_14
* Violates MISRA 2012 Required Rule-17.8, Message Number 1338
* The value of a function parameter is being modified.
* In the code, function parameter has declared with appropriate data type and
* modifying a parameter will not have any observable 
* effects on values in the calling scope
* This part of code has verified  manually.
*
* #section Dem_InternalFunc_c_REF_QAC_15
* Violates MISRA 2012 Required DIR 5.4, Message Number 0791.
* Macro identifier does not differ from other macro identifiers
* within the specified number of significant characters.
* As per AUTOSAR standard, Memory sections for variables are specified  
* to be in the format as given in the code , Hence this statement has no side
* effect.
*
* #section Dem_InternalFunc_c_REF_QAC_16
* Violates MISRA 2012 Required Rule-8.13, Message Number 3678.
* This variable is a pointer or array which is never used to modify 
* the data which it addresses or contains, but is not const-qualified.
* In this part of code, pointer is pointed to variable whose value get 
* changed under certain condition . hence it can't be CONST.
*
* #section Dem_InternalFunc_c_REF_QAC_17
* Violates MISRA 2012 Required MSC07, Message 1503.
* These module APIs are standard AUTOSAR services which will be called by application or other dependent BSW modules.
* Hence these warning is suppressed as it does not impact the module functionality.
*
* #section Dem_InternalFunc_c_REF_QAC_18
* Violates MISRA 2012 Required DCL00, Message 3227.
* The parameter '%1s' is never modified and so it could be declared with 
* the 'const' qualifier..
* The arguments of stanadard APIs are as per AUTOSAR. Hence data type can't be
* modified also it is manually verified , it has no side-effect.
*
* #section Dem_InternalFunc_c_REF_19
* Violates MISRA 2012 Advisory Rule 2.5, Message Number 1534.
* This part of code has verified manually and it has no side-effect
*
* #section Dem_InternalFunc_c_REF_20
* Violates MISRA 2012 Required INT02, Message 1251.
* ''uint8' and 'uin16' are standard AUTOSAR types (Annexure A. 2 of of AUTOSAR_SWS_PlatformTypes.pdf)
* mapped to 'unsigned char' and 'unsigned short' respectively.The operations perfomed
* on this types are to fulfill the module functionality and hence the integral promotion of these types is unavoidable. 
* Hence these warning is suppressed as it does not impact the module funtionality.
*
* #section Dem_InternalFunc_c_REF_21
* Violates MISRA 2012 Required INT02, Message 2101.
* ''uint8' and 'uin16' are standard AUTOSAR types (Annexure A. 2 of of AUTOSAR_SWS_PlatformTypes.pdf)
* mapped to 'unsigned char' and 'unsigned short' respectively.The operations perfomed
* on this types are to fulfill the module functionality and hence the integral promotion of these types is unavoidable.
* Hence these warning is suppressed as it does not impact the module funtionality.
*
* #section Dem_InternalFunc_c_REF_22
* Violates MISRA 2012 Required INT02, Message 2100.
* ''uint8' and 'uin16' are standard AUTOSAR types (Annexure A. 2 of of AUTOSAR_SWS_PlatformTypes.pdf)
* mapped to 'unsigned char' and 'unsigned short' respectively.The operations perfomed
* on this types are to fulfill the module functionality and hence the integral promotion of these types is unavoidable.
* Hence these warning is suppressed as it does not impact the module funtionality.
*
* #section Dem_InternalFunc_c_REF_23
* Violates MISRA 2012 Required Rule 10.1, Message Number 2000.
* In the case of a simple if statement then the else statement need not be included,
* since it shall increase the code complexity of function. 
* Hence this warning is suppressed as it does not impact the module functionality.
*
* #section Dem_InternalFunc_c_REF_24
* Violates MISRA 2012 Required INT02, Message 1252.
* This part of code macro is defined in Other file and tool unable to recognzie,So mannually verified.
*
* #section Dem_InternalFunc_c_REF_25
* Violates MISRA 2012 Required Rule INT02, Message Number 2104.
* In this part of code both the operands haveing same datatype, and there is no 
* sign char promoted to signed int.
* Its manually verified and it has no side-effect.
*
* #section Dem_InternalFunc_c_REF_26
* Violates MISRA 2012 Required Rule STR34, Message Number 2144.
* In this part of code the operands haveing same datatype ,its manually verified and it has no side-effect
*
* #section Dem_InternalFunc_c_REF_27
* Violates MISRA 2012 Required Rule INT30, Message Number 3383.
* This part of code has verified manually and the operand is not crossing its limit.
*
* #section Dem_InternalFunc_c_REF_28
* Violates MISRA 2012 Required CERTCCM 2.1.0, Message Number 5001.
* Since these header file names have been derived through AUTOSAR
* Specifications and KPIT Coding Guidelines, these violations is 
* suppressed as it does not impact the module functionality
* This part of code has verified manually and it has no side-effect.
*
* #section Dem_InternalFunc_c_REF_QAC_29
* Violates MISRA 2012 Required Rule-10.3, Message Number 1291
* 'uint8' and 'uin16' are standard AUTOSAR types (Annexure A. 2 of of
* AUTOSAR_SWS_PlatformTypes.pdf) mapped to 'essentially unsigned' type is being converted
 to 'signed type' on assignment respectively.The operations perfomed on this types are to fulfill
* the module functionality and hence the integral promotion of these types
* is unavoidable. Hence these warning is suppressed as it does not impact
* the module funtionality.
*
* #section Dem_InternalFunc_c_REF_QAC_30
* Violates MISRA 2012 Required Rule INT30, Message Number 3384.
* This part of code has verified manually and the operand is not crossing its limit.
*
* #section Dem_InternalFunc_c_REF_QAC_31
* Violates MISRA 2012 Required DCL13, Message 3673.
* The reference parameter  is never modified and so it could be declared with 
* the 'const' qualifier..
* The arguments of stanadard APIs are as per AUTOSAR. Hence data type can't be
* modified also it is manually verified , it has no side-effect.
*
* #section Dem_InternalFunc_c_REF_32
* Violates MISRA 2012 Required qac-10.1.0, Message Number 2109.
* Boolean is standard AUTOSAR types. 
* (Annexure A. 2 of of AUTOSAR_SWS_PlatformTypes.pdf) mapped to _bool 
* respectively. The operations perfomed on this types are to fulfill the module 
* functionality and hence the integral promotion of these types is unavoidable. 
* Hence these warning is suppressed as it does not impact the module 
* funtionality.
**/

/*******************************************************************************
**                   CERT violations Section                                  **
*******************************************************************************/
/**
* #section Dem_InternalFunc_c_CERT_REF_1
* Violates MISRA 2012 Required CERTCCM 2.1.0, Message Number 5002.
* The header '%s' file name shadows a previously included header.
* This part of code has verified manually and it has no side-effect.
*
* #section Dem_InternalFunc_c_CERT_REF_2
* Violates MISRA 2012 Required CERTCCM 2.1.0, Message Number 5001.
* Since these header file names have been derived through AUTOSAR
* Specifications and KPIT Coding Guidelines, these violations is 
* suppressed as it does not impact the module functionality
* This part of code has verified manually and it has no side-effect.
**/
/*******************************************************************************
**                      PolySpace violations Section                          **
*******************************************************************************/
/**
*
* #page PolySpace violations
*
* #section Dem_c_Poly_REF_2
* Polyspace_Start : Dem_c_Poly_REF_2
* Out of Bound Array Index
* Array index for 1)Dem_GaaAllFDC 2)Dem_GaaAllEvtStatus 3)Dem_GaaDTCAttributes
* 4)Dem_GaaMatchingDtcIndex 5)Dem_GaaOperationCycleIdsList 
* 6)Dem_GaaEventParameter 7)Dem_GaaEDRecord 8)Dem_GaaPrestoreBuffer 
* 9)Dem_GaaDataElementExternalCS 10)Dem_GaaDataElementExternalSR 
* 11)Dem_GaaDTCOriginMappingIndx 12)Dem_GaaOriginFilter 
* 13)Dem_GaaSuppressionStatus 14)Dem_GaaMemoryIndexForEvt 
* 15)Dem_GaaMatchingDtcIndex16)Dem_GaaAllDtcStatus 17)Dem_GaaDtcMainEvent 
* 18)Dem_GaaDTCAttributes 19)Dem_GaaIntDebounceTimer 20)Dem_GaaEDRecord 
* 21)Dem_GaaEDRecordNumberList will not
*  be out of bound since value is configurable and it is handled in generation.
*
* Polyspace_End : Dem_c_Poly_REF_2
**/
/**
* #page PolySpace violations
*
* #section Dem_c_Poly_REF_4
* Illegally Dereferenced Pointer
* Polyspace_Start : Dem_c_Poly_REF_4
* As this part of code is verified manually for 1)LpDTCVal 2)LpEventMemory
* 3)LpCurrentBufferIndex 4)pEventMemory 5)LpDTCAttribute
* 6)pInternalDataElement 7)LpDestBuffer 8)LpNvMemBlockIndex
* 9)LpTailNodeFoundStatusFlag. It will not be outside bound and no effect
* on functionality.
* Polyspace_End : Dem_c_Poly_REF_4
*
**/
/**
* #page PolySpace violations
*
* #section Dem_c_Poly_REF_5
* Polyspace_Start : Dem_c_Poly_REF_5
* Non-Initialized Local Variable
* Local variable 1)LucCount 2)LucEntryCnt 3)LucEventMemoryIndex 4)LucMemEntries,
* LucTailNodeIndx is initialized already.
* Polyspace_End : Dem_c_Poly_REF_5
*
**/
/**
* #page PolySpace violations
*
* #section Dem_c_Poly_REF_6
* Polyspace_Start : Dem_c_Poly_REF_6
* Overflow
* The function is required to get roudoff value of float type variable LpValue.
* The type conversion is used for same & this code doesnot have any side effect.
* Polyspace_End : Dem_c_Poly_REF_6
*
**/
/**
* #page PolySpace violations
*
* #section Dem_c_Poly_REF_8
* Polyspace_Start : Dem_c_Poly_REF_8
* Non-Initialized  Variable
* variable 1)Dem_GaaEventParameter 2)Dem_GaaAllEvtStatus 3)LucUsMemIndex 
* 4)LucCount 5)LusEventParameterIndex 6)LaaPassEvtId 7)LucHeadNodeIndx
* 8)LpIndex is initialised in function before using.
* Polyspace_End : Dem_c_Poly_REF_8
*
**/
/**
*
* #page polyspace_justifications
*
* #section Dem_InternalFunc_c_Poly_REF_1
* Unreachable Code
* Polyspace_Start : Dem_c_Poly_REF_8
* The Polyspace tool doesnt pass the function arguments to cover the given
* part of code and hence it is unreachable. However the same part
* of code is covered and tested using functional testing and unit
* testing and hence doesnt have impact on functionality.
* Polyspace_End : Dem_c_Poly_REF_8
**/
/**
*
* #page PolySpace violations
*
* #section Dem_InternalFunc_c_Cert_REF_1
* Polyspace_Start : Dem_InternalFunc_c_Cert_REF_1
* Cert C Rule : DCL15-C, DCL19-C
* The external linkage(extern declaration) of functions or variables is added to
* to avoid QAC violations related to missing external linkage and as well to
* reduce impact on code implementations when such functions or variables are
* used outside file scope.
* Polyspace_End : Dem_InternalFunc_c_Cert_REF_1
**/
/**
*
* #page PolySpace violations
*
* #section Dem_InternalFunc_c_Cert_REF_2
* Polyspace_Start : Dem_InternalFunc_c_Cert_REF_2
* Cert C Rule : MSC12-C
* Based on Configuration, the result of if condition may be either always true
* or always false. However the same part of code is covered and tested using
* functional testing and unit testing and hence doesnt have impact on
* functionality.
* Polyspace_End : Dem_InternalFunc_c_Cert_REF_2
**/
/**
*
* #page PolySpace violations
*
* #section Dem_InternalFunc_c_Cert_REF_3
* Polyspace_Start : Dem_InternalFunc_c_Cert_REF_3
* Cert C Rule : ARR30-C, EXP08-C
* Array index for Dem_GaaDTCOriginBasedPtrAddress will not be out of bound
* since the size of the array is configurable parameter and it is handled
* in generation.
* Polyspace_End : Dem_InternalFunc_c_Cert_REF_3
*
**/
/**
*
* #page PolySpace violations
*
* #section Dem_InternalFunc_c_Cert_REF_4
* Polyspace_Start : Dem_InternalFunc_c_Cert_REF_4
* Cert C Rule : DCL23-C
* The identifier 1)Dem_GetSizeOfEDRecordByDTCFoundInMem,
* 2)Dem_GetSizeOfExtendedDataRecordSelection and
* Dem_GetSizeOfExtendedDataRecordByDTCNotFoundInMem is unique, but has same
* set of initial 31 characters is used. The initial set of characters defines
* common source functionality and last few characters defines actual
* functionality being executed in functionality.
* Polyspace_End : Dem_InternalFunc_c_Cert_REF_4
**/
/**
*
* #page PolySpace violations
*
* #section Dem_InternalFunc_c_Cert_REF_5
* Polyspace_Start : Dem_InternalFunc_c_Cert_REF_5
* Cert C Rule : DCL13-C
* The function argument is not used in the current function, but intern passed
* to another function to retrieve data. Hence the argument is still used as
* pointer to variable instead of pointer to constant.
* Polyspace_End : Dem_InternalFunc_c_Cert_REF_5
**/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*Design ID: DEM_SDD_5696, DEM_SDD_5720 */
#include "Dem_Memory.h" /* NVRAM manager symbols Header File */
#include "Rte_NvM_Type.h"
#include "Det.h"
#include "Rte_Dem.h"
#include "Dem_Externals.h"
/* #violates #ref Dem_InternalFunc_c_CERT_REF_2 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5001 1 */
#include "string.h"
#include "Dem_WwhObdProcsg.h"
#include "Dem_EvtProcsg.h"
#include "Dem_Error.h"
#include "Dem_StaticInlineFunc.h"            /* DEM module Header File */
#if (DEM_J1939_DTC_SUPPORT == STD_ON)
#include "Dem_J1939InternalFunc.h"
#endif
/*******************************************************************************
**                          Common Misra Suppression                          **
*******************************************************************************/
/* #violates #ref Dem_InternalFunc_c_REF_QAC_1 Violates MISRA 2012
   Required Rule 20.1 */
/* PRQA S 5087 EOF */

/* PRQA S 3383 EOF */

/* #violates #ref Dem_InternalFunc_c_REF_QAC_3 Violates MISRA 2012
   Required Rule 18.4 */
   /* PRQA S 0488 EOF */

/* #violates #ref Dem_InternalFunc_c_REF_QAC_12 Violates MISRA 2012
   Required Rule DIR 1.1 */
/* PRQA S 0380 EOF */

/* #violates #ref Dem_InternalFunc_c_REF_QAC_15 Violates MISRA 2012
   Required Rule DIR 5.4 */
/* PRQA S 0791 EOF */

/* #violates #ref Dem_InternalFunc_c_REF_QAC_17 Violates MISRA 2012
   Required Rule MSC07 */
/* PRQA S 1503 EOF */

/* #violates #ref Dem_InternalFunc_c_REF_QAC_18 Violates MISRA 2012 
   Required Rule DCL00 */
/* PRQA S 3227 EOF */

/* #violates #ref Dem_InternalFunc_c_REF_19 Violates MISRA 2012
Required Rule DIR 2.5 */
/* PRQA S 1534 EOF */

/* #violates #ref Dem_InternalFunc_c_REF_20 Violates MISRA 2012
   Required Rule INT02 */
/* PRQA S 1251 EOF */

/* #violates #ref Dem_InternalFunc_c_REF_21 Violates MISRA 2012
   Required Rule INT02 */
/* PRQA S 2101 EOF */

/* #violates #ref Dem_InternalFunc_c_REF_22 Violates MISRA 2012
   Required Rule INT02 */
/* PRQA S 2100 EOF */

/* #violates #ref Dem_InternalFunc_c_REF_23 Violates MISRA 2012
   Required Rule-10.1  */
/* PRQA S 2000 EOF */

/* #violates #ref Dem_InternalFunc_c_REF_28 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5001 1 */

/* #violates #ref Dem_InternalFunc_c_REF_32 Violates MISRA 2012 
   Required Rule qac-10.1.0 */
/* PRQA S 2109 EOF */

/*polyspace-begin RTE:UNR [Justified:Low]
                              "Refer Dem_InternalFunc_c_Poly_REF_1" */
/*polyspace-begin CERT-C:DCL15-C [Justified:Low] "Refer
     Dem_InternalFunc_c_Cert_REF_1" */
/*polyspace-begin CERT-C:DCL19-C [Justified:Low] "Refer
     Dem_InternalFunc_c_Cert_REF_1" */
/*polyspace-begin CERT-C:MSC12-C [Justified:Low] "Refer
     Dem_InternalFunc_c_Cert_REF_2" */
/*polyspace-begin CERT-C:ARR30-C [Justified:Low] "Refer
     Dem_InternalFunc_c_Cert_REF_3" */
/*polyspace-begin CERT-C:EXP08-C [Justified:Low] "Refer
     Dem_InternalFunc_c_Cert_REF_3" */
/*polyspace-begin CERT-C:DCL23-C [Justified:Low] "Refer
     Dem_InternalFunc_c_Cert_REF_4" */
/*polyspace-begin CERT-C:DCL13-C [Justified:Low] "Refer
     Dem_InternalFunc_c_Cert_REF_5" */
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

#if ((DEM_DTR_INTERNAL_DATAELEMENT == STD_ON) || \
       (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON) || \
       (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON) || \
       (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON))
static void Dem_ProcessIumprMonitorDtr(const uint8 LucDataElement, // parasoft-suppress CERT_C-API00-a-3 "Reason: Input prameter to the call already vaildated once in the sequence"
#if ((DEM_DTR_INTERNAL_DATAELEMENT == STD_ON) || (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON) || \
(DEM_J1939LAMP_STATUS_SUPPORT == STD_ON))
uint8*  LpCurrentBufferIndex, 
#endif
uint8 *DestBuffer, 
const uint16 LusEventParameterIndex);

static void  Dem_ProcessGetInternalIumprMonitorDtr(const uint8 LucDataElement, uint16* const LusDestBufferIndex,
     uint8*  LpDestBuffer, const uint16 LusEventParameterIndex );
#endif

#if ((DEM_DTR_INTERNAL_DATAELEMENT == STD_ON) || \
       (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON) || \
       (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON) || \
       (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON))
static Std_ReturnType  Dem_CheckInternaldateleForIumprMonitorActiDtr(const uint8 LucDataElement);
#endif

static void  Dem_ChkPndUpdateStatus(void);

#if ((DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO) || \
  (DEM_MAX_NUM_OF_DID_PER_WWHOBD_FF > DEM_ZERO))
#if (DEM_WWHOBD_FF_SUPPORT == STD_ON)
static void  Dem_ProcessUdsDataForWwhRecUpdateTrue(
  #if (DEM_MAX_NUMBER_PRESTORED_FF > DEM_ZERO)
  const uint8 LucCount, const boolean LblEntryFound,
  #endif
  Dem_WWHObdEventMemory*  LpWWHOBDEventMemory
  );
#endif
#endif	  

#if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO)
#if (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)
static Std_ReturnType 
Dem_GetInternalDataElement(const uint8 LucActualRecordIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
uint16*  LpBufSize, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
uint8*  LpDestBuffer, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
const uint16 LusEventParameterIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
const Dem_DTCAttributeType* const LpDTCAttribute, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
const Dem_DTCOriginType DTCOrigin, uint16* const LusDestBufIndx, const uint8 LucStoredIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
const uint8 LucDataElementIndex // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
  , uint8* const LpReadMonitorEDdataStack
   #endif
   );
   
static void Dem_GetInternalDataIfOccOrAging(const uint8 LucDataElement,
const Dem_DTCOriginType DTCOrigin, const uint16 LusDestBufferIndex, 
uint8*  LpDestBuffer,
const uint8 LucStoredIndex 
#if (DEM_AGING_CYCLE_CONFIGURED == STD_ON)
, const Dem_DTCAttributeType* const LpDTCAttribute
#endif
);
#endif
#endif

#if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
static Std_ReturnType  Dem_DTCFilterSearch(
  const uint16 LusDtcInfoIndex, const uint16 LusDTCOrgin, const uint8 LucClientId);
#endif

#if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
    (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO) && \
    (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO))
static Std_ReturnType Dem_EvaluateInternalExtendedDataRecord
(
   uint8 *DestBuffer, 
   const Dem_DTCAttributeType* const LpDTCAttribute, 
   uint8*  LpCurrentBufferIndex,    const uint8 LucDataElementIndex, 
   const uint16 LusEventParameterIndex, 
   const uint8 LucFreeIndex, 
   const uint8 LucRecIndex, boolean* const LblRecFound 
   , const Dem_DTCOriginType LucEventDestination 
   #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
  , uint8* const LpReadMonitorEDdataStack
   #endif
  ) ;
#endif

#if ((DEM_NVM_PRESENT == STD_ON) && \
     (DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) && \
     (DEM_ZERO < DEM_NUMBER_OF_DESTINAIONS_CONFIGURED))
static Std_ReturnType  Dem_ConsistencyChecks(void);
#endif

#if ((DEM_GROUPDTC_CONFIGURED == STD_ON) && \
(DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO))
#if (DEM_CLEAR_DTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS)
static Std_ReturnType  Dem_ProcessClearGroupDTC(void);
#endif
#endif

#if (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON)
#if (DEM_IUMPR_STATUS_HANDLING == DEM_IUMPR_GROUP_SPECIFIC)
static void  Dem_ProcessIntrlDataEleGroupDemIumpr(const uint16 LusEventParameterIndex, uint8* Buffer );
#endif
#endif        

#if (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON)
#if (DEM_IUMPR_STATUS_HANDLING == DEM_IUMPR_RATIO_SPECIFIC)
  static void  Dem_ProcessIntrlDataEleRatioDemIumpr(const uint16 LusEventParameterIndex, uint8* Buffer );
#endif
#endif

#if ((DEM_NVM_PRESENT == STD_ON) && \
     (DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) && \
     (DEM_ZERO < DEM_NUMBER_OF_DESTINAIONS_CONFIGURED) && \
     ((DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)))
static Std_ReturnType  Dem_ConsistencyChecksForValidNodeIndex(
  boolean* const LpHeadNodeFoundStatusFlag,
  boolean* const LpTailNodeFoundStatusFlag,
  const Dem_EventMemory*  LpEventMemory,
  const uint8 LucMemEntries, const uint8 LucEventMemIndex
  );
#endif

static void  Dem_InitNVData_Internal(void);

#if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
    (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
static Std_ReturnType  Dem_CheckExtendedDataRecord
  (const uint8 RecordNumber,  const uint8 LucServiceId, 
   uint8 *DestBuffer, uint16 *BufSize, 
   const Dem_EventMemory*  LpEventMemory, 
   const Dem_DTCAttributeType*  const LpDTCAttribute, 
   #if (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)
   const uint16 LusEventParameterIndex, 
   #endif
   const uint8 LucFreeIndex, const uint8 LucNumOfEDRecords, boolean* const LblRecFound // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   #if (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)
   , const Dem_DTCOriginType LucEventDestination 
   #endif
   );
#endif

#if ((DEM_MAX_NUMBER_OF_DTC > DEM_ZERO) && \
     (DEM_CLEAR_DTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS))
static Std_ReturnType  Dem_ProcessClearSingleDTC(void);
#endif

#if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
    (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO) && \
    (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO))
static void  Dem_ProcessEventMemoryDestination(const Dem_DTCOriginType LucEventDestination,
Dem_DTCOriginType* const LpDTCOrigin);
#endif

#if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
    (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
static void  Dem_GetSizeOfEDRecordForEvent(
   const uint8 LucFreeIndex, uint16* const LpBufSize, const uint8 ExtendedDataNumber,
   const Dem_EventMemory*  LpEventMemory);
#endif

#if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
    (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO) && \
    (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO))
static void  Dem_EvaluateInternalExtdDataRcdIfOccOrAging(
   const uint8 LucDataElement, const Dem_DTCOriginType LucEventDestination, 
   uint8*  LpCurrentBufferIndex, 
   const uint8 LucFreeIndex, 
   uint8 *DestBuffer 
   #if (DEM_AGING_CYCLE_CONFIGURED == STD_ON)
   , const Dem_DTCAttributeType* const LpDTCAttribute
   #endif
  );
#endif


#if (((DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_ON) || \
        (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT))  &&   \
      (DEM_EVENT_MEMORY_DESTINATION_CONFIGURED == STD_ON))
#if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
static Std_ReturnType  Dem_FilterEvent(
       const uint16 LusEventIndex, const uint8 LucClientId);
#endif
#endif

#if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO) && \
   (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)
#if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
static void 
Dem_GetMaxFdcOfDtc(uint8*  LpDestBuffer,
const uint16 LusEventParameterIndex);
#endif
#endif

#if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
    (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
static void  Dem_GetSizeOfRecNoFFandFE(const uint16 LusEventParameterIndex,
#if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
const uint8* const  LpSizeOfRecordCount,
#endif
uint16* const LpSizeOfExtendedDataRecord, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
const uint8 ExtendedDataNumber,
const Dem_EventMemory*  LpEventMemory);
#endif

#if (((DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_ON) || \
        (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT))  &&   \
      (DEM_EVENT_MEMORY_DESTINATION_CONFIGURED == STD_ON))
static void  Dem_WrapchkFiltrDtc (const uint8 LucClientId);
#endif

#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
static void  Dem_EndConv16(
       uint16* const LpDataElement, const uint8 LucSize);
static void  Dem_EndConv32(
       uint32* const LpDataElement, const uint8 LucSize);
#endif

#if ((DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)  && \
        (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL))
static void Dem_GetFFrecCount(
  const uint8* const LpStdInds,
  const uint8 LucNumOfEvt, uint16* const LpBufSize, const uint8 RecordNumber,
  const Dem_EventMemory*  LpEventMemory);
#endif

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#if (DEM_IUMPR_STATUS_HANDLING == DEM_IUMPR_RATIO_SPECIFIC)
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
STD_TYPES_CONST Dem_pIUMPRMappedRatioType 
Dem_GaaIUMPRRatio[DEM_TWENTY_ONE] = // parasoft-suppress MISRAC2012-RULE_8_7-a-4 "Refer: Dem_InternalFunc_c_REF_25"
{
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_AFRI1 > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaAfri1Ratios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_AFRI2 > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaAfri2Ratios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_BOOSTPRS > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaBoostPrRatios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_CAT1 > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaCat1Ratios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_CAT2 > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaCat2Ratios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_EGR > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaEgrRatios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_EGSENSOR > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaEgSensRatios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_EVAP > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaEvapRatios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_FLSYS > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaFlSysRatios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_NMHCCAT > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaNmHcCatRatios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_NOXADSORB > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaNoXAdsorbRatios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_NOXCAT > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaNoXCatRatios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_OXS1 > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaOxS1Ratios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_OXS2 > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaOxS2Ratios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
   #if (DEM_NUM_RATIOS_MAPPED_IUMPR_PF1 > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaPf1Ratios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_PF2 > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaPf2Ratios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_PMFILTER > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaPmFilterRatios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_PRIVATE > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaPrivateRatios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_SAIR > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaSAirRatios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_SECOXS1 > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaSecOxS1Ratios[DEM_ZERO],
  #else
  NULL_PTR,
  #endif
  #if (DEM_NUM_RATIOS_MAPPED_IUMPR_SECOXS2 > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  &Dem_GaaSecOxS2Ratios[DEM_ZERO]
  #else
  NULL_PTR
  #endif
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_DTCFilterSearch                                 **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : This internal function checks for the DTC matching  **
**                        the filter criteria.                                **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : LusDTCAttributeIndex, LusDTCOrgin                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_DTC should be greater than Zero   **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaDTCAttributes,         **
**                                              Dem_GaaCurDTCFilter,          **
**                                              Dem_GaaAllFDC,                **
**                                              Dem_GaaAllDtcStatus,          **
**                                              Dem_GaaCurDTCFilterStatusMask,**
**                                              Dem_GaaDTCFormat              **
**                        Function(s) invoked : None                          **
** Design ID            : DEM_SDD_0311                                        **
**                                                                            **
*******************************************************************************/
/* #violates #ref Dem_InternalFunc_c_REF_QAC_1 Violates MISRA 2012 Required Rule
   20.1 */
/* PRQA S 5087 EOF */
#if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* #violates #ref Dem_InternalFunc_c_CERT_REF_2 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5001 2 */
static Std_ReturnType  Dem_DTCFilterSearch(
  const uint16 LusDtcInfoIndex, const uint16 LusDTCOrgin, const uint8 LucClientId) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  const Dem_EventMemorySetType*  LpEventMemorySet;
  Std_ReturnType       LddReturnValue;
  uint16               LusDTCAttributeIndex;
  uint16               LusEventIndex;
  Dem_DTCSeverityType  LddDtcSeverity;
  #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
  #if (DEM_ONE < DEM_MAX_NUM_EVENTS_PER_DTC)
  uint16               LusNoOfCombinedEvents;
  uint16               LusCombinedEvent;
  uint16               LusCombinedEvtIndx;
  sint8                LscFDCValue;
  #endif
  #endif
  uint8                LucStatus;
  uint8                LucStatusAvailabilityMask;
  #if (DEM_USER_DEF_MEMORY_CONFIGURED == STD_ON)
  uint8 LucDTCOrigin;
  #endif
  boolean              LblEventDestinationFound;
  boolean              LblDtcFormat;

  /* Initialize initial value to not ok */
  LddReturnValue = E_NOT_OK;
  LpEventMemorySet = DEM_CLIENT_EVENT_MEMORYSET(LucClientId);
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_DISABLED)
  /* polyspace +4 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
 /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  LusEventIndex = DEM_DTC_EVENT_INDEX(LusDtcInfoIndex);
  #else
  /* DEM_EVCOMB_ONRETRIEVAL */
 /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* polyspace +12 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  #if (DEM_ONE < DEM_MAX_NUM_EVENTS_PER_DTC)
  LusNoOfCombinedEvents = DEM_DTC_NUMBER_OF_EVENTS(LusDtcInfoIndex);
  #endif
  /* Fetch event index from dtc requested */

  LusEventIndex = DEM_DTC_COMBINED_EVENTS(LusDtcInfoIndex , DEM_ZERO);
  #if (DEM_ONE < DEM_MAX_NUM_EVENTS_PER_DTC)
  if (DEM_ONE != LusNoOfCombinedEvents)
  {
    /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Fetch fdc value of event */
    LscFDCValue = Dem_GaaAllFDC[LusEventIndex];
    /* Loop through the no. of combined events to find the max FDC */
    for (LusCombinedEvent = DEM_ONE; (LusCombinedEvent <
      LusNoOfCombinedEvents);
      LusCombinedEvent++)
    {
      /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      
      LusCombinedEvtIndx =
                       DEM_DTC_COMBINED_EVENTS(LusDtcInfoIndex, LusCombinedEvent);
      /* polyspace +13 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        /* Polyspace InternalFunc_c_Ref_202 */
        /* check if current fdc value is greater than previous event */
	    /* #violates #ref Dem_InternalFunc_c_REF_25  Violates MISRA 2012 Required Rule INT02 */
        /* PRQA S 2104 3 */
	    /* #violates #ref Dem_InternalFunc_c_REF_26  Violates MISRA 2012 Required Rule STR34 */
        /* PRQA S 2144 1 */
      if (LscFDCValue < Dem_GaaAllFDC[LusCombinedEvtIndx])
      {
        /* Update latest Fdc value */
        LscFDCValue = Dem_GaaAllFDC[LusCombinedEvtIndx];
        /* Update event index which has max Fdc value */
        LusEventIndex = LusCombinedEvtIndx;
      }
      /* Polyspace InternalFunc_c_Ref_202 */
      /* Check if Fdc value is equal to DEM_FDC_COUNTER_MAX+127 */
	    /* #violates #ref Dem_InternalFunc_c_REF_25  Violates MISRA 2012 Required Rule INT02 */
      /* PRQA S 2104 3 */
	    /* #violates #ref Dem_InternalFunc_c_REF_26  Violates MISRA 2012 Required Rule STR34 */
      /* PRQA S 2144 1 */
      if (DEM_FDC_COUNTER_MAX == Dem_GaaAllFDC[LusEventIndex])
      {
        /* break loop as Max fdc value found */
        break;
      }
    }
  }
  #endif
  #endif

  SchM_Enter_Dem_DEM_DATA_PROTECTION();
  /* polyspace +16 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Get the status of the DTC */
  LucStatus =
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_DISABLED)
  Dem_GaaAllEvtStatus[LusEventIndex];
  #else
  Dem_GaaAllDtcStatus[LusDtcInfoIndex];
  #endif
  SchM_Exit_Dem_DEM_DATA_PROTECTION();
  /* Get the severity */
  LddDtcSeverity = DEM_DTC_SEVERITY(LusDtcInfoIndex);
  /* Get the Dtc Format */
  LblDtcFormat =
               DEM_DTC_FORMAT(LusDtcInfoIndex, (Dem_GaaDTCFormat[LucClientId]));
  /* DTC Attribute Index */
  LusDTCAttributeIndex = DEM_DTC_ATTRIBUTE_INDEX(LusDtcInfoIndex);
  LblEventDestinationFound = DEM_FALSE;
    /* Get configured Status Availability Mask Value */
   if ((DEM_DTC_PRIMARY_MEMORY == LusDTCOrgin) || (DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY == LusDTCOrgin))
   {
	   LucStatusAvailabilityMask = LpEventMemorySet->ucDtcStatusAvailabilityMask
 		                        [LpEventMemorySet->ucPrimaryMemoryMappingIndex];
   }
   #if ((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
            (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
       /* Check if Requested Origin is Permanent Memory*/
   else if (DEM_DTC_ORIGIN_PERMANENT_MEMORY == LusDTCOrgin)
   {
       LucStatusAvailabilityMask = DEM_MAX_AVAILABILITY_MASK_PERM_MEMORY;
    }
   #endif
   else
   {
       /* Check if Requested Origin is User Defined Memory */
 	   /* polyspace +20 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
           #if (DEM_USER_DEF_MEMORY_CONFIGURED == STD_ON)
		   LucStatusAvailabilityMask = DEM_MAX_AVAILABILITY_MASK_PERM_MEMORY;
           for (LucDTCOrigin = DEM_ZERO;
                LucDTCOrigin < LpEventMemorySet->ucNumOfUserDefinedMemory;
                LucDTCOrigin++)
           {
             /* Check if requested origin is configured */
             if (LusDTCOrgin ==
                    LpEventMemorySet->aaUserDefinedMemoryId[LucDTCOrigin])
             {
            	 LucStatusAvailabilityMask = (Dem_GaaClientList[LucClientId].pEventMemorySet)->
                ucDtcStatusAvailabilityMask[
                LpEventMemorySet->aaUserDefinedMemoryMappingIndex[LucDTCOrigin]];
               break;
             }
           }
           #else
		   LucStatusAvailabilityMask = DEM_MAX_AVAILABILITY_MASK_PERM_MEMORY;   
		   #endif
     }

  /* Get Filtered Status Mask Value */
  LucStatusAvailabilityMask = Dem_GaaCurDTCFilterStatusMask[LucClientId] &
                              LucStatusAvailabilityMask;
  /* polyspace +8 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Polyspace InternalFunc_c_Ref_190 */
  /* Polyspace InternalFunc_c_Ref_202 */
  /* Check if the DTC origin matches the DTC found */
  #if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
  if (LusDTCOrgin != DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY)
  #endif
  {
    if ((Dem_GaaDTCAttributes[LusDTCAttributeIndex].
      ucEventDestination) ==
                          ((uint8)(LusDTCOrgin)))
    {
      LblEventDestinationFound = DEM_TRUE;
    }
  }
  #if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
  else
  {
	  LblEventDestinationFound = DEM_TRUE;
  }	 
  #endif
  /* Check if Event destination matches the destination in the mask */
  if (!LblEventDestinationFound)
  {
    /* Error case  */
    LddReturnValue = E_NOT_OK;
  }
  /* Check for DTCFormat filter matching */
  else if (!LblDtcFormat)
  {
    /* Error case */
    LddReturnValue = E_NOT_OK;
  }
  #if (((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
     (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) && \
    (DEM_OBD_DTC_SUPPORT == STD_ON))
  else if ((LusDTCOrgin == DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY) &&   // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 
          ((DEM_OBD_DTC_VALUE(LusDtcInfoIndex) == (uint32)DEM_INVALID_DTC) || // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 
		  (!DEM_DTC_OBD_RELEVANT(LusDtcInfoIndex)))) // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 
  {
    /* Error case */
    LddReturnValue = E_NOT_OK;
  }
  #endif
  /* Check for DTCStatusMask filter matching */
  else if (((LucStatus & LucStatusAvailabilityMask) != DEM_ZERO) || // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
    (Dem_GaaCurDTCFilterStatusMask[LucClientId] == DEM_ZERO)) // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
  {
    /* If all the conditions are satisfied only then it should be EOK */
    LddReturnValue = E_OK;
  }
  else
  {
    /* To Avoid Warnings*/
  }
  /* Check for DTCSeverity filter matching */
  /* Polyspace InternalFunc_c_Ref_202 */
  if ((Dem_GaaCurDTCFilter[LucClientId] >> (uint16) DEM_FIFTEEN) == // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
        (uint16)DEM_DTC_FILTER_WITH_SEVERITY_YES)
  {
    if ((uint16) (((uint16)LddDtcSeverity) & // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
      ((Dem_GaaCurDTCFilter[LucClientId] & (uint16)DEM_BYTE_FF))) == (uint16) DEM_ZERO) // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
    {
      /* Error case */
      LddReturnValue = E_NOT_OK;
    }
  }
  /* Polyspace InternalFunc_c_Ref_202 */
  /* Check if Filter with FDC supported */
  if (((Dem_GaaCurDTCFilter[LucClientId] & (uint16)DEM_FDC_MASK) >> DEM_TEN) ==  // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 
    (uint16)DEM_DTC_FILTER_FOR_FDC_YES)
  {
    SchM_Enter_Dem_DEM_DATA_PROTECTION();
      /* polyspace +10 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      /* The FDC values should be in the range 0x01-0x7E */
	  /* #violates #ref Dem_InternalFunc_c_REF_25  Violates MISRA 2012 Required Rule INT02 */
      /* PRQA S 2104 4 */
	  /* #violates #ref Dem_InternalFunc_c_REF_26  Violates MISRA 2012 Required Rule STR34 */
      /* PRQA S 2144 2 */
    if ((Dem_GaaAllFDC[LusEventIndex] <= (sint8)DEM_ZERO) ||
          (Dem_GaaAllFDC[LusEventIndex] == (sint8)(DEM_FDC_COUNTER_MAX)))
    {
      /* Error case */
      LddReturnValue = E_NOT_OK;
    }
    SchM_Exit_Dem_DEM_DATA_PROTECTION();
  }
  else
  {
    /* To avoid warnings */
  }
  /* Return status */
  return (LddReturnValue);
} /* End of Dem_DTCFilterSearch */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_StartupNVOperation                              **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Reading the status from NvM.                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GstAdminData           **
**                                                 Dem_GaaNVBlockStatus,      **
**                                                 Dem_GblNVReadFailed        **
**                        Function(s) invoked    : Dem_InitNVData_Internal,   **
**                                                 NvM_WriteBlock             **
** Design ID            : DEM_SDD_1524                                        **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void Dem_StartupNVOperation(void)
{
  #if ((DEM_NVM_PRESENT == STD_ON) && (DEM_NUM_OF_NV_BLOCKS > DEM_ZERO))
  #if (DEM_ZERO < DEM_NUMBER_OF_DESTINAIONS_CONFIGURED)
  Std_ReturnType  LddReturnValue;
  #endif
  uint16_least     LusBlockCount;
  uint16           LusBlockID;
  boolean          LblReadFailed;

  LblReadFailed = DEM_FALSE;
  /* Check if any Nvm Block read is failed */
  if (Dem_GblNVReadFailed)
  {
    #if (DEM_NUM_OF_NV_BLOCKS > DEM_ONE)
    /* Loop for all configured blocks */
    for (LusBlockCount = DEM_ZERO;
          (LusBlockCount < (uint16_least)DEM_NUM_OF_NV_BLOCKS); LusBlockCount++)
    #else
    LusBlockCount = DEM_ZERO;
    #endif
    {
      LusBlockID = Dem_GaaNVBlocks[LusBlockCount].usBlockID;
      /* Store Block ID in Admin Block */
      Dem_GstAdminData.ucBlockInfo[LusBlockCount][DEM_ZERO] = LusBlockID;

      SchM_Enter_Dem_DEM_DATA_PROTECTION();
      /* Store block status in Admin Block */
      Dem_GstAdminData.ucBlockInfo[LusBlockCount][DEM_ONE] =
                                    (uint16)Dem_GaaNVBlockStatus[LusBlockCount];
      SchM_Exit_Dem_DEM_DATA_PROTECTION();

      /* code to be added for check status of NV block if returns E_OK
         block to be filled with default data */
    }
    /* Write the Admin Data immediately after the Update of Status */
    /* DEM_SDD_0023 */
    (void)NvM_WriteBlock((NvM_BlockIdType)DEM_ADMIN_DATA_BLOCK_ID, 
    &Dem_GstAdminData);
    /* Update all variables with default values */
    Dem_InitNVData_Internal();
  }
  else
  {
    #if (DEM_NUM_OF_NV_BLOCKS > DEM_ONE)
    /* Loop for all configured blocks */
    for (LusBlockCount = DEM_ZERO;
          (LusBlockCount < (uint16_least)DEM_NUM_OF_NV_BLOCKS); LusBlockCount++)
    #else
    LusBlockCount = DEM_ZERO;
    #endif
    {
      /*Read is partially completed*/
      if (NVM_REQ_OK != Dem_GaaNVBlockStatus[LusBlockCount])
      {
         #if (DEM_DEV_ERROR_DETECT == STD_ON)
          /* Report to DET */
        (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID, DEM_INIT_SID,
         DEM_E_INIT_FAILED);
         #endif
         LblReadFailed = DEM_TRUE;
         #if (DEM_NUM_OF_NV_BLOCKS > DEM_ONE)
         break;
         #endif
      }
    }
    /*Read is successfully completed*/
    if (!LblReadFailed)
    {
      #if (DEM_ZERO < DEM_NUMBER_OF_DESTINAIONS_CONFIGURED)

      /* Validate Block Contents */
      LddReturnValue = Dem_ConsistencyChecks();
      /* If Data is corrupted by presence of out of range Event ID */
      if (E_NOT_OK == LddReturnValue)
      {
        /* Update all variables with default values */
        Dem_InitNVData_Internal();
      }
      #endif
    }
  }
  #else
  /* Update all variables with default values */
  Dem_InitNVData_Internal();
  #endif
} /* End of Dem_StartupNVOperation*/
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
** Function Name        : Dem_ProcessStoredlessthanReported                   **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Replaces an event as per lowest and passive entries **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : LusMemEvtIndex , LusEventIdInMemory                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LblContinueProcess                                  **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaEventParameter,        **
**                                              Dem_GaaAllEvtStatus,          **
**                                              Dem_GaaMilFaults              **
**                        Function(s) invoked : None                          **
**  Design ID           : DEM_SDD_6657                                        **
*******************************************************************************/
#if (((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
          (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) && \
         (DEM_OBD_EVENT_DISPLACEMENT_SUPPORT == STD_ON) && \
         (DEM_OBD_DTC_SUPPORT == STD_ON))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_ProcessStoredlessthanReported(
   const uint16 LusMemEvtIndex, const uint16 LusEventIdInMemory, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   boolean* const  LblContinueProcess) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
	uint16                               LusDtcInfoIndex;
	boolean                              LblDisplaceEvent;
	uint16                               LusIndex;
/* polyspace +5 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
      /* Get DTC Index for Event */
      LusDtcInfoIndex = DEM_EVENT_MAPPED_DTC_INDEX(LusMemEvtIndex);
      /* Check if OBD DTC is configured for stored event */
      if ((uint32)DEM_INVALID_DTC != DEM_OBD_DTC_VALUE(LusDtcInfoIndex))
      {
        LblDisplaceEvent = DEM_TRUE;
        /* Check if event is stored as part of global OBD Freeze Frame Data */
        if (LusEventIdInMemory == Dem_GusObdFFEvent)
        {
          LblDisplaceEvent = DEM_FALSE;
        }
        else
        {
          #if (DEM_NUM_EVENT_MAPPED_TO_MIL > DEM_ONE)
          LusIndex = DEM_NUM_EVENT_MAPPED_TO_MIL;
          while ((DEM_ZERO < LusIndex) &&  (!LblDisplaceEvent)) // parasoft-suppress CERT_C-MSC12-j-3 MISRAC2012-RULE_14_3-ac-2 "Refer: Dem_InternalFunc_c_REF_29"
          #else
          LusIndex = DEM_ZERO;
          #endif
          {
            #if (DEM_NUM_EVENT_MAPPED_TO_MIL > DEM_ONE)
            /* Decrement to point to next iteration */
            --LusIndex;
            #endif
            if (Dem_GaaMilFaults[LusIndex] == LusEventIdInMemory)
            {
              LblDisplaceEvent = DEM_FALSE;
            }
          }
        }

        if ((!LblDisplaceEvent) ||
           (DEM_EVENTSTATUS_BIT2_SET ==
            ((Dem_GaaAllEvtStatus[LusMemEvtIndex]) & DEM_EVENTSTATUS_BIT2_SET)))
        {
          *LblContinueProcess = DEM_TRUE;
        }
      }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_InitNVData_Internal                             **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Initialise the memory for internal data elements    **
                          after clearing the NVM and resetting of counters    **
                          and global variables                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : LusBlockId,LblWrite                                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GucNoOfWarmUpCycles,   **
**                                                 Dem_GulTimeSinceMilOn,     **
**                                                 Dem_GflDistTravMilOnKm,    **
**                                                 Dem_GblMilStarted,         **
**                                                 Dem_GulDemClearTimeCount,  **
**                                                 Dem_GblClearTimeStartObd,  **
**                                                 Dem_GflDistTravClrDtcKm,   **
**                                                 Dem_GusGeneralDenominator, **
**                                                 Dem_GusIgnitionCylCnt,     **
**                                                 Dem_GaaUserDefMemory,      **
**                                                 Dem_GaaFDCDirectionCB,     **
**                                                 Dem_GaaIumprNumeratorCount,**
**                                                 Dem_GaaIntDebounceCounter, **
**                                                 Dem_GaaIndicatorStatus,    **
**                                                 Dem_GaaEvtAgingCounter,    **
**                                                 Dem_GaaDtcMainEvent,       **
**                                                 Dem_GstDefaultEventMemory  **
**                                               Dem_GstWWHObdDefaultEventMemory
**                                                 Dem_GaaAllEvtStatus        **
**                                                 Dem_GaaDTCOccurenceTime    **
**                                                 Dem_GaaOCCTypeSLF          **
**                                                 Dem_GaaOCCTypeSFF          **
**                                                 Dem_GaaOCCTypeFC           **
**                                                 Dem_GaaOCCStrtSLF_SFF_FC   **
**                                                 Dem_GaaComponentstatus     **
**                                                 Dem_GucActivationMode      **
**                        Function(s) invoked    : (void) DEM_MEMCPY,         **
**                                                 (void) DEM_MEMSET,         **
** Design ID            : DEM_SDD_0326,DEM_SDD_4111,DEM_SDD_2097,             **
**                        DEM_SDD_0651,DEM_SDD_0840                           **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static void  Dem_InitNVData_Internal(void)
{
  #if (DEM_NUMBER_OF_DESTINAIONS_CONFIGURED > DEM_ZERO)
  Dem_EventMemory*  LpEventMemory;
  #if (DEM_WWHOBD_SUPPORT == STD_ON)
  Dem_WWHObdEventMemory*  LpWWHOBDEventMemory;
  #endif
  uint8                             LucEntriesInMemory;
  #if (DEM_NUMBER_OF_DESTINAIONS_CONFIGURED > DEM_ONE)
  uint8_least                       LucMemCnt;
  #else
  const uint8_least                 LucMemCnt = DEM_ZERO;
  #endif
  #endif
  uint8                             LucClientId;
  #if (DEM_MAX_NUMBER_PRESTORED_FF > DEM_ZERO)
  uint16                            LusLoopCount; 
  #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
  uint16_least                      LusFFRecordRawData;
  #endif
  #endif

  #if (DEM_NUMBER_OF_DESTINAIONS_CONFIGURED > DEM_ZERO)
  #if (DEM_NUMBER_OF_DESTINAIONS_CONFIGURED > DEM_ONE)
  /* Loop for all Destinations */
  for (LucMemCnt = DEM_ZERO;
      LucMemCnt < (uint8_least)DEM_NUMBER_OF_DESTINAIONS_CONFIGURED; LucMemCnt++)
  #endif
  {
    /* Get the address of Event Memory based on the DTCOrigin  */
    LpEventMemory = Dem_GaaDTCOriginBasedPtrAddress[LucMemCnt].pEventMemory; // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
    /* Get the value of entries in memory based on DTCOrigin */
    LucEntriesInMemory = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
                                                 LucMemCnt].ucEntriesInMemory;
    #if (DEM_WWHOBD_SUPPORT == STD_ON)
    /* Get the address of WWH OBD Event Memory based on the DTCOrigin  */
    LpWWHOBDEventMemory = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
                                                  LucMemCnt].pWWHOBDEventMemory;
    #endif
    /* Loop for entries in event memory */
    while (DEM_ZERO < LucEntriesInMemory)
    {
      /* Decrement index for next iteration */
      --LucEntriesInMemory;
      /* Reset Memory */
      (void) DEM_MEMCPY((LpEventMemory + LucEntriesInMemory), &Dem_GstDefaultEventMemory, DEM_EVENT_MEMORY_BLOCK_SIZE);  // parasoft-suppress CERT_C-POS54-a-1 MISRAC2012-RULE_18_4-a-4 CERT_C-DCL39-a-3 CERT_C-DCL39-a-3 CERT_C-MEM04-a-2 CERT_C-MEM07-a-2 "Reason: Dem_InternalFunc_c_REF_14 Dem_InternalFunc_c_REF_17 Dem_InternalFunc_c_REF_18 Dem_InternalFunc_c_REF_25 Dem_InternalFunc_c_REF_28"
      #if (DEM_WWHOBD_SUPPORT == STD_ON)
      if (NULL_PTR != LpWWHOBDEventMemory)
      {
        /* reset WWHOBD Event memory  */
    	  (void) DEM_MEMCPY((LpWWHOBDEventMemory + LucEntriesInMemory), &Dem_GstWWHObdDefaultEventMemory, DEM_WWHOBD_EVENT_MEMORY_BLOCK_SIZE); // parasoft-suppress CERT_C-POS54-a-1 MISRAC2012-RULE_18_4-a-4 CERT_C-DCL39-a-3 CERT_C-MEM04-a-2 CERT_C-MEM07-a-2 "Reason: Dem_InternalFunc_c_REF_14 Dem_InternalFunc_c_REF_25 Dem_InternalFunc_c_REF_28" 
      }
      #endif
    } /* End of loop for number of event memory entries */
  }
  #endif

  /* reset Dem_GaaAllEvtStatus  */
  (void) DEM_MEMSET(&Dem_GaaAllEvtStatus, (sint16)DEM_DEFAULT_EVENTSTATUS, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"

                                                          DEM_NUMBER_OF_EVENTS); 
  /* reset Dem_GaaAllMonitorStatus  */
  (void) DEM_MEMSET(&Dem_GaaAllMonitorStatus, (sint16)DEM_DEFAULT_EVENTSTATUS, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"

                                                          DEM_NUMBER_OF_EVENTS); 

  #if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
  /* reset Dem_GaaAllDtcStatus  */
  (void) DEM_MEMSET(&Dem_GaaAllDtcStatus, (sint16)DEM_DTC_STATUS, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                                         DEM_MAX_NUMBER_OF_DTC); 
  #endif
  #if ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
       (DEM_MAX_DEPENDENT_OPCYC > DEM_ZERO))
      /* Reset Dem_GaaOBDCycleQualified */
  (void) DEM_MEMSET(&Dem_GaaOBDCycleQualified, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"

                                      DEM_NUMBER_OPERATION_CYCLES); 
  #endif
  
  #if (DEM_NUMBER_OF_CLIENTS > DEM_ONE)
  /* Loop for configured Clients */
  for (LucClientId = DEM_ZERO; LucClientId < DEM_NUMBER_OF_CLIENTS;
               LucClientId++)
  #else
  LucClientId = DEM_ZERO;
  #endif
  {
    /* reset Dem_GaaDTCOccurenceTime  */
    Dem_GaaDTCOccurenceTime[LucClientId][DEM_ZERO] = DEM_INVALID_DTC_INDEX;
    Dem_GaaDTCOccurenceTime[LucClientId][DEM_ONE] = DEM_INVALID_DTC_INDEX;
    Dem_GaaDTCOccurenceTime[LucClientId][DEM_TWO] = DEM_INVALID_DTC_INDEX;
    Dem_GaaDTCOccurenceTime[LucClientId][DEM_THREE] = DEM_INVALID_DTC_INDEX;
  }

  #if (DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > DEM_ZERO) && \
       (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
  /* reset Dem_GstPerEventMemory */
  (void) DEM_MEMSET(&Dem_GstPerEventMemory, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                              DEM_PER_EVENT_MEMORY_SIZE); 
  #endif
  /* reset Dem_GaaAllFDC  */
  /* #violates #ref Dem_InternalFunc_c_REF_26  Violates MISRA 2012 Required Rule STR34 */
      /* PRQA S 2144 1 */
  (void) DEM_MEMSET(&Dem_GaaAllFDC, (sint8)DEM_ZERO, DEM_NUMBER_OF_EVENTS); // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
  #if (DEM_OP_CYCLE_CTR_SINCE_FIRST_FAILED_ENABLED  == STD_ON)
  /* reset Dem_GaaOCCTypeSFF  */
  (void) DEM_MEMSET(&Dem_GaaOCCTypeSFF, (sint16)DEM_ZERO,  // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                            DEM_CYCLES_SINCE_FIRST_FAILED_SIZE); 
  #endif
  #if (DEM_OP_CYCLE_CTR_FAILED_CYCLES_ENABLED == STD_ON)
  /* reset Dem_GaaOCCTypeFC  */
  (void) DEM_MEMSET(&Dem_GaaOCCTypeFC, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                                        DEM_FAILED_CYCLES_SIZE); 
  #endif
  #if (DEM_OP_CYCLE_CTR_SINCE_LAST_FAILED_ENABLED == STD_ON)
  /* reset Dem_GaaOCCTypeSLF  */
  (void) DEM_MEMSET(&Dem_GaaOCCTypeSLF, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                             DEM_CYCLES_SINCE_LAST_FAILED_SIZE); 
  #endif
  #if (DEM_OP_CYCLE_CTR_SINCE_FIRST_FAILED_TESTED_CYCLES_ENABLED == STD_ON)
  /* reset Dem_GaaOCCTypeSLF  */
  (void) DEM_MEMSET(&Dem_GaaOCCTypeTestedSFF, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                     DEM_CYCLES_TESTED_SINCE_FIRST_FAILED_SIZE); 
  #endif
  #if (DEM_OP_CYCLE_CTR_SINCE_LAST_FAILED_TESTED_CYCLES_ENABLED == STD_ON)
  /* reset Dem_GaaOCCTypeSLF  */
  (void) DEM_MEMSET(&Dem_GaaOCCTypeTestedSLF, (sint16)DEM_ZERO,  // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                     DEM_CYCLES_TESTED_SINCE_LAST_FAILED_SIZE);
  #endif
  #if ((DEM_OP_CYCLE_CTR_SINCE_LAST_FAILED_ENABLED == STD_ON) || \
     (DEM_OP_CYCLE_CTR_SINCE_FIRST_FAILED_ENABLED == STD_ON) || \
     (DEM_OP_CYCLE_CTR_FAILED_CYCLES_ENABLED == STD_ON) ||\
	 (DEM_OP_CYCLE_CTR_SINCE_FIRST_FAILED_TESTED_CYCLES_ENABLED == STD_ON) ||\
	 (DEM_OP_CYCLE_CTR_SINCE_LAST_FAILED_TESTED_CYCLES_ENABLED == STD_ON))
  /* reset Dem_GaaOCCStrtSLF_SFF_FC  */
  (void) DEM_MEMSET(&Dem_GaaOCCStrtSLF_SFF_FC, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 "Reason: Dem_InternalFunc_c_REF_14"
                                               DEM_NUMBER_OF_EVENTS); 
  #endif
  

  (void) DEM_MEMSET(&Dem_GaaEventFailureCounter, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 "Reason: Dem_InternalFunc_c_REF_14"
                                                     DEM_NUMBER_OF_EVENTS); 

  #if  ((DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO) &&    \
        ((DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_ON) ||   \
         (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)))
  /* reset Dem_GaaAllDtcStatus  */
  (void) DEM_MEMSET(&Dem_GaaOldEvtCntHeadTailIndex, (sint16)DEM_INVALID, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"  // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
                              (DEM_NUMBER_OF_DESTINAIONS_CONFIGURED * DEM_TWO)); 
  #endif

  #if (DEM_NUMBER_OF_COUNTER_BASED_DEBOUNCE > DEM_ZERO)
  /* Reset Dem_GaaIntDebounceCounter */
  (void) DEM_MEMSET(Dem_GaaIntDebounceCounter, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                                    DEM_INT_DEBOUNCE_CTR_SIZE); 
  /* Reset Dem_GaaFDCDirectionCB */
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_29 Violates
        MISRA 2012 Required Rule 10.3 */
    /* PRQA S 1291 2 */  
  (void) DEM_MEMSET(Dem_GaaFDCDirectionCB, (sint16)DEM_FDC_RESET, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                 DEM_NUMBER_OF_INTERNAL_COUNTER_BASED_DEBOUNCE); 
  #endif

  #if (DEM_NUMBER_OF_INDICATORS > DEM_ZERO)
  /* Reset Dem_GaaIndicatorStatus */
  (void) DEM_MEMSET(Dem_GaaIndicatorStatus, (sint16)DEM_INDICATOR_OFF, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                                 DEM_NUMBER_OF_INDICATORS); 
  /* Reset Indicator Behaviour Order list */
  (void) DEM_MEMSET(Dem_GaaRecIndicBehavOrder, (sint16)DEM_INVALID,  // parasoft-suppress CERT_C-POS54-a-1 "Reason: Dem_InternalFunc_c_REF_14"
                                                       DEM_RECINDI_BEHAV_SIZE);
  #endif

  #if (DEM_NUMBER_OF_INDICATORS_ATTRIBUTE > DEM_ZERO)
  /* Reset Dem_GaaIndicatorState */
  (void) DEM_MEMSET(Dem_GaaIndicatorState, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                               DEM_NUMBER_OF_INDICATORS_ATTRIBUTE); 
  /* Reset Indicator Failure Couter Threshold */
  (void) DEM_MEMSET(Dem_GaaIndicatorFailureCycleCounter, (sint16)DEM_ZERO,  // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                          DEM_NUMBER_OF_INDICATORS_ATTRIBUTE);
  /* Reset Indicator Healinf Counter Threshold */
  (void) DEM_MEMSET(Dem_GaaIndicatorHealingCounter, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                          DEM_NUMBER_OF_INDICATORS_ATTRIBUTE); 
  #endif

  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
  /* Reset Dem_GaaDtcMainEvent */
  (void) DEM_MEMSET(&Dem_GaaDtcMainEvent, (sint16)DEM_ZERO, DEM_DTC_MAINEVT_SIZE); // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
  #endif

  #if (DEM_NUMBER_COMPONENTS > DEM_ZERO)
  /* Reset  Dem_GaaComponentstatus */
  (void) DEM_MEMSET(&Dem_GaaComponentstatus, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 "Reason: Dem_InternalFunc_c_REF_14"
                                          DEM_NUMBER_COMPONENTS); 
  #endif

  #if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
  /* Reset warm-up cycle count */
  Dem_GucNoOfWarmUpCycles = DEM_ZERO;
  /* Reset flag for time since DTC clear function is called */
  Dem_GblClearTimeStartObd = DEM_FALSE;
  #if (DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
  /* Reset flag for Time since mil is on */
  Dem_GblMilStarted = DEM_FALSE;
  /* Reset Distance Travelled since mil is on */
  Dem_GflDistTravMilOnKm = (float32)DEM_ZERO;
  /* Reset Distance Travelled since DTC clear */
  Dem_GflDistTravClrDtcKm = (float32)DEM_ZERO;
    /* Reset time since DTC clear function is called */
  Dem_GulDemClearTimeCount = DEM_ZERO;
  /* Reset Time since mil is on */
  Dem_GulTimeSinceMilOn = DEM_ZERO;
  #endif
  /* Reset General Denominator Value */
  Dem_GusGeneralDenominator = (uint16)DEM_ZERO;
  /* Reset General MiniDenominator Value */
  Dem_GucGeneralMiniDenominator = DEM_ZERO;
  #if (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON)
  (void) DEM_MEMSET(&Dem_GaaMiniNumerator, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                                       DEM_NUM_EVENT_MAPPED_TO_MIL); 
  (void) DEM_MEMSET(&Dem_GaaMonitorActivityDataValue, (sint16)DEM_ZERO,  // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                                       DEM_NUM_EVENT_MAPPED_TO_MIL);
  #endif
  /* Reset Ignition Cycle Counter Value */
  Dem_GusIgnitionCylCnt = (uint16)DEM_ZERO;
  /* Reset IUMPR Numerator Value */
  #if (((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
        (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) && \
        (DEM_PTO_SUPPORT == STD_ON))
  Dem_GblPtoStatus = DEM_FALSE;
  #endif
  #if ((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
       (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))  
  #if (DEM_IUMPR_STATUS_HANDLING == DEM_IUMPR_RATIO_SPECIFIC)
  #if (DEM_MAX_NUMBER_RATIOS > DEM_ZERO)    
  /* Reset IUMPR Internal Numerator Value */
  (void) DEM_MEMSET(&Dem_GaaIumprIntrlNumeratorCount, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                       DEM_IUMPR_INTRL_COUNT_SIZE); 
  /* Reset IUMPR Internal Denominator Value */
  (void) DEM_MEMSET(&Dem_GaaIumprIntrlDenominatorCount, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                       DEM_IUMPR_INTRL_COUNT_SIZE); 
  /* Reset IUMPR Denominator Flag */
  (void) DEM_MEMSET(&Dem_GaaIumprDenominatorIncFlag, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                                       DEM_MAX_NUMBER_RATIOS); 
  /* Reset IUMPR Denominator Increment Once Flag */
  (void) DEM_MEMSET(&Dem_GaaDenIncrementedOnceFlag, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                                       DEM_MAX_NUMBER_RATIOS); 
  #endif                                                       
  #endif
  /* Reset IUMPR general Denominator Increment Once Flag */
    Dem_GblGeneralDenIncrmtOnceFlag = DEM_FALSE;
  #endif
  /* Reset Dem_GaaIumprNumeratorCount */
  (void) DEM_MEMSET(&Dem_GaaIumprNumeratorCount, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                          DEM_IUMPR_COUNT_SIZE); 
  /* Reset IUMPR Denominator Value */
  (void) DEM_MEMSET(&Dem_GaaIumprDenominatorCount, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                         DEM_IUMPR_COUNT_SIZE); 
  #endif

  #if (DEM_MAX_NUM_OF_CLASS_B1_DTCS > DEM_ZERO)
  Dem_GulTimeSinceB1CounterStart = DEM_ZERO;
  Dem_GblStartB1Counter = DEM_FALSE;
  Dem_GucResetB1Counter = DEM_ZERO;
  #endif


  #if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
  #if ((DEM_MAX_NUM_OF_CLASS_B1_DTCS > DEM_ZERO) || \
     (DEM_MAX_NUM_OF_CLASS_A_DTCS > DEM_ZERO))
  Dem_GulTimeContinuousMICounter = DEM_ZERO;
  Dem_GaaContiMICntWarmUpcycle[DEM_ZERO] = DEM_ZERO;
  Dem_GaaContiMICntWarmUpcycle[DEM_ONE] = DEM_ZERO;
  Dem_GaaContiMICntWarmUpcycle[DEM_TWO] = DEM_ZERO;
  #if (DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
  Dem_GucTimeCumulativeContMICounter = DEM_ZERO;
  #endif
  #endif
  #endif

  #if ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
     (DEM_WWHOBD_SUPPORT == STD_ON))
  /* Reset the Activation Mode */
  Dem_GucActivationMode = DEM_ZERO;
  #if ((DEM_MAX_NUM_OF_CLASS_B1_DTCS > DEM_ZERO) || \
    (DEM_MAX_NUM_OF_CLASS_A_DTCS > DEM_ZERO))
  Dem_GblResetStatus = DEM_FALSE;
  #endif
  #endif

  #if ((DEM_TESTFAILED_BIT_PERMANENT_STORAGE == STD_ON) &&  \
       (DEM_NUMBER_COMPONENTS > DEM_ZERO))
       /* Reset  Dem_GaaComponentstatus */
  (void) DEM_MEMSET(&Dem_GaaComponentstatus, (sint16)DEM_COMPONENT_NO_STATE, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                               DEM_NUMBER_COMPONENTS); 
  #endif
  
    #if (DEM_MAX_NUMBER_PRESTORED_FF > DEM_ZERO)
       /* Reset  Dem_GaaPrestoreBuffer */
    #if (DEM_MULTICORE_SUPPORT == STD_ON)
     LusLoopCount = (uint16)(DEM_NUMBER_OF_CORES * DEM_MAX_NUMBER_PRESTORED_FF);
     #else
     LusLoopCount = (uint16)(DEM_MAX_NUMBER_PRESTORED_FF);
     #endif
      while (DEM_ZERO < LusLoopCount)
      {
        /* Next Iteration */
        --LusLoopCount;

        /* Clear Prestore data from shared buffer  */
        Dem_GaaPrestoreBuffer[LusLoopCount].ddEventId = DEM_ZERO;
        /* Clear the Did's */
        #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
        /* Loop through the size of did byte by byte to clear memory */
        for (LusFFRecordRawData = DEM_ZERO;
          LusFFRecordRawData < ((uint16_least)DEM_MAXSIZE_OF_FF_RAW_DATA +
                      (uint16_least)DEM_ONE); LusFFRecordRawData++)
        {
          /* Clear the data */
          Dem_GaaPrestoreBuffer[LusLoopCount].
             aaFFRecNumAndData[LusFFRecordRawData] = 
                                                DEM_CLEAR_PRESTORAGE_DATA_BYTE;
        }
        #endif
      }
    #endif

  #if (DEM_EIM_MODE_SUPPORT == STD_ON)
  /* Default status of EIM mode */
  Dem_GblEIMModeStatus = DEM_FALSE;
  #endif
  
  #if (((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
  (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) &&  \
  (DEM_DTR_SUPPORT == STD_ON))
 (void) DEM_MEMSET(&Dem_GblDtrInvisible, (sint8)DEM_ZERO, DEM_NUMBER_OF_DTRS); // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
  #endif
}/* End of Dem_InitNVData_Internal*/
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*******************************************************************************
** Function Name        : Dem_FaultCheckInConfig                              **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Counts and store the filtered dtc as per request by **
**                        Dcm                                                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LucClientId                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaOriginFilter,          **
**                                              Dem_GaaSuppressionStatus,     **
**                                              Dem_GaaMatchingDtcIndex,      **
**                                              Dem_GaaNumOfFilteredDtc,      **
                                                Dem_GaaChronlgOrdReq          **
**                        Function(s) invoked : Dem_DTCFilterSearch           **
**                                                                            **
** Design ID            : DEM_SDD_0605                                        **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_FaultcheckInConfig(const uint8 LucClientId) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  #if (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)
  Std_ReturnType  LddTempRet;
  uint16          LusDtcInfoIndex;
  uint16          LusDTCOrgin;
  /* #violates #ref Dem_InternalFunc_c_REF_24  Violates MISRA 2012 Required Rule INT02 */
  /* PRQA S 1252 3 */
  #if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
  #if ((DEM_J1939_DTC_SUPPORT == STD_ON) && \
          (DEM_J1939_READ_DTC_SUPPORT == STD_ON)) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  uint16          LusJ1939DtcInfoIndex;
  #endif
  #endif
  #if ((DEM_DTC_SUPPRESSION_SUPPORT == STD_ON) || \
      (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
  boolean                        LblSuppressionStatus;
  #endif

  /* Fetching of DTC Origin requested by Dcm */
  /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  LusDTCOrgin = Dem_GaaOriginFilter[LucClientId];

  for (LusDtcInfoIndex = DEM_ZERO; LusDtcInfoIndex <
                           (uint16)DEM_MAX_NUMBER_OF_DTC; LusDtcInfoIndex++)
  {

    #if ((DEM_DTC_SUPPRESSION_SUPPORT == STD_ON) || \
        (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
    /* Load the suppression status */
    LblSuppressionStatus = Dem_GaaSuppressionStatus[LusDtcInfoIndex];
    /* Check for suppression status */
    if (!LblSuppressionStatus)
    #endif
    {
      /* Polyspace InternalFunc_c_Ref_205 */
	  /* #violates #ref Dem_InternalFunc_c_REF_24  Violates MISRA 2012 Required Rule INT02 */
      /* PRQA S 1252 3 */
      #if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
      #if ((DEM_J1939_DTC_SUPPORT == STD_ON) && \
          (DEM_J1939_READ_DTC_SUPPORT == STD_ON)) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
      /* Check if request is for J1939 DTCs */
      if (DEM_DTC_FORMAT_J1939 == Dem_GaaDTCFormat[LucClientId])
      {
	    #if (DEM_J1939_DTC_CALIBRATION_SUPPORT == DEM_NO_CALIBRATION)
        LusJ1939DtcInfoIndex = DEM_J1939_DTC_INFO_INDEX(LusDtcInfoIndex);
        #else
        LusJ1939DtcInfoIndex  = LusDtcInfoIndex;
        #endif
        /* Check if J1939 DTC is configured or not */
        if ((uint32)DEM_INVALID_DTC != DEM_J1939_DTC_VALUE(LusJ1939DtcInfoIndex))
        {
          /* Verify conditions to match with requested Filter Criterias */
          LddTempRet = Dem_J1939DTCFilterSearch(
                         LusJ1939DtcInfoIndex, LusDTCOrgin, LucClientId);
        }
        else
        {
          /* J1939 DTC is not configured for current DTC index */
          LddTempRet = E_NOT_OK;
        }
      }
      else
      #endif
      {
        /* Polyspace InternalFunc_c_Ref_205 */
        /* Verify conditions to match with requested Filter Criterias */
        LddTempRet = Dem_DTCFilterSearch(
                       LusDtcInfoIndex, LusDTCOrgin, LucClientId);
      }
      #else
      /*Initialise return value to be E_NOT_OK*/
      LddTempRet = E_NOT_OK;
      #endif
      /* Polyspace InternalFunc_c_Ref_202 */
      /* Matching DTC is found */
      if (E_OK == LddTempRet)
      {
    /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        /* Load the DTC index into the buffer */
        /* Polyspace InternalFunc_c_Ref_195 */
        Dem_GaaMatchingDtcIndex[Dem_GaaNumOfFilteredDtc[LucClientId]] =
          LusDtcInfoIndex;
        /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 
		       Required Rule INT30 */
        /* PRQA S 3383 4 */
        /* Increment the number of filtered DTC */
        if (Dem_GaaNumOfFilteredDtc[LucClientId] < DEM_ARRAY_LIMIT)
        {
        ++Dem_GaaNumOfFilteredDtc[LucClientId];
        }
      }
    } /* suppression check */
  } /* Loop through DTCs */
  #endif
  /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  Dem_GaaChronlgOrdReq[LucClientId] = DEM_DTC_FILTER_DONE;
} /* End of Dem_FaultCheckInConfig */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*******************************************************************************
** Function Name        : Dem_UnusedFilterRoutine                             **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Dummy function used instead of NULL_PTR as default  **
**                        value for Filter Type function                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LucClientId                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_1543                                        **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_UnusedFilterRoutine(const uint8 LucClientId) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  /* No Operation */
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 1 */
  DEM_UNUSED(LucClientId);
} /* End of Dem_UnusedFilterRoutine */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*******************************************************************************
** Function Name        : Dem_UnusedDataReadRoutine                           **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Dummy function used instead of NULL_PTR as default  **
**                        value for LpData                                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpData                                              **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_0277                                        **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType Dem_UnusedDataReadRoutine(uint8* LpData)  // parasoft-suppress  CERT_C-API00-a-3 CERT_C-DCL00-b-3 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_9"
{
   *LpData = DEM_ZERO;
 
  return (E_NOT_OK);
} /* End of Dem_UnusedDataReadRoutine */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*******************************************************************************
** Function Name        : Dem_UnusedDataReadRoutineProxy                           **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Dummy function used instead of NULL_PTR as default  **
**                        value for LpData                                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpData                                              **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_6574                                        **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* #violates #ref Dem_InternalFunc_c_REF_QAC_31 Violates MISRA 2012 Required
     Rule 8.13 */
  /* PRQA S 3673 2 */
Std_ReturnType Dem_UnusedDataReadRoutineProxy(uint8* LpData, // parasoft-suppress  CERT_C-API00-a-3 CERT_C-DCL00-b-3 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_9"
   uint16 LusDataLength, Dcm_NegativeResponseCodeType* LpErrorCode) // parasoft-suppress  CERT_C-API00-a-3 CERT_C-DCL00-b-3 MISRAC2012-RULE_8_13-a-4 CERT_C-DCL13-a-3 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_21 Dem_InternalFunc_c_REF_27"
{
   *LpData = DEM_ZERO;
   
 DEM_UNUSED(LpErrorCode);
 DEM_UNUSED(LusDataLength);
  return (E_NOT_OK);
} /* End of Dem_UnusedDataReadRoutine */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*******************************************************************************
** Function Name        : Dem_UnusedMonitorDataReadRoutine                    **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Dummy function used instead of NULL_PTR as default  **
**                        value for LpData                                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : monitorData0                                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpData                                              **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_0277                                        **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType Dem_UnusedMonitorDataReadRoutine(uint8* LpData,  // parasoft-suppress CERT_C-API00-a-3 CERT_C-DCL00-b-3 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_9"
                                              Dem_MonitorDataType monitorData0) // parasoft-suppress CERT_C-API00-a-3 CERT_C-DCL00-b-3 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_9"
{
   *LpData = DEM_ZERO;

  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 1 */
  DEM_UNUSED(monitorData0);
   
  return (E_NOT_OK);
} /* End of Dem_UnusedFilterRoutine */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*******************************************************************************
** Function Name        : Dem_UnusedCallBackGetFDCRoutine                     **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Dummy function used instead of NULL_PTR as default  **
**                        value for CallBackGetFDC function                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : FaultDetectionCounter                               **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_1544                                        **
*******************************************************************************/
#if (DEM_NUMBER_OF_MONITOR_INTERNAL_DEBOUNCE > DEM_ZERO)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType  Dem_UnusedCallBackGetFDCRoutine(
   sint8* FaultDetectionCounter) // parasoft-suppress CERT_C-API00-a-3 CERT_C-DCL00-b-3  "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_9"
{
  /* Initialization to avoid QAC Warning */
  *FaultDetectionCounter = (sint8) DEM_ZERO;
  /* Return Value */
  return (DEM_E_NO_FDC_AVAILABLE);
} /* End of Dem_UnusedCallBackGetFDCRoutine */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_UnusedInitMonitorForEventRoutine                **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Dummy function used instead of NULL_PTR as default  **
**                        value for InitMonitorForEvent callback function     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : InitMonitorReason                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_1545,DEM_SDD_0253                           **
*******************************************************************************/
#if (DEM_CBK_MONITOR_FOR_EVENT_CNF == STD_ON)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType  Dem_UnusedInitMonitorForEventRoutine(
   Dem_InitMonitorReasonType InitMonitorReason) // parasoft-suppress CERT_C-API00-a-3 CERT_C-DCL00-b-3 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_9"
{
  /* No Operation */
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 1 */
  DEM_UNUSED(InitMonitorReason);
  /* Return Value */
  return (E_NOT_OK);
} /* End of Dem_UnusedInitMonitorForEventRoutine */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_UnusedEventDataChangedRoutine                   **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Dummy function used instead of NULL_PTR as default  **
**                        value for EventDataChanged callback function        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventId                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_1546                                        **
*******************************************************************************/
#if (DEM_CBK_EVENT_DATA_CHANGED_CNF == STD_ON)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType  Dem_UnusedEventDataChangedRoutine(
   Dem_EventIdType EventId) // parasoft-suppress CERT_C-API00-a-3 CERT_C-DCL00-b-3 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_9"
{
  /* No Operation */
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 1 */
  DEM_UNUSED(EventId);
  /* Return Value */
  return (E_OK);
} /* End of Dem_UnusedEventDataChangedRoutine */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_UnusedComponentFailedRoutine                    **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Dummy function used instead of NULL_PTR as default  **
**                        value for Component failed callback function        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : ComponentId                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_1547                                        **
*******************************************************************************/
#if (DEM_COMP_FAIL_CBK_PRESENT == STD_ON)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_UnusedComponentFailedRoutine(
   Dem_ComponentIdType ComponentId, boolean ComponentStatus)  // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  /* No Operation */
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 2 */
  DEM_UNUSED(ComponentId);
  DEM_UNUSED(ComponentStatus);
} /* End of Dem_UnusedComponentFailedRoutine */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_UnusedDataCaptureRoutine                        **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Dummy function used instead of NULL_PTR as default  **
**                        value for DataCapture function in case of Asynch    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LusEventParameterIndex, LddEventStatus              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_1547                                        **
*******************************************************************************/
#if (((DEM_ASYNCH_MASTER_MAIN_BUFF_SIZE == DEM_ZERO) || \
    (DEM_SATELLITE_ASYNCH_BUFF_SIZE == DEM_ZERO) || \
    (DEM_SWC_EVENT_STATUS_MANIPULATION_TYPE == DEM_SYNCHRONOUS_PROCESSING)))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_UnusedDataCaptureRoutine(
   const Dem_EventIdType LusEventParameterIndex, const Dem_EventStatusType LddEventStatus) // parasoft-suppress CERT_C-API00-a-3 CERT_C-DCL00-b-3 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_9"
{
  /* No Operation */
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 2 */
  DEM_UNUSED(LusEventParameterIndex);
  DEM_UNUSED(LddEventStatus);
} /* End of Dem_UnusedDataCaptureRoutine */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_UnusedClearEvtAllowedRoutine                    **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Dummy function used instead of NULL_PTR as default  **
**                        value for Clear event Allowed                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : pAllowed                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_1549                                        **
*******************************************************************************/
#if (DEM_CBK_CLEAR_EVENT_ALLOWED_CNF == STD_ON)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType  Dem_UnusedClearEvtAllowedRoutine(
  boolean* pAllowed) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  /* Assignment Operation to avoid QAC message 3673, Rule 8.13 */
  *pAllowed = *pAllowed;
  /* Return Value */
  return (E_NOT_OK);
} /* End of Dem_UnusedClearEvtAllowedRoutine */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_SetEventStatus_Invalid_Routine                  **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Dummy function used instead of NULL_PTR as default  **
**                        value for DemSetEventStatusFncPtr                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : EventId and EventStatus                             **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_2036                                        **
*******************************************************************************/
#if (DEM_MULTICORE_SUPPORT == STD_ON)
#define DEM_START_SEC_CODE_GLOBAL
#include "Dem_MemMap.h"
Std_ReturnType  Dem_SetEventStatus_Invalid_Routine(
  const Dem_EventIdType EventId, const Dem_EventStatusType EventStatus) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  /* No Operation */
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 2 */
  DEM_UNUSED(EventId);
  DEM_UNUSED(EventStatus);
  return (E_NOT_OK);
} /* End of Dem_SetEventStatus_Invalid_Routine */
#define DEM_STOP_SEC_CODE_GLOBAL
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_GetFaultDetectionCounter_Invalid_Routine        **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Dummy function used instead of NULL_PTR as default  **
**                        value for DemGetFDCFncPtr                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : EventId and FaultDetectionCounter                   **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_2161                                        **
*******************************************************************************/
#if (DEM_MULTICORE_SUPPORT == STD_ON)
#define DEM_START_SEC_CODE_GLOBAL
#include "Dem_MemMap.h"
Std_ReturnType  Dem_GetFaultDetectionCounter_Invalid_Routine
(const Dem_EventIdType EventId, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
              sint8* const FaultDetectionCounter) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
    /* Assignment Operation to avoid QAC message 3673, Rule 8.13 */
  *FaultDetectionCounter = *FaultDetectionCounter;
  /* No Operation */
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 2 */
  DEM_UNUSED(EventId);
  return (E_NOT_OK);
} /* End of Dem_GetFaultDetectionCounter_Invalid_Routine */
#define DEM_STOP_SEC_CODE_GLOBAL
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_PrestoreFreezeFrame_Invalid_Routine             **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Dummy function used instead of NULL_PTR as default  **
**                        value for DemPrestoreFreezeFrameFncPtr              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : EventId                                             **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_2033, DEM_SDD_4130                          **
*******************************************************************************/
#if (DEM_MULTICORE_SUPPORT == STD_ON)
#if (DEM_MAX_NUMBER_PRESTORED_FF > DEM_ZERO)
#define DEM_START_SEC_CODE_GLOBAL
#include "Dem_MemMap.h"
Std_ReturnType  Dem_PrestoreFreezeFrame_Invalid_Routine(
  const Dem_EventIdType EventId) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  /* No Operation */
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 1 */
  DEM_UNUSED(EventId);
  return (E_NOT_OK);
} /* End of Dem_PrestoreFreezeFrame_Invalid_Routine */
#define DEM_STOP_SEC_CODE_GLOBAL
#include "Dem_MemMap.h"
#endif
#endif

/*******************************************************************************
** Function Name        : Dem_ClearPrestoreFreezeFrame_Invalid_Routine        **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Dummy function used instead of NULL_PTR as default  **
**                        value for DemClearPrestoreFreezeFrameFncPtr         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : EventId                                             **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_2033                                        **
*******************************************************************************/
#if (DEM_MULTICORE_SUPPORT == STD_ON)
#if (DEM_MAX_NUMBER_PRESTORED_FF > DEM_ZERO)
#define DEM_START_SEC_CODE_GLOBAL
#include "Dem_MemMap.h"
Std_ReturnType  Dem_ClearPrestoreFreezeFrame_Invalid_Routine(
 const Dem_EventIdType EventId) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  /* No Operation */
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 1 */
  DEM_UNUSED(EventId);
  return (E_NOT_OK);
} /* End of Dem_ClearPrestoreFreezeFrame_Invalid_Routine */
#define DEM_STOP_SEC_CODE_GLOBAL
#include "Dem_MemMap.h"
#endif
#endif

/*******************************************************************************
** Function Name        : Dem_BinarySearchGroupDTC                            **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Searches Index of the dtc group                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : DTCGroup                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint16                                              **
**                                                                            **
** Preconditions        : DEM_GROUPDTC_CONFIGURED should be  STD_ON           **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaGroupDTC               **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_2105                                        **
*******************************************************************************/
#if (DEM_GROUPDTC_CONFIGURED == STD_ON)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
uint16  Dem_BinarySearchGroupDTC(const uint32 DTCGroup)
{
  uint32   LulLow;
  uint32   LulGroupDtcHigh;
  uint32   LulCurrentDtc;
  uint32   LulMiddle;
  uint16   LusReturnIndex;
  /* Initialize LucLow variable with one */
  LulLow = DEM_ONE;

  LusReturnIndex = DEM_INVALID_GROUPDTC_INDEX;
  /* Initialize LulGroupDtcHigh variable with number group DTCs */
  LulGroupDtcHigh = (uint32)DEM_MAX_NUM_GRP_DTC - (uint32)DEM_ONE;

  LulCurrentDtc = DEM_GRP_DTC_VALUE(DEM_ZERO);
  /* Check whether search dtc is in range */
  if ((DTCGroup >= LulCurrentDtc) &&
      (DTCGroup <= DEM_GRP_DTC_VALUE(LulGroupDtcHigh)))
  {
    /* Check whether requested dtcgroup is not the first element of the list */
    if (DTCGroup != LulCurrentDtc) // parasoft-suppress CERT_C-MSC12-j-3 MISRAC2012-RULE_14_3-ac-2 "Refer: Dem_InternalFunc_c_REF_12 Dem_InternalFunc_c_REF_22"
    {
      do
      {  /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
         /* PRQA S 3383 2 */
         /* Get the middle index number */
        LulMiddle = (LulGroupDtcHigh + LulLow) >> DEM_ONE;

        /* Get the group DTC value of the middle */
        LulCurrentDtc = DEM_GRP_DTC_VALUE(LulMiddle);

        /* Compare the current DTC with the requested one */
        if (LulCurrentDtc == DTCGroup)
        {
          /* Update the group index*/
          LusReturnIndex = (uint16)LulMiddle;

          /* Set LulGroupDtcHigh to zero to break the loop */
          LulGroupDtcHigh = DEM_ZERO;
        }
        else
        {
          /* Check if the requested dtc smaller than the current DTC */
          if (DTCGroup < LulCurrentDtc)
          {  /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
             /* PRQA S 3383 8 */
            /* The requested DTC is smaller than current, update
             * LulGroupDtcHigh */
            LulGroupDtcHigh = LulMiddle - (uint32)DEM_ONE;
          }
          else
          {
            /* The requested DTC is greater than current, update LulLow */
            LulLow = LulMiddle + (uint32)DEM_ONE;
          }
        } /* end if(DTCGroup  == LulCurrentDtc) */
      } while (LulLow <= LulGroupDtcHigh);
    } 
    else
    {
      /* Update the Index as zero */
      LusReturnIndex = DEM_ZERO;
    }
  } /* End of check for whether search dtc is in range*/
  return(LusReturnIndex);
}/* End of Dem_BinarySearchGroupDTC */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_BinarySearchJ1939DTC                            **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Searches Index of the J1939DTCValue                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : J1939DTCValue                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint16                                              **
**                                                                            **
** Preconditions        : DEM_J1939_DTC_CALIBRATION_SUPPORT should be         **
**                        DEM_NO_CALIBRATION                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaJ1939DTCValue,         **
**                        Dem_GaaJ1939DTCInfoIndex                            **
**                        Function(s) invoked : None                          **
** Design ID            : DEM_SDD_2313                                          **
*******************************************************************************/
#if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
    (DEM_J1939_DTC_SUPPORT == STD_ON)
#if (DEM_J1939_DTC_CALIBRATION_SUPPORT == DEM_NO_CALIBRATION)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
uint16  Dem_BinarySearchJ1939DTC(const uint32 J1939DTCValue)
{
  uint32   LulLow;
  uint32   LulDtcHigh;
  uint32   LulCurrentDtc;
  uint32   LulMiddle;
  uint16   LusReturnIndex;

  LusReturnIndex = DEM_INVALID_DTC_INDEX;

    /* Initialize LucLow variable with one */
    LulLow = DEM_ONE;
       /* Initialize LulDtcHigh variable with number of DTCs */
    LulDtcHigh = (uint32)DEM_MAX_NUMBER_OF_DTC - (uint32)DEM_ONE;

    LulCurrentDtc = DEM_J1939_DTC_VALUE(DEM_ZERO);
    /* Check whether search dtc is in range */
    if ((J1939DTCValue >= LulCurrentDtc) && // parasoft-suppress CERT_C-MSC12-j-3 MISRAC2012-RULE_14_3-ac-2 "Refer: Dem_InternalFunc_c_REF_29"
        (J1939DTCValue <= DEM_J1939_DTC_VALUE(LulDtcHigh)))
    {
      /* Check whether requested requested dtc is not the first element
         of the list */
      if (J1939DTCValue != LulCurrentDtc)
      {
        do
        {  /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
           /* PRQA S 3383 2 */
           /* Get the middle index number */
          LulMiddle = (LulDtcHigh + LulLow) >> DEM_ONE;

          /* Get the group DTC value of the middle */
          LulCurrentDtc = DEM_J1939_DTC_VALUE(LulMiddle);

          /* Compare the current DTC with the requested one */
          if (LulCurrentDtc == J1939DTCValue)
          {
            /* Update the dtc info index*/
            LusReturnIndex = DEM_J1939_DTC_INFO_INDEX((uint16)LulMiddle);

            /* Set LulDtcHigh to zero to break the loop */
            LulDtcHigh = DEM_ZERO;
          }
          else
          {
            /* Check if the requested dtc smaller than the current DTC */
            if (J1939DTCValue < LulCurrentDtc)
            { /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
              /* PRQA S 3383 9 */
              /* The requested DTC is smaller than current, update
               * LulDtcHigh */
              LulDtcHigh = LulMiddle - (uint32)DEM_ONE;
            }
            else
            {
              /* The requested DTC is greater than current, update LulLow */
              LulLow = LulMiddle + (uint32)DEM_ONE;
            }
          } /* end if(DTCGroup  == LulCurrentDtc) */
        } while (LulLow <= LulDtcHigh);
      } 
      else
      {
        /* Update the Index  */
        LusReturnIndex = DEM_J1939_DTC_INFO_INDEX(DEM_ZERO);
      }
    } /* End of check for whether search dtc is in range*/
  return(LusReturnIndex);
}/* End of Dem_BinarySearchJ1939DTC */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
#endif
/*******************************************************************************
** Function Name        : Dem_LinearSearchJ1939DTC                            **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Searches Index of the J1939DTCValue                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : J1939DTCValue                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint16                                              **
**                                                                            **
** Preconditions        : DEM_J1939_DTC_CALIBRATION_SUPPORT should be other    **
**                        than DEM_NO_CALIBRATION                             **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaJ1939DTCValue,         **
**                        Function(s) invoked : None                          **
** Design ID            : DEM_SDD_2314                                          **
*******************************************************************************/
#if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
    (DEM_J1939_DTC_SUPPORT == STD_ON)
#if ((DEM_J1939_DTC_CALIBRATION_SUPPORT == \
                         DEM_OFFLINE_AND_ONLINE_CALIBRATION) || \
(DEM_J1939_DTC_CALIBRATION_SUPPORT == DEM_OFFLINE_CALIBRATION))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
uint16  Dem_LinearSearchJ1939DTC (const uint32 J1939DTCValue)
{
  uint16   LusReturnIndex;
  uint16   LusDtccount;

  LusReturnIndex = DEM_INVALID_DTC_INDEX;

  /* Loop for Dtcs configured */
  for (LusDtccount = DEM_ZERO;
        LusDtccount < DEM_MAX_NUMBER_OF_DTC; LusDtccount++)
  {
    /* Check if requested DTC is of UDS DTC */
    if (J1939DTCValue == DEM_J1939_DTC_VALUE(LusDtccount))
    {
      /* Return DTC Attribute Index */
      LusReturnIndex = LusDtccount;
      break;
    }
  }
  return(LusReturnIndex);
}/* End of Dem_LinearSearchJ1939DTC */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
#endif
/*******************************************************************************
** Function Name        : Dem_SearchDtc                                       **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : API to search dtc configured                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : DTC                                                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LulDTCVal,LpEventParameterIndex,LpDTCAttributeIndex **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_DTC should be greater than Zero   **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaEventParameter,        **
**                                              Dem_GaaDTCAttributes,         **
**                                              Dem_GaaDtcMainEvent           **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_0344                                        **
*******************************************************************************/
#if ((DEM_MAX_NUMBER_OF_DTC > DEM_ZERO) && \
(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_SearchDtc (const uint16 LusDtcInfoIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
uint16* const LpEventParameterIndex) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
  uint16       LusDtcMainEvent;
  #endif
  /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* polyspace +21 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_DISABLED)
  *LpEventParameterIndex = DEM_DTC_EVENT_INDEX(LusDtcInfoIndex);
  #endif
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
  /* Check if valid event entry exists in memory */
  SchM_Enter_Dem_DEM_DATA_PROTECTION();
  /* polyspace +15 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  LusDtcMainEvent = Dem_GaaDtcMainEvent[LusDtcInfoIndex];
  SchM_Exit_Dem_DEM_DATA_PROTECTION();
  if (DEM_ZERO != LusDtcMainEvent)
  {
    /* Fetch evnt index from main event among combined events */
    *LpEventParameterIndex = LusDtcMainEvent - DEM_ONE;
  }
  /* if not update first event mapped to the combined Dtc */
  else
  {
    /* Fetch event index  */

    *LpEventParameterIndex =
                    DEM_DTC_COMBINED_EVENTS(LusDtcInfoIndex , DEM_ZERO);
  }
  #endif
} /* End of Dem_SearchDtc */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_GetSizeOfRecNoFFandFE                           **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : API to provide the size of extended data record     **
**                        if records are FF and FE                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : LusEventParameterIndex, ExtendedDataNumber          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : SizeOfExtendedDataRecord,LpEventMemory              **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_ED_RECDS should be greater than   **
**                        Zero                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaEventParameter,        **
**                                              Dem_GaaEDRecord               **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_0316                                        **
*******************************************************************************/
#if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
    (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static void  Dem_GetSizeOfRecNoFFandFE(const uint16 LusEventParameterIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
#if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
const uint8* const  LpSizeOfRecordCount, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
#endif
uint16* const LpSizeOfExtendedDataRecord, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
const uint8 ExtendedDataNumber, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
const Dem_EventMemory*  LpEventMemory) // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3  "Reason: Dem_InternalFunc_c_C-DCL00-b-3 Dem_InternalFunc_c_CERT_C-API00-a-3"
{
  const Dem_DTCAttributeType*  LpDTCAttribute;
  #if (((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
       (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) && \
      (DEM_OBD_DTC_SUPPORT == STD_ON))
  uint32                               LulObdDtc;
  uint16                               LusDtcInfoIndex;
  #endif
  uint16                               LusSize;
  uint8                                LucCount;
  uint8                                LucRecordNum;
  uint8                                LucActualRecordIndex;
  uint8                                LucValidRec;
  /* intialize Size of record to Zero */
  LusSize = DEM_ZERO;
  LucValidRec = DEM_ZERO;

  /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Intialize local pointer to index of DTC attribute */
  LpDTCAttribute = Dem_GaaEventParameter[LusEventParameterIndex].
                                                        pDTCAttribute;
  #if (((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
       (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) && \
      (DEM_OBD_DTC_SUPPORT == STD_ON))
  /* Get DTC Index for Event */
  /* polyspace +6 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  LusDtcInfoIndex = DEM_EVENT_MAPPED_DTC_INDEX(LusEventParameterIndex); // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Refer: Dem_EvtProcsg_c_REF_16"
  #endif
  /* Loop for all ED record configured for the Current Event */
  for (LucCount = DEM_ZERO; LucCount < (Dem_GaaEventParameter
   /* polyspace +2 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
   /* Polyspace InternalFunc_c_Ref_124 */
    [LusEventParameterIndex].pDTCAttribute)->ucNumOfEDRecords; LucCount++)
  {
    /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Get the Actual record index */
    LucActualRecordIndex = LpDTCAttribute->aaExtendedDataRecords[LucCount];

  #if (((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
       (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) && \
      (DEM_OBD_DTC_SUPPORT == STD_ON))
    /* Fetch the Obd DTC value */
    /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    LulObdDtc = DEM_OBD_DTC_VALUE(LusDtcInfoIndex);
    #endif
    /* Get the extended data record number */
    /* Polyspace InternalFunc_c_Ref_125 */
    LucRecordNum = LpEventMemory->aaEdData[LucCount][DEM_ZERO];
    /* Check if extended data record requested is FE */
    if (DEM_EXTENDED_DATA_NUMBER_OBD  == ExtendedDataNumber)
    {
     #if (((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
           (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) && \
          (DEM_OBD_DTC_SUPPORT == STD_ON))
      if ((uint32)DEM_INVALID_DTC  != LulObdDtc)
      {
        /* If the record number value 0xFE is requested,
            the Dem considers the size of all stored extended data
            records (in the range of 0x90 to 0xEF)
        */
        /* Check if record number staored in memory is valid */
        if ((LucRecordNum >= DEM_MIM_VALID_OBD_EXTENDED_RECORD_NUMBER) &&
            (LucRecordNum <= DEM_MAX_0XFE_OBD_EXT_REC_NUM))
        {
          /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
          if (LucRecordNum ==
               Dem_GaaEDRecord[LucActualRecordIndex].ucExtendedDataRecordNumber)
          {
            LusSize = LusSize +
                    Dem_GaaEDRecord[LucActualRecordIndex].usEDRecordRawDataSize;
            #if (DEM_MAX_MONITOR_ED_EXT_RECDS_PER_EVENT > DEM_ZERO)
            /* PRQA S 3383 1 */
            LusSize += Dem_GaaEDRecord[LucActualRecordIndex].usEDMonitorRawDataSize;
            #endif
            #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
            if (DEM_ZERO == *LpSizeOfRecordCount)
            #endif
            { /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
              /* PRQA S 3383 2 */
              /* Get the size of ED record */
              LucValidRec++;
            }
          }
        }
      }
      #endif
    }
    else /* If requested Record is FF*/
    {
      /* If the record number value 0xFF is requested,
          the Dem considers the size of all stored extended data
          records (in the range of 0x01 to 0xEF)
      */
      /* Check if record number staored in memory is valid */
      if ((LucRecordNum > DEM_ZERO) &&
        (LucRecordNum <= DEM_MAX_VALID_EXTENDED_RECORD_NUMBER))
      {
        /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        if (LucRecordNum ==
               Dem_GaaEDRecord[LucActualRecordIndex].ucExtendedDataRecordNumber)
        {
          /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
          LusSize = LusSize +
                    Dem_GaaEDRecord[LucActualRecordIndex].usEDRecordRawDataSize;
          #if (DEM_MAX_MONITOR_ED_EXT_RECDS_PER_EVENT > DEM_ZERO)
          /* PRQA S 3383 1 */
          LusSize += Dem_GaaEDRecord[LucActualRecordIndex].usEDMonitorRawDataSize;
          #endif
          #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
          if (DEM_ZERO == *LpSizeOfRecordCount)
          #endif
          {  /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
             /* PRQA S 3383 2 */
             /* Get the size of ED record */
              LucValidRec++;
          }
        }
      }
    }  /*if Record no : 0xFF */
  } /* End of for Loop for all ED record configured*/
  /* Load the size in the buffer including the number of
  * Ed records
  */
  *LpSizeOfExtendedDataRecord = LusSize + (uint16) LucValidRec;
} /* End of Dem_GetSizeOfRecNoFFandFE */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_ProcessUdsDataForWwh                            **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Process UDS data of event for WWHOBD                **
**                                                                            **
** Sync/Async           : Synchronous/Asynchronous                            **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LusEventParameterIndex,LucCount,LblEntryFound,      **
                          LpDTCAttribute,LucEventDestination,LucFreeIndex     **
                          LucRecCount                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpWWHOBDEventMemory                                 **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_MAX_NUM_OF_DID_PER_FF or                        **
                          DEM_MAX_NUM_OF_DID_PER_WWHOBD_FF                    **
                          should be greater than Zero                         **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaWWHOBDFFUpdateStatus,  **
**                                        Dem_GaaCurrentWWHOBDFFTriggerStatus **
**                                        Dem_GaaAllEvtStatus                 **
**                 Function(s) invoked : Dem_ProcessUdsDataForWwhRecUpdateTrue**
**                                                                            **
** Design ID            : DEM_SDD_0912                                        **
*******************************************************************************/
#if ((DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO) || \
 (DEM_MAX_NUM_OF_DID_PER_WWHOBD_FF > DEM_ZERO))
#if (DEM_WWHOBD_FF_SUPPORT == STD_ON)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_ProcessUdsDataForWwh(
  const uint16 LusEventParameterIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  const Dem_DTCAttributeType* const LpDTCAttribute
  #if (DEM_MAX_NUMBER_PRESTORED_FF > DEM_ZERO)
  , const uint8 LucCount, const boolean LblEntryFound // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  #endif
  , Dem_WWHObdEventMemory*  LpWWHOBDEventMemory // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
  )
{
  
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
  uint16  LusDtcInfoIndex;
  #endif
  
  uint8    LucAllEvtStatus;
  #if (DEM_WWHOBD_FF_SUPPORT == STD_ON)
  boolean  LblWWHOBDRecordUpdate;
  #endif
  boolean  LblCurrentWWHOBDFFTriggerStatus;
  uint8               LucMemIndx;

  #if (DEM_WWHOBD_FF_SUPPORT == STD_ON)
  LblWWHOBDRecordUpdate = DEM_FALSE;
  #endif
 /* polyspace +12 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
 /* polyspace +57 RTE:IDP [Justified:Low] "Refer Refer Dem_c_Poly_REF_4" */
  LblCurrentWWHOBDFFTriggerStatus =
             Dem_GaaCurrentWWHOBDFFTriggerStatus[LusEventParameterIndex];
  Dem_EventSearchInMemory(LusEventParameterIndex, &LucMemIndx);
  if (LblCurrentWWHOBDFFTriggerStatus)
  {
    if (Dem_GaaDTCOriginBasedPtrAddress[LucMemIndx].ucEventEntryStorageTrigr != 
    DEM_TRIGGER_ON_CONFIRMED)
    {
      #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
      /* Get DTC Index for Event */
      /* polyspace +6 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      LusDtcInfoIndex = DEM_EVENT_MAPPED_DTC_INDEX(LusEventParameterIndex);
      if (DEM_DTC_NUMBER_OF_EVENTS(LusDtcInfoIndex) >=  DEM_ONE)
      #endif
      {
        if (DEM_UPDATE_RECORD_NO == LpDTCAttribute->ucFFUpdateStatus)
        {
          if ((((Dem_GaaAllEvtStatus[LusEventParameterIndex]) &
                DEM_EVENTSTATUS_BIT2_SET) ==
                DEM_EVENTSTATUS_BIT2_SET) &&
                (LpWWHOBDEventMemory->aaWWHOBDFFData[DEM_ZERO] ==
                                                  DEM_INVALID_FF_REC_NUM))
          {
            LblWWHOBDRecordUpdate = DEM_TRUE;
          }
        }
        else
        {
          SchM_Enter_Dem_DEM_DATA_PROTECTION();
          LucAllEvtStatus = Dem_GaaAllEvtStatus[LusEventParameterIndex];
          SchM_Exit_Dem_DEM_DATA_PROTECTION();
          if (((LucAllEvtStatus &
                DEM_EVENTSTATUS_BIT2_SET) ==
                DEM_EVENTSTATUS_BIT2_SET) &&
                (LpWWHOBDEventMemory->aaWWHOBDFFData[DEM_ZERO] ==
                                                  DEM_INVALID_FF_REC_NUM))
          {
            LblWWHOBDRecordUpdate = DEM_TRUE;
          }

          else if (((LucAllEvtStatus & DEM_EVENTSTATUS_BIT3_SET)
            == DEM_EVENTSTATUS_BIT3_SET) &&
          (!Dem_GaaWWHOBDFFUpdateStatus[LusEventParameterIndex]))
          {
            LblWWHOBDRecordUpdate = DEM_TRUE;
            Dem_GaaWWHOBDFFUpdateStatus[LusEventParameterIndex] = DEM_TRUE;
          }
          else
          {
            /*Do nothing*/
          }
        }
      }
    }
    else  
    {
      SchM_Enter_Dem_DEM_DATA_PROTECTION();
      LucAllEvtStatus = Dem_GaaAllEvtStatus[LusEventParameterIndex];
      SchM_Exit_Dem_DEM_DATA_PROTECTION();
      if (Dem_GaaWWHOBDFFUpdateStatus[LusEventParameterIndex])
      {
        Dem_GaaWWHOBDFFUpdateStatus[LusEventParameterIndex] = DEM_FALSE;
      }
      /* polyspace +4 RTE:IDP [Justified:Low] "Refer Refer Dem_c_Poly_REF_4" */
      else if (((LucAllEvtStatus &
       DEM_EVENTSTATUS_BIT2_SET) == DEM_EVENTSTATUS_BIT2_SET) &&
       (LpWWHOBDEventMemory->aaWWHOBDFFData[DEM_ZERO] ==
       DEM_INVALID_FF_REC_NUM))
      {
        LblWWHOBDRecordUpdate = DEM_TRUE;
      }
      else
      {
        /*Do nothing*/
      }
    }
    if (LblWWHOBDRecordUpdate)
    {
      /* Function for processing uds data when record update is true for wwh */
      Dem_ProcessUdsDataForWwhRecUpdateTrue(
      #if (DEM_MAX_NUMBER_PRESTORED_FF > DEM_ZERO)
      LucCount, LblEntryFound,
      #endif
      LpWWHOBDEventMemory
      );
    }
  }
  else
  {
    /* Do Nothing */
  }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
#endif
/*******************************************************************************
** Function Name        : Dem_ProcessUdsDataForWwhRecUpdateTrue               **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          :Process UDS data when record update is true for WWH  **
**                                                                            **
** Sync/Async           : Synchronous/Asynchronous                            **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LucRecCount,LucCount,LblEntryFound,LucFreeIndex     **
                          LucEventDestination                                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpWWHOBDEventMemory                                 **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_MAX_NUM_OF_DID_PER_FF or                        **
                          DEM_MAX_NUM_OF_DID_PER_WWHOBD_FF                    **
                          should be greater than Zero                         **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaWWHOBDPrestoreBuffer   **
**                        Function(s) invoked : Dem_LoadWWHOBDDid,            **
**                                              Dem_LoadWWHOBDPrestoreData    **
**                                                                            **
** Design ID            : DEM_SDD_0914                                        **
*******************************************************************************/
#if ((DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO) || \
(DEM_MAX_NUM_OF_DID_PER_WWHOBD_FF > DEM_ZERO))
#if (DEM_WWHOBD_FF_SUPPORT == STD_ON)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static void  Dem_ProcessUdsDataForWwhRecUpdateTrue(
  #if (DEM_MAX_NUMBER_PRESTORED_FF > DEM_ZERO)
  const uint8 LucCount, const boolean LblEntryFound, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  #endif
  Dem_WWHObdEventMemory*  LpWWHOBDEventMemory // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
)
  
{
  #if (DEM_MAX_NUMBER_PRESTORED_FF > DEM_ZERO)
  const Dem_WWHOBDPrestoreBuffer*  LpPFFBuffer;
  #endif
  /* polyspace +23 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* polyspace +29 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  LpWWHOBDEventMemory->aaWWHOBDFFData[DEM_ZERO] = DEM_ZERO;
  
  #if (DEM_MAX_NUMBER_PRESTORED_FF > DEM_ZERO)
  if (!LblEntryFound)
  #endif
  {
    #if (DEM_MAX_NUM_OF_DID_PER_WWHOBD_FF > DEM_ZERO)
    Dem_LoadWWHOBDDid(LpWWHOBDEventMemory);
    #endif
  }
  #if (DEM_MAX_NUMBER_PRESTORED_FF > DEM_ZERO)
  else
  {
    SchM_Enter_Dem_DEM_DATA_PROTECTION();
    LpPFFBuffer = &Dem_GaaWWHOBDPrestoreBuffer[LucCount];
    SchM_Exit_Dem_DEM_DATA_PROTECTION();
    Dem_LoadWWHOBDPrestoreData(LpWWHOBDEventMemory, LpPFFBuffer);
  }
  #endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
#endif
/*******************************************************************************
** Function Name        : Dem_LoadPrestoredDid                                **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Load prestored Did in event memory                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpPFFBuffer                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpEventMemory                                       **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_PRESTORED_FF and                     **
                          DEM_MAX_NUM_OF_DID_PER_FF                           **
                          should be greater than Zero                         **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_0320,DEM_SDD_0341                           **
*******************************************************************************/
#if ((DEM_MAX_NUMBER_PRESTORED_FF > DEM_ZERO) &&\
  (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_LoadPrestoredDid(
  Dem_EventMemory*  LpEventMemory, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
  const Dem_PrestoreBuffer*  const LpPFFBuffer, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
 const uint8 LucRecordIndexInMem) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  const Dem_DTCAttributeType*  LpDTCAttribute;
  uint16                               LusEventParameterIndex;
  uint16                               LusDataSizeCount;
  uint16                               LusFFRecordRawDataSize;

  /* Get the event parameter index */
  LusEventParameterIndex = LpEventMemory->ddEventId - (uint16)DEM_ONE;
  /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  LpDTCAttribute = Dem_GaaEventParameter[LusEventParameterIndex].pDTCAttribute;
  /* Check if LpDTCAttribute is null pointer */
  if (NULL_PTR != LpDTCAttribute)
  {
    /* Get number of Dids */
    LusFFRecordRawDataSize = LpDTCAttribute->usFFRecordRawDataSize;
    /* Get the start position of first DID in memory */
    for (LusDataSizeCount = DEM_ZERO;
      LusDataSizeCount < LusFFRecordRawDataSize;
        LusDataSizeCount++)
    { /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
      /* PRQA S 3383 6 */
    /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* polyspace +4 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
      /* Transfer data into event memory from prestore buffer */
      LpEventMemory->aaFFRecNumAndData[LucRecordIndexInMem]
      [LusDataSizeCount + DEM_ONE] =
      LpPFFBuffer->aaFFRecNumAndData[LusDataSizeCount + DEM_ONE];
    }
  } /* End of Check for LpDTCAttribute is null pointer */
} /* End Of Dem_LoadPrestoredDid */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_ClearPFFEntry                                   **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Clearing of Pre-Store Freeze frame entry            **
**                                                                            **
** Sync/Async           : Synchronous/Asynchronous                            **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LucPFFBufferIndex                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_PRESTORED_FF                         **
                          should be greter than Zero                          **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaPrestoreBuffer         **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_0329                                        **
*******************************************************************************/
#if (DEM_MAX_NUMBER_PRESTORED_FF > DEM_ZERO)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_ClearPFFEntry(const uint8 LucPFFBufferIndex) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
  uint16_least  LusFFRecordRawData;
  #endif
  /* #violates #ref Dem_InternalFunc_c_REF_24  Violates MISRA 2012 Required Rule INT02 */
  /* PRQA S 1252 2 */
  #if ((DEM_MULTICORE_SUPPORT == STD_ON) && \
       (DEM_NUM_OF_SATELLITE_CORE > DEM_ZERO)) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  Dem_EventIdType                      LddEventId;
  #endif
  /* #violates #ref Dem_InternalFunc_c_REF_24  Violates MISRA 2012 Required Rule INT02 */
  /* PRQA S 1252 2 */
  #if ((DEM_MULTICORE_SUPPORT == STD_ON) && \
       (DEM_NUM_OF_SATELLITE_CORE > DEM_ZERO)) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  /* polyspace +31 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  LddEventId = Dem_GaaPrestoreBuffer[LucPFFBufferIndex].ddEventId;
  Dem_ClearMasterEventPrestoreBuffer(LddEventId);
  #endif

  /* Clear the event id */
  Dem_GaaPrestoreBuffer[LucPFFBufferIndex].ddEventId = DEM_ZERO;

  /* Clear the Did's */
  #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
  /* Loop through the size of did byte by byte to clear memory */
  for (LusFFRecordRawData = DEM_ZERO;
           LusFFRecordRawData < ((uint16_least)DEM_MAXSIZE_OF_FF_RAW_DATA +
                                   (uint16_least)DEM_ONE); LusFFRecordRawData++)
  {
    /* Clear the data */
    Dem_GaaPrestoreBuffer[LucPFFBufferIndex].
      aaFFRecNumAndData[LusFFRecordRawData] = DEM_CLEAR_PRESTORAGE_DATA_BYTE;
  }
  #endif

  #if (DEM_WWHOBD_FF_SUPPORT == STD_ON)
  /* Loop through the size of did byte by byte to clear memory */
  for (LusFFRecordRawData = DEM_ZERO; LusFFRecordRawData <
                                              (uint16_least)DEM_SIZE_OF_WWHOBD_FF_RAW_DATA;
    LusFFRecordRawData++)
  {
    /* Clear the data */
    /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    Dem_GaaWWHOBDPrestoreBuffer[LucPFFBufferIndex].aaDid[LusFFRecordRawData] =
                                                 DEM_CLEAR_PRESTORAGE_DATA_BYTE;
  }
  #endif
} /* End of Dem_ClearPFFEntry */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_ProcessDataElementSize                          **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : This function is used to calculate the size of the  **
**                        data element                                        **
**                                                                            **
** Sync/Async           : Synchronous/Asynchronous                            **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LusDataIndex,LucDataElementType                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpSize                                              **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_FF_RECDS should be greater than Zero
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaDataElementExternalCS  **
**                                            : Dem_GaaDataElementExternalSR  **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_0322                                        **
*******************************************************************************/
 #if ((DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO) || \
     ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
     (DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ZERO)))
#if (DEM_MULTICORE_SUPPORT == STD_ON)
#define DEM_START_SEC_CODE_GLOBAL
#else
#define DEM_START_SEC_CODE
#endif
#include "Dem_MemMap.h"
Std_ReturnType Dem_ProcessDataElementSize(const uint16 LusDataIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  const uint8 LucDataElementType, uint8* const LpSize) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  #if ((DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS == DEM_ZERO) &&  \
      (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR == DEM_ZERO) &&  \
      (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL  == DEM_ZERO))
  const Std_ReturnType LddReturnValue = E_NOT_OK;
  #else  
  #if (((DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS > DEM_ZERO) || \
      (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR > DEM_ZERO))  && \
      (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL == DEM_ZERO))
  const Std_ReturnType LddReturnValue = E_OK;
  #else
  Std_ReturnType LddReturnValue;
  #endif
  #endif
  #if (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)
  LddReturnValue = E_OK;
  #endif

  #if (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS > DEM_ZERO)
  /* Data element size is fetched from Client server interface */
  if ((uint8)DEM_DATA_ELEMENT_EXTERNAL_CS  == LucDataElementType)
  {
    /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    *LpSize = Dem_GaaDataElementExternalCS[LusDataIndex].
      ucDemDataElementDataSize;
  }
  #endif

  #if (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR > DEM_ZERO)
  /* Data element size is fetched from Sender Receiver interface */
  /* polyspace +4 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  if ((uint8)DEM_DATA_ELEMENT_EXTERNAL_SR  == LucDataElementType)
  {
    *LpSize = Dem_GaaDataElementExternalSR[LusDataIndex].
      ucDemDataElementDataSize;
  }
  #endif

  #if (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)
  /* Check if dataelement type is DEM_DATA_ELEMENT_INTERNAL */
  if ((uint8)DEM_DATA_ELEMENT_INTERNAL  == LucDataElementType)
  {
    *LpSize = DEM_ONE;
    LddReturnValue = E_NOT_OK;
  }
  #endif

  /* currently data element for  SR should not be configured */
  #if ((DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS == DEM_ZERO) &&  \
      (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR == DEM_ZERO))
      
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012
      Required Rule 2.2 */
  /* PRQA S 3112 2 */
  DEM_UNUSED(LusDataIndex);
  #endif
  #if ((DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS == DEM_ZERO) &&  \
      (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR == DEM_ZERO) &&  \
      (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL  == DEM_ZERO))
  DEM_UNUSED(LucDataElementType);
  *LpSize =  DEM_ONE;
  #endif

  return LddReturnValue;
} /* End Of Dem_ProcessDataElementSize */
#if (DEM_MULTICORE_SUPPORT == STD_ON)
#define DEM_STOP_SEC_CODE_GLOBAL
#else
#define DEM_STOP_SEC_CODE
#endif
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_EnvironmentalDataCheck                          **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Common checks to be done for fetching the           **
**                        environmental data                                  **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : DTC,DTCOrigin                                       **
**                                                                            **
** InOut parameter      : LpEventMemory                                       **
**                                                                            **
** Output Parameters    : LblEventExistInMemory,LpNumOfEvts,LpStoredInds,     **
                          LpWWHOBDEventMemory,LucStoredIndex                  **
**                                                                            **
** Return parameter     : uint32                                              **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaSuppressionStatus,     **
**                                              Dem_GaaDTCAttributes,         **
**                                              Dem_GaaEventParameter         **
**                        Function(s) invoked : Dem_SearchDtc,                **
**                                              Det_ReportError               **
**                                                                            **
** Design ID            : DEM_SDD_0313                                        **
*******************************************************************************/
#if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType 
Dem_EnvironmentalDataCheck(
#if ((DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL) || \
  (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL))
const uint16 LusDtcInfoIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
#endif
const Dem_DTCOriginType LusDtcOrigin, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
boolean* const LblEventExistInMemory, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
Dem_EventMemory*  *LpEventMemory // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
#if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
, uint8*  LpStoredInds // parasoft-suppress CERT_C-API00-a-3 MISRAC2012-RULE_17_8-a-4 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_20"
, uint8*  LpNumOfEvts // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Reason: Dem_InternalFunc_c_CERT_C-DCL00-b-3 Dem_InternalFunc_c_REF_10"
#else
, uint8* const LpStoredIndex // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
#endif
#if ((DEM_DEV_ERROR_DETECT == STD_ON) && \
(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL))
, const uint8 LucSid // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
#endif
#if (DEM_WWHOBD_SUPPORT == STD_ON)
, Dem_WWHObdEventMemory*  *LpWWHOBDEventMemory // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
#endif
)
{
  Std_ReturnType   LddRetDtcCheckAndAttrInd;
  uint8            LucOriginMask;
  uint8            LucDtcorigin1;
  #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
  uint16           LusEventParameterIndex;
  #endif
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
  uint16           LusEvtCnt;
  #endif
  #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
  LusEventParameterIndex = DEM_ZERO;
  #endif
  

  LddRetDtcCheckAndAttrInd = E_OK;
  LucOriginMask = (uint8)LusDtcOrigin;
  if (LucOriginMask < (DEM_MAX_MEMORY_ID_CONF + DEM_ONE)) 
  {  
  
   LucDtcorigin1 = Dem_GaaDTCOriginMappingIndx[LucOriginMask];
    /* Get the address of Event Memory based on the DTCOrigin  */
    if (LucDtcorigin1 <= DEM_NUMBER_OF_DESTINAIONS_CONFIGURED )
    {
      *LpEventMemory = Dem_GaaDTCOriginBasedPtrAddress[LucDtcorigin1].pEventMemory; // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
  #if (DEM_WWHOBD_SUPPORT == STD_ON)
  /* Get the address of WWH OBD Event Memory based on the DTCOrigin  */
  *LpWWHOBDEventMemory = Dem_GaaDTCOriginBasedPtrAddress[LucDtcorigin1].pWWHOBDEventMemory;
  #endif

  #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
  /* Search for the DTC */
  Dem_SearchDtc(LusDtcInfoIndex, &LusEventParameterIndex);
  #endif
    /* Check if Event/DTC is found in Event Memory */
    #if ((DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL) &&  \
         (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO))
    /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
   /* polyspace +18 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    if ((Dem_GaaEventParameter[LusEventParameterIndex].pDTCAttribute)->
        ucEventDestination == LucOriginMask)
    #endif
    {
       /* polyspace +20 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      /* For Event Combination: On Retrieval, Memory belonging to the
         events belonging to DTC should be Captured  */
      #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
      for (LusEvtCnt = DEM_ZERO; ((LusEvtCnt <
         DEM_DTC_NUMBER_OF_EVENTS(LusDtcInfoIndex)) &&
         (LddRetDtcCheckAndAttrInd == E_OK))
         ;LusEvtCnt++)
      {
      /* polyspace +6 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      /* polyspace +5 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
          *LpStoredInds = Dem_GaaMemoryIndexForEvt[
                         DEM_DTC_COMBINED_EVENTS(LusDtcInfoIndex, LusEvtCnt)];
        /* Check if event stored in memory */
        if (DEM_INVALID != (*LpStoredInds))
        { /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
          /* PRQA S 3383 10 */
          /* Increment pointer to point to next location */
          /* #violates #ref Dem_InternalFunc_c_REF_QAC_14 Violates MISRA 2012
            Required Rule 17.8 */
            /* PRQA S 1338 1 */
          ++LpStoredInds; // parasoft-suppress CERT_C-API00-a-3 MISRAC2012-RULE_17_8-a-4 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_20"
          /* Number of Event Stored in Event Memory */
          (*LpNumOfEvts) = (*LpNumOfEvts) + DEM_ONE;
          /* Event Entry is found */
          (*LblEventExistInMemory) = DEM_TRUE;
        }
        /* polyspace +4 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        if ((Dem_GaaEventParameter
          [DEM_DTC_COMBINED_EVENTS(LusDtcInfoIndex, LusEvtCnt)]
          .pDTCAttribute)->
          ucEventDestination != LucOriginMask)
        {
          #if (DEM_DEV_ERROR_DETECT == STD_ON)
          /* Error report to DET */
          (void)Det_ReportError(DEM_MODULE_ID, DEM_ZERO,
            LucSid, DEM_E_WRONG_CONFIGURATION);
          #endif
          /* Return appropriate value */
          LddRetDtcCheckAndAttrInd = DEM_WRONG_DTCORIGIN;
        }
      }
      #else 
        /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        /* If Combination is Disabled or Event Combination : On Retrieval */
        *LpStoredIndex = Dem_GaaMemoryIndexForEvt[LusEventParameterIndex];
      /* Check if event stored in memory */
      if (DEM_INVALID  != (*LpStoredIndex))
      {
        (*LblEventExistInMemory) = DEM_TRUE;
      }
      #endif
    }

    #if ((DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL) &&  \
        (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO))
    else
    {
      /* Return appropriate value */
      LddRetDtcCheckAndAttrInd = DEM_WRONG_DTCORIGIN;
    }
    #endif
  }
}

  return(LddRetDtcCheckAndAttrInd);
} /* End of Dem_EnvironmentalDataCheck */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_ClearInitVariables                              **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : If EcuM Fixed is Used, Dem is Initialized without   **
**                        Startup code(while coming out of sleep), Reset of   **
**                        global variables is done using this service.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_SLEEP_WAKEUP_SUPPORT should be ON               **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GaaMatchingDtcIndex,   **
**                                                 Dem_GaaMaxFDCDCurCyc,      **
**                                                 Dem_GaaMaxFDCSLstClr,      **
**                                                 Dem_GaaFDCDirectionTD,     **
**                                                 Dem_GaaCurDTCFilter,       **
**                                                 Dem_GaaNumOfFilteredDtc,   **
**                                                 Dem_GaaIndicatorStatus,    **
**                                                 Dem_GstDtcClrStat,         **
**                                           Dem_GaaGetNxtFltrdEvntCalled,    **
**                                           Dem_GaaOperationCycleIdBuffer,   **
**                        Function(s) invoked    : (void) DEM_MEMSET                     **
**                                                                            **
** Design ID            : DEM_SDD_0308                                        **
*******************************************************************************/
#if (DEM_SLEEP_WAKEUP_SUPPORT == STD_ON)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_ClearInitVariables(void)
{
  #if (DEM_NUMBER_OF_CLIENTS > DEM_ONE)
  uint8             LucClientId;
  #else
  const uint8       LucClientId = DEM_ZERO;
  #endif
  

  #if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
  /* Reset Dem_GaaMatchingDtcIndex*/
  (void) DEM_MEMSET(&Dem_GaaMatchingDtcIndex, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 "Reason: Dem_InternalFunc_c_REF_14"
                                             DEM_DTC_MAINEVT_SIZE); 
  #endif

  #if (DEM_NUMBER_OF_TIME_BASED_DEBOUNCE > DEM_ZERO)
  /* Reset Dem_GaaFDCDirectionTD */
  (void) DEM_MEMSET(&Dem_GaaFDCDirectionTD, (sint16)DEM_FDC_RESET, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                   DEM_NUMBER_OF_INTERNAL_TIME_BASED_DEBOUNCE);
  #endif
  #if (DEM_MAX_FDC_SINCE_CURRENT_CYCLE_SUPPORT_ENABLED == STD_ON)
  /* Reset Dem_GaaMaxFDCDCurCyc */

  (void) DEM_MEMSET(&Dem_GaaMaxFDCDCurCyc, (sint16)DEM_ZERO,// parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                      DEM_NUMBER_OF_EVENTS); 

  #endif
  #if (DEM_MAX_FDC_SINCE_LAST_CLR_SUPPORT_ENABLED == STD_ON)
  /* Reset Dem_GaaMaxFDCSLstClr */
  (void) DEM_MEMSET(&Dem_GaaMaxFDCSLstClr, (sint16)DEM_ZERO, // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14"
                                      DEM_MAX_FDC_SINCE_LAST_CLEAR_SIZE); 
  #endif


   #if (DEM_NUMBER_OF_CLIENTS > DEM_ONE)
   /* Loop for configured Clients */
   for (LucClientId = DEM_ZERO; LucClientId < DEM_NUMBER_OF_CLIENTS;
	                                                       LucClientId++)
   #endif
   {
     #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
     Dem_GaaGetNxtFltrdEvntCalled[LucClientId] = (uint16)DEM_ZERO;
     Dem_GaaGetNxtFltrdEvntCalled[LucClientId] = (uint16)DEM_ZERO;
     Dem_GaaFltrdEventCount[LucClientId] = (uint16)DEM_ZERO;
     #endif
     Dem_GaaCurDTCFilter[LucClientId] = (uint16)DEM_ZERO;
     Dem_GaaNumOfFilteredDtc[LucClientId] = (uint16)DEM_ZERO;
     Dem_GstRecordUpdate[LucClientId] = Dem_GstDefaultRecordUpdate;
   }

  #if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
  #if (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)
  #if (DEM_OBD_CENTRALIZED_PID21_HANDLING == STD_ON)
  /* Reset PID21 Data */
  Dem_GaaPID21Value[DEM_ZERO] = DEM_ZERO;
  Dem_GaaPID21Value[DEM_ONE]  = DEM_ZERO;
  /* Reset the Flag */
  Dem_GblSetDataPID21Call = DEM_FALSE;
  #endif
  #if (DEM_OBD_CENTRALIZED_PID31_HANDLING == STD_ON)
  /* Reset PID31 Data */
  Dem_GaaPID31Value[DEM_ZERO] = DEM_ZERO;
  Dem_GaaPID31Value[DEM_ONE] =  DEM_ZERO;
  #endif
  /* Reset PID4D Data */
  Dem_GaaPID4DValue[DEM_ZERO] = DEM_ZERO;
  Dem_GaaPID4DValue[DEM_ONE]  = DEM_ZERO;

  /* Reset PID4E Data */
  Dem_GaaPID4EValue[DEM_ZERO] = DEM_ZERO;
  Dem_GaaPID4EValue[DEM_ONE]  = DEM_ZERO;
  #endif
  #endif


} /* End Of Dem_ClearInitVariables */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_DtcCheckInMem                                   **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Checking status of DTC in memory                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : LucMaxNumOfEventEntry,DTC,LpEventMemory             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpStoredIndxs, LpNumOfEvts, LpEvtParameterIndx      **
**                        LpEventMemoryIndex                                  **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : DEM_EVENT_MEMORY_DESTINATION_CONFIGURED should be ON**
**                        and DEM_EVENT_MEMORY_DESTINATION_CONFIGURED greater **
**                        than zero                                           **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GaaEventParameter      **
**                        Function(s) invoked    : None                       **
**                                                                            **
** Design ID            : DEM_SDD_0312                                        **
*******************************************************************************/
#if ((DEM_EVENT_MEMORY_DESTINATION_CONFIGURED == STD_ON) &&   \
     (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
boolean  Dem_DtcCheckInMem
(const uint8 ClientId, const uint32 DTC, const Dem_EventMemory*  LpEventMemory, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
    const uint8 LucMaxNumOfEventEntry // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
    #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
    , uint8 *LpStoredIndxs, uint8 *LpNumOfEvts // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
    #else
    , uint16* const LpEvtParameterIndx // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
    , uint8* const LpEventMemoryIndex // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
    #endif
    )
{
  uint32   LulDTC;
  #if (((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
      (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) && \
     (DEM_OBD_DTC_SUPPORT == STD_ON))
  uint32  LulObdDtc;
  #endif
  uint16   LusEventParameterIndex;
  uint16   LusDtcInfoIndex;
  uint8    LucCount;
  boolean  LblDTCFound;
  boolean  LblDtcformat;
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
  uint8                   LucEvtCnt;
  LucEvtCnt = DEM_ZERO;
  #else
  boolean                 LblDtcEvtFound;
  LblDtcEvtFound = DEM_FALSE;
  #endif
  LblDTCFound = DEM_FALSE;

  /* Loop for all events in memory requested */
  for (LucCount = DEM_ZERO; ((LucCount < LucMaxNumOfEventEntry)
  #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
  && (!LblDtcEvtFound)
  #endif
  ); LucCount++)
  {
     /* polyspace +8 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
     /* Check if memory entry is filled */
     /* Polyspace InternalFunc_c_Ref_196 */
    if (((LpEventMemory + LucCount)->ddEventId != DEM_ZERO) && // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
    ((LpEventMemory + LucCount)->ddEventId <= DEM_NUMBER_OF_EVENTS)) // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
    {
      /* Fetch event index */
      /* Polyspace InternalFunc_c_Ref_196 */
      LusEventParameterIndex = (LpEventMemory + LucCount)->ddEventId - DEM_ONE; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
      /* polyspace +3 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* Get DTC Index for Event */
     /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      LusDtcInfoIndex = DEM_EVENT_MAPPED_DTC_INDEX(LusEventParameterIndex);
      /* Get the DTC value*/
      LulDTC = DEM_UDS_DTC_VALUE(LusDtcInfoIndex);
      LblDtcformat = DEM_DTC_FORMAT(LusDtcInfoIndex, Dem_GaaClientSelection[ClientId].ddDTCFormat);
      #if (((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
          (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) && \
         (DEM_OBD_DTC_SUPPORT == STD_ON))
      LulObdDtc = DEM_OBD_DTC_VALUE(LusDtcInfoIndex);
      #endif
      /* Check if dtc requested is configured   */
      /* Polyspace InternalFunc_c_Ref_118 */
      if ((LblDtcformat) &&
	     (((DTC  == LulDTC) && 
	       (Dem_GaaClientSelection[ClientId].ddDTCFormat == DEM_DTC_FORMAT_UDS))
         #if (((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
          (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) && \
         (DEM_OBD_DTC_SUPPORT == STD_ON))
    	  || ((DTC == LulObdDtc) && 
		((Dem_GaaClientSelection[ClientId].ddDTCFormat == DEM_DTC_FORMAT_OBD) ||
		(Dem_GaaClientSelection[ClientId].ddDTCFormat == 
		                                             DEM_DTC_FORMAT_OBD_3BYTE)))
		 #endif
		  ))
      { /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
        /* PRQA S 3383 4 */
        #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
        LpStoredIndxs[LucEvtCnt] = LucCount;
        /* Increment event count */
        LucEvtCnt++;
        #else
        /* Fetch event parameter index */
        *LpEvtParameterIndx = LusEventParameterIndex;
        /* Fetch memory index */
        *LpEventMemoryIndex = LucCount;
        /* Update LblDtcEvtFound flag */
        LblDtcEvtFound = DEM_TRUE;
        #endif
        /* Update LblDTCFound flag  */
        LblDTCFound = DEM_TRUE;
      }
    } /* End of check for valid event id */
  }  /* End of check for all memory entries configured */
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
  *LpNumOfEvts = LucEvtCnt;
  #endif
  return(LblDTCFound);
} /* End Of Dem_DtcCheckInMem */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_GetFFrecCount                                   **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : This API is used to obtain the count of Freeze      **
**                        Frame records.                                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : RecordNumber,LpStdInds                              **
**                                                                            **
** InOut parameter      : LpEventMemory,LpBufSize                             **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_EVENT_COMBINATION_SUPPORT should be Configured  **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GaaEventParameter      **
**                        Function(s) invoked    : None                       **
**                                                                            **
** Design ID            : DEM_SDD_0315                                        **
*******************************************************************************/
#if ((DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)  && \
        (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static void  Dem_GetFFrecCount(
  const uint8* const LpStdInds, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  const uint8 LucNumOfEvt, uint16* const LpBufSize, const uint8 RecordNumber, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  const Dem_EventMemory*  LpEventMemory)// parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10" 
{
  const Dem_DTCAttributeType*  LpDTCAttribute;
  uint16  LusEvtParamIndex;
  uint16  LusDidRawDataSize;
  uint8  LucNumOfRecs;
  uint8  LucNumOfFFRec;
  uint8  LucCount;
  uint8  LucRecCnt;
  uint8  LucNoOfDids;
  uint8  LucMemMappingIndex;
  #if (DEM_MAX_MONITOR_FF_RECDS_PER_EVENT > DEM_ZERO)
  uint16  LusMonitorFFDataSizeDtcAttr;
  #endif
  LucNumOfRecs = DEM_ZERO;
  LusDidRawDataSize = DEM_ZERO;
  LucNoOfDids = DEM_ZERO;
  #if (DEM_MAX_MONITOR_FF_RECDS_PER_EVENT > DEM_ZERO)
  LusMonitorFFDataSizeDtcAttr = DEM_ZERO;
  #endif
  /* Loop for all Events */
  for (LucCount = DEM_ZERO; LucCount < LucNumOfEvt; LucCount++)
  {
    /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
          /* PRQA S 3383 4 */
    /* polyspace +3 RTE:NIV [Justified:Low] "Refer Dem_c_Poly_REF_8" */
    /* polyspace +2 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* Fetch event parameter index */
    LusEvtParamIndex = LpEventMemory[LpStdInds[LucCount]].ddEventId - DEM_ONE;
  /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    LpDTCAttribute = Dem_GaaEventParameter[LusEvtParamIndex].pDTCAttribute;
    if (NULL_PTR  != LpDTCAttribute)
    {
      LucNoOfDids = LpDTCAttribute->ucNumOfDataId;
      LusDidRawDataSize = LpDTCAttribute->usFFRecordRawDataSize;
      #if (DEM_MAX_MONITOR_FF_RECDS_PER_EVENT > DEM_ZERO)
      LusMonitorFFDataSizeDtcAttr = LpDTCAttribute->usMonitorFFDataSizeDtcAttr;
      #endif
      Dem_EventSearchInMemory(LusEvtParamIndex, &LucMemMappingIndex);
      /* Get the number of Records configured for the event */
      if (Dem_GaaDTCOriginBasedPtrAddress[LucMemMappingIndex].ucFfRecordEnumType == 
         DEM_FF_RECNUM_CALCULATED)
      {
        /* Get the maximum no of FF records configured for the event*/
        LucNumOfFFRec = LpDTCAttribute->ucMaxNumOfFFRecord;
      }
      else
      {
        /* Get the maximum no of FF record numbers configured for the event */
        LucNumOfFFRec = LpDTCAttribute->ucNumOfFFRecNum;
      }
      for (LucRecCnt = DEM_ZERO; LucRecCnt < LucNumOfFFRec; LucRecCnt++)
      {
        /* Check if the requested FF record is stored in memory */
        if (LpEventMemory[LpStdInds[LucCount]].aaFFRecNumAndData[LucRecCnt]
          [DEM_ZERO] == RecordNumber)
        { /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
          /* PRQA S 3383 2 */
          /* Fetch number of records */
          LucNumOfRecs = LucNumOfRecs + DEM_ONE;
        }
      } /* End of loop for all records */
    } /* End of if(NULL_PTR  != LpDTCAttribute) */
  }  /* End of loop for all events*/
  /* Check if record Found */
  if (LucNumOfRecs != DEM_ZERO)
  {
    /* One freeze Frame Data Size = Total Didsize +
        Count of bytes for did number +
        Record number(1 byte) + No of Did(1 byte)(SWS PG NO:178) */
    *LpBufSize =
      LusDidRawDataSize + ((uint16)LucNoOfDids * (uint16)DEM_TWO) + // parasoft-suppress CERT_C-INT13-a-2 CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24"
      (uint16)DEM_TWO;
      
    #if (DEM_MAX_MONITOR_FF_RECDS_PER_EVENT > DEM_ZERO)
    /*Variable to store monitor data size for freeze frame data elements*/ 
    *LpBufSize += LusMonitorFFDataSizeDtcAttr;
    #endif
     /* Total Freeze Frame Data Size */
    (*LpBufSize) = (*LpBufSize) *  (uint16) LucNumOfRecs; // parasoft-suppress CERT_C-INT13-a-2 CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24"
  }
  else
  {
    (*LpBufSize) = DEM_ZERO;
  }
} /* End Of Dem_GetFFrecCount */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_GetEDrecCount                                   **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : API to get the Extended Data record count.          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : ExtendedDataNumber,LucNumOfEvt                      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpBufSize,LpEventMemory                             **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_EVENT_COMBINATION_SUPPORT should be             **
**                         DEM_EVCOMB_ONRETRIEVAL                             **
** Remarks              : Global Variable(s)     : Dem_GaaEventParameter,     **
**                                                 Dem_GaaEDRecord            **
**                        Function(s) invoked    : None                       **
**                                                                            **
** Design ID            : DEM_SDD_0314                                        **
*******************************************************************************/
#if ((DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL) && \
     (DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
     (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_GetEDrecCount(
          const uint8* const LpStdInds, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
          const uint8 LucNumOfEvt, uint16* const LpBufSize, const uint8 ExtendedDataNumber, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
          const Dem_EventMemory*  LpEventMemory)// parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
{
  uint16     LusEvtParamIndex;
  uint8      LucActualRecordIndex;
  uint8      LucNumOfEDRec;
  uint8      LucCount;
  uint8      LucRecCnt;
  boolean    LblRecordValid;
  LblRecordValid = DEM_FALSE;
  /* Loop for all events */
  for (LucCount = DEM_ZERO; LucCount < LucNumOfEvt; LucCount++)
  {  /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
     /* PRQA S 3383 2 */
     /* polyspace +1 RTE:NIV [Justified:Low] "Refer Dem_c_Poly_REF_8" */
    LusEvtParamIndex = LpEventMemory[LpStdInds[LucCount]].ddEventId - DEM_ONE;
  /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Check if dtc is not configured for event */
    if (NULL_PTR  != Dem_GaaEventParameter[LusEvtParamIndex].pDTCAttribute)
    {
      /* Get the number of Records configured for the event */
        /* Get the maximum no of ED records configured for the event*/
      LucNumOfEDRec =
      (Dem_GaaEventParameter[LusEvtParamIndex].pDTCAttribute)->ucNumOfEDRecords;
      for (LucRecCnt = DEM_ZERO; LucRecCnt < LucNumOfEDRec; LucRecCnt++)
      {
        LucActualRecordIndex = Dem_GaaEventParameter[LusEvtParamIndex].
                                pDTCAttribute->aaExtendedDataRecords[LucRecCnt];
        /* Check if the requested FF record is stored in memory */
        if (LpEventMemory[LpStdInds[LucCount]].aaEdData[LucRecCnt]
          [DEM_ZERO] == ExtendedDataNumber)
        {
          /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
          if (ExtendedDataNumber ==
               Dem_GaaEDRecord[LucActualRecordIndex].ucExtendedDataRecordNumber)
          {
            /* polyspace +2 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
            LblRecordValid = DEM_TRUE;
           *LpBufSize  = *LpBufSize + Dem_GaaEDRecord[LucActualRecordIndex].
                                                        usEDRecordRawDataSize;
           #if (DEM_MAX_MONITOR_ED_EXT_RECDS_PER_EVENT > DEM_ZERO)
           /* PRQA S 3383 2 */
            *LpBufSize += Dem_GaaEDRecord[LucActualRecordIndex].
                                                        usEDMonitorRawDataSize;     
           #endif                                                        
          }
        }
      } /* End of Loop for all Ed Records */
    }  /* End of Null pointer check */
  } /* End of Loop for all Events in the memory */

  if (DEM_TRUE == LblRecordValid)
  {
	 /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
     /* PRQA S 3383 2 */
     /* polyspace +1 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    *LpBufSize  = *LpBufSize + DEM_ONE;
  }
} /* End Of Dem_GetEDrecCount */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_GetCurrentFdcValueOfMonitor                     **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Get Current Fdc value from Monitor.                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LusEventIndex                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : FaultDetectionCounter                               **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_NUMBER_OF_MONITOR_INTERNAL_DEBOUNCE should be   **
**                        greater than Zero                                   **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GaaAllFDC,             **
**                                         Dem_GaaMonitorInternalDebounceClass**
**                        Function(s) invoked    : None                       **
**                                                                            **
** Design ID            : DEM_SDD_0609                                        **
*******************************************************************************/
#if (DEM_NUMBER_OF_MONITOR_INTERNAL_DEBOUNCE > DEM_ZERO)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_GetCurrentFdcValueOfMonitor
(const Dem_EventIdType LusEventIndex,
sint8* const LpFaultDetectionCounter) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  Std_ReturnType  LddMonitorRet;
  /* polyspace +6 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Check if Get FDC Call Back is configured */
  /* Polyspace InternalFunc_c_Ref_192 */
  /* Polyspace InternalFunc_c_Ref_202 */
  if (DEM_INVALID_CBK_GET_FDC_ROUTINE !=
     Dem_GaaMonitorInternalDebounceClass
	     [DEM_EVENT_DEBOUNCE_ALGORITHM_CLASS(LusEventIndex)].pDemCallBackGetFDC) // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Refer: Dem_InternalFunc_c_REF_18"
  {
    LddMonitorRet =
     Dem_GaaMonitorInternalDebounceClass
	 [DEM_EVENT_DEBOUNCE_ALGORITHM_CLASS(LusEventIndex)].pDemCallBackGetFDC // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Refer: Dem_InternalFunc_c_REF_18"
	                                                  (LpFaultDetectionCounter);
    /* if No proper Fdc is given from monitor, Pass stored Fdc value */
    if (E_OK  != LddMonitorRet)
    {
      /* Update the fault detection counter pointer */
      *LpFaultDetectionCounter = Dem_GaaAllFDC[LusEventIndex];
    }
  }
  /* Validation point to be added if callback is not
                                      configured for monitor */
} /* End Of Dem_GetCurrentFdcValueOfMonitor */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_FaultcheckInMemory                              **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Check for the Dtcs in Requested memory.             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LucClientId                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW should be ON    **
**                        DEM_OBD_SUPPORT should be configured                **
** Remarks              : Global Variable(s)     : Dem_GaaMatchingDtcIndex,   **
**                                                 Dem_GaaNumOfFilteredDtc,   **
**                                                 Dem_GaaChronlgOrdReq       **
**                        Function(s) invoked    : Dem_FilterEvent            **
**                                                                            **
** Design ID            : DEM_SDD_0606                                        **
*******************************************************************************/
#if (((DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_ON) || \
        (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT))  &&   \
      (DEM_EVENT_MEMORY_DESTINATION_CONFIGURED == STD_ON))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* #violates #ref Dem_InternalFunc_c_CERT_REF_2 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5001 1 */
void  Dem_FaultcheckInMemory (const uint8 LucClientId) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  #if ( DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)
  #if ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
       (DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > DEM_ZERO))
  const Dem_PermanentEventMemory*  LpPerEventMemory;
  #endif
  const Dem_EventMemory*           LpEventMemory;
  Dem_EventIdType                      LddEventId;
  #if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
  Std_ReturnType                                      LddReturnValue;
  #endif
  #if ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
       (DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > DEM_ZERO))
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
  uint16                               LusDtcCount;
  boolean                              LblDTCFound;
  #endif
  #endif
  uint16                               LusDtcInfoIndex;
  uint8                                LucNodeTailIndex;
  uint8                                LucMemMappingIndex;
  uint8                                LucOriginMask;
  #if ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
       (DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > DEM_ZERO))
  uint8                                LucLatestEvtCnt;
  #endif
  #if (DEM_NUMBER_OF_OBD_RELEVANT_MEMORY > DEM_ONE)
  uint8                                LucObdRelvntMemIndex;
  #endif
  /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  LucOriginMask = (uint8)Dem_GaaOriginFilter[LucClientId];
  /* Check if Origin is with in range of configured  memories */
  if (DEM_MAX_MEMORY_ID_CONF >= LucOriginMask)
  {
	#if ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
         (DEM_NUMBER_OF_OBD_RELEVANT_MEMORY > DEM_ZERO))
  if (DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY == LucOriginMask)
  {
	#if (DEM_NUMBER_OF_OBD_RELEVANT_MEMORY > DEM_ONE)
    for (LucObdRelvntMemIndex = DEM_ZERO; LucObdRelvntMemIndex <
                      DEM_NUMBER_OF_OBD_RELEVANT_MEMORY; LucObdRelvntMemIndex++)
    #endif
    {
      #if (DEM_NUMBER_OF_OBD_RELEVANT_MEMORY > DEM_ONE)
      Dem_GaaOriginMemMappingIndex[LucClientId] =
                        Dem_GaaObdRelevantMemMappingIndex[LucObdRelvntMemIndex];
      #endif
      /* Check for valid memory index */
      if (DEM_INVALID != Dem_GaaOriginMemMappingIndex[LucClientId])
      {
      /* polyspace +15 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        /* Get the event entries in memory based on DTCOrigin */
        LpEventMemory = Dem_GaaDTCOriginBasedPtrAddress[  // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
                                               Dem_GaaOriginMemMappingIndex[LucClientId]].pEventMemory; 
        /* Get Tail Index (Index Most recent entry in Event Memory) */
        LucNodeTailIndex = // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
                    Dem_GaaOldEvtCntHeadTailIndex[Dem_GaaOriginMemMappingIndex[LucClientId]][DEM_ONE]; 
        /* check if any event is stored in node */
        if (DEM_INVALID != LucNodeTailIndex)
        {
          /* Loop for all Stored Events */
          do
          {
            /* polyspace +7 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
            /* Get Stored EventID Value */
            LddEventId = (LpEventMemory + LucNodeTailIndex)->ddEventId;// parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            #if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
            /* Polyspace InternalFunc_c_Ref_196 */
            /* Polyspace InternalFunc_c_Ref_205 */
			/* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
            /* PRQA S 3383 14 */
            LddReturnValue =
            Dem_FilterEvent ((LddEventId - DEM_ONE), LucClientId);
			
            /* Load the DTC index into the buffer */
            LusDtcInfoIndex = DEM_EVENT_MAPPED_DTC_INDEX(LddEventId - DEM_ONE);    
            if ((E_OK == LddReturnValue) && 
			    (DEM_DTC_OBD_RELEVANT(LusDtcInfoIndex)))
            #endif
            {
              /* polyspace +10 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
              /* Polyspace InternalFunc_c_Ref_194 */
              Dem_GaaMatchingDtcIndex[Dem_GaaNumOfFilteredDtc[LucClientId]] =
                                                                LusDtcInfoIndex;
              Dem_WrapchkFiltrDtc(LucClientId);
            }
            /* Update Tail to previous location to fetch event Id */
            LucNodeTailIndex =
                   (LpEventMemory + LucNodeTailIndex)->ucPreviousIndex; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
          /* Check if any further entries are availabe */
          } while (DEM_INVALID != LucNodeTailIndex);
        } /* End of if(DEM_INVALID != LucNodeTailIndex) */
      } /* End of if(DEM_INVALID != LucMemMappingIndex) */
	  /* End of if (LucOriginMask != DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY) */
    }/* check if origin is other than obd relevant memory */
	}
	#endif
	#if ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
         (DEM_NUMBER_OF_OBD_RELEVANT_MEMORY > DEM_ZERO))
    else if (DEM_DTC_ORIGIN_PERMANENT_MEMORY != LucOriginMask)
	#else 
	if (DEM_DTC_ORIGIN_PERMANENT_MEMORY != LucOriginMask)
	#endif		
    {
      /* Get memory mapping index */
      LucMemMappingIndex = Dem_GaaDTCOriginMappingIndx[LucOriginMask];
      /* Check for valid memory index */
      if (DEM_INVALID != LucMemMappingIndex)
      {
      /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        /* Get the event entries in memory based on DTCOrigin */
        LpEventMemory = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
                                               LucMemMappingIndex].pEventMemory;
        /* Get Tail Index (Index Most recent entry in Event Memory) */
        LucNodeTailIndex = Dem_GaaOldEvtCntHeadTailIndex[LucMemMappingIndex][DEM_ONE]; // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11" 
        /* check if any event is stored in node */
        if (DEM_INVALID != LucNodeTailIndex)
        {
          /* Loop for all Stored Events */
          do
          {
            /* polyspace +7 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
            /* Get Stored EventID Value */
            LddEventId = (LpEventMemory + LucNodeTailIndex)->ddEventId; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            #if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
            /* Polyspace InternalFunc_c_Ref_196 */
            /* Polyspace InternalFunc_c_Ref_205 */
			/* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
            /* PRQA S 3383 15 */
            LddReturnValue =
            Dem_FilterEvent ((LddEventId - DEM_ONE), LucClientId);
            if (E_OK == LddReturnValue)
            #endif
            {
               /* polyspace +10 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
              /* Load the DTC index into the buffer */
              LusDtcInfoIndex =
                               DEM_EVENT_MAPPED_DTC_INDEX(LddEventId - DEM_ONE);
              /* Polyspace InternalFunc_c_Ref_194 */
              Dem_GaaMatchingDtcIndex[Dem_GaaNumOfFilteredDtc[LucClientId]] =
                                                                LusDtcInfoIndex;
              /* Increment the number of filtered DTC */
              Dem_WrapchkFiltrDtc(LucClientId);
            }
            /* Update Tail to previous location to fetch event Id */
            LucNodeTailIndex =
                   (LpEventMemory + LucNodeTailIndex)->ucPreviousIndex; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
          /* Check if any further entries are availabe */
          } while (DEM_INVALID != LucNodeTailIndex);
        } /* End of if(DEM_INVALID != LucNodeTailIndex) */
      } /* End of if(DEM_INVALID != LucMemMappingIndex) */
    } /* End of if (Dem_GaaOriginFilter != DEM_DTC_ORIGIN_PERMANENT_MEMORY) */
    #if ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
         (DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > DEM_ZERO))
    else
    {
      /* Pointer to Permanent Memory */
       
      LpPerEventMemory = &Dem_GstPerEventMemory[DEM_ZERO];
      
      /* Polyspace InternalFunc_c_Ref_205 */
      for (LucLatestEvtCnt = DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT;
        (LucLatestEvtCnt > DEM_ZERO); LucLatestEvtCnt--)
      {
        /* Polyspace InternalFunc_c_Ref_196 */
        /* Polyspace InternalFunc_c_Ref_205 */
        /* Check Events in Permanent Memory */
		/* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
        /* PRQA S 3383 15 */
        if ((LpPerEventMemory + (LucLatestEvtCnt - DEM_ONE))->ddEventId != // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
          DEM_ZERO)
        {
          #if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
          /* Polyspace InternalFunc_c_Ref_196 */
          LddReturnValue =
          Dem_FilterEvent ((LpPerEventMemory + // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
            (LucLatestEvtCnt - DEM_ONE))->ddEventId - DEM_ONE, LucClientId);
          if (E_OK == LddReturnValue)
          #endif
          {
             /* polyspace +7 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
            LusDtcInfoIndex = DEM_EVENT_MAPPED_DTC_INDEX((LpPerEventMemory + // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
                  (LucLatestEvtCnt - DEM_ONE))->ddEventId - DEM_ONE);
            #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
            /* Set dTC found Flag to False */
            LblDTCFound = DEM_FALSE;
            /* Loop through number for DTC filtered */
            LusDtcCount = Dem_GaaNumOfFilteredDtc[LucClientId];
            while (LusDtcCount > DEM_ZERO)
            {
              /* Point through next iteration */
              --LusDtcCount;
              /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_4" */
              /* Check if DTC is already filtered */
              if (Dem_GaaMatchingDtcIndex[LusDtcCount] == LusDtcInfoIndex)
              {
                LblDTCFound = DEM_TRUE;
              }
            }
            /* check if DTC is already filtered or not */
            if (!LblDTCFound)
            #endif
            {  /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
               /* PRQA S 3383 6 */
               /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_4" */
               /* Store filtered DTC */
               /* Store filtered DTC */
              Dem_GaaMatchingDtcIndex[Dem_GaaNumOfFilteredDtc[LucClientId]] =
                                                                LusDtcInfoIndex;
              Dem_WrapchkFiltrDtc(LucClientId);
            }
          } /* End of if(E_OK == LddReturnValue) */
        } /* End of EventId check in Permanent Memory */
      } /* End of loop through permenant memroy */
    } /* End of DEM_DTC_ORIGIN_PERMANENT_MEMORY) */
  #elif ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
         (DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT == DEM_ZERO) && \
		 (DEM_NUMBER_OF_OBD_RELEVANT_MEMORY > DEM_ZERO))
    else 
	{
		/* No operation */
	}
  #endif
  } /* End of if(DEM_MAX_MEMORY_ID_CONF < Dem_GaaOriginFilter) */
  #endif
  Dem_GaaChronlgOrdReq[LucClientId] = DEM_DTC_FILTER_DONE;
} /* End Of Dem_FaultcheckInMemory */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_WrapchkFiltrDtc                              **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Check for the Dtcs in Requested memory.             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LucClientId                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW should be ON    **
**                        DEM_OBD_SUPPORT should be configured                **
** Remarks              : Global Variable(s)     : Dem_GaaMatchingDtcIndex,   **
**                                                 Dem_GaaNumOfFilteredDtc,   **
**                                                 Dem_GaaChronlgOrdReq       **
**                        Function(s) invoked    : Dem_FilterEvent            **
**                                                                            **
** Design ID            : DEM_SDD_5775                                        **
*******************************************************************************/
#if (((DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_ON) || \
        (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT))  &&   \
      (DEM_EVENT_MEMORY_DESTINATION_CONFIGURED == STD_ON))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* #violates #ref Dem_InternalFunc_c_CERT_REF_2 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5001 1 */
static void  Dem_WrapchkFiltrDtc (const uint8 LucClientId) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  if (Dem_GaaNumOfFilteredDtc[LucClientId] < DEM_ARRAY_LIMIT)
  {                                                  
    ++Dem_GaaNumOfFilteredDtc[LucClientId];
  }
} /* End Of Dem_FaultcheckInMemory */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_RecordNumberCheckInMemory                              **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Check for the Dtcs in Requested memory.             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LucClientId                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GaaMatchingDtcIndex,   **
**                                                 Dem_GaaNumOfFilteredDtc,   **
**                                                 Dem_GaaChronlgOrdReq       **
**                        Function(s) invoked    : Dem_FilterEvent            **
**                                                                            **
** Design ID            : DEM_SDD_5117                                        **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* #violates #ref Dem_InternalFunc_c_CERT_REF_2 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5001 1 */
void  Dem_RecordNumberCheckInMemory(const uint8 LucClientId) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  #if ((DEM_MAX_ED_RECORDS_REFERRED > DEM_ZERO) && \
     (DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
     (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
  Dem_EventIdType                      LddEventId;
  uint16                               LusDtcInfoIndex;
  uint16                               LusEvtCnt;
  uint16                               LusEventCount;
  uint8                                LucCount;
  boolean                              LblDtcFormat;
  #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
  uint16                               LusDtcCount;
  boolean                              LblDTCFound;
  #endif
  #if ((DEM_DTC_SUPPRESSION_SUPPORT == STD_ON) || \
      (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
  boolean                              LblSuppressionStatus;
  #endif
   /* polyspace +8 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    LucCount = Dem_GaaRecordNumber[LucClientId];
	LusEventCount = (Dem_GaaEDRecordNumberList[LucCount].usNumOfEventsRef);
	for (LusEvtCnt = DEM_ZERO; LusEvtCnt < LusEventCount; LusEvtCnt++)
	{  
        /* PRQA S 3383 4 */
        LddEventId =  Dem_GaaEDRecordNumberList[LucCount].
		                                              usEventIdRef[LusEvtCnt];
		LusDtcInfoIndex = DEM_EVENT_MAPPED_DTC_INDEX(LddEventId - DEM_ONE); 
		#if ((DEM_DTC_SUPPRESSION_SUPPORT == STD_ON) || \
        (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
        /* polyspace +4 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        /* Load the suppression status */
        SchM_Enter_Dem_DEM_DATA_PROTECTION();
        LblSuppressionStatus = Dem_GaaSuppressionStatus[LusDtcInfoIndex];
        SchM_Exit_Dem_DEM_DATA_PROTECTION();
        #endif
        
        #if ((DEM_DTC_SUPPRESSION_SUPPORT == STD_ON) || \
            (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
        /* Check for suppression status */
        if (!LblSuppressionStatus)
        #endif
        {
        /* polyspace +10 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
         /* Get the Dtc Format */                            
         LblDtcFormat =
         DEM_DTC_FORMAT(LusDtcInfoIndex, (Dem_GaaDTCFormat[LucClientId]));
         if (LblDtcFormat)  
         {   
           #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
          /* Set dTC found Flag to False */
          LblDTCFound = DEM_FALSE;
          /* Loop through number for DTC filtered */
          LusDtcCount = Dem_GaaNumOfFilteredDtc[LucClientId];
          while (LusDtcCount > DEM_ZERO)
          {
            /* Point through next iteration */
            --LusDtcCount;
            /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_4" */
            /* Check if DTC is already filtered */
            if (Dem_GaaMatchingDtcIndex[LusDtcCount] == LusDtcInfoIndex)
            {
              LblDTCFound = DEM_TRUE;
            }
          }
          /* check if DTC is already filtered or not */
          if (!LblDTCFound)
          #endif
          {  
            /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_4" */            
            /* Polyspace InternalFunc_c_Ref_194 */
            Dem_GaaMatchingDtcIndex[Dem_GaaNumOfFilteredDtc[LucClientId]] =
                                                              LusDtcInfoIndex;
            if (Dem_GaaNumOfFilteredDtc[LucClientId] < DEM_ARRAY_LIMIT)
            { 
              /* Increment the number of filtered DTC */
              ++Dem_GaaNumOfFilteredDtc[LucClientId];
            }
          }
         }/* End of DTC format check*/
        }
	}		
  /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  Dem_GaaChronlgOrdReq[LucClientId] = DEM_DTC_FILTER_DONE;
 #endif
  
DEM_UNUSED(LucClientId);
} /* End Of Dem_RecordNumberCheckInMemory */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*******************************************************************************
** Function Name        : Dem_ReadinessGroupCheckInMemory                              **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Check for the Dtcs in Requested memory.             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LucClientId                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
** Remarks              : Global Variable(s)     : Dem_GaaMatchingDtcIndex,   **
**                                                 Dem_GaaNumOfFilteredDtc,   **
**                                                 Dem_GaaChronlgOrdReq       **
**                        Function(s) invoked    : Dem_FilterEvent            **
**                                                                            **
** Design ID            : DEM_SDD_0606                                        **
*******************************************************************************/
#if (DEM_OBD_READINESS_SUPPORTED == STD_ON)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* #violates #ref Dem_InternalFunc_c_CERT_REF_2 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5001 1 */
void  Dem_ReadinessGroupCheckInMemory (const uint8 LucClientId) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  #if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
  #if ((DEM_DTC_SUPPRESSION_SUPPORT == STD_ON) || \
        (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
  boolean                              LblSuppressionStatus;
  #endif
  #endif
  uint8                                LucReadiness;
  uint16                               LusDtcInfoIndex;
  uint16                               LusReadinessEventMappedID;
  uint16                               LusReadinessEventIDIndex;
  uint16                               Lusnumberofevents;
  boolean                              LblDtcFormat;

  #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
  uint16                               LusDtcCount;
  boolean                              LblDTCFound;
  #endif
  /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  LucReadiness = Dem_GaaReadinessGroup[LucClientId];
  Lusnumberofevents = Dem_GaaOBDEvtReadinessGrp[LucReadiness].usNumOfEvents;
  for (LusReadinessEventIDIndex = (uint16)DEM_ZERO; LusReadinessEventIDIndex < Lusnumberofevents; LusReadinessEventIDIndex++)
  {

    /* Check for valid memory index */
  /* polyspace +4 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_4" */
	/* PRQA S 3383 4 */
    LusReadinessEventMappedID = Dem_GaaOBDEvtReadinessGrp[LucReadiness].
                          aaOBDReadinessGroupEventID[LusReadinessEventIDIndex];
    LusDtcInfoIndex = DEM_EVENT_MAPPED_DTC_INDEX(LusReadinessEventMappedID - DEM_ONE);  
    #if ((DEM_DTC_SUPPRESSION_SUPPORT == STD_ON) || \
          (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
         /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
         /* Load the suppression status */
         SchM_Enter_Dem_DEM_DATA_PROTECTION();
         LblSuppressionStatus = Dem_GaaSuppressionStatus[LusDtcInfoIndex];
         SchM_Exit_Dem_DEM_DATA_PROTECTION();
    #endif
         
    #if ((DEM_DTC_SUPPRESSION_SUPPORT == STD_ON) || \
             (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
         /* Check for suppression status */
    if (!LblSuppressionStatus)
    #endif
    {
       /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_4" */
      /* Get the Dtc Format */                            
      LblDtcFormat =
      DEM_DTC_FORMAT(LusDtcInfoIndex, (Dem_GaaDTCFormat[LucClientId]));
      if ((LblDtcFormat) && (DEM_DTC_OBD_RELEVANT(LusDtcInfoIndex)))  
      {  
        #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
        /* Set dTC found Flag to False */
        LblDTCFound = DEM_FALSE;
        /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_4" */
        /* Loop through number for DTC filtered */
         SchM_Enter_Dem_DEM_DATA_PROTECTION();
        LusDtcCount = Dem_GaaNumOfFilteredDtc[LucClientId];
        SchM_Exit_Dem_DEM_DATA_PROTECTION();
        while (LusDtcCount > DEM_ZERO)
        {
          /* Point through next iteration */
          --LusDtcCount;
          /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_4" */
          /* Check if DTC is already filtered */
          if (Dem_GaaMatchingDtcIndex[LusDtcCount] == LusDtcInfoIndex)
          {
            LblDTCFound = DEM_TRUE;
          }
        }
        /* check if DTC is already filtered or not */
        if (!LblDTCFound)
        #endif
        { 
          /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_4" */
          /* Polyspace InternalFunc_c_Ref_194 */
          Dem_GaaMatchingDtcIndex[Dem_GaaNumOfFilteredDtc[LucClientId]] =
                                                           LusDtcInfoIndex;
          if (Dem_GaaNumOfFilteredDtc[LucClientId] < DEM_ARRAY_LIMIT)
          {
            /* Increment the number of filtered DTC */
            ++Dem_GaaNumOfFilteredDtc[LucClientId];
          }
        }
      }/* End of DTC format check*/
    }/*End of DTC Suppression Check*/
        
  } 
    Dem_GaaChronlgOrdReq[LucClientId] = DEM_DTC_FILTER_DONE;    


} /* End Of Dem_FaultcheckInMemory */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
 #endif
/*******************************************************************************
** Function Name        : Dem_FilterEvent                                     **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : To Check the requested event if filter              **
**                        conditions are met.                                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LusEventIndex, LucClientId                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GaaEventParameter,     **
**                                                 Dem_GaaAllDtcStatus,       **
**                                                 Dem_GaaAllEvtStatus,       **
**                                                 Dem_GaaCurDTCFilter,       **
**                                                 Dem_GaaDTCFormat,          **
**                                                 Dem_GaaAllFDC,             **
**                                               Dem_GaaCurDTCFilterStatusMask**
**                        Function(s) invoked    : None                       **
**                                                                            **
** Design ID            : DEM_SDD_0608                                        **
*******************************************************************************/
#if (((DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_ON) || \
        (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT))  &&   \
      (DEM_EVENT_MEMORY_DESTINATION_CONFIGURED == STD_ON) && \
	  (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static Std_ReturnType 
          Dem_FilterEvent (const uint16 LusEventIndex, const uint8 LucClientId) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  Dem_DTCSeverityType  LddDtcSeverity;
  Std_ReturnType       LddReturnValue;
  uint16               LusDtcInfoIndex;
  uint8                LucStatus;
  boolean              LblDtcFormat;
  #if ((DEM_DTC_SUPPRESSION_SUPPORT == STD_ON) || \
      (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
  boolean              LblSuppressionStatus;
  #endif

  LddReturnValue = E_OK;
  /* polyspace +10 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* polyspace +4 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  LusDtcInfoIndex = DEM_EVENT_MAPPED_DTC_INDEX(LusEventIndex);
  #if ((DEM_DTC_SUPPRESSION_SUPPORT == STD_ON) || \
      (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
  /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Load the suppression status */
  LblSuppressionStatus = Dem_GaaSuppressionStatus[LusDtcInfoIndex];
  #endif

  #if ((DEM_DTC_SUPPRESSION_SUPPORT == STD_ON) || \
      (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
  /* Check for suppression status */
  if (!LblSuppressionStatus)
  #endif
  {
    SchM_Enter_Dem_DEM_DATA_PROTECTION();
  /* polyspace +15 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Get the status of the DTC */
    LucStatus =
    #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_DISABLED)
    Dem_GaaAllEvtStatus[LusEventIndex];
    #else
    Dem_GaaAllDtcStatus[LusDtcInfoIndex];
    #endif
    SchM_Exit_Dem_DEM_DATA_PROTECTION();
    /* Get format of the DTC */
    LblDtcFormat =
            DEM_DTC_FORMAT(LusDtcInfoIndex, (Dem_GaaDTCFormat[LucClientId]));
    /* Get the severity */
    LddDtcSeverity = DEM_DTC_SEVERITY(LusDtcInfoIndex);

    if (!LblDtcFormat)
    {
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      /* To avoid QAC warnings*/
    }

    /* Status checking is not required if Origin is permanent because, status of
       events which are in permanent memory can change even after it is
       permanently stored */
     /* polyspace +15 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    if (Dem_GaaOriginFilter[LucClientId] != DEM_DTC_ORIGIN_PERMANENT_MEMORY)
    {
      if (((LucStatus & Dem_GaaCurDTCFilterStatusMask[LucClientId] & // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
           DEM_EVENTSTATUS_BIT2_SET) != DEM_EVENTSTATUS_BIT2_SET) && // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
          ((LucStatus & Dem_GaaCurDTCFilterStatusMask[LucClientId] & // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
            DEM_EVENTSTATUS_BIT3_SET) != DEM_EVENTSTATUS_BIT3_SET)) // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
      {
        LddReturnValue = E_NOT_OK;
      }
    }

    /* Check for DTCSeverity filter matching */
    if ((Dem_GaaCurDTCFilter[LucClientId] & (uint16) DEM_ONE) ==  // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
                                       (uint16)DEM_DTC_FILTER_WITH_SEVERITY_YES)  // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
    {
      /* polyspace +15 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      if ((uint16) (((uint16)LddDtcSeverity) &  // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
        ((Dem_GaaCurDTCFilter[LucClientId] & (uint16)DEM_MASK1))) == (uint16) DEM_ZERO)  // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
      {
        /* Error case */
        LddReturnValue = E_NOT_OK;
      }
    }
    /* polyspace +15 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Check if Filter with FDC supported */
    if (((Dem_GaaCurDTCFilter[LucClientId] & (uint16)DEM_FDC_MASK) >> DEM_TEN) ==  // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
      (uint16)DEM_DTC_FILTER_FOR_FDC_YES)  // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
    {
      SchM_Enter_Dem_DEM_DATA_PROTECTION();
      /* polyspace +15 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      /* The FDC values should be in the range 0x01-0x7E */
	  /* #violates #ref Dem_InternalFunc_c_REF_25  Violates MISRA 2012 Required Rule INT02 */
      /* PRQA S 2104 4 */
	  /* #violates #ref Dem_InternalFunc_c_REF_26  Violates MISRA 2012 Required Rule STR34 */
      /* PRQA S 2144 2 */
      if ((Dem_GaaAllFDC[LusEventIndex] <= (sint8)DEM_ZERO) ||  // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
            (Dem_GaaAllFDC[LusEventIndex] == (sint8)(DEM_FDC_COUNTER_MAX)))  // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
      {
        /* Error case */
        LddReturnValue = E_NOT_OK;
      }
      SchM_Exit_Dem_DEM_DATA_PROTECTION();
    }
    else
    {
      /* To avoid warnings */
    }
  }
  #if ((DEM_DTC_SUPPRESSION_SUPPORT == STD_ON) || \
      (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
  else
  {
    /* Error case */
    LddReturnValue = E_NOT_OK;
  }
  #endif
  /* Return status */
  return (LddReturnValue);
} /* End Of Dem_FilterEvent */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_GetMaxFdcOfDtc                                  **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : API to Return Max FDC of the Current Dtc requested  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpDTCAttribute                                      **
**                                                                            **
** InOut parameter      : DestBuffer                                          **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_EVENT_COMBINATION_SUPPORT should be configured  **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GaaAllFDC              **
**                        Function(s) invoked    : None                       **
**                                                                            **
** Design ID            : DEM_SDD_0610                                        **
*******************************************************************************/
#if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO) && \
   (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)
#if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static void 
Dem_GetMaxFdcOfDtc(uint8*  LpDestBuffer, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
const uint16 LusEventParameterIndex) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  uint16  LusDtcInfoIndex;
  uint16  LusEventIndex;
  #if (DEM_MAX_NUM_EVENTS_PER_DTC > DEM_ONE)
  uint16  LusNoOfCombinedEvents;
  uint16  LusCombinedEvent;
  sint8  LscFDCValue;
  #endif
  /* polyspace +6 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  /* Get DTC Index for Event */
  /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  LusDtcInfoIndex = DEM_EVENT_MAPPED_DTC_INDEX(LusEventParameterIndex);
  #if (DEM_MAX_NUM_EVENTS_PER_DTC > DEM_ONE)
  #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
  LusNoOfCombinedEvents = DEM_DTC_NUMBER_OF_EVENTS(LusDtcInfoIndex);
  #endif
  #endif
  /* Fetch the Event Index from DTCAttribute */
  LusEventIndex = DEM_DTC_COMBINED_EVENTS(LusDtcInfoIndex, DEM_ZERO);
  #if (DEM_MAX_NUM_EVENTS_PER_DTC > DEM_ONE)
  if (DEM_ONE == LusNoOfCombinedEvents)
  #endif
  {
	/* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Polyspace InternalFunc_c_Ref_203 */
    /* Polyspace InternalFunc_c_Ref_204 */
    /* Obtain the FDC Status */
    *LpDestBuffer = (uint8) Dem_GaaAllFDC[LusEventIndex];
  }
  #if (DEM_MAX_NUM_EVENTS_PER_DTC > DEM_ONE)
  else if (LusNoOfCombinedEvents <= DEM_MAX_NUM_EVENTS_PER_DTC)
  {
	 /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Polyspace InternalFunc_c_Ref_203 */
    /* Polyspace InternalFunc_c_Ref_204 */
    LscFDCValue = Dem_GaaAllFDC[LusEventIndex];
    /* Loop through the no. of combined events to find the max FDC */
    for (LusCombinedEvent = DEM_ONE; (LusCombinedEvent <
      LusNoOfCombinedEvents);
      LusCombinedEvent++)
    {
      /* Polyspace InternalFunc_c_Ref_203 */
      /* Polyspace InternalFunc_c_Ref_204 */
      /* Fetch the Event Index from DTCAttribute */
      LusEventIndex =
                 DEM_DTC_COMBINED_EVENTS(LusDtcInfoIndex, LusCombinedEvent);
      /* Polyspace InternalFunc_c_Ref_202 */
      /* Polyspace InternalFunc_c_Ref_203 */
      /* Polyspace InternalFunc_c_Ref_204 */
	   /* polyspace +8 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
	  /* #violates #ref Dem_InternalFunc_c_REF_26  Violates MISRA 2012 Required Rule STR34 */
      /* PRQA S 2144 6 */
	  /* #violates #ref Dem_InternalFunc_c_REF_25  Violates MISRA 2012 Required Rule INT02 */
      /* PRQA S 2104 4 */
      if (LscFDCValue < Dem_GaaAllFDC[LusEventIndex])
      {
        LscFDCValue = Dem_GaaAllFDC[LusEventIndex];
      }

      /* Polyspace InternalFunc_c_Ref_202 */
	  /* #violates #ref Dem_InternalFunc_c_REF_25  Violates MISRA 2012 Required Rule INT02 */
      /* PRQA S 2104 3 */
	  /* #violates #ref Dem_InternalFunc_c_REF_26  Violates MISRA 2012 Required Rule STR34 */
      /* PRQA S 2144 1 */
      if (DEM_FDC_COUNTER_MAX == Dem_GaaAllFDC[LusEventIndex])  // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
      {
        /* Break: Max Fdc found */
        break;
      }
    }
    *LpDestBuffer = (uint8)LscFDCValue;
  }
  else
  {
	/* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
	*LpDestBuffer = (uint8) Dem_GaaAllFDC[LusEventIndex];
  }
  #endif
} /* End Of Dem_GetMaxFdcOfDtc */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
#endif

/*******************************************************************************
** Function Name        : Dem_CheckExtendedDataRecord                         **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Checks the type of data of an extended data record  **
**                        by event.                                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpEventMemory, LpDTCAttribute, LucFreeIndex         **
**                        RecordNumber,LusEventParameterIndex ,LucNumOfEDRecords
**                                                                            **
** InOut parameter      : LblRecFound                                         **
**                                                                            **
** Output Parameters    : DestBuffer                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_ED_RECDS should be greater than   **
**                        Zero                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked :                               **
**                                      Dem_EvaluateInternalExtendedDataRecord**
**                                                                            **
** Design ID            : DEM_SDD_0602                                        **
*******************************************************************************/
#if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
    (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* #violates #ref Dem_InternalFunc_c_CERT_REF_2 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5001 11 */
static Std_ReturnType  Dem_CheckExtendedDataRecord
  (const uint8 RecordNumber,  const uint8 LucServiceId,  // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   uint8 *DestBuffer, uint16 *BufSize, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
   const Dem_EventMemory*  LpEventMemory, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
   const Dem_DTCAttributeType*  const LpDTCAttribute, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   #if (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)
   const uint16 LusEventParameterIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   #endif
   const uint8 LucFreeIndex, const uint8 LucNumOfEDRecords, boolean* const LblRecFound // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   #if (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)
   , const Dem_DTCOriginType LucEventDestination // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   #endif
   )
{
  Std_ReturnType         LddReturnValue;

  #if ((DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS > DEM_ZERO) ||\
  (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR > DEM_ZERO))
  uint16  LusRecSize;
  uint16  LusTempIndex;
  uint8   LucCurrentBufferExtIndex;
  uint8   LusRecDataIndexToBuffer;
  #endif
  uint8   LucRecIndex;
  uint8   LucCurrentBufferIndex;
  uint8   LucActualRecordIndex;
  uint8   LucDataElementIndex;
  #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
  uint8    LucMonitorDataByte;
  uint8    LucMonitorDataSupport;
  uint8    LucReadMonitorEDdataStack;
  #endif

  /* Initialize return to E_OK */
  LddReturnValue = E_OK;
     /* Initialize monitor data stack variable*/
    #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
    LucReadMonitorEDdataStack = DEM_ZERO;
    #endif
               
  /* Loop for all Extended data Records */
  for (LucRecIndex = DEM_ZERO ; ((LucRecIndex < LucNumOfEDRecords) &&
              (!(*LblRecFound))); LucRecIndex++)
  {
    /* Initialize current buffer index */
    LucCurrentBufferIndex = DEM_ZERO;
    #if ((DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS > DEM_ZERO) ||\
         (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR > DEM_ZERO))
    LucCurrentBufferExtIndex = DEM_ZERO;
    #endif
  /* polyspace +6 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* If Event exist in Memory then  records data element should be of
                                                    External Type */
    if ((LpEventMemory + LucFreeIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
  /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Polyspace InternalFunc_c_Ref_109 */
         aaEdData[LucRecIndex][DEM_ZERO] == RecordNumber)
    {
      /* Get the Actual record index */
      LucActualRecordIndex = LpDTCAttribute->
                          aaExtendedDataRecords[LucRecIndex];
      /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      if (RecordNumber ==
               Dem_GaaEDRecord[LucActualRecordIndex].ucExtendedDataRecordNumber)
      {
        #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
        if (LucReadMonitorEDdataStack < DEM_MAX_MONITOR_ED_RECDS_PER_EVENT)
        {
          LucReadMonitorEDdataStack++;
        } 
         #endif
        
        /* Loop for all data elements in the memory */
        for (LucDataElementIndex = DEM_ZERO; (LucDataElementIndex <
          Dem_GaaEDRecord[LucActualRecordIndex].
          ucNumOfDataElements);
          LucDataElementIndex++)
        {
          /* Check Record containing internal data elements */
          /* and trig satisfied for the record*/
          #if (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)
      /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
          if (((Dem_GaaEDRecord[LucActualRecordIndex].
          aaDataElementType[LucDataElementIndex]) ==
          (uint8)DEM_DATA_ELEMENT_INTERNAL))
          {
            /* Check if record is of type INTERNAL_DATA_ELEMENT */
            LddReturnValue = Dem_EvaluateInternalExtendedDataRecord(
            DestBuffer,
            LpDTCAttribute,
            &LucCurrentBufferIndex,
            LucDataElementIndex,
            LusEventParameterIndex,
            LucFreeIndex,
            LucRecIndex, LblRecFound
            , LucEventDestination
             #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
            , &LucReadMonitorEDdataStack
             #endif
            );
            *BufSize = LucCurrentBufferIndex;
          }
          else
          #endif
          {
             /* Fetch the size of the data element */
            #if ((DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS > DEM_ZERO) ||\
                 (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR > DEM_ZERO))
            /* Get the index of the data element */
            LusTempIndex = Dem_GaaEDRecord[LucActualRecordIndex].
                                  aaDataElementIndex[LucDataElementIndex];
            LusRecSize = DEM_ZERO;
            #if (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS > DEM_ZERO)
            if ((uint8)DEM_DATA_ELEMENT_EXTERNAL_CS ==  // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
                        (Dem_GaaEDRecord[LucActualRecordIndex].  // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
                                        aaDataElementType[LucDataElementIndex]))  // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
            {
        /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
              /* Data element size is fetched from Client server interface */
              LusRecSize = Dem_GaaDataElementExternalCS[LusTempIndex].
                        ucDemDataElementDataSize;
            }
            #endif

            #if (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR > DEM_ZERO)
            if ((uint8)DEM_DATA_ELEMENT_EXTERNAL_SR ==
                        (Dem_GaaEDRecord[LucActualRecordIndex].
                                        aaDataElementType[LucDataElementIndex]))
            {
              /* Data element size is fetched from Sender Receiver interface */
              LusRecSize = Dem_GaaDataElementExternalSR[LusTempIndex].
                        ucDemDataElementDataSize;
            }
            #endif
            /* Loop for size of the record byte by byte  */
            for (LusRecDataIndexToBuffer = DEM_ZERO;
                LusRecDataIndexToBuffer < LusRecSize; LusRecDataIndexToBuffer++) // parasoft-suppress CERT_C-INT13-a-2 CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24" 
            {
              *(DestBuffer + LucCurrentBufferIndex) = // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
               (LpEventMemory + LucFreeIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
			   /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
               /* PRQA S 3383 35 */
               /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
               /* Polyspace InternalFunc_c_Ref_111 */
               /* Polyspace InternalFunc_c_Ref_112 */
               aaEdData[LucRecIndex][DEM_ONE + LucCurrentBufferExtIndex];
                 LucCurrentBufferIndex++;
                  LucCurrentBufferExtIndex++; 
            }
            #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
            LucMonitorDataSupport = Dem_GaaEDRecord[LucActualRecordIndex].
                  aaDataElementMonitorDataSupport[LucDataElementIndex];
            if ((LucMonitorDataSupport == DEM_MONITOR_TRUE) && 
            ((LucReadMonitorEDdataStack - DEM_ONE) <
                                            DEM_MAX_MONITOR_ED_RECDS_PER_EVENT))
            {  
            LucMonitorDataByte = (uint8)((LpEventMemory + LucFreeIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
                  aaEdMonitorData[LucReadMonitorEDdataStack - DEM_ONE][DEM_ONE]);
            *(DestBuffer + LucCurrentBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            LucCurrentBufferIndex++;
            LucMonitorDataByte = (uint8)((LpEventMemory + LucFreeIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            aaEdMonitorData[LucReadMonitorEDdataStack - DEM_ONE][DEM_ONE] >> DEM_ONE_BYTE);
            *(DestBuffer + LucCurrentBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            LucCurrentBufferIndex++;
            LucMonitorDataByte = (uint8)((LpEventMemory + LucFreeIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
               aaEdMonitorData[LucReadMonitorEDdataStack - DEM_ONE][DEM_ONE] >> DEM_TWO_BYTE);
            *(DestBuffer + LucCurrentBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            LucCurrentBufferIndex++;
            LucMonitorDataByte = (uint8)((LpEventMemory + LucFreeIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            aaEdMonitorData[LucReadMonitorEDdataStack - DEM_ONE][DEM_ONE] >> DEM_THREE_BYTE);

            *(DestBuffer + LucCurrentBufferIndex) = LucMonitorDataByte; 
            LucCurrentBufferIndex++;
            LusRecSize = LusRecSize + DEM_FOUR;
            }
            #endif               
            *BufSize = LusRecSize;
            #else
            *BufSize = DEM_ZERO;
            #endif
          }
        }
        /* Update record found to DEM_TRUE */
        *LblRecFound = DEM_TRUE;
      }
    }
    else
    {
      /* Get the Actual record index */
      LucActualRecordIndex = LpDTCAttribute->
                                  aaExtendedDataRecords[LucRecIndex];
    /* polyspace +4 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      /* Check if record is valid(configured) */
      if (Dem_GaaEDRecord
      [LucActualRecordIndex].
                         ucExtendedDataRecordNumber == RecordNumber)
      {
        *LblRecFound = DEM_TRUE;
        (void)Det_ReportRuntimeError(DEM_MODULE_ID, DEM_INSTANCE_ID,
        LucServiceId, DEM_E_NODATAAVAILABLE);
        /* valid record number but data is not available */
        /* Failure of Trigger */
        LddReturnValue = DEM_NO_SUCH_ELEMENT;
      }
    }
    
  } /* End of Record looping*/
  return(LddReturnValue);
} /* End of Dem_CheckExtendedDataRecord */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_EvaluateInternalExtendedDataRecord              **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Evaluates the internal extended data Records        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : RecordNumber, LpEventMemory, LpDTCAttribute,        **
                          LusEventParameterIndex, LucEventDestination,
                          LucFreeIndex                                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : DestBuffer                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_ED_RECDS should be greater than   **
**                        Zero                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GaaEDRecord            **
**                        Function(s) invoked    : Det_ReportError,           **
**                                                 Dem_UDMemoryIndexFetch     **
**                                                                            **
** Design ID            : DEM_SDD_0604                                        **
*******************************************************************************/
#if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
    (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO) && \
    (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static Std_ReturnType  Dem_EvaluateInternalExtendedDataRecord
  (
   uint8 *DestBuffer, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
   const Dem_DTCAttributeType* const LpDTCAttribute, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   uint8*  LpCurrentBufferIndex, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   const uint8 LucDataElementIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   const uint16 LusEventParameterIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   const uint8 LucFreeIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   const uint8 LucRecIndex, boolean* const LblRecFound // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   , const Dem_DTCOriginType LucEventDestination // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)

  , uint8* const LpReadMonitorEDdataStack
   #endif
  )
{
  Dem_DTCOriginType     LddDTCOrigin;
  /* Initialize return to E_OK */
  const Std_ReturnType  LddReturnValue = E_OK;
   #if ((DEM_DTR_INTERNAL_DATAELEMENT == STD_ON) || \
       (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON) || \
       (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON) || \
       (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON))
  Std_ReturnType  LddReturnValue1 ;
  #endif
  uint8                 LucActualRecordIndex;
  uint8                 LucDataElement;
  #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
  uint8               LucMonitorDataByte;
  #endif
  #if ((DEM_OP_CYCLE_CTR_SUPPORT == STD_ON) ||\
	       (DEM_MAX_FDC_SINCE_LAST_CLR_SUPPORT_ENABLED == STD_ON))
  uint16                 LusEvtInternaldataindex;
  #endif
 #if ((DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO) || \
      (DEM_NUM_OF_EVENT_WITH_ASSOCIATED_IDENTIFICATION > DEM_ZERO))
  const Dem_EventMemory*     LpEventMemory;
  #endif
   #if (DEM_NUM_OF_EVENT_WITH_ASSOCIATED_IDENTIFICATION > DEM_ZERO)
  uint16                                  LusEventData; 
  #endif
  LddDTCOrigin = DEM_ZERO;
 #if ((DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO) || \
      (DEM_NUM_OF_EVENT_WITH_ASSOCIATED_IDENTIFICATION > DEM_ZERO))

      /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      /* Pointer to Event Memeory */
  LpEventMemory =  Dem_GaaDTCOriginBasedPtrAddress[
                 Dem_GaaDTCOriginMappingIndx[LucEventDestination]].pEventMemory;
   #endif 
  /* Get the Actual record index */
  LucActualRecordIndex = LpDTCAttribute->aaExtendedDataRecords[LucRecIndex];
  /* Check if data element is of Internal Type */
  LucDataElement = Dem_GaaDataElementInternal
  /* polyspace +4 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Polyspace InternalFunc_c_Ref_189 */
                      [Dem_GaaEDRecord[LucActualRecordIndex].
                                  aaDataElementIndex[LucDataElementIndex]].
                                                  ucDemInternalDataElement;
      #if ((DEM_DTR_INTERNAL_DATAELEMENT == STD_ON) || \
       (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON) || \
       (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON) || \
       (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON))
        LddReturnValue1 = Dem_CheckInternaldateleForIumprMonitorActiDtr(LucDataElement);
        #endif
     /* Check if data element is configured and data element is  
           overflowindication*/
    /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    if (((Dem_GaaInternalDataElements
         [LucDataElement].pInternalDataElement) != NULL_PTR) &&
         (LucDataElement == DEM_OVFLIND))
    {
      Dem_ProcessEventMemoryDestination(LucEventDestination, &LddDTCOrigin);
	   /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
       /* PRQA S 3383 8 */
       /* Update data in the buffer */
       /* Polyspace InternalFunc_c_Ref_114 */
      *(DestBuffer + *LpCurrentBufferIndex) = // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
         *((uint8 *)(Dem_GaaInternalDataElements
         [LucDataElement].pInternalDataElement) + // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
         LddDTCOrigin);
      /* Next Location */
      ++(*LpCurrentBufferIndex);
    }
    #if ((DEM_DTR_INTERNAL_DATAELEMENT == STD_ON) || \
       (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON) || \
       (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON) || \
       (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON))
    else if (LddReturnValue1 == E_OK)
    {
      Dem_ProcessIumprMonitorDtr(LucDataElement, 
      #if ((DEM_DTR_INTERNAL_DATAELEMENT == STD_ON) || (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON) || \
      (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON))
      LpCurrentBufferIndex,
     #endif
     DestBuffer, LusEventParameterIndex );
    }
    #endif  
     /* Check if data element is configured and data element is  
           DTC Priority*/
    /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    else if (((Dem_GaaInternalDataElements
         [LucDataElement].pInternalDataElement) == NULL_PTR) &&
         (LucDataElement == DEM_DTC_PRIORITY))
    { /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
      /* PRQA S 3383 5 */
      /* Update data in the buffer */
      /* Polyspace InternalFunc_c_Ref_114 */
      *(DestBuffer + *LpCurrentBufferIndex) = LpDTCAttribute->DTCPriority; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
      /* Next Location */
      ++(*LpCurrentBufferIndex);
    }
	/* PRQA S 3383 50 */
	
     /* Check if data element is configured and data element is  
           Event assicated indication*/
        /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  #if (DEM_NUM_OF_EVENT_WITH_ASSOCIATED_IDENTIFICATION > DEM_ZERO)
   else if (((Dem_GaaInternalDataElements
         [LucDataElement].pInternalDataElement) == NULL_PTR) &&
         (LucDataElement == DEM_EVENT_ASSOCIATED_IDENTIFICATION))
    {
      
      /* Update data in the buffer */
      /* Polyspace InternalFunc_c_Ref_114 */
       /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
       /* PRQA S 3383 8 */
      LusEventData = DEM_ASSOCIATED_IDENTIFICATION((LpEventMemory + // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
                                             LucFreeIndex)->ddEventId - DEM_ONE);
      *(DestBuffer + *LpCurrentBufferIndex) = (uint8)LusEventData; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
         
      ++(*LpCurrentBufferIndex);
        *(DestBuffer + *LpCurrentBufferIndex) = (uint8)(LusEventData >> DEM_ONE_BYTE) ; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
      /* Next Location */
      ++(*LpCurrentBufferIndex);
    }
 #endif   
    else if (((((Dem_GaaInternalDataElements
               [LucDataElement].pInternalDataElement) != NULL_PTR) &&
               (LucDataElement != DEM_OVFLIND)) && // parasoft-suppress CERT_C-MSC12-j-3 "Refer: Dem_InternalFunc_c_REF_12"
               (LucDataElement != DEM_MONITOR_DATA_0)) && // parasoft-suppress CERT_C-MSC12-j-3 "Refer: Dem_InternalFunc_c_REF_12"
               (LucDataElement != DEM_MONITOR_DATA_1)) // parasoft-suppress CERT_C-MSC12-j-3 "Refer: Dem_InternalFunc_c_REF_12"
    { /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
      /* PRQA S 3383 40 */
      /* polyspace +9 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
      /* Update with internal data element in the pointer location */
	  #if ((DEM_OP_CYCLE_CTR_SUPPORT == STD_ON) ||\
	      (DEM_MAX_FDC_SINCE_LAST_CLR_SUPPORT_ENABLED == STD_ON))
	  switch (LucDataElement) // parasoft-suppress CDD-DUPC-3 "Refer: Dem_Cfg_c_REF_15"
	  {
		 #if (DEM_OP_CYCLE_CTR_FAILED_CYCLES_ENABLED == STD_ON)
		 case DEM_FAILED_CYCLES:
		 LusEvtInternaldataindex = Dem_GaaEventParameter[LusEventParameterIndex].ucfailedcycleindex;
		 break;
		 #endif
		 #if (DEM_OP_CYCLE_CTR_SINCE_LAST_FAILED_ENABLED == STD_ON)
		 case DEM_CYCLES_SINCE_LAST_FAILED:
		 LusEvtInternaldataindex = Dem_GaaEventParameter[LusEventParameterIndex].uclastfailedindex;
		 break;
		 #endif
		 #if (DEM_OP_CYCLE_CTR_SINCE_FIRST_FAILED_ENABLED == STD_ON)
		 case DEM_CYCLES_SINCE_FIRST_FAILED:
		 LusEvtInternaldataindex = Dem_GaaEventParameter[LusEventParameterIndex].ucfirstfailedindex;
		 break;
		 #endif
		 #if (DEM_MAX_FDC_SINCE_LAST_CLR_SUPPORT_ENABLED == STD_ON)
		 case DEM_MAX_FDC_SINCE_LAST_CLEAR:
		 LusEvtInternaldataindex = Dem_GaaEventParameter[LusEventParameterIndex].uclastclrindex;
		 break;
		 #endif
		 #if (DEM_OP_CYCLE_CTR_SINCE_FIRST_FAILED_TESTED_CYCLES_ENABLED == STD_ON)
		 case DEM_CYCLES_TESTED_SINCE_FIRST_FAILED:
		 LusEvtInternaldataindex = Dem_GaaEventParameter[LusEventParameterIndex].uctestedfirstfailedindex;
		 break;	 
	     #endif
	     #if (DEM_OP_CYCLE_CTR_SINCE_LAST_FAILED_TESTED_CYCLES_ENABLED == STD_ON)
		 case DEM_CYCLES_TESTED_SINCE_LAST_FAILED:
		 LusEvtInternaldataindex = Dem_GaaEventParameter[LusEventParameterIndex].uctestedlastfailedindex;
		 break;
	     #endif
		 default:
		 LusEvtInternaldataindex = LusEventParameterIndex;
		 break;
	  }
      *(DestBuffer + *LpCurrentBufferIndex) = // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
               /* Polyspace InternalFunc_c_Ref_42 */
               *((uint8*)(Dem_GaaInternalDataElements
               [LucDataElement].pInternalDataElement) +
               LusEvtInternaldataindex);
      /* Increment buffer pointer */
      ++(*LpCurrentBufferIndex);
	  #else
	  *(DestBuffer + *LpCurrentBufferIndex) = // parasoft-suppress  MISRAC2012-RULE_18_4-a-4 CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_18 Dem_InternalFunc_c_REF_11"
      /* Polyspace InternalFunc_c_Ref_42 */
       *((uint8*)(Dem_GaaInternalDataElements // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
       [LucDataElement].pInternalDataElement) + // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
       LusEventParameterIndex);
      /* Increment buffer pointer */
      ++(*LpCurrentBufferIndex);
	  #endif
    }
    #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
     else if (((Dem_GaaInternalMonitorDataElements
               [DEM_ZERO].pInternalDataElement) == NULL_PTR) &&
               (LucDataElement == DEM_MONITOR_DATA_0) &&
               ((*LpReadMonitorEDdataStack - DEM_ONE) < 
                                            DEM_MAX_MONITOR_ED_RECDS_PER_EVENT))
    {
       LucMonitorDataByte = (uint8) // parasoft-suppress CDD-DUPC-3 "Refer: Dem_Cfg_c_REF_15"
            ((LpEventMemory + LucFreeIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
                   aaEdMonitorData[(*LpReadMonitorEDdataStack - DEM_ONE)][DEM_ONE]);
            *(DestBuffer + *LpCurrentBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
            ++(*LpCurrentBufferIndex);
            LucMonitorDataByte = (uint8)((LpEventMemory + LucFreeIndex)->// parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            aaEdMonitorData[(*LpReadMonitorEDdataStack - DEM_ONE)][DEM_ONE] >> DEM_ONE_BYTE);
            *(DestBuffer + *LpCurrentBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            ++(*LpCurrentBufferIndex);
            LucMonitorDataByte = (uint8)((LpEventMemory + LucFreeIndex)->// parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            aaEdMonitorData[(*LpReadMonitorEDdataStack - DEM_ONE)][DEM_ONE] >> DEM_TWO_BYTE);
            *(DestBuffer + *LpCurrentBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            ++(*LpCurrentBufferIndex);
            LucMonitorDataByte = (uint8)((LpEventMemory + LucFreeIndex)->// parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
             aaEdMonitorData[(*LpReadMonitorEDdataStack - DEM_ONE)][DEM_ONE] >> DEM_THREE_BYTE);
            *(DestBuffer + *LpCurrentBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"

            ++(*LpCurrentBufferIndex);
			(*LpReadMonitorEDdataStack)++;

    } /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
      /* PRQA S 3383 30 */
    #endif
    #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
     else if (((Dem_GaaInternalMonitorDataElements
               [DEM_ONE].pInternalDataElement) == NULL_PTR) &&
               (LucDataElement == DEM_MONITOR_DATA_1) &&
               ((*LpReadMonitorEDdataStack - DEM_ONE) < 
                                            DEM_MAX_MONITOR_ED_RECDS_PER_EVENT))
    {
     LucMonitorDataByte = (uint8)  // parasoft-suppress CDD-DUPC-3 "Refer: Dem_Cfg_c_REF_15"
            ((LpEventMemory + LucFreeIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
                   aaEdMonitorData[(*LpReadMonitorEDdataStack - DEM_ONE)][DEM_ONE]);
            *(DestBuffer + *LpCurrentBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            ++(*LpCurrentBufferIndex);
            LucMonitorDataByte = (uint8)((LpEventMemory + LucFreeIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            aaEdMonitorData[(*LpReadMonitorEDdataStack - DEM_ONE)][DEM_ONE] >> DEM_ONE_BYTE);
            *(DestBuffer + *LpCurrentBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            ++(*LpCurrentBufferIndex);
            LucMonitorDataByte = (uint8)((LpEventMemory + LucFreeIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            aaEdMonitorData[(*LpReadMonitorEDdataStack - DEM_ONE)][DEM_ONE] >> DEM_TWO_BYTE);
            *(DestBuffer + *LpCurrentBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            ++(*LpCurrentBufferIndex);
            LucMonitorDataByte = (uint8)((LpEventMemory + LucFreeIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
          aaEdMonitorData[(*LpReadMonitorEDdataStack - DEM_ONE)][DEM_ONE] >> DEM_THREE_BYTE);
           *(DestBuffer + *LpCurrentBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            ++(*LpCurrentBufferIndex);
			(*LpReadMonitorEDdataStack)++;

    }
    #endif
    #if (DEM_MAX_TYPEOF_IMPL_SPEC_INT_DATA_ELE_CNF > DEM_ZERO)
    else if (DEM_MAX_SUPPORTED_INTERNAL_DATA_ELE_SIZE  < LucDataElement)
    {
      /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 
		       Required Rule INT30 */
        /* PRQA S 3383 2 */
      Dem_GetImplSpecificExtData((LusEventParameterIndex + DEM_ONE),
             LpDTCAttribute, (DestBuffer + *LpCurrentBufferIndex),
                                                          LucDataElement);
      /* Get size of configured Data Element */
      *LpCurrentBufferIndex = *LpCurrentBufferIndex +
                         Dem_GaaDataElementInternal
                               [Dem_GaaEDRecord[LucActualRecordIndex].
                                   aaDataElementIndex[LucDataElementIndex]].
                                                       ucDemDataElementDataSize;
    }
    #endif
    else
    {
      Dem_EvaluateInternalExtdDataRcdIfOccOrAging(LucDataElement
        , LucEventDestination, LpCurrentBufferIndex, LucFreeIndex, DestBuffer
        #if (DEM_AGING_CYCLE_CONFIGURED == STD_ON)
        , LpDTCAttribute
        #endif
        );
    }
  *LblRecFound = DEM_TRUE;
  /* Return Value */
  return(LddReturnValue);
} /* End Of Dem_EvaluateInternalExtendedDataRecord */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_EvaluateInternalExtdDataRcdIfOccOrAging         **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Evaluates the internal extended data Records        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LucDataElement, LpDTCAttribute,                     **
                          LucFreeIndex, LucEventDestination                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : DestBuffer,LucCurrentBufferIndex                    **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_ED_RECDS should be greater than   **
**                        Zero                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : None                       **
**                                                                            **
** Design ID            : DEM_SDD_0915                                        **
*******************************************************************************/
#if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
    (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO) && \
    (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static void  Dem_EvaluateInternalExtdDataRcdIfOccOrAging(
   const uint8 LucDataElement, const Dem_DTCOriginType LucEventDestination, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   uint8*  LpCurrentBufferIndex, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
   const uint8 LucFreeIndex,  // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   uint8 *DestBuffer // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
   #if (DEM_AGING_CYCLE_CONFIGURED == STD_ON)
   , const Dem_DTCAttributeType* const LpDTCAttribute // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   #endif
  )
{
  uint8             LucOccuranceCounter;
  #if (DEM_AGING_CYCLE_CONFIGURED == STD_ON)
  uint16            LusEventParameterIndex;
  uint8             LucAgingCounter;
  uint8             LucEventStatus;
  #endif

  if (DEM_OCCCTR  == LucDataElement)
  {
  /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* polyspace +4 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* Get Occurance counter for requested Event Destination */
    LucOccuranceCounter = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
             Dem_GaaDTCOriginMappingIndx[LucEventDestination]].pEventMemory
                         [LucFreeIndex].ucOccuranceCounter;
    *(DestBuffer + *LpCurrentBufferIndex) = LucOccuranceCounter; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
	   /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
       /* PRQA S 3383 5 */
        if (DEM_OCC_MAX > *LpCurrentBufferIndex)
		{
          ++(*LpCurrentBufferIndex);
		}
		
  }
  
  #if (DEM_AGING_CYCLE_CONFIGURED == STD_ON)
  else if (DEM_AGINGCTR_UPCNT  == LucDataElement)
  {  /* polyspace +9 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
     /* polyspace +8 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
     /* Get Aging counter for requested Event Destination */
     /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required 
        Rule INT30 */
     /* PRQA S 3383 14 */
     LucAgingCounter = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
         Dem_GaaDTCOriginMappingIndx[LucEventDestination]].pEventMemory
                                         [LucFreeIndex].ucAgingCounter;
     if (LpDTCAttribute->blAgingAllowed)
     {
       *(DestBuffer + *LpCurrentBufferIndex) = LucAgingCounter; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
       ++(*LpCurrentBufferIndex);
     }
     else
     {  /* implemented as per SWS_Dem_01044 */
       *(DestBuffer + *LpCurrentBufferIndex) = DEM_ZERO; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
       ++(*LpCurrentBufferIndex);
     }
  }
   else if (DEM_AGINGCTR_UPCNT_FIRST_ACTIVE  == LucDataElement)
  {
  /* polyspace +5 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* polyspace +11 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Get Aging counter for requested Event Destination */
     LucAgingCounter = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
         Dem_GaaDTCOriginMappingIndx[LucEventDestination]].pEventMemory
                                         [LucFreeIndex].ucAgingCounter;
    /* #violates #ref Dem_InternalFunc_c_REF_QAC_3 Violates MISRA 2012 Required
       Rule 18.4 */
    /* PRQA S 0488 2 */
	LusEventParameterIndex = Dem_GaaDTCOriginBasedPtrAddress[
         Dem_GaaDTCOriginMappingIndx[LucEventDestination]].pEventMemory
                                         [LucFreeIndex].ddEventId - (uint16)DEM_ONE;
	LucEventStatus = Dem_GaaAllEvtStatus[LusEventParameterIndex];
 	if ((LucAgingCounter == DEM_ZERO) && 
						((LucEventStatus & DEM_EVENTSTATUS_BIT1_BIT6) == DEM_ZERO))
	 {
		  *(DestBuffer + *LpCurrentBufferIndex) = DEM_ONE; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
	 }
	 else
	 {  /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
        /* PRQA S 3383 4 */
       *(DestBuffer + *LpCurrentBufferIndex) = LucAgingCounter;// parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
	 } 
    ++(*LpCurrentBufferIndex);
  }
  else if (LucDataElement == DEM_AGINGCTR_DOWNCNT)
  { /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
    /* PRQA S 3383 17 */
    /* polyspace +5 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* polyspace +4 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Get Aging counter for requested Event Destination */
    LucAgingCounter = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
       Dem_GaaDTCOriginMappingIndx[LucEventDestination]].pEventMemory
                                       [LucFreeIndex].ucAgingCounter;
    if (LpDTCAttribute->blAgingAllowed)
    {

      *(DestBuffer + *LpCurrentBufferIndex) = LpDTCAttribute->usAgingCycleCounterThreshold - LucAgingCounter; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
      ++(*LpCurrentBufferIndex);
    }
    else
    { /* implemented as per SWS_Dem_01043 */
      *(DestBuffer + *LpCurrentBufferIndex) = DEM_INVALID; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
      ++(*LpCurrentBufferIndex);
    }
  }
  else
  {
    /* do nothing */
  }
  #else
  /* implemented as per SWS_Dem_01043 */
  /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 
     Required Rule INT30 */
  /* PRQA S 3383 10 */
  if (LucDataElement == DEM_AGINGCTR_DOWNCNT)
  {
      *(DestBuffer + *LpCurrentBufferIndex) = DEM_INVALID; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
      ++(*LpCurrentBufferIndex);
  }/* implemented as per SWS_Dem_01044 */
  else if (LucDataElement == DEM_AGINGCTR_UPCNT)
  { 
    *(DestBuffer + *LpCurrentBufferIndex) = DEM_ZERO; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
    ++(*LpCurrentBufferIndex);
  }
  else
  {
    /* do nothing */
  }
  
  #endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_SearchInMemory                                  **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : API to search for records in memory                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : RecordNumber,DataId,LucMemoryIndex,LpEventMemory    **
**                        LpDTCAttribute                                      **
**                                                                            **
** InOut parameter      : LblRecordFound                                      **
**                                                                            **
** Output Parameters    : DestBuffer                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : Dem_GetDidData,            **
**                                                 Det_ReportError            **
**                                                                            **
** Design ID            : DEM_SDD_0615                                        **
*******************************************************************************/
#if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType  Dem_SearchInMemory(const uint8 RecordNumber,
    const uint8 LucMemoryIndex, boolean* const LblRecordFound, const uint16 DataId, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
    const Dem_EventMemory*  LpEventMemory, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
    /* #violates #ref Dem_InternalFunc_c_REF_QAC_2 Violates MISRA 2012 Required
     Rule 8.13 */
    /* PRQA S 3673 1 */
    uint8*  LpDestBuffer, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
    const Dem_DTCAttributeType*  const LpDTCAttribute) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  Std_ReturnType LddReturnValue;
  #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
  uint8          LucLatestRecIndex;
  #endif
  #if (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)
  uint8          LucRecordCount;
  #endif
  uint8          LucMemIndx;
  uint8          LucRecordCntCmpVal;
  LddReturnValue = E_OK;
  /* check if Application requested for latest record */
  if (DEM_MAX_RECORD  == RecordNumber)
  {
  /* polyspace +6 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* Check at least one ff is recorded */
    /* Polyspace InternalFunc_c_Ref_180 */
    if ((LpEventMemory + LucMemoryIndex)->ucNumOfFF > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
    {
      #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
      /* Get Latest record index in memory */
      /* Polyspace InternalFunc_c_Ref_196 */
      LucLatestRecIndex =
          (LpEventMemory + LucMemoryIndex)->ucNumOfFF - DEM_ONE; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
      LddReturnValue = Dem_GetDidData(LpEventMemory, LpDestBuffer,
      LucMemoryIndex, DataId, LucLatestRecIndex);
      if (E_NOT_OK  == LddReturnValue)
      {
        LddReturnValue = DEM_NO_SUCH_ELEMENT;
      }
      #else
      LddReturnValue = DEM_NO_SUCH_ELEMENT;
      #endif
    }
    else
    {
      /* No records are stored Yet  */
      LddReturnValue = DEM_NO_SUCH_ELEMENT;
    }
  }
  /* if record requested is selective  */
  else
  {
    Dem_DtcAttrSearchInMemory(LpDTCAttribute, &LucMemIndx);
    if (Dem_GaaDTCOriginBasedPtrAddress[LucMemIndx].ucFfRecordEnumType == \
       DEM_FF_RECNUM_CONFIGURED)
    {
      LucRecordCntCmpVal = LpDTCAttribute->ucNumOfFFRecNum;
    }
    else
    {
      LucRecordCntCmpVal = LpDTCAttribute->ucMaxNumOfFFRecord;
    }
    /* Search in stored records for requested Record no */
    for (LucRecordCount = DEM_ZERO; ((LucRecordCount <
      LucRecordCntCmpVal
      ) &&
      ((!(*LblRecordFound)))); LucRecordCount++)
    {
    /* polyspace +5 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
      /* Polyspace InternalFunc_c_Ref_196 */
      if (RecordNumber == (LpEventMemory + LucMemoryIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
    /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      /* Polyspace InternalFunc_c_Ref_137 */
        aaFFRecNumAndData[LucRecordCount][DEM_ZERO])
      {
        *LblRecordFound = DEM_TRUE;
        #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
        LddReturnValue = Dem_GetDidData(LpEventMemory, LpDestBuffer,
        LucMemoryIndex, DataId, LucRecordCount);
        if (E_NOT_OK  == LddReturnValue)
        {
          LddReturnValue = DEM_NO_SUCH_ELEMENT;
        }
        #else  /* start of #if(DEM_MAX_NUM_OF_DID_PER_FF < DEM_ZERO) */
        LddReturnValue = DEM_NO_SUCH_ELEMENT;
        #endif /* End of #if(DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO) */
      }
    }
  } /* End of Requested Rec number*/

  #if (DEM_MAX_NUM_OF_DID_PER_FF <= DEM_ZERO)
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012
      Required Rule 2.2 */
  /* PRQA S 3112 2 */
  DEM_UNUSED(DataId);
  DEM_UNUSED(LpDestBuffer);
  #endif
  return(LddReturnValue);
} /* End Of Dem_SearchInMemory */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_CheckforValidRecord                             **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Check for valid record in memory                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : RecordNumber,DataId,LpDTCAttribute                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_FF_RECDS should be greater than   **
**                        Zero                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GaaFreezeFrameRecord   **
**                                               : Dem_GaaDid                 **
**                        Function(s) invoked    : Det_ReportError            **
**                                                                            **
** Design ID            : DEM_SDD_0603                                        **
*******************************************************************************/
#if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType  Dem_CheckforValidRecord(const uint8 RecordNumber,
   const uint8 LucServiceId, const uint16 DataId, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   const Dem_DTCAttributeType* const LpDTCAttribute) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  Std_ReturnType          LddReturnValue;
  #if (DEM_ANY_MEM_REC_NUM_CONFIG == DEM_ONE)
  uint8                   LucRecordCount;
  #endif

  #if (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)
  uint8                   LucNumOfRecs;
  #endif

   #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
  uint8                   LucDidCount;
  #endif
  

  #if (DEM_ANY_MEM_REC_NUM_CONFIG == DEM_ONE)
  uint8    LucRecordIndex;
  boolean  LblValidRecord;
  uint8    LucMemIndx;
  #endif

  #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO) 
  boolean  LblDidFound;
  #endif

  #if (DEM_ANY_MEM_REC_NUM_CONFIG == DEM_ONE)
  LblValidRecord = DEM_FALSE;
  #endif
  

    #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO) 
  LblDidFound = DEM_FALSE;
  #endif
  /* Check in FF records of the event if it is valid record */
  #if (DEM_ANY_MEM_REC_NUM_CONFIG == DEM_ONE)
  LddReturnValue = E_OK;
  Dem_DtcAttrSearchInMemory(LpDTCAttribute, &LucMemIndx);
  if (Dem_GaaDTCOriginBasedPtrAddress[LucMemIndx].ucFfRecordEnumType == \
     DEM_FF_RECNUM_CONFIGURED)
  {
    
    LucNumOfRecs = LpDTCAttribute->ucNumOfFFRecNum;
    /* Loop for all freeze frame records */
    for (LucRecordCount = DEM_ZERO;
       ((LucRecordCount < LucNumOfRecs) &&
       (!LblValidRecord)); LucRecordCount++)
    {
      LucRecordIndex =
           LpDTCAttribute->aaFreezeFrameRecords[LucRecordCount];
      /* Check if requested record number is found  */
      if (RecordNumber ==
         Dem_GaaFreezeFrameRecord[LucRecordIndex].
                                       ucFreezeFrameRecordNumber)
      {
          #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO) 
        for (LucDidCount = DEM_ZERO;
           ((LucDidCount < LpDTCAttribute->ucNumOfDataId) &&
           (!LblDidFound)); LucDidCount++)
        {
          if (Dem_GaaDid[LpDTCAttribute->aaDataIdArray[LucDidCount]]
           .usDid == DataId)
          {
            LblDidFound = DEM_TRUE;
          }
        }
        if (LblDidFound)
        {

          /* Report to DET */
          (void)Det_ReportRuntimeError(DEM_MODULE_ID, DEM_INSTANCE_ID,
          LucServiceId, DEM_E_NODATAAVAILABLE);

          LddReturnValue = DEM_NO_SUCH_ELEMENT;
        }
        else
        {
          LddReturnValue = DEM_NO_SUCH_ELEMENT;
        }
        #else
        LddReturnValue = DEM_NO_SUCH_ELEMENT;
        #endif /* End of #if(DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO) */
        LblValidRecord = DEM_TRUE;
      } /* End of check for record number */
    } /* End of loop for all freeze frame records */
    if (!LblValidRecord)
    {
      LddReturnValue = DEM_NO_SUCH_ELEMENT;
    }
  }
  else /* End of DEM_FFRECORD_NUMERATION_TYPE CONFIGURED*/
  #endif
  {
    LucNumOfRecs = LpDTCAttribute->ucMaxNumOfFFRecord;
    if (RecordNumber > LucNumOfRecs)
    {
      LddReturnValue = DEM_NO_SUCH_ELEMENT;
    }
    else
    {
        #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
      /* Loop for all Dids */
      for (LucDidCount = DEM_ZERO;
         ((LucDidCount < LpDTCAttribute->ucNumOfDataId) &&
         (!LblDidFound)); LucDidCount++)
      {
      /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        /* check if requested did is found */
        if (Dem_GaaDid[LpDTCAttribute->aaDataIdArray[LucDidCount]]
        .usDid == DataId)
        {
          /* set LblDidFound flag  */
          LblDidFound = DEM_TRUE;
        }
      } /* End of loop for all dids */
      if (LblDidFound)
      {
        /* Report to DET */
        (void)Det_ReportRuntimeError(DEM_MODULE_ID, DEM_INSTANCE_ID,
        LucServiceId, DEM_E_NODATAAVAILABLE);

        LddReturnValue = DEM_NO_SUCH_ELEMENT;
      }
      else
      {
        LddReturnValue = DEM_NO_SUCH_ELEMENT;
      }
      #else
      LddReturnValue = DEM_NO_SUCH_ELEMENT;
      #endif
    }
  }/* End of DEM_FFRECORD_NUMERATION_TYPE CALCULATED*/
  
  #if (DEM_MAX_NUM_OF_DID_PER_FF <= DEM_ZERO)
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012
      Required Rule 2.2 */
  /* PRQA S 3112 2 */
  DEM_UNUSED(DataId);
  #endif

  return(LddReturnValue);
} /* End Of Dem_CheckforValidRecord */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_SearchforInternalIfOccOrAging                   **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Search for Internal Extended Data Elements in       **
**                        case of event occurred or aged                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LucStoredIndex,LucDataElement                       **
**                        LucEvtDestination,LpDTCAttribute                    **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : DestBuffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_ED_RECDS should be greater than   **
**                        Zero                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_0916                                        **
*******************************************************************************/
#if ((DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO) && \
  (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_SearchforInternalIfOccOrAging(
const uint8 LucDataElement, const Dem_DTCOriginType LucEvtDestination, const uint8 LucStoredIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
uint8*  LpCurrentBufferIndex // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
#if (DEM_AGING_CYCLE_CONFIGURED == STD_ON)
, const Dem_DTCAttributeType* const LpDTCAttribute
#endif
, uint8 *DestBuffer) // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
{
  uint8           LucOccuranceCounter;
  #if (DEM_AGING_CYCLE_CONFIGURED == STD_ON)
  uint16          LusEventParameterIndex;
  uint8           LucAgingCounter;
  uint8           LucEventStatus;
  #endif
  if (DEM_OCCCTR  == LucDataElement)
  {
    /* polyspace +4 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* polyspace +4 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* Get Occurance counter for requested Event Destination */
    LucOccuranceCounter = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
             Dem_GaaDTCOriginMappingIndx[LucEvtDestination]].pEventMemory
                        [LucStoredIndex].ucOccuranceCounter;
    /* Load Occurance Counter Value */
    *(DestBuffer + *LpCurrentBufferIndex) = LucOccuranceCounter; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
       /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
       /* PRQA S 3383 1 */
  ++(*LpCurrentBufferIndex);
  }
  #if (DEM_AGING_CYCLE_CONFIGURED == STD_ON)
  else if (DEM_AGINGCTR_UPCNT  == LucDataElement)
  {
    /* polyspace +4 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* polyspace +4 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* Get Aging counter for requested Event Destination */
     LucAgingCounter = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
             Dem_GaaDTCOriginMappingIndx[LucEvtDestination]].pEventMemory
             [LucStoredIndex].ucAgingCounter;
    /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
    /* PRQA S 3383 30 */
    *(DestBuffer + *LpCurrentBufferIndex) =  LucAgingCounter; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
  ++(*LpCurrentBufferIndex);
  }
  else if (DEM_AGINGCTR_UPCNT_FIRST_ACTIVE  == LucDataElement)
  {
     /* polyspace +6 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* polyspace +12 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* polyspace +4 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* Get Aging counter for requested Event Destination */
     LucAgingCounter = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
             Dem_GaaDTCOriginMappingIndx[LucEvtDestination]].pEventMemory
             [LucStoredIndex].ucAgingCounter;
    /* #violates #ref Dem_InternalFunc_c_REF_QAC_3 Violates MISRA 2012 Required
       Rule 18.4 */
    /* PRQA S 0488 2 */
	LusEventParameterIndex = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
             Dem_GaaDTCOriginMappingIndx[LucEvtDestination]].pEventMemory
                      [LucStoredIndex].ddEventId - (uint16)DEM_ONE;
	LucEventStatus = Dem_GaaAllEvtStatus[LusEventParameterIndex];
 	if ((LucAgingCounter == DEM_ZERO) && 
			((LucEventStatus & DEM_EVENTSTATUS_BIT1_BIT6) == DEM_ZERO))
	 {
		  *(DestBuffer + *LpCurrentBufferIndex) = DEM_ONE; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
	 }
	 else
	 {
       *(DestBuffer + *LpCurrentBufferIndex) = // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
                                        LucAgingCounter + DEM_ONE;
	 }
  ++(*LpCurrentBufferIndex);
  }
  else if (LucDataElement == DEM_AGINGCTR_DOWNCNT)
  { /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
    /* PRQA S 3383 20 */
    /* polyspace +4 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* polyspace +4 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* Get Aging counter for requested Event Destination */
    LucAgingCounter = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
             Dem_GaaDTCOriginMappingIndx[LucEvtDestination]].pEventMemory
             [LucStoredIndex].ucAgingCounter;
    /* Check if Aging allowed for event is configured as TRUE */
    if (LpDTCAttribute->blAgingAllowed)
    {
      *(DestBuffer + *LpCurrentBufferIndex) = // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
                 LpDTCAttribute->usAgingCycleCounterThreshold - LucAgingCounter;
      /* #violates #ref Dem_InternalFunc_c_REF_QAC_3 Violates MISRA 2012*/
    ++(*LpCurrentBufferIndex);
    }
    else
    {
      *(DestBuffer + *LpCurrentBufferIndex) = DEM_INVALID; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
    ++(*LpCurrentBufferIndex); 
    }
  }
  else
  {
    /* do nothing */
  }
  #endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_GetFreezeFrameDataFromEvtMemory                 **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Reterive data for particular DTC from memory        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpEventMemory, LpStoredInds, LucNumOfEvts,          **
**                        LucEventMemoryIndex, RecordNumber                   **
** InOut parameter      : BufSize, LblRecordFound                             **
**                                                                            **
** Output Parameters    : DestBuffer                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)   : Dem_GaaEventParameter        **
**                        Function(s) invoked  : Det_ReportError              **
**                                               Dem_GetFFrecCount            **
**                                                                            **
** Design ID            : DEM_SDD_1426                                        **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* #violates #ref Dem_InternalFunc_c_CERT_REF_2 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5001 20 */
Std_ReturnType 
 Dem_GetFreezeFrameDataFromEvtMemory(
  const Dem_EventMemory*  LpEventMemory, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_2 Violates MISRA 2012 Required
     Rule 8.13 */
  /* PRQA S 3673 2 */
  uint8*  DestBuffer, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 MISRAC2012-RULE_17_8-a-4  MISRAC2012-RULE_8_13-a-4 CERT_C-DCL13-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_20 Dem_InternalFunc_c_REF_21 Dem_InternalFunc_c_REF_27"
  uint16*  BufSize // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
  , const uint8*  LpStoredInds // parasoft-suppress CERT_C-API00-a-3 CERT_C-DCL00-b-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
  , const uint8 LucNumOfEvts // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  #else
  , const uint8 LucEventMemoryIndex // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  #endif
  , const uint8 RecordNumber // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
  , const uint8 LucClientId // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  #endif
  , boolean* const LblRecordFound // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   )
{
  #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
  Std_ReturnType                                      LddReturnValue;
  #else
  /* Initialize Return Value */
  const Std_ReturnType                                LddReturnValue = E_OK; 
  #endif
  #if (DEM_MAX_NUMBER_OF_FF_RECDS == DEM_ZERO)
  const uint16                       LusCopiedSize =  DEM_ZERO; 
  #else
  uint16                               LusCopiedSize;
  #endif
  #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
  const Dem_DTCAttributeType*  LpDTCAttribute;
  #endif
  #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
  #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
  uint16                               LusDidRawDataSize;
  #endif
  #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
  uint16                               LusDidIdentifier;
  #endif
  uint16                               LusBufSize;
  uint16                               LusEventParameterIndex;
  #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
  uint16                               LusDidSize;
  uint16                               LusDataElementTypeIndex;
  uint16                               LusCount1;
  uint16                               LusDidOffset;
  uint8                                LucDataElementIndex;
  uint8                                LucSize;
  uint8                                LucNumOfDataElements;
  uint8                                LucDataElementType;
  uint8                                LucDidCount;
  #endif
  uint8                                LucNumOfFFRecNum;
  uint8                                LucRecordCnt;
  uint8                                LucNoOfDids;
  uint8                                LucRecordIndex;
  uint8                                LucRecordNumber;
  #endif
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
  uint8                                LucEntryCnt;
  #endif
  #if (DEM_MAX_MONITOR_FF_RECDS_PER_EVENT > DEM_ZERO)
  uint8                  LucMonitorDataByte;
  uint8                   LucMonitorDataSupport;
  uint8                   LucLoopCount;
  uint8                   LucElementCount;
  uint8                    LucReadMonitorFFdataStack;
  #endif
  #if ((DEM_MAX_MONITOR_FF_RECDS_PER_EVENT > DEM_ZERO) && \
      (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL))
  uint16  LusMonitorFFDataSizeDtcAttr;
  #endif
  #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
  uint8                   LucMemIndx;
  #endif
  #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
  /* Initialize Return Value */
  LddReturnValue = E_OK;
  #endif
  #if (DEM_MAX_NUMBER_OF_FF_RECDS != DEM_ZERO)
  LusCopiedSize =  DEM_ZERO;
  #endif
   /* initialize the record found variable to false */
      *LblRecordFound = DEM_FALSE;
 
  #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
  LucRecordNumber = RecordNumber;
    /* polyspace +22 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* polyspace +20 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
	/* polyspace +10 RTE:NIV [Justified:Low] "Refer Dem_c_Poly_REF_8" */
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
  LusEventParameterIndex = ((LpEventMemory + // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
				   LpStoredInds[DEM_ZERO])->ddEventId) - (uint16)DEM_ONE;
  #else
  LusEventParameterIndex = ((LpEventMemory + // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
				   LucEventMemoryIndex)->ddEventId) - (uint16)DEM_ONE;  
  #endif
  #endif

  #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
  /* polyspace +12 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  /* Get DTC Attribute for Event */
  LpDTCAttribute = Dem_GaaEventParameter[LusEventParameterIndex].pDTCAttribute;
  Dem_DtcAttrSearchInMemory(LpDTCAttribute, &LucMemIndx);
  /* Get number of record configured for DTC */
  if (Dem_GaaDTCOriginBasedPtrAddress[LucMemIndx].ucFfRecordEnumType == 
       DEM_FF_RECNUM_CONFIGURED)
  {
    LucNumOfFFRecNum = LpDTCAttribute->ucNumOfFFRecNum;
  }
  else
  {
    LucNumOfFFRecNum = LpDTCAttribute->ucMaxNumOfFFRecord;
  }
  /* Loop for number of records to be process */
  for (LucRecordCnt = Dem_GaaClientSelection[LucClientId].ucFFNumRecordProcessed;
      ((LucRecordCnt < LucNumOfFFRecNum) &&
       ((!(*LblRecordFound)) || (DEM_MAX_RECORD == RecordNumber))); LucRecordCnt++)
  #endif
  {
    #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
    /* Check if Request is for all records */
    if (DEM_MAX_RECORD == RecordNumber)
    {
		/* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
        /* PRQA S 3383 2 */
      /* Increment to process next record */
      ++(Dem_GaaClientSelection[LucClientId].ucFFNumRecordProcessed);
	  #if (DEM_TOTAL_CONFIG_FF_RECDS > DEM_ZERO)
      if (Dem_GaaDTCOriginBasedPtrAddress[LucMemIndx].ucFfRecordEnumType == 
          DEM_FF_RECNUM_CONFIGURED)
      {
        /* Get record number to be process */
        LucRecordNumber = Dem_GaaFreezeFrameRecord[LpDTCAttribute->
                  aaFreezeFrameRecords[LucRecordCnt]].ucFreezeFrameRecordNumber;
      }
      else
	  #endif
      {
        /* Get record number to be process */
        LucRecordNumber =
                     Dem_GaaClientSelection[LucClientId].ucFFNumRecordProcessed;
      }
    }
    #endif
    /* Get Size of all Records for all events mapped to DTC Requested */
    #if ((DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)  && \
         (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL))
    LusBufSize = DEM_ZERO;
    Dem_GetFFrecCount(LpStoredInds, LucNumOfEvts,
                               &LusBufSize, LucRecordNumber, LpEventMemory);
    /* Check whether the actual buffer size greater than the max
          buffer size */
          /* Polyspace InternalFunc_c_Ref_140 */
          if (*BufSize < LusBufSize)
          {
            /* Error report to DET */
            #if (DEM_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
                DEM_GETNEXTFREEZEFRAMEDATA_SID, DEM_E_PARAM_LENGTH);
            #endif
            /* Set the return value */
            /* Polyspace InternalFunc_c_Ref_198 */
            LddReturnValue = DEM_BUFFER_TOO_SMALL;
          }
		   else
		  {
			*BufSize = *BufSize - LusBufSize;
			/* Load the actual buffer size */
			LusCopiedSize = LusCopiedSize + LusBufSize;  
		  }
	#endif

    #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
    /* Loop for all  combined events */
    for (LucEntryCnt = DEM_ZERO; 
	#if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
	((LucEntryCnt < LucNumOfEvts) &&
        (E_OK == LddReturnValue ));
    #else
	(LucEntryCnt < LucNumOfEvts);
	#endif
	LucEntryCnt++)
    #endif
    {
  
     
      #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
      for (LucRecordIndex = DEM_ZERO; (LucRecordIndex < LucNumOfFFRecNum)
           ; LucRecordIndex++)
      {
        /* polyspace +7 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
       /* polyspace +7 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
	   /* polyspace +15 RTE:NIV [Justified:Low] "Refer Dem_c_Poly_REF_8" */
        /* Check if the requested FF record is stored in memory */
        /* Polyspace InternalFunc_c_Ref_139 */
		 #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
        if ((LpEventMemory + LpStoredInds[LucEntryCnt])-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
                aaFFRecNumAndData[LucRecordIndex][DEM_ZERO] == LucRecordNumber)
		#else
		if ((LpEventMemory + LucEventMemoryIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
                aaFFRecNumAndData[LucRecordIndex][DEM_ZERO] == LucRecordNumber)	
		#endif
        {
          #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
          LucNoOfDids = LpDTCAttribute->ucNumOfDataId;
          #else
          LucNoOfDids = DEM_ZERO;
          #endif
          #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
          /* Get size of the record */
          LusDidRawDataSize = LpDTCAttribute->usFFRecordRawDataSize;
          #if (DEM_MAX_MONITOR_FF_RECDS_PER_EVENT > DEM_ZERO)
          LusMonitorFFDataSizeDtcAttr = LpDTCAttribute->usMonitorFFDataSizeDtcAttr;
          #endif
          /* Size = Total Didsize + Count of bytes for did number +
          Record number(1 byte) + No of Did(1 byte)(SWS PG NO:178) */
          /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012
            Required Rule 2.2 */
           /* PRQA S 3112 1 */
          LusBufSize = (uint16)DEM_TWO + LusDidRawDataSize +
                                         ((uint16)LucNoOfDids * (uint16)DEM_TWO);
          #if (DEM_MAX_MONITOR_FF_RECDS_PER_EVENT > DEM_ZERO)
          LusBufSize += LusMonitorFFDataSizeDtcAttr;
          #endif
          
		/* Check whether the actual buffer size greater than the max
          buffer size */
          /* Polyspace InternalFunc_c_Ref_140 */
          if (*BufSize < LusBufSize)
          {
            /* Error report to DET */
            #if (DEM_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
                DEM_GETNEXTFREEZEFRAMEDATA_SID, DEM_E_PARAM_LENGTH);
            #endif
            /* Set the return value */
            /* Polyspace InternalFunc_c_Ref_198 */
            LddReturnValue = DEM_BUFFER_TOO_SMALL;
          }
		  else
		  {
			*BufSize = *BufSize - LusBufSize;
			/* Load the actual buffer size */
			LusCopiedSize = LusCopiedSize + LusBufSize;  
		  }
          #endif
          
		  #if ((DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL) && \
		      (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO) && \
			  (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO))
	      
		  #else
		  
          if (E_OK == LddReturnValue)
          
		  #endif
        {
            #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
            /* Load the record number */
            /* Polyspace InternalFunc_c_Ref_141 */
            /* Polyspace InternalFunc_c_Ref_142 */
            *DestBuffer = (LpEventMemory + // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
             #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
             LpStoredInds[LucEntryCnt]
             #else
             LucEventMemoryIndex
             #endif
             )->aaFFRecNumAndData[LucRecordIndex][DEM_ZERO];
            /* Increment the destination buffer */
            /* #violates #ref Dem_InternalFunc_c_REF_QAC_11 Violates MISRA
               2012 */
            /* PRQA S 0489 4 */
            /* #violates #ref Dem_InternalFunc_c_REF_QAC_14 Violates MISRA 2012
            Required Rule 17.8 */
            /* PRQA S 1338 1 */
            DestBuffer++; // parasoft-suppress MISRAC2012-RULE_17_8-a-4 "Refer:Dem_InternalFunc_c_REF_20"
            /* Load the no of Data Id's */
            /* Polyspace InternalFunc_c_Ref_143*/
            /* Polyspace InternalFunc_c_Ref_144*/
            *DestBuffer = LpDTCAttribute->ucNumOfDataId;
             /* Increment the destination buffer */
             /* #violates #ref Dem_InternalFunc_c_REF_QAC_11 Violates MISRA
                2012 */
            /* PRQA S 0489 4 */
             /* #violates #ref Dem_InternalFunc_c_REF_QAC_14 Violates MISRA 2012
            Required Rule 17.8 */
            /* PRQA S 1338 1 */
            DestBuffer++; // parasoft-suppress MISRAC2012-RULE_17_8-a-4 "Refer:Dem_InternalFunc_c_REF_20"

            LusDidOffset = DEM_ZERO;
            /* Load the data into Destination buffer */
            for (LucDidCount = DEM_ZERO; LucDidCount < LucNoOfDids;
                                                              LucDidCount++)
            {
          /* polyspace +6 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
              /* Load the first 8 bits of Did number */
              /* Polyspace InternalFunc_c_Ref_146*/
              /* Polyspace InternalFunc_c_Ref_147*/
              /* Polyspace InternalFunc_c_Ref_148*/
              LusDidIdentifier = Dem_GaaDid
                        [LpDTCAttribute->aaDataIdArray[LucDidCount]].usDid;

              /* Load Msb of Did identifier in to Destination Buffer */
              *DestBuffer = (uint8)(LusDidIdentifier >> DEM_EIGHT);
              /* Increment destination buffer */
              /* #violates #ref Dem_InternalFunc_c_REF_QAC_11 Violates MISRA
                 2012 */
              /* PRQA S 0489 4 */
               /* #violates #ref Dem_InternalFunc_c_REF_QAC_14 Violates MISRA 2012
               Required Rule 17.8 */
               /* PRQA S 1338 1 */
              DestBuffer++; // parasoft-suppress MISRAC2012-RULE_17_8-a-4 "Refer:Dem_InternalFunc_c_REF_20"
              /* Load Lsb of Did identifier in to Destination Buffer */
              *DestBuffer = (uint8)(LusDidIdentifier  & (uint8)DEM_BYTE_FF);
              /* Increment the destination buffer */
              /* #violates #ref Dem_InternalFunc_c_REF_QAC_11 Violates MISRA
                 2012 */
              /* PRQA S 0489 4 */
               /* #violates #ref Dem_InternalFunc_c_REF_QAC_14 Violates MISRA 2012
               Required Rule 17.8 */
               /* PRQA S 1338 1 */
               DestBuffer++; // parasoft-suppress MISRAC2012-RULE_17_8-a-4 "Refer:Dem_InternalFunc_c_REF_20"
              LucNumOfDataElements = Dem_GaaDid
                          [LpDTCAttribute->aaDataIdArray[LucDidCount]].
                                                        ucNumOfDataElements;
              /* Get the size of Did */
              LusDidSize = DEM_ZERO;
              #if (DEM_MAX_MONITOR_FF_RECDS_PER_EVENT > DEM_ZERO)
              LucReadMonitorFFdataStack = DEM_ZERO;
              LucElementCount = DEM_ZERO; 
              #endif
              for (LucDataElementIndex = DEM_ZERO; LucDataElementIndex <
                                LucNumOfDataElements; LucDataElementIndex++)
              {
                LucSize = DEM_ZERO;
          /* polyspace +4 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
                /* Get the data element type of the Did */
                LucDataElementType =
                  Dem_GaaDid[LpDTCAttribute->aaDataIdArray[LucDidCount]].
                                    aaDataElementType[LucDataElementIndex];
                /* Get the index of the data element array */
                LusDataElementTypeIndex =
                    Dem_GaaDid[LpDTCAttribute->aaDataIdArray[LucDidCount]].
                                   aaDataElementIndex[LucDataElementIndex];
                /* Fetch the size of data element */
                LddReturnValue = Dem_ProcessDataElementSize
                    (LusDataElementTypeIndex, LucDataElementType, &LucSize);
                LusDidSize = LusDidSize + (uint16) LucSize;
                 #if (DEM_MAX_MONITOR_FF_RECDS_PER_EVENT > DEM_ZERO)
                 LucMonitorDataSupport = Dem_GaaDid[LpDTCAttribute->
                    aaDataIdArray[LucDidCount]].
                       aaDidDataElementMonitorDataSupport[LucDataElementIndex];
			    /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
                /* PRQA S 3383 5 */
                 if (LucMonitorDataSupport == DEM_MONITOR_TRUE) 
                 {
                  
                   LucElementCount++;
                 }
                 #endif
              } /* End of  looping for data elements for current Did*/

              for (LusCount1 = DEM_ZERO; LusCount1 < LusDidSize;
                 LusCount1++)
              {
				/* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
                /* PRQA S 3383 13 */
                /* polyspace +20 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
                /* Load the data into Destination buffer */
                /* Polyspace InternalFunc_c_Ref_153*/
                /* Polyspace InternalFunc_c_Ref_154*/
                /* Polyspace InternalFunc_c_Ref_155*/
                *DestBuffer = (LpEventMemory + // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
                 #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
                 LpStoredInds[LucEntryCnt]
                 #else
                 LucEventMemoryIndex
                 #endif
                 )-> aaFFRecNumAndData[LucRecordIndex][(uint16) DEM_ONE + LusDidOffset + // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
                  LusCount1]; // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
				/* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
                /* PRQA S 3383 38 */
                /* Increment destination buffer */
                /* #violates #ref Dem_InternalFunc_c_REF_QAC_11 Violates MISRA
                   2012 */
                /* PRQA S 0489 4 */
                 /* #violates #ref Dem_InternalFunc_c_REF_QAC_14 Violates MISRA 2012
                  Required Rule 17.8 */
                 /* PRQA S 1338 30 */
                DestBuffer++; // parasoft-suppress MISRAC2012-RULE_17_8-a-4 "Refer:Dem_InternalFunc_c_REF_20"
              }/* Loop for loading the complete data of particular DID */
              #if (DEM_MAX_MONITOR_FF_RECDS_PER_EVENT > DEM_ZERO)
               
               if (LucElementCount > DEM_ZERO) 
               {
                for (LucLoopCount = DEM_ZERO; ((LucLoopCount < LucElementCount) && 
                (LucReadMonitorFFdataStack < DEM_MAX_FF_MONITOR_DATA_ELEMENT));
                 LucLoopCount++)
                 {  
                 LucMonitorDataByte = (uint8)(LpEventMemory ->
                       aaFFMonitorData[LucReadMonitorFFdataStack][DEM_ONE + 
                                                         LucLoopCount]);
                 *DestBuffer = LucMonitorDataByte;
                 ++DestBuffer; // parasoft-suppress MISRAC2012-RULE_17_8-a-4 "Refer:Dem_InternalFunc_c_REF_20"
                 LucMonitorDataByte = (uint8)(LpEventMemory ->
                       aaFFMonitorData[LucReadMonitorFFdataStack][DEM_ONE + 
                                          LucLoopCount] >> DEM_ONE_BYTE);
                 *DestBuffer = LucMonitorDataByte;
                 ++DestBuffer; // parasoft-suppress MISRAC2012-RULE_17_8-a-4 "Refer:Dem_InternalFunc_c_REF_20"
                 LucMonitorDataByte = (uint8)(LpEventMemory ->
                       aaFFMonitorData[LucReadMonitorFFdataStack][DEM_ONE + 
                                 LucLoopCount] >> DEM_TWO_BYTE);
                 *DestBuffer = LucMonitorDataByte;
                 ++DestBuffer; // parasoft-suppress MISRAC2012-RULE_17_8-a-4 "Refer:Dem_InternalFunc_c_REF_20"
                 LucMonitorDataByte = (uint8)(LpEventMemory ->
                       aaFFMonitorData[LucReadMonitorFFdataStack][DEM_ONE + 
                                      LucLoopCount] >> DEM_THREE_BYTE);
                 *DestBuffer = LucMonitorDataByte; 
                 ++DestBuffer; // parasoft-suppress MISRAC2012-RULE_17_8-a-4 "Refer:Dem_InternalFunc_c_REF_20"
                 LucReadMonitorFFdataStack++;
                 }
               }
              #endif
              LusDidOffset = LusDidOffset + LusDidSize;
            } /* Load the complete set of DID and data into
               Destination buffer */
            #endif
          }/* Required buffer size is available */
          /* Record is found in memory */
          *LblRecordFound = DEM_TRUE;
        }/* Check if the requested FF record is stored in memory */
      }/* Loop through the number of FF captured */
      #else
      /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012
          Required Rule 2.2 */
      /* PRQA S 3112 7 */
      DEM_UNUSED(DestBuffer);
      #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
      DEM_UNUSED(LucEventMemoryIndex);
      #endif
      DEM_UNUSED(LpEventMemory);
      DEM_UNUSED(RecordNumber);
      #endif
    }
    #if ((DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO) && \
        (DEM_MAX_NUM_OF_DID_PER_FF == DEM_ZERO))
    /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012
    Required Rule 2.2 */
    /* PRQA S 3112 1 */
    DEM_UNUSED(DestBuffer);
    #endif
    #if ((DEM_MAX_NUMBER_OF_FF_RECDS == DEM_ZERO) && \
    (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL))
    /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012
    Required Rule 2.2 */
    /* PRQA S 3112 1 */
    DEM_UNUSED(LpStoredInds);
    #endif
  } /* End of For Loop(Event Combination : DEM_EVCOMB_ONRETRIEVAL)*/
  *BufSize = LusCopiedSize;			
  return(LddReturnValue);

} /* End Of Dem_GetFreezeFrameDataFromEvtMemory */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*******************************************************************************
** Function Name        : Dem_GetSizeOfRecord                                 **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : This API is used to get size of Freeze Frame Record **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : RecordNumber, LucEventMemoryIndex, LucNumOfEvt,     **
**                        LaaStoredInds,LpEventMemory                         **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : SizeOfFreezeFrame                                   **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GaaEventParameter      **
**                        Function(s) invoked    : Det_ReportError            **
**                                                                            **
** Design ID            : DEM_SDD_0611                                        **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* #violates #ref Dem_InternalFunc_c_CERT_REF_2 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5001 14 */
Std_ReturnType 
  Dem_GetSizeOfRecord(const uint8 RecordNumber // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
     #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
     , uint16* const LpSizeOfFreezeFrame // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
     #endif
     #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
     , const uint8 LucEventMemoryIndex // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
     #endif
     , const Dem_EventMemory*  LpEventMemory // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
     #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
     , const uint8* const LaaStoredInds // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
     , const uint8 LucNumOfEvt // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
     #endif
    )
{
  #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
  Std_ReturnType                                    LddReturnValue;
  #else
  const Std_ReturnType                              LddReturnValue = E_OK;
  #endif
  #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
  const Dem_DTCAttributeType*  LpDTCAttribute;
  uint16                             LusEventParameterIndex;
  uint16                             LusBufSize;
  uint16                             LusDidRawDataSize;
  uint8                              LucRecordNum;
  #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
  uint8                              LucNoOfDids;
  #endif
  #endif
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
  uint8                              LucEntryCnt;
  #endif
  #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
  boolean                            LblRecordconfigured;
  boolean                            LblDtcFormat;
  boolean                            LblDtcthreebyte;
  #endif
  #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
  uint16                             LusDtcInfoIndex;
  uint8                              LucNumOFRecord;
  uint8                              LucCount;
  boolean                            LblRecordFound;
  uint8                              LucCmpRecord;
  uint8                              LucMemIndx;
  uint8                              LucInvalidRecNum;
  #endif
  #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
  LddReturnValue = E_OK;
  #endif

  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
  /* Loop for all combined events */
  for (LucEntryCnt = DEM_ZERO; 
   #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
   ((LucEntryCnt < LucNumOfEvt) &&
     (LddReturnValue == E_OK)); 
   #else
   (LucEntryCnt < LucNumOfEvt);
   #endif
   LucEntryCnt++)
  #endif
  {
    /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
    /* PRQA S 3383 12 */
    #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
    /* polyspace +25 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* Polyspace InternalFunc_c_Ref_44 */
    /* Polyspace InternalFunc_c_Ref_196 */
	 /* polyspace +10 RTE:NIV [Justified:Low] "Refer Dem_c_Poly_REF_8" */
	 #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
    LusEventParameterIndex =
    ((LpEventMemory + LaaStoredInds[LucEntryCnt])->ddEventId) - DEM_ONE; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
	#else
	 LusEventParameterIndex =
    ((LpEventMemory + LucEventMemoryIndex)->ddEventId) - DEM_ONE; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
	#endif
      /* polyspace +7 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Polyspace InternalFunc_c_Ref_126 */
    LpDTCAttribute = Dem_GaaEventParameter
                    [LusEventParameterIndex].pDTCAttribute;
    /* Get DTC Index for Event */
    LusDtcInfoIndex = DEM_EVENT_MAPPED_DTC_INDEX(LusEventParameterIndex);
    LblDtcFormat = DEM_DTC_FORMAT(LusDtcInfoIndex, DEM_DTC_FORMAT_UDS);
    LblDtcthreebyte = DEM_DTC_FORMAT(LusDtcInfoIndex, DEM_DTC_FORMAT_OBD_3BYTE);
	Dem_DtcAttrSearchInMemory(LpDTCAttribute, &LucMemIndx);
    /* Check event is obd or uds */
    if (LblDtcFormat || LblDtcthreebyte)
    {
      /* Check if a specific record or all the records captured
      has to be retrieved */
      if (DEM_MAX_RECORD  != RecordNumber)
      {
        /* Set the record found to false */
        LblRecordFound = DEM_FALSE;
        
        if (Dem_GaaDTCOriginBasedPtrAddress[LucMemIndx].ucFfRecordEnumType == 
           DEM_FF_RECNUM_CONFIGURED)
        {
          /* polyspace +1 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
          LucCmpRecord = LpDTCAttribute->ucNumOfFFRecNum;
        }
        else
        {
           /* polyspace +1 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
          LucCmpRecord = LpDTCAttribute->ucMaxNumOfFFRecord;
        }
          /* Loop through the number of FF captured */
          for (LucCount = DEM_ZERO;
          ((LucCount < LucCmpRecord
          ) &&
          (!LblRecordFound)); LucCount++)
        {
          /* polyspace +30 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
          /* Check if the requested FF record is stored in memory */
          /* Polyspace InternalFunc_c_Ref_127 */
          if ((LpEventMemory + // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
             #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
             LaaStoredInds[LucEntryCnt]
             #else
             LucEventMemoryIndex
             #endif
             )->aaFFRecNumAndData[LucCount]
               [DEM_ZERO] == RecordNumber)
          {
            /* Record is present in memory */
            LblRecordFound = DEM_TRUE;
            /* Get size of the record */
            #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
            LucNoOfDids = LpDTCAttribute->ucNumOfDataId;
            #endif
            LusDidRawDataSize = LpDTCAttribute->usFFRecordRawDataSize;
            /* Size = Total Didsize + Count of bytes for did number +
            Record number(1 byte) + No of Did(1 byte)(SWS PG NO:178) */
            #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
            LusBufSize =
              LusDidRawDataSize + ((uint16)LucNoOfDids * (uint16)DEM_TWO) + // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_19"
              (uint16)DEM_TWO;
            #if (DEM_MAX_MONITOR_FF_RECDS_PER_EVENT > DEM_ZERO)
            LusBufSize +=  LpDTCAttribute->usMonitorFFDataSizeDtcAttr;
            #endif
            #else
            LusBufSize = LusDidRawDataSize + (uint16)DEM_TWO;
            #endif
            *LpSizeOfFreezeFrame = *LpSizeOfFreezeFrame + LusBufSize;
          }
        }
        /* Check if the requested record is found in memory */
        if (!LblRecordFound)
        {
          #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
          if (Dem_GaaDTCOriginBasedPtrAddress[LucMemIndx].ucFfRecordEnumType == 
             DEM_FF_RECNUM_CONFIGURED)
          {
            LucNumOFRecord = (Dem_GaaEventParameter
            [LusEventParameterIndex].pDTCAttribute)->ucNumOfFFRecNum;
          }
          else
          {
            LucNumOFRecord = (Dem_GaaEventParameter
            [LusEventParameterIndex].pDTCAttribute)->ucMaxNumOfFFRecord;
          }
          LblRecordconfigured = DEM_FALSE;
          for (LucCount = DEM_ZERO;((LucCount < LucNumOFRecord) &&
          (!LblRecordconfigured)); LucCount++)
          {
		    #if (DEM_TOTAL_CONFIG_FF_RECDS > DEM_ZERO)
            if (Dem_GaaDTCOriginBasedPtrAddress[LucMemIndx].ucFfRecordEnumType == 
               DEM_FF_RECNUM_CONFIGURED)
            {
              LucRecordNum =
              Dem_GaaFreezeFrameRecord[(Dem_GaaEventParameter
              [LusEventParameterIndex].pDTCAttribute)->
              aaFreezeFrameRecords[LucCount]].ucFreezeFrameRecordNumber;
            }
            else
			#endif
            {
              /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
              /* PRQA S 3383 4 */
              /* Calculated record no starts from one to ucMaxNumOfFFRecord*/
              LucRecordNum =
              LucCount + DEM_ONE;
            }

            if (LucRecordNum == RecordNumber)
            {
              LblRecordconfigured = DEM_TRUE;
            }
          }
          if (!LblRecordconfigured)
          {
            /* Return The wrong record number */
            LddReturnValue = DEM_NO_SUCH_ELEMENT;
          }
          #endif
        }
      }
      /* Loop in memory get all the records stored in memory */
      /* If Event Combination is configured to ON Retrival  */
      /* Loop for all events belong to particular DTC to calculate Size */
      else
      {
        #if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
		 LucInvalidRecNum = (uint8)DEM_INVALID_FF_REC_NUM;
        if (Dem_GaaDTCOriginBasedPtrAddress[LucMemIndx].ucFfRecordEnumType == 
           DEM_FF_RECNUM_CONFIGURED)
        {
          /* polyspace +1 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
          LucCmpRecord = LpDTCAttribute->ucNumOfFFRecNum;
         
        }
        else
        {
           /* polyspace +1 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
          LucCmpRecord = LpDTCAttribute->ucMaxNumOfFFRecord;
         
        }
        /* Loop through the number of Configured FF records */
        for (LucCount = DEM_ZERO;
          (LucCount < LucCmpRecord
          ); LucCount++)
        {
          /* Check if valid record entry is present */
          if (LucInvalidRecNum
          /* polyspace +30 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
             != (LpEventMemory + // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
             #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
             LaaStoredInds[LucEntryCnt]
             #else
             LucEventMemoryIndex
             #endif
             )-> aaFFRecNumAndData[LucCount][DEM_ZERO])
          {
            /* Get size of the record */
            #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
            LucNoOfDids = LpDTCAttribute->ucNumOfDataId; 
            #endif
            LusDidRawDataSize = LpDTCAttribute->usFFRecordRawDataSize;
            /* Size = Total Didsize + Count of bytes for did number +
            Record number(1 byte) + No of Did(1 byte)(SWS PG NO:178) */
            #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
            LusBufSize =
              LusDidRawDataSize + ((uint16)LucNoOfDids * (uint16)DEM_TWO) + // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_19"
              (uint16)DEM_TWO;
            #if (DEM_MAX_MONITOR_FF_RECDS_PER_EVENT > DEM_ZERO)
            LusBufSize +=  LpDTCAttribute->usMonitorFFDataSizeDtcAttr;
            #endif
            #else
            LusBufSize = LusDidRawDataSize + (uint16)DEM_TWO;
            #endif
            *LpSizeOfFreezeFrame = (*LpSizeOfFreezeFrame) + LusBufSize;
          } /* End of check for valid Record entry */
        } /* End of loop for all Configured records*/
        #endif
      }  /* End of check for all Recs Size*/
    }  /* Check for UDS format*/
    #else
    /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012
        Required Rule 2.2 */
    /* PRQA S 3112 4 */
    DEM_UNUSED(LpEventMemory);
    DEM_UNUSED(RecordNumber);
    #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
    DEM_UNUSED(LucEventMemoryIndex);
    #endif
    #endif/* End of DEM_MAX_NUMBER_OF_FF_RECDS  */
    #if ((DEM_MAX_NUMBER_OF_FF_RECDS == DEM_ZERO) && \
    (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL))
    /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012
    Required Rule 2.2 */
    /* PRQA S 3112 1 */
    DEM_UNUSED(LaaStoredInds);
    #endif
  }  /* End of loop for  Events(Event combination : On Retrieval)*/
  return(LddReturnValue);
} /* End Of Dem_GetSizeOfRecord */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*******************************************************************************
** Function Name        : Dem_ReshuffleMILEvents                              **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Search and Delete clear requested Event             **
**                        Reshuffle evemnts in array                          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LusEvntId                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_MIL_SUPPORT should be ON                        **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GaaMilFaults           **
**                        Function(s) invoked    : None                       **
** Design ID            : DEM_SDD_0772                                        **
*******************************************************************************/
 #if ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) &&    \
       (DEM_MIL_SUPPORT == STD_ON))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_ReshuffleMILEvents(const uint16 LusEvntId)
{
  #if (DEM_NUM_EVENT_MAPPED_TO_MIL > DEM_ONE)
  uint16_least    LusEventCount;
  #else
  const uint16_least    LusEventCount = DEM_ZERO;
  #endif
  #if (DEM_NUM_EVENT_MAPPED_TO_MIL > DEM_ONE)
  boolean         LblEvtFound;
  LblEvtFound = DEM_FALSE;
  #endif
  SchM_Enter_Dem_DEM_DATA_PROTECTION();
  #if (DEM_NUM_EVENT_MAPPED_TO_MIL > DEM_ONE)
  /* Loop for all Events configured to MIL */
  for (LusEventCount = DEM_ZERO; LusEventCount < (uint16_least)DEM_NUM_EVENT_MAPPED_TO_MIL; // parasoft-suppress CERT_C-INT13-a-2 CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24"
      LusEventCount++)
  #endif
  {
    /* Check Event in recorded in MIL faults */
    if ((Dem_GaaMilFaults[LusEventCount] == DEM_ZERO) ||
      (Dem_GaaMilFaults[LusEventCount] == LusEvntId))
    {
      Dem_GaaMilFaults[LusEventCount] = DEM_ZERO;
      #if (DEM_NUM_EVENT_MAPPED_TO_MIL > DEM_ONE)
      if (!LblEvtFound)
      {
        LblEvtFound = DEM_TRUE;
      }
      #endif
    }
    #if (DEM_NUM_EVENT_MAPPED_TO_MIL > DEM_ONE)
    else
    {
      /* Check if Event found */
      if (LblEvtFound)
      { /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
        /* PRQA S 3383 3 */
        /* Reshuffle events */
        Dem_GaaMilFaults[LusEventCount - (uint16)DEM_ONE] =
                                                Dem_GaaMilFaults[LusEventCount];
        Dem_GaaMilFaults[LusEventCount] = DEM_ZERO;
		 
        /* Beak the For Loop (LusEventCount = LucEvtIndx;) */
        break;
      }
    }
    #endif
  } /* End of loop for all MIL events*/
  SchM_Exit_Dem_DEM_DATA_PROTECTION();
}  /* End of Dem_ReshuffleMILEvents */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_RecordMilFault                                  **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Record event in MIL fault array                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LusEventParameterIndex                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_MIL_SUPPORT should be STD_ON                    **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GaaMilFaults           **
**                        Function(s) invoked    : None                       **
** Design ID            : DEM_SDD_0771                                        **
*******************************************************************************/
 #if ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) &&    \
       (DEM_MIL_SUPPORT == STD_ON))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_RecordMilFault(const uint16 LusEventParameterIndex) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  #if (DEM_NUM_EVENT_MAPPED_TO_MIL > DEM_ONE)
  uint16  LusEventCount;
  #else
  const uint16_least    LusEventCount = DEM_ZERO;
  #endif
  #if (DEM_NUM_EVENT_MAPPED_TO_MIL > DEM_ONE)
  /* loop to find free index to store new event to store in memory */
  for (LusEventCount = DEM_ZERO; (LusEventCount < DEM_NUM_EVENT_MAPPED_TO_MIL)
      ; LusEventCount++)
  #endif
  {
    if (DEM_ZERO  == Dem_GaaMilFaults[LusEventCount])
    {  /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
       /* PRQA S 3383 2 */
       /* Store event contributing for MIl fault */
      Dem_GaaMilFaults[LusEventCount] = LusEventParameterIndex + DEM_ONE;
	 
      #if (DEM_NUM_EVENT_MAPPED_TO_MIL > DEM_ONE)
      /* Break as valid index index found */
      break;
      #endif
    }
  }
} /* End Of Dem_RecordMilFault */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_EndConv16                                       **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Endianness Data conversion for uint16 datatype.     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : LucSize                                             **
**                                                                            **
** Output Parameters    : LpDataElement                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : DEM_SDD_0627                                        **
*******************************************************************************/
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_EndConv16(
       uint16* const LpDataElement, const uint8 LucSize)
{
  uint8  LucIndex;
  for (LucIndex = DEM_ZERO; LucIndex < LucSize; LucIndex++)
  {
    /* Polyspace InternalFunc_c_Ref_196 */
    *(LpDataElement + LucIndex) = (((*(LpDataElement + LucIndex) >> DEM_EIGHT)
    & (uint16)DEM_BYTE_FF) | (uint16)(((uint32)(*(LpDataElement + LucIndex)) &
    (uint32)DEM_BYTE_FF) << DEM_EIGHT));
  }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_EndConv32                                       **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Endianness Data conversion for uint32 datatype.     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : LucSize                                             **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** InOut parameter      : LpDataElement                                       **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : DEM_SDD_1467                                        **
*******************************************************************************/
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_EndConv32(
       uint32*  LpDataElement, uint8 LucSize)
{
  uint8  LucIndex;
  uint16  LusdataLsb;
  uint16  LusdataMsb;
  for (LucIndex = DEM_ZERO; LucIndex < LucSize; LucIndex++)
  {
    /* Polyspace InternalFunc_c_Ref_196 */
    LusdataLsb = (uint16)*(LpDataElement + LucIndex);
    LusdataLsb = (((LusdataLsb >> DEM_EIGHT) & (uint16)DEM_BYTE_FF) |
   (uint16)(((uint32)LusdataLsb & (uint32)DEM_BYTE_FF) << DEM_EIGHT));

    /* Polyspace InternalFunc_c_Ref_196 */
    LusdataMsb = (uint16)(*(LpDataElement + LucIndex) >> DEM_SIXTEEN);
    LusdataMsb = (((LusdataMsb >> DEM_EIGHT) & (uint16)DEM_BYTE_FF) |
    (uint16)(((uint32)LusdataMsb & (uint32)DEM_BYTE_FF) << DEM_EIGHT));

    /* Polyspace InternalFunc_c_Ref_196 */
    *(LpDataElement + LucIndex) = (((uint32)LusdataLsb << DEM_SIXTEEN) |
    (uint32)LusdataMsb);
  }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_SetWarningIndicator                             **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Setting the Warning Indicator ON                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LusEvtParamIndex, LpEventStatus                     **
**                                                                            **
** InOut parameter      : LpEventStatus                                       **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_MIL_SUPPORT should be STD_ON                    **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GaaIndicatorList       **
**                        Function(s) invoked    : None                       **
** Design ID            : DEM_SDD_5765                                        **
*******************************************************************************/
#if ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) &&    \
            (DEM_MIL_SUPPORT == STD_ON))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void 
        Dem_SetWarningIndicator(const uint16 LusEvtParamIndex, uint8* const LpEventStatus) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  Dem_IndicatorStatusType  LddIndicatorBehaviour;
  uint8                                    LucIndicatorCount;
  uint16                                   LusIndicatorIndex;

  /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Loop through the number of indicators configured for the event */
  for (LucIndicatorCount = DEM_ZERO; LucIndicatorCount < Dem_GaaEventParameter
    [LusEvtParamIndex].ucNumberofIndicator; LucIndicatorCount++)
  {
    /* Get the index of indicator list array */
    LusIndicatorIndex = Dem_GaaEventParameter[LusEvtParamIndex].
      aaIndicatorIndex[LucIndicatorCount];
  /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Check if any indicators mapped to DTC  */
    if (DEM_MIL_INDICATOR_ID  ==
         Dem_GaaIndicatorList[LusIndicatorIndex].ddIndicatorId)
    {
      SchM_Enter_Dem_DEM_DATA_PROTECTION();
      /* Set : Warning Indicator Bit */
      *LpEventStatus =
          (*LpEventStatus | DEM_EVENTSTATUS_BIT7_SET);
    /* polyspace +4 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */


      LddIndicatorBehaviour = DEM_INDICATOR_BEHAVIOUR(LusIndicatorIndex); // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Refer: Dem_InternalFunc_c_REF_18"
      /* Switch Mil ON */
      Dem_GaaIndicatorStatus[Dem_GaaIndicatorList[LusIndicatorIndex].
           aaIndicatorIdIndex] = LddIndicatorBehaviour;

      SchM_Exit_Dem_DEM_DATA_PROTECTION();
      break;
    }
  }
} /* End Of Dem_SetWarningIndicator */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_SearchInPermanentMemory                         **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Search for valid Event in memory                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : LusEventId                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpFreeNdx                                           **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT should be      **
**                        greater than Zero                                   **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GstPerEventMemory      **
**                        Function(s) invoked    : None                       **
** Design ID            : DEM_SDD_0767                                        **
*******************************************************************************/
#if ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
(DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
boolean  Dem_SearchInPermanentMemory(
      const Dem_EventIdType LusEventId, uint16* const LpFreeNdx ) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  /* Local variable for Index of Permanent Memory */
  uint16   LusIndex;
  /* Local variable for return Value */
  boolean  LblReturnValue;
  /* Flag for Free Index */
  boolean  LblMemFlg;
  /* Initialize return value */
  LblReturnValue = DEM_FALSE;
  /* Initialize return value */
  LblMemFlg = DEM_FALSE;
  /*Initialise free index*/
  *LpFreeNdx = DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT + DEM_ONE;
  /* For each entry in Permanent Memory */
  for (LusIndex = DEM_ZERO; LusIndex < DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT;
       LusIndex++)
  {
    if (
    #if ((DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) && \
                 (DEM_INVALID != DEM_PERMANENT_MEM_NVM_BLOCK_INDX))
    /* Polyspace InternalFunc_c_Ref_203 */
    (Dem_GstCpyPerEventMemory[LusIndex].ddEventId == DEM_ZERO) &&
    #else
    (Dem_GstPerEventMemory[LusIndex].ddEventId == DEM_ZERO) &&
    #endif
    (!LblMemFlg))
        
    {
      *LpFreeNdx = LusIndex;
      LblMemFlg = DEM_TRUE;
    }
    /* Check if EventId exists in Permanent Memory */
   
    #if ((DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) && \
                 (DEM_INVALID != DEM_PERMANENT_MEM_NVM_BLOCK_INDX))
    /* Polyspace InternalFunc_c_Ref_203 */
    if (Dem_GstCpyPerEventMemory[LusIndex].ddEventId == LusEventId)
    #else
    if (Dem_GstPerEventMemory[LusIndex].ddEventId == LusEventId) 
    #endif
    {
      LblReturnValue = DEM_TRUE;
      break;
    }
  }

  /* Event found */
  if (LblReturnValue)
  {
    /* Invalid Index */
    *LpFreeNdx = DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT + DEM_ONE;
  }
  /* No free entry in memory */
  else if (!LblMemFlg)
  {
    /* Set Memory overflow flag to TRUE */
    Dem_GaaEventMemOvflw[DEM_TWO] = DEM_ONE;
  }
  else
  {
    /* Do nothing */
  }
  /* Return Value */
  return(LblReturnValue);
} /* End Of Dem_SearchInPermanentMemory */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_RoundOff                                        **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : RoundOff the float value to nearest decimal value.  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** InOut parameter      : LssValue                                            **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_PID_RECDS should be greater than  **
**                        Zero                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : DEM_SDD_0769                                        **
*******************************************************************************/
#if ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
     (DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_RoundOff(
     float32* const LpValue) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  uint32   LulInteger;
  float32  LflDifference;
  /* polyspace +2 RTE:OVFL [Justified:Low] "Refer Dem_c_Poly_REF_6" */
  LulInteger = (uint32)(*LpValue);
  LflDifference = (*LpValue) - (float32)LulInteger;
  if (DEM_FLOAT_ZERO_POINT_FIVE  < LflDifference)
  {
    *LpValue = (float32)((float32)LulInteger + (float32)DEM_ONE);
  }
  else
  {
    *LpValue = (float32)LulInteger;
  }
} /* End Of Dem_RoundOff */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_GetInternalDataElement                          **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Gets required internal Data Element(Extended data)  **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : LucActualRecordIndex                                **
**                                                                            **
** InOut parameter      : BufSize,DTCOrigin                                   **
**                                                                            **
** Output Parameters    : DestBuffer                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_ED_RECDS should be greater than   **
**                          ZERO                                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaEDRecord,              **
**                                              Dem_GaaDataElementInternal,   **
**
**                        Function(s) invoked : Det_ReportError               **
**                                              Dem_GetMaxFdcOfDtc            **
**                                              Dem_GetImplSpecificExtData    **
**                                              Dem_UDMemoryIndexFetch        **
**                                              Dem_GetInternalDataIfOccOrAging
** Design ID            : DEM_SDD_0623                                        **
*******************************************************************************/
#if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO) && \
   (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static Std_ReturnType 
Dem_GetInternalDataElement(const uint8 LucActualRecordIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
uint16*  LpBufSize, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
uint8*  LpDestBuffer, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
const uint16 LusEventParameterIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
const Dem_DTCAttributeType* const LpDTCAttribute, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
const Dem_DTCOriginType DTCOrigin, uint16* const LusDestBufIndx, const uint8 LucStoredIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
const uint8 LucDataElementIndex // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
  , uint8* const LpReadMonitorEDdataStack
   #endif
   )
{
  const Std_ReturnType                     LddReturnValue = E_OK;
     #if ((DEM_DTR_INTERNAL_DATAELEMENT == STD_ON) || \
       (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON) || \
       (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON) || \
       (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON))
  Std_ReturnType  LddReturnValue1 ;
  #endif
  Dem_DTCOriginType         LddDTCOrigin;
  uint8                     LucDataElement;
  uint16                    LusDestBufferIndex;
  #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
  uint8                     LucMonitorDataByte;
  #endif
  #if ((DEM_OP_CYCLE_CTR_SUPPORT == STD_ON) ||\
	       (DEM_MAX_FDC_SINCE_LAST_CLR_SUPPORT_ENABLED == STD_ON))
  uint16                     LusEvtInternaldataindex;
  #endif
  #if ((DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO) ||\
  (DEM_NUM_OF_EVENT_WITH_ASSOCIATED_IDENTIFICATION > DEM_ZERO))
  const Dem_EventMemory*     LpEventMemory;
  #endif
  #if (DEM_NUM_OF_EVENT_WITH_ASSOCIATED_IDENTIFICATION > DEM_ZERO)
  uint16                     LusEventData; 
  #endif
  LddDTCOrigin = DEM_ZERO;
  #if ((DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO) ||\
  (DEM_NUM_OF_EVENT_WITH_ASSOCIATED_IDENTIFICATION > DEM_ZERO))

      /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      /* Pointer to Event Memeory */
  LpEventMemory =  Dem_GaaDTCOriginBasedPtrAddress[
                 Dem_GaaDTCOriginMappingIndx[(uint8)DTCOrigin]].pEventMemory;
   #endif 

  LusDestBufferIndex = *LusDestBufIndx;

  /* polyspace +4 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  LucDataElement = Dem_GaaDataElementInternal
      [Dem_GaaEDRecord[LucActualRecordIndex].
      aaDataElementIndex[LucDataElementIndex]].
        ucDemInternalDataElement;
   #if ((DEM_DTR_INTERNAL_DATAELEMENT == STD_ON) || \
       (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON) || \
       (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON) || \
       (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON))
        LddReturnValue1 = Dem_CheckInternaldateleForIumprMonitorActiDtr(LucDataElement);
        #endif       
     /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
        /* PRQA S 3383 61 */
	    #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
      if (((Dem_GaaInternalMonitorDataElements
                 [DEM_ZERO].pInternalDataElement) == NULL_PTR) &&
                 (LucDataElement == DEM_MONITOR_DATA_0) &&
                 ((*LpReadMonitorEDdataStack - DEM_ONE) < 
                                            DEM_MAX_MONITOR_ED_RECDS_PER_EVENT))
      {
         LucMonitorDataByte = (uint8) // parasoft-suppress CDD-DUPC-3 "Refer: Dem_Cfg_c_REF_15"
        ((LpEventMemory + LucStoredIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
               aaEdMonitorData[(*LpReadMonitorEDdataStack - DEM_ONE)][DEM_ONE]);
        *(LpDestBuffer + LusDestBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        LusDestBufferIndex++;
        LucMonitorDataByte = (uint8)((LpEventMemory + LucStoredIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        aaEdMonitorData[(*LpReadMonitorEDdataStack - DEM_ONE)][DEM_ONE] >> DEM_ONE_BYTE);
        *(LpDestBuffer + LusDestBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        LusDestBufferIndex++;
        LucMonitorDataByte = (uint8)((LpEventMemory + LucStoredIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        aaEdMonitorData[(*LpReadMonitorEDdataStack - DEM_ONE)][DEM_ONE] >> DEM_TWO_BYTE);
        *(LpDestBuffer + LusDestBufferIndex) = LucMonitorDataByte;
        LusDestBufferIndex++;
        LucMonitorDataByte = (uint8)((LpEventMemory + LucStoredIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
         aaEdMonitorData[(*LpReadMonitorEDdataStack - DEM_ONE)][DEM_ONE] >> DEM_THREE_BYTE);
        *(LpDestBuffer + LusDestBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        LusDestBufferIndex++;
		(*LpReadMonitorEDdataStack)++;
      
      }
      #endif
      #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
       else if (((Dem_GaaInternalMonitorDataElements
                 [DEM_ONE].pInternalDataElement) == NULL_PTR) &&
                 (LucDataElement == DEM_MONITOR_DATA_1) && (
                 (*LpReadMonitorEDdataStack - DEM_ONE) < 
                                            DEM_MAX_MONITOR_ED_RECDS_PER_EVENT))
      {
       LucMonitorDataByte = 

             (uint8)((LpEventMemory + LucStoredIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
              aaEdMonitorData[(*LpReadMonitorEDdataStack - DEM_ONE)][DEM_ONE +
                                                           LucDataElementIndex]);
       *(LpDestBuffer + LusDestBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
       LusDestBufferIndex++;
       LucMonitorDataByte = (uint8)((LpEventMemory + LucStoredIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
       aaEdMonitorData[(*LpReadMonitorEDdataStack - DEM_ONE)][DEM_ONE + 
                                    LucDataElementIndex] >> DEM_ONE_BYTE);
       *(LpDestBuffer + LusDestBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
       LusDestBufferIndex++;
       LucMonitorDataByte = (uint8)((LpEventMemory + LucStoredIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
       aaEdMonitorData[(*LpReadMonitorEDdataStack - DEM_ONE)][DEM_ONE] >> DEM_TWO_BYTE);
       *(LpDestBuffer + LusDestBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
       LusDestBufferIndex++;
       LucMonitorDataByte = (uint8)((LpEventMemory + LucStoredIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
       aaEdMonitorData[(*LpReadMonitorEDdataStack - DEM_ONE)][DEM_ONE] >> DEM_THREE_BYTE);
      *(LpDestBuffer + LusDestBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
       LusDestBufferIndex++;
	   (*LpReadMonitorEDdataStack)++;

      }
      #endif
      #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
      else if ((Dem_GaaInternalDataElements
      [LucDataElement].pInternalDataElement) != NULL_PTR)
      #else
       if ((Dem_GaaInternalDataElements
      [LucDataElement].pInternalDataElement) != NULL_PTR)
      #endif
    /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    {
      if (DEM_OVFLIND  != LucDataElement)
	  {
        #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
        if (DEM_MAX_FDC_DURING_CURRENT_CYCLE != LucDataElement)
        #endif
        {
		 #if ((DEM_OP_CYCLE_CTR_SUPPORT == STD_ON) ||\
	      (DEM_MAX_FDC_SINCE_LAST_CLR_SUPPORT_ENABLED == STD_ON))
	    switch (LucDataElement)
	    {
		 #if (DEM_OP_CYCLE_CTR_FAILED_CYCLES_ENABLED == STD_ON)
		 case DEM_FAILED_CYCLES:
		 LusEvtInternaldataindex = Dem_GaaEventParameter[LusEventParameterIndex].ucfailedcycleindex;
		 break;
		 #endif
		 #if (DEM_OP_CYCLE_CTR_SINCE_LAST_FAILED_ENABLED == STD_ON)
		 case DEM_CYCLES_SINCE_LAST_FAILED:
		 LusEvtInternaldataindex = Dem_GaaEventParameter[LusEventParameterIndex].uclastfailedindex;
		 break;
		 #endif
		 #if (DEM_OP_CYCLE_CTR_SINCE_FIRST_FAILED_ENABLED == STD_ON)
		 case DEM_CYCLES_SINCE_FIRST_FAILED:
		 LusEvtInternaldataindex = Dem_GaaEventParameter[LusEventParameterIndex].ucfirstfailedindex;
		 break;
		 #endif
		 #if (DEM_MAX_FDC_SINCE_LAST_CLR_SUPPORT_ENABLED == STD_ON)
		 case DEM_MAX_FDC_SINCE_LAST_CLEAR:
		 LusEvtInternaldataindex = Dem_GaaEventParameter[LusEventParameterIndex].uclastclrindex;
		 break;
		 #endif
		 #if (DEM_OP_CYCLE_CTR_SINCE_FIRST_FAILED_TESTED_CYCLES_ENABLED == STD_ON)
		 case DEM_CYCLES_TESTED_SINCE_FIRST_FAILED:
		 LusEvtInternaldataindex = Dem_GaaEventParameter[LusEventParameterIndex].uctestedfirstfailedindex;
		 break;	 
	     #endif
	     #if (DEM_OP_CYCLE_CTR_SINCE_LAST_FAILED_TESTED_CYCLES_ENABLED == STD_ON)
		 case DEM_CYCLES_TESTED_SINCE_LAST_FAILED:
		 LusEvtInternaldataindex = Dem_GaaEventParameter[LusEventParameterIndex].uctestedlastfailedindex;
		 break;
	     #endif
		 default:
		 LusEvtInternaldataindex = LusEventParameterIndex;
		 break;
	    }
		  *(LpDestBuffer + LusDestBufferIndex) = // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
          *((Dem_GaaInternalDataElements
            [LucDataElement].pInternalDataElement) +
            LusEvtInternaldataindex);
		#else
      /* polyspace +11 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
          /* Update data in the buffer */
          *(LpDestBuffer + LusDestBufferIndex) = // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
          *((Dem_GaaInternalDataElements // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
            [LucDataElement].pInternalDataElement) + // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
            LusEventParameterIndex);
		  #endif
		/* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
          /* PRQA S 3383 10 */
          LusDestBufferIndex++;
        }
        #if (DEM_EVENT_COMBINATION_SUPPORT ==  DEM_EVCOMB_ONSTORAGE)
        else
        { 
          Dem_GetMaxFdcOfDtc(&LpDestBuffer[LusDestBufferIndex],
                                     LusEventParameterIndex);
          LusDestBufferIndex++;
        }
        #endif
      }
	  else
      {
        if ((DTCOrigin == DEM_DTC_PRIMARY_MEMORY) ||
        (DTCOrigin == DEM_DTC_ORIGIN_PERMANENT_MEMORY))
        {
          LddDTCOrigin = DTCOrigin - (uint16)DEM_ONE;
        }
        #if (DEM_USER_DEF_MEMORY_CONFIGURED == STD_ON)
        else
        {
          (void)Dem_UDMemoryIndexFetch(DTCOrigin,
            &LddDTCOrigin);
        }
        #endif
		/* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
        /* PRQA S 3383 6 */
        /* Update data in the buffer */
        *(LpDestBuffer + LusDestBufferIndex) = // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        *((Dem_GaaInternalDataElements // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        [LucDataElement].pInternalDataElement) + // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        LddDTCOrigin);
        LusDestBufferIndex++;
      }
    }
	
       
      else if (DEM_DTC_PRIORITY  == LucDataElement)
      {
		/* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
        /* PRQA S 3383 73 */
        /* Update data in the buffer */
        *(LpDestBuffer + LusDestBufferIndex) = LpDTCAttribute->DTCPriority; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        LusDestBufferIndex++;
      }
      #if (DEM_NUM_OF_EVENT_WITH_ASSOCIATED_IDENTIFICATION > DEM_ZERO)
        else if (DEM_EVENT_ASSOCIATED_IDENTIFICATION  == LucDataElement)
      {
        /* Update data in the buffer */
         LusEventData = DEM_ASSOCIATED_IDENTIFICATION(LpEventMemory
                                                         ->ddEventId - DEM_ONE);
        *(LpDestBuffer + LusDestBufferIndex) = (uint8)LusEventData; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        LusDestBufferIndex++;
        *(LpDestBuffer + LusDestBufferIndex) = (uint8) // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
                                                 (LusEventData >> DEM_ONE_BYTE);
        LusDestBufferIndex++;
      }
      #endif
      /* PRQA S 3383 85 */
       #if ((DEM_DTR_INTERNAL_DATAELEMENT == STD_ON) || \
       (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON) || \
       (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON) || \
       (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON) )
    else if (LddReturnValue1 == E_OK)
    {
      Dem_ProcessGetInternalIumprMonitorDtr(LucDataElement, 
      &LusDestBufferIndex, LpDestBuffer, LusEventParameterIndex );
    }
    #endif  
   #if (DEM_MAX_TYPEOF_IMPL_SPEC_INT_DATA_ELE_CNF > DEM_ZERO)
   else if (DEM_MAX_SUPPORTED_INTERNAL_DATA_ELE_SIZE  < LucDataElement)
   {
     Dem_GetImplSpecificExtData((LusEventParameterIndex + DEM_ONE),
                 LpDTCAttribute, (LpDestBuffer + LusDestBufferIndex), LucDataElement); // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
     LusDestBufferIndex = LusDestBufferIndex + Dem_GaaDataElementInternal[Dem_GaaEDRecord[LucActualRecordIndex].aaDataElementIndex[LucDataElementIndex]].ucDemDataElementDataSize; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2  "Reason: Dem_InternalFunc_c_REF_18 Dem_InternalFunc_c_REF_24 Dem_InternalFunc_c_REF_23"
   }
   #endif
    else
    {
      Dem_GetInternalDataIfOccOrAging(LucDataElement, DTCOrigin,
                    LusDestBufferIndex, LpDestBuffer, LucStoredIndex
                    #if (DEM_AGING_CYCLE_CONFIGURED == STD_ON)
                    , LpDTCAttribute
                    #endif
                    );
	  /* PRQA S 3383 1 */
      LusDestBufferIndex++;
    }
  
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_30  Violates MISRA 2012 
		 Required Rule INT30 */
  /* PRQA S 3384 6 */
  /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 
		 Required Rule INT30 */
  /* PRQA S 3383 10 */
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
  #if (DEM_MAX_TYPEOF_IMPL_SPEC_INT_DATA_ELE_CNF > DEM_ZERO)
  *LpBufSize = ((*LpBufSize) + (LusDestBufferIndex - (*LusDestBufIndx))) - (uint16) DEM_ONE; // parasoft-suppress CERT_C-INT13-a-2 CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24"
  #else
  ++(*LpBufSize);
  #endif
  #else
  *LpBufSize = LusDestBufferIndex - DEM_ONE;
  #endif

  *LusDestBufIndx = LusDestBufferIndex;
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 1 */
  DEM_UNUSED(LpDTCAttribute);
  return LddReturnValue;
} /* End Of Dem_GetInternalDataElement */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_GetInternalDataIfOccOrAging                     **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Gets required internal Data Element(Extended data)  **
**                        if Event occurred or aging process involved         **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : LucActualRecordIndex                                **
**                                                                            **
** InOut parameter      : BufSize,DTCOrigin                                   **
**                                                                            **
** Output Parameters    : DestBuffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_ED_RECDS should be greater than   **
**                        ZERO                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_0917                                        **
*******************************************************************************/
#if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO) && \
   (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static void Dem_GetInternalDataIfOccOrAging(const uint8 LucDataElement,
const Dem_DTCOriginType DTCOrigin, const uint16 LusDestBufferIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
uint8*  LpDestBuffer,// parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
const uint8 LucStoredIndex // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
#if (DEM_AGING_CYCLE_CONFIGURED == STD_ON)
, const Dem_DTCAttributeType* const LpDTCAttribute
#endif
)
{
  uint8             LucOccuranceCounter;
  uint8             LucOriginMask;
  #if (DEM_AGING_CYCLE_CONFIGURED == STD_ON)
  uint16            LusEventParameterIndex;
  uint8             LucAgingCounter;
  uint8             LucEventStatus;
  #endif
  LucOriginMask = (uint8)(DTCOrigin);

  if (DEM_OCCCTR  == LucDataElement)
  {
    /* polyspace +5 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Get Occurance counter for requested Event Destination */
    LucOccuranceCounter = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
             Dem_GaaDTCOriginMappingIndx[LucOriginMask]].pEventMemory
                 [LucStoredIndex].ucOccuranceCounter;


    *(LpDestBuffer + LusDestBufferIndex) = LucOccuranceCounter;

  }
  #if (DEM_AGING_CYCLE_CONFIGURED == STD_ON)
  else if (DEM_AGINGCTR_UPCNT  == LucDataElement)
  {
    /* polyspace +5 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Get Aging counter for requested Event Destination */
     LucAgingCounter = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
             Dem_GaaDTCOriginMappingIndx[LucOriginMask]].pEventMemory
                      [LucStoredIndex].ucAgingCounter;


    *(LpDestBuffer + LusDestBufferIndex) =  LucAgingCounter; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
  }
   else if (DEM_AGINGCTR_UPCNT_FIRST_ACTIVE  == LucDataElement)
  {
    /* polyspace +5 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* polyspace +4 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Get Aging counter for requested Event Destination */
     LucAgingCounter = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
             Dem_GaaDTCOriginMappingIndx[LucOriginMask]].pEventMemory
                      [LucStoredIndex].ucAgingCounter;
       /* #violates #ref Dem_InternalFunc_c_REF_QAC_3 Violates MISRA 2012 Required
       Rule 18.4 */
    /* PRQA S 0488 2 */
	/* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
    /* PRQA S 3383 33 */
	LusEventParameterIndex = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
             Dem_GaaDTCOriginMappingIndx[LucOriginMask]].pEventMemory
                      [LucStoredIndex].ddEventId - DEM_ONE;
	LucEventStatus = Dem_GaaAllEvtStatus[LusEventParameterIndex];
 	if ((LucAgingCounter == DEM_ZERO) && 
			((LucEventStatus & DEM_EVENTSTATUS_BIT1_BIT6) == DEM_ZERO))
	 {
		  *(LpDestBuffer + LusDestBufferIndex) = DEM_ONE; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
	 }
	 else
	 {
       *(LpDestBuffer + LusDestBufferIndex) =
                                        LucAgingCounter;
	 } 
  }
  else if (LucDataElement == DEM_AGINGCTR_DOWNCNT)
  {
    /* polyspace +5 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Get Aging counter for requested Event Destination */
    LucAgingCounter = Dem_GaaDTCOriginBasedPtrAddress[ // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
             Dem_GaaDTCOriginMappingIndx[LucOriginMask]].pEventMemory
             [LucStoredIndex].ucAgingCounter;
    if (LpDTCAttribute->blAgingAllowed)
    {
      *(LpDestBuffer + LusDestBufferIndex) = // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
                 LpDTCAttribute->usAgingCycleCounterThreshold - LucAgingCounter;
    }
    else
    {
      *(LpDestBuffer + LusDestBufferIndex) = DEM_INVALID; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
    }
  }
  else
  {
    /* do nothing */
  }
  #endif
} /* End Of Dem_GetInternalDataIfOccOrAging */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_GetExtendedDataRecordByDTCExistInMem            **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Gets extended data by DTC. The function             **
**                        stores the data in the provided DestBuffer if DTC   **
**                        is valid                                            **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     :ExtendedDataNumber,LusEventParameterIndex,LpEventMemory
**                        LucStoredIndex                                      **
** InOut parameter      : BufSize,DTCOrigin,LucDestBuffIndx                   **
**                                                                            **
** Output Parameters    : DestBuffer                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_ED_RECDS should be greater than   **
**                          ZERO                                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaEDRecord,              **
**                                              Dem_GaaDTCAttributes,         **
**                                              Dem_GaaCurrentEDTriggerStatus **
**                        Function(s) invoked : Det_ReportError               **
**                                              Dem_GetInternalDataElement    **
**                                                                            **
** Design ID            : DEM_SDD_0402,DEM_SDD_0622                           **
*******************************************************************************/
#if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
    (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* #violates #ref Dem_InternalFunc_c_CERT_REF_2 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5001 10 */
Std_ReturnType 
Dem_GetExtendedDataRecordByDTCExistInMem(
uint8* const LpRecNumberStored,
const uint16 LusEventParameterIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
const Dem_EventMemory*  LpEventMemory, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
const uint8 LucStoredIndex, const uint8 ExtendedDataNumber,
uint16*  LpBufSize, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
uint8*  LpDestBuffer, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
const Dem_DTCOriginType DTCOrigin, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
uint16*  LpDestBuffIndx) // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
{
  uint8                                LucDataElementIndex;
  #if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO)
  uint8                                LucNumOfEDRecords;
  uint8                                LucActualRecordIndex;
  uint16                               LusDestBufferIndex;
  boolean                              LblRecordFound;
  #endif
  Std_ReturnType                                      LddReturnValue;
  #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
  uint16                               LusSize;
  #endif

  const Dem_DTCAttributeType*  LpDTCAttribute;
  uint8                                LucCount;
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
  uint16                               LusRawDataSize;
  #endif
  #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
  uint8                                LucMonitorDataByte;
  uint8                                LucMonitorDataSupport;
  uint8                                LucReadMonitorEDdataStack;
  #endif

  #if ((DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS > DEM_ZERO) ||\
  (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR > DEM_ZERO))
  uint16  LusRecSize;
  uint16  LusTempIndex;
  uint8   LucCurrentBufferExtIndex;
  uint16  LusLoadDataIndex;
  #endif
  LddReturnValue = E_OK;
  #if ((DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS > DEM_ZERO) ||\
       (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR > DEM_ZERO))
  LucCurrentBufferExtIndex = DEM_ZERO;
  #endif
  #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
    LucReadMonitorEDdataStack = DEM_ZERO;
  #endif

  #if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO)
  LusDestBufferIndex = *LpDestBuffIndx;
  #endif

  /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Initialize local pointer to events dtc Attribute */
  LpDTCAttribute = Dem_GaaEventParameter[LusEventParameterIndex].
                  pDTCAttribute;
  /* Initialize record found to false */
  LblRecordFound = DEM_FALSE;
  /* Get no of records for this Event */
  /* polyspace +1 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  LucNumOfEDRecords = LpDTCAttribute->ucNumOfEDRecords;
  /* Loop for all records till valid record is found in memory or
      Configuration */
  for (LucCount = DEM_ZERO; ((LucCount <
    LucNumOfEDRecords) && (!LblRecordFound)); LucCount++)
  {
    /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Get the actual index of the record */
    LucActualRecordIndex = LpDTCAttribute->aaExtendedDataRecords[LucCount];
    /* Check if record is stored in memory */


    if ((LpEventMemory + LucStoredIndex)->aaEdData[LucCount] // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
       [DEM_ZERO] == ExtendedDataNumber)
    {
      #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
    /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      LusSize = Dem_GaaEDRecord[LucActualRecordIndex].usEDRecordRawDataSize;
      #if (DEM_MAX_MONITOR_ED_EXT_RECDS_PER_EVENT > DEM_ZERO)
      LusSize += Dem_GaaEDRecord[LucActualRecordIndex].usEDMonitorRawDataSize;
      #endif
      #endif
      
      #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
      /* Raw Data Size + Record number Size */
      /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
      /* PRQA S 3383 1 */
      if (*LpBufSize < (LusSize + (uint16) DEM_ONE)) // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_19"
      {
        #if (DEM_DEV_ERROR_DETECT == STD_ON)
        /* Error report to DET */
        (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
         DEM_GETNEXTEXTENDEDDATARECORD_SID, DEM_E_PARAM_LENGTH);
         #endif
        /* Return  wrong buffer size */
        LddReturnValue = DEM_BUFFER_TOO_SMALL;
      }
      else /* If Buffer given is greater than size of record */
      #endif
      {
        /* Add Extended Data Record number */

      /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
      /* PRQA S 3383 12 */
        if (DEM_ZERO == *LpRecNumberStored)
        {
           #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
            *LpBufSize =  *LpBufSize + DEM_ONE;
           #endif
           /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
           *(LpDestBuffer + LusDestBufferIndex) = Dem_GaaEDRecord // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
              [LucActualRecordIndex].ucExtendedDataRecordNumber;
          /* Increment buffer index */
          ++LusDestBufferIndex;
        }
        *LpRecNumberStored =   *LpRecNumberStored + DEM_ONE;
        
         #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
        if (LucReadMonitorEDdataStack < DEM_MAX_MONITOR_ED_RECDS_PER_EVENT)
        {
          LucReadMonitorEDdataStack++;
        } 
		#endif
      /* Loop for all data elements in the memory */
      /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      for (LucDataElementIndex = DEM_ZERO; (LucDataElementIndex <
        Dem_GaaEDRecord[LucActualRecordIndex].
        ucNumOfDataElements);
        LucDataElementIndex++)
      {
        /* Check Record containing internal data elements */
          /* and trig satisfied for the record*/
        #if (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)
    /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        if (((Dem_GaaEDRecord[LucActualRecordIndex].
        aaDataElementType[LucDataElementIndex]) ==
        (uint8)DEM_DATA_ELEMENT_INTERNAL))
        {
        *LpDestBuffIndx = LusDestBufferIndex;
        /* Invoke Dem_GetInternalDataElement to update internaldata element*/
        LddReturnValue = Dem_GetInternalDataElement(LucActualRecordIndex,
        LpBufSize,
        LpDestBuffer, LusEventParameterIndex,
        LpDTCAttribute, DTCOrigin, LpDestBuffIndx
        , LucStoredIndex,
        LucDataElementIndex
         #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
        , &LucReadMonitorEDdataStack
        #endif
        );
        #if ((DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS > DEM_ZERO) ||\
             (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR > DEM_ZERO))
        LusDestBufferIndex = *LpDestBuffIndx;
        #endif
        }
        else
        #endif
        {
          #if ((DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS > DEM_ZERO) ||\
               (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR > DEM_ZERO))
          /* Get the index of the data element */
          LusTempIndex = Dem_GaaEDRecord[LucActualRecordIndex].
                                      aaDataElementIndex[LucDataElementIndex];
          /* Initialize default value */
          LusRecSize = DEM_ZERO;
          #endif
          #if (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS > DEM_ZERO)
      /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
          if ((uint8)DEM_DATA_ELEMENT_EXTERNAL_CS ==
                        (Dem_GaaEDRecord[LucActualRecordIndex].
                                        aaDataElementType[LucDataElementIndex]))
          {
            /* Data element size is fetched from Client server interface */
            LusRecSize = Dem_GaaDataElementExternalCS[LusTempIndex].
                      ucDemDataElementDataSize;
          }
          #endif

          #if (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR > DEM_ZERO)
          if ((uint8)DEM_DATA_ELEMENT_EXTERNAL_SR ==
                        (Dem_GaaEDRecord[LucActualRecordIndex].
                                        aaDataElementType[LucDataElementIndex]))
          {
            /* Data element size is fetched from Sender Receiver interface */
            LusRecSize = Dem_GaaDataElementExternalSR[LusTempIndex].
                      ucDemDataElementDataSize;
          }
          #endif

          #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
          #if ((DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS > DEM_ZERO) ||\
                  (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR > DEM_ZERO))
          /* Load the actual buffer size */
          LusRawDataSize = LusRecSize;
          #endif
          #endif

          #if ((DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS > DEM_ZERO) ||\
                  (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR > DEM_ZERO))
          /* Load the Extended data into destination buffer */
          for (LusLoadDataIndex = DEM_ZERO; LusLoadDataIndex <
          #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
          LusRecSize
          #else
          LusRawDataSize
          #endif
          ; LusLoadDataIndex++)
          {
	    /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
        /* PRQA S 3383 34 */
        /* polyspace +6 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
            *(LpDestBuffer + LusDestBufferIndex) = // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
            (LpEventMemory + LucStoredIndex)->aaEdData // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
            [LucCount][DEM_ONE + LucCurrentBufferExtIndex];
            LusDestBufferIndex++;
            LucCurrentBufferExtIndex++;
          }
          #if (DEM_MAX_MONITOR_ED_RECDS_PER_EVENT > DEM_ZERO)
           LucMonitorDataSupport = Dem_GaaEDRecord[LucActualRecordIndex].
                  aaDataElementMonitorDataSupport[LucDataElementIndex];
          if ((LucMonitorDataSupport == DEM_MONITOR_TRUE) &&
           ((LucReadMonitorEDdataStack - DEM_ONE) < DEM_MAX_MONITOR_ED_RECDS_PER_EVENT))
          {  
          LucMonitorDataByte = (uint8)((LpEventMemory + LucStoredIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
                aaEdMonitorData[(LucReadMonitorEDdataStack - DEM_ONE)][DEM_ONE]);
          *(LpDestBuffer + LusDestBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
          LusDestBufferIndex++;
          LucMonitorDataByte = (uint8)((LpEventMemory + LucStoredIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
          aaEdMonitorData[(LucReadMonitorEDdataStack - DEM_ONE)][DEM_ONE] >> DEM_ONE_BYTE);
          *(LpDestBuffer + LusDestBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
          LusDestBufferIndex++;
          LucMonitorDataByte = (uint8)((LpEventMemory + LucStoredIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
             aaEdMonitorData[(LucReadMonitorEDdataStack - DEM_ONE)][DEM_ONE] >> DEM_TWO_BYTE);
          *(LpDestBuffer + LusDestBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
          LusDestBufferIndex++;
          LucMonitorDataByte = (uint8)((LpEventMemory + LucStoredIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
          aaEdMonitorData[(LucReadMonitorEDdataStack - DEM_ONE)][DEM_ONE] >> DEM_THREE_BYTE);
          *(LpDestBuffer + LusDestBufferIndex) = LucMonitorDataByte; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
          LusDestBufferIndex++;
		  LucReadMonitorEDdataStack++;

          }
          #endif 
          *LpDestBuffIndx = LusDestBufferIndex;

          #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
          if ((uint16)DEM_ONE < LusDestBufferIndex)
			    {
				    *LpBufSize = LusDestBufferIndex - (uint16)DEM_ONE;
			    }
			    else 
          {
				    *LpBufSize = DEM_ZERO;
          }
          #else
          *LpBufSize = *LpBufSize + LusRecSize;
          #endif

          #endif
          } /*End of check for Extended or Internal data record */
        } /* End of Loop for all data elements in the memory */
      } /* End of Buffer size of record */
      /* Increment the buffer size for extended record */
      #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
      *LpBufSize = *LpBufSize + (uint16)DEM_ONE;
      #endif
      LblRecordFound = DEM_TRUE;
    } /*End of check for Extended data record */
    else /* If record not found in the memory */
    {
      /* Get the actual index of the record */
      LucActualRecordIndex =
           LpDTCAttribute->aaExtendedDataRecords[LucCount];
    /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      /* check if it is valid record */
      if ((Dem_GaaEDRecord[LucActualRecordIndex].
              ucExtendedDataRecordNumber) == ExtendedDataNumber)
      {
        #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
        *LpBufSize = DEM_ZERO;
        #endif
        LblRecordFound = DEM_TRUE;
      } /*End of check for Extended data record */
    }  /*End of record not found in memory*/
  }  /* End of for loop for all extended data record for
                                              current event*/
   
  /* Check if record is found  */
  if (!LblRecordFound)
  {
    LddReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 1 */
   DEM_UNUSED(DTCOrigin);
  #if ((DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_CS == DEM_ZERO) && \
       (DEM_NUMBER_OF_DATA_ELEMENT_EXTERNAL_SR == DEM_ZERO))
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 1 */
  DEM_UNUSED(LusDestBufferIndex);
  #endif
  return LddReturnValue;
} /* End Of Dem_GetExtendedDataRecordByDTCExistInMem */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_GetExtendedDataRecordByDTCVAlidButNotInMem      **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Gets extended data by DTC. The function             **
**                        stores the data in the provided DestBuffer if DTC   **
**                        is valid but not   present in memory                **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : ExtendedDataNumber,LusDTCAttributeIndex             **
**                                                                            **
** InOut parameter      : BufSize                                             **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_ED_RECDS should be greater than   **
                          ZERO                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaEDRecord,              **
**                                              Dem_GaaDTCAttributes,         **
**                        Function(s) invoked : Det_ReportError               **
**                                                                            **
** Design ID            : DEM_SDD_0621,DEM_SDD_0402                           **
*******************************************************************************/
#if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
    (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType 
  Dem_GetExtendedDataRecordByDTCVAlidButNotInMem(const uint16 LusDTCAttributeIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  const uint8 ExtendedDataNumber, uint16* const LpBufSize ) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  uint8                     LucCount;
  uint8                     LucNumOfEDRecords;
  Std_ReturnType                           LddReturnValue;
  #if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO)
  boolean                   LblRecordValid;
  #endif

  /* Initialize the record found to FALSE */
  LblRecordValid = DEM_FALSE;
  /* SWS_Dem_00631 */
  if (DEM_MAX_EXTENDED_RECORD_NUMBER == ExtendedDataNumber)
  {
	  LblRecordValid = DEM_TRUE;
  }
  /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Get Number of Records for current event */
  LucNumOfEDRecords =
          Dem_GaaDTCAttributes[LusDTCAttributeIndex].ucNumOfEDRecords;
  /* Loop for all records */
  for (LucCount = DEM_ZERO; ((LucCount <
  LucNumOfEDRecords) && (!LblRecordValid)); LucCount++)
  {
  /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Check if record number is valid */
    if ((Dem_GaaEDRecord[
        Dem_GaaDTCAttributes[LusDTCAttributeIndex].
        aaExtendedDataRecords[LucCount]].
        ucExtendedDataRecordNumber) == ExtendedDataNumber)
    {
      LblRecordValid = DEM_TRUE;
    }
  }
  /* Check if Valid record Found */
  if (LblRecordValid)
  {
    /* Load the buffer with value zero */
    *LpBufSize = DEM_ZERO;
    /* Return */
    LddReturnValue = E_OK;
  }
  else
  {
    /* Return  wrong Number */
    LddReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  return LddReturnValue;
} /* End Of Dem_GetExtendedDataRecordByDTCVAlidButNotInMem */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_GetSizeOfEDRecordByDTCFoundInMem      **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Gets the size of extended data by DTC found in      **
                          memory.                                             **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : DTC, DTCOrigin, ExtendedDataNumber                  **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : SizeOfExtendedDataRecord                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaEventParameter,        **
**                                              Dem_GaaSuppressionStatus      **
**                        Function(s) invoked : Dem_GaaEDRecord,              **
**                                              Det_ReportError               **
**                                              Dem_GetSizeOfRecNoFFandFE     **
**                                                                            **
** Design ID            : DEM_SDD_0624                                        **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
 /* Polyspace InternalFunc_c_Ref_201 */
Std_ReturnType  Dem_GetSizeOfEDRecordByDTCFoundInMem(
 const uint8 ExtendedDataNumber, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_2 Violates MISRA 2012 Required
     Rule 8.13 */
  /* PRQA S 3673 1 */
  uint16* LpSizeOfExtendedDataRecord // parasoft-suppress CERT_C-API00-a-3 MISRAC2012-RULE_8_13-a-4 CERT_C-DCL13-a-3 CERT_C-DCL00-b-3 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_21 Dem_InternalFunc_c_REF_27 Dem_InternalFunc_c_REF_9"
  #if ((DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL) || \
  ((DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO) || \
  (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)))
  , const Dem_EventMemory*  LpEventMemory // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
   #endif
 #if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO)
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
  , const uint8*  const LaaMemInds // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  , const uint8 LucNumOfEvts // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  #else
  , const uint16 LusEventParameterIndex // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  #if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO)
  , const uint8 LucEventMemoryIndex // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  #endif
  #endif
  #endif
  )
{
  Std_ReturnType                   LddReturnValue;
  #if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO)
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
  uint8             LucEntryCnt;
  #endif
  #endif
  #if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
      (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
  uint16            LusBuffSize;
  uint8             LucCount;
  boolean           LblRecordFound;
  boolean           LblValidRecord;
  boolean           LblRecordDataFound;
  #endif
   #if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO)
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
  uint16            LusEventParameterIndex;
  uint8             LucEventMemoryIndex;
  #endif
  #endif
  #if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
      (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
  LblRecordDataFound = DEM_FALSE;
  #endif
  #if (((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
      (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO)) || \
      ((DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO) && \
      (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)))
  /* Polyspace InternalFunc_c_Ref_205 */
  LddReturnValue = E_OK;
  #endif

  #if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO)
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
  for (LucEntryCnt = DEM_ZERO; ((LucEntryCnt < LucNumOfEvts)
  && (LddReturnValue == E_OK)); LucEntryCnt++)
  #endif
  #endif
  { /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
    /* PRQA S 3383 6 */
    #if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO)
    #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
  /* polyspace +1 RTE:NIV [Justified:Low] "Refer Dem_c_Poly_REF_8" */
    LucEventMemoryIndex = LaaMemInds[LucEntryCnt];
    LusEventParameterIndex =
             (LpEventMemory[LucEventMemoryIndex].ddEventId) - DEM_ONE;
    #endif
    #endif

      #if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
          (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
      /* Check if a specific record or all the records captured
      has to be retrieved */
      if ((ExtendedDataNumber != DEM_MAX_EXTENDED_RECORD_NUMBER) &&
                  (ExtendedDataNumber != DEM_EXTENDED_DATA_NUMBER_OBD))
      {
        LblRecordFound = DEM_FALSE;
        LblValidRecord = DEM_FALSE;
        /* polyspace +6 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
        /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        /* Loop through all the records for the Event */
        for (LucCount = DEM_ZERO; (LucCount <
         (Dem_GaaEventParameter[LusEventParameterIndex].pDTCAttribute)->
         ucNumOfEDRecords) && ((!LblRecordFound) &&
         (!LblValidRecord)); LucCount++)
        {
          /* polyspace +6 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
          /* Check record is not stored in memory and */
          /* valid record number not stored because record trigger */
          /* check if it is valid record */
          if ((Dem_GaaEDRecord[
          (Dem_GaaEventParameter[LusEventParameterIndex].
          pDTCAttribute)->aaExtendedDataRecords[LucCount]].
          ucExtendedDataRecordNumber) ==
          ExtendedDataNumber)
          {
              /* Check for record number matching in memory */


              if ((LpEventMemory + LucEventMemoryIndex)->aaEdData[LucCount] // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
                  [DEM_ZERO] == ExtendedDataNumber)
              {
                /* Get the size of ED record */
                *LpSizeOfExtendedDataRecord = (*LpSizeOfExtendedDataRecord) +
                (Dem_GaaEDRecord[
                (Dem_GaaEventParameter[LusEventParameterIndex].
                pDTCAttribute)->aaExtendedDataRecords[LucCount]].
                usEDRecordRawDataSize);
                #if (DEM_MAX_MONITOR_ED_EXT_RECDS_PER_EVENT > DEM_ZERO)
                 /* PRQA S 3383 4 */
                *LpSizeOfExtendedDataRecord +=  (Dem_GaaEDRecord[
                (Dem_GaaEventParameter[LusEventParameterIndex].
                pDTCAttribute)->aaExtendedDataRecords[LucCount]].
                usEDMonitorRawDataSize);
                #endif
                
                LblRecordDataFound = DEM_TRUE;
                LblRecordFound = DEM_TRUE;
              }
              /* Else LpSizeOfExtendedDataRecord No Update */
              LddReturnValue = E_OK;

            /* update variable to Record valid */
            LblValidRecord = DEM_TRUE;
          }/* End of valid record check*/
        }   /* End of For loop for no of records*/
        /* Record is not found or it is not valid  */
        if (!LblValidRecord)
        {
          /* Return value for wrong Record number */
          LddReturnValue = DEM_NO_SUCH_ELEMENT;
        }
      } 
      else  /*if requested record no is FF/FE*/
      {
        /* Collective size of all Record numbers belongs to the DTC  */
        /* Invoking  Dem_GetSizeOfRecNoFFandFE*/
        LusBuffSize = DEM_ZERO;
        Dem_GetSizeOfRecNoFFandFE(LusEventParameterIndex,
        #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
        &LucEntryCnt,
        #endif
        &LusBuffSize, ExtendedDataNumber,


        (LpEventMemory + LucEventMemoryIndex)); // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"

        (*LpSizeOfExtendedDataRecord) =
            (*LpSizeOfExtendedDataRecord) + LusBuffSize;
      }
      #else  /* start #else (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO) */
      /* Error report to DET */
      #if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO)
      /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012
          Required Rule 2.2 */
      /* PRQA S 3112 1 */
      DEM_UNUSED(LusEventParameterIndex);
      #endif

      /* Return value for wrong Record number */
      LddReturnValue = DEM_NO_SUCH_ELEMENT;
      /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012
         Required Rule 2.2 */
      /* PRQA S 3112 2 */
      DEM_UNUSED(LpSizeOfExtendedDataRecord);
      DEM_UNUSED(ExtendedDataNumber);
      #endif /* End of #if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO) */
  }
  #if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
          (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
  if (LblRecordDataFound)
  {
    *LpSizeOfExtendedDataRecord = (*LpSizeOfExtendedDataRecord) + (uint16)DEM_ONE;
  }
  #endif
  /* End of For loop for Combination(On Retrieval)*/
  /* For the filtered events in the memory */
  #if ((DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL) || \
  ((DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO) || \
  (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)))
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 1 */
  DEM_UNUSED (LpEventMemory);
  #if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO)
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 1 */
  DEM_UNUSED(LucEventMemoryIndex); // parasoft-suppress CERT_C-EXP33-a-1 MISRAC2012-RULE_9_1-a-1 MISRAC2012-RULE_1_3-b-2 "Refer: Dem_InternalFunc_c_REF_26"
  #endif
  #endif
  return LddReturnValue;
} /* End Of Dem_GetSizeOfEDRecordByDTCFoundInMem */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*******************************************************************************
** Function Name        : Dem_GetSizeOfExtendedDataRecordByDTCNotFoundInMem   **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Gets the size of extended data by DTC if not found  **
                          in memory.                                          **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : ExtendedDataNumber                                  **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : SizeOfExtendedDataRecord                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_DTC should be greater than Zero   **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaSuppressionStatus,     **
**                                              Dem_GaaDTCAttributes,         **
**                                              Dem_GaaEDRecord               **
**                        Function(s) invoked : Det_ReportError               **
**                                                                            **
** Design ID            : DEM_SDD_0625                                        **
*******************************************************************************/
#if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* Polyspace InternalFunc_c_Ref_201 */
Std_ReturnType  
 Dem_GetSizeOfExtendedDataRecordByDTCNotFoundInMem(
  #if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
      (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO))
  const uint16 LusDtcInfoIndex , // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  #endif
  const uint8 ExtendedDataNumber,
  uint16* const LpSizeOfExtendedDataRecord) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{

  Std_ReturnType                   LddReturnValue;
  #if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
      (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO))
  uint16            LusDTCAttributeIndex;
  #endif
  #if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO)
  uint8             LucCount;
  boolean           LblValidRecord;
  #endif
  LddReturnValue = E_OK;

  *LpSizeOfExtendedDataRecord = DEM_ZERO;
  #if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
      (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
  LblValidRecord = DEM_FALSE;

/* polyspace +6 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
 /* polyspace +4 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  LusDTCAttributeIndex = DEM_DTC_ATTRIBUTE_INDEX(LusDtcInfoIndex);
  /* Loop through all the records for in the Event */
  for (LucCount = DEM_ZERO; ((LucCount <
   Dem_GaaDTCAttributes[LusDTCAttributeIndex].
   ucNumOfEDRecords) &&
   (!LblValidRecord)); LucCount++)
  {
/* polyspace +6 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
     /* check if it is valid record */
    if ((Dem_GaaEDRecord[
    Dem_GaaDTCAttributes[LusDTCAttributeIndex].
    aaExtendedDataRecords[LucCount]].
    ucExtendedDataRecordNumber) ==
    ExtendedDataNumber)
    {
      LblValidRecord = DEM_TRUE;
    }
  }
  if (!LblValidRecord)
  #else
  #if (DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO)
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012
      Required Rule 2.2 */
  /* PRQA S 3112 2 */
  DEM_UNUSED(LucCount);
  DEM_UNUSED(LblValidRecord);
  #endif
  #endif
  {
    if (DEM_MAX_EXTENDED_RECORD_NUMBER  != ExtendedDataNumber)
    {
      /* Return Wrong Rec number */
      LddReturnValue = DEM_NO_SUCH_ELEMENT;
    }
  }  /* End of Valid record Check */
  return LddReturnValue;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/* End Of Dem_GetSizeOfExtendedDataRecordByDTCNotFoundInMem */
/*******************************************************************************
** Function Name        : Dem_ResetFdc                                        **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Resets FDC of Internal Debounce Configured Events   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : LusEventIndex                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :Global Variable(s):   Dem_GaaEventParameter,         **
**                                             Dem_GaaIntDebounceCounter,     **
**                                             Dem_GaaAllFDC                  **
**                       Function(s) invoked : None                           **
**                                                                            **
** Design ID            : DEM_SDD_0559                                        **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_ResetFdc(const uint16 LusEventIndex) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  #if (((DEM_DEBOUNCE_TIME_SUPPORT == STD_ON) && \
        (DEM_NUMBER_OF_TIME_BASED_DEBOUNCE > DEM_ZERO)) || \
       ((DEM_DEBOUNCE_COUNTER_SUPPORT == STD_ON) && \
        (DEM_NUMBER_OF_COUNTER_BASED_DEBOUNCE > DEM_ZERO)))
  uint16  LusIndexOfDebounceAry;
  uint16  LusIndexOfIntDebounceAry;
  /* get the debounce indes of the array */
  LusIndexOfDebounceAry = DEM_EVENT_DEBOUNCE_ALGORITHM_CLASS(LusEventIndex);// parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Refer: Dem_InternalFunc_c_REF_18"
  /*get the debounce index for internal debounce counter*/
  LusIndexOfIntDebounceAry =
  Dem_GaaEventParameter[LusEventIndex].usIndexOfInternalCntDebounceAry;
  #endif

  #if ((DEM_DEBOUNCE_COUNTER_SUPPORT == STD_ON) && \
       (DEM_NUMBER_OF_COUNTER_BASED_DEBOUNCE > DEM_ZERO))
  /* polyspace +7 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* set dtc as disabled for this event */
  /* Check if debounce is counter based and
     Check if latest debounce setting is RESET */
  if ((DEM_DEBOUNCE_COUNTER_BASED == Dem_GaaEventParameter[
                                     LusEventIndex].ucDebounceType) &&
    (DEM_DEBOUNCE_STATUS_RESET  == DEM_EVENT_DEBOUNCE_COUNTER_DEBOUNCE_BEHAVIOUR // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Refer: Dem_InternalFunc_c_REF_18"
                                     (LusIndexOfDebounceAry)))
  {
    /* SchM protection to be added(Pending) */
    /* To be reviewed for direction RESET */
    SchM_Enter_Dem_DEM_DATA_PROTECTION();
    /* Reset the internal debounce counter */
    Dem_GaaIntDebounceCounter[LusIndexOfIntDebounceAry] = (sint16)DEM_ZERO;
    /* Reset Fault detection COunter */
    Dem_GaaAllFDC[LusEventIndex] = (sint8)DEM_ZERO;
    SchM_Exit_Dem_DEM_DATA_PROTECTION();
  }
  #endif

  #if ((DEM_DEBOUNCE_TIME_SUPPORT == STD_ON) && \
       (DEM_NUMBER_OF_TIME_BASED_DEBOUNCE > DEM_ZERO))
  /* polyspace +6 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Check if debounce is timer based and
     Check if latest debounce setting is RESET */
  if ((DEM_DEBOUNCE_TIME_BASED == Dem_GaaEventParameter[
                                     LusEventIndex].ucDebounceType) &&
     (DEM_DEBOUNCE_STATUS_RESET  == DEM_EVENT_DEBOUNCE_TIME_DEBOUNCE_BEHAVIOUR  // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Refer: Dem_InternalFunc_c_REF_18"
                                     (LusIndexOfDebounceAry)))
  {
    /* Reset the internal debounce timer */
    /* To be reviewed for direction RESET */
    SchM_Enter_Dem_DEM_DATA_PROTECTION();
    /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    Dem_GaaIntDebounceTimer[LusIndexOfIntDebounceAry] = DEM_ZERO;
    /* Reset Fault detection COunter */
    Dem_GaaAllFDC[LusEventIndex] = (sint8)DEM_ZERO;

    Dem_GaaFDCDirectionTD[LusIndexOfIntDebounceAry] = (uint8)DEM_FDC_RESET;
    Dem_GaaTimeDebounceEntry[LusIndexOfIntDebounceAry].ddEventId = DEM_ZERO;
    Dem_GaaTimeDebounceFreeze[LusIndexOfIntDebounceAry] = DEM_FREEZE;
    Dem_GaaTimeDebounceEntry[LusIndexOfIntDebounceAry].ddEventStatus =
                               (Dem_EventStatusType)DEM_INVALID_EVENT_STATUS;

    SchM_Exit_Dem_DEM_DATA_PROTECTION();
  }
  #endif

  #if (DEM_NUMBER_OF_MONITOR_INTERNAL_DEBOUNCE > DEM_ZERO)
  /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Check if requested EventId is configure with monitor based debounce */
  if (DEM_DEBOUNCE_MONITOR_BASED ==
     Dem_GaaEventParameter[LusEventIndex].ucDebounceType)
  {
    Dem_GaaAllFDC[LusEventIndex] = (sint8)DEM_ZERO;
  }
  #endif
} /* End Of Dem_ResetFdc */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
** Function Name        : Dem_DTCFilterDetCheck                               **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Checks for the DET errors                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : DTCKind, DTCFormat, DTCOrigin,                      **
**                        FilterWithSeverity, DTCSeverityMask,                **
**                        FilterForFaultDetectionCounter                      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :Global Variable(s):   None                           **
**                       Function(s) invoked : Det_ReportError                **
**                                                                            **
** Design ID            : DEM_SDD_0686                                        **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType   Dem_DTCFilterDetCheck(
     const uint8 ClientId // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
     #if ((DEM_DEV_ERROR_DETECT == STD_ON) && \
          (DEM_OBD_SUPPORT == DEM_OBD_NO_OBD_SUPPORT))
     , const Dem_DTCFormatType DTCFormat
     #endif
     , const Dem_DTCOriginType DTCOrigin
     #if (DEM_DEV_ERROR_DETECT == STD_ON)
     #if (DEM_OBD_SUPPORT == DEM_OBD_NO_OBD_SUPPORT)
     , const Dem_DTCSeverityType DTCSeverityMask
     #endif
     #endif
     )
{
  const Dem_EventMemorySetType*  LpEventMemorySet;
  /* Local Variable for Returntype */
  Std_ReturnType LddReturnValue;
  #if (DEM_USER_DEF_MEMORY_CONFIGURED == STD_ON)
  uint8 LucDTCOrigin;
  #endif

  /* Local Variable for DTC Origin */
  boolean  LblDetDTCOrigin;

  /* Initialize set Filter status */
  LddReturnValue = E_OK;

  LblDetDTCOrigin = DEM_FALSE;
  /* Get pointer reference to Memeory Set for Origin check */
  /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  LpEventMemorySet = DEM_CLIENT_EVENT_MEMORYSET(ClientId);
  /* Check if Requested Origin is Primary Memory */
  if (DEM_DTC_PRIMARY_MEMORY == DTCOrigin)
  {
    /* Get Origin mapping index */
    Dem_GaaOriginMemMappingIndex[ClientId] =
                                LpEventMemorySet->ucPrimaryMemoryMappingIndex;
    /* Requeted origin found */
    LblDetDTCOrigin = DEM_TRUE;
  }
  #if ((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
       (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
  /* Check if Requested Origin is Permanent or OBD Relavant Memory */
  else if (((DEM_DTC_ORIGIN_PERMANENT_MEMORY == DTCOrigin) &&
            (DEM_ZERO != LpEventMemorySet->ucNumberEventEntryPermanent)) ||
			(DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY == DTCOrigin))
  {
    /* Set destination Flag found to TRUE and break loop */
    LblDetDTCOrigin = DEM_TRUE;
  }
  #endif
  #if (DEM_USER_DEF_MEMORY_CONFIGURED == STD_ON)
  /* Check if Requested Origin is User Defined Memory */
  else
  {
    for (LucDTCOrigin = DEM_ZERO;
         LucDTCOrigin < LpEventMemorySet->ucNumOfUserDefinedMemory;
         LucDTCOrigin++)
    {
      /* Check if requested origin is configured */
      if (DTCOrigin == LpEventMemorySet->aaUserDefinedMemoryId[LucDTCOrigin])
      {
        /* Get Origin mapping index */
        Dem_GaaOriginMemMappingIndex[ClientId] =
              LpEventMemorySet->aaUserDefinedMemoryMappingIndex[LucDTCOrigin];
        /* Set destination Flag found to TRUE and break loop */
        LblDetDTCOrigin = DEM_TRUE;
        break;
      }
    }
  }
  #endif
  #if (DEM_USER_DEF_MEMORY_CONFIGURED == STD_OFF)
  else
  {
    /*Do nothing*/
  }
  #endif
  /* Requested origin not found */
  if (!LblDetDTCOrigin)
  {
    #if (DEM_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_SETDTCFILTER_SID, DEM_E_WRONG_CONFIGURATION);
    #endif
    LddReturnValue = E_NOT_OK;
  }

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Checking of DTCSeverityMask is not required for OBD*/
  /* UDS Format and EMISSION DTC is also possible and needs to be updated 0x12*/
  #if (DEM_OBD_SUPPORT == DEM_OBD_NO_OBD_SUPPORT)
  if (DTCFormat != DEM_DTC_FORMAT_OBD)
  {
    /* DTCSeverityMask input is not defined */
    if ((DTCSeverityMask != (uint8)DEM_DTC_SEV_NO_SEVERITY) &&
       (DTCSeverityMask != (uint8)DEM_DTC_SEV_MAINTENANCE_ONLY) &&
       (DTCSeverityMask != (uint8)DEM_DTC_SEV_CHECK_AT_NEXT_HALT) &&
       (DTCSeverityMask != (uint8)DEM_DTC_SEV_IMMEDIATELY))
    {
      /* Report to DET */
      (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_SETDTCFILTER_SID, DEM_E_PARAM_DATA);

      LddReturnValue = E_NOT_OK;
    }
  }
  #endif
  #endif
  return(LddReturnValue);
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
** Function Name        : Dem_ProcessAsyncServiceRequest                      **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Process asynchonous Functions                       **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :Global Variable(s):   Dem_GstDtcAsyncServiceStat     **
**                       Function(s) invoked : Dem_ProcessClearGroupDTC       **
**                                             Dem_ClearAllEvents             **
**                                             Dem_ProcessClearSingleDTC      **
**                                                                            **
** Design ID            : DEM_SDD_1435                                        **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_ProcessAsyncServiceRequest(void)
{
  Dem_ClrNatureType LddClrNature;

  if (DEM_CLEAR_NONE != Dem_GstDtcAsyncServiceStat.ucClearProcessType)
  {
  switch (Dem_GstDtcAsyncServiceStat.ucServiceToProcess)
  {
    case DEM_CLEARDTC_SID:
	/* #violates #ref Dem_InternalFunc_c_REF_24  Violates MISRA 2012 Required Rule INT02 */
    /* PRQA S 1252 2 */
	#if ((DEM_J1939_DTC_SUPPORT == STD_ON) && \
         (DEM_J1939_CLEAR_DTC_SUPPORT == STD_ON)) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
    case DEM_J1939DCMCLEARDTC_SID:
    #endif
    {
      LddClrNature = Dem_GstDtcAsyncServiceStat.ddClrNature;
      /* CLear All Dtcs  */
      if ((uint8)DEM_CLEAR_TYPE_ALL_DTCS == LddClrNature)
      {
        Dem_GstDtcAsyncServiceStat.ucResponsToSend = Dem_ClearAllEvents();
      }
      #if (DEM_CLEAR_DTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS)
      #if (DEM_GROUPDTC_CONFIGURED == STD_ON)
      /* find requested DTC is AllDtc/GroupDTc/SingleDTC */
      else if ((uint8)DEM_CLEAR_TYPE_GROUPDTC == LddClrNature)
      {
        #if (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)
        Dem_GstDtcAsyncServiceStat.ucResponsToSend = Dem_ProcessClearGroupDTC();
        #else
        /* No Further operation Pending */
        Dem_GstDtcAsyncServiceStat.ucClearProcessType = DEM_CLEAR_NONE;
        /* Return E_OK */
        Dem_GstDtcAsyncServiceStat.ucResponsToSend = E_OK;
        #endif
      }
      #endif
      #if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
      else if ((uint8)DEM_CLEAR_TYPE_SINGLE_DTC == LddClrNature)
      {
        Dem_GstDtcAsyncServiceStat.ucResponsToSend =
                                    Dem_ProcessClearSingleDTC();
      }
      #endif
      #endif
      else
      {
        #if (DEM_DEV_ERROR_DETECT == STD_ON)
        /* Error report to DET */
        (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
                        Dem_GstDtcAsyncServiceStat.ucServiceToProcess,
                        DEM_E_WRONG_CONFIGURATION);
        #endif
        /* Return DEM_CLEAR_WRONG__DTC */
        Dem_GstDtcAsyncServiceStat.ucResponsToSend = DEM_WRONG_DTC;
        /* No Further operation Pending */
        Dem_GstDtcAsyncServiceStat.ucClearProcessType = DEM_CLEAR_NONE;
      }
    }
   #if ((DEM_MAX_NUM_OF_CLEAR_DTC_NOTIFICATION_PER_MEMORY_SET > DEM_ZERO) && \
         (DEM_CLEAR_DTC_BEHAVIOUR != DEM_CLRRESP_NONVOLATILE_FINISH))
    /* Notification to SWC about Clear DTC */
    if (E_OK == Dem_GstDtcAsyncServiceStat.ucResponsToSend)
    {
      Dem_NotifyClearDtcRequest(Dem_GstDtcAsyncServiceStat.ddCaller,
                                              DEM_CLEAR_NOTIFICATION_ON_FINISH);
    }
  #endif
    break;

    default:
    /* Do Nothing */
    break;
  }
  }
  if ((Dem_GstDtcAsyncServiceStat.ucResponsToSend == E_OK)
       #if ((DEM_CLEAR_DTC_BEHAVIOUR == DEM_CLRRESP_NONVOLATILE_FINISH) && \
            (DEM_NUM_OF_NV_BLOCKS > DEM_ZERO))
             || (Dem_GstDtcAsyncServiceStat.ucResponsToSend == DEM_PENDING)
       #endif
      )
  {
     Dem_ChkPndUpdateStatus();
  }
  /* #violates #ref Dem_InternalFunc_c_REF_24  Violates MISRA 2012 Required Rule INT02 */
  /* PRQA S 1252 2 */
    #if ((DEM_MULTICORE_SUPPORT == STD_ON) && \
       (DEM_NUM_OF_SATELLITE_CORE > DEM_ZERO)) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
    DEM_SET_FDC_UPDATE_FLAG_STATUS_FOR_SATELLITE_CORE()
  #endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*******************************************************************************
** Function Name        : Dem_ChkPndUpdateStatus                              **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : It check for the pending DTCs and update the Status **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :Global Variable(s):   Dem_GstDtcAsyncServiceStat     **
**                       Function(s) invoked : Dem_ProcessClearGroupDTC       **
**                                             Dem_ProcessClearSingleDTC      **
**                                                                            **
** Design ID            : DEM_SDD_1437                                        **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static void  Dem_ChkPndUpdateStatus(void)
{
  Dem_DTCOriginType LucDTCOrigin;
  uint8 LucClientId;
  #if ((DEM_CLEAR_DTC_BEHAVIOUR == DEM_CLRRESP_NONVOLATILE_FINISH) && \
      (DEM_NUM_OF_NV_BLOCKS > DEM_ZERO))
  #if (DEM_MAX_NUM_OF_CLEAR_DTC_NOTIFICATION_PER_MEMORY_SET > DEM_ZERO)
  Std_ReturnType LddReturnValue;
  #endif
  uint8    LucBlkCnt;
  uint8    LucBlkIndex;
  uint8    LucNVBlockStatus;
  boolean  LblPenBlk;
  boolean  LblFailedBlk;
  #if (DEM_MAX_NUM_OF_CLEAR_DTC_NOTIFICATION_PER_MEMORY_SET > DEM_ZERO)
  LddReturnValue = E_NOT_OK;
  #endif
  LblPenBlk = DEM_FALSE;
  LblFailedBlk = DEM_FALSE;
  #endif
  LucDTCOrigin = Dem_GstDtcAsyncServiceStat.ddDtcOrigin;
  LucClientId = Dem_GstDtcAsyncServiceStat.ddCaller;
       #if ((DEM_CLEAR_DTC_BEHAVIOUR == DEM_CLRRESP_NONVOLATILE_FINISH) && \
            (DEM_NUM_OF_NV_BLOCKS > DEM_ZERO))
	   SchM_Enter_Dem_DEM_DATA_PROTECTION();
       for (LucBlkCnt = DEM_ZERO; LucBlkCnt < Dem_GucBlkCnt; LucBlkCnt++)
       {
         /* polyspace +30 RTE:NIVL [Justified:Low] "Refer Dem_c_Poly_REF_5" */
         /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
         LucBlkIndex = Dem_GaaNvBlockIndBuffer[LucBlkCnt];
         /* Check if block status is NVM_REQ_PENDING */
         /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
         LucNVBlockStatus = Dem_GaaNVBlockStatus[LucBlkIndex];
         if (NVM_REQ_PENDING == LucNVBlockStatus)
         {
           LblPenBlk = DEM_TRUE;
           break;
         }
         /* Check if block status is other than NVM_REQ_OK and
             NVM_REQ_NV_INVALIDATED*/
         else if ((NVM_REQ_OK != LucNVBlockStatus) &&
                 (NVM_REQ_NV_INVALIDATED != LucNVBlockStatus))
         {
           LblFailedBlk = DEM_TRUE;
         }
          /* Check if block status is NVM_REQ_OK or NVM_REQ_NV_INVALIDATED */
         else
         {
           /*Do nothing*/
         }
       }
	   SchM_Exit_Dem_DEM_DATA_PROTECTION();
       if (LblPenBlk)
       {
          /* do nothing */
       }
       /* Check if any Pending block is found */
       else if (LblFailedBlk)
       {
         /* if any one block Failed return : DEM_CLEAR_FAILED */
         Dem_GucNvmClearFinish = DEM_CLEARDTC_CLEAR_MEMORY_ERROR;
         /* Set cleint operation status to FINISHED forfurther processing */
         Dem_GaaClientSelection[LucClientId].ucClientOperationState =
                                                 DEM_CLIENT_OPERATION_FINISHED;
       }
       else
       {
         /* Check if Clear DTC is in progress when
             Dem_Mainfunction is not called */
         if (DEM_CLEAR_NONE == Dem_GstDtcAsyncServiceStat.ucClearProcessType)
         {
           /* if none of the blocks were NVM_REQ_PENDING/not NVM_REQ_OK */
		   #if (DEM_MAX_NUM_OF_CLEAR_DTC_NOTIFICATION_PER_MEMORY_SET > DEM_ZERO)
           LddReturnValue = E_OK;
	       #endif
           /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
           Dem_GaaServiceInProcess[LucDTCOrigin] = DEM_INVALID;
           Dem_GucNvmClearFinish = DEM_CLEARDTC_COMPLETED;
           /* Set cleint operation status to FINISHED forfurther processing */
           Dem_GaaClientSelection[LucClientId].ucClientOperationState =
                                                 DEM_CLIENT_OPERATION_FINISHED;
         }
       }
       #else
       /*Design ID: DEM_SDD_1482 */
       /* Check if Clear DTC is in progress when
          Dem_Mainfunction is not called */
       if (DEM_CLEAR_NONE == Dem_GstDtcAsyncServiceStat.ucClearProcessType)
       {
         /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
         Dem_GstDtcAsyncServiceStat.ddCaller = DEM_INVALID_CLIENT_ID;
         Dem_GstDtcAsyncServiceStat.ucServiceToProcess = DEM_INVALID;
         Dem_GstDtcAsyncServiceStat.blPendingFlag = DEM_FALSE;
		 Dem_GstDtcAsyncServiceStat.blClrDTCCnfmFlag =  DEM_FALSE;
		 Dem_GaaServiceInProcess[LucDTCOrigin] = DEM_INVALID;
		#if (DEM_CLEAR_DTC_BEHAVIOUR == DEM_CLRRESP_VOLATILE)
		Dem_GucVolatileClrDtc = DEM_CLEARDTC_COMPLETED;
	    #endif
         /* Set cleint operation status to FINISHED forfurther processing */
         Dem_GaaClientSelection[LucClientId].ucClientOperationState =
                                                 DEM_CLIENT_OPERATION_FINISHED;
       }
       #endif
    #if ((DEM_CLEAR_DTC_BEHAVIOUR == DEM_CLRRESP_NONVOLATILE_FINISH) && \
     (DEM_NUM_OF_NV_BLOCKS > DEM_ZERO))
	/*Design ID: DEM_SDD_0006 */
    /* Check if NvM clear is Finished/Failed */
    if (Dem_GucNvmClearFinish == DEM_CLEARDTC_COMPLETED)
    {
      #if (DEM_MAX_NUM_OF_CLEAR_DTC_NOTIFICATION_PER_MEMORY_SET > DEM_ZERO)
      /* Notification to SWC about Clear DTC */
      if (E_OK == LddReturnValue)
      {
        Dem_NotifyClearDtcRequest(Dem_GstDtcAsyncServiceStat.ddCaller,
                                              DEM_CLEAR_NOTIFICATION_ON_FINISH);
      }
      #endif
      Dem_GstDtcAsyncServiceStat.ddCaller = DEM_INVALID_CLIENT_ID;
      Dem_GstDtcAsyncServiceStat.ucServiceToProcess = DEM_INVALID;
      Dem_GucNvmClearFinish = DEM_CLEARDTC_NOTIFY_SENT;
      Dem_GstDtcAsyncServiceStat.blPendingFlag = DEM_FALSE;
	  Dem_GstDtcAsyncServiceStat.blClrDTCCnfmFlag =  DEM_FALSE;
      /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      Dem_GaaServiceInProcess[LucDTCOrigin] = DEM_INVALID;
      Dem_GaaClientSelection[LucClientId].ucClientOperationState =
                                                      DEM_CLIENT_OPERATION_FINISHED;
    }
    #endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*******************************************************************************
** Function Name        : Dem_ProcessClearGroupDTC                           **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Clears Group DTC                                    **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :Global Variable(s):   Dem_GstDtcAsyncServiceStat     **
**                       Function(s) invoked : Dem_ProcessClearGroupDTC       **
**                                             Dem_ProcessClearSingleDTC      **
**                                                                            **
** Design ID            : DEM_SDD_1437                                        **
*******************************************************************************/
#if ((DEM_GROUPDTC_CONFIGURED == STD_ON) && \
(DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO) && \
(DEM_CLEAR_DTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static Std_ReturnType  Dem_ProcessClearGroupDTC(void)
{
  Std_ReturnType LddReturnValue;
  uint16  LaaEvtIndex[DEM_NUMBER_OF_EVENTS];
  uint16  LusEvtCnt;
  uint16  LusEvtInd;
  uint8   LucEventCount;
  uint8   LucGroupDtcIndex;
  LusEvtCnt = DEM_ZERO;
  /* Get the Group DTC Index from LddClrNature from Lower Nibble */
  LucGroupDtcIndex = (uint8)Dem_GstDtcAsyncServiceStat.usIndex;
  /* polyspace +10 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* loop for the events configured for the current clear requested Group DTC */
  for (LucEventCount = DEM_ZERO;(LucEventCount < // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_19"
           DEM_GRP_NO_OF_EVENTS_VALUE(LucGroupDtcIndex)); LucEventCount++)
  {
    /* load the index of current event */
    LusEvtInd =
         DEM_GRP_EVENT_VALUE(LucGroupDtcIndex , LucEventCount);
    /* Check if destination is matched with DTC origin */
    if ((Dem_GaaEventParameter[LusEvtInd].pDTCAttribute)->
        ucEventDestination ==
        ((uint8)(Dem_GstDtcAsyncServiceStat.ddDtcOrigin)))
    { /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
      /* PRQA S 3383 4 */
      /* Get the events Index */
      LaaEvtIndex[LusEvtCnt] =
       DEM_GRP_EVENT_VALUE(LucGroupDtcIndex , LucEventCount);
      LusEvtCnt++;
    }
  }
  if (DEM_ZERO == LusEvtCnt)
  {
    /* Check for DET Error */
    #if (DEM_DEV_ERROR_DETECT == STD_ON)
    /* Error report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
    Dem_GstDtcAsyncServiceStat.ucServiceToProcess, DEM_E_WRONG_CONFIGURATION);
    #endif
    LddReturnValue = DEM_WRONG_DTCORIGIN;
  }
  else
  {
    LddReturnValue = Dem_ClearGroupEvents(&LaaEvtIndex[DEM_ZERO], LusEvtCnt);
  }
  /* No Further operation Pending */
  Dem_GstDtcAsyncServiceStat.ucClearProcessType = DEM_CLEAR_NONE;
  /* Return Value */
  return LddReturnValue;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_ProcessClearSingleDTC                           **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Clears All DTC                                      **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :Global Variable(s):   Dem_GstDtcAsyncServiceStat     **
**                       Function(s) invoked : None                           **
**                                                                            **
** Design ID            : DEM_SDD_1436                                        **
*******************************************************************************/
#if ((DEM_MAX_NUMBER_OF_DTC > DEM_ZERO) && \
     (DEM_CLEAR_DTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static Std_ReturnType  Dem_ProcessClearSingleDTC(void)
{
  Std_ReturnType LddReturnValue;
  uint16  LaaEvtIndex[DEM_NUMBER_OF_EVENTS];
  uint16  LusDtcInfoIndex;
  #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
  uint16  LusCount;
  #endif
  #if ((DEM_DTC_SUPPRESSION_SUPPORT == STD_ON) || \
      (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
  boolean  LblSuppressionStatus;
  #endif

  LusDtcInfoIndex = Dem_GstDtcAsyncServiceStat.usIndex;
  /* To be verified for Suppression (Only for Single DTC)*/
  #if ((DEM_DTC_SUPPRESSION_SUPPORT == STD_ON) || \
      (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
  /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  LblSuppressionStatus = Dem_GaaSuppressionStatus[LusDtcInfoIndex];

  if (!LblSuppressionStatus)
  #endif
  {
    /* Get the Dtc attribute Index from the Lower Nibble */
    #if (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)
  /* polyspace +6 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */


    if (Dem_GaaDTCAttributes[DEM_DTC_ATTRIBUTE_INDEX(LusDtcInfoIndex)].
    ucEventDestination ==
    ((uint8)(Dem_GstDtcAsyncServiceStat.ddDtcOrigin)))
    #endif
    {
      #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
      #if (DEM_ONE < DEM_MAX_NUM_EVENTS_PER_DTC)

 /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      LusCount = DEM_DTC_NUMBER_OF_EVENTS(LusDtcInfoIndex);
      while (DEM_ZERO < LusCount)
      #else
      LusCount = DEM_ZERO;
      #endif
      #endif
      {
        /*Fetch the event(s) index mapped to dtc */
        #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_DISABLED)
          /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        LaaEvtIndex[DEM_ZERO] = DEM_DTC_EVENT_INDEX(LusDtcInfoIndex);
        #else
        #if (DEM_ONE < DEM_MAX_NUM_EVENTS_PER_DTC)
        --LusCount;
        #endif
      /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        LaaEvtIndex[LusCount] = DEM_DTC_COMBINED_EVENTS(LusDtcInfoIndex,
                                                                      LusCount);
        #endif
      }
      #if (DEM_WWHOBD_SUPPORT == STD_ON)
      if ((DEM_DTC_SEVERITY(LusDtcInfoIndex) & DEM_DTC_CLASS_ALL) != DEM_ZERO)
      {
        LddReturnValue = DEM_WRONG_DTC;
      }
      else
      #endif
      {
         /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        LddReturnValue = Dem_ClearGroupEvents(&LaaEvtIndex[DEM_ZERO],
                      #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
                      #if (DEM_ONE <= DEM_MAX_NUM_EVENTS_PER_DTC)
                      DEM_DTC_NUMBER_OF_EVENTS(LusDtcInfoIndex)
                      #else
                      DEM_ZERO
                      #endif
                      #else
                      DEM_ONE
                      #endif
                      );
      }
    }
    #if (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)
    else
    {
      /* Check for DET Error */
      #if (DEM_DEV_ERROR_DETECT == STD_ON)
      /* Error report to DET */
      (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      Dem_GstDtcAsyncServiceStat.ucServiceToProcess, DEM_E_WRONG_CONFIGURATION);
      #endif
      LddReturnValue = DEM_WRONG_DTCORIGIN;
    }
    #endif
  }
  #if ((DEM_DTC_SUPPRESSION_SUPPORT == STD_ON) || \
      (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
  else
  {
    LddReturnValue = DEM_WRONG_DTC;
  }
  #endif
  /* No Further operation Pending */
  Dem_GstDtcAsyncServiceStat.ucClearProcessType = DEM_CLEAR_NONE;
  /* Return Value */
  return LddReturnValue;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_ProcAgCntrAfterThresholdSatified                **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : This function involves the activity to be done      **
**                        Once the basic Aging criteria fulfilled             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpEventMemory, LusEventParameterIndex,              **
**                        LucMaxNumOfEventEntry,LpDTCAttribute,               **
**                        LpWWHOBDEventMemory,LucOrigin                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_MAX_EVENT_DESTINATION_SELECTED should be greater**
**                        than Zero,DEM_MAX_EVENT_PER_AGING_CYCLE should      **
**                        be greater than Zero,DEM_AGING_CYCLE_CONFIGURED     **
**                        should be STD_ON                                    **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaEventParameter,        **
**                                              Dem_GaaAllEvtStatus           **
**                                              Dem_GstObdEvntMemFF           **
**                                              Dem_GaaIndicatorList          **
**                                              Dem_GaaMilFaults              **
**                                              Dem_GulTimeSinceMilOn         **
**                                              Dem_GaaPID4DValue             **
**                                              Dem_GblMilStarted             **
**                                              Dem_GblSetDataPID21Call       **
**                                              Dem_GflDistTravMilOnKm        **
**                                              Dem_GaaPID21Value             **
**                        Function(s) invoked : Dem_RearrangeOldEvtsInd       **
**                                              Dem_StoreEnvironmentalData    **
**                                              Dem_CnfdEvtBufferHand
                                                (void) DEM_MEMSET                        **
** Design ID            : DEM_SDD_0918                                        **
**                                                                            **
*******************************************************************************/

#if ((DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO) && \
     (DEM_MAX_EVENT_PER_AGING_CYCLE > DEM_ZERO) && \
     (DEM_AGING_CYCLE_CONFIGURED == STD_ON))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* #violates #ref Dem_InternalFunc_c_REF_28 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5001 7 */
void  Dem_ProcAgCntrAfterThresholdSatified(
  Dem_EventMemory*  LpEventMemory, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
 const uint8 LucMemMappingIndx, const uint8 LucMaxNumOfEventEntry, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  const uint16 LusEventParameterIndex, const uint8 LucEventCount // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  #if (DEM_WWHOBD_SUPPORT == STD_ON)
  , Dem_WWHObdEventMemory*  LpWWHOBDEventMemory // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
  #endif
  )
{
  #if ((DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE) || \
       ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
        (DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ZERO)))
  uint16                               LusDtcInfoIndex;
  #endif
  #if ((DEM_MAX_NUMBER_OF_ED_RECDS == DEM_ZERO) &&  \
       (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO))
  uint8                                LucMemIndx;
  #endif
  #if (DEM_NUM_OF_NV_BLOCKS > DEM_ZERO)
  const uint8*                 LpNvMemBlockIndex;
  #endif
  #if (((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
        (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) && \
       (DEM_OBD_DTC_SUPPORT == STD_ON))
  #if (DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ZERO)
  uint8                                LucSizeOfDataElement;
  uint8_least                          LucDataElementCount;
  uint8                                LucMaxSizeOfDE;
  uint8                                LucPidCount;
  #endif
  #endif
  #if (DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_OFF) 
  Dem_EventMemory*     LpCurrOldEvtCnt;
  uint8                                LucNodeTailIndex;
  #endif
  #if (DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_OFF)
  uint16                                               LusDTCOrigin;
  Dem_EventIdType                                     LddCnfEvtID;
  uint16*              LpCnfdEvtBuff;
  uint16                               LusCnfdEvtBuffSize;
  uint16                               LusBufferIndex;
  boolean                              LblBuffEntryFound;
  #endif
  #if (((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
        (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) && \
       (DEM_OBD_DTC_SUPPORT == STD_ON))
  #if (DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ZERO)
  uint32                               LulObdDtc;
  #endif
  #if ((DEM_NUMBER_OF_INDICATORS_ATTRIBUTE > DEM_ZERO) && \
       (DEM_MIL_SUPPORT == STD_ON))
  uint8                                LucNumOfInd;
  uint8                                LucCount;
  #endif
  #endif

  #if ((DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_OFF) && \
       ((DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO) || \
       (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO) || \
       (DEM_WWHOBD_FF_SUPPORT == STD_ON)))
  #if ((DEM_CBK_EVENT_DATA_CHANGED_CNF == STD_ON) || \
       ((DEM_GENERALINTERFACE_SUPPORT == STD_ON) && \
       (DEM_GENERALEVENTDATACHANGED_CALLBACK_SUPPORT == STD_ON)) || \
       (DEM_NUM_OF_NV_BLOCKS > DEM_ZERO))
  #if (DEM_CBK_EVENT_DATA_CHANGED_CNF == STD_ON)
  uint16                               LusEventIndex;
  #endif
  sint8                                LscDataChange;
  LscDataChange = (sint8)DEM_ZERO;
  #endif
  #endif
  
  
 
  #if ((DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE) || \
       ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
        (DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ZERO)))
  /* polyspace +5 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  /* Get DTC Index for Event */
 /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  LusDtcInfoIndex = DEM_EVENT_MAPPED_DTC_INDEX(LusEventParameterIndex);
  #endif
  /* Rearrange ranks of events in memory*/
   #if ((DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW != STD_ON) &&   \
      (DEM_OBD_SUPPORT == DEM_OBD_NO_OBD_SUPPORT))
    if (Dem_GaaDTCOriginBasedPtrAddress[
                LucMemMappingIndx].ucEventDisplacement != DEM_DISPLACEMENT_NONE)
	#endif
	{
	 /* Reset Event ID to delete node */
    Dem_RearrangeOldEvtsInd(LucEventCount, LucMaxNumOfEventEntry, LpEventMemory);
    }

  /* Clear the event from memory */
  /* Polyspace InternalFunc_c_Ref_207 */


  *(LpEventMemory + LucEventCount) = Dem_GstDefaultEventMemory; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
  /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Reset Event Memory index */
  Dem_GaaMemoryIndexForEvt[LusEventParameterIndex] = DEM_INVALID;
  /* polyspace +10 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Fill stack with free memeory indexes */
  Dem_GaaAvailableMemIndexs[LucMemMappingIndx][
                    Dem_GaaMemFreeStackIndx[LucMemMappingIndx]] = LucEventCount;
  /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
  /* PRQA S 3383 6 */
  /* Increment stack pointer index to point to next location */ 
    if (DEM_OCC_MAX > Dem_GaaMemFreeStackIndx[LucMemMappingIndx])
		{
          ++Dem_GaaMemFreeStackIndx[LucMemMappingIndx];
		} 

  SchM_Enter_Dem_DEM_DATA_PROTECTION();
  /* Reset confirmed bit */
  Dem_GaaAllEvtStatus[LusEventParameterIndex] =
    (Dem_GaaAllEvtStatus[LusEventParameterIndex] & DEM_EVENTSTATUS_BIT3_RESET);
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
  /* polyspace +6 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Protection to be added */
  Dem_GaaDtcMainEvent[LusDtcInfoIndex] = DEM_ZERO;
  #endif
  SchM_Exit_Dem_DEM_DATA_PROTECTION();

  #if (DEM_WWHOBD_SUPPORT == STD_ON)
  /* Clear the event from memory */
/* polyspace +4 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  *LpWWHOBDEventMemory = Dem_GstWWHObdDefaultEventMemory;
  #endif

  #if (DEM_NUM_OF_NV_BLOCKS > DEM_ZERO)
  /* Get Memmory block index for respective destination */
/* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  LpNvMemBlockIndex =
        Dem_GaaDTCOriginBasedPtrAddress[LucMemMappingIndx].pNvMemBlockIndex;
  /* polyspace +14 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  /* Check if memory block is configured */
  if ((NULL_PTR != LpNvMemBlockIndex) &&
      (DEM_INVALID != LpNvMemBlockIndex[LucEventCount]))
  {
    /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Invoke NvM to write the contents of the buffer to NV Block */
    (void)NvM_WriteBlock(
        Dem_GaaNVBlocks[LpNvMemBlockIndex[LucEventCount]].usBlockID,
           /* #violates #ref Dem_EvtProcsg_c_REF_QAC_10 Violates MISRA 2012
              Required Rule REFERENCE - ISO:C90 */
           /* PRQA S 0491 1 */
           &LpEventMemory[LucEventCount]);
    /* Update block status to pending */
    Dem_GaaNVBlockStatus[LpNvMemBlockIndex[LucEventCount]] = NVM_REQ_PENDING;
  } /* End of check for Memory block configuration */

  #if (DEM_EVENT_STATUS_NVM_BLOCK_INDX != DEM_INVALID)
  /* Invoke NvM to write the contents of the buffer to NV Block */
/* polyspace +6 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  (void)NvM_WriteBlock(
        Dem_GaaNVBlocks[DEM_EVENT_STATUS_NVM_BLOCK_INDX].usBlockID,
        &Dem_GaaAllEvtStatus);
  /* Update block status to pending */
  Dem_GaaNVBlockStatus[DEM_EVENT_STATUS_NVM_BLOCK_INDX] = NVM_REQ_PENDING;
  #endif
  #endif

  #if ((DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO) ||  \
       (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO))
  #if (DEM_MAX_NUMBER_OF_ED_RECDS == DEM_ZERO) 
  Dem_EventSearchInMemory(LusEventParameterIndex, &LucMemIndx);
  if (Dem_GaaDTCOriginBasedPtrAddress[LucMemIndx].ucFfRecordEnumType == 
       DEM_FF_RECNUM_CONFIGURED)
  #endif
  {
  
    Dem_ClearRecordTriggers(LusEventParameterIndex);
  }
  #endif

  /* Clearing of OBD-FF Data */
  #if (((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || \
        (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) && \
       (DEM_OBD_DTC_SUPPORT == STD_ON))
  #if (DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ZERO)
  /* Check if Aged event is of OBD Event which had caused Freeze Frame
     Data Storage */


  LulObdDtc = DEM_OBD_DTC_VALUE(LusDtcInfoIndex);
  if (LulObdDtc == Dem_GstObdEvntMemFF.ulObdDtc)
  {
    /* Clear DTC Value */
    Dem_GstObdEvntMemFF.ulObdDtc = DEM_ZERO;
    /* Loop for Clearing all Pids */
    LucMaxSizeOfDE = DEM_MAX_SIZE_OF_PID_DATAELEMENT + DEM_ONE;
    #if (DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ONE)
    for (LucPidCount = DEM_ZERO;
         LucPidCount < DEM_MAX_NUMBER_OF_PID_RECDS; LucPidCount++)
    #else
    LucPidCount = DEM_ZERO;
    #endif
    {
      Dem_GstObdEvntMemFF.aaFFObdData[LucPidCount][DEM_ZERO] = DEM_ZERO;
      /* Clear No. of DataElement in to memory */
      Dem_GstObdEvntMemFF.aaFFObdData[LucPidCount][DEM_ONE] = DEM_ZERO;
    }
    /* Loop for clearing all the data elements per PID */
    #if (DEM_TOTAL_NUMBER_OF_PID_DATAELEMENT > DEM_ONE)
    for (LucDataElementCount = DEM_ZERO; LucDataElementCount <
        (uint8_least)DEM_TOTAL_NUMBER_OF_PID_DATAELEMENT; LucDataElementCount++)
    #else
    LucDataElementCount = DEM_ZERO;
    #endif
    {
      for (LucSizeOfDataElement = DEM_ZERO;
          LucSizeOfDataElement < LucMaxSizeOfDE;
          LucSizeOfDataElement++)
      {
        Dem_GstObdEvntMemFF.aaDataElement[LucDataElementCount]
                                        [LucSizeOfDataElement] = DEM_ZERO;
      }
    }
  }
  #endif

  #if ((DEM_NUMBER_OF_INDICATORS_ATTRIBUTE > DEM_ZERO) && \
       (DEM_MIL_SUPPORT == STD_ON))
  /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Get count of configured Indicator attributes to event */
  LucNumOfInd = Dem_GaaEventParameter[LusEventParameterIndex].
                                                      ucNumberofIndicator;
  /* Loop through all indicator attributes */
  for (LucCount = DEM_ZERO; LucCount < LucNumOfInd; LucCount++)
  {
    /* polyspace +9 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Check if mapped indicator ID is same as of MIL ID */
    if (Dem_GaaIndicatorList[Dem_GaaEventParameter[
        LusEventParameterIndex].aaIndicatorIndex[LucCount]].
          ddIndicatorId == DEM_MIL_INDICATOR_ID)
    {
      /* Check if MIL id OFF and no event is contributing to MIL */
      if ((DEM_MIL_ACTIVE() == DEM_INDICATOR_OFF) &&
          (Dem_GaaMilFaults[DEM_ZERO] == DEM_ZERO))
       
      {
        #if (DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
        /* Reset Time since mil is on */
        Dem_GulTimeSinceMilOn = DEM_ZERO;
        /* Reset Distance Travelled since mil is on */
        Dem_GflDistTravMilOnKm = (float32)DEM_ZERO;
        /* Reset flag for Time since mil is on */
        Dem_GblMilStarted = DEM_FALSE;
        /* polyspace +8 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        #endif
        /* polyspace +11 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        #if (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)
        #if (DEM_OBD_CENTRALIZED_PID21_HANDLING == STD_ON)
        /* Reset PID21 Data */
        Dem_GaaPID21Value[DEM_ZERO] = DEM_ZERO;
        Dem_GaaPID21Value[DEM_ONE]  = DEM_ZERO;
        /* Reset the Flag */
        Dem_GblSetDataPID21Call = DEM_FALSE;
        #endif
        /* Reset PID4D Data */
        Dem_GaaPID4DValue[DEM_ZERO] = DEM_ZERO;
        Dem_GaaPID4DValue[DEM_ONE]  = DEM_ZERO;
        #endif
      }
    }
  }
  #endif
  #endif
  /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  #if (DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_OFF)
  LusDTCOrigin =
         (uint8) Dem_GaaDTCOriginBasedPtrAddress[LucMemMappingIndx].usDtcOrigin;
  LusCnfdEvtBuffSize = Dem_CnfdEvtBufferHand(LusDTCOrigin, &LpCnfdEvtBuff);
  LblBuffEntryFound = DEM_FALSE;
  for (LusBufferIndex = DEM_ZERO; ((LusBufferIndex < LusCnfdEvtBuffSize)
      && (!LblBuffEntryFound)); LusBufferIndex++)
  {
    /* polyspace +4 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    if (DEM_ZERO  != LpCnfdEvtBuff[LusBufferIndex])
    {
      LddCnfEvtID = LpCnfdEvtBuff[LusBufferIndex];
      LpEventMemory[LucEventCount].ddEventId = LddCnfEvtID;
	  /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
      /* PRQA S 3383 5 */
      /* Store memory Index */
      /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      Dem_GaaMemoryIndexForEvt[LddCnfEvtID - DEM_ONE] = LucEventCount;
      /* Increment stack pointer index to point to next location */
      --Dem_GaaMemFreeStackIndx[LucMemMappingIndx];
    /* polyspace +10 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      /* Fill stack with free memeory indexes */
      Dem_GaaAvailableMemIndexs[LucMemMappingIndx][
         Dem_GaaMemFreeStackIndx[LucMemMappingIndx]] = DEM_INVALID_MEMORY_INDEX;
      LpCnfdEvtBuff[LusBufferIndex] = DEM_ZERO;
      /* polyspace +3 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
      /* Increment the occurrence counter */
      Dem_GaaDTCOriginBasedPtrAddress[LucMemMappingIndx].pEventMemory
                                [LucEventCount].ucOccuranceCounter = DEM_ONE;

      #if ((DEM_MAX_NUMBER_OF_ED_RECDS > DEM_ZERO) || \
           (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO) || \
           (DEM_WWHOBD_FF_SUPPORT == STD_ON))
      /* Invoke Dem_StoreEnvironmentalData to store Environmental Data */
      Dem_StoreEnvironmentalData(LpEventMemory
      #if (DEM_WWHOBD_FF_SUPPORT == STD_ON)
      , LpWWHOBDEventMemory
      #endif
      #if ((DEM_CBK_EVENT_DATA_CHANGED_CNF == STD_ON) || \
           ((DEM_GENERALINTERFACE_SUPPORT == STD_ON) && \
           (DEM_GENERALEVENTDATACHANGED_CALLBACK_SUPPORT == STD_ON)) || \
           (DEM_NUM_OF_NV_BLOCKS > DEM_ZERO))
      , &LscDataChange
      #endif
      );

      /*Call to immediate write of data*/
    #if ((DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) &&  \
     (DEM_IMMEDIATE_FIRST_OCCURRENCE == STD_ON))
      Dem_ProcessImmediateStorageInMem(LpEventMemory, LucEventCount);
      #endif
      /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 
	  Required Rule INT30 */
      /* PRQA S 3383 4 */
      #if (DEM_CBK_EVENT_DATA_CHANGED_CNF == STD_ON)
      LusEventIndex = (LpEventMemory->ddEventId) - DEM_ONE;
     /* polyspace +7 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      if (DEM_INVALID_EVENT_DATA_CHANGED_ROUTINE !=
        Dem_GaaEventParameter[LusEventIndex].pDemEventDataChanged)
      {
        /* Invoke data changed call back */
        (void)Dem_GaaEventParameter[LusEventIndex].
                               pDemEventDataChanged(LpEventMemory->ddEventId);
      }
      #endif
      /* Invoke data changed general interface call back */
      #if ((DEM_GENERALINTERFACE_SUPPORT == STD_ON) && \
      (DEM_GENERALEVENTDATACHANGED_CALLBACK_SUPPORT == STD_ON))
      DEM_GENERAL_EVTDATACHNGED_CALLBACK(LpEventMemory->ddEventId)
      #endif
      #endif
      #if (DEM_OBD_SUPPORT == DEM_OBD_NO_OBD_SUPPORT)
      if (Dem_GaaDTCOriginBasedPtrAddress[
                LucMemMappingIndx].ucEventDisplacement != DEM_DISPLACEMENT_NONE)
	  #endif
	    {
      
        /* Point to node where data need to be filled */


      LpCurrOldEvtCnt = LpEventMemory + LucEventCount; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
      /* Store EventId Value in node */
      LpCurrOldEvtCnt->ddEventId = LddCnfEvtID;
      /* Get Tail index value */
      /* polyspace +25 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      LucNodeTailIndex =
                     Dem_GaaOldEvtCntHeadTailIndex[LucMemMappingIndx][DEM_ONE]; // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
      /* polyspace +5 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* Update tail node next index value to current node index */


      (LpEventMemory + LucNodeTailIndex)->ucNextEventIdIndex = LucEventCount; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
      /* Update Previous node with Invalid value */
      LpCurrOldEvtCnt->ucPreviousIndex =
                     Dem_GaaOldEvtCntHeadTailIndex[LucMemMappingIndx][DEM_ONE]; // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
      /* Update Next node with Invalid value */
      LpCurrOldEvtCnt->ucNextEventIdIndex = DEM_INVALID;
      /* Update tail to current node */
      Dem_GaaOldEvtCntHeadTailIndex[LucMemMappingIndx][DEM_ONE] = LucEventCount; // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"

    }
      LblBuffEntryFound = DEM_TRUE;
    }
  }
  #endif

  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012
      Required Rule 2.2 */
  /* PRQA S 3112 1 */
  #if (DEM_WWHOBD_SUPPORT == STD_ON)
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 1 */
  DEM_UNUSED(LpWWHOBDEventMemory);
  #endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_ProcAgCntrAfterThrSatifiedTfslc                **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : This function involves the activity to be done      **
**                        Once the basic Aging criteria fulfilled for TFSLC   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LusEventParameterIndex                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_STATUS_BIT_HANDLING_TFSLC shall be              **
**                        DEM_STATUS_BIT_AGING_AND_DISPLACEMENT should        **
**                        be greater than Zero,DEM_AGING_CYCLE_CONFIGURED     **
**                        should be STD_ON                                    **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaAllEvtStatus,          **
**                        Function(s) invoked :                               **
** Design ID            : DEM_SDD_0919                                        **
**                                                                            **
*******************************************************************************/

#if (DEM_STATUS_BIT_HANDLING_TFSLC == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_ProcAgCntrAfterThrSatifiedTfslc(
                     const uint16 LusEventParameterIndex // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
                     )
{
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
  uint16  LusDtcInfoIndex;
  uint16  LusEventIndex;
  uint16   LusCombiEvents;
  #endif
 /* polyspace +7 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
  /* Get DTC Index for Event */
  LusDtcInfoIndex = DEM_EVENT_MAPPED_DTC_INDEX(LusEventParameterIndex);
  /* Loop for number of combined events */
  for (LusCombiEvents = DEM_ZERO;
   LusCombiEvents < DEM_DTC_NUMBER_OF_EVENTS(LusDtcInfoIndex); LusCombiEvents++) // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 
  {
    /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Fetch the Event index */
    LusEventIndex = DEM_DTC_COMBINED_EVENTS(LusDtcInfoIndex, LusCombiEvents);
    SchM_Enter_Dem_DEM_DATA_PROTECTION();
  /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Reset the TFSLC bit i.e. bit 5 */
    Dem_GaaAllEvtStatus[LusEventIndex] =
      Dem_GaaAllEvtStatus[LusEventIndex] &
      DEM_EVENTSTATUS_BIT5_RESET;
   SchM_Exit_Dem_DEM_DATA_PROTECTION();
  }
  #else
  /* Reset the TFSLC bit i.e. bit 5 */
  SchM_Enter_Dem_DEM_DATA_PROTECTION();
  /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  Dem_GaaAllEvtStatus[LusEventParameterIndex] =
    Dem_GaaAllEvtStatus[LusEventParameterIndex] &
    DEM_EVENTSTATUS_BIT5_RESET;
  SchM_Exit_Dem_DEM_DATA_PROTECTION();
  #endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_ProccessingLeastRatio                           **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : This Function caluculates which ratio has least     **
**                        value
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LusEventParameterIndex                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : DEM_STATUS_BIT_HANDLING_TFSLC shall be              **
**                        DEM_STATUS_BIT_AGING_AND_DISPLACEMENT should        **
**                        be greater than Zero,DEM_AGING_CYCLE_CONFIGURED     **
**                        should be STD_ON                                    **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaAllEvtStatus,          **
**                        Function(s) invoked :                               **
**  Design ID           : DEM_SDD_1485                                        **
**                                                                            **
*******************************************************************************/

#if (DEM_IUMPR_STATUS_HANDLING == DEM_IUMPR_RATIO_SPECIFIC)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_ProccessingLeastRatio(void)
{
  uint16   LusRatioCount;
  float32  LflRatioValue;
  float32  LflCalRatioValue;
  uint16   LusRatioIndex;
  uint8    LucIumprGroupId;

  LflRatioValue = (float32)DEM_MAX_IUPMR_RATIO;
  LusRatioIndex = DEM_ZERO;
  for (LucIumprGroupId = DEM_ZERO;
                    LucIumprGroupId < DEM_TWENTY_ONE; LucIumprGroupId++)
  {
    if (NULL_PTR != Dem_GaaIUMPRRatio[LucIumprGroupId])
    {
      /* Loop through all the ratios mapped to that event */
      for (LusRatioCount = DEM_ZERO;
            LusRatioCount < (uint16) Dem_GaaIUMPRSize[LucIumprGroupId]; LusRatioCount++)// parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT13-a-2 CERT_C-INT13-b-2 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_24 
      {
        /* Requirement 69*/
        if (DEM_ZERO  != Dem_GaaIumprIntrlDenominatorCount
          [(*(Dem_GaaIUMPRRatio[LucIumprGroupId] + LusRatioCount))])
        {
          LflCalRatioValue = ((float32)(Dem_GaaIumprIntrlNumeratorCount
            [(*(Dem_GaaIUMPRRatio[LucIumprGroupId] + LusRatioCount))]) /
                            (float32)(Dem_GaaIumprIntrlDenominatorCount
            [(*(Dem_GaaIUMPRRatio[LucIumprGroupId] + LusRatioCount))]));
        }
        else
        {
          LflCalRatioValue = (float32)DEM_MAX_IUPMR_RATIO;
        }

        /* Requirement 69*/
        if ((float32)DEM_MAX_IUPMR_RATIO < LflCalRatioValue)
        {
          LflCalRatioValue = (float32)DEM_MAX_IUPMR_RATIO;
        }

        if (LflCalRatioValue < LflRatioValue)
        {


          LusRatioIndex = *(Dem_GaaIUMPRRatio[LucIumprGroupId] + LusRatioCount);
          LflRatioValue = LflCalRatioValue;
        }
        else if (!((LflCalRatioValue > LflRatioValue) ||
                  (LflRatioValue > LflCalRatioValue)))
        { /* #violates #ref Dem_InternalFunc_c_REF_27  Violates MISRA 2012 Required Rule INT30 */
          /* PRQA S 3383 14 */
          if (DEM_ONE  < Dem_GaaIUMPRSize[LucIumprGroupId]) // parasoft-suppress CERT_C-MSC12-j-3 MISRAC2012-RULE_14_3-ac-2 "Refer: Dem_InternalFunc_c_REF_29"
          {
            if (Dem_GaaIumprIntrlDenominatorCount
            [(*(Dem_GaaIUMPRRatio[LucIumprGroupId] + LusRatioCount))] >
              Dem_GaaIumprIntrlDenominatorCount
          [(*(Dem_GaaIUMPRRatio[LucIumprGroupId] + (LusRatioCount - DEM_ONE)))])
            {
              LusRatioIndex =
              *(Dem_GaaIUMPRRatio[LucIumprGroupId] + LusRatioCount);
            }
            else
            {
              LusRatioIndex =
              *(Dem_GaaIUMPRRatio[LucIumprGroupId] + (LusRatioCount - DEM_ONE));
            }
          }
        }
        else if (DEM_ONE  == Dem_GaaIUMPRSize[LucIumprGroupId])
        {
          LusRatioIndex =
            *(Dem_GaaIUMPRRatio[LucIumprGroupId] + LusRatioCount);
        }
        else
        {
          /* to avoid QAC Warning */
        }
      }
      /* Updating the denominator count with the least denominator */
      Dem_GaaIumprNumeratorCount[LucIumprGroupId] =
                                Dem_GaaIumprIntrlNumeratorCount[LusRatioIndex];
      Dem_GaaIumprDenominatorCount[LucIumprGroupId] =
                              Dem_GaaIumprIntrlDenominatorCount[LusRatioIndex];
      LflRatioValue = (float32)DEM_MAX_IUPMR_RATIO;
    }
  }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_ProcessClearPermanentMemory                     **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Used to clear Events stored in Permanent memory.    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LucOperationCycleIndex                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaAllEvtStatus,          **
**                                              Dem_GstPerEventMemory,        **
**                                              Dem_GaaAllDtcStatus,          **
**                        Function(s) invoked : None                          **
**                                                                            **
**  Design ID           : DEM_SDD_1550                                        **
**                                                                            **
*******************************************************************************/
#if ((DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > DEM_ZERO) && \
     (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_ProcessClearPermanentMemory(
  const uint8 LucOperationCycleIndex)
{
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
  uint16       LusDtcInfoIndex;
  #endif
  uint8_least  LucPerMemIndx;
  uint8        LucStatus;
  #if ((DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) && \
  (DEM_INVALID != DEM_PERMANENT_MEM_NVM_BLOCK_INDX))
  boolean      LblPerMemWrite;
  NvM_RequestResultType LddReqResult;
  Std_ReturnType LddReturnValue;
  LddReqResult =  NVM_REQ_NOT_OK;
  LblPerMemWrite  = DEM_FALSE;
  #endif
  /* Check wheter operation cycle is PFC cycle */
  if (DEM_OPCYC_OBDPFC_INDEX == LucOperationCycleIndex)
  {
    /* Erase permanent memory if conditions are satisfied */
    #if (DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > DEM_ONE)
    /* Loop thhoguh all the events stored in permanent memory */
    for (LucPerMemIndx = DEM_ZERO; LucPerMemIndx <
                          (uint8_least)DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT; LucPerMemIndx++)
    #else
    LucPerMemIndx = DEM_ZERO;
    #endif
    {
      #if ((DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) && \
                 (DEM_INVALID != DEM_PERMANENT_MEM_NVM_BLOCK_INDX))
      /* Check if Valid event id is stored in memory */
      if (DEM_ZERO != Dem_GstCpyPerEventMemory[LucPerMemIndx].ddEventId)
      #else
      if (DEM_ZERO != Dem_GstPerEventMemory[LucPerMemIndx].ddEventId) 
       #endif
      {
        /* To get the status of the event stored in permanent memory */
        #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONSTORAGE)
          /* polyspace +21 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        LucStatus = Dem_GaaAllEvtStatus
        #if ((DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) && \
                 (DEM_INVALID != DEM_PERMANENT_MEM_NVM_BLOCK_INDX))
                    [Dem_GstCpyPerEventMemory[LucPerMemIndx].ddEventId  - DEM_ONE];
                    #else
                   [Dem_GstPerEventMemory[LucPerMemIndx].ddEventId  - DEM_ONE];		    
                 #endif
        #else
        /* Default DTC Status 0x50 */
        LucStatus = DEM_SET_EVENTSTATUSBITS_FOUR_SIX;
    /* polyspace +12 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
        /* Get DTC Index for Event */
         #if ((DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) && \
                 (DEM_INVALID != DEM_PERMANENT_MEM_NVM_BLOCK_INDX))
        LusDtcInfoIndex = DEM_EVENT_MAPPED_DTC_INDEX
         (Dem_GstCpyPerEventMemory[LucPerMemIndx].ddEventId - DEM_ONE);		
         #else
           LusDtcInfoIndex = DEM_EVENT_MAPPED_DTC_INDEX
            (Dem_GstPerEventMemory[LucPerMemIndx].ddEventId - DEM_ONE);			
         #endif
		
        /* DTC is configured */
        if (DEM_INVALID_DTC_INDEX != LusDtcInfoIndex)
        {
      /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
          LucStatus = Dem_GaaAllDtcStatus[LusDtcInfoIndex]; // parasoft-suppress CERT_C-ARR30-a-2 CERT_C-ARR39-a-2 CERT_C-EXP08-b-2 CERT_C-FIO37-a-1 CERT_C-MSC19-a-3 CERT_C-STR31-a-1 MISRAC2012-DIR_4_1-a-2 MISRAC2012-RULE_18_1-a-2 "Refer: Dem_InternalFunc_c_REF_11"
        }
        #endif
        /*To check whether Clear DTC has been occured or not */
        /* Test failed since last clear bit check */
        if (DEM_ZERO == (LucStatus & DEM_EVENTSTATUS_BIT5_SET))
        {
          /*Check whether the event is Passed and Tested*/
          /* Bit 6 check not required, since there may be different operation
          cycle for processing of event other than driving cycle */
          if (DEM_ZERO == (LucStatus & DEM_EVENTSTATUS_BIT_PERMANENT))
          {
            #if ((DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) && \
                 (DEM_INVALID != DEM_PERMANENT_MEM_NVM_BLOCK_INDX))
            /* Erase the permanent memory */
            Dem_GstCpyPerEventMemory[LucPerMemIndx].ddEventId = DEM_ZERO;
            #else
             Dem_GstPerEventMemory[LucPerMemIndx].ddEventId = DEM_ZERO;
            #endif
            /* Reset Memory overFLow flag to False */
            /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
            Dem_GaaEventMemOvflw[DEM_TWO] = DEM_ZERO;
            #if ((DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) && \
            (DEM_INVALID != DEM_PERMANENT_MEM_NVM_BLOCK_INDX))
            LblPerMemWrite = DEM_TRUE;
            #endif
          }
        }
        else
        {
          /* check if Warning Indicator Bit is set */
          if ((DEM_ZERO == (LucStatus & DEM_EVENTSTATUS_BIT7_SET)) &&
              (DEM_ZERO == (LucStatus & DEM_EVENTSTATUS_BIT2_SET)))
          {
            #if ((DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) && \
                 (DEM_INVALID != DEM_PERMANENT_MEM_NVM_BLOCK_INDX))
            /* Erase the permanent memory */
            Dem_GstCpyPerEventMemory[LucPerMemIndx].ddEventId = DEM_ZERO;
            #else
              Dem_GstPerEventMemory[LucPerMemIndx].ddEventId = DEM_ZERO;
            #endif
            /* Reset Memory overFLow flag to False */
            /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
            Dem_GaaEventMemOvflw[DEM_TWO] = DEM_ZERO;
            #if ((DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) && \
            (DEM_INVALID != DEM_PERMANENT_MEM_NVM_BLOCK_INDX))
            LblPerMemWrite = DEM_TRUE;
            #endif
          }
        }
      } /* End of Event ID Check */
    } /* End of permanent memory loop */
  } /* End of operation cycle check */
  /* Permanent Memory block is configured */
  #if ((DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) &&\
       (DEM_INVALID != DEM_PERMANENT_MEM_NVM_BLOCK_INDX))
  if (LblPerMemWrite)
  {
	LddReturnValue = NvM_GetErrorStatus(Dem_GaaNVBlocks
    [DEM_PERMANENT_MEM_NVM_BLOCK_INDX].usBlockID, &LddReqResult);
			  
	if ((LddReturnValue == E_NOT_OK) || (LddReqResult == NVM_REQ_PENDING))
	{
	 Dem_GblPerEvtMemNotWritten = DEM_TRUE;  
	}
	else
	{
	/* Store Event from Dem_GstCpyPerEventMemory to Permanent Memory */	
	(void) DEM_MEMCPY(Dem_GstPerEventMemory, Dem_GstCpyPerEventMemory, DEM_TWO * DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT);	 // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14" // parasoft-suppress CERT_C-POS54-a-1 MISRAC2012-RULE_18_4-a-4 CERT_C-DCL39-a-3 CERT_C-DCL39-a-3 CERT_C-MEM04-a-2 CERT_C-MEM07-a-2 "Reason: Dem_InternalFunc_c_REF_14 Dem_InternalFunc_c_REF_17 Dem_InternalFunc_c_REF_18 Dem_InternalFunc_c_REF_25"
    (void)NvM_WriteBlock
      (Dem_GaaNVBlocks[DEM_PERMANENT_MEM_NVM_BLOCK_INDX].usBlockID,
        &Dem_GstPerEventMemory);
    Dem_GblPerEvtMemNotWritten = DEM_FALSE;
	}
  }
  #endif
} /* End of Dem_ProcessClearPermanentMemory */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_GetEDRecordEx                                   **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Gets the data of an extended data record by event.  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventId,RecordNumber,LucEntriesInMemory             **
**                                                                            **
** InOut parameter      : DestBuffer                                          **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_ED_RECDS should be greater than   **
**                        Zero                                                **
** Remarks              : Global Variable(s) :Dem_GaaEventParameter,          **
**                                            Dem_GaaEDRecord                 **
**                        Function(s) invoked : Det_ReportError               **
**                                              Dem_CheckExtendedDataRecord   **
**  Design ID           : DEM_SDD_1795                                        **
*******************************************************************************/
#if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
    (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType  Dem_GetEDRecordEx(
   const Dem_EventIdType EventId, const uint8 RecordNumber, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   uint8 *DestBuffer, uint16* BufSize) // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
{
  const Dem_EventMemory*     LpEventMemory;
  const Dem_DTCAttributeType*  LpDTCAttribute;
  Std_ReturnType                                      LddReturnValue;
  Dem_DTCOriginType                                   LucEventDestination;
  uint16                               LusEventParameterIndex;
  uint16                               LusSize;
  uint8                                LucFreeIndex;
  uint8                                LucNumOfEDRecords;
  uint8                                LucRecIndex;
  uint8                                LucActualRecordIndex;
  boolean                              LblRecFound;
  boolean                              LblValidRec;

  /* Initialize return to E_OK */
  LddReturnValue = E_OK;
  /* Initialize Record Index Found to DEM_FALSE  */
  LblRecFound = DEM_FALSE;
  /* Initialize Valid Record to DEM_FALSE  */
  LblValidRec = DEM_FALSE;
  /* Initialize Event Parameter Index */
  LusEventParameterIndex = EventId - (uint16)DEM_ONE;
  /* polyspace +4 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Get number of destination for current Event */
  /* Initialize local pointer to index of DTC attribute */
  LpDTCAttribute = Dem_GaaEventParameter[LusEventParameterIndex].
                                                        pDTCAttribute;
  if (NULL_PTR != LpDTCAttribute)
  {
    /* Get memory Location for the event */
    LucFreeIndex = Dem_GaaMemoryIndexForEvt[LusEventParameterIndex];
    /* Check if event is stored in memory */
    if (DEM_INVALID_MEMORY_INDEX != LucFreeIndex)
    {
      /* Event Destination */
      LucEventDestination = LpDTCAttribute->ucEventDestination;
      /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      /* Pointer to Event Memeory */
      LpEventMemory =  Dem_GaaDTCOriginBasedPtrAddress[
                 Dem_GaaDTCOriginMappingIndx[LucEventDestination]].pEventMemory;
      /* Get Size of Extended Data Record */
      LusSize = DEM_ZERO;
      Dem_GetSizeOfEDRecordForEvent(LucFreeIndex, &LusSize,
                                                   RecordNumber, LpEventMemory);
      if (*BufSize < LusSize)
      {
        #if (DEM_DEV_ERROR_DETECT == STD_ON)
        /* Error report to DET */
        (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
         DEM_GETEVENTEXTENDEDDATARECORDEX_SID , DEM_E_PARAM_LENGTH);
         #endif
        /* Return  wrong buffer size */
        LddReturnValue = DEM_BUFFER_TOO_SMALL;
      }
      else
      {
         /* Initialize LucNumOfEDRecords to total Event Records */
         LucNumOfEDRecords = LpDTCAttribute->ucNumOfEDRecords;
         LddReturnValue = Dem_CheckExtendedDataRecord(RecordNumber,
         DEM_GETEVENTEXTENDEDDATARECORDEX_SID , DestBuffer, BufSize,
         LpEventMemory, LpDTCAttribute,
         #if (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)
         LusEventParameterIndex,
         #endif
         LucFreeIndex, LucNumOfEDRecords, &LblRecFound
         #if (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO)
         , LucEventDestination
         #endif
         );
        if (!LblRecFound)
        {
        #if (DEM_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
        DEM_GETEVENTEXTENDEDDATARECORDEX_SID, DEM_E_PARAM_DATA);
        #endif
        LddReturnValue = DEM_NO_SUCH_ELEMENT;
        }
      }
    }/* End of if (event doesn't exist in memory) */
    else /* if event doesn't exist memory*/
    {
      /* Initialize LucNumOfEDRecords to total Event Records */
      LucNumOfEDRecords = LpDTCAttribute->ucNumOfEDRecords;
      /* Check if record is valid  */
      for (LucRecIndex = DEM_ZERO ; ((LucRecIndex < LucNumOfEDRecords) &&
      (!LblValidRec)); LucRecIndex++)
      {
      /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        /* Get the Actual record index */
        LucActualRecordIndex = LpDTCAttribute->
                                    aaExtendedDataRecords[LucRecIndex];
      /* polyspace +4 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
        /* Check if record is valid(configured) */
        if (Dem_GaaEDRecord
        [LucActualRecordIndex].
                           ucExtendedDataRecordNumber == RecordNumber)
        {
          LblValidRec = DEM_TRUE;
          (void)Det_ReportRuntimeError(DEM_MODULE_ID, DEM_INSTANCE_ID,
          DEM_GETEVENTEXTENDEDDATARECORDEX_SID, DEM_E_NODATAAVAILABLE);

          /* valid record number but data is not available */
          /* Failure of Trigger */
          LddReturnValue = DEM_NO_SUCH_ELEMENT;
        }
      }
      /* Check if valid record is found */
      if (!LblValidRec)
      {
        LddReturnValue = DEM_NO_SUCH_ELEMENT;
      }
    } /* End of if event doesn't exist memory*/
  }
  return(LddReturnValue);
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_GetSizeOfEDRecordForEvent                       **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : API to get the Extended Data record size for Eevnt  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : LusEventParameterIndex,RecordNumber, LpEventMemory  **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpBufSize                                           **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
** Remarks              : Global Variable(s)     : Dem_GaaEventParameter,     **
**                                                 Dem_GaaEDRecord            **
**                        Function(s) invoked    : None                       **
**                                                                            **
** Design ID            : DEM_SDD_1796                                        **
*******************************************************************************/
#if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
    (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static void  Dem_GetSizeOfEDRecordForEvent(
   const uint8 LucFreeIndex, uint16* const LpBufSize, const uint8 ExtendedDataNumber, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
   const Dem_EventMemory*  LpEventMemory) // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
{
  const Dem_DTCAttributeType*  LpDTCAttribute;
  uint16                               LusEvtParamIndex;
  uint16                               LusSize;
  uint8                                LucActualRecordIndex;
  uint8                                LucNumOfEDRec;
  uint8                                LucRecCnt;
  /* Initialise Buffer Size to ZERO */
  LusSize = DEM_ZERO;
  /* Get Event Paramter Index */
  /* polyspace +4 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  LusEvtParamIndex = LpEventMemory[LucFreeIndex].ddEventId - (uint16)DEM_ONE;
  /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Get DTC Attribute for the event */
  LpDTCAttribute = Dem_GaaEventParameter[LusEvtParamIndex].pDTCAttribute;
  /* polyspace +2 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
  /* Get the number of Records configured for the event */
  LucNumOfEDRec = LpDTCAttribute->ucNumOfEDRecords;
  /* Loop for all records */
  for (LucRecCnt = DEM_ZERO; LucRecCnt < LucNumOfEDRec; LucRecCnt++)
  {
    /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    LucActualRecordIndex = LpDTCAttribute->aaExtendedDataRecords[LucRecCnt];
    /* Check if the requested ED record is stored in memory */
    if (LpEventMemory[LucFreeIndex].aaEdData[LucRecCnt]
       [DEM_ZERO] == ExtendedDataNumber)
    {
    /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      if (ExtendedDataNumber ==
               Dem_GaaEDRecord[LucActualRecordIndex].ucExtendedDataRecordNumber)
      {
        LusSize = Dem_GaaEDRecord[LucActualRecordIndex].usEDRecordRawDataSize;
        #if (DEM_MAX_MONITOR_ED_EXT_RECDS_PER_EVENT > DEM_ZERO)
         /* PRQA S 3383 1 */
        LusSize += Dem_GaaEDRecord[LucActualRecordIndex].usEDMonitorRawDataSize;
        #endif
      }
      /* Update buffer size needed */
      (*LpBufSize) = (*LpBufSize) + LusSize; // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_19"
    }
    else
    /* If record configured is of InternalDataElementType */
    {
    /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      if ((Dem_GaaEDRecord[LpDTCAttribute->aaExtendedDataRecords[LucRecCnt]]. // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_19"
         ucExtendedDataRecordNumber == ExtendedDataNumber) && // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_19"
         ((LpEventMemory[LucFreeIndex]).aaEdData[LucRecCnt] // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_19"
           [DEM_ONE] == DEM_REC_INTDATAELMT_TRIG_SAT)) // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_19"
      {
        /* Update buffer size */
        (*LpBufSize) = (*LpBufSize) + Dem_GaaEDRecord // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_19"
                      [LpDTCAttribute->aaExtendedDataRecords[LucRecCnt]]. // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_19"
                                                           ucNumOfDataElements; // parasoft-suppress CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_InternalFunc_c_REF_19"
      }
    }
  } /* End of Loop for all Ed Records */
} /* End Of Dem_GetSizeOfEDRecordForEvent */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_SearchRecInMem                                  **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : API to search for records in memory                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : RecordNumber,DataId,LucMemoryIndex,LpEventMemory    **
**                        LpDTCAttribute                                      **
**                                                                            **
** InOut parameter      : LblRecordFound, BufSize                             **
**                                                                            **
** Output Parameters    : DestBuffer                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : Dem_GetDidData,            **
**                                                 Det_ReportError            **
**                                                                            **
** Design ID            : DEM_SDD_1797                                        **
*******************************************************************************/
#if (DEM_MAX_NUMBER_OF_FF_RECDS > DEM_ZERO)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType  Dem_SearchRecInMem(const uint8 RecordNumber,
    const uint8 LucFreeIndex, boolean* const LblRecordFound, const uint16 DataId, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
    const Dem_EventMemory*  LpEventMemory, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
    /* #violates #ref Dem_InternalFunc_c_REF_QAC_2 Violates MISRA 2012 Required
     Rule 8.13 */
    /* PRQA S 3673 1 */
    uint8* LpDestBuffer, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
    const Dem_DTCAttributeType* const LpDTCAttribute, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
    /* #violates #ref Dem_InternalFunc_c_REF_QAC_2 Violates MISRA 2012 Required
     Rule 8.13 */
    /* PRQA S 3673 1 */
    uint16*  BufSize) // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
{
  Std_ReturnType LddReturnValue;
  #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
  uint8          LucLatestRecIndex;
  #endif
  #if (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)
  uint8          LucRecordCount;
  #endif
  uint8          LucMemIndx;
  uint8          LucCmpRecord;
  LddReturnValue = E_OK;
  /* check if Application requested for latest record */
  if (RecordNumber == DEM_MAX_RECORD)
  {
  /* polyspace +6 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* Check at least one ff is recorded */
    /* Polyspace InternalFunc_c_Ref_180 */


    if ((LpEventMemory + LucFreeIndex)->ucNumOfFF > DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
    {
      #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
      /* Get Latest record index in memory */
      /* Polyspace InternalFunc_c_Ref_196 */
      LucLatestRecIndex =
          (LpEventMemory + LucFreeIndex)->ucNumOfFF - DEM_ONE; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
      LddReturnValue = Dem_GetFFDidData(LpEventMemory, LpDestBuffer,
      LucFreeIndex, DataId, LucLatestRecIndex, BufSize);
      if (E_NOT_OK == LddReturnValue)
      {
        LddReturnValue = DEM_NO_SUCH_ELEMENT;
      }
      #else
      LddReturnValue = DEM_NO_SUCH_ELEMENT;
      #endif
    }
    else
    {
      /* No records are stored Yet  */
      LddReturnValue = DEM_NO_SUCH_ELEMENT;
    }
  }
  /* if record requested is selective  */
  else
  {
    Dem_DtcAttrSearchInMemory(LpDTCAttribute, &LucMemIndx);
    if (Dem_GaaDTCOriginBasedPtrAddress[LucMemIndx].ucFfRecordEnumType == 
       DEM_FF_RECNUM_CONFIGURED)
    {
      LucCmpRecord = LpDTCAttribute->ucNumOfFFRecNum;
    }
    else
    {
      LucCmpRecord = LpDTCAttribute->ucMaxNumOfFFRecord;
    }
    /* Search in stored records for requested Record no */
    for (LucRecordCount = DEM_ZERO; ((LucRecordCount <
      LucCmpRecord) &&
      (!(*LblRecordFound))); LucRecordCount++)
    {
    /* polyspace +8 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* polyspace +5 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
      /* Polyspace InternalFunc_c_Ref_196 */


      if (RecordNumber == (LpEventMemory + LucFreeIndex)-> // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
      /* Polyspace InternalFunc_c_Ref_137 */
        aaFFRecNumAndData[LucRecordCount][DEM_ZERO])
      {
        *LblRecordFound = DEM_TRUE;
        #if (DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO)
        LddReturnValue = Dem_GetFFDidData(LpEventMemory, LpDestBuffer,
        LucFreeIndex, DataId, LucRecordCount, BufSize);
        if (LddReturnValue == E_NOT_OK)
        {
          LddReturnValue = DEM_NO_SUCH_ELEMENT;
        }
        #else  /* start of #if(DEM_MAX_NUM_OF_DID_PER_FF < DEM_ZERO) */
        LddReturnValue = DEM_NO_SUCH_ELEMENT;
        #endif /* End of #if(DEM_MAX_NUM_OF_DID_PER_FF > DEM_ZERO) */
      }
    }
  } /* End of Requested Rec number*/

  #if (DEM_MAX_NUM_OF_DID_PER_FF == DEM_ZERO)
   /* #violates #ref Dem_InternalFunc_c_REF_QAC_8 Violates MISRA 2012 Required
     Rule 2.2 */
  /* PRQA S 3112 3 */
  DEM_UNUSED(DataId);
  DEM_UNUSED(BufSize);
  DEM_UNUSED(LpDestBuffer);
  #endif

  return(LddReturnValue);
} /* End Of Dem_SearchRecInMem */
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_ConsistencyChecks                               **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Function to verfy data consistency in Dem variables **
**                        after NVM read                                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Dem_GstPerEventMemory      **
**                                             Dem_GaaDTCOriginBasedPtrAddress**
**                        Function(s) invoked    :                            **
**                                      Dem_ConsistencyChecksForValidNodeIndex**
**                                                                            **
** Design ID            : DEM_SDD_2107                                        **
*******************************************************************************/
#if ((DEM_NVM_PRESENT == STD_ON) && \
     (DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) && \
     (DEM_ZERO < DEM_NUMBER_OF_DESTINAIONS_CONFIGURED))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static Std_ReturnType  Dem_ConsistencyChecks(void)
{
   
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_16 Violates MISRA 2012
  Required Rule 8.13 */
  /* PRQA S 3678 1 */
  Dem_EventMemory*  LpEventMemory;
  Std_ReturnType              LddReturnValue;
  Dem_EventIdType             LddEventIdInMem;
  #if (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)
  boolean LaaHeadNodeFoundStatusFlag[DEM_MAX_NUMBER_EVENT_ENTRY];
  boolean LaaTailNodeFoundStatusFlag[DEM_MAX_NUMBER_EVENT_ENTRY];
  #endif
  #if (DEM_ONE < DEM_NUMBER_OF_DESTINAIONS_CONFIGURED)
  uint8   LucEventMemIndex;
  #else
  const uint8   LucEventMemIndex = DEM_ZERO;
  #endif
  uint8   LucMemEntries;

  #if (DEM_ONE < DEM_NUMBER_OF_DESTINAIONS_CONFIGURED)
  /* Initialize Return Value */
  LddReturnValue = E_OK;
  /* Fetch the number of destinations configured */
  LucEventMemIndex = DEM_NUMBER_OF_DESTINAIONS_CONFIGURED;
  /* Loop for all the event memories */
  while ((DEM_ZERO < LucEventMemIndex) && (E_OK == LddReturnValue))
  #endif
  {
    #if (DEM_ONE < DEM_NUMBER_OF_DESTINAIONS_CONFIGURED)
    /* Decrement to point to next iteration */
    --LucEventMemIndex;
    #endif
      /* Fetch the number of event memory entries */
      LucMemEntries =
            Dem_GaaDTCOriginBasedPtrAddress[LucEventMemIndex].ucEntriesInMemory;
      /* Fetch the event memory */
      LpEventMemory =
                Dem_GaaDTCOriginBasedPtrAddress[LucEventMemIndex].pEventMemory;
      #if (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)
			#if ((DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW != STD_ON) && \
			     (DEM_OBD_SUPPORT == DEM_OBD_NO_OBD_SUPPORT))
				 LddReturnValue = E_OK;
      if (Dem_GaaDTCOriginBasedPtrAddress[LucEventMemIndex].ucEventDisplacement !=
                   DEM_DISPLACEMENT_NONE)
		 #endif
			{
			
        /* Set node found flag to False */
        (void) DEM_MEMSET(&LaaHeadNodeFoundStatusFlag, // parasoft-suppress CERT_C-POS54-a-1 "Reason: Dem_InternalFunc_c_REF_14" 
                               (sint16)DEM_ZERO, (uint32)LucMemEntries);   // parasoft-suppress CERT_C-INT02-a-2 "Refer: Dem_InternalFunc_c_REF_27"
  
        (void) DEM_MEMSET(&LaaTailNodeFoundStatusFlag,  // parasoft-suppress CERT_C-POS54-a-1 "Reason: Dem_InternalFunc_c_REF_14"
                               (sint16)DEM_ZERO, (uint32)LucMemEntries);   // parasoft-suppress CERT_C-INT02-a-2 "Refer: Dem_InternalFunc_c_REF_27"
  
        /* Get valid node index in Linked List for data consitency
           of Event memory */
        LddReturnValue = Dem_ConsistencyChecksForValidNodeIndex(
                         LaaHeadNodeFoundStatusFlag, LaaTailNodeFoundStatusFlag,
                         LpEventMemory, LucMemEntries, LucEventMemIndex);
      }
      #else
      /* Initialize Return Value */
      LddReturnValue = E_OK;
      #endif

      /* Loop through all the entries of the event memory */
      while ((DEM_ZERO < LucMemEntries) && (LddReturnValue == E_OK))
      {
        /* Decrement to point to next iteration */
        --LucMemEntries;
        /* Fetch the stored event Id */
        /* #violates #ref Dem_EvtProcsg_c_REF_QAC_10 Violates MISRA 2012
           Required Rule REFERENCE - ISO:C90 */
        /* PRQA S 0491 1 */
        LddEventIdInMem = LpEventMemory[LucMemEntries].ddEventId;
        /* Check for valid Event id */
        if (DEM_ZERO != LddEventIdInMem)
        {
          /* Event ID is out of range */
          if (DEM_NUMBER_OF_EVENTS < LddEventIdInMem)
          {
            /* Retuen E_NOT_OK to reset Complete Data */
            LddReturnValue = E_NOT_OK;
          }
          else
          {
            #if (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)
			      #if ((DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW != STD_ON) && \
			         (DEM_OBD_SUPPORT == DEM_OBD_NO_OBD_SUPPORT))
            if (Dem_GaaDTCOriginBasedPtrAddress[LucEventMemIndex].ucEventDisplacement !=
                   DEM_DISPLACEMENT_NONE)
		        #endif
			      {
			      
                
              /* polyspace +3 RTE:NIVL [Justified:Low] "Refer Dem_c_Poly_REF_5" */
              /* Check if current event is present in linked list */
              if ((!LaaHeadNodeFoundStatusFlag[LucMemEntries]) ||
                  (!LaaTailNodeFoundStatusFlag[LucMemEntries]))
              {
                LddReturnValue = E_NOT_OK;
              }
            }
			      #endif
            if (Dem_GaaDTCOriginBasedPtrAddress[LucEventMemIndex].ucEventEntryStorageTrigr != 
                                        DEM_TRIGGER_ON_FDC_THRESHOLD)
            {
             
              /* Check for Event status with default value */
              if ((DEM_SET_EVENTSTATUSBITS_FOUR_SIX ==
                                Dem_GaaAllEvtStatus[LddEventIdInMem - DEM_ONE]) &&
                  (LddReturnValue == E_OK))
              {
			          #if  (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)
				
                #if ((DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW != STD_ON) && \
			           (DEM_OBD_SUPPORT == DEM_OBD_NO_OBD_SUPPORT))
                if (Dem_GaaDTCOriginBasedPtrAddress[LucEventMemIndex].ucEventDisplacement !=
                   DEM_DISPLACEMENT_NONE)
		           #endif
			          {
			          
                
                    
                  /* Invoke Dem_RearrangeOldEvtsInd to rearrange older events */
                  Dem_RearrangeOldEvtsInd(
                                   LucMemEntries, LucMemEntries, LpEventMemory);
                }
				        #endif
                /* Clear the event entry */
                *(LpEventMemory + LucMemEntries) = Dem_GstDefaultEventMemory; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
              }
              else
              {
                /* Do nothing */
              }
            }
          
          } /* End of valid Event ID Check */
        } /*End of if(DEM_ZERO != LusEventId) */
      } /* End of while(DEM_ZERO < LucMemEntries) */
  } /* End of loop of number of destinations */

  #if ((DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > DEM_ZERO) && \
       (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT))
  #if (DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > DEM_ONE)
  LucMemEntries = DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT;
  /* Loop for entries in permanent memory */
  while ((DEM_ZERO < LucMemEntries) && (LddReturnValue == E_OK))
  #else
  LucMemEntries = DEM_ZERO;
  #endif
  {
    #if (DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > DEM_ONE)
    /* Decrement to point to next iteration */
    --LucMemEntries;
    #endif
    /* Check if event Id in permanent memory is out of range */
    if (DEM_NUMBER_OF_EVENTS < Dem_GstPerEventMemory[LucMemEntries].ddEventId)
    {
      /* Return E_NOT_OK */
      LddReturnValue = E_NOT_OK;
    }
  }
  #endif
  /* Return Value */
  return LddReturnValue;
} /* End of Function Dem_ConsistencyChecks*/
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_ConsistencyChecksForValidNodeIndex              **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Function to get valid node index in Linked List for **
**                        data consitency of Event memory                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : RecordNumber,DataId,LucMemoryIndex,LpEventMemory    **
**                        LpDTCAttribute                                      **
**                                                                            **
** InOut parameter      : LblRecordFound, BufSize                             **
**                                                                            **
** Output Parameters    : DestBuffer                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : Dem_GetDidData,            **
**                                                 Det_ReportError            **
**                                                                            **
** Design ID            : DEM_SDD_2034                                        **
*******************************************************************************/
#if ((DEM_NVM_PRESENT == STD_ON) && \
     (DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) && \
     (DEM_ZERO < DEM_NUMBER_OF_DESTINAIONS_CONFIGURED) && \
     (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)) 
      
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static Std_ReturnType  Dem_ConsistencyChecksForValidNodeIndex(
  boolean* const LpHeadNodeFoundStatusFlag,
  boolean* const LpTailNodeFoundStatusFlag,
  const Dem_EventMemory*  LpEventMemory, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
  const uint8 LucMemEntries, const uint8 LucEventMemIndex // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  )
{
  Dem_EventIdType  LddEventIdInMem;
  Std_ReturnType   LddReturnValue;
  uint8            LucHeadNodeIndx;
  uint8            LucTailNodeIndx;

  /* Initialize Return Value */
  LddReturnValue = E_OK;
  /* Get head node index value */
  LucHeadNodeIndx =
                  Dem_GaaOldEvtCntHeadTailIndex[LucEventMemIndex][DEM_ZERO];
  /* Check if head node is present */
  if (DEM_INVALID != LucHeadNodeIndx)
  {
    /* Head node value is greater than size of event memory */
    if (LucMemEntries <= LucHeadNodeIndx)
    {
      /* Head node index is out of range */
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      /* Traverse from head to tail node index */
      do
      {
      /* polyspace +6 RTE:NIV [Justified:Low] "Refer Dem_c_Poly_REF_8" */
      /* polyspace +5 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
        /* Check if node is repeated */
        /* #violates #ref Dem_EvtProcsg_c_REF_QAC_10 Violates MISRA 2012
           Required Rule REFERENCE - ISO:C90 */
        /* PRQA S 0491 1 */
        if (LpHeadNodeFoundStatusFlag[LucHeadNodeIndx])
        {
          /* Node is repeated */
          LddReturnValue = E_NOT_OK;
        }
        else
        {
          /* Set node found Flag TRUE */
          /* #violates #ref Dem_EvtProcsg_c_REF_QAC_10 Violates MISRA 2012
             Required Rule REFERENCE - ISO:C90 */
          /* PRQA S 0491 1 */
          LpHeadNodeFoundStatusFlag[LucHeadNodeIndx] = DEM_TRUE;
      /* polyspace +5 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
          /* Get event Id Value */


          LddEventIdInMem = (LpEventMemory + LucHeadNodeIndx)->ddEventId; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
          /* Check for valid Event id */
          if ((DEM_ZERO == LddEventIdInMem) ||
              (DEM_NUMBER_OF_EVENTS < LddEventIdInMem))
          {
            /* Event ID is invalid or out of range */
            LddReturnValue = E_NOT_OK;
          }
          else
          {
            /* Get next node index value */
            LucHeadNodeIndx =
                      (LpEventMemory + LucHeadNodeIndx)->ucNextEventIdIndex; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
          }
        } /* End of repeated node check */
      } while ((DEM_INVALID != LucHeadNodeIndx) &&
               (E_OK == LddReturnValue));
    } /* End of if(LucMemEntries <= LucHeadNodeIndx) */
  } /* End of if (DEM_INVALID != LucHeadNodeIndx) */

  /* Get tail node index value */
  LucTailNodeIndx =
                   Dem_GaaOldEvtCntHeadTailIndex[LucEventMemIndex][DEM_ONE];
  /* Check if tail node is present */
  if ((E_OK == LddReturnValue) && (DEM_INVALID != LucTailNodeIndx))
  {
    /* Tail node value is greater than size of event memory */
    if (LucMemEntries <= LucTailNodeIndx)
    {
      /* Tail node index is out of range */
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      /* Traverse from tail to head node index */
      do
      {
      /* polyspace +6 RTE:NIV [Justified:Low] "Refer Dem_c_Poly_REF_8" */
      /* polyspace +5 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
        /* Check if node is repeated */
        /* #violates #ref Dem_EvtProcsg_c_REF_QAC_10 Violates MISRA 2012
           Required Rule REFERENCE - ISO:C90 */
        /* PRQA S 0491 1 */
        if (LpTailNodeFoundStatusFlag[LucTailNodeIndx])
        {
          /* Node is repeated */
          LddReturnValue = E_NOT_OK;
        }
        else
        {
          /* Set node found Flag TRUE */
          /* #violates #ref Dem_EvtProcsg_c_REF_QAC_10 Violates MISRA 2012
             Required Rule REFERENCE - ISO:C90 */
          /* PRQA S 0491 1 */
          LpTailNodeFoundStatusFlag[LucTailNodeIndx] = DEM_TRUE;
      /* polyspace +5 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
          /* Get event Id Value */
          LddEventIdInMem = (LpEventMemory + LucTailNodeIndx)->ddEventId; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
          /* Check for valid Event id */
          if ((DEM_ZERO == LddEventIdInMem) ||
              (DEM_NUMBER_OF_EVENTS < LddEventIdInMem))
          {
            /* Event ID is invalid or out of range */
            LddReturnValue = E_NOT_OK;
          }
          else
          {
            /* Get previous node index value */
            LucTailNodeIndx =
                         (LpEventMemory + LucTailNodeIndx)->ucPreviousIndex; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_17"
          }
        } /* End of repeated node check */
      } while ((DEM_INVALID != LucTailNodeIndx) &&
               (E_OK == LddReturnValue));
    }
  }
  /* Return Value */
  return LddReturnValue;
} /* End of Function Dem_ConsistencyChecksForValidNodeIndex*/
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_EventSearchInMemory                             **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Description          : Check DTC memory entry index                        **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventParameterIndex                                 **
**                        PMemMapIndx                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :  None                         **
**                        Function(s) invoked :  None                         **
**  Design ID           : DEM_SDD_5119                                        **
**                                                                            **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_EventSearchInMemory(const Dem_EventIdType EventParameterIndex,  // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
uint8*  const  PMemMapIndx) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  #if (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)
  const Dem_DTCAttributeType*  LpDTCAttribute;
  Dem_DTCOriginType                    LddDTCOrigin;
  
  /* polyspace +20 RTE:OBAI [Justified:Low] "Refer Dem_h_Poly_REF_1" */
  
  /* Initialize variable pointer to null */
  LpDTCAttribute = Dem_GaaEventParameter[EventParameterIndex].pDTCAttribute;
  if (NULL_PTR != LpDTCAttribute)  
  {    
  /* Event Destination */
  LddDTCOrigin = LpDTCAttribute->ucEventDestination;
  /* Get Memory mapping index */
  *PMemMapIndx = Dem_GaaDTCOriginMappingIndx[LddDTCOrigin];
  }
  else
  {
    *PMemMapIndx = DEM_ZERO;
  }  
  #else
  DEM_UNUSED(EventParameterIndex);
  *PMemMapIndx = DEM_ZERO;
  #endif

  /* Check if event is stored in memory */
} /* End of Dem_EventSearchInMirrorMemory */
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"

/*******************************************************************************
** Function Name        : Dem_DtcAttrSearchInMemory                           **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Description          : Check DTC memory entry index                        **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventParameterIndex                                 **
**                        PMemMapIndx                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :  None                         **
**                        Function(s) invoked :  None                         **
**  Design ID           : DEM_SDD_5120                                        **
**                                                                            **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_DtcAttrSearchInMemory(
const Dem_DTCAttributeType*  const LpDTCAttribute,  uint8* const PMemMapIndx) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  #if (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)
  Dem_DTCOriginType                    LddDTCOrigin;

 if (NULL_PTR  != LpDTCAttribute)
 {
  /* polyspace +5 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* Event Destination */
  LddDTCOrigin = LpDTCAttribute->ucEventDestination;
  /* Get Memory mapping index */
  *PMemMapIndx = Dem_GaaDTCOriginMappingIndx[LddDTCOrigin];
 }
 else 
 {
   DEM_UNUSED(LpDTCAttribute);
  *PMemMapIndx = DEM_ZERO;
 }  
  #else
  DEM_UNUSED(LpDTCAttribute);
  *PMemMapIndx = DEM_ZERO;
  #endif
  /* Check if event is stored in memory */
} /* End of Dem_EventSearchInMirrorMemory */
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"


/*******************************************************************************
** Function Name        : Dem_Offline_Cal_DTCSuppressionStatus                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This API shall be used to update the each DTC's     **
**                        Supression status based on Event availability when  **
**                        offline calibration support is available.           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaSuppressionStatus      **
** Design ID            : DEM_SDD_1907                                        **
*******************************************************************************/

/* Redmine 55836 Start*/
#if ((DEM_OFFLINE_CALIBRATION_FEATURE_SUPPORT == STD_ON) && \
    (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_Offline_Cal_DTCSuppressionStatus(void)
{
  uint16                    LusDtcInfoIndex;
  uint16                    LusEventIndex;
  #if (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
  uint16                    LusEvtCount;
  boolean                   LblEventStatus;
  uint16                    LusNoOfCombinedEvents;
  #endif

  #if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
  for (LusDtcInfoIndex = DEM_ZERO;
        (LusDtcInfoIndex < DEM_MAX_NUMBER_OF_DTC);LusDtcInfoIndex++)
  {
    #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_DISABLED)

/* polyspace +11 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    LusEventIndex = DEM_DTC_EVENT_INDEX(LusDtcInfoIndex);

    /* Check if requested EventId is available */
    if (DEM_ZERO ==  (Dem_GaaEvtPreConditions[LusEventIndex] &
                         DEM_PRECOND_EVENT_NOT_AVAILABLE_BIT_VALUE))
    {
      /* Set DTC Suppression Status to FALSE */
      Dem_GaaSuppressionStatus[LusDtcInfoIndex] = DEM_FALSE;
    }
    else
    {
      /* Set DTC Suppression Status to FALSE */
      Dem_GaaSuppressionStatus[LusDtcInfoIndex] = DEM_TRUE;
    }
    #else

 /* polyspace +23 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    LusNoOfCombinedEvents = DEM_DTC_NUMBER_OF_EVENTS(LusDtcInfoIndex);
    LblEventStatus = DEM_FALSE;
    /* Loop for number of events */
    for (LusEvtCount = DEM_ZERO;
             LusEvtCount < LusNoOfCombinedEvents; LusEvtCount++)
    {
      /* Event Index */


      LusEventIndex = DEM_DTC_COMBINED_EVENTS(LusDtcInfoIndex, LusEvtCount);
      /* Check if requested EventId is available */
      if (DEM_ZERO ==  (Dem_GaaEvtPreConditions[LusEventIndex] &
                      DEM_PRECOND_EVENT_NOT_AVAILABLE_BIT_VALUE))
      {
         LblEventStatus = DEM_TRUE;
         /* Break the loop if any of event is available */
         break;
      }
    }
    if (!LblEventStatus)
    {
      Dem_GaaSuppressionStatus[LusDtcInfoIndex] = DEM_TRUE;
    }
    else
    {
      Dem_GaaSuppressionStatus[LusDtcInfoIndex] = DEM_FALSE;
    }
    #endif
  }
  #endif
} /* End Of Dem_Offline_Cal_DTCSuppressionStatus */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/* Redmine 55836 End*/



/*******************************************************************************
** Function Name        : Dem_Offline_Cal_EvtAvailibility                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This API shall be used to update the each Event's   **
**                        Availibility in Event's precondition when offline   **
**                        calibration support is available.                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaEvtPreConditions       **
** Design ID            : DEM_SDD_1908,DEM_SDD_1911              **
*******************************************************************************/

/* Redmine 55836 Start*/
#if ((DEM_OFFLINE_CALIBRATION_FEATURE_SUPPORT == STD_ON) && \
    (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_Offline_Cal_EvtAvailibility
#if (DEM_PRE_COMPILE_SINGLE == STD_ON)
(void)
#else
(const boolean* const LpCalEventAvailability) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
#endif
{
   uint16                               LusEvtIndex;
   boolean                              LblEventAvailable;

  /* Initialize to number of event configured */
     LusEvtIndex = DEM_NUMBER_OF_EVENTS;
  while (DEM_ZERO < LusEvtIndex)
  {
    /* Decrement Event Index */
    --LusEvtIndex;
    #if (DEM_PRE_COMPILE_SINGLE == STD_ON)
    LblEventAvailable = Dem_GaaAllCalEventAvailability[LusEvtIndex];
    #else


    LblEventAvailable = (boolean)(*(LpCalEventAvailability + LusEvtIndex));
    #endif

    if (LblEventAvailable)
    {
      /* Set event availability status to event available */
      Dem_GaaEvtPreConditions[LusEvtIndex] =
                     Dem_GaaEvtPreConditions[LusEvtIndex] &
                                       DEM_PRECOND_EVENT_AVAILABLE_BIT_VALUE;
    }
    else
    {
      /* Set event availability status to event not available */
       Dem_GaaEvtPreConditions[LusEvtIndex] =
                    Dem_GaaEvtPreConditions[LusEvtIndex] |
                                 DEM_PRECOND_EVENT_NOT_AVAILABLE_BIT_VALUE;
    }
  }
} /* End Of Dem_Offline_Cal_EvtAvailibility */

/* Redmine 55836 End*/
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_CheckPassiveEventCount                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This API shall be used to Check Passive Event Count **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaEventParameter         **
** Design ID            : DEM_SDD_1438                                       **
*******************************************************************************/

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void Dem_CheckPassiveEventCount(
/* #violates #ref Dem_InternalFunc_c_REF_QAC_2 Violates MISRA 2012 Required
     Rule 8.13 */
    /* PRQA S 3673 2 */
const uint8*  const LucNoOfPassEvt,  // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
 const uint8* LucNoOfTestNotCmpltEvt,  // parasoft-suppress CERT_C-API00-a-3 MISRAC2012-RULE_17_8-a-4 MISRAC2012-RULE_8_13-a-4 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_20 Dem_InternalFunc_c_REF_21"
 const uint16 LusLpriDTC,
 uint16* LaaPassEvtId, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
  STD_TYPES_CONST uint16  LaaPassEvtPriDTC[DEM_MAX_NUMBER_EVENT_ENTRY],
  STD_TYPES_CONST uint16  LaaPassEvtIdAll[DEM_MAX_NUMBER_EVENT_ENTRY], // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
 uint8* const LucNoOfLowestPassEvt,  // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
  STD_TYPES_CONST uint16   LaaTestNotCmpltEvtPriDTC[DEM_MAX_NUMBER_EVENT_ENTRY],
  STD_TYPES_CONST uint16  LaaTestNotCmpltEvtIdAll[DEM_MAX_NUMBER_EVENT_ENTRY]) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
 uint8  LucNoOfPassEvents = *LucNoOfPassEvt;
 uint8  LucNoOfLowestPassEvents = *LucNoOfLowestPassEvt; 
    if (LucNoOfPassEvents > DEM_ZERO)
  { 
    while (DEM_ZERO < LucNoOfPassEvents)
    {
      --LucNoOfPassEvents;
      /* polyspace +6 RTE:NIV [Justified:Low] "Refer Dem_c_Poly_REF_8" */
      /*If the passive event DTC priority is lowest then only consider it for displacement*/
       if (LaaPassEvtPriDTC[LucNoOfPassEvents] == LusLpriDTC)
      {
        LaaPassEvtId[LucNoOfLowestPassEvents] = LaaPassEvtIdAll[LucNoOfPassEvents]; 
        /* #violates #ref Dem_EvtProcsg_c_REF_35 Violates MISRA 2012 Required Rule INT30 */
        /* PRQA S 3383 2 */
        LucNoOfLowestPassEvents++;
      }  
    }
  }
  else
  {
    while (DEM_ZERO < (*LucNoOfTestNotCmpltEvt))
    {
      /* #violates #ref Dem_InternalFunc_c_REF_QAC_14 Violates MISRA 2012
            Required Rule 17.8 */
            /* PRQA S 1338 2 */
      --LucNoOfTestNotCmpltEvt; // parasoft-suppress MISRAC2012-RULE_17_8-a-4 "Refer:Dem_InternalFunc_c_REF_20"
        /* polyspace +10 RTE:NIV [Justified:Low] "Refer Dem_c_Poly_REF_8" */
      /*If the Test not complete event DTC priority is lowest then only consider it for displacement*/
      if (LaaTestNotCmpltEvtPriDTC[*LucNoOfTestNotCmpltEvt] == LusLpriDTC)
      {
        LaaPassEvtId[LucNoOfLowestPassEvents] = LaaTestNotCmpltEvtIdAll[*LucNoOfTestNotCmpltEvt]; 
        /* #violates #ref Dem_EvtProcsg_c_REF_35 Violates MISRA 2012 Required Rule INT30 */
        /* PRQA S 3383 2 */
        LucNoOfLowestPassEvents++;
      }  
    }
  }
  *LucNoOfLowestPassEvt = LucNoOfLowestPassEvents;
}
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 2 */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
** Function Name        : Dem_CheckforNoPassiveEvent                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This API shall be used to Check Passive Event Count **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
** Design ID            : DEM_SDD_1438                                       **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void Dem_CheckforNoPassiveEvent(
     const uint8  LucNoOfPassEvt,
     const Dem_EventIdType LddEventId, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
     const uint16  LusMemEvtIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
     uint16* const LaaTestNotCmpltEvtPriDTC, // parasoft-suppress CERT_C-API00-a-3 MISRAC2012-RULE_8_13-a-4 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_21"
    uint16* const LaaTestNotCmpltEvtIdAll, // parasoft-suppress CERT_C-API00-a-3 MISRAC2012-RULE_8_13-a-4 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_21"
    /* #violates #ref Dem_InternalFunc_c_REF_QAC_2 Violates MISRA 2012 Required
     Rule 8.13 */
    /* PRQA S 3673 1 */
    const uint8* const LucNoOfTestNotCmpltEvt, // parasoft-suppress CERT_C-API00-a-3 MISRAC2012-RULE_8_13-a-4 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_21"
	const uint16  LusEventIdInMemory) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  uint8  LucStoredEvtDtcPriority;
  uint8  LucReportedEvtDtcPriority;
    /* polyspace +25 RTE:NIV [Justified:Low] "Refer Dem_c_Poly_REF_8" */
  /* polyspace +4 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* polyspace +3 RTE:IDP [Justified:Low] "Refer Dem_c_Poly_REF_4" */
    /* Get DTC Priority of for event stored in memory */
    LucStoredEvtDtcPriority = (Dem_GaaEventParameter[
                                    LusMemEvtIndex].pDTCAttribute)->DTCPriority;
    /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  /* polyspace +2 RTE:IDP [Justified:Low] "ReferDem_c_Poly_REF_4" */
  LucReportedEvtDtcPriority = (Dem_GaaEventParameter[LddEventId - (uint16)DEM_ONE].
                                                    pDTCAttribute)->DTCPriority;
 if (LucNoOfPassEvt == DEM_ZERO)  
        {
          if ((LucStoredEvtDtcPriority == LucReportedEvtDtcPriority) &&
             (((Dem_GaaAllEvtStatus[LusMemEvtIndex]) &
                  DEM_EVENTSTATUS_BIT6_SET) == DEM_EVENTSTATUS_BIT6_SET))  
          /*as per SWS_DM_00929 the test not complete bit will be checked only when events are equal*/
          {
            
            LaaTestNotCmpltEvtPriDTC[*LucNoOfTestNotCmpltEvt] = LucStoredEvtDtcPriority ;
            LaaTestNotCmpltEvtIdAll[*LucNoOfTestNotCmpltEvt] = LusEventIdInMemory;
          }
        }
}
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 2 */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
** Function Name        : Dem_EventStatusCallbackforBit7                      **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : This internal function calls the Event Status       **
**                        changed callback for Event Status Bit 7             **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LusEventParameterIndex, LucOldEventStatus,          **
**                        LucNewEventStatus                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : DEM_MAX_NUMBER_OF_DTC should be greater than Zero   **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaEventParameter,        **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : DEM_SDD_0538                                        **
**                                                                            **
*******************************************************************************/
#if (DEM_MAX_NUM_OF_EVENT_STATUS_CHANGED_FUNCTIONS > DEM_ZERO)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void Dem_EventStatusCallbackforBit7(const uint16 LusEventParameterIndex,  // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
     const uint8 LucOldEventStatus, const uint8 LucNewEventStatus) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  #if (DEM_MAX_NUM_OF_EVENT_STATUS_CHANGED_FUNCTIONS > DEM_ZERO)
  uint8                                LucFncCount;
  uint16                               LusIndex;
  #endif
  
  for (LucFncCount = DEM_ZERO; LucFncCount < Dem_GaaEventParameter
      [LusEventParameterIndex].ddNumOfEventStatusFct; LucFncCount++)
  {
    /* Get the index of the event status function */
    LusIndex = Dem_GaaEventParameter[LusEventParameterIndex].
      aaEventStatusFuncIndex[LucFncCount];
    /* #violates #ref Dem_EvtProcsg_c_REF_35 Violates MISRA 2012 Required Rule 
       INT30 */
    /* PRQA S 3383 4 */
    /* notify application that event status has changed */
    (void)Dem_GaaEvtStatusChangedFctPtr[LusIndex]((LusEventParameterIndex +
     DEM_ONE), LucOldEventStatus, LucNewEventStatus);
  }  
} /* End of Dem_EventStatusCallbackforBit7*/
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_ResetEventStatusMultiEventTriggering            **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Resets the event failed status                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventId                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GaaAllEvtStatus,          **
**                                              Dem_GaaEventParameter,        **
**                                              Dem_GaaIntDebounceCounter,    **
**                                              Dem_GaaFDCDirectionCB,        **
**                                              Dem_GaaIntDebounceTimer,      **
**                                              Dem_GaaFDCDirectionTD,        **
**                                              Dem_GaaEvtStatusChangedFctPtr,**
**                                              Dem_GaaDtcStatusChangedFctPtr,**
**                                              Dem_GaaAllDtcStatus,          **
**                                           Dem_GaaObdDtcStatusChangedFctPtr,**
**                       Function(s) invoked :  Det_ReportError,              **
**                                              Dcm_DemTriggerOnDTCStatus     **
**                                              Dem_DtcStatusChange           **
**                                                                            **
**  Design ID           : DEM_SDD_5889                                        **
**                                                                            **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType  Dem_ResetEventStatusMultiEventTriggering(
const uint16 LusEventParameterIndex) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  /* #violates #ref Dem_EvtProcsg_c_REF_39 Violates MISRA 2012 
  Required Rule DCL00 */
  /* PRQA S 3204 1*/  
  Std_ReturnType                                      LddReturnValue;
  const Dem_DTCAttributeType*  LpDTCAttribute;
  #if ((DEM_NUMBER_OF_COUNTER_BASED_DEBOUNCE > DEM_ZERO) ||   \
  (DEM_NUMBER_OF_TIME_BASED_DEBOUNCE > DEM_ZERO))
  uint16                               LusIndexOfIntDebounceAry;
  #endif
  #if (((DEM_GENERALINTERFACE_SUPPORT == STD_ON) && \
  (DEM_GENERALEVENTSTATUSCHANGED_CALLBACK_SUPPORT == STD_ON)) || \
  (DEM_MAX_NUM_OF_EVENT_STATUS_CHANGED_FUNCTIONS > DEM_ZERO) || \
  (((DEM_MAX_NUM_OF_DTC_STATUS_CHANGED_FUNCTIONS > DEM_ZERO) || \
  ((DEM_J1939_DTC_SUPPORT == STD_ON) && \
  (DEM_MAX_NUM_OF_J1939_DTC_STATUS_CHANGED_FUNC > DEM_ZERO)) || \
  ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
  (DEM_MAX_NUM_OF_OBD_DTC_STATUS_CHANGED_FUNCTIONS > DEM_ZERO))) &&   \
  (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_DISABLED)))
  uint8                                LucOldEventStatus;
  #endif
  #if (DEM_MAX_NUM_OF_EVENT_STATUS_CHANGED_FUNCTIONS > DEM_ZERO)
  uint8                                LucFncCount;
  uint16                               LusIndex;
  #endif
  #if ((DEM_NUMBER_COMPONENTS > DEM_ZERO) ||\
    (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
  uint8                                LucPreCondition;
  #endif   
  LddReturnValue = E_OK;
  
  /*Check if component or event avaialbilty is available or not*/
  #if ((DEM_NUMBER_COMPONENTS > DEM_ZERO) ||\
  (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
  SchM_Enter_Dem_DEM_DATA_PROTECTION();
  /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  LucPreCondition = Dem_GaaEvtPreConditions[LusEventParameterIndex];
  SchM_Exit_Dem_DEM_DATA_PROTECTION();
  if (DEM_ZERO ==  (LucPreCondition &
                              DEM_PRECOND_EVENTAVAI_COMPAVAIL_BIT_VALUE))
  #endif
  {
    SchM_Enter_Dem_DEM_DATA_PROTECTION();
    /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    /* Check if test completed this operation cycle and Passed/Failed*/
    if ((Dem_GaaAllEvtStatus[LusEventParameterIndex] &
              DEM_EVENTSTATUS_BIT6_SET) == DEM_EVENTSTATUS_BIT6_SET)
    {
      #if (((DEM_GENERALINTERFACE_SUPPORT == STD_ON) && \
      (DEM_GENERALEVENTSTATUSCHANGED_CALLBACK_SUPPORT == STD_ON)) || \
      (DEM_MAX_NUM_OF_EVENT_STATUS_CHANGED_FUNCTIONS > DEM_ZERO) || \
      (((DEM_MAX_NUM_OF_DTC_STATUS_CHANGED_FUNCTIONS > DEM_ZERO) || \
      ((DEM_J1939_DTC_SUPPORT == STD_ON) && \
      (DEM_MAX_NUM_OF_J1939_DTC_STATUS_CHANGED_FUNC > DEM_ZERO)) || \
      ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
      (DEM_MAX_NUM_OF_OBD_DTC_STATUS_CHANGED_FUNCTIONS > DEM_ZERO))) &&   \
      (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_DISABLED)))
      LucOldEventStatus = Dem_GaaAllEvtStatus[LusEventParameterIndex];
      #endif
      /* Reset the Event Status BIT 0 */
      Dem_GaaAllEvtStatus[LusEventParameterIndex] =
      Dem_GaaAllEvtStatus[LusEventParameterIndex] &
                                                      DEM_EVENTSTATUS_BIT0_RESET;
      SchM_Exit_Dem_DEM_DATA_PROTECTION();
      /* Resetting of de-bounce counter */
      /* checking if De-bounce is internal */
      if (DEM_DEBOUNCE_MONITOR_BASED !=
              Dem_GaaEventParameter[LusEventParameterIndex].ucDebounceType)
      {
        #if ((DEM_NUMBER_OF_COUNTER_BASED_DEBOUNCE > DEM_ZERO) ||   \
          (DEM_NUMBER_OF_TIME_BASED_DEBOUNCE > DEM_ZERO))
        /* load de-bounce index for corresponding internal Counter of this
          event */
        LusIndexOfIntDebounceAry = Dem_GaaEventParameter
        [LusEventParameterIndex].usIndexOfInternalCntDebounceAry;
        #endif
        #if (DEM_NUMBER_OF_COUNTER_BASED_DEBOUNCE > DEM_ZERO)
        /*Check de-bouncing is Counter based */
        if (DEM_DEBOUNCE_COUNTER_BASED ==
        Dem_GaaEventParameter[LusEventParameterIndex].ucDebounceType)
        {
          SchM_Enter_Dem_DEM_DATA_PROTECTION();
          /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
          /* Initialize the de-bounce counter and reset FDC */
          Dem_GaaIntDebounceCounter[LusIndexOfIntDebounceAry] =
          (sint16)DEM_ZERO;
          Dem_GaaFDCDirectionCB
          [LusIndexOfIntDebounceAry] = (uint8)DEM_FDC_RESET;
          SchM_Exit_Dem_DEM_DATA_PROTECTION();
        }
        #endif
    
        #if (DEM_NUMBER_OF_TIME_BASED_DEBOUNCE > DEM_ZERO)
        if (DEM_DEBOUNCE_TIME_BASED ==
          Dem_GaaEventParameter[LusEventParameterIndex].ucDebounceType)
        {
          SchM_Enter_Dem_DEM_DATA_PROTECTION();
          /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_3" */
          /* Initialize the de-bounce Timer and reset FDC */
          Dem_GaaIntDebounceTimer[LusIndexOfIntDebounceAry] = DEM_ZERO;
          Dem_GaaFDCDirectionTD[LusIndexOfIntDebounceAry] =
                                                      (uint8)DEM_FDC_RESET;
          Dem_GaaTimeDebounceEntry[LusIndexOfIntDebounceAry].ddEventId =
                                                                  DEM_ZERO;
          Dem_GaaTimeDebounceFreeze[LusIndexOfIntDebounceAry] = DEM_FREEZE;
          Dem_GaaTimeDebounceEntry[LusIndexOfIntDebounceAry].ddEventStatus =
                              (Dem_EventStatusType)DEM_INVALID_EVENT_STATUS;
    
          SchM_Exit_Dem_DEM_DATA_PROTECTION();
        }
        #endif
      }/*End of Check if De-bounce is internal */
    
      #if (DEM_MAX_NUM_OF_EVENT_STATUS_CHANGED_FUNCTIONS > DEM_ZERO)
      /* Loop through number of event status functions to be invoked for
        the event */
      for (LucFncCount = DEM_ZERO; LucFncCount < Dem_GaaEventParameter
        [LusEventParameterIndex].ddNumOfEventStatusFct; LucFncCount++)
      {
        /* Get the index of the event status function */
        LusIndex = Dem_GaaEventParameter[LusEventParameterIndex].
          aaEventStatusFuncIndex[LucFncCount];
        /* #violates #ref Dem_EvtProcsg_c_REF_35 Violates MISRA 2012 Required Rule INT30 */
        /* PRQA S 3383 4 */
        /* notify application that event status has changed */
        (void)Dem_GaaEvtStatusChangedFctPtr[LusIndex]((LusEventParameterIndex +
        DEM_ONE), LucOldEventStatus,
        Dem_GaaAllEvtStatus[LusEventParameterIndex]);
      }
      #endif
    
      /* notify application that event status has changed */
      #if ((DEM_GENERALINTERFACE_SUPPORT == STD_ON) && \
          (DEM_GENERALEVENTSTATUSCHANGED_CALLBACK_SUPPORT == STD_ON))
      /* #violates #ref Dem_EvtProcsg_c_REF_35 Violates MISRA 2012 
          Required Rule INT30 */
      /* PRQA S 3383 3 */
      DEM_GENERAL_EVTSTATUSCHNGED_CALLBACK(
        (LusEventParameterIndex + DEM_ONE)
          , LucOldEventStatus, Dem_GaaAllEvtStatus[LusEventParameterIndex])
      #endif
      /* Initialize local pointer Attribute to the event's DTC
        attributes */
      LpDTCAttribute = Dem_GaaEventParameter[LusEventParameterIndex].
                                                          pDTCAttribute;
      if (NULL_PTR != LpDTCAttribute)
      {
        (void)Dem_DtcStatusChange(
        #if (((DEM_MAX_NUM_OF_DTC_STATUS_CHANGED_FUNCTIONS > DEM_ZERO) || \
            ((DEM_J1939_DTC_SUPPORT == STD_ON) && \
            (DEM_MAX_NUM_OF_J1939_DTC_STATUS_CHANGED_FUNC > DEM_ZERO)) || \
            ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && \
      (DEM_MAX_NUM_OF_OBD_DTC_STATUS_CHANGED_FUNCTIONS > DEM_ZERO))) &&   \
      (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_DISABLED))
        LucOldEventStatus,
        #endif
        LpDTCAttribute, LusEventParameterIndex );
      }
    }/*End of Check if test is completed */
    else
    {
      SchM_Exit_Dem_DEM_DATA_PROTECTION();
      LddReturnValue = E_NOT_OK;
    }
  }
  #if ((DEM_NUMBER_COMPONENTS > DEM_ZERO) ||\
  (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
  else
  {
    LddReturnValue = E_NOT_OK;
  }
  #endif /*End of if(E_OK  == LddReturnValue) */
  return(LddReturnValue);
} /* End of Dem_ResetEventStatus */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
** Function Name        : Dem_ResetEventDebounceStatusMultiEventTriggering    **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Control the internal debounce counter/timer         **
**                        by BSW modules  and SW-Cs.                          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventId, DebounceResetStatus                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Dem_GucInit,                  **
**                                              Dem_GaaIntDebounceCounter,    **
**                                              Dem_GaaIntDebounceTimer,      **
**                                              Dem_GaaTimeDebounceEntry,     **
**                                              Dem_GaaEventParameter,        **
**                                              Dem_GaaAllFDC                 **
**                                              Dem_GaaCounterDebounceClass   **
**                                              Dem_GaaTimeDebounceFreeze     **
**                        Function(s) invoked : Det_ReportError               **
**                                                                            **
**  Design ID           : DEM_SDD_5890                                        **
**                                                                            **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType  Dem_ResetEventDebounceStatusMultiEventTriggering(
const uint16 LusEventParameterIndex, const Dem_DebounceResetStatusType DebounceResetStatus) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
    /* #violates #ref Dem_EvtProcsg_c_REF_39 Violates MISRA 2012 
    Required Rule DCL00 */
    /* PRQA S 3204 1*/
    Std_ReturnType                       LddReturnValue;
    #if ((DEM_NUMBER_COMPONENTS > DEM_ZERO) ||\
    (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
    uint8                             LucEvtPreCondition;
    #endif
    #if ((DEM_DEV_ERROR_DETECT == STD_ON) &&           \
      (DEM_DEBOUNCE_COUNTER_SUPPORT == STD_ON))
    uint16                            LusDebounceIndex;
    #endif
    #if ((DEM_NUMBER_OF_COUNTER_BASED_DEBOUNCE > DEM_ZERO) ||   \
      (DEM_NUMBER_OF_TIME_BASED_DEBOUNCE > DEM_ZERO))
    uint16                         LusIndexOfInternalDebounceAry;
    #endif
    LddReturnValue = E_OK;
    #if ((DEM_DEBOUNCE_COUNTER_SUPPORT == STD_ON) && \
         (DEM_DEV_ERROR_DETECT == STD_ON))
    if ((DEM_INIT != Dem_GucInit) &&
       /* polyspace +8 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
         /* Polyspace EvtProcsg_c_Ref_37 */
        (Dem_GaaEventParameter[LusEventParameterIndex].ucDebounceType ==
         DEM_DEBOUNCE_COUNTER_BASED))
    {
      LusDebounceIndex =
            DEM_EVENT_DEBOUNCE_ALGORITHM_CLASS(LusEventParameterIndex); // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Refer: Dem_InternalFunc_c_REF_18"
      if (DEM_EVENT_DEBOUNCE_COUNTER_STORE_FDC(LusDebounceIndex)) // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Refer: Dem_InternalFunc_c_REF_18"
      {
        (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
          DEM_RESETEVENTDEBOUNCESTATUS_SID, DEM_E_WRONG_CONDITION);
        LddReturnValue = E_NOT_OK;
      }
    }
    #endif

    /*Check if component or event avaialbilty is available or not*/
    #if ((DEM_NUMBER_COMPONENTS > DEM_ZERO) ||\
    (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
    SchM_Enter_Dem_DEM_DATA_PROTECTION();
    /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
    LucEvtPreCondition = Dem_GaaEvtPreConditions[LusEventParameterIndex];
    SchM_Exit_Dem_DEM_DATA_PROTECTION();
    if (DEM_ZERO ==  (LucEvtPreCondition &
                           DEM_PRECOND_EVENTAVAI_COMPAVAIL_BIT_VALUE))
    #endif
    {
        #if ((DEM_NUMBER_OF_COUNTER_BASED_DEBOUNCE > DEM_ZERO) ||   \
        (DEM_NUMBER_OF_TIME_BASED_DEBOUNCE > DEM_ZERO))
        /* Get the index of internal debounce counter */
        LusIndexOfInternalDebounceAry =
        /* Polyspace EvtProcsg_c_Ref_92 */
          Dem_GaaEventParameter[LusEventParameterIndex].
                                             usIndexOfInternalCntDebounceAry;
        #endif
        /* Check if reset debounce status is RESET */
        if (DEM_DEBOUNCE_STATUS_RESET  == DebounceResetStatus)
        {
          #if ((DEM_DEBOUNCE_COUNTER_SUPPORT == STD_ON) && \
                    (DEM_NUMBER_OF_COUNTER_BASED_DEBOUNCE > DEM_ZERO))
          if (DEM_DEBOUNCE_COUNTER_BASED ==
          Dem_GaaEventParameter[LusEventParameterIndex].ucDebounceType)
          {
            SchM_Enter_Dem_DEM_DATA_PROTECTION();
            /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_3" */
            /* reset internal debounce counter */
            Dem_GaaIntDebounceCounter[LusIndexOfInternalDebounceAry] =
                                                            (sint16)DEM_ZERO;
            SchM_Exit_Dem_DEM_DATA_PROTECTION();
          }
          #endif
          #if ((DEM_DEBOUNCE_TIME_SUPPORT == STD_ON) && \
                        (DEM_NUMBER_OF_TIME_BASED_DEBOUNCE > DEM_ZERO))
          if (DEM_DEBOUNCE_TIME_BASED ==
          Dem_GaaEventParameter[LusEventParameterIndex].ucDebounceType)
          {
            SchM_Enter_Dem_DEM_DATA_PROTECTION();
            /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_3" */
            /* reset internal debounce Timer */
            Dem_GaaIntDebounceTimer[LusIndexOfInternalDebounceAry] =
                                                               (uint32)DEM_ZERO;
            Dem_GaaTimeDebounceEntry[LusIndexOfInternalDebounceAry].ddEventId
                                                             = (uint16)DEM_ZERO;
            SchM_Exit_Dem_DEM_DATA_PROTECTION();
          }
          #endif
          SchM_Enter_Dem_DEM_DATA_PROTECTION();
          /* Reset Fault detection COunter */
          /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
          Dem_GaaAllFDC[LusEventParameterIndex] = (sint8)DEM_ZERO;
          SchM_Exit_Dem_DEM_DATA_PROTECTION();
        }
        #if ((DEM_DEBOUNCE_TIME_SUPPORT == STD_ON) && \
                        (DEM_NUMBER_OF_TIME_BASED_DEBOUNCE > DEM_ZERO))
        if (DEM_DEBOUNCE_TIME_BASED ==
        Dem_GaaEventParameter[LusEventParameterIndex].ucDebounceType)
        {
          SchM_Enter_Dem_DEM_DATA_PROTECTION();
          /* polyspace +2 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_3" */
          Dem_GaaTimeDebounceFreeze
          [Dem_GaaEventParameter[LusEventParameterIndex].
          usIndexOfInternalCntDebounceAry] = DEM_FREEZE;
          SchM_Exit_Dem_DEM_DATA_PROTECTION();
        }
        #endif
    }
    #if ((DEM_NUMBER_COMPONENTS > DEM_ZERO) ||\
         (DEM_EVENT_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY))
    else
    {
      LddReturnValue = E_NOT_OK;
    }
    #endif
  return(LddReturnValue);
}
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"
/*******************************************************************************
** Function Name        : Dem_DtrBit4StatusUpdate            **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : To get the storage condition status                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventId                                             **
**                                                                            **
** InOut parameter      : LusEventParameterIndex,LblStorageConditionStatus    **
**                                                                            **
** Output Parameters    : LblStorageConditionStatus                           **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : 
**                                                                            **
**  Design ID           : DEM_SDD_6556,DEM_SDD_6562                            **
**                                                                            **
*******************************************************************************/
#if ((DEM_STORAGE_CONDITION_SUPPORT == STD_ON) && \
    (DEM_NUMBER_STORAGE_CONDITION > DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_DtrBit4StatusUpdate(const uint16 LusEventParameterIndex,  // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
boolean* const LblStorageconditionFullFill) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  const Dem_StorageConditionGroupType* 
                                               LpStorageConditionGroup;
  uint8                         LucNumOfCondition;
  uint8                         LucStorageConditionIndex;
  uint8                         LucCount;
  boolean                       LblStorageConditionStatus;

  if (NULL_PTR != Dem_GaaEventParameter[LusEventParameterIndex].
                                  pStorageConditionGroup)
  {
    /* Fetch Pointer to the storage condition group */
    LpStorageConditionGroup = Dem_GaaEventParameter[LusEventParameterIndex].
                                    pStorageConditionGroup;
    /* Get the number of storage conditions belongs to this group*/
    LucNumOfCondition = LpStorageConditionGroup->ucNumOfStorageCondition;

    /* Check the status of all storage conditions configured for the event */
    for (LucCount = DEM_ZERO; LucCount < LucNumOfCondition; LucCount++)
    {
      /* Fetch index of the storage condition */
      LucStorageConditionIndex = LpStorageConditionGroup->
                                            aaStorageConditionGroupId[LucCount];
      
      SchM_Enter_Dem_DEM_DATA_PROTECTION();
      LblStorageConditionStatus =
    /* polyspace +1 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
      Dem_GaaStorageConditionStatus[LucStorageConditionIndex];
      SchM_Exit_Dem_DEM_DATA_PROTECTION();
      
            /* Check if storage condition is true */
      if (!LblStorageConditionStatus)
      {
       *LblStorageconditionFullFill = DEM_FALSE;
      }
     
      
     
    }
}
else
{
  *LblStorageconditionFullFill = DEM_TRUE;
}
}

#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_OBDAssocitateEventGroupReference            **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Resets the event failed status                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventId                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : 
**                                                                            **
**  Design ID           : DEM_SDD_6560                                        **
**                                                                            **
*******************************************************************************/
#if (DEM_OBD_ASSOCIATIVE_EVENT == STD_ON) 
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_OBDAssocitateEventGroupReference(const uint16 LusEventParameterIndex,  // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
const uint16 LusIndicatorIndex , const boolean LblIndicatorFailurCounter // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
     #if (DEM_WWHOBD_SUPPORT == STD_ON)
      , const uint16 LusDtcInfoIndex // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
       #endif
       )
{

  uint8    LucEvtFailureCntThres;
  uint16   Lusmappedobdgrpeventindex;
  uint16    LusNumberofEvents;
  uint16    LusNumberofEventsIndex;
  uint16   LusIncrementIndex;
  uint16   LuslocalEventID;
  
  Lusmappedobdgrpeventindex = Dem_GaaEventParameter
                              [LusEventParameterIndex].usobdeventgroupIndex;
  LusNumberofEvents = Dem_GaaOBDGroupAssociativeEvtRef
                                 [Lusmappedobdgrpeventindex].usNumOfEvents;
  if (!LblIndicatorFailurCounter)
  {    
    if ((Dem_GaaEventParameter
              [LusEventParameterIndex].blObdAssociativeEventGrp)
              && (DEM_MIL_INDICATOR_ID == Dem_GaaIndicatorList
              [LusIndicatorIndex].ddIndicatorId))
   {
      for (LusNumberofEventsIndex = (uint16)DEM_ZERO;  LusNumberofEventsIndex < 
                     LusNumberofEvents; LusNumberofEventsIndex++)  
              {
                /* #violates #ref Dem_EvtProcsg_c_REF_35 Violates MISRA 2012 
                   Required Rule INT30 */
                /* PRQA S 3383 3 */
                LuslocalEventID = (Dem_GaaOBDGroupAssociativeEvtRef
                [Lusmappedobdgrpeventindex].aaOBDAssociativeGroupEventID
                                        [LusNumberofEventsIndex]) - DEM_ONE;
                #if (DEM_EVT_CONFIRM_THRESHOLD_ADAPTABLE == STD_ON) 
                if (Dem_GaaEventParameter[LuslocalEventID].
                                             blEvtConfThrldContrAdaptable)
                {
                  LucEvtFailureCntThres = 
                  DEM_EVENT_FAILURE_COUNTER_THRESHOLD_ADAPTABLE(LuslocalEventID); // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Refer: Dem_InternalFunc_c_REF_18"
                }
                else
                #endif
                {
                  LucEvtFailureCntThres = 
		                      DEM_EVENT_FAILURE_COUNTER_THRESHOLD(LuslocalEventID); // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Refer: Dem_InternalFunc_c_REF_18"
                }
                /* #violates #ref Dem_EvtProcsg_c_REF_35 Violates MISRA 2012 
                   Required Rule INT30 */
                /* PRQA S 3383 3 */
                LusIncrementIndex = Dem_GaaOBDGroupAssociativeEvtRef
                [Lusmappedobdgrpeventindex].aaMILEventIndex[LusNumberofEventsIndex];
                if ((Dem_GaaIndicatorFailureCycleCounter[LusIncrementIndex] + DEM_ONE)// parasoft-suppress MISRAC2012-RULE_5_2-a-2 CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_EvtProcsg_c_REF_17 Dem_EvtProcsg_c_REF_18"
                                                     >= LucEvtFailureCntThres)// parasoft-suppress MISRAC2012-RULE_5_2-a-2 CERT_C-EXP14-a-3 CERT_C-INT02-b-2 "Refer: Dem_EvtProcsg_c_REF_17 Dem_EvtProcsg_c_REF_18"
        {
     
         
          if (DEM_INDICATOR_OFF == Dem_GaaIndicatorStatus[DEM_MIL_INDICATORINDEX])
          {
             #if (DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
            SchM_Enter_Dem_DEM_DATA_PROTECTION();
            Dem_GblMilStarted = DEM_TRUE;
            SchM_Exit_Dem_DEM_DATA_PROTECTION();
            #endif
            Dem_RecordMilFault(LusEventParameterIndex);
           
          }
               Dem_UpdateIndicatorStatus(
            #if (DEM_WWHOBD_SUPPORT == STD_ON)
            LusDtcInfoIndex,
            #endif
            LusIndicatorIndex);
          

        } 
      }
    }
  }
}
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_StoreNvmStatusInPerMemory            **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Resets the event failed status                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventId                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : 
**                                                                            **
**  Design ID           : DEM_SDD_6561                                        **
**                                                                            **
*******************************************************************************/
#if ((DEM_NUM_OF_NV_BLOCKS > DEM_ZERO) &&  \
     (DEM_INVALID != DEM_PERMANENT_MEM_NVM_BLOCK_INDX) && \
     (DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > DEM_ZERO) && \
     (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_StoreNvmStatusInPerMemory(void)
{
  Std_ReturnType LddReturnValue;
  NvM_RequestResultType LddReqResult;
  /* To store the Permanent memory in NvM */
	LddReturnValue = NvM_GetErrorStatus(Dem_GaaNVBlocks
			[DEM_PERMANENT_MEM_NVM_BLOCK_INDX].usBlockID, &LddReqResult);
	if ((LddReturnValue == E_NOT_OK) || (LddReqResult == NVM_REQ_PENDING))
	{
    Dem_GblPerEvtMemNotWritten = DEM_TRUE;  
	}
	else
	{
		/* Store Event from Dem_GstCpyPerEventMemory to Permanent Memory */
    (void) DEM_MEMCPY(Dem_GstPerEventMemory, Dem_GstCpyPerEventMemory, DEM_TWO *DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT); // parasoft-suppress CERT_C-POS54-a-1 CERT_C-DCL39-a-3 "Reason: Dem_InternalFunc_c_REF_14" // parasoft-suppress CERT_C-POS54-a-1 MISRAC2012-RULE_18_4-a-4 CERT_C-DCL39-a-3 CERT_C-DCL39-a-3 CERT_C-MEM04-a-2 CERT_C-MEM07-a-2 "Reason: Dem_InternalFunc_c_REF_14 Dem_InternalFunc_c_REF_17 Dem_InternalFunc_c_REF_18 Dem_InternalFunc_c_REF_25"
		(void)NvM_WriteBlock
            (Dem_GaaNVBlocks[DEM_PERMANENT_MEM_NVM_BLOCK_INDX].usBlockID,
			      &Dem_GstPerEventMemory);
			Dem_GblPerEvtMemNotWritten = DEM_FALSE;
  }
}
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_ReturnHealingFlag                               **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Checks the healing flag                      		  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventId                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : 
**                                                                            **
**  Design ID           : DEM_SDD_6571                                        **
**                                                                            **
*******************************************************************************/
#if (DEM_NUMBER_OF_INDICATORS_ATTRIBUTE != DEM_ZERO)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_ReturnHealingFlag(boolean* const  LblBit7ToProcessFlag,  // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
     const boolean LblReturnHealingFlag) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  
  *LblBit7ToProcessFlag = ((*LblBit7ToProcessFlag) || LblReturnHealingFlag);
}
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Dem_ProcessExtDataRecNum0x9F                        **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Process DTCExtendedDataRecordNumber                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventId                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : 
**                                                                            **
**  Design ID           : DEM_SDD_6623                                        **
**                                                                            **
*******************************************************************************/
#if (DEM_MAX_NUMBER_OF_DTC > DEM_ZERO)
#if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
     (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_ProcessExtDataRecNum0x9F(const uint8 ClientId,  // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
      boolean* const LpValidRecord,  // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
      uint8* const LucExtendedDataNumber,  // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
      const uint8 LucRecordIndx)
{
  /* polyspace +3 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  if ((Dem_GaaEDRecord[LucRecordIndx].ucExtendedDataRecordNumber >= 
  DEM_MIM_VALID_OBD_EXTENDED_RECORD_NUMBER) && (Dem_GaaEDRecord[LucRecordIndx].
  ucExtendedDataRecordNumber <= DEM_MAX_0XFE_OBD_EXT_REC_NUM))
  {	
    *LpValidRecord = DEM_TRUE;
    /* Get record number to be process */
    *LucExtendedDataNumber = Dem_GaaEDRecord[LucRecordIndx].
                                                     ucExtendedDataRecordNumber;
    /* #violates #ref Dem_Dcm_c_REF_19 Violates MISRA 2012 Required Rule INT30 */
    /* PRQA S 3383 2 */
    /* Increment to process next record */
    ++(Dem_GaaClientSelection[ClientId].ucEDNumRecordProcessed);
  }
}
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"
#endif
#endif

/*******************************************************************************
** Function Name        : Dem_ProcessIntrlDataEleRatioDemIumpr                **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Process Internal Data Element of Ratio Dem Iumpr    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventId                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                                                                            **
**  Design ID           : DEM_SDD_6658,DEM_SDD_7083                           **
**                                                                            **
*******************************************************************************/
/**********Ratio specific******************************/
#if (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON)
#if (DEM_IUMPR_STATUS_HANDLING == DEM_IUMPR_RATIO_SPECIFIC)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void  Dem_ProcessIntrlDataEleRatioDemIumpr(const uint16 LusEventParameterIndex, uint8* Buffer )// parasoft-suppress CERT_C-API00-a-3 "Reason: Input prameter to the call already vaildated once in the sequence"
{
  uint16   LusRatioCount;
  uint16   LusRatioIndex;
  float32  LflRatioValue = (float32)DEM_MAX_IUPMR_RATIO;
  float32  LflCalRatioValue;
  uint8    LucIumprGroupId;
  LusRatioIndex = (uint16)DEM_ZERO;
  /* polyspace +70 RTE:NIVL [Justified:Low] "Refer Dem_ObdEvtProcsg_c_Poly_REF_4" */ 
  /* polyspace +70 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  SchM_Enter_Dem_DEM_DATA_PROTECTION();
   for (LucIumprGroupId = DEM_ZERO; LucIumprGroupId < Dem_GaaEventParameter[  // parasoft-suppress CERT_C-INT02-a-2 "Refer: Dem_InternalFunc_c_REF_27"
  LusEventParameterIndex].usRatioIdCount; 
             LucIumprGroupId++)
  {
    
    {
      LusRatioCount = Dem_GaaEventParameter[LusEventParameterIndex].aaRatioId[LucIumprGroupId];
        #if (DEM_MAX_NUMBER_RATIOS > DEM_ZERO)     
        if (DEM_ZERO  != Dem_GaaIumprIntrlDenominatorCount[LusRatioCount])
        {
            /* polyspace +10 RTE:ZDV [Justified:Low] "Refer Dem_ObdEvtProcsg_c_Poly_REF_2" */

          LflCalRatioValue = ((float32)(Dem_GaaIumprIntrlNumeratorCount
        		  [LusRatioCount]) /
                            (float32)(Dem_GaaIumprIntrlDenominatorCount
                            		[LusRatioCount]));
        }
        else
        #endif
        {
          LflCalRatioValue = (float32)DEM_MAX_IUPMR_RATIO;
        }

        /* Requirement 69*/
        if ((float32)DEM_MAX_IUPMR_RATIO < LflCalRatioValue)
        {
          LflCalRatioValue = (float32)DEM_MAX_IUPMR_RATIO;
        }

        if (LflCalRatioValue <= LflRatioValue)
        {
          LusRatioIndex = LusRatioCount;
          LflRatioValue = LflCalRatioValue;
        }
        else
        {
          /* to avoid QAC Warning */
        }
      
    }
  }

  #if ((DEM_IUMPR_STATUS_HANDLING == DEM_IUMPR_RATIO_SPECIFIC) && \
                                             (DEM_MAX_NUMBER_RATIOS > DEM_ZERO))  
  *Buffer = (uint8)Dem_GaaIumprIntrlNumeratorCount[LusRatioIndex];
  /* #violates #ref Dem_InternalFunc_c_REF_QAC_14 Violates MISRA 2012
  Required Rule 17.8 */
  /* PRQA S 1338 6 */
  Buffer++; // parasoft-suppress CERT_C-API00-a-3 MISRAC2012-RULE_17_8-a-4 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_20"
  *Buffer = (uint8)(Dem_GaaIumprIntrlNumeratorCount[LusRatioIndex] >> (uint16)DEM_ONE_BYTE);
  Buffer++; // parasoft-suppress CERT_C-API00-a-3 MISRAC2012-RULE_17_8-a-4 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_20"
  *Buffer = (uint8)Dem_GaaIumprIntrlDenominatorCount[LusRatioIndex];
  Buffer++; // parasoft-suppress CERT_C-API00-a-3 MISRAC2012-RULE_17_8-a-4 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_20"
  *Buffer = (uint8)(Dem_GaaIumprIntrlDenominatorCount[LusRatioIndex] >> (uint16)DEM_ONE_BYTE);
  #endif
  SchM_Exit_Dem_DEM_DATA_PROTECTION();
  DEM_UNUSED(LusRatioIndex);
}
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"
#endif
#endif

/*******************************************************************************
** Function Name        : Dem_ProcessIntrlDataEleGroupDemIumpr                **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Process Internal Data Element of Group Dem Iumpr    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventId                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                                                                            **
**  Design ID           : DEM_SDD_6659,DEM_SDD_7083                           **
**                                                                            **
*******************************************************************************/
#if (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON)
#if (DEM_IUMPR_STATUS_HANDLING == DEM_IUMPR_GROUP_SPECIFIC)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static void  Dem_ProcessIntrlDataEleGroupDemIumpr(const uint16 LusEventParameterIndex, uint8* Buffer ) // parasoft-suppress MISRAC2012-RULE_17_8-a-4 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_20 Dem_InternalFunc_c_REF_10"
{
  uint16   LusIumprCount;
  uint16   LusRatioIndex;
  float32  LflRatioValue;
  float32  LflCalRatioValue;
  uint8    LucIumprGroupId;
  LusRatioIndex = (uint16)DEM_ZERO;
  LflRatioValue = DEM_MAX_IUPMR_RATIO;
  /* polyspace +70 RTE:NIVL [Justified:Low] "Refer Dem_ObdEvtProcsg_c_Poly_REF_4" */ 
  /* polyspace +70 RTE:OBAI [Justified:Low] "Refer Dem_c_Poly_REF_2" */
  SchM_Enter_Dem_DEM_DATA_PROTECTION();
  for (LucIumprGroupId = DEM_ZERO;
                    LucIumprGroupId < Dem_GaaEventParameter[LusEventParameterIndex].ucIumprIdcount; LucIumprGroupId++)
  {
    
    {
      LusIumprCount = Dem_GaaEventParameter[LusEventParameterIndex].aaIUMPRId[LucIumprGroupId];     
        if (DEM_ZERO  != Dem_GaaIumprNumeratorCount
          [LusIumprCount])
        {
           /* polyspace +10 RTE:ZDV [Justified:Low] "Refer Dem_ObdEvtProcsg_c_Poly_REF_2" */
          LflCalRatioValue = ((float32)(Dem_GaaIumprNumeratorCount
            [LusIumprCount]) /
                            (float32)(Dem_GaaIumprDenominatorCount
            [LusIumprCount]));
        }
        else
        {
          LflCalRatioValue = (float32)DEM_MAX_IUPMR_RATIO;
        }

        /* Requirement 69*/
        if ((float32)DEM_MAX_IUPMR_RATIO < LflCalRatioValue)
        {
          LflCalRatioValue = (float32)DEM_MAX_IUPMR_RATIO;
        }

        if (LflCalRatioValue <= LflRatioValue)
        {


          LusRatioIndex = LusIumprCount;
          LflRatioValue = LflCalRatioValue;
        }
        else
        {
          /* to avoid QAC Warning */
        }
      }
  }
  /* PRQA S 1338 6 */
  *Buffer = (uint8)Dem_GaaIumprNumeratorCount[LusRatioIndex];
  Buffer++; // parasoft-suppress CERT_C-API00-a-3 MISRAC2012-RULE_17_8-a-4 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_20"
  *Buffer = (uint8)(Dem_GaaIumprNumeratorCount[LusRatioIndex] >> (uint16)DEM_ONE_BYTE);
  Buffer++; // parasoft-suppress CERT_C-API00-a-3 MISRAC2012-RULE_17_8-a-4 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_20"
  *Buffer = (uint8)Dem_GaaIumprDenominatorCount[LusRatioIndex];
  Buffer++; // parasoft-suppress CERT_C-API00-a-3 MISRAC2012-RULE_17_8-a-4 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_20"
  *Buffer = (uint8)(Dem_GaaIumprDenominatorCount[LusRatioIndex] >> (uint16)DEM_ONE_BYTE);
  SchM_Exit_Dem_DEM_DATA_PROTECTION();
}
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"
#endif
#endif
/*******************************************************************************
** Function Name        : Dem_ProcessEventMemoryDestination                **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Process DTCExtendedDataRecordNumber                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventId                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : 
**                                                                            **
**  Design ID           : DEM_SDD_6659                                        **
**                                                                            **
*******************************************************************************/
#if ((DEM_MAX_ED_RECDS_PER_EVENT > DEM_ZERO) && \
    (DEM_MAX_NUMBER_OF_ED_RECDS >  DEM_ZERO) && \
    (DEM_NUMBER_OF_DATA_ELEMENT_INTERNAL > DEM_ZERO))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static void  Dem_ProcessEventMemoryDestination(const Dem_DTCOriginType LucEventDestination,
Dem_DTCOriginType*  const  LpDTCOrigin) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  
  if ((LucEventDestination == DEM_DTC_PRIMARY_MEMORY) ||
          (LucEventDestination == DEM_DTC_ORIGIN_PERMANENT_MEMORY))
      {
        *LpDTCOrigin = LucEventDestination - (uint16)DEM_ONE;
      }
      #if (DEM_USER_DEF_MEMORY_CONFIGURED == STD_ON)
      else
      {
        (void)Dem_UDMemoryIndexFetch(LucEventDestination,
                      LpDTCOrigin);
      }
      #endif

}
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_CheckInternaldateleForIumprMonitorActiDtr       **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Process Internaldataelements for IUMPR,DTR,MONIOTRDATA **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventId                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : 
**                                                                            **
**  Design ID           : DEM_SDD_7024                                        **
**                                                                            **
*******************************************************************************/
#if ((DEM_DTR_INTERNAL_DATAELEMENT == STD_ON) || \
       (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON) || \
       (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON) || \
       (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static Std_ReturnType  Dem_CheckInternaldateleForIumprMonitorActiDtr(const uint8 LucDataElement) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  Std_ReturnType  LddReturnValue = E_NOT_OK; 
 #if (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON)
     if (((Dem_GaaInternalDataElements
               [LucDataElement].pInternalDataElement) == NULL_PTR) &&
               (LucDataElement == DEM_MONITOR_ACTIVITY_DATA))
      {
         LddReturnValue = E_OK;
      }
    #endif
    #if (DEM_DTR_INTERNAL_DATAELEMENT == STD_ON)
     if (((Dem_GaaInternalDataElements
         [LucDataElement].pInternalDataElement) == NULL_PTR) &&
         (LucDataElement == DEM_DTR))
      {
         LddReturnValue = E_OK;
      }
    #endif
    #if (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON)
     if (((Dem_GaaInternalDataElements
         [LucDataElement].pInternalDataElement) == NULL_PTR) &&
         (LucDataElement == DEM_IUMPR))
         {
         LddReturnValue = E_OK;
         }
    #endif
    #if (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON)
     if (((Dem_GaaInternalDataElements
         [LucDataElement].pInternalDataElement) == NULL_PTR) &&
         (LucDataElement == DEM_J1939LAMP_STATUS))
         {
         LddReturnValue = E_OK;
         }
    #endif
    return(LddReturnValue);
}
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_ProcessIumprMonitorDtr       **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Process Internaldataelements for IUMPR,DTR,MONIOTRDATA **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventId                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : 
**                                                                            **
**  Design ID           : DEM_SDD_7025                                        **
**                                                                            **
*******************************************************************************/
#if ((DEM_DTR_INTERNAL_DATAELEMENT == STD_ON) || \
       (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON) || \
       (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON) || \
       (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static void  Dem_ProcessIumprMonitorDtr(const uint8 LucDataElement, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
#if ((DEM_DTR_INTERNAL_DATAELEMENT == STD_ON) || (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON) || \
(DEM_J1939LAMP_STATUS_SUPPORT == STD_ON))
uint8*  LpCurrentBufferIndex, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
#endif
 uint8 *DestBuffer, // parasoft-suppress CERT_C-DCL00-b-3 CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_9 Dem_InternalFunc_c_REF_10"
 const uint16 LusEventParameterIndex) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  #if (DEM_DTR_INTERNAL_DATAELEMENT == STD_ON)
  uint8                 LucDTRCount;
  uint8                 LucCount;
  uint16                 LusDtrId;
  uint8 LucptrIndex;
  #endif
  #if (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON)
  /* #violates #ref Dem_InternalFunc_c_REF_24  Violates MISRA 2012 Required Rule INT02 */
  /* PRQA S 1252 3 */
  #if ((DEM_MIL_SUPPORT == STD_ON) || (DEM_RED_STOP_LAMP_SUPPORT == STD_ON) || (DEM_PROTECT_LAMP_SUPPORT == STD_ON) || (DEM_AMBER_WARNING_LAMP_SUPPORT == STD_ON)) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  uint8   LucLampStatus = DEM_ZERO;
  uint8   LucFlashLampStatus = DEM_UNAVAILABLE_FLASH_LAMP_STATUS;
  #else
  const uint8   LucLampStatus = DEM_ZERO;
  uint8   LucFlashLampStatus = DEM_UNAVAILABLE_FLASH_LAMP_STATUS;
  #endif
  #endif

 #if (DEM_DTR_INTERNAL_DATAELEMENT == STD_ON)
    if (LucDataElement == DEM_DTR)
    {
		LucDTRCount = Dem_GaaEventParameter[LusEventParameterIndex].ucDtrEvnts;
		*(DestBuffer + *LpCurrentBufferIndex) = DEM_ZERO;
		LucptrIndex = *LpCurrentBufferIndex;
	    ++(*LpCurrentBufferIndex);
		SchM_Enter_Dem_DEM_DATA_PROTECTION();
		for (LucCount = DEM_ZERO; LucCount < LucDTRCount; LucCount++)
		{
			LusDtrId = Dem_GaaEventParameter[LusEventParameterIndex].
			           usDtrIndex[LucCount];
      /* Check whether DTR is visible */
      if (Dem_GblDtrInvisible[LusDtrId] == DEM_ZERO)
      {
    	    *(DestBuffer + LucptrIndex) =  (*(DestBuffer + LucptrIndex)) + DEM_ONE ; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"			
		    *(DestBuffer + *LpCurrentBufferIndex) = DEM_ZERO;	// parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"	
		    ++(*LpCurrentBufferIndex);
			
			*(DestBuffer + *LpCurrentBufferIndex) = // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
			 Dem_GaaEventParameter[LusEventParameterIndex].ucUascalId[LucCount];
		    ++(*LpCurrentBufferIndex);
			
			
			*(DestBuffer + *LpCurrentBufferIndex) = (uint8) (Dem_GaaTidCurData[LusDtrId].usCurrentTestValue >> DEM_ONE_BYTE); // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
			++(*LpCurrentBufferIndex);
			
			*(DestBuffer + *LpCurrentBufferIndex) = (uint8) Dem_GaaTidCurData[LusDtrId].usCurrentTestValue; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
			++(*LpCurrentBufferIndex);

            *(DestBuffer + *LpCurrentBufferIndex) = (uint8) (Dem_GaaTidCurData[LusDtrId].usCurrentLowerLimit >> DEM_ONE_BYTE); // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
			++(*LpCurrentBufferIndex);
			*(DestBuffer + *LpCurrentBufferIndex) = (uint8) Dem_GaaTidCurData[LusDtrId]. usCurrentLowerLimit; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
			++(*LpCurrentBufferIndex);
			
			*(DestBuffer + *LpCurrentBufferIndex) = (uint8) (Dem_GaaTidCurData[LusDtrId].
			                                usCurrentUpperLimit >> DEM_ONE_BYTE); // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
			++(*LpCurrentBufferIndex);
			*(DestBuffer + *LpCurrentBufferIndex) = (uint8) Dem_GaaTidCurData[LusDtrId].
			                                usCurrentUpperLimit; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
			++(*LpCurrentBufferIndex);
			}
	  }
	  if (*(DestBuffer + LucptrIndex) == DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
      {
        (void) DEM_MEMSET((DestBuffer + *LpCurrentBufferIndex), // parasoft-suppress MISRAC2012-RULE_18_4-a-4  CERT_C-POS54-a-1 CERT_C-INT31-i-2 "Reason: Dem_InternalFunc_c_REF_18 Dem_InternalFunc_c_REF_14"
                        DEM_ZERO, DEM_EIGHT); // parasoft-suppress MISRAC2012-RULE_18_4-a-4  CERT_C-POS54-a-1 CERT_C-INT31-i-2 MISRAC2012-RULE_10_3-b-2 "Reason: Dem_InternalFunc_c_REF_18 Dem_InternalFunc_c_REF_14"
        *LpCurrentBufferIndex += DEM_SEVEN;
      }
		
		SchM_Exit_Dem_DEM_DATA_PROTECTION();
    }     
	#endif
  #if (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON)
    if (LucDataElement == DEM_IUMPR)
    {
            #if (DEM_IUMPR_STATUS_HANDLING == DEM_IUMPR_RATIO_SPECIFIC)
            Dem_ProcessIntrlDataEleRatioDemIumpr(LusEventParameterIndex, DestBuffer);
            #elif (DEM_IUMPR_STATUS_HANDLING == DEM_IUMPR_GROUP_SPECIFIC)
            Dem_ProcessIntrlDataEleGroupDemIumpr(LusEventParameterIndex, DestBuffer);
            #endif
    }    
    #endif     
    #if (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON)
     if (LucDataElement == DEM_MONITOR_ACTIVITY_DATA)
     {       
       *(DestBuffer + *LpCurrentBufferIndex) = // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
               Dem_GaaMonitorActivityDataValue[(Dem_GaaEventParameter
		        [LusEventParameterIndex].usMilEventIDIndex) ];
         /* PRQA S 3383 5 */
        ++(*LpCurrentBufferIndex);
               *(DestBuffer + *LpCurrentBufferIndex) = // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
               Dem_GaaMiniNumerator[(Dem_GaaEventParameter
		        [LusEventParameterIndex].usMilEventIDIndex)];
        ++(*LpCurrentBufferIndex);
     }
     #endif
      #if (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON)
      if (LucDataElement == DEM_J1939LAMP_STATUS)
    {
      /* #violates #ref Dem_InternalFunc_c_REF_24  Violates MISRA 2012 Required Rule INT02 */
      /* PRQA S 1252 5 */
      #if   ((DEM_MIL_SUPPORT == STD_ON) || (DEM_RED_STOP_LAMP_SUPPORT == STD_ON) || (DEM_PROTECT_LAMP_SUPPORT == STD_ON) || (DEM_AMBER_WARNING_LAMP_SUPPORT == STD_ON)) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
      Dem_GetCurrentLampStatus(LusEventParameterIndex, &LucLampStatus, &LucFlashLampStatus);
       
       *(DestBuffer + *LpCurrentBufferIndex) = LucLampStatus; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        ++(*LpCurrentBufferIndex);
              *(DestBuffer + *LpCurrentBufferIndex) = LucFlashLampStatus; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        ++(*LpCurrentBufferIndex);
      #else
       *(DestBuffer + *LpCurrentBufferIndex) = LucLampStatus; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        ++(*LpCurrentBufferIndex);
              *(DestBuffer + *LpCurrentBufferIndex) = LucFlashLampStatus; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        ++(*LpCurrentBufferIndex);
      #endif
    
    }
    #endif  
}
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"
 #endif
/*******************************************************************************
** Function Name        : Dem_UdsOnObdRecordChk                               **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Checking the RecordNumber 0xF0 for 3byte dtc        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : RecordNumber                                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Boolean                                             **
**                                                                            **
** Preconditions        : The SupportedObdOnUds and MaxNumberOfDtc should be  **
**                        True                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :Dem_GucInit,                   **
**                                             Dem_GaaDTCAttributes,          **
**                                             Dem_GaaSuppressionStatus       **
**                        Function(s) invoked :Det_ReportError                **
**                                                                            **
** Design ID            : DEM_SDD_XXXX                                        **
*******************************************************************************/
#if ((DEM_MAX_NUMBER_OF_DTC > DEM_ZERO) && \
      (DEM_SUPPORTEDOBD_ON_UDSDTC == STD_ON))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* #violates #ref Dem_Dcm_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5001 1 */
boolean Dem_UdsOnObdRecordChk (const uint8 ClientId, const uint8 RecordNumber) // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
{
  boolean                          LddReturnValue;
  Dem_DTCFormatType                LddDTCFormat;
  
  LddDTCFormat = Dem_GaaClientSelection[ClientId].ddDTCFormat;
  /* Check for DTC FORMAT */
  if ((((DEM_ZERO == RecordNumber) ||
	  (DEM_UDS_ON_OBD_RECORD_NUMBER == RecordNumber)) &&
	  (LddDTCFormat == DEM_DTC_FORMAT_OBD_3BYTE))
      || (DEM_ZERO != RecordNumber))
  {
	LddReturnValue = DEM_TRUE;		   
  }
  else
  {
	LddReturnValue = DEM_FALSE;  
  }
  return LddReturnValue;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Dem_ProcessGetInternalIumprMonitorDtr       **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Process Internaldataelements for IUMPR,DTR,MONIOTRDATA **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : EventId                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : 
**                                                                            **
**  Design ID           : DEM_SDD_7026                                        **
**                                                                            **
*******************************************************************************/
#if ((DEM_DTR_INTERNAL_DATAELEMENT == STD_ON) || \
       (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON) || \
       (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON) || \
       (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON))
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static void  Dem_ProcessGetInternalIumprMonitorDtr(const uint8 LucDataElement, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
uint16* const LusDestBufferIndex, // parasoft-suppress CERT_C-API00-a-3 "Refer: Dem_InternalFunc_c_REF_10"
uint8*  LpDestBuffer, const uint16 LusEventParameterIndex) // parasoft-suppress CERT_C-API00-a-3 CERT_C-DCL00-b-3 "Refer: Dem_InternalFunc_c_REF_10 Dem_InternalFunc_c_REF_9"
{
  #if (DEM_DTR_INTERNAL_DATAELEMENT == STD_ON)
  uint8                 LucDTRCount;
  uint8                 LucCount;
  uint16                 LusDtrId;
  uint16                 LusptrIndex;
  #endif
  
  #if (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON)
  /* #violates #ref Dem_InternalFunc_c_REF_24  Violates MISRA 2012 Required Rule INT02 */
  /* PRQA S 1252 3 */
  #if ((DEM_MIL_SUPPORT == STD_ON) || (DEM_RED_STOP_LAMP_SUPPORT == STD_ON) || (DEM_PROTECT_LAMP_SUPPORT == STD_ON) || (DEM_AMBER_WARNING_LAMP_SUPPORT == STD_ON)) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
  uint8   LucLampStatus = DEM_ZERO;
  uint8   LucFlashLampStatus = DEM_UNAVAILABLE_FLASH_LAMP_STATUS;
  #else
  const uint8   LucLampStatus = DEM_ZERO;
  uint8   LucFlashLampStatus = DEM_UNAVAILABLE_FLASH_LAMP_STATUS;
  #endif
  #endif

 #if (DEM_DTR_INTERNAL_DATAELEMENT == STD_ON)
    if (LucDataElement == DEM_DTR)
    {
      LucDTRCount = Dem_GaaEventParameter[LusEventParameterIndex].ucDtrEvnts;
      *(LpDestBuffer + *LusDestBufferIndex) = DEM_ZERO; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
		  LusptrIndex = *LusDestBufferIndex;
	    ++(*LusDestBufferIndex);
			SchM_Enter_Dem_DEM_DATA_PROTECTION();
      		for (LucCount = DEM_ZERO; LucCount < LucDTRCount; LucCount++)
      		{
      			LusDtrId = Dem_GaaEventParameter[LusEventParameterIndex].
      			             usDtrIndex[LucCount];
            /* Check whether DTR is visible*/
            if (Dem_GblDtrInvisible[LusDtrId] == DEM_ZERO)
            {
               *(LpDestBuffer + LusptrIndex) =  (*(LpDestBuffer + LusptrIndex)) + DEM_ONE;  // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"  // parasoft-suppress CERT_C-INT02-a-2 "Refer: Dem_InternalFunc_c_REF_27"
      			  *(LpDestBuffer + (*LusDestBufferIndex)) = DEM_ZERO; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
      		      ++(*LusDestBufferIndex);
      			  *(LpDestBuffer + (*LusDestBufferIndex)) = // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
      			               Dem_GaaEventParameter[LusEventParameterIndex].ucUascalId[LucCount];
      		      ++(*LusDestBufferIndex);
      			  
                    *(LpDestBuffer + (*LusDestBufferIndex)) = (uint8) (Dem_GaaTidCurData[LusDtrId].usCurrentTestValue >> DEM_ONE_BYTE); // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
      			  ++(*LusDestBufferIndex);
      			  *(LpDestBuffer + (*LusDestBufferIndex)) = (uint8) Dem_GaaTidCurData[LusDtrId].  usCurrentTestValue; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
      			  ++(*LusDestBufferIndex);
                    *(LpDestBuffer + (*LusDestBufferIndex)) = (uint8) (Dem_GaaTidCurData[LusDtrId].usCurrentTestValue >> DEM_ONE_BYTE); // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
      			  ++(*LusDestBufferIndex);
      			  *(LpDestBuffer + (*LusDestBufferIndex)) = (uint8) Dem_GaaTidCurData[LusDtrId].usCurrentLowerLimit; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
      			  ++(*LusDestBufferIndex);
      			  *(LpDestBuffer + (*LusDestBufferIndex)) = (uint8) (Dem_GaaTidCurData[LusDtrId].usCurrentUpperLimit >> DEM_ONE_BYTE); // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
      			  ++(*LusDestBufferIndex);
      			  *(LpDestBuffer + (*LusDestBufferIndex)) = (uint8) Dem_GaaTidCurData[LusDtrId].usCurrentUpperLimit; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
      			  ++(*LusDestBufferIndex);
            }
          }
          if (*(LpDestBuffer + LusptrIndex) == DEM_ZERO) // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
          {
      			(void) DEM_MEMSET((LpDestBuffer + (*LusDestBufferIndex)), DEM_ZERO, DEM_EIGHT);  // parasoft-suppress MISRAC2012-RULE_18_4-a-4 CERT_C-POS54-a-1 CERT_C-INT31-i-2 MISRAC2012-RULE_10_3-b-2 "Reason: Dem_InternalFunc_c_REF_18 Dem_InternalFunc_c_REF_14"
            *LusDestBufferIndex += DEM_SEVEN;             
          }
     		SchM_Exit_Dem_DEM_DATA_PROTECTION(); 			  
		}

	#endif
  #if (DEM_ED_INTL_IUMPR_SUPPORT == STD_ON)
    if (LucDataElement == DEM_IUMPR)
    {
            #if (DEM_IUMPR_STATUS_HANDLING == DEM_IUMPR_RATIO_SPECIFIC)
            Dem_ProcessIntrlDataEleRatioDemIumpr(LusEventParameterIndex, LpDestBuffer);
            #elif (DEM_IUMPR_STATUS_HANDLING == DEM_IUMPR_GROUP_SPECIFIC)
            Dem_ProcessIntrlDataEleGroupDemIumpr(LusEventParameterIndex, LpDestBuffer);
            #endif
            *LusDestBufferIndex = *LusDestBufferIndex + DEM_FOUR; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
    }    
    #endif     
    #if (DEM_MAX_MONITOR_ACTIVITY_SUPPORT == STD_ON)
     if (LucDataElement == DEM_MONITOR_ACTIVITY_DATA)
     {       
      *(LpDestBuffer + (*LusDestBufferIndex)) = // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
               Dem_GaaMonitorActivityDataValue[(Dem_GaaEventParameter
		        [LusEventParameterIndex].usMilEventIDIndex )];
        (*LusDestBufferIndex)++;
               *(LpDestBuffer + (*LusDestBufferIndex)) = // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
               Dem_GaaMiniNumerator[(Dem_GaaEventParameter
		        [LusEventParameterIndex].usMilEventIDIndex )];
        (*LusDestBufferIndex)++;
     }
     #endif
     
     #if (DEM_J1939LAMP_STATUS_SUPPORT == STD_ON)
      if (LucDataElement == DEM_J1939LAMP_STATUS)
    {
      /* #violates #ref Dem_InternalFunc_c_REF_24  Violates MISRA 2012 Required Rule INT02 */
      /* PRQA S 1252 5 */
      #if  ((DEM_MIL_SUPPORT == STD_ON) || (DEM_RED_STOP_LAMP_SUPPORT == STD_ON) || (DEM_PROTECT_LAMP_SUPPORT == STD_ON) || (DEM_AMBER_WARNING_LAMP_SUPPORT == STD_ON)) // parasoft-suppress MISRAC2012-RULE_20_9-b-2 "Reason: Dem_InternalFunc_c_REF_16"
      Dem_GetCurrentLampStatus(LusEventParameterIndex, &LucLampStatus, &LucFlashLampStatus);
       
       *(LpDestBuffer + (*LusDestBufferIndex)) = LucLampStatus; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        (*LusDestBufferIndex)++;
               *(LpDestBuffer + (*LusDestBufferIndex)) = LucFlashLampStatus; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        (*LusDestBufferIndex)++;
       #else
       *(DestBuffer + *LpCurrentBufferIndex) = LucLampStatus; // parasoft-suppress MISRAC2012-RULE_18_4-a-4 "Reason: Dem_InternalFunc_c_REF_18"
        ++(*LpCurrentBufferIndex);
              *(DestBuffer + *LpCurrentBufferIndex) = LucFlashLampStatus;
        ++(*LpCurrentBufferIndex);
      #endif
    }
    #endif  
}
#define DEM_STOP_SEC_CODE
/* #violates #ref Dem_InternalFunc_c_CERT_REF_1 Violates MISRA 2012
   Required Rule CERTCCM 2.1.0 */
/* PRQA S 5002 1 */
#include "Dem_MemMap.h"
 #endif
/*polyspace-end RTE:UNR [Justified:Low] "Refer Dem_InternalFunc_c_Poly_REF_1" */
/*polyspace-end CERT-C:DCL15-C [Justified:Low] "Refer
     Dem_InternalFunc_c_Cert_REF_1" */
/*polyspace-end CERT-C:DCL19-C [Justified:Low] "Refer
     Dem_InternalFunc_c_Cert_REF_1" */
/*polyspace-end CERT-C:MSC12-C [Justified:Low] "Refer
     Dem_InternalFunc_c_Cert_REF_2" */
/*polyspace-end CERT-C:ARR30-C [Justified:Low] "Refer
     Dem_InternalFunc_c_Cert_REF_3" */
/*polyspace-end CERT-C:EXP08-C [Justified:Low] "Refer
     Dem_InternalFunc_c_Cert_REF_3" */
/*polyspace-end CERT-C:DCL23-C [Justified:Low] "Refer
     Dem_InternalFunc_c_Cert_REF_4" */
/*polyspace-end CERT-C:DCL13-C [Justified:Low] "Refer
     Dem_InternalFunc_c_Cert_REF_5" */
/*******************************************************************************
**                      Polyspace MISRA Violations                            **
**        Polyspace Warning 21.1 Minimisation of run-time failures.           **
*******************************************************************************/
/**
  **Polyspace InternalFunc_c_Ref_42:
  Explanation: Dem_GaaInternalDataElements[LusDataElement].pInternalDataElement
  is checked for null pointer in code.

  **Polyspace InternalFunc_c_Ref_43:
  Explanation: LucCount1 boundary conditions are checked in code.
  Explanation Rule 9.1: Initialization of LaaEdDataBuffer is not required
  because this array gets filled with valid value before used.

  **Polyspace InternalFunc_c_Ref_44:
  Explanation: EventId will give DET error if it is zero also it is not
  configurable as zero in KSAR as well.

  **Polyspace InternalFunc_c_Ref_45:
  Explanation: LucDataCount boundary conditions are checked in code.
  Explanation Rule 9.1: Initialization of LaaDidDataBuffer is not required
  because this array gets filled with valid value before used.

   **Polyspace InternalFunc_c_Ref_46:
  Explanation: EventId will give DET error if it is zero also it is not
  configurable as zero in KSAR as well.

  **Polyspace InternalFunc_c_Ref_47:
  Explanation: Dem_GaaInternalDataElements[LusDataElement].pInternalDataElement
  is checked for null pointer in code.

  **Polyspace InternalFunc_c_Ref_48:
  Explanation: Dem_GaaInternalDataElements[LusDataElement].pInternalDataElement
  is checked for null pointer in code.

  **Polyspace InternalFunc_c_Ref_108:
  Explanation: LpOperationCycleIndex will give right value since LucMid is
  checked that it should be always greater than one.

  **Polyspace InternalFunc_c_Ref_109:
  Explanation: aaEdData[LucRecIndex] is taken care that it will give right
  value as LucCount is taken care that it should not exceed LucNumOfEDRecords.

  **Polyspace InternalFunc_c_Ref_110:
  Explanation: aaEdData[LucRecIndex] is taken care that it will give right
  value as LucCount is taken care that it should not exceed LucNumOfEDRecords.

  **Polyspace InternalFunc_c_Ref_111:
  Explanation: aaEdData[LucRecIndex] is taken care that it will give right
  value as LucCount is taken care that it should not exceed LucNumOfEDRecords.

  **Polyspace InternalFunc_c_Ref_112:
  Explanation: LucRecDataIndexToBuffer is taken care that it should not exceed
  LucRecSize so that it will give right value.

  **Polyspace InternalFunc_c_Ref_113:
  Explanation: aaEdData[LucRecIndex] is taken care that it will give right
  value as LucCount is taken care that it should not exceed LucNumOfEDRecords.

  **Polyspace InternalFunc_c_Ref_114:
  Explanation: *DestBuffer will give DET error if it is zero .

  **Polyspace InternalFunc_c_Ref_118:
  Explanation: LusEventParameterIndex is taken care that it will give right
  value as EventParameterIndex comes from EventId and EventId can never be zero
  otherwise it will give DET.

  **Polyspace InternalFunc_c_Ref_123:
  Explanation: LusEventIndex is taken care that it will give right
  value asEventIndex comes from EventId and EventId can never be zero
  otherwise it will give DET.

  **Polyspace InternalFunc_c_Ref_124:
  Explanation: LusEventParameterIndex is taken care that it will give right
  value as EventParameterIndex comes from EventId and EventId can never be zero
  otherwise it will give DET.

  **Polyspace InternalFunc_c_Ref_125:
  Explanation: aaEdData[LucCount] is taken care that it will give right
  value as LucCount is taken care that it should not exceed NumOfEDRecords.

  **Polyspace InternalFunc_c_Ref_126:
  Explanation: LusEventParameterIndex is taken care that it will give right
  value as EventParameterIndex comes from EventId and EventId can never be zero
  otherwise it will give DET.

  **Polyspace InternalFunc_c_Ref_127:
  Explanation: aaFfData[LucCount] is taken care that it will give right
  value as LucCount is taken care that it should not exceed NumOfFFRecNum or
  MaxNumOfFFRecord .

  **Polyspace InternalFunc_c_Ref_128:
  Explanation: LusEventParameterIndex is taken care that it will give right
  value as EventParameterIndex comes from EventId and EventId can never be zero
  otherwise it will give DET.

  **Polyspace InternalFunc_c_Ref_129:
  Explanation: LusEventParameterIndex is taken care that it will give right
  value as EventParameterIndex comes from EventId and EventId can never be zero
  otherwise it will give DET.

  **Polyspace InternalFunc_c_Ref_137:
  Explanation: aaFfData[LucRecordCount] is taken care that it will give right
  value as LucCount is taken care that it should not exceed NumOfFFRecNum or
  MaxNumOfFFRecord .

  **Polyspace InternalFunc_c_Ref_138:
  Explanation: LusEventParameterIndex is taken care that it will give right
  value as EventParameterIndex comes from EventId and EventId can never be zero
  otherwise it will give DET.

  **Polyspace InternalFunc_c_Ref_139:
  Explanation: aaFfData[LucRecordIndex] is taken care that it will give right
  value as LucCount is taken care that it should not exceed NumOfFFRecNum or
  MaxNumOfFFRecord .

  **Polyspace InternalFunc_c_Ref_140:
  Explanation: *BufSize will give DET error if it is zero .

  **Polyspace InternalFunc_c_Ref_141:
  Explanation: *DestBuffer will give DET error if it is zero .

  **Polyspace InternalFunc_c_Ref_142:
  Explanation: aaFfData[LucRecordIndex] is taken care that it will give right
  value as LucCount is taken care that it should not exceed NumOfFFRecNum or
  MaxNumOfFFRecord .

  **Polyspace InternalFunc_c_Ref_143:
  Explanation: *DestBuffer will give DET error if it is zero .

  **Polyspace InternalFunc_c_Ref_144:
  Explanation: aaFfData[LucRecordIndex] is taken care that it will give right
  value as LucCount is taken care that it should not exceed NumOfFFRecNum or
  MaxNumOfFFRecord .

  **Polyspace InternalFunc_c_Ref_145 :
  Explanation: aaFfData[LucRecordIndex] is taken care that it will give right
  value as LucCount is taken care that it should not exceed NumOfFFRecNum or
  MaxNumOfFFRecord .

  **Polyspace InternalFunc_c_Ref_146:
  Explanation: *DestBuffer will give DET error if it is zero .

  **Polyspace InternalFunc_c_Ref_147:
  Explanation: aaDid is taken care that it should give remain within limit .

  **Polyspace InternalFunc_c_Ref_148:
  Explanation: [(LucRecordIndex * LucNoOfDids) + LucCount][DEM_ZERO] is taken
  care that it should give remain within limit .

  **Polyspace InternalFunc_c_Ref_149:
  Explanation: *DestBuffer will give DET error if it is zero .

  **Polyspace InternalFunc_c_Ref_150:
  Explanation: [(LucRecordIndex * LucNoOfDids) + LucCount][DEM_ONE] is taken
  care that it should give remain within limit .

  **Polyspace InternalFunc_c_Ref_151:
  Explanation: [(LucRecordIndex * LucNoOfDids) + LucCount][DEM_TWO] is taken
  care that it should give remain within limit .

  **Polyspace InternalFunc_c_Ref_152:
  Explanation: [(LucRecordIndex * LucNoOfDids) + LucCount][DEM_THREE] is taken
  care that it should give remain within limit .

  **Polyspace InternalFunc_c_Ref_153:
  Explanation: *DestBuffer will give DET error if it is zero .

  **Polyspace InternalFunc_c_Ref_154:
  Explanation: aaDid((LucRecordIndex X LucNoOfDids) + LucCount]
 [DEM_FOUR + LusCount1]is taken care that it should give remain within limit .

 **Polyspace InternalFunc_c_Ref_155:
  Explanation: LusCount1 is taken care that it should not exceed LusSize  .

  **Polyspace InternalFunc_c_Ref_156:
  Explanation: *BufSize will give DET error if it is zero .

  **Polyspace InternalFunc_c_Ref_157:
  Explanation: *DestBuffer will give DET error if it is zero .

  **Polyspace InternalFunc_c_Ref_158:
  Explanation: *DestBuffer will give DET error if it is zero .

  **Polyspace InternalFunc_c_Ref_180:
  Explanation: ucNumOfFF is taken care in generation that it will give right
  value.

  **Polyspace InternalFunc_c_Ref_181:
  Explanation: LusCurDidLoc is taken care that it will give right
  value.

  **Polyspace InternalFunc_c_Ref_182:
  Explanation: [DEM_FOUR + LusDidSize] is taken care that it will give right
  value since LusDidSize is checked for its boundary conditions.

  **Polyspace InternalFunc_c_Ref_183:
  Explanation: [DEM_FOUR + LusDidSize] is taken care that it will give right
  value since LusDidSize is checked for its boundary conditions.

  **Polyspace InternalFunc_c_Ref_184:
  Explanation: LucStorageIndex is taken care that it will give right
  value .

  **Polyspace InternalFunc_c_Ref_189:
  Explanation: Dem_GaaEDRecord[LucActualRecordIndex] is taken care that it will
  give right value .

  **Polyspace InternalFunc_c_Ref_190:
  Explanation: [Dem_GaaDTCFormat] is taken care that it will
  give right value from Dem_GaaDTCAttributes.

  **Polyspace InternalFunc_c_Ref_191:
  Explanation: Dem_GaaEDRecord[LucActualRecordIndex] is taken care that it will
  give right value .

  **Polyspace InternalFunc_c_Ref_192:
  Explanation: Dem_GaaEventParameter[LusEventIndex] is taken care that it will
  give right value .

  **Polyspace InternalFunc_c_Ref_193:
  Explanation: [Dem_GaaDTCFormat] is taken care that it will
  give right value from Dem_GaaDTCAttributes.

  **Polyspace InternalFunc_c_Ref_194:
  Explanation: [Dem_GaaNumOfFilteredDtc] is taken care that it will
  give right value .

  **Polyspace InternalFunc_c_Ref_195:
  Explanation: [Dem_GaaNumOfFilteredDtc] is taken care that it will
  give right value .

  **Polyspace InternalFunc_c_Ref_196:
  Polyspace Warning 18.4: The +, -, += and -= operators should not be applied to
  an expression of pointer type.
  Explanation:Refer Dem_InternalFunc_c_REF_QAC_3
  This part of code has verified manually and has no side-effect.

  **Polyspace InternalFunc_c_Ref_198:
  Polyspace Warning 17.8:A function parameter should not be modified.
  Explanation:This part of code has verified manually and has no side-effect.

  **Polyspace InternalFunc_c_Ref_199:
  Polyspace Warning 11.5:A conversion should not be performed from pointer to
  void into pointer to object.
  Explanation:This part of code has verified manually and has no side-effect.

  **Polyspace InternalFunc_c_Ref_200:
  Polyspace Warning 8.13: A pointer should point to a const-qualified type
  whenever possible.
  Explanation:Refer Dem_InternalFunc_c_REF_QAC_7
  This part of code has verified manually and has no side-effect.

  **Polyspace InternalFunc_c_Ref_201:
  Polyspace Warning D5.1:External identifiers shall be distinct.
  Explanation:This part of code has verified manually and has no side-effect.

  **Polyspace InternalFunc_c_Ref_202:
  Explanation: If condition will be covered for both true and false based on
  sequence of execution of functions and different conditions. However, this
  part of code has been verified Manually and has no side effect.

  **Polyspace InternalFunc_c_Ref_203:
  Explanation: This part of code has been verified Manually and has no
  side effect.

  **Polyspace InternalFunc_c_Ref_204:
  Polyspace Warning 18.1:A pointer resulting from arithmetic on a pointer
  operand shall address an element of the same array as that pointer operand.
  Explanation:This part of code has verified manually and has no side-effect.

  **Polyspace InternalFunc_c_Ref_205:
  Explanation: This part of code has been verified Manually and has no
  side effect.

  **Polyspace InternalFunc_c_Ref_206:
  Explanation: If condition will be covered for both true and false based on
  sequence of execution of functions and different conditions. However, this
  part of code has been verified Manually and has no side effect.

  **Polyspace InternalFunc_c_Ref_207:
  Explanation: LucEventCount comes input value from
  Dem_ProcAgCntrAfterThresholdSatified and it is taken care that it will give
  right value.
**/
/*******************************************************************************
**                      Parasoft MISRA Violations                             **
**                                                                            **
*******************************************************************************/
/* parasoft-end-suppress MISRAC2012-RULE_20_1-a-4 
"Reason: Dem_InternalFunc_c_REF_1" */

/* parasoft-end-suppress MISRAC2012-RULE_5_4-c-2 
"Reason: Dem_InternalFunc_c_REF_6" */

/* parasoft-end-suppress MISRAC2012-RULE_1_1-c-2
"Reason: Dem_InternalFunc_c_REF_7" */

/* parasoft-end-suppress MISRAC2012-RULE_1_1-b-2
"Reason: Dem_InternalFunc_c_REF_2" */

/* parasoft-end-suppress MISRAC2012-RULE_1_1-a-2
  "Reason: Dem_InternalFunc_c_REF_3" */
  
/* parasoft-end-suppress MISRAC2012-DIR_4_4-b-4 
"Refer Dem_InternalFunc_c_REF_4" */

/* parasoft-end-suppress CERT_C-DCL19-a-3 
"Reason: Dem_InternalFunc_c_REF_5" */

/* parasoft-end-suppress CERT_C-EXP08-a-2 CERT_C-ARR39-b-2
"Reason: Dem_InternalFunc_c_REF_13" */

/* parasoft-end-suppress MISRAC2012-RULE_5_4-d-2 
"Reason: Dem_InternalFunc_c_REF_15" */

/* parasoft-end-suppress MISRAC2012-RULE_18_4-a-4
"Reason: Dem_InternalFunc_c_REF_18" */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
