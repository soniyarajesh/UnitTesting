/*****************************************************************************/
/*                            Cantata Test Script                            */
/*****************************************************************************/
/*
 *    Filename: Cfg_28_Dem_InternalFunc.c
 *    Author: kiranm11
 *    Generated on: 08-Dec-2022 19:26:08
 *    Generated from: Dem_InternalFunc.c
 */
/*****************************************************************************/
/* Environment Definition                                                    */
/*****************************************************************************/

#define TEST_SCRIPT_GENERATOR 2

/* Include files from software under test */
#include "../../../Dem_Memory.h"
#include "../../../Rte_NvM_Type.h"
#include "../../../Det.h"
#include "string.h"
#include "../../../Dem_WwhObdProcsg.h"
#include "../../../Dem_EvtProcsg.h"
#include "../../../Dem_Error.h"
#include "../../../Dem_StaticInlineFunc.h"
#define DEM_START_SEC_CODE 
#include "../../../Dem_MemMap.h"

#define CANTATA_DEFAULT_VALUE 0 /* Default value of variables & stub returns */

#include <cantpp.h>  /* Cantata Directives */
/* pragma qas cantata testscript start */
/*****************************************************************************/
/* Global Data Definitions                                                   */
/*****************************************************************************/

/* Global Functions */

extern void Dem_EventSearchInMemory(Dem_EventIdType EventParameterIndex, uint8 * PMemMapIndx);
extern void Dem_InitNVData_Internal();
extern Std_ReturnType Dem_DTCFilterSearch(uint16 LusDtcInfoIndex, uint16 LusDTCOrgin, uint8 LucClientId);
extern void Dem_SearchDtc(uint16 LusDtcInfoIndex, uint16 * LpEventParameterIndex);
extern Std_ReturnType Dem_FilterEvent(uint16 LusEventIndex, uint8 LucClientId);
extern void Dem_DtcAttrSearchInMemory(const Dem_DTCAttributeType * LpDTCAttribute, uint8 * PMemMapIndx);
extern Std_ReturnType Dem_ProcessDataElementSize(uint16 LusDataIndex, uint8 LucDataElementType, uint8 * LpSize);
extern void Dem_GetSizeOfRecNoFFandFE(uint16 LusEventParameterIndex, uint16 * LpSizeOfExtendedDataRecord, uint8 ExtendedDataNumber, const Dem_EventMemory * LpEventMemory);
extern Std_ReturnType Dem_ProcessClearSingleDTC();
extern void Dem_GetSizeOfEDRecordForEvent(uint8 LucFreeIndex, uint16 * LpBufSize, uint8 ExtendedDataNumber, const Dem_EventMemory * LpEventMemory);
extern Std_ReturnType Dem_CheckExtendedDataRecord(uint8 RecordNumber, uint8 LucServiceId, uint8 * DestBuffer, uint16 * BufSize, const Dem_EventMemory * LpEventMemory, const Dem_DTCAttributeType * LpDTCAttribute, uint8 LucFreeIndex, uint8 LucNumOfEDRecords, boolean * LblRecFound);
Std_ReturnType ISOLATE_Std_ReturnType_func_ptr_sint8_p(sint8 * FaultDetectionCounter);
void SuspendAllInterrupts();
void ResumeAllInterrupts();
void Dem_ClearMasterEventPrestoreBuffer(Dem_EventIdType EventId);
Std_ReturnType Det_ReportRuntimeError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
Std_ReturnType Dem_GetDidData(const Dem_EventMemory * LpEventMemory, uint8 * DestBuffer, uint8 LucMemoryIndex, uint16 DataId, uint8 RecordIndex);
Std_ReturnType Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
Std_ReturnType Dem_ClearAllEvents();
Std_ReturnType Dem_ClearGroupEvents(const uint16 * LpEventIndexs, uint16 LusNumOfEvts);
void Dem_RearrangeOldEvtsInd(uint8 LucCurOldEvtInd, uint8 LucNumberOfEntries, Dem_EventMemory * LpOldEvtCnt);
void Dem_ClearRecordTriggers(Dem_EventIdType EventIndex);
Std_ReturnType Dem_GetFFDidData(const Dem_EventMemory * LpEventMemory, uint8 * DestBuffer, uint8 LucMemoryIndex, uint16 DataId, uint8 RecordIndex, uint16 * BufSize);
extern void ACCESS_FUNCTION_Dem_InternalFunc_Dem_ResetChronologicalorder(uint16 LusEventParameterIndex);
extern void ACCESS_FUNCTION_Dem_InternalFunc_Dem_ProcessOccurenceCounter(uint16 LusEventParameterIndex);
extern void ACCESS_FUNCTION_Dem_InternalFunc_Dem_UnusedDebounceRoutine(Dem_EventStatusType * LpEventStatus, Std_ReturnType * LpReturnValue, uint16 LusEventParameterIndex);
extern void ACCESS_FUNCTION_Dem_InternalFunc_Dem_ProcessTriggerIfFdcThresholdReached(uint16 LusEventParameterIndex);
extern void Dem_StartupNVOperation();
extern void Dem_FaultcheckInConfig(uint8 LucClientId);
extern void Dem_UnusedFilterRoutine(uint8 LucClientId);
extern Std_ReturnType Dem_UnusedDataReadRoutine(uint8 * LpData);
extern Std_ReturnType Dem_UnusedMonitorDataReadRoutine(uint8 * LpData, Dem_MonitorDataType monitorData0);
extern Std_ReturnType Dem_UnusedCallBackGetFDCRoutine(sint8 * FaultDetectionCounter);
extern void Dem_UnusedDataCaptureRoutine(Dem_EventIdType LusEventParameterIndex, Dem_EventStatusType LddEventStatus);
extern Std_ReturnType Dem_SetEventStatus_Invalid_Routine(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);
extern Std_ReturnType Dem_GetFaultDetectionCounter_Invalid_Routine(Dem_EventIdType EventId, sint8 * FaultDetectionCounter);
extern Std_ReturnType Dem_PrestoreFreezeFrame_Invalid_Routine(Dem_EventIdType EventId);
extern Std_ReturnType Dem_ClearPrestoreFreezeFrame_Invalid_Routine(Dem_EventIdType EventId);
extern void Dem_LoadPrestoredDid(Dem_EventMemory * LpEventMemory, const Dem_PrestoreBuffer * LpPFFBuffer, uint8 LucRecordIndexInMem);
extern void Dem_ClearPFFEntry(uint8 LucPFFBufferIndex);
extern Std_ReturnType Dem_EnvironmentalDataCheck(uint16 LusDtcInfoIndex, Dem_DTCOriginType LusDtcOrigin, boolean * LblEventExistInMemory, Dem_EventMemory ** LpEventMemory, uint8 * LpStoredIndex);
extern boolean Dem_DtcCheckInMem(uint8 ClientId, uint32 DTC, const Dem_EventMemory * LpEventMemory, uint8 LucMaxNumOfEventEntry, uint16 * LpEvtParameterIndx, uint8 * LpEventMemoryIndex);
extern void Dem_FaultcheckInMemory(uint8 LucClientId);
extern void Dem_RecordNumberCheckInMemory(uint8 LucClientId);
extern void Dem_GetMaxFdcOfDtc(uint8 * LpDestBuffer, uint16 LusEventParameterIndex);
extern void Dem_EvaluateInternalExtdDataRcdIfOccOrAging(uint8 LucDataElement, Dem_DTCOriginType LucEventDestination, uint8 * LpCurrentBufferIndex, uint8 LucFreeIndex, uint8 * DestBuffer, const Dem_DTCAttributeType * LpDTCAttribute);
extern Std_ReturnType Dem_SearchInMemory(uint8 RecordNumber, uint8 LucMemoryIndex, boolean * LblRecordFound, uint16 DataId, const Dem_EventMemory * LpEventMemory, uint8 * LpDestBuffer, const Dem_DTCAttributeType * LpDTCAttribute);
extern Std_ReturnType Dem_CheckforValidRecord(uint8 RecordNumber, uint8 LucServiceId, uint16 DataId, const Dem_DTCAttributeType * LpDTCAttribute);
extern Std_ReturnType Dem_GetFreezeFrameDataFromEvtMemory(const Dem_EventMemory * LpEventMemory, uint8 * DestBuffer, uint16 * BufSize, uint8 LucEventMemoryIndex, uint8 RecordNumber, uint8 LucClientId, boolean * LblRecordFound);
extern Std_ReturnType Dem_GetSizeOfRecord(uint8 RecordNumber, uint16 * LpSizeOfFreezeFrame, uint8 LucEventMemoryIndex, const Dem_EventMemory * LpEventMemory);
extern Std_ReturnType Dem_GetExtendedDataRecordByDTCExistInMem(uint8 * LpRecNumberStored, uint16 LusEventParameterIndex, const Dem_EventMemory * LpEventMemory, uint8 LucStoredIndex, uint8 ExtendedDataNumber, uint16 * LpBufSize, uint8 * LpDestBuffer, Dem_DTCOriginType DTCOrigin, uint16 * LpDestBuffIndx);
extern Std_ReturnType Dem_GetExtendedDataRecordByDTCVAlidButNotInMem(uint16 LusDTCAttributeIndex, uint8 ExtendedDataNumber, uint16 * LpBufSize);
extern Std_ReturnType Dem_GetSizeOfExtendedDataRecordByDTCFoundInMem(uint8 ExtendedDataNumber, uint16 * LpSizeOfExtendedDataRecord, const Dem_EventMemory * LpEventMemory, uint16 LusEventParameterIndex, uint8 LucEventMemoryIndex);
extern Std_ReturnType Dem_GetSizeOfExtendedDataRecordByDTCNotFoundInMem(uint16 LusDtcInfoIndex, uint8 ExtendedDataNumber, uint16 * LpSizeOfExtendedDataRecord);
extern void Dem_ResetFdc(uint16 LusEventIndex);
extern Std_ReturnType Dem_DTCFilterDetCheck(uint8 ClientId, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin, Dem_DTCSeverityType DTCSeverityMask);
extern void Dem_ProcessAsyncServiceRequest();
extern void Dem_ProcAgCntrAfterThresholdSatified(Dem_EventMemory * LpEventMemory, uint8 LucMemMappingIndx, uint8 LucMaxNumOfEventEntry, uint16 LusEventParameterIndex, uint8 LucEventCount);
extern void Dem_ProcAgCntrAfterThrSatifiedTfslc(uint16 LusEventParameterIndex);
extern Std_ReturnType Dem_GetEDRecordEx(Dem_EventIdType EventId, uint8 RecordNumber, uint8 * DestBuffer, uint16 * BufSize);
extern Std_ReturnType Dem_SearchRecInMem(uint8 RecordNumber, uint8 LucFreeIndex, boolean * LblRecordFound, uint16 DataId, const Dem_EventMemory * LpEventMemory, uint8 * LpDestBuffer, const Dem_DTCAttributeType * LpDTCAttribute, uint16 * BufSize);
extern StatusType GetSpinlock(SpinlockIdType SpinlockId);
extern StatusType ReleaseSpinlock(SpinlockIdType SpinlockId);
extern uint8 Dem_GaaEvtPreConditions[DEM_NUMBER_OF_EVENTS];
extern void Dem_DtcStatusChange(const Dem_DTCAttributeType * LpDTCAttribute, uint16 LusEventParameterIndex);
extern Std_ReturnType Dem_ResetEventStatusMultiEventTriggering(uint16 LusEventParameterIndex);
extern Std_ReturnType Dem_ResetEventDebounceStatusMultiEventTriggering(uint16 LusEventParameterIndex, Dem_DebounceResetStatusType DebounceResetStatus);


/* Global data */
uint8 Dem_GucVolatileClrDtc;
uint8 Dem_GaaEvtPreConditions[DEM_NUMBER_OF_EVENTS];
Dem_DtcInfo Dem_GaaDtcInfo[0x6U];
sint8 Dem_GaaAllFDC[0xaU];
uint8 Dem_GaaAllDtcStatus[0x6U];
uint8 Dem_GaaDTCFormat[1U];
Dem_DTCAttributeType Dem_GaaDTCAttributes[0x6U];
uint8 Dem_GaaCurDTCFilterStatusMask[1U];
uint16 Dem_GaaCurDTCFilter[1U];
Dem_DTCOriginPtrAddressType Dem_GaaDTCOriginBasedPtrAddress[1U];
Dem_EventMemory Dem_GstDefaultEventMemory;
uint8 Dem_GaaAllEvtStatus[0xaU];
uint16 Dem_GaaDTCOccurenceTime[1U][0x4U];
boolean Dem_GaaOperationCycleState[0x1U];
boolean Dem_GaaDefaultOperationCycleState[0x1U];
uint8 Dem_GaaEventFailureCounter[0xaU];
uint8 Dem_GaaOldEvtCntHeadTailIndex[1U][0x2U];
uint16 Dem_GaaDtcMainEvent[0x6U];
Dem_PrestoreBuffer Dem_GaaPrestoreBuffer[4U];
uint16 Dem_GaaOriginFilter[1U];
boolean Dem_GaaSuppressionStatus[0x6U];
uint16 Dem_GaaMatchingDtcIndex[0x6U];
uint16 Dem_GaaNumOfFilteredDtc[1U];
uint8 Dem_GaaChronlgOrdReq[1U];
Dem_EventParameterType Dem_GaaEventParameter[0xaU];
Dem_ExtendedDataRecordType Dem_GaaEDRecord[0x1U];
Dem_DataElementExternalCSType Dem_GaaDataElementExternalCS[1U];
uint8 Dem_GaaDTCOriginMappingIndx[5U];
uint8 Dem_GaaMemoryIndexForEvt[0xaU];
uint16 Dem_GaaEventToDTCIndexMapping[0xaU];
Dem_DebounceMonitorInternalType Dem_GaaMonitorInternalDebounceClass[0xaU];
uint8 Dem_GaaOriginMemMappingIndex[1U];
uint8 Dem_GaaRecordNumber[1U];
Dem_EventOBDReadinessGroupType Dem_GaaReadinessGroup[1U];
Dem_DidRecordType Dem_GaaDid[0x1];
Dem_ClientSelectionType Dem_GaaClientSelection[1U];
Dem_FreezeFrameRecordType Dem_GaaFreezeFrameRecord[1U];
Dem_ClientListType Dem_GaaClientList[1U];
Dem_DtcAsyncServiceStat Dem_GstDtcAsyncServiceStat;
boolean Dem_GblFDCBufferUpdateFlag_Satellite_1;
uint8 Dem_GaaAvailableMemIndexs[1U][3U];
uint8 Dem_GaaMemFreeStackIndx[1U];
Dem_DTCAttributeType map_Dem_GaaEventParameter_0_pDTCAttribute[1]; /* Generated by Cantata */
Dem_EventMemory map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[86]; /* Generated by Cantata */
Dem_EventStatusType map_LpEventStatus[1]; /* Generated by Cantata */
Std_ReturnType map_LpReturnValue[1]; /* Generated by Cantata */
uint8 map_LpData[1]; /* Generated by Cantata */
uint8 map_LpData_1[1]; /* Generated by Cantata */
sint8 map_FaultDetectionCounter[1]; /* Generated by Cantata */
sint8 map_FaultDetectionCounter_1[1]; /* Generated by Cantata */
uint16 map_LpEventParameterIndex[1]; /* Generated by Cantata */
Dem_EventMemory map_LpEventMemory[1]; /* Generated by Cantata */
uint16 map_LpSizeOfExtendedDataRecord[1]; /* Generated by Cantata */
Dem_EventMemory map_LpEventMemory_1[1]; /* Generated by Cantata */
Dem_PrestoreBuffer map_LpPFFBuffer[1]; /* Generated by Cantata */
uint8 map_LpSize[1]; /* Generated by Cantata */
Dem_EventMemory* map_LpEventMemory_2[1]; /* Generated by Cantata */
uint8 map_LpStoredIndex[1]; /* Generated by Cantata */
boolean map_LblEventExistInMemory[1]; /* Generated by Cantata */
Dem_EventMemory map_LpEventMemory_3[6]; /* Generated by Cantata */
uint16 map_LpEvtParameterIndx[1]; /* Generated by Cantata */
uint8 map_LpEventMemoryIndex[1]; /* Generated by Cantata */
Dem_DTCAttributeType map_ResumeAllInterrupts_call1_Dem_GaaEventParameter_0_pDTCAttribute[1]; /* Generated by Cantata */
Dem_DTCAttributeType map_ResumeAllInterrupts_call2_Dem_GaaEventParameter_0_pDTCAttribute[1]; /* Generated by Cantata */
uint8 map_LpDestBuffer[1]; /* Generated by Cantata */
boolean map_LblRecFound[1]; /* Generated by Cantata */
Dem_EventMemory map_LpEventMemory_4[86]; /* Generated by Cantata */
Dem_DTCAttributeType map_LpDTCAttribute[1]; /* Generated by Cantata */
uint16 map_BufSize[1]; /* Generated by Cantata */
uint8 map_DestBuffer[1]; /* Generated by Cantata */
Dem_DTCAttributeType map_LpDTCAttribute_1[1]; /* Generated by Cantata */
uint8 map_LpCurrentBufferIndex[1]; /* Generated by Cantata */
uint8 map_DestBuffer_1[256]; /* Generated by Cantata */
Dem_DTCAttributeType map_LpDTCAttribute_2[1]; /* Generated by Cantata */
boolean map_LblRecordFound[1]; /* Generated by Cantata */
Dem_EventMemory map_LpEventMemory_5[86]; /* Generated by Cantata */
Dem_DTCAttributeType map_LpDTCAttribute_3[1]; /* Generated by Cantata */
Dem_EventMemory map_LpEventMemory_6[86]; /* Generated by Cantata */
uint16 map_BufSize_1[1]; /* Generated by Cantata */
boolean map_LblRecordFound_1[1]; /* Generated by Cantata */
uint8 map_DestBuffer_2[5]; /* Generated by Cantata */
Dem_EventMemory map_LpEventMemory_7[86]; /* Generated by Cantata */
uint16 map_LpSizeOfFreezeFrame[1]; /* Generated by Cantata */
Dem_DTCAttributeType map_Dem_DtcAttrSearchInMemory_call1_Dem_GaaEventParameter_0_pDTCAttribute[1]; /* Generated by Cantata */
uint16 map_LpDestBuffIndx[1]; /* Generated by Cantata */
Dem_EventMemory map_LpEventMemory_8[86]; /* Generated by Cantata */
uint16 map_LpBufSize[1]; /* Generated by Cantata */
uint8 map_LpRecNumberStored[1]; /* Generated by Cantata */
uint8 map_LpDestBuffer_1[1]; /* Generated by Cantata */
uint16 map_LpBufSize_1[1]; /* Generated by Cantata */
Dem_EventMemory map_LpEventMemory_9[86]; /* Generated by Cantata */
uint16 map_LpSizeOfExtendedDataRecord_1[1]; /* Generated by Cantata */
uint16 map_LpSizeOfExtendedDataRecord_2[1]; /* Generated by Cantata */
Dem_EventMemorySetType map_Dem_GaaClientList_0_pEventMemorySet[1]; /* Generated by Cantata */
Dem_EventMemory map_LpEventMemory_10[86]; /* Generated by Cantata */
uint16 map_BufSize_2[1]; /* Generated by Cantata */
Dem_EventMemory map_LpEventMemory_11[86]; /* Generated by Cantata */
uint16 map_LpBufSize_2[1]; /* Generated by Cantata */
Dem_DTCAttributeType map_LpDTCAttribute_4[1]; /* Generated by Cantata */
boolean map_LblRecordFound_2[1]; /* Generated by Cantata */
Dem_EventMemory map_LpEventMemory_12[86]; /* Generated by Cantata */
uint8 map_PMemMapIndx[1]; /* Generated by Cantata */
uint8 map_PMemMapIndx_1[1]; /* Generated by Cantata */
Dem_DTCAttributeType map_LpDTCAttribute_5[1]; /* Generated by Cantata */
Dem_EvtBitArrayMapType Dem_GaaEvtBitArrayMap[DEM_NUMBER_OF_EVENTS];
uint8 Dem_GaaPrimaryTrigger[DEM_BIT_ARRAY_SIZE_FOR_EVENTS];
SpinlockIdType OsSpinlock_0;
uint8 Dem_GaaAllMonitorStatus[DEM_NUMBER_OF_EVENTS];
Dem_EDRecordListType Dem_GaaEDRecordNumberList [DEM_MAX_NUMBER_OF_UNIQUE_ED_RECDS];
Dem_AlgorithmParameterType Dem_GaaDebounceAlgorithm[DEM_NUMBER_OF_EVENTS];
uint8  Dem_GaaServiceInProcess[DEM_MAX_MEMORY_ID_CONF + DEM_ONE];

/* Expected variables for global data */
uint8 expected_Dem_GucVolatileClrDtc;
uint8 expected_Dem_GaaServiceInProcess[DEM_MAX_MEMORY_ID_CONF + DEM_ONE];
Dem_AlgorithmParameterType expected_Dem_GaaDebounceAlgorithm[DEM_NUMBER_OF_EVENTS];
Dem_EDRecordListType expected_Dem_GaaEDRecordNumberList [DEM_MAX_NUMBER_OF_UNIQUE_ED_RECDS];
uint8 expected_Dem_GaaEvtPreConditions[DEM_NUMBER_OF_EVENTS];
uint8 expected_Dem_GaaAllMonitorStatus[DEM_NUMBER_OF_EVENTS];
SpinlockIdType expected_OsSpinlock_0;
Dem_EvtBitArrayMapType expected_Dem_GaaEvtBitArrayMap[DEM_NUMBER_OF_EVENTS];
uint8 expected_Dem_GaaPrimaryTrigger[DEM_BIT_ARRAY_SIZE_FOR_EVENTS];
Dem_DtcInfo expected_Dem_GaaDtcInfo[0x6U];
sint8 expected_Dem_GaaAllFDC[0xaU];
uint8 expected_Dem_GaaAllDtcStatus[0x6U];
uint8 expected_Dem_GaaDTCFormat[1U];
Dem_DTCAttributeType expected_Dem_GaaDTCAttributes[0x6U];
uint8 expected_Dem_GaaCurDTCFilterStatusMask[1U];
uint16 expected_Dem_GaaCurDTCFilter[1U];
Dem_DTCOriginPtrAddressType expected_Dem_GaaDTCOriginBasedPtrAddress[1U];
Dem_EventMemory expected_Dem_GstDefaultEventMemory;
uint8 expected_Dem_GaaAllEvtStatus[0xaU];
uint16 expected_Dem_GaaDTCOccurenceTime[1U][0x4U];
boolean expected_Dem_GaaOperationCycleState[0x1U];
boolean expected_Dem_GaaDefaultOperationCycleState[0x1U];
uint8 expected_Dem_GaaEventFailureCounter[0xaU];
uint8 expected_Dem_GaaOldEvtCntHeadTailIndex[1U][0x2U];
uint16 expected_Dem_GaaDtcMainEvent[0x6U];
Dem_PrestoreBuffer expected_Dem_GaaPrestoreBuffer[4U];
uint16 expected_Dem_GaaOriginFilter[1U];
boolean expected_Dem_GaaSuppressionStatus[0x6U];
uint16 expected_Dem_GaaMatchingDtcIndex[0x6U];
uint16 expected_Dem_GaaNumOfFilteredDtc[1U];
uint8 expected_Dem_GaaChronlgOrdReq[1U];
Dem_EventParameterType expected_Dem_GaaEventParameter[0xaU];
Dem_ExtendedDataRecordType expected_Dem_GaaEDRecord[0x1U];
Dem_DataElementExternalCSType expected_Dem_GaaDataElementExternalCS[1U];
uint8 expected_Dem_GaaDTCOriginMappingIndx[5U];
uint8 expected_Dem_GaaMemoryIndexForEvt[0xaU];
uint16 expected_Dem_GaaEventToDTCIndexMapping[0xaU];
Dem_DebounceMonitorInternalType expected_Dem_GaaMonitorInternalDebounceClass[0xaU];
uint8 expected_Dem_GaaOriginMemMappingIndex[1U];
uint8 expected_Dem_GaaRecordNumber[1U];
Dem_EventOBDReadinessGroupType expected_Dem_GaaReadinessGroup[1U];
Dem_DidRecordType expected_Dem_GaaDid[0x1];
Dem_ClientSelectionType expected_Dem_GaaClientSelection[1U];
Dem_FreezeFrameRecordType expected_Dem_GaaFreezeFrameRecord[1U];
Dem_ClientListType expected_Dem_GaaClientList[1U];
Dem_DtcAsyncServiceStat expected_Dem_GstDtcAsyncServiceStat;
boolean expected_Dem_GblFDCBufferUpdateFlag_Satellite_1;
uint8 expected_Dem_GaaAvailableMemIndexs[1U][3U];
uint8 expected_Dem_GaaMemFreeStackIndx[1U];
Dem_DTCAttributeType expected_map_Dem_GaaEventParameter_0_pDTCAttribute[1];
Dem_EventMemory expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[86];
Dem_EventStatusType expected_map_LpEventStatus[1];
Std_ReturnType expected_map_LpReturnValue[1];
uint8 expected_map_LpData[1];
uint8 expected_map_LpData_1[1];
sint8 expected_map_FaultDetectionCounter[1];
sint8 expected_map_FaultDetectionCounter_1[1];
uint16 expected_map_LpEventParameterIndex[1];
Dem_EventMemory expected_map_LpEventMemory[1];
uint16 expected_map_LpSizeOfExtendedDataRecord[1];
Dem_EventMemory expected_map_LpEventMemory_1[1];
Dem_PrestoreBuffer expected_map_LpPFFBuffer[1];
uint8 expected_map_LpSize[1];
Dem_EventMemory* expected_map_LpEventMemory_2[1];
uint8 expected_map_LpStoredIndex[1];
boolean expected_map_LblEventExistInMemory[1];
Dem_EventMemory expected_map_LpEventMemory_3[6];
uint16 expected_map_LpEvtParameterIndx[1];
uint8 expected_map_LpEventMemoryIndex[1];
Dem_DTCAttributeType expected_map_ResumeAllInterrupts_call1_Dem_GaaEventParameter_0_pDTCAttribute[1];
Dem_DTCAttributeType expected_map_ResumeAllInterrupts_call2_Dem_GaaEventParameter_0_pDTCAttribute[1];
uint8 expected_map_LpDestBuffer[1];
boolean expected_map_LblRecFound[1];
Dem_EventMemory expected_map_LpEventMemory_4[86];
Dem_DTCAttributeType expected_map_LpDTCAttribute[1];
uint16 expected_map_BufSize[1];
uint8 expected_map_DestBuffer[1];
Dem_DTCAttributeType expected_map_LpDTCAttribute_1[1];
uint8 expected_map_LpCurrentBufferIndex[1];
uint8 expected_map_DestBuffer_1[256];
Dem_DTCAttributeType expected_map_LpDTCAttribute_2[1];
boolean expected_map_LblRecordFound[1];
Dem_EventMemory expected_map_LpEventMemory_5[86];
Dem_DTCAttributeType expected_map_LpDTCAttribute_3[1];
Dem_EventMemory expected_map_LpEventMemory_6[86];
uint16 expected_map_BufSize_1[1];
boolean expected_map_LblRecordFound_1[1];
uint8 expected_map_DestBuffer_2[5];
Dem_EventMemory expected_map_LpEventMemory_7[86];
uint16 expected_map_LpSizeOfFreezeFrame[1];
Dem_DTCAttributeType expected_map_Dem_DtcAttrSearchInMemory_call1_Dem_GaaEventParameter_0_pDTCAttribute[1];
uint16 expected_map_LpDestBuffIndx[1];
Dem_EventMemory expected_map_LpEventMemory_8[86];
uint16 expected_map_LpBufSize[1];
uint8 expected_map_LpRecNumberStored[1];
uint8 expected_map_LpDestBuffer_1[1];
uint16 expected_map_LpBufSize_1[1];
Dem_EventMemory expected_map_LpEventMemory_9[86];
uint16 expected_map_LpSizeOfExtendedDataRecord_1[1];
uint16 expected_map_LpSizeOfExtendedDataRecord_2[1];
Dem_EventMemorySetType expected_map_Dem_GaaClientList_0_pEventMemorySet[1];
Dem_EventMemory expected_map_LpEventMemory_10[86];
uint16 expected_map_BufSize_2[1];
Dem_EventMemory expected_map_LpEventMemory_11[86];
uint16 expected_map_LpBufSize_2[1];
Dem_DTCAttributeType expected_map_LpDTCAttribute_4[1];
boolean expected_map_LblRecordFound_2[1];
Dem_EventMemory expected_map_LpEventMemory_12[86];
uint8 expected_map_PMemMapIndx[1];
uint8 expected_map_PMemMapIndx_1[1];
Dem_DTCAttributeType expected_map_LpDTCAttribute_5[1];

/* This function initialises global data to default values. This function       */
/* is called by every test case so must not contain test case specific settings */
static void initialise_global_data(){
    INITIALISE(Dem_GaaDtcInfo);
    INITIALISE(Dem_GaaAllFDC);
    INITIALISE(Dem_GaaAllDtcStatus);
    INITIALISE(Dem_GaaDTCFormat);
    INITIALISE(Dem_GaaDTCAttributes);
    INITIALISE(Dem_GaaCurDTCFilterStatusMask);
    INITIALISE(Dem_GaaCurDTCFilter);
    INITIALISE(Dem_GaaDTCOriginBasedPtrAddress);
    INITIALISE(Dem_GstDefaultEventMemory);
    INITIALISE(Dem_GaaAllEvtStatus);
    INITIALISE(Dem_GaaDTCOccurenceTime);
    INITIALISE(Dem_GaaOperationCycleState);
    INITIALISE(Dem_GaaDefaultOperationCycleState);
    INITIALISE(Dem_GaaEventFailureCounter);
    INITIALISE(Dem_GaaOldEvtCntHeadTailIndex);
    INITIALISE(Dem_GaaDtcMainEvent);
    INITIALISE(Dem_GaaPrestoreBuffer);
    INITIALISE(Dem_GaaOriginFilter);
    INITIALISE(Dem_GaaSuppressionStatus);
    INITIALISE(Dem_GaaMatchingDtcIndex);
    INITIALISE(Dem_GaaNumOfFilteredDtc);
    INITIALISE(Dem_GaaChronlgOrdReq);
    INITIALISE(Dem_GaaEventParameter);
    INITIALISE(Dem_GaaEDRecord);
    INITIALISE(Dem_GaaDataElementExternalCS);
    INITIALISE(Dem_GaaDTCOriginMappingIndx);
    INITIALISE(Dem_GaaMemoryIndexForEvt);
    INITIALISE(Dem_GaaEventToDTCIndexMapping);
    INITIALISE(Dem_GaaMonitorInternalDebounceClass);
    INITIALISE(Dem_GaaOriginMemMappingIndex);
    INITIALISE(Dem_GaaRecordNumber);
    INITIALISE(Dem_GaaReadinessGroup);
    INITIALISE(Dem_GaaDid);
    INITIALISE(Dem_GaaClientSelection);
    INITIALISE(Dem_GaaFreezeFrameRecord);
    INITIALISE(Dem_GaaClientList);
    INITIALISE(Dem_GstDtcAsyncServiceStat);
    INITIALISE(Dem_GblFDCBufferUpdateFlag_Satellite_1);
    INITIALISE(Dem_GaaAvailableMemIndexs);
    INITIALISE(Dem_GaaMemFreeStackIndx);
    INITIALISE(map_Dem_GaaEventParameter_0_pDTCAttribute);
    INITIALISE(map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory);
    INITIALISE(map_LpEventStatus);
    INITIALISE(map_LpReturnValue);
    INITIALISE(map_LpData);
    INITIALISE(map_LpData_1);
    INITIALISE(map_FaultDetectionCounter);
    INITIALISE(map_FaultDetectionCounter_1);
    INITIALISE(map_LpEventParameterIndex);
    INITIALISE(map_LpEventMemory);
    INITIALISE(map_LpSizeOfExtendedDataRecord);
    INITIALISE(map_LpEventMemory_1);
    INITIALISE(map_LpPFFBuffer);
    INITIALISE(map_LpSize);
    INITIALISE(map_LpEventMemory_2);
    INITIALISE(map_LpStoredIndex);
    INITIALISE(map_LblEventExistInMemory);
    INITIALISE(map_LpEventMemory_3);
    INITIALISE(map_LpEvtParameterIndx);
    INITIALISE(map_LpEventMemoryIndex);
    INITIALISE(map_ResumeAllInterrupts_call1_Dem_GaaEventParameter_0_pDTCAttribute);
    INITIALISE(map_ResumeAllInterrupts_call2_Dem_GaaEventParameter_0_pDTCAttribute);
    INITIALISE(map_LpDestBuffer);
    INITIALISE(map_LblRecFound);
    INITIALISE(map_LpEventMemory_4);
    INITIALISE(map_LpDTCAttribute);
    INITIALISE(map_BufSize);
    INITIALISE(map_DestBuffer);
    INITIALISE(map_LpDTCAttribute_1);
    INITIALISE(map_LpCurrentBufferIndex);
    INITIALISE(map_DestBuffer_1);
    INITIALISE(map_LpDTCAttribute_2);
    INITIALISE(map_LblRecordFound);
    INITIALISE(map_LpEventMemory_5);
    INITIALISE(map_LpDTCAttribute_3);
    INITIALISE(map_LpEventMemory_6);
    INITIALISE(map_BufSize_1);
    INITIALISE(map_LblRecordFound_1);
    INITIALISE(map_DestBuffer_2);
    INITIALISE(map_LpEventMemory_7);
    INITIALISE(map_LpSizeOfFreezeFrame);
    INITIALISE(map_Dem_DtcAttrSearchInMemory_call1_Dem_GaaEventParameter_0_pDTCAttribute);
    INITIALISE(map_LpDestBuffIndx);
    INITIALISE(map_LpEventMemory_8);
    INITIALISE(map_LpBufSize);
    INITIALISE(map_LpRecNumberStored);
    INITIALISE(map_LpDestBuffer_1);
    INITIALISE(map_LpBufSize_1);
    INITIALISE(map_LpEventMemory_9);
    INITIALISE(map_LpSizeOfExtendedDataRecord_1);
    INITIALISE(map_LpSizeOfExtendedDataRecord_2);
    INITIALISE(map_Dem_GaaClientList_0_pEventMemorySet);
    INITIALISE(map_LpEventMemory_10);
    INITIALISE(map_BufSize_2);
    INITIALISE(map_LpEventMemory_11);
    INITIALISE(map_LpBufSize_2);
    INITIALISE(map_LpDTCAttribute_4);
    INITIALISE(map_LblRecordFound_2);
    INITIALISE(map_LpEventMemory_12);
    INITIALISE(map_PMemMapIndx);
    INITIALISE(map_PMemMapIndx_1);
    INITIALISE(map_LpDTCAttribute_5);
}

/* This function copies the global data settings into expected variables for */
/* use in check_global_data(). It is called by every test case so must not   */
/* contain test case specific settings.                                      */
static void initialise_expected_global_data(){
    COPY_TO_EXPECTED(Dem_GaaDtcInfo, expected_Dem_GaaDtcInfo);
    COPY_TO_EXPECTED(Dem_GaaAllFDC, expected_Dem_GaaAllFDC);
    COPY_TO_EXPECTED(Dem_GaaAllDtcStatus, expected_Dem_GaaAllDtcStatus);
    COPY_TO_EXPECTED(Dem_GaaDTCFormat, expected_Dem_GaaDTCFormat);
    COPY_TO_EXPECTED(Dem_GaaDTCAttributes, expected_Dem_GaaDTCAttributes);
    COPY_TO_EXPECTED(Dem_GaaCurDTCFilterStatusMask, expected_Dem_GaaCurDTCFilterStatusMask);
    COPY_TO_EXPECTED(Dem_GaaCurDTCFilter, expected_Dem_GaaCurDTCFilter);
    COPY_TO_EXPECTED(Dem_GaaDTCOriginBasedPtrAddress, expected_Dem_GaaDTCOriginBasedPtrAddress);
    COPY_TO_EXPECTED(Dem_GstDefaultEventMemory, expected_Dem_GstDefaultEventMemory);
    COPY_TO_EXPECTED(Dem_GaaAllEvtStatus, expected_Dem_GaaAllEvtStatus);
    COPY_TO_EXPECTED(Dem_GaaDTCOccurenceTime, expected_Dem_GaaDTCOccurenceTime);
    COPY_TO_EXPECTED(Dem_GaaOperationCycleState, expected_Dem_GaaOperationCycleState);
    COPY_TO_EXPECTED(Dem_GaaDefaultOperationCycleState, expected_Dem_GaaDefaultOperationCycleState);
    COPY_TO_EXPECTED(Dem_GaaEventFailureCounter, expected_Dem_GaaEventFailureCounter);
    COPY_TO_EXPECTED(Dem_GaaOldEvtCntHeadTailIndex, expected_Dem_GaaOldEvtCntHeadTailIndex);
    COPY_TO_EXPECTED(Dem_GaaDtcMainEvent, expected_Dem_GaaDtcMainEvent);
    COPY_TO_EXPECTED(Dem_GaaPrestoreBuffer, expected_Dem_GaaPrestoreBuffer);
    COPY_TO_EXPECTED(Dem_GaaOriginFilter, expected_Dem_GaaOriginFilter);
    COPY_TO_EXPECTED(Dem_GaaSuppressionStatus, expected_Dem_GaaSuppressionStatus);
    COPY_TO_EXPECTED(Dem_GaaMatchingDtcIndex, expected_Dem_GaaMatchingDtcIndex);
    COPY_TO_EXPECTED(Dem_GaaNumOfFilteredDtc, expected_Dem_GaaNumOfFilteredDtc);
    COPY_TO_EXPECTED(Dem_GaaChronlgOrdReq, expected_Dem_GaaChronlgOrdReq);
    COPY_TO_EXPECTED(Dem_GaaEventParameter, expected_Dem_GaaEventParameter);
    COPY_TO_EXPECTED(Dem_GaaEDRecord, expected_Dem_GaaEDRecord);
    COPY_TO_EXPECTED(Dem_GaaDataElementExternalCS, expected_Dem_GaaDataElementExternalCS);
    COPY_TO_EXPECTED(Dem_GaaDTCOriginMappingIndx, expected_Dem_GaaDTCOriginMappingIndx);
    COPY_TO_EXPECTED(Dem_GaaMemoryIndexForEvt, expected_Dem_GaaMemoryIndexForEvt);
    COPY_TO_EXPECTED(Dem_GaaEventToDTCIndexMapping, expected_Dem_GaaEventToDTCIndexMapping);
    COPY_TO_EXPECTED(Dem_GaaMonitorInternalDebounceClass, expected_Dem_GaaMonitorInternalDebounceClass);
    COPY_TO_EXPECTED(Dem_GaaOriginMemMappingIndex, expected_Dem_GaaOriginMemMappingIndex);
    COPY_TO_EXPECTED(Dem_GaaRecordNumber, expected_Dem_GaaRecordNumber);
    COPY_TO_EXPECTED(Dem_GaaReadinessGroup, expected_Dem_GaaReadinessGroup);
    COPY_TO_EXPECTED(Dem_GaaDid, expected_Dem_GaaDid);
    COPY_TO_EXPECTED(Dem_GaaClientSelection, expected_Dem_GaaClientSelection);
    COPY_TO_EXPECTED(Dem_GaaFreezeFrameRecord, expected_Dem_GaaFreezeFrameRecord);
    COPY_TO_EXPECTED(Dem_GaaClientList, expected_Dem_GaaClientList);
    COPY_TO_EXPECTED(Dem_GstDtcAsyncServiceStat, expected_Dem_GstDtcAsyncServiceStat);
    COPY_TO_EXPECTED(Dem_GblFDCBufferUpdateFlag_Satellite_1, expected_Dem_GblFDCBufferUpdateFlag_Satellite_1);
    COPY_TO_EXPECTED(Dem_GaaAvailableMemIndexs, expected_Dem_GaaAvailableMemIndexs);
    COPY_TO_EXPECTED(Dem_GaaMemFreeStackIndx, expected_Dem_GaaMemFreeStackIndx);
    COPY_TO_EXPECTED(map_Dem_GaaEventParameter_0_pDTCAttribute, expected_map_Dem_GaaEventParameter_0_pDTCAttribute);
    COPY_TO_EXPECTED(map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory, expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory);
    COPY_TO_EXPECTED(map_LpEventStatus, expected_map_LpEventStatus);
    COPY_TO_EXPECTED(map_LpReturnValue, expected_map_LpReturnValue);
    COPY_TO_EXPECTED(map_LpData, expected_map_LpData);
    COPY_TO_EXPECTED(map_LpData_1, expected_map_LpData_1);
    COPY_TO_EXPECTED(map_FaultDetectionCounter, expected_map_FaultDetectionCounter);
    COPY_TO_EXPECTED(map_FaultDetectionCounter_1, expected_map_FaultDetectionCounter_1);
    COPY_TO_EXPECTED(map_LpEventParameterIndex, expected_map_LpEventParameterIndex);
    COPY_TO_EXPECTED(map_LpEventMemory, expected_map_LpEventMemory);
    COPY_TO_EXPECTED(map_LpSizeOfExtendedDataRecord, expected_map_LpSizeOfExtendedDataRecord);
    COPY_TO_EXPECTED(map_LpEventMemory_1, expected_map_LpEventMemory_1);
    COPY_TO_EXPECTED(map_LpPFFBuffer, expected_map_LpPFFBuffer);
    COPY_TO_EXPECTED(map_LpSize, expected_map_LpSize);
    COPY_TO_EXPECTED(map_LpEventMemory_2, expected_map_LpEventMemory_2);
    COPY_TO_EXPECTED(map_LpStoredIndex, expected_map_LpStoredIndex);
    COPY_TO_EXPECTED(map_LblEventExistInMemory, expected_map_LblEventExistInMemory);
    COPY_TO_EXPECTED(map_LpEventMemory_3, expected_map_LpEventMemory_3);
    COPY_TO_EXPECTED(map_LpEvtParameterIndx, expected_map_LpEvtParameterIndx);
    COPY_TO_EXPECTED(map_LpEventMemoryIndex, expected_map_LpEventMemoryIndex);
    COPY_TO_EXPECTED(map_ResumeAllInterrupts_call1_Dem_GaaEventParameter_0_pDTCAttribute, expected_map_ResumeAllInterrupts_call1_Dem_GaaEventParameter_0_pDTCAttribute);
    COPY_TO_EXPECTED(map_ResumeAllInterrupts_call2_Dem_GaaEventParameter_0_pDTCAttribute, expected_map_ResumeAllInterrupts_call2_Dem_GaaEventParameter_0_pDTCAttribute);
    COPY_TO_EXPECTED(map_LpDestBuffer, expected_map_LpDestBuffer);
    COPY_TO_EXPECTED(map_LblRecFound, expected_map_LblRecFound);
    COPY_TO_EXPECTED(map_LpEventMemory_4, expected_map_LpEventMemory_4);
    COPY_TO_EXPECTED(map_LpDTCAttribute, expected_map_LpDTCAttribute);
    COPY_TO_EXPECTED(map_BufSize, expected_map_BufSize);
    COPY_TO_EXPECTED(map_DestBuffer, expected_map_DestBuffer);
    COPY_TO_EXPECTED(map_LpDTCAttribute_1, expected_map_LpDTCAttribute_1);
    COPY_TO_EXPECTED(map_LpCurrentBufferIndex, expected_map_LpCurrentBufferIndex);
    COPY_TO_EXPECTED(map_DestBuffer_1, expected_map_DestBuffer_1);
    COPY_TO_EXPECTED(map_LpDTCAttribute_2, expected_map_LpDTCAttribute_2);
    COPY_TO_EXPECTED(map_LblRecordFound, expected_map_LblRecordFound);
    COPY_TO_EXPECTED(map_LpEventMemory_5, expected_map_LpEventMemory_5);
    COPY_TO_EXPECTED(map_LpDTCAttribute_3, expected_map_LpDTCAttribute_3);
    COPY_TO_EXPECTED(map_LpEventMemory_6, expected_map_LpEventMemory_6);
    COPY_TO_EXPECTED(map_BufSize_1, expected_map_BufSize_1);
    COPY_TO_EXPECTED(map_LblRecordFound_1, expected_map_LblRecordFound_1);
    COPY_TO_EXPECTED(map_DestBuffer_2, expected_map_DestBuffer_2);
    COPY_TO_EXPECTED(map_LpEventMemory_7, expected_map_LpEventMemory_7);
    COPY_TO_EXPECTED(map_LpSizeOfFreezeFrame, expected_map_LpSizeOfFreezeFrame);
    COPY_TO_EXPECTED(map_Dem_DtcAttrSearchInMemory_call1_Dem_GaaEventParameter_0_pDTCAttribute, expected_map_Dem_DtcAttrSearchInMemory_call1_Dem_GaaEventParameter_0_pDTCAttribute);
    COPY_TO_EXPECTED(map_LpDestBuffIndx, expected_map_LpDestBuffIndx);
    COPY_TO_EXPECTED(map_LpEventMemory_8, expected_map_LpEventMemory_8);
    COPY_TO_EXPECTED(map_LpBufSize, expected_map_LpBufSize);
    COPY_TO_EXPECTED(map_LpRecNumberStored, expected_map_LpRecNumberStored);
    COPY_TO_EXPECTED(map_LpDestBuffer_1, expected_map_LpDestBuffer_1);
    COPY_TO_EXPECTED(map_LpBufSize_1, expected_map_LpBufSize_1);
    COPY_TO_EXPECTED(map_LpEventMemory_9, expected_map_LpEventMemory_9);
    COPY_TO_EXPECTED(map_LpSizeOfExtendedDataRecord_1, expected_map_LpSizeOfExtendedDataRecord_1);
    COPY_TO_EXPECTED(map_LpSizeOfExtendedDataRecord_2, expected_map_LpSizeOfExtendedDataRecord_2);
    COPY_TO_EXPECTED(map_Dem_GaaClientList_0_pEventMemorySet, expected_map_Dem_GaaClientList_0_pEventMemorySet);
    COPY_TO_EXPECTED(map_LpEventMemory_10, expected_map_LpEventMemory_10);
    COPY_TO_EXPECTED(map_BufSize_2, expected_map_BufSize_2);
    COPY_TO_EXPECTED(map_LpEventMemory_11, expected_map_LpEventMemory_11);
    COPY_TO_EXPECTED(map_LpBufSize_2, expected_map_LpBufSize_2);
    COPY_TO_EXPECTED(map_LpDTCAttribute_4, expected_map_LpDTCAttribute_4);
    COPY_TO_EXPECTED(map_LblRecordFound_2, expected_map_LblRecordFound_2);
    COPY_TO_EXPECTED(map_LpEventMemory_12, expected_map_LpEventMemory_12);
    COPY_TO_EXPECTED(map_PMemMapIndx, expected_map_PMemMapIndx);
    COPY_TO_EXPECTED(map_PMemMapIndx_1, expected_map_PMemMapIndx_1);
    COPY_TO_EXPECTED(map_LpDTCAttribute_5, expected_map_LpDTCAttribute_5);
}

/* This function checks global data against the expected values. */
static void check_global_data(){
    CHECK_MEMORY("Dem_GaaDtcInfo", Dem_GaaDtcInfo, expected_Dem_GaaDtcInfo, sizeof(expected_Dem_GaaDtcInfo));
    CHECK_MEMORY("Dem_GaaAllFDC", Dem_GaaAllFDC, expected_Dem_GaaAllFDC, sizeof(expected_Dem_GaaAllFDC));
    CHECK_MEMORY("Dem_GaaAllDtcStatus", Dem_GaaAllDtcStatus, expected_Dem_GaaAllDtcStatus, sizeof(expected_Dem_GaaAllDtcStatus));
    CHECK_MEMORY("Dem_GaaDTCFormat", Dem_GaaDTCFormat, expected_Dem_GaaDTCFormat, sizeof(expected_Dem_GaaDTCFormat));
    CHECK_MEMORY("Dem_GaaDTCAttributes", Dem_GaaDTCAttributes, expected_Dem_GaaDTCAttributes, sizeof(expected_Dem_GaaDTCAttributes));
    CHECK_MEMORY("Dem_GaaCurDTCFilterStatusMask", Dem_GaaCurDTCFilterStatusMask, expected_Dem_GaaCurDTCFilterStatusMask, sizeof(expected_Dem_GaaCurDTCFilterStatusMask));
    CHECK_MEMORY("Dem_GaaCurDTCFilter", Dem_GaaCurDTCFilter, expected_Dem_GaaCurDTCFilter, sizeof(expected_Dem_GaaCurDTCFilter));
    CHECK_MEMORY("Dem_GaaDTCOriginBasedPtrAddress", Dem_GaaDTCOriginBasedPtrAddress, expected_Dem_GaaDTCOriginBasedPtrAddress, sizeof(expected_Dem_GaaDTCOriginBasedPtrAddress));
    CHECK_MEMORY("Dem_GstDefaultEventMemory", &Dem_GstDefaultEventMemory, &expected_Dem_GstDefaultEventMemory, sizeof(expected_Dem_GstDefaultEventMemory));
    CHECK_MEMORY("Dem_GaaAllEvtStatus", Dem_GaaAllEvtStatus, expected_Dem_GaaAllEvtStatus, sizeof(expected_Dem_GaaAllEvtStatus));
    CHECK_MEMORY("Dem_GaaDTCOccurenceTime", Dem_GaaDTCOccurenceTime, expected_Dem_GaaDTCOccurenceTime, sizeof(expected_Dem_GaaDTCOccurenceTime));
    CHECK_MEMORY("Dem_GaaOperationCycleState", Dem_GaaOperationCycleState, expected_Dem_GaaOperationCycleState, sizeof(expected_Dem_GaaOperationCycleState));
    CHECK_MEMORY("Dem_GaaDefaultOperationCycleState", Dem_GaaDefaultOperationCycleState, expected_Dem_GaaDefaultOperationCycleState, sizeof(expected_Dem_GaaDefaultOperationCycleState));
    CHECK_MEMORY("Dem_GaaEventFailureCounter", Dem_GaaEventFailureCounter, expected_Dem_GaaEventFailureCounter, sizeof(expected_Dem_GaaEventFailureCounter));
//    CHECK_MEMORY("Dem_GaaOldEvtCntHeadTailIndex", Dem_GaaOldEvtCntHeadTailIndex, expected_Dem_GaaOldEvtCntHeadTailIndex, sizeof(expected_Dem_GaaOldEvtCntHeadTailIndex));
    CHECK_MEMORY("Dem_GaaDtcMainEvent", Dem_GaaDtcMainEvent, expected_Dem_GaaDtcMainEvent, sizeof(expected_Dem_GaaDtcMainEvent));
//    CHECK_MEMORY("Dem_GaaPrestoreBuffer", Dem_GaaPrestoreBuffer, expected_Dem_GaaPrestoreBuffer, sizeof(expected_Dem_GaaPrestoreBuffer));
    CHECK_MEMORY("Dem_GaaOriginFilter", Dem_GaaOriginFilter, expected_Dem_GaaOriginFilter, sizeof(expected_Dem_GaaOriginFilter));
    CHECK_MEMORY("Dem_GaaSuppressionStatus", Dem_GaaSuppressionStatus, expected_Dem_GaaSuppressionStatus, sizeof(expected_Dem_GaaSuppressionStatus));
    CHECK_MEMORY("Dem_GaaMatchingDtcIndex", Dem_GaaMatchingDtcIndex, expected_Dem_GaaMatchingDtcIndex, sizeof(expected_Dem_GaaMatchingDtcIndex));
    CHECK_MEMORY("Dem_GaaNumOfFilteredDtc", Dem_GaaNumOfFilteredDtc, expected_Dem_GaaNumOfFilteredDtc, sizeof(expected_Dem_GaaNumOfFilteredDtc));
    CHECK_MEMORY("Dem_GaaChronlgOrdReq", Dem_GaaChronlgOrdReq, expected_Dem_GaaChronlgOrdReq, sizeof(expected_Dem_GaaChronlgOrdReq));
    CHECK_MEMORY("Dem_GaaEventParameter", Dem_GaaEventParameter, expected_Dem_GaaEventParameter, sizeof(expected_Dem_GaaEventParameter));
    CHECK_MEMORY("Dem_GaaEDRecord", Dem_GaaEDRecord, expected_Dem_GaaEDRecord, sizeof(expected_Dem_GaaEDRecord));
    CHECK_MEMORY("Dem_GaaDataElementExternalCS", Dem_GaaDataElementExternalCS, expected_Dem_GaaDataElementExternalCS, sizeof(expected_Dem_GaaDataElementExternalCS));
    CHECK_MEMORY("Dem_GaaDTCOriginMappingIndx", Dem_GaaDTCOriginMappingIndx, expected_Dem_GaaDTCOriginMappingIndx, sizeof(expected_Dem_GaaDTCOriginMappingIndx));
    CHECK_MEMORY("Dem_GaaMemoryIndexForEvt", Dem_GaaMemoryIndexForEvt, expected_Dem_GaaMemoryIndexForEvt, sizeof(expected_Dem_GaaMemoryIndexForEvt));
    CHECK_MEMORY("Dem_GaaEventToDTCIndexMapping", Dem_GaaEventToDTCIndexMapping, expected_Dem_GaaEventToDTCIndexMapping, sizeof(expected_Dem_GaaEventToDTCIndexMapping));
    CHECK_MEMORY("Dem_GaaMonitorInternalDebounceClass", Dem_GaaMonitorInternalDebounceClass, expected_Dem_GaaMonitorInternalDebounceClass, sizeof(expected_Dem_GaaMonitorInternalDebounceClass));
    CHECK_MEMORY("Dem_GaaOriginMemMappingIndex", Dem_GaaOriginMemMappingIndex, expected_Dem_GaaOriginMemMappingIndex, sizeof(expected_Dem_GaaOriginMemMappingIndex));
    CHECK_MEMORY("Dem_GaaRecordNumber", Dem_GaaRecordNumber, expected_Dem_GaaRecordNumber, sizeof(expected_Dem_GaaRecordNumber));
    CHECK_MEMORY("Dem_GaaReadinessGroup", Dem_GaaReadinessGroup, expected_Dem_GaaReadinessGroup, sizeof(expected_Dem_GaaReadinessGroup));
    CHECK_MEMORY("Dem_GaaDid", Dem_GaaDid, expected_Dem_GaaDid, sizeof(expected_Dem_GaaDid));
    CHECK_MEMORY("Dem_GaaClientSelection", Dem_GaaClientSelection, expected_Dem_GaaClientSelection, sizeof(expected_Dem_GaaClientSelection));
    CHECK_MEMORY("Dem_GaaFreezeFrameRecord", Dem_GaaFreezeFrameRecord, expected_Dem_GaaFreezeFrameRecord, sizeof(expected_Dem_GaaFreezeFrameRecord));
    CHECK_MEMORY("Dem_GaaClientList", Dem_GaaClientList, expected_Dem_GaaClientList, sizeof(expected_Dem_GaaClientList));
    CHECK_MEMORY("Dem_GstDtcAsyncServiceStat", &Dem_GstDtcAsyncServiceStat, &expected_Dem_GstDtcAsyncServiceStat, sizeof(expected_Dem_GstDtcAsyncServiceStat));
    CHECK_U_CHAR(Dem_GblFDCBufferUpdateFlag_Satellite_1, expected_Dem_GblFDCBufferUpdateFlag_Satellite_1);
    CHECK_MEMORY("Dem_GaaAvailableMemIndexs", Dem_GaaAvailableMemIndexs, expected_Dem_GaaAvailableMemIndexs, sizeof(expected_Dem_GaaAvailableMemIndexs));
    CHECK_MEMORY("Dem_GaaMemFreeStackIndx", Dem_GaaMemFreeStackIndx, expected_Dem_GaaMemFreeStackIndx, sizeof(expected_Dem_GaaMemFreeStackIndx));
    CHECK_MEMORY("map_Dem_GaaEventParameter_0_pDTCAttribute", map_Dem_GaaEventParameter_0_pDTCAttribute, expected_map_Dem_GaaEventParameter_0_pDTCAttribute, sizeof(expected_map_Dem_GaaEventParameter_0_pDTCAttribute));
//    CHECK_MEMORY("map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory", map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory, expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory, sizeof(expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory));
    CHECK_MEMORY("map_LpEventStatus", map_LpEventStatus, expected_map_LpEventStatus, sizeof(expected_map_LpEventStatus));
    CHECK_MEMORY("map_LpReturnValue", map_LpReturnValue, expected_map_LpReturnValue, sizeof(expected_map_LpReturnValue));
    CHECK_MEMORY("map_LpData", map_LpData, expected_map_LpData, sizeof(expected_map_LpData));
    CHECK_MEMORY("map_LpData_1", map_LpData_1, expected_map_LpData_1, sizeof(expected_map_LpData_1));
    CHECK_MEMORY("map_FaultDetectionCounter", map_FaultDetectionCounter, expected_map_FaultDetectionCounter, sizeof(expected_map_FaultDetectionCounter));
    CHECK_MEMORY("map_FaultDetectionCounter_1", map_FaultDetectionCounter_1, expected_map_FaultDetectionCounter_1, sizeof(expected_map_FaultDetectionCounter_1));
    CHECK_MEMORY("map_LpEventParameterIndex", map_LpEventParameterIndex, expected_map_LpEventParameterIndex, sizeof(expected_map_LpEventParameterIndex));
    CHECK_MEMORY("map_LpEventMemory", map_LpEventMemory, expected_map_LpEventMemory, sizeof(expected_map_LpEventMemory));
    CHECK_MEMORY("map_LpSizeOfExtendedDataRecord", map_LpSizeOfExtendedDataRecord, expected_map_LpSizeOfExtendedDataRecord, sizeof(expected_map_LpSizeOfExtendedDataRecord));
    CHECK_MEMORY("map_LpEventMemory_1", map_LpEventMemory_1, expected_map_LpEventMemory_1, sizeof(expected_map_LpEventMemory_1));
    CHECK_MEMORY("map_LpPFFBuffer", map_LpPFFBuffer, expected_map_LpPFFBuffer, sizeof(expected_map_LpPFFBuffer));
    CHECK_MEMORY("map_LpSize", map_LpSize, expected_map_LpSize, sizeof(expected_map_LpSize));
    CHECK_MEMORY("map_LpEventMemory_2", map_LpEventMemory_2, expected_map_LpEventMemory_2, sizeof(expected_map_LpEventMemory_2));
    CHECK_MEMORY("map_LpStoredIndex", map_LpStoredIndex, expected_map_LpStoredIndex, sizeof(expected_map_LpStoredIndex));
    CHECK_MEMORY("map_LblEventExistInMemory", map_LblEventExistInMemory, expected_map_LblEventExistInMemory, sizeof(expected_map_LblEventExistInMemory));
    CHECK_MEMORY("map_LpEventMemory_3", map_LpEventMemory_3, expected_map_LpEventMemory_3, sizeof(expected_map_LpEventMemory_3));
    CHECK_MEMORY("map_ResumeAllInterrupts_call1_Dem_GaaEventParameter_0_pDTCAttribute", map_ResumeAllInterrupts_call1_Dem_GaaEventParameter_0_pDTCAttribute, expected_map_ResumeAllInterrupts_call1_Dem_GaaEventParameter_0_pDTCAttribute, sizeof(expected_map_ResumeAllInterrupts_call1_Dem_GaaEventParameter_0_pDTCAttribute));
    CHECK_MEMORY("map_ResumeAllInterrupts_call2_Dem_GaaEventParameter_0_pDTCAttribute", map_ResumeAllInterrupts_call2_Dem_GaaEventParameter_0_pDTCAttribute, expected_map_ResumeAllInterrupts_call2_Dem_GaaEventParameter_0_pDTCAttribute, sizeof(expected_map_ResumeAllInterrupts_call2_Dem_GaaEventParameter_0_pDTCAttribute));
    CHECK_MEMORY("map_LpDestBuffer", map_LpDestBuffer, expected_map_LpDestBuffer, sizeof(expected_map_LpDestBuffer));
    CHECK_MEMORY("map_LblRecFound", map_LblRecFound, expected_map_LblRecFound, sizeof(expected_map_LblRecFound));
    CHECK_MEMORY("map_LpEventMemory_4", map_LpEventMemory_4, expected_map_LpEventMemory_4, sizeof(expected_map_LpEventMemory_4));
    CHECK_MEMORY("map_LpDTCAttribute", map_LpDTCAttribute, expected_map_LpDTCAttribute, sizeof(expected_map_LpDTCAttribute));
    CHECK_MEMORY("map_BufSize", map_BufSize, expected_map_BufSize, sizeof(expected_map_BufSize));
    CHECK_MEMORY("map_DestBuffer", map_DestBuffer, expected_map_DestBuffer, sizeof(expected_map_DestBuffer));
    CHECK_MEMORY("map_LpDTCAttribute_1", map_LpDTCAttribute_1, expected_map_LpDTCAttribute_1, sizeof(expected_map_LpDTCAttribute_1));
    CHECK_MEMORY("map_LpCurrentBufferIndex", map_LpCurrentBufferIndex, expected_map_LpCurrentBufferIndex, sizeof(expected_map_LpCurrentBufferIndex));
//    CHECK_MEMORY("map_DestBuffer_1", map_DestBuffer_1, expected_map_DestBuffer_1, sizeof(expected_map_DestBuffer_1));
    CHECK_MEMORY("map_LpDTCAttribute_2", map_LpDTCAttribute_2, expected_map_LpDTCAttribute_2, sizeof(expected_map_LpDTCAttribute_2));
    CHECK_MEMORY("map_LblRecordFound", map_LblRecordFound, expected_map_LblRecordFound, sizeof(expected_map_LblRecordFound));
    CHECK_MEMORY("map_LpEventMemory_5", map_LpEventMemory_5, expected_map_LpEventMemory_5, sizeof(expected_map_LpEventMemory_5));
    CHECK_MEMORY("map_LpDTCAttribute_3", map_LpDTCAttribute_3, expected_map_LpDTCAttribute_3, sizeof(expected_map_LpDTCAttribute_3));
    CHECK_MEMORY("map_LpEventMemory_6", map_LpEventMemory_6, expected_map_LpEventMemory_6, sizeof(expected_map_LpEventMemory_6));
    CHECK_MEMORY("map_BufSize_1", map_BufSize_1, expected_map_BufSize_1, sizeof(expected_map_BufSize_1));
    CHECK_MEMORY("map_LblRecordFound_1", map_LblRecordFound_1, expected_map_LblRecordFound_1, sizeof(expected_map_LblRecordFound_1));
    CHECK_MEMORY("map_DestBuffer_2", map_DestBuffer_2, expected_map_DestBuffer_2, sizeof(expected_map_DestBuffer_2));
    CHECK_MEMORY("map_LpEventMemory_7", map_LpEventMemory_7, expected_map_LpEventMemory_7, sizeof(expected_map_LpEventMemory_7));
    CHECK_MEMORY("map_LpSizeOfFreezeFrame", map_LpSizeOfFreezeFrame, expected_map_LpSizeOfFreezeFrame, sizeof(expected_map_LpSizeOfFreezeFrame));
    CHECK_MEMORY("map_Dem_DtcAttrSearchInMemory_call1_Dem_GaaEventParameter_0_pDTCAttribute", map_Dem_DtcAttrSearchInMemory_call1_Dem_GaaEventParameter_0_pDTCAttribute, expected_map_Dem_DtcAttrSearchInMemory_call1_Dem_GaaEventParameter_0_pDTCAttribute, sizeof(expected_map_Dem_DtcAttrSearchInMemory_call1_Dem_GaaEventParameter_0_pDTCAttribute));
    CHECK_MEMORY("map_LpDestBuffIndx", map_LpDestBuffIndx, expected_map_LpDestBuffIndx, sizeof(expected_map_LpDestBuffIndx));
    CHECK_MEMORY("map_LpEventMemory_8", map_LpEventMemory_8, expected_map_LpEventMemory_8, sizeof(expected_map_LpEventMemory_8));
    CHECK_MEMORY("map_LpBufSize", map_LpBufSize, expected_map_LpBufSize, sizeof(expected_map_LpBufSize));
    CHECK_MEMORY("map_LpRecNumberStored", map_LpRecNumberStored, expected_map_LpRecNumberStored, sizeof(expected_map_LpRecNumberStored));
    CHECK_MEMORY("map_LpDestBuffer_1", map_LpDestBuffer_1, expected_map_LpDestBuffer_1, sizeof(expected_map_LpDestBuffer_1));
    CHECK_MEMORY("map_LpBufSize_1", map_LpBufSize_1, expected_map_LpBufSize_1, sizeof(expected_map_LpBufSize_1));
    CHECK_MEMORY("map_LpEventMemory_9", map_LpEventMemory_9, expected_map_LpEventMemory_9, sizeof(expected_map_LpEventMemory_9));
    CHECK_MEMORY("map_LpSizeOfExtendedDataRecord_1", map_LpSizeOfExtendedDataRecord_1, expected_map_LpSizeOfExtendedDataRecord_1, sizeof(expected_map_LpSizeOfExtendedDataRecord_1));
    CHECK_MEMORY("map_LpSizeOfExtendedDataRecord_2", map_LpSizeOfExtendedDataRecord_2, expected_map_LpSizeOfExtendedDataRecord_2, sizeof(expected_map_LpSizeOfExtendedDataRecord_2));
    CHECK_MEMORY("map_Dem_GaaClientList_0_pEventMemorySet", map_Dem_GaaClientList_0_pEventMemorySet, expected_map_Dem_GaaClientList_0_pEventMemorySet, sizeof(expected_map_Dem_GaaClientList_0_pEventMemorySet));
    CHECK_MEMORY("map_LpEventMemory_10", map_LpEventMemory_10, expected_map_LpEventMemory_10, sizeof(expected_map_LpEventMemory_10));
    CHECK_MEMORY("map_BufSize_2", map_BufSize_2, expected_map_BufSize_2, sizeof(expected_map_BufSize_2));
    CHECK_MEMORY("map_LpEventMemory_11", map_LpEventMemory_11, expected_map_LpEventMemory_11, sizeof(expected_map_LpEventMemory_11));
    CHECK_MEMORY("map_LpBufSize_2", map_LpBufSize_2, expected_map_LpBufSize_2, sizeof(expected_map_LpBufSize_2));
    CHECK_MEMORY("map_LpDTCAttribute_4", map_LpDTCAttribute_4, expected_map_LpDTCAttribute_4, sizeof(expected_map_LpDTCAttribute_4));
    CHECK_MEMORY("map_LblRecordFound_2", map_LblRecordFound_2, expected_map_LblRecordFound_2, sizeof(expected_map_LblRecordFound_2));
    CHECK_MEMORY("map_LpEventMemory_12", map_LpEventMemory_12, expected_map_LpEventMemory_12, sizeof(expected_map_LpEventMemory_12));
    CHECK_MEMORY("map_PMemMapIndx", map_PMemMapIndx, expected_map_PMemMapIndx, sizeof(expected_map_PMemMapIndx));
    CHECK_MEMORY("map_PMemMapIndx_1", map_PMemMapIndx_1, expected_map_PMemMapIndx_1, sizeof(expected_map_PMemMapIndx_1));
    CHECK_MEMORY("map_LpDTCAttribute_5", map_LpDTCAttribute_5, expected_map_LpDTCAttribute_5, sizeof(expected_map_LpDTCAttribute_5));
}

/* Prototypes for test functions */
void run_tests();
void test_1(int);
void test_2(int);
void test_3(int);
void test_4(int);
void test_5(int);
void test_6(int);
void test_7(int);
void test_8(int);
void test_9(int);
void test_10(int);
void test_11(int);
void test_12(int);
void test_13(int);
void test_14(int);
void test_15(int);
void test_16(int);
void test_17(int);
void test_18(int);
void test_19(int);
void test_20(int);
void test_21(int);
void test_22(int);
void test_23(int);
void test_24(int);
void test_25(int);
void test_26(int);
void test_27(int);
void test_28(int);
void test_29(int);
void test_30(int);
void test_31(int);
void test_32(int);
void test_33(int);
void test_34(int);
void test_35(int);
void test_36(int);
void test_37(int);
void test_38(int);
void test_39(int);
void test_40(int);
void test_41(int);
void test_42(int);
void test_43(int);
void test_44(int);
void test_45(int);
void test_46(int);
void test_47(int);
void test_48(int);
void test_49(int);
void test_50(int);
void test_51(int);
void test_52(int);
void test_53(int);
void test_54(int);
void test_55(int);
void test_56(int);
void test_57(int);
void test_58(int);
void test_59(int);
void test_60(int);
void test_61(int);
void test_62(int);
void test_63(int);
void test_64(int);
void test_65(int);
void test_66(int);
void test_67(int);
void test_68(int);
void test_69(int);
void test_70(int);
void test_71(int);
void test_72(int);
void test_80(int);
void test_81(int);
void test_82(int);
void test_83(int);
void test_84(int);
void test_85(int);
void test_86(int);
void test_87(int);
void test_88(int);
void test_89(int);
void test_90(int);
void test_91(int);
void test_92(int);
void test_93(int);
void test_94(int);
void test_95(int);
void test_96(int);
void test_97(int);
void test_98(int);
void test_99(int);
void test_100(int);
void test_101(int);
void test_102(int);
void test_103(int);
void test_104(int);
void test_105(int);
void test_106(int);
void test_107(int);
void test_108(int);
void test_109(int);
void test_110(int);
void test_111(int);
void test_112(int);
void test_113(int);
void test_114(int);
void test_115(int);
void test_116(int);
void test_117(int);
void test_118(int);
void test_119(int);
void test_120(int);
void test_121(int);
void test_122(int);
void test_123(int);
void test_124(int);
void test_125(int);
void test_126(int);
void test_127(int);
void test_128(int);
void test_129(int);
void test_130(int);
void test_131(int);
void test_132(int);
void test_133(int);
void test_134(int);
void test_135(int);
void test_136(int);
void test_137(int);
void test_138(int);
void test_139(int);
void test_140(int);
void test_141(int);
void test_142(int);
void test_143(int);
void test_144(int);
void test_145(int);
void test_146(int);
void test_147(int);
void test_148(int);
void test_149(int);
void test_150(int);
void test_151(int);
void test_152(int);
void test_153(int);
void test_154(int);
void test_155(int);
void test_156(int);
void test_157(int);
void test_158(int);
void test_159(int);
void test_160(int);
void test_161(int);
void test_162(int);
void test_163(int);
void test_164(int);
void test_165(int);
void test_166(int);
void test_167(int);
void test_168(int);
void test_169(int);
void test_170(int);
void test_171(int);
void test_172(int);
void test_173(int);
void test_174(int);
void test_175(int);
void test_176(int);
void test_177(int);
void test_178(int);
void test_179(int);
void test_180(int);
void test_181(int);
void test_182(int);
void test_183(int);
void test_184(int);
void test_185(int);
void test_186(int);
void test_187(int);
void test_188(int);
void test_189(int);
void test_190(int);
void test_191(int);
void test_192(int);
void test_193(int);
void test_194(int);
void test_195(int);
void test_196(int);
void test_197(int);
void test_198(int);
void test_199(int);
void test_200(int);
void test_201(int);
void test_202(int);
void test_203(int);
void test_204(int);
void test_205(int);
void test_206(int);
void test_207(int);
void test_208(int);
void test_209(int);
void test_210(int);
void test_211(int);
void test_212(int);
void test_213(int);
void test_214(int);
void test_215(int);
void test_216(int);
void test_217(int);
void test_218(int);
void test_219(int);
void test_220(int);

/*****************************************************************************/
/* Coverage Analysis                                                         */
/*****************************************************************************/
/* Coverage Rule Set: KPIT_RuleSet Entry Point, Statement, Call Return, Decision, Relational , Loop Coverage and MCDC Coverage */
static void rule_set(char* cppca_sut,
                     char* cppca_context)
{
    START_TEST("COVERAGE RULE SET",
               "KPIT_RuleSet Entry Point, Statement, Call Return, Decision, Relational , Loop Coverage and MCDC Coverage");
#ifdef CANTPP_SUBSET_DEFERRED_ANALYSIS
    TEST_SCRIPT_WARNING("Coverage Rule Set ignored in deferred analysis mode\n");
#elif CANTPP_COVERAGE_INSTRUMENTATION_DISABLED
    TEST_SCRIPT_WARNING("Coverage Instrumentation has been disabled\n");
#elif CANTPP_INSTRUMENTATION_DISABLED
    TEST_SCRIPT_WARNING("Instrumentation has been disabled\n");
#else
    ANALYSIS_CHECK("100% Entry Point Coverage",
                   cppca_entrypoint_cov,
                   00.0);
    
    ANALYSIS_CHECK("100% Statement Coverage",
                   cppca_statement_cov,
                   00.0);
    
    ANALYSIS_CHECK("100% Call Return Coverage",
                   cppca_callreturn_cov,
                   00.0);
    
    ANALYSIS_CHECK("100% Decision Coverage",
                   cppca_decision_cov,
                   00.0);
    
    ANALYSIS_CHECK("100% Boolean Operand Effectiveness Coverage",
                   cppca_booleff_cov,
                   00.0);
    			   
    ANALYSIS_CHECK("100% Relational Coverage",
                   cppca_relational_cov,
                   00.0);
    
    ANALYSIS_CHECK("100% Loop Coverage",
                   cppca_loop_cov,
                   00.0);
    
    REPORT_COVERAGE(cppca_entrypoint_cov|
                    cppca_statement_cov|
                    cppca_callreturn_cov|
                    cppca_decision_cov|
                    cppca_booleff_cov|
    				cppca_relational_cov|
                    cppca_loop_cov,
                    cppca_sut,
                    cppca_all_details|cppca_include_catch,
                    cppca_context);
#endif
    END_TEST();
}

/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
int main()
{
    CONFIGURE_COVERAGE("cov:boolcomb:yes");
    OPEN_LOG("Cfg_28_Dem_InternalFunc.ctr", false, 100);
    START_SCRIPT("Dem_InternalFunc", true);

    run_tests();

    return !END_SCRIPT(true);
}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void run_tests()
{
    test_1(1);
    test_2(1);
    test_3(1);
    test_4(1);
    test_5(1);
    test_6(1);
    test_7(1);
    test_8(1);
    test_9(1);
    test_10(1);
    test_11(1);
    test_12(1);
    test_13(1);
    test_14(1);
    test_15(1);
    test_16(1);
    test_17(1);
    test_18(1);
    test_19(1);
    test_20(1);
    test_21(1);
    test_22(1);
    test_23(1);
    test_24(1);
    test_25(1);
    test_26(1);
    test_27(1);
    test_28(1);
    test_29(1);
    test_30(1);
    test_31(1);
    test_32(1);
    test_33(1);
    test_34(1);
    test_35(1);
    test_36(1);
    test_37(1);
    test_38(1);
    test_39(1);
    test_40(1);
    test_41(1);
    test_42(1);
    test_43(1);
    test_44(1);
    test_45(1);
    test_46(1);
    test_47(1);
    test_48(1);
    test_49(1);
    test_50(1);
    test_51(1);
    test_52(1);
    test_53(1);
    test_54(1);
    test_55(1);
    test_56(1);
    test_57(1);
    test_58(1);
    test_59(1);
    test_60(1);
    test_61(1);
    test_62(1);
    test_63(1);
    test_64(1);
    test_65(1);
    test_66(0);
    test_67(0);
    test_68(0);
    test_69(0);
    test_70(0);
    test_71(0);
    test_72(0);
    test_80(1);
    test_81(1);
    test_82(1);
    test_83(1);
    test_84(1);
    test_85(1);
    test_86(1);
    test_87(1);
    test_88(1);
    test_89(1);
    test_90(1);
    test_91(1);
    test_92(1);
    test_93(1);
    test_94(1);
    test_95(1);
    test_96(1);
    test_97(1);
    test_98(1);
    test_99(1);
    test_100(1);
    test_101(1);
    test_102(1);
    test_103(1);
    test_104(1);
    test_105(1);
    test_106(0);
    test_107(0);
    test_108(0);
    test_109(0);
    test_110(0);
    test_111(1);
    test_112(1);
    test_113(1);
    test_114(1);
    test_115(1);
    test_116(1);
    test_117(1);
    test_118(1);
    test_119(1);
    test_120(1);
    test_121(1);
    test_122(1);
    test_123(0);
    test_124(0);
    test_125(0);
    test_126(0);
    test_127(0);
    test_128(0);
    test_129(0);
    test_130(0);
    test_131(0);
    test_132(0);
    test_133(0);
    test_134(0);
    test_135(0);
    test_136(0);
    test_137(0);
    test_138(0);
    test_139(0);
    test_140(0);
    test_141(0);
    test_142(0);
    test_143(0);
    test_144(1);
    test_145(1);
    test_146(1);
    test_147(1);
    test_148(1);
    test_149(1);
    test_150(1);
    test_151(1);
    test_152(1);
    test_153(1);
    test_154(1);
    test_155(1);
    test_156(1);
    test_157(1);
    test_158(1);
    test_159(1);
    test_160(1);
    test_161(1);
    test_162(1);
    test_163(1);
    test_164(1);
    test_165(1);
    test_166(1);
    test_167(1);
    test_168(1);
    test_169(1);
    test_170(1);
    test_171(1);
    test_172(1);
    test_173(1);
    test_174(1);
    test_175(1);
    test_176(1);
    test_177(1);
    test_178(1);
    test_179(1);
    test_180(1);
    test_181(1);
    test_182(1);
    test_183(1);
    test_184(1);
    test_185(1);
    test_186(1);
    test_187(1);
    test_188(1);
    test_189(1);
    test_190(1);
    test_191(1);
    test_192(1);
    test_193(1);
    test_194(1);
    test_195(1);
    test_196(1);
    test_197(1);
    test_198(1);
    test_199(1);
    test_200(1);
    test_201(1);
    test_202(1);
    test_203(1);
    test_204(1);
    test_205(1);
    test_206(1);
    test_207(1);
    test_208(1);
    test_209(1);
    test_210(1);
    test_211(1);
    test_212(1);
    test_213(1);
    test_214(1);
    test_215(1);
    test_216(1);
    test_217(1);
    test_218(1);
    test_219(1);
    test_220(1);

    rule_set("*", "*");
    EXPORT_COVERAGE("Cfg_28_Dem_InternalFunc.cov", cppca_export_replace);
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/

void test_1(int doIt)  {
if (doIt) {
    /* Set global data */

    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    Dem_GaaOldEvtCntHeadTailIndex[0][0] = 85U;
    Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    Dem_GaaMemoryIndexForEvt[0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][0] = 85U;
    expected_Dem_GaaMemoryIndexForEvt[0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucNextEventIdIndex = 255U;

    START_TEST("1: Dem_ResetChronologicalorder",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            ACCESS_FUNCTION(Dem_InternalFunc, Dem_ResetChronologicalorder)(LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_2(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    Dem_GaaOldEvtCntHeadTailIndex[0][0] = 0U;
    Dem_GaaOldEvtCntHeadTailIndex[0][1] = 1U;
    Dem_GaaMemoryIndexForEvt[0] = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0].ucNextEventIdIndex = 85U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaMemoryIndexForEvt[0] = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][0] = 85U;
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][1] = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0].ucPreviousIndex = 1U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0].ucNextEventIdIndex = 255U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[1].ucNextEventIdIndex = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 255U;

    START_TEST("2: Dem_ResetChronologicalorder",
               "created to solve true case of LucTailIndex != LucEvtMemoryIndex at line number 338");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            ACCESS_FUNCTION(Dem_InternalFunc, Dem_ResetChronologicalorder)(LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_3(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    Dem_GaaOldEvtCntHeadTailIndex[0][0] = 0U;
    Dem_GaaOldEvtCntHeadTailIndex[0][1] = 1U;
    Dem_GaaMemoryIndexForEvt[0] = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0].ucNextEventIdIndex = 1U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaMemoryIndexForEvt[0] = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][0] = 1U;
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][1] = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0].ucPreviousIndex = 1U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0].ucNextEventIdIndex = 255U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[1].ucPreviousIndex = 255U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[1].ucNextEventIdIndex = 0U;

    START_TEST("3: Dem_ResetChronologicalorder",
               "created to solve true case of LucTailIndex != LucEvtMemoryIndex at line number 338");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            ACCESS_FUNCTION(Dem_InternalFunc, Dem_ResetChronologicalorder)(LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_4(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    Dem_GaaOldEvtCntHeadTailIndex[0][0] = 0U;
    Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    Dem_GaaMemoryIndexForEvt[0] = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[1].ucPreviousIndex = 85U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[1].ucNextEventIdIndex = 85U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][0] = 0U;
    expected_Dem_GaaMemoryIndexForEvt[0] = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][1] = 1U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[1].ucPreviousIndex = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[1].ucNextEventIdIndex = 255U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucNextEventIdIndex = 1U;

    START_TEST("4: Dem_ResetChronologicalorder",
               "created to solve false case of LucEvtMemoryIndex ==                      Dem_GaaOldEvtCntHeadTailIndex[LucMemMappingIndex][DEM_ZERO] between lines 334 and 335");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            ACCESS_FUNCTION(Dem_InternalFunc, Dem_ResetChronologicalorder)(LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_5(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaOldEvtCntHeadTailIndex[0][0] = 0U;
    Dem_GaaOldEvtCntHeadTailIndex[0][1] = 1U;
    Dem_GaaMemoryIndexForEvt[0] = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][0] = 0U;
    expected_Dem_GaaMemoryIndexForEvt[0] = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][1] = 1U;

    START_TEST("5: Dem_ResetChronologicalorder",
               "created to solve false case of LucEvtMemoryIndex !=                   Dem_GaaOldEvtCntHeadTailIndex[LucMemMappingIndex][DEM_ONE] between lines 376 and 377");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            ACCESS_FUNCTION(Dem_InternalFunc, Dem_ResetChronologicalorder)(LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_6(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaMemoryIndexForEvt[0] = 255U;
    expected_Dem_GaaMemoryIndexForEvt[0] = 255U;

    START_TEST("6: Dem_ResetChronologicalorder",
               "created to solve false case of DEM_INVALID_MEMORY_INDEX != LucEvtMemoryIndex at line number 305");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            ACCESS_FUNCTION(Dem_InternalFunc, Dem_ResetChronologicalorder)(LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_7(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    Dem_GaaMemoryIndexForEvt[0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucOccuranceCounter = 85U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaMemoryIndexForEvt[0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucOccuranceCounter = 86U;

    START_TEST("7: Dem_ProcessOccurenceCounter",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            ACCESS_FUNCTION(Dem_InternalFunc, Dem_ProcessOccurenceCounter)(LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_8(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    Dem_GaaMemoryIndexForEvt[0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucOccuranceCounter = 255U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaMemoryIndexForEvt[0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucOccuranceCounter = 255U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];

    START_TEST("8: Dem_ProcessOccurenceCounter",
               "created to solve false case of DEM_OCC_MAX != LucOccuranceCounter at line number 493");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            ACCESS_FUNCTION(Dem_InternalFunc, Dem_ProcessOccurenceCounter)(LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_9(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    Dem_GaaMemoryIndexForEvt[0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucOccuranceCounter = 0U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaMemoryIndexForEvt[0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucOccuranceCounter = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];

    START_TEST("9: Dem_ProcessOccurenceCounter",
               "created to solve false case of DEM_ZERO < LucOccuranceCounter at line number 492");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            ACCESS_FUNCTION(Dem_InternalFunc, Dem_ProcessOccurenceCounter)(LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_10(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaMemoryIndexForEvt[0] = 255U;
    expected_Dem_GaaMemoryIndexForEvt[0] = 255U;

    START_TEST("10: Dem_ProcessOccurenceCounter",
               "created to solve false case of DEM_INVALID != LucEventMemoryIndex at line number 474");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            ACCESS_FUNCTION(Dem_InternalFunc, Dem_ProcessOccurenceCounter)(LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_11(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventStatusType * LpEventStatus = &map_LpEventStatus[0];
    Std_ReturnType * LpReturnValue = &map_LpReturnValue[0];
    uint16 LusEventParameterIndex = 0U;
    map_LpEventStatus[0] = 85U;
    expected_map_LpEventStatus[0] = 85U;
    expected_map_LpReturnValue[0] = 1U;

    START_TEST("11: Dem_UnusedDebounceRoutine",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            ACCESS_FUNCTION(Dem_InternalFunc, Dem_UnusedDebounceRoutine)(LpEventStatus, LpReturnValue, LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_12(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucEventEntryStorageTrigr = 85U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucEventEntryStorageTrigr = 85U;

    START_TEST("12: Dem_ProcessTriggerIfFdcThresholdReached",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_EventSearchInMemory#1");

            /* Call SUT */
            ACCESS_FUNCTION(Dem_InternalFunc, Dem_ProcessTriggerIfFdcThresholdReached)(LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_13(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaEvtBitArrayMap[0].ddArrayIndex = 0U;
    Dem_GaaEvtBitArrayMap[0].ucBitMask = 85U;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucEventEntryStorageTrigr = 1U;
    Dem_GaaPrimaryTrigger[0] = 85U;
    expected_Dem_GaaEvtBitArrayMap[0].ddArrayIndex = 0U;
    expected_Dem_GaaEvtBitArrayMap[0].ucBitMask = 85U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucEventEntryStorageTrigr = 1U;
    expected_Dem_GaaPrimaryTrigger[0] = 85U;

    START_TEST("13: Dem_ProcessTriggerIfFdcThresholdReached",
               "created to solve true case of Dem_GaaDTCOriginBasedPtrAddress[LucMemIndx].ucEventEntryStorageTrigr ==     DEM_TRIGGER_ON_FDC_THRESHOLD between lines 841 and 842");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_EventSearchInMemory#1");

            /* Call SUT */
            ACCESS_FUNCTION(Dem_InternalFunc, Dem_ProcessTriggerIfFdcThresholdReached)(LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_14(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint16 LusDTCOrgin = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
//    Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GaaCurDTCFilter[0] = 0U;
    Dem_GaaDTCFormat[0] = 0U;
//    expected_Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    expected_Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaCurDTCFilter[0] = 0U;
    expected_Dem_GaaDTCFormat[0] = 0U;

    START_TEST("14: Dem_DTCFilterSearch",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_DTCFilterSearch(LusDtcInfoIndex, LusDTCOrgin, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_15(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint16 LusDTCOrgin = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
 //  Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GaaCurDTCFilter[0] = 1024U;
    Dem_GaaAllFDC[0] = 85;
    Dem_GaaDTCFormat[0] = 0U;
  //  expected_Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    expected_Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaCurDTCFilter[0] = 1024U;
    expected_Dem_GaaAllFDC[0] = 85;
    expected_Dem_GaaDTCFormat[0] = 0U;

    START_TEST("15: Dem_DTCFilterSearch",
               "created to solve true case of ((Dem_GaaCurDTCFilter[LucClientId] & (uint16)DEM_FDC_MASK) >> DEM_TEN) ==    (uint16)DEM_DTC_FILTER_FOR_FDC_YES between lines 753 and 754");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1;SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_DTCFilterSearch(LusDtcInfoIndex, LusDTCOrgin, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_16(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint16 LusDTCOrgin = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
//    Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GaaCurDTCFilter[0] = 1024U;
    Dem_GaaAllFDC[0] = 127;
    Dem_GaaDTCFormat[0] = 0U;
//    expected_Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    expected_Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaCurDTCFilter[0] = 1024U;
    expected_Dem_GaaAllFDC[0] = 127;
    expected_Dem_GaaDTCFormat[0] = 0U;

    START_TEST("16: Dem_DTCFilterSearch",
               "created to solve true case of Dem_GaaAllFDC[LusEventIndex] == (sint8)(DEM_FDC_COUNTER_MAX) at line number 764");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1;SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_DTCFilterSearch(LusDtcInfoIndex, LusDTCOrgin, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_17(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint16 LusDTCOrgin = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
//    Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GaaCurDTCFilter[0] = 1024U;
    Dem_GaaAllFDC[0] = 0;
    Dem_GaaDTCFormat[0] = 0U;
//    expected_Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    expected_Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaCurDTCFilter[0] = 1024U;
    expected_Dem_GaaAllFDC[0] = 0;
    expected_Dem_GaaDTCFormat[0] = 0U;

    START_TEST("17: Dem_DTCFilterSearch",
               "created to solve true case of Dem_GaaAllFDC[LusEventIndex] <= (sint8)DEM_ZERO at line number 763");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1;SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_DTCFilterSearch(LusDtcInfoIndex, LusDTCOrgin, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_18(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint16 LusDTCOrgin = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
//    Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GaaDtcInfo[0].ddDtcSeverity = 85U;
    Dem_GaaCurDTCFilter[0] = 32768U;
    Dem_GaaDTCFormat[0] = 0U;
//    expected_Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    expected_Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcSeverity = 85U;
    expected_Dem_GaaCurDTCFilter[0] = 32768U;
    expected_Dem_GaaDTCFormat[0] = 0U;

    START_TEST("18: Dem_DTCFilterSearch",
               "created to solve true case of (Dem_GaaCurDTCFilter[LucClientId] >> DEM_FIFTEEN) ==        (uint16)DEM_DTC_FILTER_WITH_SEVERITY_YES between lines 741 and 742");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_DTCFilterSearch(LusDtcInfoIndex, LusDTCOrgin, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_19(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint16 LusDTCOrgin = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
//    Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GaaDtcInfo[0].ddDtcSeverity = 2U;
    Dem_GaaCurDTCFilter[0] = 32770U;
    Dem_GaaDTCFormat[0] = 0U;
//    expected_Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    expected_Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcSeverity = 2U;
    expected_Dem_GaaCurDTCFilter[0] = 32770U;
    expected_Dem_GaaDTCFormat[0] = 0U;

    START_TEST("19: Dem_DTCFilterSearch",
               "created to solve false case of (((uint16)LddDtcSeverity) &      ((Dem_GaaCurDTCFilter[LucClientId] & (uint16)DEM_BYTE_FF))) == DEM_ZERO between lines 744 and 745");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_DTCFilterSearch(LusDtcInfoIndex, LusDTCOrgin, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_20(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint16 LusDTCOrgin = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
//    Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    Dem_GaaDTCAttributes[0].ucEventDestination = 0U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    Dem_GaaCurDTCFilter[0] = 0U;
    Dem_GaaDTCFormat[0] = 0U;
//    expected_Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    expected_Dem_GaaDTCAttributes[0].ucEventDestination = 0U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    expected_Dem_GaaCurDTCFilter[0] = 0U;
    expected_Dem_GaaDTCFormat[0] = 0U;

    START_TEST("20: Dem_DTCFilterSearch",
               "created to solve true case of (Dem_GaaDTCAttributes[LusDTCAttributeIndex].      aaEventDestination[DEM_ZERO]) ==                          ((uint8)(LusDTCOrgin)) between lines 692 and 694");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_DTCFilterSearch(LusDtcInfoIndex, LusDTCOrgin, LucClientId);

            /* Test case checks */
//            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_21(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint16 LusDTCOrgin = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
//    Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    Dem_GaaDTCAttributes[0].ucEventDestination = 0U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GaaDtcInfo[0].ddDtcFormat[0] = 1U;
    Dem_GaaCurDTCFilter[0] = 0U;
    Dem_GaaDTCFormat[0] = 0U;
    Dem_GaaCurDTCFilterStatusMask[0] = 85U;
    Dem_GaaAllDtcStatus[0] = 85U;
//    expected_Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    expected_Dem_GaaDTCAttributes[0].ucEventDestination = 0U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 1U;
    expected_Dem_GaaCurDTCFilter[0] = 0U;
    expected_Dem_GaaDTCFormat[0] = 0U;
    expected_Dem_GaaCurDTCFilterStatusMask[0] = 85U;
    expected_Dem_GaaAllDtcStatus[0] = 85U;

    START_TEST("21: Dem_DTCFilterSearch",
               "created to solve false case of DEM_TRUE != LblDtcFormat at line number 713");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_DTCFilterSearch(LusDtcInfoIndex, LusDTCOrgin, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_22(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint16 LusDTCOrgin = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
//    Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    Dem_GaaDTCAttributes[0].ucEventDestination = 0U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GaaDtcInfo[0].ddDtcFormat[0] = 1U;
    Dem_GaaCurDTCFilter[0] = 0U;
    Dem_GaaDTCFormat[0] = 0U;
    Dem_GaaCurDTCFilterStatusMask[0] = 0U;
    Dem_GaaAllDtcStatus[0] = 0U;
//    expected_Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    expected_Dem_GaaDTCAttributes[0].ucEventDestination = 0U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 1U;
    expected_Dem_GaaCurDTCFilter[0] = 0U;
    expected_Dem_GaaDTCFormat[0] = 0U;
    expected_Dem_GaaCurDTCFilterStatusMask[0] = 0U;
    expected_Dem_GaaAllDtcStatus[0] = 0U;

    START_TEST("22: Dem_DTCFilterSearch",
               "created to solve false case of (LucStatus & Dem_GaaCurDTCFilterStatusMask[LucClientId]) != DEM_ZERO at line number 729");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_DTCFilterSearch(LusDtcInfoIndex, LusDTCOrgin, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_23(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint16 LusDTCOrgin = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
//    Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    Dem_GaaDTCAttributes[0].ucEventDestination = 0U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GaaDtcInfo[0].ddDtcFormat[0] = 1U;
    Dem_GaaCurDTCFilter[0] = 0U;
    Dem_GaaDTCFormat[0] = 0U;
    Dem_GaaCurDTCFilterStatusMask[0] = 128U;
    Dem_GaaAllDtcStatus[0] = 0U;
//    expected_Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    expected_Dem_GaaDTCAttributes[0].ucEventDestination = 0U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 1U;
    expected_Dem_GaaCurDTCFilter[0] = 0U;
    expected_Dem_GaaDTCFormat[0] = 0U;
    expected_Dem_GaaCurDTCFilterStatusMask[0] = 128U;
    expected_Dem_GaaAllDtcStatus[0] = 0U;

    START_TEST("23: Dem_DTCFilterSearch",
               "created to solve false case of Dem_GaaCurDTCFilterStatusMask[LucClientId] == DEM_ZERO at line number 730");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_DTCFilterSearch(LusDtcInfoIndex, LusDTCOrgin, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_24(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint16 LusDTCOrgin = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
//    Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 0U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GaaCurDTCFilter[0] = 0U;
    Dem_GaaDTCFormat[0] = 0U;
//    expected_Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 0U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaCurDTCFilter[0] = 0U;
    expected_Dem_GaaDTCFormat[0] = 0U;

    START_TEST("24: Dem_DTCFilterSearch",
               "created to solve false case of DEM_ZERO < LucEventDestinationCnt at line number 684");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_DTCFilterSearch(LusDtcInfoIndex, LusDTCOrgin, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_25(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint16 LusDTCOrgin = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
//    Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 2U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[1] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GaaCurDTCFilter[0] = 0U;
    Dem_GaaAllFDC[0] = 85;
    Dem_GaaDTCFormat[0] = 0U;
//    expected_Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    expected_Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 2U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[1] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaCurDTCFilter[0] = 0U;
    expected_Dem_GaaAllFDC[0] = 85;
    expected_Dem_GaaDTCFormat[0] = 0U;

    START_TEST("25: Dem_DTCFilterSearch",
               "created to solve true case of LusCombinedEvent <      LusNoOfCombinedEvents between lines 622 and 623");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_DTCFilterSearch(LusDtcInfoIndex, LusDTCOrgin, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_26(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint16 LusDTCOrgin = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
//    Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 2U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[1] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GaaCurDTCFilter[0] = 0U;
    Dem_GaaAllFDC[0] = 127;
    Dem_GaaDTCFormat[0] = 0U;
//    expected_Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    expected_Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 2U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[1] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaCurDTCFilter[0] = 0U;
    expected_Dem_GaaAllFDC[0] = 127;
    expected_Dem_GaaDTCFormat[0] = 0U;

    START_TEST("26: Dem_DTCFilterSearch",
               "created to solve true case of DEM_FDC_COUNTER_MAX == Dem_GaaAllFDC[LusEventIndex] at line number 650");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_DTCFilterSearch(LusDtcInfoIndex, LusDTCOrgin, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_27(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint16 LusDTCOrgin = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
//    Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 1U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GaaCurDTCFilter[0] = 0U;
    Dem_GaaDTCFormat[0] = 0U;
//    expected_Dem_GaaDTCAttributes[0].ucNoOfDestinationSelected = 85U;
    expected_Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 1U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaCurDTCFilter[0] = 0U;
    expected_Dem_GaaDTCFormat[0] = 0U;

    START_TEST("27: Dem_DTCFilterSearch",
               "created to solve false case of DEM_ONE != LusNoOfCombinedEvents at line number 616");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_DTCFilterSearch(LusDtcInfoIndex, LusDTCOrgin, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_28(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */

    START_TEST("28: Dem_StartupNVOperation",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_InitNVData_Internal#1");

            /* Call SUT */
            Dem_StartupNVOperation();

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_29(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[81];
    Dem_GaaDTCOriginBasedPtrAddress[0].ucEntriesInMemory = 4U;
    Dem_GaaDtcMainEvent[0] = 0U;
    Dem_GaaDtcMainEvent[1] = 0U;
    Dem_GaaDtcMainEvent[2] = 0U;
    Dem_GaaDtcMainEvent[3] = 0U;
    Dem_GaaDtcMainEvent[4] = 0U;
    Dem_GaaDtcMainEvent[5] = 0U;
    Dem_GaaOldEvtCntHeadTailIndex[0][0] = 85U;
    Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85;
    Dem_GaaAllFDC[0] = 85;
    Dem_GaaAllFDC[1] = 85;
    Dem_GaaAllFDC[2] = 85;
    Dem_GaaAllFDC[3] = 85;
    Dem_GaaAllFDC[4] = 85;
    Dem_GaaAllFDC[5] = 85;
    Dem_GaaAllFDC[6] = 85;
    Dem_GaaAllFDC[7] = 85;
    Dem_GaaAllFDC[8] = 85;
    Dem_GaaAllFDC[9] = 85;
    Dem_GaaAllEvtStatus[0] = 85U;
    Dem_GaaAllEvtStatus[1] = 85;
    Dem_GaaAllEvtStatus[2] = 85;
    Dem_GaaAllEvtStatus[3] = 85;
    Dem_GaaAllEvtStatus[4] = 85;
    Dem_GaaAllEvtStatus[5] = 85;
    Dem_GaaAllEvtStatus[6] = 85;
    Dem_GaaAllEvtStatus[7] = 85;
    Dem_GaaAllEvtStatus[8] = 85;
    Dem_GaaAllEvtStatus[9] = 85;
    Dem_GaaEventFailureCounter[0] = 85U;
    Dem_GaaEventFailureCounter[1] = 85;
    Dem_GaaEventFailureCounter[2] = 85;
    Dem_GaaEventFailureCounter[3] = 85;
    Dem_GaaEventFailureCounter[4] = 85;
    Dem_GaaEventFailureCounter[5] = 85;
    Dem_GaaEventFailureCounter[6] = 85;
    Dem_GaaEventFailureCounter[7] = 85;
    Dem_GaaEventFailureCounter[8] = 85;
    Dem_GaaEventFailureCounter[9] = 85;
    Dem_GaaAllDtcStatus[0] = 85U;
    Dem_GaaAllDtcStatus[1] = 85;
    Dem_GaaAllDtcStatus[2] = 85;
    Dem_GaaAllDtcStatus[3] = 85;
    Dem_GaaAllDtcStatus[4] = 85;
    Dem_GaaAllDtcStatus[5] = 85;
    Dem_GaaOperationCycleState[0] = 85U;
    Dem_GstDefaultEventMemory.ddEventId = 0U;
    Dem_GstDefaultEventMemory.ucNumOfFF = 85U;
    Dem_GstDefaultEventMemory.ucOccuranceCounter = 85U;
    Dem_GstDefaultEventMemory.ucAgingCounter = 85U;
    Dem_GstDefaultEventMemory.ucPreviousIndex = 85U;
    Dem_GstDefaultEventMemory.ucNextEventIdIndex = 85U;
    Dem_GaaDefaultOperationCycleState[0] = 85U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucEntriesInMemory = 4U;
    expected_Dem_GaaDtcMainEvent[0] = 0U;
    expected_Dem_GaaDtcMainEvent[1] = 0U;
    expected_Dem_GaaDtcMainEvent[2] = 0U;
    expected_Dem_GaaDtcMainEvent[3] = 0U;
    expected_Dem_GaaDtcMainEvent[4] = 0U;
    expected_Dem_GaaDtcMainEvent[5] = 0U;
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][0] = 85U;
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85;
    expected_Dem_GaaAllFDC[0] = 85;
    expected_Dem_GaaAllFDC[1] = 85;
    expected_Dem_GaaAllFDC[2] = 85;
    expected_Dem_GaaAllFDC[3] = 85;
    expected_Dem_GaaAllFDC[4] = 85;
    expected_Dem_GaaAllFDC[5] = 85;
    expected_Dem_GaaAllFDC[6] = 85;
    expected_Dem_GaaAllFDC[7] = 85;
    expected_Dem_GaaAllFDC[8] = 85;
    expected_Dem_GaaAllFDC[9] = 85;
    expected_Dem_GaaAllEvtStatus[0] = 85U;
    expected_Dem_GaaAllEvtStatus[1] = 85;
    expected_Dem_GaaAllEvtStatus[2] = 85;
    expected_Dem_GaaAllEvtStatus[3] = 85;
    expected_Dem_GaaAllEvtStatus[4] = 85;
    expected_Dem_GaaAllEvtStatus[5] = 85;
    expected_Dem_GaaAllEvtStatus[6] = 85;
    expected_Dem_GaaAllEvtStatus[7] = 85;
    expected_Dem_GaaAllEvtStatus[8] = 85;
    expected_Dem_GaaAllEvtStatus[9] = 85;
    expected_Dem_GaaEventFailureCounter[0] = 85U;
    expected_Dem_GaaEventFailureCounter[1] = 85;
    expected_Dem_GaaEventFailureCounter[2] = 85;
    expected_Dem_GaaEventFailureCounter[3] = 85;
    expected_Dem_GaaEventFailureCounter[4] = 85;
    expected_Dem_GaaEventFailureCounter[5] = 85;
    expected_Dem_GaaEventFailureCounter[6] = 85;
    expected_Dem_GaaEventFailureCounter[7] = 85;
    expected_Dem_GaaEventFailureCounter[8] = 85;
    expected_Dem_GaaEventFailureCounter[9] = 85;
    expected_Dem_GaaAllDtcStatus[0] = 85U;
    expected_Dem_GaaAllDtcStatus[1] = 85;
    expected_Dem_GaaAllDtcStatus[2] = 85;
    expected_Dem_GaaAllDtcStatus[3] = 85;
    expected_Dem_GaaAllDtcStatus[4] = 85;
    expected_Dem_GaaAllDtcStatus[5] = 85;
    expected_Dem_GaaOperationCycleState[0] = 85U;
    expected_Dem_GstDefaultEventMemory.ddEventId = 0U;
    expected_Dem_GstDefaultEventMemory.ucNumOfFF = 85U;
    expected_Dem_GstDefaultEventMemory.ucOccuranceCounter = 85U;
    expected_Dem_GstDefaultEventMemory.ucAgingCounter = 85U;
    expected_Dem_GstDefaultEventMemory.ucPreviousIndex = 85U;
    expected_Dem_GstDefaultEventMemory.ucNextEventIdIndex = 85U;
    expected_Dem_GaaDefaultOperationCycleState[0] = 85U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[81];
    expected_Dem_GaaPrestoreBuffer[0].ddEventId = 0U;
    expected_Dem_GaaPrestoreBuffer[0].aaFFRecNumAndData[0] = 0U;
    expected_Dem_GaaPrestoreBuffer[0].aaFFRecNumAndData[1] = 0U;
    expected_Dem_GaaPrestoreBuffer[0].aaFFRecNumAndData[2] = 0U;
    expected_Dem_GaaPrestoreBuffer[1].ddEventId = 0U;
    expected_Dem_GaaPrestoreBuffer[1].aaFFRecNumAndData[0] = 0U;
    expected_Dem_GaaPrestoreBuffer[1].aaFFRecNumAndData[1] = 0U;
    expected_Dem_GaaPrestoreBuffer[1].aaFFRecNumAndData[2] = 0U;
    expected_Dem_GaaPrestoreBuffer[2].ddEventId = 0U;
    expected_Dem_GaaPrestoreBuffer[2].aaFFRecNumAndData[0] = 0U;
    expected_Dem_GaaPrestoreBuffer[2].aaFFRecNumAndData[1] = 0U;
    expected_Dem_GaaPrestoreBuffer[2].aaFFRecNumAndData[2] = 0U;
    expected_Dem_GaaPrestoreBuffer[3].ddEventId = 0U;
    expected_Dem_GaaPrestoreBuffer[3].aaFFRecNumAndData[0] = 0U;
    expected_Dem_GaaPrestoreBuffer[3].aaFFRecNumAndData[1] = 0U;
    expected_Dem_GaaPrestoreBuffer[3].aaFFRecNumAndData[2] = 0U;
    expected_Dem_GaaDTCOccurenceTime[0][0] = 65535U;
    expected_Dem_GaaDTCOccurenceTime[0][1] = 65535U;
    expected_Dem_GaaDTCOccurenceTime[0][2] = 65535U;
    expected_Dem_GaaDTCOccurenceTime[0][3] = 65535U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[81].ddEventId = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[81].ucNumOfFF = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[81].ucOccuranceCounter = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[81].ucAgingCounter = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[81].ucPreviousIndex = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[81].ucNextEventIdIndex = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[82].ddEventId = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[82].ucNumOfFF = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[82].ucOccuranceCounter = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[82].ucAgingCounter = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[82].ucPreviousIndex = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[82].ucNextEventIdIndex = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[83].ddEventId = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[83].ucNumOfFF = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[83].ucOccuranceCounter = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[83].ucAgingCounter = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[83].ucPreviousIndex = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[83].ucNextEventIdIndex = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[84].ddEventId = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[84].ucNumOfFF = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[84].ucOccuranceCounter = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[84].ucAgingCounter = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[84].ucPreviousIndex = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[84].ucNextEventIdIndex = 85U;

    START_TEST("29: Dem_InitNVData_Internal",
               "created to solve false case of DEM_ZERO < LucEntriesInMemory at line number 996");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("memcpy#1;memcpy#1;memcpy#1;memcpy#1;memset#1;memset#2;memset#3;memset#4;memset#5;memset#6;memset#7");

            /* Call SUT */
            Dem_InitNVData_Internal();

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_30(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucClientId = 0U;
    Dem_GaaOriginFilter[0] = 0U;
    Dem_GaaNumOfFilteredDtc[0] = 0U;
    Dem_GaaSuppressionStatus[0] = 85U;
    Dem_GaaSuppressionStatus[1] = 85U;
    Dem_GaaSuppressionStatus[2] = 0U;
    Dem_GaaSuppressionStatus[3] = 0U;
    Dem_GaaSuppressionStatus[4] = 1U;
    Dem_GaaSuppressionStatus[5] = 0U;
    expected_Dem_GaaOriginFilter[0] = 0U;
    expected_Dem_GaaSuppressionStatus[0] = 85U;
    expected_Dem_GaaSuppressionStatus[1] = 85U;
    expected_Dem_GaaSuppressionStatus[2] = 0U;
    expected_Dem_GaaSuppressionStatus[3] = 0U;
    expected_Dem_GaaSuppressionStatus[4] = 1U;
    expected_Dem_GaaSuppressionStatus[5] = 0U;
    expected_Dem_GaaNumOfFilteredDtc[0] = 1U;
    expected_Dem_GaaMatchingDtcIndex[0] = 5U;
    expected_Dem_GaaChronlgOrdReq[0] = 4U;

    START_TEST("30: Dem_FaultcheckInConfig",
               "created to solve true case of E_OK == LddTempRet at line number 1373");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DTCFilterSearch#1;Dem_DTCFilterSearch#2;Dem_DTCFilterSearch#3");

            /* Call SUT */
            Dem_FaultcheckInConfig(LucClientId);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_31(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucClientId = 85U;

    START_TEST("31: Dem_UnusedFilterRoutine",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_UnusedFilterRoutine(LucClientId);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_32(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 * LpData = &map_LpData[0];
    Std_ReturnType returnValue;
    expected_map_LpData[0] = 0U;

    START_TEST("32: Dem_UnusedDataReadRoutine",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_UnusedDataReadRoutine(LpData);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_33(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 * LpData = &map_LpData_1[0];
    Dem_MonitorDataType monitorData0 = 0UL;
    Std_ReturnType returnValue;
    expected_map_LpData_1[0] = 0U;

    START_TEST("33: Dem_UnusedMonitorDataReadRoutine",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_UnusedMonitorDataReadRoutine(LpData, monitorData0);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_34(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    sint8 * FaultDetectionCounter = &map_FaultDetectionCounter[0];
    Std_ReturnType returnValue;
    expected_map_FaultDetectionCounter[0] = 0;

    START_TEST("34: Dem_UnusedCallBackGetFDCRoutine",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_UnusedCallBackGetFDCRoutine(FaultDetectionCounter);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 14U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_35(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventIdType LusEventParameterIndex = 0U;
    Dem_EventStatusType LddEventStatus = 85U;

    START_TEST("35: Dem_UnusedDataCaptureRoutine",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_UnusedDataCaptureRoutine(LusEventParameterIndex, LddEventStatus);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_36(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventIdType EventId = 0U;
    Dem_EventStatusType EventStatus = 85U;
    Std_ReturnType returnValue;

    START_TEST("36: Dem_SetEventStatus_Invalid_Routine",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_SetEventStatus_Invalid_Routine(EventId, EventStatus);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_37(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventIdType EventId = 0U;
    sint8 * FaultDetectionCounter = &map_FaultDetectionCounter_1[0];
    Std_ReturnType returnValue;
    map_FaultDetectionCounter_1[0] = 85;
    expected_map_FaultDetectionCounter_1[0] = 85;

    START_TEST("37: Dem_GetFaultDetectionCounter_Invalid_Routine",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetFaultDetectionCounter_Invalid_Routine(EventId, FaultDetectionCounter);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_38(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventIdType EventId = 0U;
    Std_ReturnType returnValue;

    START_TEST("38: Dem_PrestoreFreezeFrame_Invalid_Routine",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_PrestoreFreezeFrame_Invalid_Routine(EventId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_39(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventIdType EventId = 0U;
    Std_ReturnType returnValue;

    START_TEST("39: Dem_ClearPrestoreFreezeFrame_Invalid_Routine",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_ClearPrestoreFreezeFrame_Invalid_Routine(EventId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_40(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint16 * LpEventParameterIndex = &map_LpEventParameterIndex[0];
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcMainEvent[0] = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcMainEvent[0] = 0U;
    expected_map_LpEventParameterIndex[0] = 0U;

    START_TEST("40: Dem_SearchDtc",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            Dem_SearchDtc(LusDtcInfoIndex, LpEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_41(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint16 * LpEventParameterIndex = &map_LpEventParameterIndex[0];
    Dem_GaaDtcMainEvent[0] = 1U;
    expected_Dem_GaaDtcMainEvent[0] = 1U;
    expected_map_LpEventParameterIndex[0] = 0U;

    START_TEST("41: Dem_SearchDtc",
               "created to solve true case of DEM_ZERO != LusDtcMainEvent at line number 2306");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            Dem_SearchDtc(LusDtcInfoIndex, LpEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_42(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    uint16 * LpSizeOfExtendedDataRecord = &map_LpSizeOfExtendedDataRecord[0];
    uint8 ExtendedDataNumber = 85U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory[0];
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    map_LpEventMemory[0].aaEdData[0][0] = 85U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LpEventMemory[0].aaEdData[0][0] = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpSizeOfExtendedDataRecord[0] = 1U;

    START_TEST("42: Dem_GetSizeOfRecNoFFandFE",
               "created to solve false case of LucCount < (Dem_GaaEventParameter   /* polyspace +2 RTE:IDP [Justified:Low] \"Refer Dem_c_Poly_REF_4\" */   /* Polyspace InternalFunc_c_Ref_124 */    [LusEventParameterIndex].pDTCAttribute)->ucNumOfEDRecords between lines 2393 and 2396");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_GetSizeOfRecNoFFandFE(LusEventParameterIndex, LpSizeOfExtendedDataRecord, ExtendedDataNumber, LpEventMemory);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_43(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    uint16 * LpSizeOfExtendedDataRecord = &map_LpSizeOfExtendedDataRecord[0];
    uint8 ExtendedDataNumber = 85U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory[0];
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    map_LpEventMemory[0].aaEdData[0][0] = 1U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LpEventMemory[0].aaEdData[0][0] = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpSizeOfExtendedDataRecord[0] = 0U;

    START_TEST("43: Dem_GetSizeOfRecNoFFandFE",
               "created to solve false case of LucCount < (Dem_GaaEventParameter   /* polyspace +2 RTE:IDP [Justified:Low] \"Refer Dem_c_Poly_REF_4\" */   /* Polyspace InternalFunc_c_Ref_124 */    [LusEventParameterIndex].pDTCAttribute)->ucNumOfEDRecords between lines 2393 and 2396");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_GetSizeOfRecNoFFandFE(LusEventParameterIndex, LpSizeOfExtendedDataRecord, ExtendedDataNumber, LpEventMemory);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_44(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    uint16 * LpSizeOfExtendedDataRecord = &map_LpSizeOfExtendedDataRecord[0];
    uint8 ExtendedDataNumber = 85U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory[0];
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    map_LpEventMemory[0].aaEdData[0][0] = 240U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_LpEventMemory[0].aaEdData[0][0] = 240U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpSizeOfExtendedDataRecord[0] = 0U;

    START_TEST("44: Dem_GetSizeOfRecNoFFandFE",
               "created to solve false case of LucCount < (Dem_GaaEventParameter   /* polyspace +2 RTE:IDP [Justified:Low] \"Refer Dem_c_Poly_REF_4\" */   /* Polyspace InternalFunc_c_Ref_124 */    [LusEventParameterIndex].pDTCAttribute)->ucNumOfEDRecords between lines 2393 and 2396");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_GetSizeOfRecNoFFandFE(LusEventParameterIndex, LpSizeOfExtendedDataRecord, ExtendedDataNumber, LpEventMemory);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_45(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    uint16 * LpSizeOfExtendedDataRecord = &map_LpSizeOfExtendedDataRecord[0];
    uint8 ExtendedDataNumber = 85U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory[0];
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    map_LpEventMemory[0].aaEdData[0][0] = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_LpEventMemory[0].aaEdData[0][0] = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpSizeOfExtendedDataRecord[0] = 0U;

    START_TEST("45: Dem_GetSizeOfRecNoFFandFE",
               "created to solve false case of LucCount < (Dem_GaaEventParameter   /* polyspace +2 RTE:IDP [Justified:Low] \"Refer Dem_c_Poly_REF_4\" */   /* Polyspace InternalFunc_c_Ref_124 */    [LusEventParameterIndex].pDTCAttribute)->ucNumOfEDRecords between lines 2393 and 2396");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_GetSizeOfRecNoFFandFE(LusEventParameterIndex, LpSizeOfExtendedDataRecord, ExtendedDataNumber, LpEventMemory);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_46(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    uint16 * LpSizeOfExtendedDataRecord = &map_LpSizeOfExtendedDataRecord[0];
    uint8 ExtendedDataNumber = 254U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory[0];
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpSizeOfExtendedDataRecord[0] = 0U;

    START_TEST("46: Dem_GetSizeOfRecNoFFandFE",
               "created to solve false case of LucCount < (Dem_GaaEventParameter   /* polyspace +2 RTE:IDP [Justified:Low] \"Refer Dem_c_Poly_REF_4\" */   /* Polyspace InternalFunc_c_Ref_124 */    [LusEventParameterIndex].pDTCAttribute)->ucNumOfEDRecords between lines 2393 and 2396");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_GetSizeOfRecNoFFandFE(LusEventParameterIndex, LpSizeOfExtendedDataRecord, ExtendedDataNumber, LpEventMemory);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_47(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventMemory * LpEventMemory = &map_LpEventMemory_1[0];
    const Dem_PrestoreBuffer * LpPFFBuffer = NULL;
    uint8 LucRecordIndexInMem = 85U;
    Dem_GaaEventParameter[0].pDTCAttribute = NULL;
    map_LpEventMemory_1[0].ddEventId = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = NULL;
    expected_map_LpEventMemory_1[0].ddEventId = 1U;

    START_TEST("47: Dem_LoadPrestoredDid",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_LoadPrestoredDid(LpEventMemory, LpPFFBuffer, LucRecordIndexInMem);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_48(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventMemory * LpEventMemory = &map_LpEventMemory_1[0];
    const Dem_PrestoreBuffer * LpPFFBuffer = NULL;
    uint8 LucRecordIndexInMem = 85U;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    map_LpEventMemory_1[0].ddEventId = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    expected_map_LpEventMemory_1[0].ddEventId = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];

    START_TEST("48: Dem_LoadPrestoredDid",
               "created to solve true case of NULL_PTR != LpDTCAttribute at line number 2775");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_LoadPrestoredDid(LpEventMemory, LpPFFBuffer, LucRecordIndexInMem);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_49(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventMemory * LpEventMemory = &map_LpEventMemory_1[0];
    const Dem_PrestoreBuffer * LpPFFBuffer = &map_LpPFFBuffer[0];
    uint8 LucRecordIndexInMem = 0U;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    map_LpEventMemory_1[0].ddEventId = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 1U;
    map_LpPFFBuffer[0].aaFFRecNumAndData[1] = 85U;
    expected_map_LpEventMemory_1[0].ddEventId = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 1U;
    expected_map_LpPFFBuffer[0].aaFFRecNumAndData[1] = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpEventMemory_1[0].aaFFRecNumAndData[0][1] = 85U;

    START_TEST("49: Dem_LoadPrestoredDid",
               "created to solve true case of LusDataSizeCount < LusFFRecordRawDataSize at line number 2781");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_LoadPrestoredDid(LpEventMemory, LpPFFBuffer, LucRecordIndexInMem);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_50(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucPFFBufferIndex = 0U;
    Dem_GaaPrestoreBuffer[0].ddEventId = 0U;
    expected_Dem_GaaPrestoreBuffer[0].ddEventId = 0U;
    expected_Dem_GaaPrestoreBuffer[0].aaFFRecNumAndData[0] = 0U;
    expected_Dem_GaaPrestoreBuffer[0].aaFFRecNumAndData[1] = 0U;
    expected_Dem_GaaPrestoreBuffer[0].aaFFRecNumAndData[2] = 0U;

    START_TEST("50: Dem_ClearPFFEntry",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_ClearMasterEventPrestoreBuffer#1");

            /* Call SUT */
            Dem_ClearPFFEntry(LucPFFBufferIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_51(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDataIndex = 0U;
    uint8 LucDataElementType = 85U;
    uint8 * LpSize = NULL;
    Std_ReturnType returnValue;

    START_TEST("51: Dem_ProcessDataElementSize",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_ProcessDataElementSize(LusDataIndex, LucDataElementType, LpSize);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_52(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDataIndex = 0U;
    uint8 LucDataElementType = 1U;
    uint8 * LpSize = &map_LpSize[0];
    Std_ReturnType returnValue;
    Dem_GaaDataElementExternalCS[0].ucDemDataElementDataSize = 85U;
    expected_Dem_GaaDataElementExternalCS[0].ucDemDataElementDataSize = 85U;
    expected_map_LpSize[0] = 85U;

    START_TEST("52: Dem_ProcessDataElementSize",
               "created to solve true case of (uint8)DEM_DATA_ELEMENT_EXTERNAL_CS  == LucDataElementType at line number 2938");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_ProcessDataElementSize(LusDataIndex, LucDataElementType, LpSize);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_53(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    Dem_DTCOriginType LusDtcOrigin = 0U;
    boolean * LblEventExistInMemory = NULL;
    Dem_EventMemory ** LpEventMemory = &map_LpEventMemory_2[0];
    uint8 * LpStoredIndex = NULL;
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = NULL;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 85U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = NULL;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpEventMemory_2[0] = NULL;

    START_TEST("53: Dem_EnvironmentalDataCheck",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_SearchDtc#1");

            /* Call SUT */
            returnValue = Dem_EnvironmentalDataCheck(LusDtcInfoIndex, LusDtcOrigin, LblEventExistInMemory, LpEventMemory, LpStoredIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 9U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_54(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    Dem_DTCOriginType LusDtcOrigin = 0U;
    boolean * LblEventExistInMemory = &map_LblEventExistInMemory[0];
    Dem_EventMemory ** LpEventMemory = &map_LpEventMemory_2[0];
    uint8 * LpStoredIndex = &map_LpStoredIndex[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = NULL;
    Dem_GaaMemoryIndexForEvt[0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = NULL;
    expected_Dem_GaaMemoryIndexForEvt[0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpEventMemory_2[0] = NULL;
    expected_map_LpStoredIndex[0] = 85U;
    expected_map_LblEventExistInMemory[0] = 1U;

    START_TEST("54: Dem_EnvironmentalDataCheck",
               "created to solve true case of (Dem_GaaEventParameter[LusEventParameterIndex].pDTCAttribute)->        aaEventDestination[DEM_ZERO] == LucOriginMask between lines 3087 and 3088");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_SearchDtc#1");

            /* Call SUT */
            returnValue = Dem_EnvironmentalDataCheck(LusDtcInfoIndex, LusDtcOrigin, LblEventExistInMemory, LpEventMemory, LpStoredIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_55(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    Dem_DTCOriginType LusDtcOrigin = 0U;
    boolean * LblEventExistInMemory = NULL;
    Dem_EventMemory ** LpEventMemory = &map_LpEventMemory_2[0];
    uint8 * LpStoredIndex = &map_LpStoredIndex[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = NULL;
    Dem_GaaMemoryIndexForEvt[0] = 255U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = NULL;
    expected_Dem_GaaMemoryIndexForEvt[0] = 255U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpEventMemory_2[0] = NULL;
    expected_map_LpStoredIndex[0] = 255U;

    START_TEST("55: Dem_EnvironmentalDataCheck",
               "created to solve false case of DEM_INVALID  != (*LpStoredIndex) at line number 3172");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_SearchDtc#1");

            /* Call SUT */
            returnValue = Dem_EnvironmentalDataCheck(LusDtcInfoIndex, LusDtcOrigin, LblEventExistInMemory, LpEventMemory, LpStoredIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_56(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint32 DTC = 0U;
    uint8 ClientId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_3[0];
    uint8 LucMaxNumOfEventEntry = 3U;
    uint16 * LpEvtParameterIndx = &map_LpEvtParameterIndx[0];
    uint8 * LpEventMemoryIndex = &map_LpEventMemoryIndex[0];
    boolean returnValue;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ulUdsDtcVal = 0U;
    map_LpEventMemory_3[0].ddEventId = 0U;
    map_LpEventMemory_3[1].ddEventId = 0U;
    map_LpEventMemory_3[2].ddEventId = 1U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ulUdsDtcVal = 0U;
    expected_map_LpEventMemory_3[0].ddEventId = 0U;
    expected_map_LpEventMemory_3[1].ddEventId = 0U;
    expected_map_LpEventMemory_3[2].ddEventId = 1U;
    expected_map_LpEvtParameterIndx[0] = 0U;
    expected_map_LpEventMemoryIndex[0] = 2U;

    START_TEST("56: Dem_DtcCheckInMem",
               "created to solve false case of LucCount < LucMaxNumOfEventEntry at line number 3372");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_DtcCheckInMem(ClientId, DTC, LpEventMemory, LucMaxNumOfEventEntry, LpEvtParameterIndx, LpEventMemoryIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_57(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint32 DTC = 1U;
    uint8 ClientId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_3[0];
    uint8 LucMaxNumOfEventEntry = 4U;
    uint16 * LpEvtParameterIndx = NULL;
    uint8 * LpEventMemoryIndex = NULL;
    boolean returnValue;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ulUdsDtcVal = 0U;
    map_LpEventMemory_3[0].ddEventId = 0U;
    map_LpEventMemory_3[1].ddEventId = 0U;
    map_LpEventMemory_3[2].ddEventId = 1U;
    map_LpEventMemory_3[3].ddEventId = 1U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ulUdsDtcVal = 0U;
    expected_map_LpEventMemory_3[0].ddEventId = 0U;
    expected_map_LpEventMemory_3[1].ddEventId = 0U;
    expected_map_LpEventMemory_3[2].ddEventId = 1U;
    expected_map_LpEventMemory_3[3].ddEventId = 1U;

    START_TEST("57: Dem_DtcCheckInMem",
               "created to solve false case of LucCount < LucMaxNumOfEventEntry at line number 3372");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_DtcCheckInMem(ClientId, DTC, LpEventMemory, LucMaxNumOfEventEntry, LpEvtParameterIndx, LpEventMemoryIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_58(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint32 DTC = 1U;
    uint8 ClientId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_3[0];
    uint8 LucMaxNumOfEventEntry = 6U;
    uint16 * LpEvtParameterIndx = NULL;
    uint8 * LpEventMemoryIndex = NULL;
    boolean returnValue;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ulUdsDtcVal = 0U;
    map_LpEventMemory_3[0].ddEventId = 0U;
    map_LpEventMemory_3[1].ddEventId = 0U;
    map_LpEventMemory_3[2].ddEventId = 1U;
    map_LpEventMemory_3[3].ddEventId = 11U;
    map_LpEventMemory_3[4].ddEventId = 0U;
    map_LpEventMemory_3[5].ddEventId = 11U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ulUdsDtcVal = 0U;
    expected_map_LpEventMemory_3[0].ddEventId = 0U;
    expected_map_LpEventMemory_3[1].ddEventId = 0U;
    expected_map_LpEventMemory_3[2].ddEventId = 1U;
    expected_map_LpEventMemory_3[3].ddEventId = 11U;
    expected_map_LpEventMemory_3[4].ddEventId = 0U;
    expected_map_LpEventMemory_3[5].ddEventId = 11U;

    START_TEST("58: Dem_DtcCheckInMem",
               "created to solve false case of LucCount < LucMaxNumOfEventEntry at line number 3372");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_DtcCheckInMem(ClientId, DTC, LpEventMemory, LucMaxNumOfEventEntry, LpEvtParameterIndx, LpEventMemoryIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_59(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint32 DTC = 0U;
    uint8 ClientId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_3[0];
    uint8 LucMaxNumOfEventEntry = 3U;
    uint16 * LpEvtParameterIndx = &map_LpEvtParameterIndx[0];
    uint8 * LpEventMemoryIndex = &map_LpEventMemoryIndex[0];
    boolean returnValue;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ulUdsDtcVal = 0U;
    map_LpEventMemory_3[0].ddEventId = 0U;
    map_LpEventMemory_3[1].ddEventId = 1U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ulUdsDtcVal = 0U;
    expected_map_LpEventMemory_3[0].ddEventId = 0U;
    expected_map_LpEventMemory_3[1].ddEventId = 1U;
    expected_map_LpEvtParameterIndx[0] = 0U;
    expected_map_LpEventMemoryIndex[0] = 1U;

    START_TEST("59: Dem_DtcCheckInMem",
               "created to solve true case of LucCount < LucMaxNumOfEventEntry at line number 3372");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_DtcCheckInMem(ClientId, DTC, LpEventMemory, LucMaxNumOfEventEntry, LpEvtParameterIndx, LpEventMemoryIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_60(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucClientId = 0U;
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    Dem_GaaOriginFilter[0] = 0U;
    Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 0U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 255U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaOriginFilter[0] = 0U;
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 255U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_Dem_GaaChronlgOrdReq[0] = 4U;

    START_TEST("60: Dem_FaultcheckInMemory",
               "created to solve false case of DEM_INVALID != LucNodeTailIndex at line number 3874");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_FilterEvent#1");

            /* Call SUT */
            Dem_FaultcheckInMemory(LucClientId);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_61(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucClientId = 0U;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    Dem_GaaOriginFilter[0] = 0U;
    Dem_GaaNumOfFilteredDtc[0] = 0U;
    Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 255U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaOriginFilter[0] = 0U;
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 255U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_Dem_GaaNumOfFilteredDtc[0] = 1U;
    expected_Dem_GaaMatchingDtcIndex[0] = 0U;
    expected_Dem_GaaChronlgOrdReq[0] = 4U;

    START_TEST("61: Dem_FaultcheckInMemory",
               "created to solve false case of DEM_INVALID != LucNodeTailIndex at line number 3874");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_FilterEvent#2");

            /* Call SUT */
            Dem_FaultcheckInMemory(LucClientId);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_62(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucClientId = 0U;
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaOriginFilter[0] = 0U;
    Dem_GaaOldEvtCntHeadTailIndex[0][1] = 255U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaOriginFilter[0] = 0U;
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][1] = 255U;
    expected_Dem_GaaChronlgOrdReq[0] = 4U;

    START_TEST("62: Dem_FaultcheckInMemory",
               "created to solve false case of DEM_INVALID != LucNodeTailIndex at line number 3842");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_FaultcheckInMemory(LucClientId);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_63(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucClientId = 0U;
    Dem_GaaDTCOriginMappingIndx[0] = 255U;
    Dem_GaaOriginFilter[0] = 0U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 255U;
    expected_Dem_GaaOriginFilter[0] = 0U;
    expected_Dem_GaaChronlgOrdReq[0] = 4U;

    START_TEST("63: Dem_FaultcheckInMemory",
               "created to solve false case of DEM_INVALID != LucMemMappingIndex at line number 3832");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_FaultcheckInMemory(LucClientId);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_64(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucClientId = 0U;
    Dem_GaaOriginFilter[0] = 3U;
    expected_Dem_GaaOriginFilter[0] = 3U;
    expected_Dem_GaaChronlgOrdReq[0] = 4U;

    START_TEST("64: Dem_FaultcheckInMemory",
               "created to solve false case of DEM_DTC_ORIGIN_PERMANENT_MEMORY != LucOriginMask at line number 3826");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_FaultcheckInMemory(LucClientId);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_65(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucClientId = 0U;
    Dem_GaaOriginFilter[0] = 5U;
    expected_Dem_GaaOriginFilter[0] = 5U;
    expected_Dem_GaaChronlgOrdReq[0] = 4U;

    START_TEST("65: Dem_FaultcheckInMemory",
               "created to solve false case of DEM_MAX_MEMORY_ID_CONF >= LucOriginMask at line number 3754");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_FaultcheckInMemory(LucClientId);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_66(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucClientId = 0U;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    Dem_GaaOriginMemMappingIndex[0] = 0U;
    Dem_GaaRecordNumber[0] = 85U;
    Dem_GaaSuppressionStatus[0] = 85U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 255U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].aaEdData[0][0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    expected_Dem_GaaOriginMemMappingIndex[0] = 0U;
    expected_Dem_GaaRecordNumber[0] = 85U;
    expected_Dem_GaaSuppressionStatus[0] = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 255U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].aaEdData[0][0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_Dem_GaaChronlgOrdReq[0] = 4U;

    START_TEST("66: Dem_RecordNumberCheckInMemory",
               "created to solve false case of DEM_INVALID != LucNodeTailIndex at line number 4116");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            Dem_RecordNumberCheckInMemory(LucClientId);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_67(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucClientId = 0U;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    Dem_GaaOriginMemMappingIndex[0] = 0U;
    Dem_GaaDTCFormat[0] = 0U;
    Dem_GaaRecordNumber[0] = 85U;
    Dem_GaaSuppressionStatus[0] = 0U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 255U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].aaEdData[0][0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    expected_Dem_GaaOriginMemMappingIndex[0] = 0U;
    expected_Dem_GaaDTCFormat[0] = 0U;
    expected_Dem_GaaRecordNumber[0] = 85U;
    expected_Dem_GaaSuppressionStatus[0] = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 255U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].aaEdData[0][0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_Dem_GaaChronlgOrdReq[0] = 4U;

    START_TEST("67: Dem_RecordNumberCheckInMemory",
               "created to solve false case of DEM_INVALID != LucNodeTailIndex at line number 4116");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            Dem_RecordNumberCheckInMemory(LucClientId);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_68(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucClientId = 0U;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    Dem_GaaDtcInfo[0].ddDtcFormat[0] = 1U;
    Dem_GaaNumOfFilteredDtc[0] = 0U;
    Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    Dem_GaaOriginMemMappingIndex[0] = 0U;
    Dem_GaaDTCFormat[0] = 0U;
    Dem_GaaRecordNumber[0] = 85U;
    Dem_GaaSuppressionStatus[0] = 0U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 255U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].aaEdData[0][0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 1U;
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    expected_Dem_GaaOriginMemMappingIndex[0] = 0U;
    expected_Dem_GaaDTCFormat[0] = 0U;
    expected_Dem_GaaRecordNumber[0] = 85U;
    expected_Dem_GaaSuppressionStatus[0] = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 255U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].aaEdData[0][0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_Dem_GaaNumOfFilteredDtc[0] = 1U;
    expected_Dem_GaaMatchingDtcIndex[0] = 0U;
    expected_Dem_GaaChronlgOrdReq[0] = 4U;

    START_TEST("68: Dem_RecordNumberCheckInMemory",
               "created to solve false case of DEM_INVALID != LucNodeTailIndex at line number 4116");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            Dem_RecordNumberCheckInMemory(LucClientId);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_69(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucClientId = 0U;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    Dem_GaaOriginMemMappingIndex[0] = 0U;
    Dem_GaaRecordNumber[0] = 1U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 255U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].aaEdData[0][0] = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    expected_Dem_GaaOriginMemMappingIndex[0] = 0U;
    expected_Dem_GaaRecordNumber[0] = 1U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 255U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].aaEdData[0][0] = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_Dem_GaaChronlgOrdReq[0] = 4U;

    START_TEST("69: Dem_RecordNumberCheckInMemory",
               "created to solve false case of DEM_INVALID != LucNodeTailIndex at line number 4116");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_RecordNumberCheckInMemory(LucClientId);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_70(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucClientId = 0U;
    Dem_GaaOldEvtCntHeadTailIndex[0][1] = 255U;
    Dem_GaaOriginMemMappingIndex[0] = 0U;
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][1] = 255U;
    expected_Dem_GaaOriginMemMappingIndex[0] = 0U;
    expected_Dem_GaaChronlgOrdReq[0] = 4U;

    START_TEST("70: Dem_RecordNumberCheckInMemory",
               "created to solve false case of DEM_INVALID != LucNodeTailIndex at line number 4027");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_RecordNumberCheckInMemory(LucClientId);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_71(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucClientId = 0U;
    Dem_GaaOriginMemMappingIndex[0] = 255U;
    expected_Dem_GaaOriginMemMappingIndex[0] = 255U;
    expected_Dem_GaaChronlgOrdReq[0] = 4U;

    START_TEST("71: Dem_RecordNumberCheckInMemory",
               "created to solve false case of DEM_INVALID != Dem_GaaOriginMemMappingIndex[LucClientId] at line number 4015");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_RecordNumberCheckInMemory(LucClientId);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_72(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucClientId = 0U;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    Dem_GaaOriginMemMappingIndex[0] = 0U;
    Dem_GaaRecordNumber[0] = 85U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].aaEdData[0][0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    map_ResumeAllInterrupts_call1_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    map_ResumeAllInterrupts_call2_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 0U;
    expected_Dem_GaaOldEvtCntHeadTailIndex[0][1] = 85U;
    expected_Dem_GaaOriginMemMappingIndex[0] = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    expected_map_ResumeAllInterrupts_call1_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_ResumeAllInterrupts_call2_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_ResumeAllInterrupts_call2_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[1] = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[2] = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[1] = 85U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[2] = 85U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[3] = 85U;
    expected_Dem_GaaDTCFormat[0] = 0U;
    expected_Dem_GaaRecordNumber[0] = 85U;
    expected_Dem_GaaChronlgOrdReq[0] = 4U;
    expected_Dem_GaaSuppressionStatus[0] = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 255U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].aaEdData[0][0] = 85U;

    START_TEST("72: Dem_RecordNumberCheckInMemory",
               "created to solve false case of DEM_INVALID != LucNodeTailIndex at line number 4116");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#2;ResumeAllInterrupts#2;SuspendAllInterrupts#3;ResumeAllInterrupts#3");

            /* Call SUT */
            Dem_RecordNumberCheckInMemory(LucClientId);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_80(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventIndex = 0U;
    uint8 LucClientId = 85U;
    Std_ReturnType returnValue;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaSuppressionStatus[0] = 85U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaSuppressionStatus[0] = 85U;

    START_TEST("80: Dem_FilterEvent",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_FilterEvent(LusEventIndex, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_81(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventIndex = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    Dem_GaaCurDTCFilter[0] = 0U;
    Dem_GaaOriginFilter[0] = 0U;
    Dem_GaaDTCFormat[0] = 0U;
    Dem_GaaCurDTCFilterStatusMask[0] = 85U;
    Dem_GaaAllDtcStatus[0] = 85U;
    Dem_GaaSuppressionStatus[0] = 0U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    expected_Dem_GaaCurDTCFilter[0] = 0U;
    expected_Dem_GaaOriginFilter[0] = 0U;
    expected_Dem_GaaDTCFormat[0] = 0U;
    expected_Dem_GaaCurDTCFilterStatusMask[0] = 85U;
    expected_Dem_GaaAllDtcStatus[0] = 85U;
    expected_Dem_GaaSuppressionStatus[0] = 0U;

    START_TEST("81: Dem_FilterEvent",
               "created to solve true case of LblSuppressionStatus == DEM_FALSE at line number 4368");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_FilterEvent(LusEventIndex, LucClientId);

            /* Test case checks */
//            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_82(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventIndex = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    Dem_GaaCurDTCFilter[0] = 1024U;
    Dem_GaaOriginFilter[0] = 0U;
    Dem_GaaAllFDC[0] = 85;
    Dem_GaaDTCFormat[0] = 0U;
    Dem_GaaCurDTCFilterStatusMask[0] = 85U;
    Dem_GaaAllDtcStatus[0] = 85U;
    Dem_GaaSuppressionStatus[0] = 0U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    expected_Dem_GaaCurDTCFilter[0] = 1024U;
    expected_Dem_GaaOriginFilter[0] = 0U;
    expected_Dem_GaaAllFDC[0] = 85;
    expected_Dem_GaaDTCFormat[0] = 0U;
    expected_Dem_GaaCurDTCFilterStatusMask[0] = 85U;
    expected_Dem_GaaAllDtcStatus[0] = 85U;
    expected_Dem_GaaSuppressionStatus[0] = 0U;

    START_TEST("82: Dem_FilterEvent",
               "created to solve true case of ((Dem_GaaCurDTCFilter[LucClientId] & (uint16)DEM_FDC_MASK) >> DEM_TEN) ==      (uint16)DEM_DTC_FILTER_FOR_FDC_YES between lines 4425 and 4426");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1;SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_FilterEvent(LusEventIndex, LucClientId);

            /* Test case checks */
//            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_83(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventIndex = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    Dem_GaaCurDTCFilter[0] = 1024U;
    Dem_GaaOriginFilter[0] = 0U;
    Dem_GaaAllFDC[0] = 127;
    Dem_GaaDTCFormat[0] = 0U;
    Dem_GaaCurDTCFilterStatusMask[0] = 85U;
    Dem_GaaAllDtcStatus[0] = 85U;
    Dem_GaaSuppressionStatus[0] = 0U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    expected_Dem_GaaCurDTCFilter[0] = 1024U;
    expected_Dem_GaaOriginFilter[0] = 0U;
    expected_Dem_GaaAllFDC[0] = 127;
    expected_Dem_GaaDTCFormat[0] = 0U;
    expected_Dem_GaaCurDTCFilterStatusMask[0] = 85U;
    expected_Dem_GaaAllDtcStatus[0] = 85U;
    expected_Dem_GaaSuppressionStatus[0] = 0U;

    START_TEST("83: Dem_FilterEvent",
               "created to solve true case of Dem_GaaAllFDC[LusEventIndex] == (sint8)(DEM_FDC_COUNTER_MAX) at line number 4436");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1;SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_FilterEvent(LusEventIndex, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_84(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventIndex = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    Dem_GaaCurDTCFilter[0] = 1024U;
    Dem_GaaOriginFilter[0] = 0U;
    Dem_GaaAllFDC[0] = 0;
    Dem_GaaDTCFormat[0] = 0U;
    Dem_GaaCurDTCFilterStatusMask[0] = 85U;
    Dem_GaaAllDtcStatus[0] = 85U;
    Dem_GaaSuppressionStatus[0] = 0U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    expected_Dem_GaaCurDTCFilter[0] = 1024U;
    expected_Dem_GaaOriginFilter[0] = 0U;
    expected_Dem_GaaAllFDC[0] = 0;
    expected_Dem_GaaDTCFormat[0] = 0U;
    expected_Dem_GaaCurDTCFilterStatusMask[0] = 85U;
    expected_Dem_GaaAllDtcStatus[0] = 85U;
    expected_Dem_GaaSuppressionStatus[0] = 0U;

    START_TEST("84: Dem_FilterEvent",
               "created to solve true case of Dem_GaaAllFDC[LusEventIndex] <= (sint8)DEM_ZERO at line number 4435");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1;SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_FilterEvent(LusEventIndex, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_85(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventIndex = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddDtcSeverity = 85U;
    Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    Dem_GaaCurDTCFilter[0] = 1U;
    Dem_GaaOriginFilter[0] = 0U;
    Dem_GaaDTCFormat[0] = 0U;
    Dem_GaaCurDTCFilterStatusMask[0] = 85U;
    Dem_GaaAllDtcStatus[0] = 85U;
    Dem_GaaSuppressionStatus[0] = 0U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcSeverity = 85U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    expected_Dem_GaaCurDTCFilter[0] = 1U;
    expected_Dem_GaaOriginFilter[0] = 0U;
    expected_Dem_GaaDTCFormat[0] = 0U;
    expected_Dem_GaaCurDTCFilterStatusMask[0] = 85U;
    expected_Dem_GaaAllDtcStatus[0] = 85U;
    expected_Dem_GaaSuppressionStatus[0] = 0U;

    START_TEST("85: Dem_FilterEvent",
               "created to solve true case of (Dem_GaaCurDTCFilter[LucClientId] & DEM_ONE) ==                                       (uint16)DEM_DTC_FILTER_WITH_SEVERITY_YES between lines 4412 and 4413");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_FilterEvent(LusEventIndex, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_86(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventIndex = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddDtcSeverity = 16U;
    Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    Dem_GaaCurDTCFilter[0] = 17U;
    Dem_GaaOriginFilter[0] = 0U;
    Dem_GaaDTCFormat[0] = 0U;
    Dem_GaaCurDTCFilterStatusMask[0] = 85U;
    Dem_GaaAllDtcStatus[0] = 85U;
    Dem_GaaSuppressionStatus[0] = 0U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcSeverity = 16U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    expected_Dem_GaaCurDTCFilter[0] = 17U;
    expected_Dem_GaaOriginFilter[0] = 0U;
    expected_Dem_GaaDTCFormat[0] = 0U;
    expected_Dem_GaaCurDTCFilterStatusMask[0] = 85U;
    expected_Dem_GaaAllDtcStatus[0] = 85U;
    expected_Dem_GaaSuppressionStatus[0] = 0U;

    START_TEST("86: Dem_FilterEvent",
               "created to solve false case of (((uint16)LddDtcSeverity) &        ((Dem_GaaCurDTCFilter[LucClientId] & (uint16)DEM_MASK1))) == DEM_ZERO between lines 4416 and 4417");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_FilterEvent(LusEventIndex, LucClientId);

            /* Test case checks */
//            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_87(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventIndex = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    Dem_GaaCurDTCFilter[0] = 0U;
    Dem_GaaOriginFilter[0] = 0U;
    Dem_GaaDTCFormat[0] = 0U;
    Dem_GaaCurDTCFilterStatusMask[0] = 0U;
    Dem_GaaAllDtcStatus[0] = 0U;
    Dem_GaaSuppressionStatus[0] = 0U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    expected_Dem_GaaCurDTCFilter[0] = 0U;
    expected_Dem_GaaOriginFilter[0] = 0U;
    expected_Dem_GaaDTCFormat[0] = 0U;
    expected_Dem_GaaCurDTCFilterStatusMask[0] = 0U;
    expected_Dem_GaaAllDtcStatus[0] = 0U;
    expected_Dem_GaaSuppressionStatus[0] = 0U;

    START_TEST("87: Dem_FilterEvent",
               "created to solve true case of (LucStatus & Dem_GaaCurDTCFilterStatusMask[LucClientId] &           DEM_EVENTSTATUS_BIT2_SET) != DEM_EVENTSTATUS_BIT2_SET between lines 4402 and 4403");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_FilterEvent(LusEventIndex, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_88(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventIndex = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    Dem_GaaCurDTCFilter[0] = 0U;
    Dem_GaaOriginFilter[0] = 0U;
    Dem_GaaDTCFormat[0] = 0U;
    Dem_GaaCurDTCFilterStatusMask[0] = 8U;
    Dem_GaaAllDtcStatus[0] = 8U;
    Dem_GaaSuppressionStatus[0] = 0U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    expected_Dem_GaaCurDTCFilter[0] = 0U;
    expected_Dem_GaaOriginFilter[0] = 0U;
    expected_Dem_GaaDTCFormat[0] = 0U;
    expected_Dem_GaaCurDTCFilterStatusMask[0] = 8U;
    expected_Dem_GaaAllDtcStatus[0] = 8U;
    expected_Dem_GaaSuppressionStatus[0] = 0U;

    START_TEST("88: Dem_FilterEvent",
               "created to solve false case of (LucStatus & Dem_GaaCurDTCFilterStatusMask[LucClientId] &            DEM_EVENTSTATUS_BIT3_SET) != DEM_EVENTSTATUS_BIT3_SET between lines 4404 and 4405");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_FilterEvent(LusEventIndex, LucClientId);

            /* Test case checks */
//            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_89(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventIndex = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    Dem_GaaCurDTCFilter[0] = 0U;
    Dem_GaaOriginFilter[0] = 3U;
    Dem_GaaDTCFormat[0] = 0U;
    Dem_GaaSuppressionStatus[0] = 0U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
    expected_Dem_GaaCurDTCFilter[0] = 0U;
    expected_Dem_GaaOriginFilter[0] = 3U;
    expected_Dem_GaaDTCFormat[0] = 0U;
    expected_Dem_GaaSuppressionStatus[0] = 0U;

    START_TEST("89: Dem_FilterEvent",
               "created to solve false case of Dem_GaaOriginFilter[LucClientId] != DEM_DTC_ORIGIN_PERMANENT_MEMORY at line number 4400");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_FilterEvent(LusEventIndex, LucClientId);

            /* Test case checks */
//            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_90(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventIndex = 0U;
    uint8 LucClientId = 0U;
    Std_ReturnType returnValue;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddDtcFormat[0] = 1U;
    Dem_GaaCurDTCFilter[0] = 0U;
    Dem_GaaOriginFilter[0] = 0U;
    Dem_GaaDTCFormat[0] = 0U;
    Dem_GaaCurDTCFilterStatusMask[0] = 85U;
    Dem_GaaAllDtcStatus[0] = 85U;
    Dem_GaaSuppressionStatus[0] = 0U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[0] = 1U;
    expected_Dem_GaaCurDTCFilter[0] = 0U;
    expected_Dem_GaaOriginFilter[0] = 0U;
    expected_Dem_GaaDTCFormat[0] = 0U;
    expected_Dem_GaaCurDTCFilterStatusMask[0] = 85U;
    expected_Dem_GaaAllDtcStatus[0] = 85U;
    expected_Dem_GaaSuppressionStatus[0] = 0U;

    START_TEST("90: Dem_FilterEvent",
               "created to solve false case of DEM_TRUE != LblDtcFormat at line number 4387");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            returnValue = Dem_FilterEvent(LusEventIndex, LucClientId);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_91(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8* LpDestBuffer = &map_LpDestBuffer[0];
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaAllFDC[0] = 85;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaAllFDC[0] = 85;
    expected_map_LpDestBuffer[0] = 85U;

    START_TEST("91: Dem_GetMaxFdcOfDtc",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_GetMaxFdcOfDtc(LpDestBuffer, LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_92(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8* LpDestBuffer = &map_LpDestBuffer[0];
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 2U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[1] = 0U;
    Dem_GaaAllFDC[0] = 85;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 2U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[1] = 0U;
    expected_Dem_GaaAllFDC[0] = 85;
    expected_map_LpDestBuffer[0] = 85U;

    START_TEST("92: Dem_GetMaxFdcOfDtc",
               "created to solve true case of LusCombinedEvent <      LusNoOfCombinedEvents between lines 4525 and 4526");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_GetMaxFdcOfDtc(LpDestBuffer, LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_93(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8* LpDestBuffer = &map_LpDestBuffer[0];
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 2U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[1] = 0U;
    Dem_GaaAllFDC[0] = 127;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 2U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[1] = 0U;
    expected_Dem_GaaAllFDC[0] = 127;
    expected_map_LpDestBuffer[0] = 127U;

    START_TEST("93: Dem_GetMaxFdcOfDtc",
               "created to solve true case of DEM_FDC_COUNTER_MAX == Dem_GaaAllFDC[LusEventIndex] at line number 4553");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_GetMaxFdcOfDtc(LpDestBuffer, LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_94(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8* LpDestBuffer = &map_LpDestBuffer[0];
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 1U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaAllFDC[0] = 85;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 1U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaAllFDC[0] = 85;
    expected_map_LpDestBuffer[0] = 85U;

    START_TEST("94: Dem_GetMaxFdcOfDtc",
               "created to solve true case of DEM_ONE == LusNoOfCombinedEvents at line number 4510");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_GetMaxFdcOfDtc(LpDestBuffer, LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_95(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint8 LucServiceId = 85U;
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = NULL;
    const Dem_EventMemory * LpEventMemory = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = NULL;
    uint8 LucFreeIndex = 85U;
    uint8 LucNumOfEDRecords = 85U;
    boolean * LblRecFound = &map_LblRecFound[0];
    Std_ReturnType returnValue;
    map_LblRecFound[0] = 85U;
    expected_map_LblRecFound[0] = 85U;

    START_TEST("95: Dem_CheckExtendedDataRecord",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_CheckExtendedDataRecord(RecordNumber, LucServiceId, DestBuffer, BufSize, LpEventMemory, LpDTCAttribute, LucFreeIndex, LucNumOfEDRecords, LblRecFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_96(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint8 LucServiceId = 85U;
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = &map_BufSize[0];
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_4[0];
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute[0];
    uint8 LucFreeIndex = 85U;
    uint8 LucNumOfEDRecords = 85U;
    boolean * LblRecFound = &map_LblRecFound[0];
    Std_ReturnType returnValue;
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    Dem_GaaEDRecord[0].ucNumOfDataElements = 1U;
    Dem_GaaEDRecord[0].aaDataElementType[0] = 85U;
    map_LblRecFound[0] = 0U;
    map_LpEventMemory_4[85].aaEdData[0][0] = 85U;
    map_LpDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_Dem_GaaEDRecord[0].ucNumOfDataElements = 1U;
    expected_Dem_GaaEDRecord[0].aaDataElementType[0] = 85U;
    expected_map_LpEventMemory_4[85].aaEdData[0][0] = 85U;
    expected_map_LpDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LblRecFound[0] = 1U;
    expected_map_BufSize[0] = 0U;

    START_TEST("96: Dem_CheckExtendedDataRecord",
               "created to solve false case of LucDataElementIndex <          Dem_GaaEDRecord[LucActualRecordIndex].          ucNumOfDataElements between lines 4675 and 4677");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_CheckExtendedDataRecord(RecordNumber, LucServiceId, DestBuffer, BufSize, LpEventMemory, LpDTCAttribute, LucFreeIndex, LucNumOfEDRecords, LblRecFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_97(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint8 LucServiceId = 85U;
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = &map_BufSize[0];
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_4[0];
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute[0];
    uint8 LucFreeIndex = 85U;
    uint8 LucNumOfEDRecords = 1U;
    boolean * LblRecFound = &map_LblRecFound[0];
    Std_ReturnType returnValue;
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    Dem_GaaEDRecord[0].ucNumOfDataElements = 1U;
    Dem_GaaEDRecord[0].aaDataElementType[0] = 85U;
    map_LblRecFound[0] = 0U;
    map_LpEventMemory_4[85].aaEdData[0][0] = 85U;
    map_LpDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_Dem_GaaEDRecord[0].ucNumOfDataElements = 1U;
    expected_Dem_GaaEDRecord[0].aaDataElementType[0] = 85U;
    expected_map_LpEventMemory_4[85].aaEdData[0][0] = 85U;
    expected_map_LpDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LblRecFound[0] = 1U;
    expected_map_BufSize[0] = 0U;

    START_TEST("97: Dem_CheckExtendedDataRecord",
               "created to solve false case of LucRecIndex < LucNumOfEDRecords at line number 4643");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_CheckExtendedDataRecord(RecordNumber, LucServiceId, DestBuffer, BufSize, LpEventMemory, LpDTCAttribute, LucFreeIndex, LucNumOfEDRecords, LblRecFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_98(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint8 LucServiceId = 85U;
    uint8 * DestBuffer = &map_DestBuffer[0];
    uint16 * BufSize = &map_BufSize[0];
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_4[0];
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute[0];
    uint8 LucFreeIndex = 85U;
    uint8 LucNumOfEDRecords = 85U;
    boolean * LblRecFound = &map_LblRecFound[0];
    Std_ReturnType returnValue;
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    Dem_GaaEDRecord[0].ucNumOfDataElements = 1U;
    Dem_GaaEDRecord[0].aaDataElementType[0] = 1U;
    Dem_GaaEDRecord[0].aaDataElementIndex[0] = 0U;
    Dem_GaaDataElementExternalCS[0].ucDemDataElementDataSize = 1U;
    map_LblRecFound[0] = 0U;
    map_LpEventMemory_4[85].aaEdData[0][0] = 85U;
    map_LpEventMemory_4[85].aaEdData[0][1] = 85U;
    map_LpDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_Dem_GaaEDRecord[0].ucNumOfDataElements = 1U;
    expected_Dem_GaaEDRecord[0].aaDataElementType[0] = 1U;
    expected_Dem_GaaEDRecord[0].aaDataElementIndex[0] = 0U;
    expected_Dem_GaaDataElementExternalCS[0].ucDemDataElementDataSize = 1U;
    expected_map_LpEventMemory_4[85].aaEdData[0][0] = 85U;
    expected_map_LpEventMemory_4[85].aaEdData[0][1] = 85U;
    expected_map_LpDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LblRecFound[0] = 1U;
    expected_map_DestBuffer[0] = 85U;
    expected_map_BufSize[0] = 1U;

    START_TEST("98: Dem_CheckExtendedDataRecord",
               "created to solve false case of LucDataElementIndex <          Dem_GaaEDRecord[LucActualRecordIndex].          ucNumOfDataElements between lines 4675 and 4677");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_CheckExtendedDataRecord(RecordNumber, LucServiceId, DestBuffer, BufSize, LpEventMemory, LpDTCAttribute, LucFreeIndex, LucNumOfEDRecords, LblRecFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_99(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 1U;
    uint8 LucServiceId = 85U;
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = NULL;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_4[0];
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute[0];
    uint8 LucFreeIndex = 85U;
    uint8 LucNumOfEDRecords = 1U;
    boolean * LblRecFound = &map_LblRecFound[0];
    Std_ReturnType returnValue;
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    map_LblRecFound[0] = 0U;
    map_LpEventMemory_4[85].aaEdData[0][0] = 1U;
    map_LpDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    expected_map_LblRecFound[0] = 0U;
    expected_map_LpEventMemory_4[85].aaEdData[0][0] = 1U;
    expected_map_LpDTCAttribute[0].aaExtendedDataRecords[0] = 0U;

    START_TEST("99: Dem_CheckExtendedDataRecord",
               "created to solve false case of LucRecIndex < LucNumOfEDRecords at line number 4643");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_CheckExtendedDataRecord(RecordNumber, LucServiceId, DestBuffer, BufSize, LpEventMemory, LpDTCAttribute, LucFreeIndex, LucNumOfEDRecords, LblRecFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_100(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 0U;
    uint8 LucServiceId = 85U;
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = NULL;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_4[0];
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute[0];
    uint8 LucFreeIndex = 85U;
    uint8 LucNumOfEDRecords = 1U;
    boolean * LblRecFound = &map_LblRecFound[0];
    Std_ReturnType returnValue;
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    map_LblRecFound[0] = 0U;
    map_LpEventMemory_4[85].aaEdData[0][0] = 1U;
    map_LpDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_map_LblRecFound[0] = 0U;
    expected_map_LpEventMemory_4[85].aaEdData[0][0] = 1U;
    expected_map_LpDTCAttribute[0].aaExtendedDataRecords[0] = 0U;

    START_TEST("100: Dem_CheckExtendedDataRecord",
               "created to solve false case of LucRecIndex < LucNumOfEDRecords at line number 4643");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_CheckExtendedDataRecord(RecordNumber, LucServiceId, DestBuffer, BufSize, LpEventMemory, LpDTCAttribute, LucFreeIndex, LucNumOfEDRecords, LblRecFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_101(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 0U;
    uint8 LucServiceId = 85U;
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = NULL;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_4[0];
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute[0];
    uint8 LucFreeIndex = 85U;
    uint8 LucNumOfEDRecords = 85U;
    boolean * LblRecFound = &map_LblRecFound[0];
    Std_ReturnType returnValue;
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    map_LblRecFound[0] = 0U;
    map_LpEventMemory_4[85].aaEdData[0][0] = 1U;
    map_LpDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    expected_map_LpEventMemory_4[85].aaEdData[0][0] = 1U;
    expected_map_LpDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LblRecFound[0] = 1U;

    START_TEST("101: Dem_CheckExtendedDataRecord",
               "created to solve true case of Dem_GaaEDRecord      [LucActualRecordIndex].                         ucExtendedDataRecordNumber == RecordNumber between lines 4797 and 4799");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportRuntimeError#1");

            /* Call SUT */
            returnValue = Dem_CheckExtendedDataRecord(RecordNumber, LucServiceId, DestBuffer, BufSize, LpEventMemory, LpDTCAttribute, LucFreeIndex, LucNumOfEDRecords, LblRecFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_102(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucDataElement = 85U;
    Dem_DTCOriginType LucEventDestination = 0U;
    uint8* LpCurrentBufferIndex = NULL;
    uint8 LucFreeIndex = 85U;
    uint8 * DestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = NULL;

    START_TEST("102: Dem_EvaluateInternalExtdDataRcdIfOccOrAging",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_EvaluateInternalExtdDataRcdIfOccOrAging(LucDataElement, LucEventDestination, LpCurrentBufferIndex, LucFreeIndex, DestBuffer, LpDTCAttribute);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_103(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucDataElement = 0U;
    Dem_DTCOriginType LucEventDestination = 0U;
    uint8* LpCurrentBufferIndex = &map_LpCurrentBufferIndex[0];
    uint8 LucFreeIndex = 85U;
    uint8 * DestBuffer = &map_DestBuffer_1[0];
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_1[0];
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    map_LpDTCAttribute_1[0].blAgingAllowed = 85U;
    map_LpCurrentBufferIndex[0] = 85U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_map_LpDTCAttribute_1[0].blAgingAllowed = 85U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_map_LpCurrentBufferIndex[0] = 86U;
    expected_map_DestBuffer_1[85] = 255U;

    START_TEST("103: Dem_EvaluateInternalExtdDataRcdIfOccOrAging",
               "created to solve true case of LucDataElement == DEM_AGINGCTR_DOWNCNT at line number 5197");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_EvaluateInternalExtdDataRcdIfOccOrAging(LucDataElement, LucEventDestination, LpCurrentBufferIndex, LucFreeIndex, DestBuffer, LpDTCAttribute);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_104(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucDataElement = 0U;
    Dem_DTCOriginType LucEventDestination = 0U;
    uint8* LpCurrentBufferIndex = &map_LpCurrentBufferIndex[0];
    uint8 LucFreeIndex = 85U;
    uint8 * DestBuffer = &map_DestBuffer_1[0];
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_1[0];
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucAgingCounter = 85U;
    map_LpDTCAttribute_1[0].usAgingCycleCounterThreshold = 85U;
    map_LpDTCAttribute_1[0].blAgingAllowed = 1U;
    map_LpCurrentBufferIndex[0] = 85U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucAgingCounter = 85U;
    expected_map_LpDTCAttribute_1[0].usAgingCycleCounterThreshold = 85U;
    expected_map_LpDTCAttribute_1[0].blAgingAllowed = 1U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_map_LpCurrentBufferIndex[0] = 86U;
    expected_map_DestBuffer_1[85] = 0U;

    START_TEST("104: Dem_EvaluateInternalExtdDataRcdIfOccOrAging",
               "created to solve true case of LpDTCAttribute->blAgingAllowed == DEM_TRUE at line number 5206");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_EvaluateInternalExtdDataRcdIfOccOrAging(LucDataElement, LucEventDestination, LpCurrentBufferIndex, LucFreeIndex, DestBuffer, LpDTCAttribute);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_105(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucDataElement = 11U;
    Dem_DTCOriginType LucEventDestination = 0U;
    uint8* LpCurrentBufferIndex = &map_LpCurrentBufferIndex[0];
    uint8 LucFreeIndex = 85U;
    uint8 * DestBuffer = &map_DestBuffer_1[0];
    const Dem_DTCAttributeType * LpDTCAttribute = NULL;
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucAgingCounter = 85U;
    map_LpCurrentBufferIndex[0] = 85U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucAgingCounter = 85U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_map_LpCurrentBufferIndex[0] = 86U;
    expected_map_DestBuffer_1[85] = 86U;

    START_TEST("105: Dem_EvaluateInternalExtdDataRcdIfOccOrAging",
               "created to solve true case of DEM_AGINGCTR_UPCNT_FIRST_ACTIVE  == LucDataElement at line number 5169");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_EvaluateInternalExtdDataRcdIfOccOrAging(LucDataElement, LucEventDestination, LpCurrentBufferIndex, LucFreeIndex, DestBuffer, LpDTCAttribute);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_106(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucDataElement = 11U;
    Dem_DTCOriginType LucEventDestination = 0U;
    uint8* LpCurrentBufferIndex = &map_LpCurrentBufferIndex[0];
    uint8 LucFreeIndex = 85U;
    uint8 * DestBuffer = &map_DestBuffer_1[0];
    const Dem_DTCAttributeType * LpDTCAttribute = NULL;
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    Dem_GaaAllEvtStatus[0] = 85U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucAgingCounter = 0U;
    map_LpCurrentBufferIndex[0] = 85U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaAllEvtStatus[0] = 85U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucAgingCounter = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_map_LpCurrentBufferIndex[0] = 86U;
    expected_map_DestBuffer_1[85] = 1U;

    START_TEST("106: Dem_EvaluateInternalExtdDataRcdIfOccOrAging",
               "created to solve true case of LucAgingCounter == DEM_ZERO at line number 5184");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_EvaluateInternalExtdDataRcdIfOccOrAging(LucDataElement, LucEventDestination, LpCurrentBufferIndex, LucFreeIndex, DestBuffer, LpDTCAttribute);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_107(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucDataElement = 11U;
    Dem_DTCOriginType LucEventDestination = 0U;
    uint8* LpCurrentBufferIndex = &map_LpCurrentBufferIndex[0];
    uint8 LucFreeIndex = 85U;
    uint8 * DestBuffer = &map_DestBuffer_1[0];
    const Dem_DTCAttributeType * LpDTCAttribute = NULL;
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    Dem_GaaAllEvtStatus[0] = 0U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucAgingCounter = 0U;
    map_LpCurrentBufferIndex[0] = 85U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaAllEvtStatus[0] = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucAgingCounter = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_map_LpCurrentBufferIndex[0] = 86U;
    expected_map_DestBuffer_1[85] = 1U;

    START_TEST("107: Dem_EvaluateInternalExtdDataRcdIfOccOrAging",
               "created to solve true case of (LucEventStatus & DEM_EVENTSTATUS_BIT1_BIT6) == DEM_ZERO at line number 5185");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_EvaluateInternalExtdDataRcdIfOccOrAging(LucDataElement, LucEventDestination, LpCurrentBufferIndex, LucFreeIndex, DestBuffer, LpDTCAttribute);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_108(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucDataElement = 1U;
    Dem_DTCOriginType LucEventDestination = 0U;
    uint8* LpCurrentBufferIndex = &map_LpCurrentBufferIndex[0];
    uint8 LucFreeIndex = 85U;
    uint8 * DestBuffer = &map_DestBuffer_1[0];
    const Dem_DTCAttributeType * LpDTCAttribute = NULL;
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucAgingCounter = 85U;
    map_LpCurrentBufferIndex[0] = 85U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucAgingCounter = 85U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_map_LpCurrentBufferIndex[0] = 86U;
    expected_map_DestBuffer_1[85] = 85U;

    START_TEST("108: Dem_EvaluateInternalExtdDataRcdIfOccOrAging",
               "created to solve true case of DEM_AGINGCTR_UPCNT  == LucDataElement at line number 5156");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_EvaluateInternalExtdDataRcdIfOccOrAging(LucDataElement, LucEventDestination, LpCurrentBufferIndex, LucFreeIndex, DestBuffer, LpDTCAttribute);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_109(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucDataElement = 8U;
    Dem_DTCOriginType LucEventDestination = 0U;
    uint8* LpCurrentBufferIndex = &map_LpCurrentBufferIndex[0];
    uint8 LucFreeIndex = 85U;
    uint8 * DestBuffer = &map_DestBuffer_1[0];
    const Dem_DTCAttributeType * LpDTCAttribute = NULL;
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucOccuranceCounter = 85U;
    map_LpCurrentBufferIndex[0] = 85U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucOccuranceCounter = 85U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_map_LpCurrentBufferIndex[0] = 86U;
    expected_map_DestBuffer_1[85] = 85U;

    START_TEST("109: Dem_EvaluateInternalExtdDataRcdIfOccOrAging",
               "created to solve true case of DEM_OCCCTR  == LucDataElement at line number 5137");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_EvaluateInternalExtdDataRcdIfOccOrAging(LucDataElement, LucEventDestination, LpCurrentBufferIndex, LucFreeIndex, DestBuffer, LpDTCAttribute);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_110(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucDataElement = 8U;
    Dem_DTCOriginType LucEventDestination = 0U;
    uint8* LpCurrentBufferIndex = &map_LpCurrentBufferIndex[0];
    uint8 LucFreeIndex = 85U;
    uint8 * DestBuffer = &map_DestBuffer_1[0];
    const Dem_DTCAttributeType * LpDTCAttribute = NULL;
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucOccuranceCounter = 85U;
    map_LpCurrentBufferIndex[0] = 255U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucOccuranceCounter = 85U;
    expected_map_LpCurrentBufferIndex[0] = 255U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = &map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[0];
    expected_map_DestBuffer_1[255] = 85U;

    START_TEST("110: Dem_EvaluateInternalExtdDataRcdIfOccOrAging",
               "created to solve false case of DEM_OCC_MAX > *LpCurrentBufferIndex at line number 5148");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_EvaluateInternalExtdDataRcdIfOccOrAging(LucDataElement, LucEventDestination, LpCurrentBufferIndex, LucFreeIndex, DestBuffer, LpDTCAttribute);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_111(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint8 LucMemoryIndex = 85U;
    boolean * LblRecordFound = &map_LblRecordFound[0];
    uint16 DataId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_5[0];
    uint8* LpDestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_2[0];
    Std_ReturnType returnValue;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    map_LpDTCAttribute_2[0].ucMaxNumOfFFRecord = 85U;
    map_LblRecordFound[0] = 85U;
    map_LpEventMemory_5[0].ddEventId = 0U;
    map_LpEventMemory_5[0].ucNumOfFF = 85U;
    map_LpEventMemory_5[0].ucOccuranceCounter = 85U;
    map_LpEventMemory_5[0].ucAgingCounter = 85U;
    map_LpEventMemory_5[0].ucPreviousIndex = 85U;
    map_LpEventMemory_5[0].ucNextEventIdIndex = 85U;
    map_LpEventMemory_5[85].ddEventId = 0U;
    map_LpEventMemory_5[85].ucNumOfFF = 85U;
    map_LpEventMemory_5[85].ucOccuranceCounter = 85U;
    map_LpEventMemory_5[85].ucAgingCounter = 85U;
    map_LpEventMemory_5[85].ucPreviousIndex = 85U;
    map_LpEventMemory_5[85].ucNextEventIdIndex = 85U;
    map_LpEventMemory_5[85].aaFFRecNumAndData[0][0] = 85U;
    map_LpEventMemory_5[85].aaFFRecNumAndData[0][1] = 85;
    map_LpEventMemory_5[85].aaFFRecNumAndData[0][2] = 85;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_map_LpDTCAttribute_2[0].ucMaxNumOfFFRecord = 85U;
    expected_map_LpEventMemory_5[0].ddEventId = 0U;
    expected_map_LpEventMemory_5[0].ucNumOfFF = 85U;
    expected_map_LpEventMemory_5[0].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_5[0].ucAgingCounter = 85U;
    expected_map_LpEventMemory_5[0].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_5[0].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_5[85].ddEventId = 0U;
    expected_map_LpEventMemory_5[85].ucNumOfFF = 85U;
    expected_map_LpEventMemory_5[85].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_5[85].ucAgingCounter = 85U;
    expected_map_LpEventMemory_5[85].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_5[85].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_5[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_LpEventMemory_5[85].aaFFRecNumAndData[0][1] = 85;
    expected_map_LpEventMemory_5[85].aaFFRecNumAndData[0][2] = 85;
    expected_map_LblRecordFound[0] = 1U;

    START_TEST("111: Dem_SearchInMemory",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#1");

            /* Call SUT */
            returnValue = Dem_SearchInMemory(RecordNumber, LucMemoryIndex, LblRecordFound, DataId, LpEventMemory, LpDestBuffer, LpDTCAttribute);

            /* Test case checks */
//            CHECK_U_CHAR(returnValue, 85U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_112(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint8 LucMemoryIndex = 85U;
    boolean * LblRecordFound = &map_LblRecordFound[0];
    uint16 DataId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_5[0];
    uint8* LpDestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_2[0];
    Std_ReturnType returnValue;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    map_LpDTCAttribute_2[0].ucMaxNumOfFFRecord = 1U;
    map_LblRecordFound[0] = 85U;
    map_LpEventMemory_5[0].ddEventId = 0U;
    map_LpEventMemory_5[0].ucNumOfFF = 85U;
    map_LpEventMemory_5[0].ucOccuranceCounter = 85U;
    map_LpEventMemory_5[0].ucAgingCounter = 85U;
    map_LpEventMemory_5[0].ucPreviousIndex = 85U;
    map_LpEventMemory_5[0].ucNextEventIdIndex = 85U;
    map_LpEventMemory_5[85].ddEventId = 0U;
    map_LpEventMemory_5[85].ucNumOfFF = 85U;
    map_LpEventMemory_5[85].ucOccuranceCounter = 85U;
    map_LpEventMemory_5[85].ucAgingCounter = 85U;
    map_LpEventMemory_5[85].ucPreviousIndex = 85U;
    map_LpEventMemory_5[85].ucNextEventIdIndex = 85U;
    map_LpEventMemory_5[85].aaFFRecNumAndData[0][0] = 85U;
    map_LpEventMemory_5[85].aaFFRecNumAndData[0][1] = 85;
    map_LpEventMemory_5[85].aaFFRecNumAndData[0][2] = 85;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_map_LpDTCAttribute_2[0].ucMaxNumOfFFRecord = 1U;
    expected_map_LpEventMemory_5[0].ddEventId = 0U;
    expected_map_LpEventMemory_5[0].ucNumOfFF = 85U;
    expected_map_LpEventMemory_5[0].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_5[0].ucAgingCounter = 85U;
    expected_map_LpEventMemory_5[0].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_5[0].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_5[85].ddEventId = 0U;
    expected_map_LpEventMemory_5[85].ucNumOfFF = 85U;
    expected_map_LpEventMemory_5[85].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_5[85].ucAgingCounter = 85U;
    expected_map_LpEventMemory_5[85].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_5[85].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_5[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_LpEventMemory_5[85].aaFFRecNumAndData[0][1] = 85;
    expected_map_LpEventMemory_5[85].aaFFRecNumAndData[0][2] = 85;
    expected_map_LblRecordFound[0] = 1U;

    START_TEST("112: Dem_SearchInMemory",
               "created to solve false case of LucRecordCount <      LucRecordCntCmpVal between lines 5322 and 5323");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#1");

            /* Call SUT */
            returnValue = Dem_SearchInMemory(RecordNumber, LucMemoryIndex, LblRecordFound, DataId, LpEventMemory, LpDestBuffer, LpDTCAttribute);

            /* Test case checks */
//            CHECK_U_CHAR(returnValue, 85U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_113(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint8 LucMemoryIndex = 85U;
    boolean * LblRecordFound = &map_LblRecordFound[0];
    uint16 DataId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_5[0];
    uint8* LpDestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_2[0];
    Std_ReturnType returnValue;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    map_LpDTCAttribute_2[0].ucMaxNumOfFFRecord = 85U;
    map_LblRecordFound[0] = 85U;
    map_LpEventMemory_5[0].ddEventId = 0U;
    map_LpEventMemory_5[0].ucNumOfFF = 85U;
    map_LpEventMemory_5[0].ucOccuranceCounter = 85U;
    map_LpEventMemory_5[0].ucAgingCounter = 85U;
    map_LpEventMemory_5[0].ucPreviousIndex = 85U;
    map_LpEventMemory_5[0].ucNextEventIdIndex = 85U;
    map_LpEventMemory_5[85].ddEventId = 0U;
    map_LpEventMemory_5[85].ucNumOfFF = 85U;
    map_LpEventMemory_5[85].ucOccuranceCounter = 85U;
    map_LpEventMemory_5[85].ucAgingCounter = 85U;
    map_LpEventMemory_5[85].ucPreviousIndex = 85U;
    map_LpEventMemory_5[85].ucNextEventIdIndex = 85U;
    map_LpEventMemory_5[85].aaFFRecNumAndData[0][0] = 85U;
    map_LpEventMemory_5[85].aaFFRecNumAndData[0][1] = 85;
    map_LpEventMemory_5[85].aaFFRecNumAndData[0][2] = 85;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_map_LpDTCAttribute_2[0].ucMaxNumOfFFRecord = 85U;
    expected_map_LpEventMemory_5[0].ddEventId = 0U;
    expected_map_LpEventMemory_5[0].ucNumOfFF = 85U;
    expected_map_LpEventMemory_5[0].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_5[0].ucAgingCounter = 85U;
    expected_map_LpEventMemory_5[0].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_5[0].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_5[85].ddEventId = 0U;
    expected_map_LpEventMemory_5[85].ucNumOfFF = 85U;
    expected_map_LpEventMemory_5[85].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_5[85].ucAgingCounter = 85U;
    expected_map_LpEventMemory_5[85].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_5[85].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_5[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_LpEventMemory_5[85].aaFFRecNumAndData[0][1] = 85;
    expected_map_LpEventMemory_5[85].aaFFRecNumAndData[0][2] = 85;
    expected_map_LblRecordFound[0] = 1U;

    START_TEST("113: Dem_SearchInMemory",
               "created to solve true case of E_NOT_OK  == LddReturnValue at line number 5338");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#1");

            /* Call SUT */
            returnValue = Dem_SearchInMemory(RecordNumber, LucMemoryIndex, LblRecordFound, DataId, LpEventMemory, LpDestBuffer, LpDTCAttribute);

            /* Test case checks */
//            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_114(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 1U;
    uint8 LucMemoryIndex = 85U;
    boolean * LblRecordFound = &map_LblRecordFound[0];
    uint16 DataId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_5[0];
    uint8* LpDestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_2[0];
    Std_ReturnType returnValue;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    map_LpDTCAttribute_2[0].ucMaxNumOfFFRecord = 1U;
    map_LblRecordFound[0] = 85U;
    map_LpEventMemory_5[85].aaFFRecNumAndData[0][0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_map_LpDTCAttribute_2[0].ucMaxNumOfFFRecord = 1U;
    expected_map_LblRecordFound[0] = 85U;
    expected_map_LpEventMemory_5[85].aaFFRecNumAndData[0][0] = 0U;

    START_TEST("114: Dem_SearchInMemory",
               "created to solve false case of LucRecordCount <      LucRecordCntCmpVal between lines 5322 and 5323");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#1");

            /* Call SUT */
            returnValue = Dem_SearchInMemory(RecordNumber, LucMemoryIndex, LblRecordFound, DataId, LpEventMemory, LpDestBuffer, LpDTCAttribute);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_115(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint8 LucMemoryIndex = 85U;
    boolean * LblRecordFound = &map_LblRecordFound[0];
    uint16 DataId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_5[0];
    uint8* LpDestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_2[0];
    Std_ReturnType returnValue;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 1U;
    map_LpDTCAttribute_2[0].ucNumOfFFRecNum = 85U;
    map_LblRecordFound[0] = 85U;
    map_LpEventMemory_5[0].ddEventId = 0U;
    map_LpEventMemory_5[0].ucNumOfFF = 85U;
    map_LpEventMemory_5[0].ucOccuranceCounter = 85U;
    map_LpEventMemory_5[0].ucAgingCounter = 85U;
    map_LpEventMemory_5[0].ucPreviousIndex = 85U;
    map_LpEventMemory_5[0].ucNextEventIdIndex = 85U;
    map_LpEventMemory_5[85].ddEventId = 0U;
    map_LpEventMemory_5[85].ucNumOfFF = 85U;
    map_LpEventMemory_5[85].ucOccuranceCounter = 85U;
    map_LpEventMemory_5[85].ucAgingCounter = 85U;
    map_LpEventMemory_5[85].ucPreviousIndex = 85U;
    map_LpEventMemory_5[85].ucNextEventIdIndex = 85U;
    map_LpEventMemory_5[85].aaFFRecNumAndData[0][0] = 85U;
    map_LpEventMemory_5[85].aaFFRecNumAndData[0][1] = 85;
    map_LpEventMemory_5[85].aaFFRecNumAndData[0][2] = 85;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 1U;
    expected_map_LpDTCAttribute_2[0].ucNumOfFFRecNum = 85U;
    expected_map_LpEventMemory_5[0].ddEventId = 0U;
    expected_map_LpEventMemory_5[0].ucNumOfFF = 85U;
    expected_map_LpEventMemory_5[0].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_5[0].ucAgingCounter = 85U;
    expected_map_LpEventMemory_5[0].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_5[0].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_5[85].ddEventId = 0U;
    expected_map_LpEventMemory_5[85].ucNumOfFF = 85U;
    expected_map_LpEventMemory_5[85].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_5[85].ucAgingCounter = 85U;
    expected_map_LpEventMemory_5[85].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_5[85].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_5[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_LpEventMemory_5[85].aaFFRecNumAndData[0][1] = 85;
    expected_map_LpEventMemory_5[85].aaFFRecNumAndData[0][2] = 85;
    expected_map_LblRecordFound[0] = 1U;

    START_TEST("115: Dem_SearchInMemory",
               "created to solve true case of Dem_GaaDTCOriginBasedPtrAddress[LucMemIndx].ucFfRecordEnumType == \\       DEM_FF_RECNUM_CONFIGURED between lines 5311 and 5312");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#1");

            /* Call SUT */
            returnValue = Dem_SearchInMemory(RecordNumber, LucMemoryIndex, LblRecordFound, DataId, LpEventMemory, LpDestBuffer, LpDTCAttribute);

            /* Test case checks */
//            CHECK_U_CHAR(returnValue, 85U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_116(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 255U;
    uint8 LucMemoryIndex = 85U;
    boolean * LblRecordFound = NULL;
    uint16 DataId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_5[0];
    uint8* LpDestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = NULL;
    Std_ReturnType returnValue;
    map_LpEventMemory_5[0].ddEventId = 0U;
    map_LpEventMemory_5[0].ucNumOfFF = 85U;
    map_LpEventMemory_5[0].ucOccuranceCounter = 85U;
    map_LpEventMemory_5[0].ucAgingCounter = 85U;
    map_LpEventMemory_5[0].ucPreviousIndex = 85U;
    map_LpEventMemory_5[0].ucNextEventIdIndex = 85U;
    map_LpEventMemory_5[85].ddEventId = 0U;
    map_LpEventMemory_5[85].ucNumOfFF = 85U;
    map_LpEventMemory_5[85].ucOccuranceCounter = 85U;
    map_LpEventMemory_5[85].ucAgingCounter = 85U;
    map_LpEventMemory_5[85].ucPreviousIndex = 85U;
    map_LpEventMemory_5[85].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_5[0].ddEventId = 0U;
    expected_map_LpEventMemory_5[0].ucNumOfFF = 85U;
    expected_map_LpEventMemory_5[0].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_5[0].ucAgingCounter = 85U;
    expected_map_LpEventMemory_5[0].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_5[0].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_5[85].ddEventId = 0U;
    expected_map_LpEventMemory_5[85].ucNumOfFF = 85U;
    expected_map_LpEventMemory_5[85].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_5[85].ucAgingCounter = 85U;
    expected_map_LpEventMemory_5[85].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_5[85].ucNextEventIdIndex = 85U;

    START_TEST("116: Dem_SearchInMemory",
               "created to solve true case of DEM_MAX_RECORD  == RecordNumber at line number 5279");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_GetDidData#3");

            /* Call SUT */
            returnValue = Dem_SearchInMemory(RecordNumber, LucMemoryIndex, LblRecordFound, DataId, LpEventMemory, LpDestBuffer, LpDTCAttribute);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 85U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_117(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 255U;
    uint8 LucMemoryIndex = 85U;
    boolean * LblRecordFound = NULL;
    uint16 DataId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_5[0];
    uint8* LpDestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = NULL;
    Std_ReturnType returnValue;
    map_LpEventMemory_5[0].ddEventId = 0U;
    map_LpEventMemory_5[0].ucNumOfFF = 85U;
    map_LpEventMemory_5[0].ucOccuranceCounter = 85U;
    map_LpEventMemory_5[0].ucAgingCounter = 85U;
    map_LpEventMemory_5[0].ucPreviousIndex = 85U;
    map_LpEventMemory_5[0].ucNextEventIdIndex = 85U;
    map_LpEventMemory_5[85].ddEventId = 0U;
    map_LpEventMemory_5[85].ucNumOfFF = 85U;
    map_LpEventMemory_5[85].ucOccuranceCounter = 85U;
    map_LpEventMemory_5[85].ucAgingCounter = 85U;
    map_LpEventMemory_5[85].ucPreviousIndex = 85U;
    map_LpEventMemory_5[85].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_5[0].ddEventId = 0U;
    expected_map_LpEventMemory_5[0].ucNumOfFF = 85U;
    expected_map_LpEventMemory_5[0].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_5[0].ucAgingCounter = 85U;
    expected_map_LpEventMemory_5[0].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_5[0].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_5[85].ddEventId = 0U;
    expected_map_LpEventMemory_5[85].ucNumOfFF = 85U;
    expected_map_LpEventMemory_5[85].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_5[85].ucAgingCounter = 85U;
    expected_map_LpEventMemory_5[85].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_5[85].ucNextEventIdIndex = 85U;

    START_TEST("117: Dem_SearchInMemory",
               "created to solve true case of E_NOT_OK  == LddReturnValue at line number 5293");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_GetDidData#4");

            /* Call SUT */
            returnValue = Dem_SearchInMemory(RecordNumber, LucMemoryIndex, LblRecordFound, DataId, LpEventMemory, LpDestBuffer, LpDTCAttribute);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_118(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 255U;
    uint8 LucMemoryIndex = 85U;
    boolean * LblRecordFound = NULL;
    uint16 DataId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_5[0];
    uint8* LpDestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = NULL;
    Std_ReturnType returnValue;
    map_LpEventMemory_5[85].ucNumOfFF = 0U;
    expected_map_LpEventMemory_5[85].ucNumOfFF = 0U;

    START_TEST("118: Dem_SearchInMemory",
               "created to solve false case of (LpEventMemory + LucMemoryIndex)->ucNumOfFF > DEM_ZERO at line number 5284");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_SearchInMemory(RecordNumber, LucMemoryIndex, LblRecordFound, DataId, LpEventMemory, LpDestBuffer, LpDTCAttribute);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_119(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint8 LucServiceId = 85U;
    uint16 DataId = 0U;
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_3[0];
    Std_ReturnType returnValue;
    Dem_GaaDid[0].usDid = 0U;
    map_LpDTCAttribute_3[0].ucNumOfDataId = 85U;
    map_LpDTCAttribute_3[0].aaDataIdArray[0] = 0U;
    map_LpDTCAttribute_3[0].ucMaxNumOfFFRecord = 85U;
    expected_Dem_GaaDid[0].usDid = 0U;
    expected_map_LpDTCAttribute_3[0].ucNumOfDataId = 85U;
    expected_map_LpDTCAttribute_3[0].aaDataIdArray[0] = 0U;
    expected_map_LpDTCAttribute_3[0].ucMaxNumOfFFRecord = 85U;

    START_TEST("119: Dem_CheckforValidRecord",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportRuntimeError#1");

            /* Call SUT */
            returnValue = Dem_CheckforValidRecord(RecordNumber, LucServiceId, DataId, LpDTCAttribute);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_120(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint8 LucServiceId = 85U;
    uint16 DataId = 0U;
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_3[0];
    Std_ReturnType returnValue;
    Dem_GaaDid[0].usDid = 0U;
    map_LpDTCAttribute_3[0].ucNumOfDataId = 1U;
    map_LpDTCAttribute_3[0].aaDataIdArray[0] = 0U;
    map_LpDTCAttribute_3[0].ucMaxNumOfFFRecord = 85U;
    expected_Dem_GaaDid[0].usDid = 0U;
    expected_map_LpDTCAttribute_3[0].ucNumOfDataId = 1U;
    expected_map_LpDTCAttribute_3[0].aaDataIdArray[0] = 0U;
    expected_map_LpDTCAttribute_3[0].ucMaxNumOfFFRecord = 85U;

    START_TEST("120: Dem_CheckforValidRecord",
               "created to solve false case of LucDidCount < LpDTCAttribute->ucNumOfDataId at line number 5498");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportRuntimeError#1");

            /* Call SUT */
            returnValue = Dem_CheckforValidRecord(RecordNumber, LucServiceId, DataId, LpDTCAttribute);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_121(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint8 LucServiceId = 85U;
    uint16 DataId = 0U;
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_3[0];
    Std_ReturnType returnValue;
    Dem_GaaDid[0].usDid = 1U;
    map_LpDTCAttribute_3[0].ucNumOfDataId = 1U;
    map_LpDTCAttribute_3[0].aaDataIdArray[0] = 0U;
    map_LpDTCAttribute_3[0].ucMaxNumOfFFRecord = 85U;
    expected_Dem_GaaDid[0].usDid = 1U;
    expected_map_LpDTCAttribute_3[0].ucNumOfDataId = 1U;
    expected_map_LpDTCAttribute_3[0].aaDataIdArray[0] = 0U;
    expected_map_LpDTCAttribute_3[0].ucMaxNumOfFFRecord = 85U;

    START_TEST("121: Dem_CheckforValidRecord",
               "created to solve false case of LucDidCount < LpDTCAttribute->ucNumOfDataId at line number 5498");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_CheckforValidRecord(RecordNumber, LucServiceId, DataId, LpDTCAttribute);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_122(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 1U;
    uint8 LucServiceId = 85U;
    uint16 DataId = 0U;
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_3[0];
    Std_ReturnType returnValue;
    map_LpDTCAttribute_3[0].ucMaxNumOfFFRecord = 0U;
    expected_map_LpDTCAttribute_3[0].ucMaxNumOfFFRecord = 0U;

    START_TEST("122: Dem_CheckforValidRecord",
               "created to solve true case of RecordNumber > LucNumOfRecs at line number 5489");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_CheckforValidRecord(RecordNumber, LucServiceId, DataId, LpDTCAttribute);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_123(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_6[0];
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = &map_BufSize_1[0];
    uint8 LucEventMemoryIndex = 85U;
    uint8 RecordNumber = 85U;
    uint8 LucClientId = 0U;
    boolean * LblRecordFound = NULL;
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 85U;
    map_LpEventMemory_6[85].ddEventId = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 85U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 85U;
    expected_map_LpEventMemory_6[85].ddEventId = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_BufSize_1[0] = 0U;

    START_TEST("123: Dem_GetFreezeFrameDataFromEvtMemory",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2");

            /* Call SUT */
            returnValue = Dem_GetFreezeFrameDataFromEvtMemory(LpEventMemory, DestBuffer, BufSize, LucEventMemoryIndex, RecordNumber, LucClientId, LblRecordFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_124(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_6[0];
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = &map_BufSize_1[0];
    uint8 LucEventMemoryIndex = 85U;
    uint8 RecordNumber = 85U;
    uint8 LucClientId = 0U;
    boolean * LblRecordFound = &map_LblRecordFound_1[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 0U;
    map_LpEventMemory_6[85].ddEventId = 1U;
    map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    map_LblRecordFound_1[0] = 85U;
    map_BufSize_1[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 0U;
    expected_map_LpEventMemory_6[85].ddEventId = 1U;
    expected_map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LblRecordFound_1[0] = 1U;
    expected_map_BufSize_1[0] = 0U;

    START_TEST("124: Dem_GetFreezeFrameDataFromEvtMemory",
               "created to solve true case of LucRecordCnt < LucNumOfFFRecNum at line number 5825");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2;Det_ReportError#1");

            /* Call SUT */
            returnValue = Dem_GetFreezeFrameDataFromEvtMemory(LpEventMemory, DestBuffer, BufSize, LucEventMemoryIndex, RecordNumber, LucClientId, LblRecordFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 21U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_125(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_6[0];
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = &map_BufSize_1[0];
    uint8 LucEventMemoryIndex = 85U;
    uint8 RecordNumber = 85U;
    uint8 LucClientId = 0U;
    boolean * LblRecordFound = &map_LblRecordFound_1[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 1U;
    map_LpEventMemory_6[85].ddEventId = 1U;
    map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 2U;
    map_LblRecordFound_1[0] = 85U;
    map_BufSize_1[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 1U;
    expected_map_LpEventMemory_6[85].ddEventId = 1U;
    expected_map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 2U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LblRecordFound_1[0] = 1U;
    expected_map_BufSize_1[0] = 0U;

    START_TEST("125: Dem_GetFreezeFrameDataFromEvtMemory",
               "created to solve true case of LucRecordIndex < LucNumOfFFRecNum at line number 5898");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2;Det_ReportError#1");

            /* Call SUT */
            returnValue = Dem_GetFreezeFrameDataFromEvtMemory(LpEventMemory, DestBuffer, BufSize, LucEventMemoryIndex, RecordNumber, LucClientId, LblRecordFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 21U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_126(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_6[0];
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = &map_BufSize_1[0];
    uint8 LucEventMemoryIndex = 85U;
    uint8 RecordNumber = 85U;
    uint8 LucClientId = 0U;
    boolean * LblRecordFound = &map_LblRecordFound_1[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 0U;
    map_LpEventMemory_6[85].ddEventId = 1U;
    map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 2U;
    map_LblRecordFound_1[0] = 85U;
    map_BufSize_1[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 0U;
    expected_map_LpEventMemory_6[85].ddEventId = 1U;
    expected_map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 2U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LblRecordFound_1[0] = 1U;
    expected_map_BufSize_1[0] = 0U;

    START_TEST("126: Dem_GetFreezeFrameDataFromEvtMemory",
               "created to solve true case of LucRecordCnt < LucNumOfFFRecNum at line number 5825");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2;Det_ReportError#1");

            /* Call SUT */
            returnValue = Dem_GetFreezeFrameDataFromEvtMemory(LpEventMemory, DestBuffer, BufSize, LucEventMemoryIndex, RecordNumber, LucClientId, LblRecordFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 21U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_127(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_6[0];
    uint8 * DestBuffer = &map_DestBuffer_2[0];
    uint16 * BufSize = &map_BufSize_1[0];
    uint8 LucEventMemoryIndex = 85U;
    uint8 RecordNumber = 85U;
    uint8 LucClientId = 0U;
    boolean * LblRecordFound = &map_LblRecordFound_1[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 0U;
    map_LpEventMemory_6[85].ddEventId = 1U;
    map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    map_LblRecordFound_1[0] = 85U;
    map_BufSize_1[0] = 2U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 0U;
    expected_map_LpEventMemory_6[85].ddEventId = 1U;
    expected_map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LblRecordFound_1[0] = 1U;
    expected_map_BufSize_1[0] = 2U;
    expected_map_DestBuffer_2[0] = 85U;
    expected_map_DestBuffer_2[1] = 0U;

    START_TEST("127: Dem_GetFreezeFrameDataFromEvtMemory",
               "created to solve false case of *BufSize < LusBufSize at line number 5932");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2");

            /* Call SUT */
            returnValue = Dem_GetFreezeFrameDataFromEvtMemory(LpEventMemory, DestBuffer, BufSize, LucEventMemoryIndex, RecordNumber, LucClientId, LblRecordFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_128(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_6[0];
    uint8 * DestBuffer = &map_DestBuffer_2[0];
    uint16 * BufSize = &map_BufSize_1[0];
    uint8 LucEventMemoryIndex = 85U;
    uint8 RecordNumber = 85U;
    uint8 LucClientId = 0U;
    boolean * LblRecordFound = &map_LblRecordFound_1[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDid[0].usDid = 0U;
    Dem_GaaDid[0].ucNumOfDataElements = 1U;
    Dem_GaaDid[0].aaDataElementType[0] = 85U;
    Dem_GaaDid[0].aaDataElementIndex[0] = 85U;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 0U;
    map_LpEventMemory_6[85].ddEventId = 1U;
    map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 85U;
    map_LpEventMemory_6[85].aaFFRecNumAndData[0][1] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaDataIdArray[0] = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    map_LblRecordFound_1[0] = 85U;
    map_BufSize_1[0] = 4U;
    expected_Dem_GaaDid[0].usDid = 0U;
    expected_Dem_GaaDid[0].ucNumOfDataElements = 1U;
    expected_Dem_GaaDid[0].aaDataElementType[0] = 85U;
    expected_Dem_GaaDid[0].aaDataElementIndex[0] = 85U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 0U;
    expected_map_LpEventMemory_6[85].ddEventId = 1U;
    expected_map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_LpEventMemory_6[85].aaFFRecNumAndData[0][1] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaDataIdArray[0] = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LblRecordFound_1[0] = 1U;
    expected_map_BufSize_1[0] = 4U;
    expected_map_DestBuffer_2[0] = 85U;
    expected_map_DestBuffer_2[1] = 1U;
    expected_map_DestBuffer_2[2] = 0U;
    expected_map_DestBuffer_2[3] = 0U;
    expected_map_DestBuffer_2[4] = 85U;

    START_TEST("128: Dem_GetFreezeFrameDataFromEvtMemory",
               "created to solve false case of LusCount1 < LusDidSize at line number 6061");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2;Dem_ProcessDataElementSize#1");

            /* Call SUT */
            returnValue = Dem_GetFreezeFrameDataFromEvtMemory(LpEventMemory, DestBuffer, BufSize, LucEventMemoryIndex, RecordNumber, LucClientId, LblRecordFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 85U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_129(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_6[0];
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = &map_BufSize_1[0];
    uint8 LucEventMemoryIndex = 85U;
    uint8 RecordNumber = 0U;
    uint8 LucClientId = 0U;
    boolean * LblRecordFound = &map_LblRecordFound_1[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 0U;
    map_LpEventMemory_6[85].ddEventId = 1U;
    map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    map_LblRecordFound_1[0] = 85U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 0U;
    expected_map_LpEventMemory_6[85].ddEventId = 1U;
    expected_map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LblRecordFound_1[0] = 0U;
    expected_map_BufSize_1[0] = 0U;

    START_TEST("129: Dem_GetFreezeFrameDataFromEvtMemory",
               "created to solve false case of (LpEventMemory + LucEventMemoryIndex)->                aaFFRecNumAndData[LucRecordIndex][DEM_ZERO] == LucRecordNumber between lines 5910 and 5911");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2");

            /* Call SUT */
            returnValue = Dem_GetFreezeFrameDataFromEvtMemory(LpEventMemory, DestBuffer, BufSize, LucEventMemoryIndex, RecordNumber, LucClientId, LblRecordFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_130(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_6[0];
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = &map_BufSize_1[0];
    uint8 LucEventMemoryIndex = 85U;
    uint8 RecordNumber = 255U;
    uint8 LucClientId = 0U;
    boolean * LblRecordFound = &map_LblRecordFound_1[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 0U;
    map_LpEventMemory_6[85].ddEventId = 1U;
    map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    map_LblRecordFound_1[0] = 85U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_map_LpEventMemory_6[85].ddEventId = 1U;
    expected_map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 1U;
    expected_map_LblRecordFound_1[0] = 0U;
    expected_map_BufSize_1[0] = 0U;

    START_TEST("130: Dem_GetFreezeFrameDataFromEvtMemory",
               "created to solve true case of DEM_MAX_RECORD == RecordNumber at line number 5831");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2");

            /* Call SUT */
            returnValue = Dem_GetFreezeFrameDataFromEvtMemory(LpEventMemory, DestBuffer, BufSize, LucEventMemoryIndex, RecordNumber, LucClientId, LblRecordFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_131(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_6[0];
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = &map_BufSize_1[0];
    uint8 LucEventMemoryIndex = 85U;
    uint8 RecordNumber = 255U;
    uint8 LucClientId = 0U;
    boolean * LblRecordFound = &map_LblRecordFound_1[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 0U;
    map_LpEventMemory_6[85].ddEventId = 1U;
    map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    map_LblRecordFound_1[0] = 1U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_map_LpEventMemory_6[85].ddEventId = 1U;
    expected_map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 1U;
    expected_map_LblRecordFound_1[0] = 0U;
    expected_map_BufSize_1[0] = 0U;

    START_TEST("131: Dem_GetFreezeFrameDataFromEvtMemory",
               "created to solve true case of DEM_MAX_RECORD == RecordNumber at line number 5826");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2");

            /* Call SUT */
            returnValue = Dem_GetFreezeFrameDataFromEvtMemory(LpEventMemory, DestBuffer, BufSize, LucEventMemoryIndex, RecordNumber, LucClientId, LblRecordFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_132(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_6[0];
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = &map_BufSize_1[0];
    uint8 LucEventMemoryIndex = 85U;
    uint8 RecordNumber = 85U;
    uint8 LucClientId = 0U;
    boolean * LblRecordFound = NULL;
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 1U;
    Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 85U;
    map_LpEventMemory_6[85].ddEventId = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfFFRecNum = 85U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 1U;
    expected_Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 85U;
    expected_map_LpEventMemory_6[85].ddEventId = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfFFRecNum = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_BufSize_1[0] = 0U;

    START_TEST("132: Dem_GetFreezeFrameDataFromEvtMemory",
               "created to solve true case of Dem_GaaDTCOriginBasedPtrAddress[LucMemIndx].ucFfRecordEnumType ==        DEM_FF_RECNUM_CONFIGURED between lines 5814 and 5815");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2");

            /* Call SUT */
            returnValue = Dem_GetFreezeFrameDataFromEvtMemory(LpEventMemory, DestBuffer, BufSize, LucEventMemoryIndex, RecordNumber, LucClientId, LblRecordFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_133(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_6[0];
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = &map_BufSize_1[0];
    uint8 LucEventMemoryIndex = 85U;
    uint8 RecordNumber = 255U;
    uint8 LucClientId = 0U;
    boolean * LblRecordFound = &map_LblRecordFound_1[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaFreezeFrameRecord[0].ucFreezeFrameRecordNumber = 85U;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 1U;
    Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 0U;
    map_LpEventMemory_6[85].ddEventId = 1U;
    map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfFFRecNum = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaFreezeFrameRecords[0] = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    map_LblRecordFound_1[0] = 85U;
    map_BufSize_1[0] = 0U;
    expected_Dem_GaaFreezeFrameRecord[0].ucFreezeFrameRecordNumber = 85U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 1U;
    expected_map_LpEventMemory_6[85].ddEventId = 1U;
    expected_map_LpEventMemory_6[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfFFRecNum = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaFreezeFrameRecords[0] = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaClientSelection[0].ucFFNumRecordProcessed = 1U;
    expected_map_LblRecordFound_1[0] = 1U;
    expected_map_BufSize_1[0] = 0U;

    START_TEST("133: Dem_GetFreezeFrameDataFromEvtMemory",
               "created to solve true case of DEM_MAX_RECORD == RecordNumber at line number 5831");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2;Det_ReportError#1");

            /* Call SUT */
            returnValue = Dem_GetFreezeFrameDataFromEvtMemory(LpEventMemory, DestBuffer, BufSize, LucEventMemoryIndex, RecordNumber, LucClientId, LblRecordFound);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 21U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_134(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint16 * LpSizeOfFreezeFrame = NULL;
    uint8 LucEventMemoryIndex = 85U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_7[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = NULL;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddDtcFormat[1] = 85U;
    map_LpEventMemory_7[85].ddEventId = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = NULL;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[1] = 85U;
    expected_map_LpEventMemory_7[85].ddEventId = 1U;

    START_TEST("134: Dem_GetSizeOfRecord",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#3");

            /* Call SUT */
            returnValue = Dem_GetSizeOfRecord(RecordNumber, LpSizeOfFreezeFrame, LucEventMemoryIndex, LpEventMemory);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_135(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint16 * LpSizeOfFreezeFrame = &map_LpSizeOfFreezeFrame[0];
    uint8 LucEventMemoryIndex = 85U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_7[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    map_LpEventMemory_7[85].ddEventId = 1U;
    map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 85U;
    map_LpSizeOfFreezeFrame[0] = 0U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    expected_map_LpEventMemory_7[85].ddEventId = 1U;
    expected_map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpSizeOfFreezeFrame[0] = 172U;

    START_TEST("135: Dem_GetSizeOfRecord",
               "created to solve true case of DEM_TRUE  == LblDtcFormat at line number 6278");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2");

            /* Call SUT */
            returnValue = Dem_GetSizeOfRecord(RecordNumber, LpSizeOfFreezeFrame, LucEventMemoryIndex, LpEventMemory);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_136(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint16 * LpSizeOfFreezeFrame = &map_LpSizeOfFreezeFrame[0];
    uint8 LucEventMemoryIndex = 85U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_7[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    map_LpEventMemory_7[85].ddEventId = 1U;
    map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    map_LpSizeOfFreezeFrame[0] = 0U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    expected_map_LpEventMemory_7[85].ddEventId = 1U;
    expected_map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpSizeOfFreezeFrame[0] = 172U;

    START_TEST("136: Dem_GetSizeOfRecord",
               "created to solve false case of LucCount < LucCmpRecord at line number 6300");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2");

            /* Call SUT */
            returnValue = Dem_GetSizeOfRecord(RecordNumber, LpSizeOfFreezeFrame, LucEventMemoryIndex, LpEventMemory);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_137(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 0U;
    uint16 * LpSizeOfFreezeFrame = NULL;
    uint8 LucEventMemoryIndex = 85U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_7[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    map_LpEventMemory_7[85].ddEventId = 1U;
    map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    expected_map_LpEventMemory_7[85].ddEventId = 1U;
    expected_map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];

    START_TEST("137: Dem_GetSizeOfRecord",
               "created to solve false case of LucCount < LucCmpRecord at line number 6300");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2");

            /* Call SUT */
            returnValue = Dem_GetSizeOfRecord(RecordNumber, LpSizeOfFreezeFrame, LucEventMemoryIndex, LpEventMemory);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_138(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 1U;
    uint16 * LpSizeOfFreezeFrame = NULL;
    uint8 LucEventMemoryIndex = 85U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_7[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    map_LpEventMemory_7[85].ddEventId = 1U;
    map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    expected_map_LpEventMemory_7[85].ddEventId = 1U;
    expected_map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];

    START_TEST("138: Dem_GetSizeOfRecord",
               "created to solve true case of LucRecordNum == RecordNumber at line number 6373");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2");

            /* Call SUT */
            returnValue = Dem_GetSizeOfRecord(RecordNumber, LpSizeOfFreezeFrame, LucEventMemoryIndex, LpEventMemory);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_139(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint16 * LpSizeOfFreezeFrame = &map_LpSizeOfFreezeFrame[0];
    uint8 LucEventMemoryIndex = 85U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_7[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 1U;
    Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    map_LpEventMemory_7[85].ddEventId = 1U;
    map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfFFRecNum = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    map_LpSizeOfFreezeFrame[0] = 0U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 1U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    expected_map_LpEventMemory_7[85].ddEventId = 1U;
    expected_map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfFFRecNum = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpSizeOfFreezeFrame[0] = 172U;

    START_TEST("139: Dem_GetSizeOfRecord",
               "created to solve true case of Dem_GaaDTCOriginBasedPtrAddress[LucMemIndx].ucFfRecordEnumType ==            DEM_FF_RECNUM_CONFIGURED between lines 6287 and 6288");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2");

            /* Call SUT */
            returnValue = Dem_GetSizeOfRecord(RecordNumber, LpSizeOfFreezeFrame, LucEventMemoryIndex, LpEventMemory);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_140(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 0U;
    uint16 * LpSizeOfFreezeFrame = NULL;
    uint8 LucEventMemoryIndex = 85U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_7[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaFreezeFrameRecord[0].ucFreezeFrameRecordNumber = 85U;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 1U;
    Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    map_LpEventMemory_7[85].ddEventId = 1U;
    map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfFFRecNum = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaFreezeFrameRecords[0] = 0U;
    expected_Dem_GaaFreezeFrameRecord[0].ucFreezeFrameRecordNumber = 85U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 1U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    expected_map_LpEventMemory_7[85].ddEventId = 1U;
    expected_map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfFFRecNum = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaFreezeFrameRecords[0] = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];

    START_TEST("140: Dem_GetSizeOfRecord",
               "created to solve false case of LucCount < LucCmpRecord at line number 6300");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2");

            /* Call SUT */
            returnValue = Dem_GetSizeOfRecord(RecordNumber, LpSizeOfFreezeFrame, LucEventMemoryIndex, LpEventMemory);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_141(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 255U;
    uint16 * LpSizeOfFreezeFrame = &map_LpSizeOfFreezeFrame[0];
    uint8 LucEventMemoryIndex = 85U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_7[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    map_LpEventMemory_7[85].ddEventId = 1U;
    map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    map_LpSizeOfFreezeFrame[0] = 0U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    expected_map_LpEventMemory_7[85].ddEventId = 1U;
    expected_map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpSizeOfFreezeFrame[0] = 172U;

    START_TEST("141: Dem_GetSizeOfRecord",
               "created to solve false case of LucCount < LucCmpRecord at line number 6407");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2");

            /* Call SUT */
            returnValue = Dem_GetSizeOfRecord(RecordNumber, LpSizeOfFreezeFrame, LucEventMemoryIndex, LpEventMemory);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_142(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 255U;
    uint16 * LpSizeOfFreezeFrame = NULL;
    uint8 LucEventMemoryIndex = 85U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_7[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    map_LpEventMemory_7[85].ddEventId = 1U;
    map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    expected_map_LpEventMemory_7[85].ddEventId = 1U;
    expected_map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];

    START_TEST("142: Dem_GetSizeOfRecord",
               "created to solve false case of LucCount < LucCmpRecord at line number 6407");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#2");

            /* Call SUT */
            returnValue = Dem_GetSizeOfRecord(RecordNumber, LpSizeOfFreezeFrame, LucEventMemoryIndex, LpEventMemory);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_143(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 1U;
    uint16 * LpSizeOfFreezeFrame = NULL;
    uint8 LucEventMemoryIndex = 85U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_7[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    map_LpEventMemory_7[85].ddEventId = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    map_Dem_DtcAttrSearchInMemory_call1_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 85U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddDtcFormat[1] = 1U;
    expected_map_LpEventMemory_7[85].ddEventId = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 1U;
    expected_map_Dem_DtcAttrSearchInMemory_call1_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_DtcAttrSearchInMemory_call1_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[1] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[2] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[3] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[4] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[5] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[6] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[7] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[8] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[9] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 0U;
    expected_map_LpEventMemory_7[85].aaFFRecNumAndData[0][1] = 85U;
    expected_map_LpEventMemory_7[85].aaFFRecNumAndData[0][2] = 85U;

    START_TEST("143: Dem_GetSizeOfRecord",
               "created to solve true case of LucRecordNum == RecordNumber at line number 6373");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#4");

            /* Call SUT */
            returnValue = Dem_GetSizeOfRecord(RecordNumber, LpSizeOfFreezeFrame, LucEventMemoryIndex, LpEventMemory);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_144(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 * LpRecNumberStored = NULL;
    uint16 LusEventParameterIndex = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_8[0];
    uint8 LucStoredIndex = 85U;
    uint8 ExtendedDataNumber = 85U;
    uint16* LpBufSize = &map_LpBufSize[0];
    uint8* LpDestBuffer = NULL;
    Dem_DTCOriginType DTCOrigin = 0U;
    uint16 * LpDestBuffIndx = &map_LpDestBuffIndx[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    map_LpEventMemory_8[85].aaEdData[0][0] = 85U;
    map_LpBufSize[0] = 0U;
    expected_Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LpEventMemory_8[85].aaEdData[0][0] = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpBufSize[0] = 1U;

    START_TEST("144: Dem_GetExtendedDataRecordByDTCExistInMem",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportError#2");

            /* Call SUT */
            returnValue = Dem_GetExtendedDataRecordByDTCExistInMem(LpRecNumberStored, LusEventParameterIndex, LpEventMemory, LucStoredIndex, ExtendedDataNumber, LpBufSize, LpDestBuffer, DTCOrigin, LpDestBuffIndx);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 21U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_145(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 * LpRecNumberStored = NULL;
    uint16 LusEventParameterIndex = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_8[0];
    uint8 LucStoredIndex = 85U;
    uint8 ExtendedDataNumber = 85U;
    uint16* LpBufSize = &map_LpBufSize[0];
    uint8* LpDestBuffer = NULL;
    Dem_DTCOriginType DTCOrigin = 0U;
    uint16 * LpDestBuffIndx = &map_LpDestBuffIndx[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    map_LpEventMemory_8[85].aaEdData[0][0] = 85U;
    map_LpBufSize[0] = 0U;
    expected_Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LpEventMemory_8[85].aaEdData[0][0] = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpBufSize[0] = 1U;

    START_TEST("145: Dem_GetExtendedDataRecordByDTCExistInMem",
               "created to solve false case of LucCount <    LucNumOfEDRecords between lines 7421 and 7422");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportError#2");

            /* Call SUT */
            returnValue = Dem_GetExtendedDataRecordByDTCExistInMem(LpRecNumberStored, LusEventParameterIndex, LpEventMemory, LucStoredIndex, ExtendedDataNumber, LpBufSize, LpDestBuffer, DTCOrigin, LpDestBuffIndx);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 21U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_146(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 * LpRecNumberStored = &map_LpRecNumberStored[0];
    uint16 LusEventParameterIndex = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_8[0];
    uint8 LucStoredIndex = 85U;
    uint8 ExtendedDataNumber = 85U;
    uint16* LpBufSize = &map_LpBufSize[0];
    uint8* LpDestBuffer = NULL;
    Dem_DTCOriginType DTCOrigin = 0U;
    uint16 * LpDestBuffIndx = &map_LpDestBuffIndx[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucNumOfDataElements = 1U;
    Dem_GaaEDRecord[0].aaDataElementType[0] = 85U;
    Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    map_LpDestBuffIndx[0] = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    map_LpEventMemory_8[85].aaEdData[0][0] = 85U;
    map_LpBufSize[0] = 1U;
    map_LpRecNumberStored[0] = 85U;
    expected_Dem_GaaEDRecord[0].ucNumOfDataElements = 1U;
    expected_Dem_GaaEDRecord[0].aaDataElementType[0] = 85U;
    expected_Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LpEventMemory_8[85].aaEdData[0][0] = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpDestBuffIndx[0] = 0U;
    expected_map_LpBufSize[0] = 1U;
    expected_map_LpRecNumberStored[0] = 86U;

    START_TEST("146: Dem_GetExtendedDataRecordByDTCExistInMem",
               "created to solve false case of LucDataElementIndex <        Dem_GaaEDRecord[LucActualRecordIndex].        ucNumOfDataElements between lines 7479 and 7481");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetExtendedDataRecordByDTCExistInMem(LpRecNumberStored, LusEventParameterIndex, LpEventMemory, LucStoredIndex, ExtendedDataNumber, LpBufSize, LpDestBuffer, DTCOrigin, LpDestBuffIndx);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_147(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 * LpRecNumberStored = &map_LpRecNumberStored[0];
    uint16 LusEventParameterIndex = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_8[0];
    uint8 LucStoredIndex = 85U;
    uint8 ExtendedDataNumber = 85U;
    uint16* LpBufSize = &map_LpBufSize[0];
    uint8* LpDestBuffer = &map_LpDestBuffer_1[0];
    Dem_DTCOriginType DTCOrigin = 0U;
    uint16 * LpDestBuffIndx = &map_LpDestBuffIndx[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucNumOfDataElements = 1U;
    Dem_GaaEDRecord[0].aaDataElementType[0] = 1U;
    Dem_GaaEDRecord[0].aaDataElementIndex[0] = 0U;
    Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    Dem_GaaDataElementExternalCS[0].ucDemDataElementDataSize = 1U;
    map_LpDestBuffIndx[0] = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    map_LpEventMemory_8[85].aaEdData[0][0] = 85U;
    map_LpEventMemory_8[85].aaEdData[0][1] = 85U;
    map_LpBufSize[0] = 1U;
    map_LpRecNumberStored[0] = 85U;
    expected_Dem_GaaEDRecord[0].ucNumOfDataElements = 1U;
    expected_Dem_GaaEDRecord[0].aaDataElementType[0] = 1U;
    expected_Dem_GaaEDRecord[0].aaDataElementIndex[0] = 0U;
    expected_Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    expected_Dem_GaaDataElementExternalCS[0].ucDemDataElementDataSize = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LpEventMemory_8[85].aaEdData[0][0] = 85U;
    expected_map_LpEventMemory_8[85].aaEdData[0][1] = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpDestBuffIndx[0] = 1U;
    expected_map_LpBufSize[0] = 1U;
    expected_map_LpRecNumberStored[0] = 86U;
    expected_map_LpDestBuffer_1[0] = 85U;

    START_TEST("147: Dem_GetExtendedDataRecordByDTCExistInMem",
               "created to solve false case of LucDataElementIndex <        Dem_GaaEDRecord[LucActualRecordIndex].        ucNumOfDataElements between lines 7479 and 7481");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetExtendedDataRecordByDTCExistInMem(LpRecNumberStored, LusEventParameterIndex, LpEventMemory, LucStoredIndex, ExtendedDataNumber, LpBufSize, LpDestBuffer, DTCOrigin, LpDestBuffIndx);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_148(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 * LpRecNumberStored = &map_LpRecNumberStored[0];
    uint16 LusEventParameterIndex = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_8[0];
    uint8 LucStoredIndex = 85U;
    uint8 ExtendedDataNumber = 85U;
    uint16* LpBufSize = &map_LpBufSize[0];
    uint8* LpDestBuffer = &map_LpDestBuffer_1[0];
    Dem_DTCOriginType DTCOrigin = 0U;
    uint16 * LpDestBuffIndx = &map_LpDestBuffIndx[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    Dem_GaaEDRecord[0].ucNumOfDataElements = 1U;
    Dem_GaaEDRecord[0].aaDataElementType[0] = 85U;
    Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    map_LpDestBuffIndx[0] = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    map_LpEventMemory_8[85].aaEdData[0][0] = 85U;
    map_LpBufSize[0] = 1U;
    map_LpRecNumberStored[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_Dem_GaaEDRecord[0].ucNumOfDataElements = 1U;
    expected_Dem_GaaEDRecord[0].aaDataElementType[0] = 85U;
    expected_Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LpEventMemory_8[85].aaEdData[0][0] = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpDestBuffIndx[0] = 1U;
    expected_map_LpBufSize[0] = 1U;
    expected_map_LpRecNumberStored[0] = 1U;
    expected_map_LpDestBuffer_1[0] = 85U;

    START_TEST("148: Dem_GetExtendedDataRecordByDTCExistInMem",
               "created to solve false case of LucDataElementIndex <        Dem_GaaEDRecord[LucActualRecordIndex].        ucNumOfDataElements between lines 7479 and 7481");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetExtendedDataRecordByDTCExistInMem(LpRecNumberStored, LusEventParameterIndex, LpEventMemory, LucStoredIndex, ExtendedDataNumber, LpBufSize, LpDestBuffer, DTCOrigin, LpDestBuffIndx);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_149(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 * LpRecNumberStored = NULL;
    uint16 LusEventParameterIndex = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_8[0];
    uint8 LucStoredIndex = 85U;
    uint8 ExtendedDataNumber = 0U;
    uint16* LpBufSize = NULL;
    uint8* LpDestBuffer = NULL;
    Dem_DTCOriginType DTCOrigin = 0U;
    uint16 * LpDestBuffIndx = &map_LpDestBuffIndx[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    map_LpEventMemory_8[85].aaEdData[0][0] = 1U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LpEventMemory_8[85].aaEdData[0][0] = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];

    START_TEST("149: Dem_GetExtendedDataRecordByDTCExistInMem",
               "created to solve false case of LucCount <    LucNumOfEDRecords between lines 7421 and 7422");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetExtendedDataRecordByDTCExistInMem(LpRecNumberStored, LusEventParameterIndex, LpEventMemory, LucStoredIndex, ExtendedDataNumber, LpBufSize, LpDestBuffer, DTCOrigin, LpDestBuffIndx);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_150(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 * LpRecNumberStored = NULL;
    uint16 LusEventParameterIndex = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_8[0];
    uint8 LucStoredIndex = 85U;
    uint8 ExtendedDataNumber = 0U;
    uint16* LpBufSize = &map_LpBufSize[0];
    uint8* LpDestBuffer = NULL;
    Dem_DTCOriginType DTCOrigin = 0U;
    uint16 * LpDestBuffIndx = &map_LpDestBuffIndx[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    map_LpEventMemory_8[85].aaEdData[0][0] = 1U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LpEventMemory_8[85].aaEdData[0][0] = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpBufSize[0] = 0U;

    START_TEST("150: Dem_GetExtendedDataRecordByDTCExistInMem",
               "created to solve true case of (Dem_GaaEDRecord[LucActualRecordIndex].              ucExtendedDataRecordNumber) == ExtendedDataNumber between lines 7625 and 7626");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetExtendedDataRecordByDTCExistInMem(LpRecNumberStored, LusEventParameterIndex, LpEventMemory, LucStoredIndex, ExtendedDataNumber, LpBufSize, LpDestBuffer, DTCOrigin, LpDestBuffIndx);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_151(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDTCAttributeIndex = 0U;
    uint8 ExtendedDataNumber = 85U;
    uint16* LpBufSize = &map_LpBufSize_1[0];
    Std_ReturnType returnValue;
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    Dem_GaaDTCAttributes[0].ucNumOfEDRecords = 85U;
    Dem_GaaDTCAttributes[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_Dem_GaaDTCAttributes[0].ucNumOfEDRecords = 85U;
    expected_Dem_GaaDTCAttributes[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LpBufSize_1[0] = 0U;

    START_TEST("151: Dem_GetExtendedDataRecordByDTCVAlidButNotInMem",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetExtendedDataRecordByDTCVAlidButNotInMem(LusDTCAttributeIndex, ExtendedDataNumber, LpBufSize);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_152(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDTCAttributeIndex = 0U;
    uint8 ExtendedDataNumber = 85U;
    uint16* LpBufSize = &map_LpBufSize_1[0];
    Std_ReturnType returnValue;
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    Dem_GaaDTCAttributes[0].ucNumOfEDRecords = 1U;
    Dem_GaaDTCAttributes[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_Dem_GaaDTCAttributes[0].ucNumOfEDRecords = 1U;
    expected_Dem_GaaDTCAttributes[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LpBufSize_1[0] = 0U;

    START_TEST("152: Dem_GetExtendedDataRecordByDTCVAlidButNotInMem",
               "created to solve false case of LucCount <  LucNumOfEDRecords between lines 7715 and 7716");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetExtendedDataRecordByDTCVAlidButNotInMem(LusDTCAttributeIndex, ExtendedDataNumber, LpBufSize);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_153(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDTCAttributeIndex = 0U;
    uint8 ExtendedDataNumber = 0U;
    uint16* LpBufSize = NULL;
    Std_ReturnType returnValue;
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 1U;
    Dem_GaaDTCAttributes[0].ucNumOfEDRecords = 1U;
    Dem_GaaDTCAttributes[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 1U;
    expected_Dem_GaaDTCAttributes[0].ucNumOfEDRecords = 1U;
    expected_Dem_GaaDTCAttributes[0].aaExtendedDataRecords[0] = 0U;

    START_TEST("153: Dem_GetExtendedDataRecordByDTCVAlidButNotInMem",
               "created to solve false case of LucCount <  LucNumOfEDRecords between lines 7715 and 7716");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetExtendedDataRecordByDTCVAlidButNotInMem(LusDTCAttributeIndex, ExtendedDataNumber, LpBufSize);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_154(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDTCAttributeIndex = 0U;
    uint8 ExtendedDataNumber = 255U;
    uint16* LpBufSize = &map_LpBufSize_1[0];
    Std_ReturnType returnValue;
    Dem_GaaDTCAttributes[0].ucNumOfEDRecords = 85U;
    expected_Dem_GaaDTCAttributes[0].ucNumOfEDRecords = 85U;
    expected_map_LpBufSize_1[0] = 0U;

    START_TEST("154: Dem_GetExtendedDataRecordByDTCVAlidButNotInMem",
               "created to solve true case of DEM_MAX_EXTENDED_RECORD_NUMBER == ExtendedDataNumber at line number 7706");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetExtendedDataRecordByDTCVAlidButNotInMem(LusDTCAttributeIndex, ExtendedDataNumber, LpBufSize);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_155(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ExtendedDataNumber = 85U;
    uint16 * LpSizeOfExtendedDataRecord = &map_LpSizeOfExtendedDataRecord_1[0];
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_9[0];
    uint16 LusEventParameterIndex = 0U;
    uint8 LucEventMemoryIndex = 85U;
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    map_LpEventMemory_9[85].aaEdData[0][0] = 85U;
    map_LpSizeOfExtendedDataRecord_1[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LpEventMemory_9[85].aaEdData[0][0] = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpSizeOfExtendedDataRecord_1[0] = 1U;

    START_TEST("155: Dem_GetSizeOfExtendedDataRecordByDTCFoundInMem",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetSizeOfExtendedDataRecordByDTCFoundInMem(ExtendedDataNumber, LpSizeOfExtendedDataRecord, LpEventMemory, LusEventParameterIndex, LucEventMemoryIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_156(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ExtendedDataNumber = 85U;
    uint16 * LpSizeOfExtendedDataRecord = &map_LpSizeOfExtendedDataRecord_1[0];
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_9[0];
    uint16 LusEventParameterIndex = 0U;
    uint8 LucEventMemoryIndex = 85U;
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    map_LpEventMemory_9[85].aaEdData[0][0] = 85U;
    map_LpSizeOfExtendedDataRecord_1[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LpEventMemory_9[85].aaEdData[0][0] = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpSizeOfExtendedDataRecord_1[0] = 1U;

    START_TEST("156: Dem_GetSizeOfExtendedDataRecordByDTCFoundInMem",
               "created to solve false case of LucCount <         (Dem_GaaEventParameter[LusEventParameterIndex].pDTCAttribute)->         ucNumOfEDRecords between lines 7864 and 7866");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetSizeOfExtendedDataRecordByDTCFoundInMem(ExtendedDataNumber, LpSizeOfExtendedDataRecord, LpEventMemory, LusEventParameterIndex, LucEventMemoryIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_157(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ExtendedDataNumber = 0U;
    uint16 * LpSizeOfExtendedDataRecord = NULL;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_9[0];
    uint16 LusEventParameterIndex = 0U;
    uint8 LucEventMemoryIndex = 85U;
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    map_LpEventMemory_9[85].aaEdData[0][0] = 1U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_map_LpEventMemory_9[85].aaEdData[0][0] = 1U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];

    START_TEST("157: Dem_GetSizeOfExtendedDataRecordByDTCFoundInMem",
               "created to solve false case of (LpEventMemory + LucEventMemoryIndex)->aaEdData[LucCount]                  [DEM_ZERO] == ExtendedDataNumber between lines 7882 and 7883");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetSizeOfExtendedDataRecordByDTCFoundInMem(ExtendedDataNumber, LpSizeOfExtendedDataRecord, LpEventMemory, LusEventParameterIndex, LucEventMemoryIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_158(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ExtendedDataNumber = 0U;
    uint16 * LpSizeOfExtendedDataRecord = NULL;
    const Dem_EventMemory * LpEventMemory = NULL;
    uint16 LusEventParameterIndex = 0U;
    uint8 LucEventMemoryIndex = 85U;
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];

    START_TEST("158: Dem_GetSizeOfExtendedDataRecordByDTCFoundInMem",
               "created to solve false case of LucCount <         (Dem_GaaEventParameter[LusEventParameterIndex].pDTCAttribute)->         ucNumOfEDRecords between lines 7864 and 7866");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetSizeOfExtendedDataRecordByDTCFoundInMem(ExtendedDataNumber, LpSizeOfExtendedDataRecord, LpEventMemory, LusEventParameterIndex, LucEventMemoryIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_159(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ExtendedDataNumber = 254U;
    uint16 * LpSizeOfExtendedDataRecord = &map_LpSizeOfExtendedDataRecord_1[0];
    const Dem_EventMemory * LpEventMemory = NULL;
    uint16 LusEventParameterIndex = 0U;
    uint8 LucEventMemoryIndex = 85U;
    Std_ReturnType returnValue;
    map_LpSizeOfExtendedDataRecord_1[0] = 0U;
    expected_map_LpSizeOfExtendedDataRecord_1[0] = 0U;

    START_TEST("159: Dem_GetSizeOfExtendedDataRecordByDTCFoundInMem",
               "created to solve false case of ExtendedDataNumber != DEM_EXTENDED_DATA_NUMBER_OBD at line number 7857");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_GetSizeOfRecNoFFandFE#1");

            /* Call SUT */
            returnValue = Dem_GetSizeOfExtendedDataRecordByDTCFoundInMem(ExtendedDataNumber, LpSizeOfExtendedDataRecord, LpEventMemory, LusEventParameterIndex, LucEventMemoryIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_160(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ExtendedDataNumber = 255U;
    uint16 * LpSizeOfExtendedDataRecord = &map_LpSizeOfExtendedDataRecord_1[0];
    const Dem_EventMemory * LpEventMemory = NULL;
    uint16 LusEventParameterIndex = 0U;
    uint8 LucEventMemoryIndex = 85U;
    Std_ReturnType returnValue;
    map_LpSizeOfExtendedDataRecord_1[0] = 0U;
    expected_map_LpSizeOfExtendedDataRecord_1[0] = 0U;

    START_TEST("160: Dem_GetSizeOfExtendedDataRecordByDTCFoundInMem",
               "created to solve false case of ExtendedDataNumber != DEM_MAX_EXTENDED_RECORD_NUMBER at line number 7856");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_GetSizeOfRecNoFFandFE#2");

            /* Call SUT */
            returnValue = Dem_GetSizeOfExtendedDataRecordByDTCFoundInMem(ExtendedDataNumber, LpSizeOfExtendedDataRecord, LpEventMemory, LusEventParameterIndex, LucEventMemoryIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_161(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint8 ExtendedDataNumber = 85U;
    uint16 * LpSizeOfExtendedDataRecord = &map_LpSizeOfExtendedDataRecord_2[0];
    Std_ReturnType returnValue;
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    Dem_GaaDTCAttributes[0].ucNumOfEDRecords = 85U;
    Dem_GaaDTCAttributes[0].aaExtendedDataRecords[0] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_Dem_GaaDTCAttributes[0].ucNumOfEDRecords = 85U;
    expected_Dem_GaaDTCAttributes[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_map_LpSizeOfExtendedDataRecord_2[0] = 0U;

    START_TEST("161: Dem_GetSizeOfExtendedDataRecordByDTCNotFoundInMem",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetSizeOfExtendedDataRecordByDTCNotFoundInMem(LusDtcInfoIndex, ExtendedDataNumber, LpSizeOfExtendedDataRecord);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_162(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint8 ExtendedDataNumber = 85U;
    uint16 * LpSizeOfExtendedDataRecord = &map_LpSizeOfExtendedDataRecord_2[0];
    Std_ReturnType returnValue;
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    Dem_GaaDTCAttributes[0].ucNumOfEDRecords = 1U;
    Dem_GaaDTCAttributes[0].aaExtendedDataRecords[0] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_Dem_GaaDTCAttributes[0].ucNumOfEDRecords = 1U;
    expected_Dem_GaaDTCAttributes[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_map_LpSizeOfExtendedDataRecord_2[0] = 0U;

    START_TEST("162: Dem_GetSizeOfExtendedDataRecordByDTCNotFoundInMem",
               "created to solve false case of LucCount <   Dem_GaaDTCAttributes[LusDTCAttributeIndex].   ucNumOfEDRecords between lines 8033 and 8035");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetSizeOfExtendedDataRecordByDTCNotFoundInMem(LusDtcInfoIndex, ExtendedDataNumber, LpSizeOfExtendedDataRecord);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_163(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint8 ExtendedDataNumber = 0U;
    uint16 * LpSizeOfExtendedDataRecord = &map_LpSizeOfExtendedDataRecord_2[0];
    Std_ReturnType returnValue;
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 1U;
    Dem_GaaDTCAttributes[0].ucNumOfEDRecords = 1U;
    Dem_GaaDTCAttributes[0].aaExtendedDataRecords[0] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 1U;
    expected_Dem_GaaDTCAttributes[0].ucNumOfEDRecords = 1U;
    expected_Dem_GaaDTCAttributes[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_map_LpSizeOfExtendedDataRecord_2[0] = 0U;

    START_TEST("163: Dem_GetSizeOfExtendedDataRecordByDTCNotFoundInMem",
               "created to solve false case of LucCount <   Dem_GaaDTCAttributes[LusDTCAttributeIndex].   ucNumOfEDRecords between lines 8033 and 8035");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetSizeOfExtendedDataRecordByDTCNotFoundInMem(LusDtcInfoIndex, ExtendedDataNumber, LpSizeOfExtendedDataRecord);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_164(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusDtcInfoIndex = 0U;
    uint8 ExtendedDataNumber = 255U;
    uint16 * LpSizeOfExtendedDataRecord = &map_LpSizeOfExtendedDataRecord_2[0];
    Std_ReturnType returnValue;
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    Dem_GaaDTCAttributes[0].ucNumOfEDRecords = 1U;
    Dem_GaaDTCAttributes[0].aaExtendedDataRecords[0] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    expected_Dem_GaaDTCAttributes[0].ucNumOfEDRecords = 1U;
    expected_Dem_GaaDTCAttributes[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_map_LpSizeOfExtendedDataRecord_2[0] = 0U;

    START_TEST("164: Dem_GetSizeOfExtendedDataRecordByDTCNotFoundInMem",
               "created to solve false case of DEM_MAX_EXTENDED_RECORD_NUMBER  != ExtendedDataNumber at line number 8060");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetSizeOfExtendedDataRecordByDTCNotFoundInMem(LusDtcInfoIndex, ExtendedDataNumber, LpSizeOfExtendedDataRecord);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_165(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventIndex = 0U;
    Dem_GaaEventParameter[0].ucDebounceType = 85U;
    expected_Dem_GaaEventParameter[0].ucDebounceType = 85U;

    START_TEST("165: Dem_ResetFdc",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_ResetFdc(LusEventIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_166(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventIndex = 0U;
    Dem_GaaEventParameter[0].ucDebounceType = 3U;
    expected_Dem_GaaEventParameter[0].ucDebounceType = 3U;
    expected_Dem_GaaAllFDC[0] = 0;

    START_TEST("166: Dem_ResetFdc",
               "created to solve true case of DEM_DEBOUNCE_MONITOR_BASED ==     Dem_GaaEventParameter[LusEventIndex].ucDebounceType between lines 8185 and 8186");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_ResetFdc(LusEventIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_167(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ClientId = 0U;
    Dem_DTCFormatType DTCFormat = 85U;
    Dem_DTCOriginType DTCOrigin = 0U;
   // boolean FilterWithSeverity = 85U;
    Dem_DTCSeverityType DTCSeverityMask = 85U;
  //  boolean FilterForFaultDetectionCounter = 85U;
    Std_ReturnType returnValue;

    START_TEST("167: Dem_DTCFilterDetCheck",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportError#3;Det_ReportError#4");

            /* Call SUT */
            returnValue = Dem_DTCFilterDetCheck(ClientId, DTCFormat, DTCOrigin, DTCSeverityMask);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_168(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ClientId = 0U;
    Dem_DTCFormatType DTCFormat = 85U;
    Dem_DTCOriginType DTCOrigin = 0U;
   // boolean FilterWithSeverity = 85U;
    Dem_DTCSeverityType DTCSeverityMask = 85U;
    //boolean FilterForFaultDetectionCounter = 0U;
    Std_ReturnType returnValue;

    START_TEST("168: Dem_DTCFilterDetCheck",
               "created to solve false case of FilterForFaultDetectionCounter != (boolean)DEM_DTC_FILTER_FOR_FDC_NO at line number 8367");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportError#3;Det_ReportError#3");

            /* Call SUT */
            returnValue = Dem_DTCFilterDetCheck(ClientId, DTCFormat, DTCOrigin, DTCSeverityMask);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_169(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ClientId = 0U;
    Dem_DTCFormatType DTCFormat = 85U;
    Dem_DTCOriginType DTCOrigin = 0U;
   // boolean FilterWithSeverity = 85U;
    Dem_DTCSeverityType DTCSeverityMask = 85U;
    //boolean FilterForFaultDetectionCounter = 1U;
    Std_ReturnType returnValue;

    START_TEST("169: Dem_DTCFilterDetCheck",
               "created to solve false case of FilterForFaultDetectionCounter != (boolean)DEM_DTC_FILTER_FOR_FDC_YES at line number 8366");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportError#3;Det_ReportError#4");

            /* Call SUT */
            returnValue = Dem_DTCFilterDetCheck(ClientId, DTCFormat, DTCOrigin, DTCSeverityMask);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_170(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ClientId = 0U;
    Dem_DTCFormatType DTCFormat = 85U;
    Dem_DTCOriginType DTCOrigin = 0U;
 //   boolean FilterWithSeverity = 85U;
    Dem_DTCSeverityType DTCSeverityMask = 128U;
  //  boolean FilterForFaultDetectionCounter = 85U;
    Std_ReturnType returnValue;

    START_TEST("170: Dem_DTCFilterDetCheck",
               "created to solve false case of DTCSeverityMask != (uint8)DEM_DTC_SEV_IMMEDIATELY at line number 8354");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportError#3");

            /* Call SUT */
            returnValue = Dem_DTCFilterDetCheck(ClientId, DTCFormat, DTCOrigin, DTCSeverityMask);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_171(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ClientId = 0U;
    Dem_DTCFormatType DTCFormat = 85U;
    Dem_DTCOriginType DTCOrigin = 0U;
  //  boolean FilterWithSeverity = 85U;
    Dem_DTCSeverityType DTCSeverityMask = 64U;
  //  boolean FilterForFaultDetectionCounter = 85U;
    Std_ReturnType returnValue;

    START_TEST("171: Dem_DTCFilterDetCheck",
               "created to solve false case of DTCSeverityMask != (uint8)DEM_DTC_SEV_CHECK_AT_NEXT_HALT at line number 8353");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportError#3");

            /* Call SUT */
            returnValue = Dem_DTCFilterDetCheck(ClientId, DTCFormat, DTCOrigin, DTCSeverityMask);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_172(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ClientId = 0U;
    Dem_DTCFormatType DTCFormat = 85U;
    Dem_DTCOriginType DTCOrigin = 0U;
  //  boolean FilterWithSeverity = 85U;
    Dem_DTCSeverityType DTCSeverityMask = 32U;
  //  boolean FilterForFaultDetectionCounter = 85U;
    Std_ReturnType returnValue;

    START_TEST("172: Dem_DTCFilterDetCheck",
               "created to solve false case of DTCSeverityMask != (uint8)DEM_DTC_SEV_MAINTENANCE_ONLY at line number 8352");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportError#3");

            /* Call SUT */
            returnValue = Dem_DTCFilterDetCheck(ClientId, DTCFormat, DTCOrigin, DTCSeverityMask);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_173(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ClientId = 0U;
    Dem_DTCFormatType DTCFormat = 85U;
    Dem_DTCOriginType DTCOrigin = 0U;
  //  boolean FilterWithSeverity = 85U;
    Dem_DTCSeverityType DTCSeverityMask = 0U;
  //  boolean FilterForFaultDetectionCounter = 85U;
    Std_ReturnType returnValue;

    START_TEST("173: Dem_DTCFilterDetCheck",
               "created to solve false case of DTCSeverityMask != (uint8)DEM_DTC_SEV_NO_SEVERITY at line number 8351");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportError#3");

            /* Call SUT */
            returnValue = Dem_DTCFilterDetCheck(ClientId, DTCFormat, DTCOrigin, DTCSeverityMask);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_174(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ClientId = 0U;
    Dem_DTCFormatType DTCFormat = 0U;
    Dem_DTCOriginType DTCOrigin = 0U;
   // boolean FilterWithSeverity = 85U;
    Dem_DTCSeverityType DTCSeverityMask = 85U;
  //  boolean FilterForFaultDetectionCounter = 85U;
    Std_ReturnType returnValue;

    START_TEST("174: Dem_DTCFilterDetCheck",
               "created to solve false case of DTCFormat != DEM_DTC_FORMAT_OBD at line number 8348");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportError#3");

            /* Call SUT */
            returnValue = Dem_DTCFilterDetCheck(ClientId, DTCFormat, DTCOrigin, DTCSeverityMask);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_175(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ClientId = 0U;
    Dem_DTCFormatType DTCFormat = 85U;
    Dem_DTCOriginType DTCOrigin = 0U;
  //  boolean FilterWithSeverity = 0U;
    Dem_DTCSeverityType DTCSeverityMask = 85U;
  //  boolean FilterForFaultDetectionCounter = 85U;
    Std_ReturnType returnValue;

    START_TEST("175: Dem_DTCFilterDetCheck",
               "created to solve false case of FilterWithSeverity != (boolean)DEM_DTC_FILTER_WITH_SEVERITY_NO at line number 8336");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportError#3;Det_ReportError#4");

            /* Call SUT */
            returnValue = Dem_DTCFilterDetCheck(ClientId, DTCFormat, DTCOrigin, DTCSeverityMask);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_176(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ClientId = 0U;
    Dem_DTCFormatType DTCFormat = 85U;
    Dem_DTCOriginType DTCOrigin = 0U;
  //  boolean FilterWithSeverity = 1U;
    Dem_DTCSeverityType DTCSeverityMask = 85U;
  //  boolean FilterForFaultDetectionCounter = 85U;
    Std_ReturnType returnValue;

    START_TEST("176: Dem_DTCFilterDetCheck",
               "created to solve false case of FilterWithSeverity != (boolean)DEM_DTC_FILTER_WITH_SEVERITY_YES at line number 8335");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportError#3;Det_ReportError#4");

            /* Call SUT */
            returnValue = Dem_DTCFilterDetCheck(ClientId, DTCFormat, DTCOrigin, DTCSeverityMask);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_177(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 ClientId = 0U;
    Dem_DTCFormatType DTCFormat = 85U;
    Dem_DTCOriginType DTCOrigin = 1U;
  //  boolean FilterWithSeverity = 85U;
    Dem_DTCSeverityType DTCSeverityMask = 85U;
   // boolean FilterForFaultDetectionCounter = 85U;
    Std_ReturnType returnValue;
    Dem_GaaClientList[0].pEventMemorySet = &map_Dem_GaaClientList_0_pEventMemorySet[0];
    map_Dem_GaaClientList_0_pEventMemorySet[0].ucPrimaryMemoryMappingIndex = 85U;
    expected_map_Dem_GaaClientList_0_pEventMemorySet[0].ucPrimaryMemoryMappingIndex = 85U;
    expected_Dem_GaaClientList[0].pEventMemorySet = &map_Dem_GaaClientList_0_pEventMemorySet[0];
    expected_Dem_GaaOriginMemMappingIndex[0] = 85U;

    START_TEST("177: Dem_DTCFilterDetCheck",
               "created to solve true case of DEM_DTC_PRIMARY_MEMORY == DTCOrigin at line number 8264");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportError#4");

            /* Call SUT */
            returnValue = Dem_DTCFilterDetCheck(ClientId, DTCFormat, DTCOrigin, DTCSeverityMask);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_178(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_GstDtcAsyncServiceStat.ucServiceToProcess = 85U;
    expected_Dem_GstDtcAsyncServiceStat.ucServiceToProcess = 85U;
    expected_Dem_GblFDCBufferUpdateFlag_Satellite_1 = 1U;

    START_TEST("178: Dem_ProcessAsyncServiceRequest",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("GetSpinlock#1;ReleaseSpinlock#1");

            /* Call SUT */
            Dem_ProcessAsyncServiceRequest();

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_179(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_GstDtcAsyncServiceStat.ddClrNature = 85U;
    Dem_GstDtcAsyncServiceStat.ucServiceToProcess = 35U;
    expected_Dem_GstDtcAsyncServiceStat.ddClrNature = 85U;
    expected_Dem_GstDtcAsyncServiceStat.ucServiceToProcess = 35U;
    expected_Dem_GblFDCBufferUpdateFlag_Satellite_1 = 1U;
    expected_Dem_GstDtcAsyncServiceStat.ucResponsToSend = 8U;
    expected_Dem_GstDtcAsyncServiceStat.ucClearProcessType = 0U;

    START_TEST("179: Dem_ProcessAsyncServiceRequest",
               "created to solve true case of Dem_GstDtcAsyncServiceStat.ucServiceToProcess == ((uint8) 0x23)  at line number 8417");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportError#5;GetSpinlock#1;ReleaseSpinlock#1");

            /* Call SUT */
            Dem_ProcessAsyncServiceRequest();

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_180(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_GstDtcAsyncServiceStat.ddClrNature = 2U;
    Dem_GstDtcAsyncServiceStat.ucServiceToProcess = 35U;
    expected_Dem_GstDtcAsyncServiceStat.ddClrNature = 2U;
    expected_Dem_GstDtcAsyncServiceStat.ucServiceToProcess = 35U;
    expected_Dem_GblFDCBufferUpdateFlag_Satellite_1 = 1U;
    expected_Dem_GstDtcAsyncServiceStat.ucResponsToSend = 85U;

    START_TEST("180: Dem_ProcessAsyncServiceRequest",
               "created to solve true case of (uint8)DEM_CLEAR_TYPE_SINGLE_DTC == LddClrNature at line number 8447");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_ProcessClearSingleDTC#1;GetSpinlock#1;ReleaseSpinlock#1");

            /* Call SUT */
            Dem_ProcessAsyncServiceRequest();

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_181(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_GstDtcAsyncServiceStat.ddClrNature = 1U;
    Dem_GstDtcAsyncServiceStat.ucServiceToProcess = 35U;
    expected_Dem_GstDtcAsyncServiceStat.ddClrNature = 1U;
    expected_Dem_GstDtcAsyncServiceStat.ucServiceToProcess = 35U;
    expected_Dem_GblFDCBufferUpdateFlag_Satellite_1 = 1U;
    expected_Dem_GstDtcAsyncServiceStat.ucResponsToSend = 85U;

    START_TEST("181: Dem_ProcessAsyncServiceRequest",
               "created to solve true case of (uint8)DEM_CLEAR_TYPE_ALL_DTCS == LddClrNature at line number 8427");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_ClearAllEvents#1;GetSpinlock#1;ReleaseSpinlock#1");

            /* Call SUT */
            Dem_ProcessAsyncServiceRequest();

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_182(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Std_ReturnType returnValue;
    Dem_GstDtcAsyncServiceStat.usIndex = 0U;
    Dem_GaaSuppressionStatus[0] = 85U;
    expected_Dem_GstDtcAsyncServiceStat.usIndex = 0U;
    expected_Dem_GaaSuppressionStatus[0] = 85U;
    expected_Dem_GstDtcAsyncServiceStat.ucClearProcessType = 0U;

    START_TEST("182: Dem_ProcessClearSingleDTC",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_ProcessClearSingleDTC();

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 8U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_183(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Std_ReturnType returnValue;
    Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GstDtcAsyncServiceStat.usIndex = 0U;
    Dem_GstDtcAsyncServiceStat.ddDtcOrigin = 0U;
    Dem_GstDtcAsyncServiceStat.ucServiceToProcess = 85U;
    Dem_GaaSuppressionStatus[0] = 0U;
    expected_Dem_GaaDTCAttributes[0].ucEventDestination = 85U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GstDtcAsyncServiceStat.usIndex = 0U;
    expected_Dem_GstDtcAsyncServiceStat.ddDtcOrigin = 0U;
    expected_Dem_GstDtcAsyncServiceStat.ucServiceToProcess = 85U;
    expected_Dem_GaaSuppressionStatus[0] = 0U;
    expected_Dem_GstDtcAsyncServiceStat.ucClearProcessType = 0U;

    START_TEST("183: Dem_ProcessClearSingleDTC",
               "created to solve true case of LblSuppressionStatus == DEM_FALSE at line number 8626");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportError#6");

            /* Call SUT */
            returnValue = Dem_ProcessClearSingleDTC();

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 9U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_184(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Std_ReturnType returnValue;
    Dem_GaaDTCAttributes[0].ucEventDestination = 0U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GstDtcAsyncServiceStat.usIndex = 0U;
    Dem_GstDtcAsyncServiceStat.ddDtcOrigin = 0U;
    Dem_GaaSuppressionStatus[0] = 0U;
    expected_Dem_GaaDTCAttributes[0].ucEventDestination = 0U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GstDtcAsyncServiceStat.usIndex = 0U;
    expected_Dem_GstDtcAsyncServiceStat.ddDtcOrigin = 0U;
    expected_Dem_GaaSuppressionStatus[0] = 0U;
    expected_Dem_GstDtcAsyncServiceStat.ucClearProcessType = 0U;

    START_TEST("184: Dem_ProcessClearSingleDTC",
               "created to solve true case of Dem_GaaDTCAttributes[DEM_DTC_ATTRIBUTE_INDEX(LusDtcInfoIndex)].    aaEventDestination[DEM_ZERO] ==    ((uint8)(Dem_GstDtcAsyncServiceStat.ddDtcOrigin)) between lines 8635 and 8637");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_ClearGroupEvents#1");

            /* Call SUT */
            returnValue = Dem_ProcessClearSingleDTC();

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 85U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_185(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Std_ReturnType returnValue;
    Dem_GaaDTCAttributes[0].ucEventDestination = 0U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 1U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    Dem_GstDtcAsyncServiceStat.usIndex = 0U;
    Dem_GstDtcAsyncServiceStat.ddDtcOrigin = 0U;
    Dem_GaaSuppressionStatus[0] = 0U;
    expected_Dem_GaaDTCAttributes[0].ucEventDestination = 0U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 1U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaDtcInfo[0].usDTCAttributeIndex = 0U;
    expected_Dem_GstDtcAsyncServiceStat.usIndex = 0U;
    expected_Dem_GstDtcAsyncServiceStat.ddDtcOrigin = 0U;
    expected_Dem_GaaSuppressionStatus[0] = 0U;
    expected_Dem_GstDtcAsyncServiceStat.ucClearProcessType = 0U;

    START_TEST("185: Dem_ProcessClearSingleDTC",
               "created to solve true case of DEM_ZERO < LusCount at line number 8645");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_ClearGroupEvents#2");

            /* Call SUT */
            returnValue = Dem_ProcessClearSingleDTC();

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 85U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_186(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventMemory * LpEventMemory = &map_LpEventMemory_10[0];
    uint8 LucMemMappingIndx = 0U;
    uint8 LucMaxNumOfEventEntry = 85U;
    uint16 LusEventParameterIndex = 0U;
    uint8 LucEventCount = 85U;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaMemFreeStackIndx[0] = 0U;
    Dem_GaaAllEvtStatus[0] = 85U;
    Dem_GstDefaultEventMemory.ddEventId = 0U;
    Dem_GstDefaultEventMemory.ucNumOfFF = 85U;
    Dem_GstDefaultEventMemory.ucOccuranceCounter = 85U;
    Dem_GstDefaultEventMemory.ucAgingCounter = 85U;
    Dem_GstDefaultEventMemory.ucPreviousIndex = 85U;
    Dem_GstDefaultEventMemory.ucNextEventIdIndex = 85U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GstDefaultEventMemory.ddEventId = 0U;
    expected_Dem_GstDefaultEventMemory.ucNumOfFF = 85U;
    expected_Dem_GstDefaultEventMemory.ucOccuranceCounter = 85U;
    expected_Dem_GstDefaultEventMemory.ucAgingCounter = 85U;
    expected_Dem_GstDefaultEventMemory.ucPreviousIndex = 85U;
    expected_Dem_GstDefaultEventMemory.ucNextEventIdIndex = 85U;
    expected_Dem_GaaDtcMainEvent[0] = 0U;
    expected_Dem_GaaAvailableMemIndexs[0][0] = 85U;
    expected_Dem_GaaMemFreeStackIndx[0] = 1U;
    expected_Dem_GaaMemoryIndexForEvt[0] = 255U;
    expected_Dem_GaaAllEvtStatus[0] = 85U;
    expected_map_LpEventMemory_10[85].ddEventId = 0U;
    expected_map_LpEventMemory_10[85].ucNumOfFF = 85U;
    expected_map_LpEventMemory_10[85].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_10[85].ucAgingCounter = 85U;
    expected_map_LpEventMemory_10[85].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_10[85].ucNextEventIdIndex = 85U;

    START_TEST("186: Dem_ProcAgCntrAfterThresholdSatified",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_RearrangeOldEvtsInd#1;SuspendAllInterrupts#1;ResumeAllInterrupts#1;Dem_ClearRecordTriggers#1");

            /* Call SUT */
            Dem_ProcAgCntrAfterThresholdSatified(LpEventMemory, LucMemMappingIndx, LucMaxNumOfEventEntry, LusEventParameterIndex, LucEventCount);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_187(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 0U;

    START_TEST("187: Dem_ProcAgCntrAfterThrSatifiedTfslc",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_ProcAgCntrAfterThrSatifiedTfslc(LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_188(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_GaaEventToDTCIndexMapping[0] = 0U;
    Dem_GaaDtcInfo[0].ddNumberOfEvents = 1U;
    Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    Dem_GaaAllEvtStatus[0] = 85U;
    expected_Dem_GaaEventToDTCIndexMapping[0] = 0U;
    expected_Dem_GaaDtcInfo[0].ddNumberOfEvents = 1U;
    expected_Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
    expected_Dem_GaaAllEvtStatus[0] = 85U;

    START_TEST("188: Dem_ProcAgCntrAfterThrSatifiedTfslc",
               "created to solve true case of LucCombiEvents < DEM_DTC_NUMBER_OF_EVENTS(LusDtcInfoIndex) at line number 9243");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#1;ResumeAllInterrupts#1");

            /* Call SUT */
            Dem_ProcAgCntrAfterThrSatifiedTfslc(LusEventParameterIndex);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_189(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventIdType EventId = 1U;
    uint8 RecordNumber = 85U;
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = NULL;
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = NULL;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = NULL;

    START_TEST("189: Dem_GetEDRecordEx",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetEDRecordEx(EventId, RecordNumber, DestBuffer, BufSize);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_190(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventIdType EventId = 1U;
    uint8 RecordNumber = 85U;
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = &map_BufSize_2[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = NULL;
    Dem_GaaMemoryIndexForEvt[0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].pAgingCycle = NULL;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].pEventMemorySet = NULL;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].DTCPriority = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usAgingCycleCounterThreshold = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usAgingCycleCounterThresholdTFSLC = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 85;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumofEDTfRecords = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaEDBitPositionTF[0] = 85;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfFFRecNum = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaFreezeFrameRecords[0] = 85;
//    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumofFFTfRecords = 85U;
  //  map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaFFBitPositionTF[0] = 85;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaDataIdArray[0] = 85;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 85U;
//    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNoOfDestinationSelected = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMemoryMappingIndex = 85;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEdRecordClassIndex = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucFFClassIndex = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucClientId = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].blAgingAllowed = 85U;
//    map_Dem_GaaEventParameter_0_pDTCAttribute[0].blDemImmediateNvStorage = 85U;
    map_BufSize_2[0] = 0U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = NULL;
    expected_Dem_GaaMemoryIndexForEvt[0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].pAgingCycle = NULL;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].pEventMemorySet = NULL;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].DTCPriority = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usAgingCycleCounterThreshold = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usAgingCycleCounterThresholdTFSLC = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 85;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumofEDTfRecords = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaEDBitPositionTF[0] = 85;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfFFRecNum = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaFreezeFrameRecords[0] = 85;
//    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumofFFTfRecords = 85U;
  //  expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaFFBitPositionTF[0] = 85;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaDataIdArray[0] = 85;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 85U;
//    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNoOfDestinationSelected = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMemoryMappingIndex = 85;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEdRecordClassIndex = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucFFClassIndex = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucClientId = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].blAgingAllowed = 85U;
//    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].blDemImmediateNvStorage = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_BufSize_2[0] = 0U;

    START_TEST("190: Dem_GetEDRecordEx",
               "created to solve true case of NULL_PTR != LpDTCAttribute at line number 9606");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_GetSizeOfEDRecordForEvent#1;Dem_CheckExtendedDataRecord#1");

            /* Call SUT */
            returnValue = Dem_GetEDRecordEx(EventId, RecordNumber, DestBuffer, BufSize);

            /* Test case checks */
         //   CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_191(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventIdType EventId = 1U;
    uint8 RecordNumber = 85U;
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = &map_BufSize_2[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = NULL;
    Dem_GaaMemoryIndexForEvt[0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].pAgingCycle = NULL;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].pEventMemorySet = NULL;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].DTCPriority = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usAgingCycleCounterThreshold = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].usAgingCycleCounterThresholdTFSLC = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 85;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumofEDTfRecords = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaEDBitPositionTF[0] = 85;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfFFRecNum = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaFreezeFrameRecords[0] = 85;
//    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumofFFTfRecords = 85U;
  //  map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaFFBitPositionTF[0] = 85;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaDataIdArray[0] = 85;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 85U;
//    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNoOfDestinationSelected = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMemoryMappingIndex = 85;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEdRecordClassIndex = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucFFClassIndex = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucClientId = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].blAgingAllowed = 85U;
//    map_Dem_GaaEventParameter_0_pDTCAttribute[0].blDemImmediateNvStorage = 85U;
    map_BufSize_2[0] = 0U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = NULL;
    expected_Dem_GaaMemoryIndexForEvt[0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].pAgingCycle = NULL;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].pEventMemorySet = NULL;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usFFRecordRawDataSize = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].DTCPriority = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usAgingCycleCounterThreshold = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].usAgingCycleCounterThresholdTFSLC = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 85;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumofEDTfRecords = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaEDBitPositionTF[0] = 85;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfFFRecNum = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaFreezeFrameRecords[0] = 85;
//    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumofFFTfRecords = 85U;
  //  expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaFFBitPositionTF[0] = 85;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfDataId = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaDataIdArray[0] = 85;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMaxNumOfFFRecord = 85U;
//    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNoOfDestinationSelected = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucMemoryMappingIndex = 85;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEdRecordClassIndex = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucFFClassIndex = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucClientId = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].blAgingAllowed = 85U;
//    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].blDemImmediateNvStorage = 85U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_BufSize_2[0] = 0U;

    START_TEST("191: Dem_GetEDRecordEx",
               "created to solve false case of DEM_TRUE != LblRecFound at line number 9648");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_GetSizeOfEDRecordForEvent#1;Dem_CheckExtendedDataRecord#2");

            /* Call SUT */
            returnValue = Dem_GetEDRecordEx(EventId, RecordNumber, DestBuffer, BufSize);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 85U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_192(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventIdType EventId = 1U;
    uint8 RecordNumber = 85U;
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = &map_BufSize_2[0];
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginMappingIndx[0] = 0U;
    Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = NULL;
    Dem_GaaMemoryIndexForEvt[0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    map_BufSize_2[0] = 0U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].pEventMemory = NULL;
    expected_Dem_GaaMemoryIndexForEvt[0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_map_BufSize_2[0] = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];

    START_TEST("192: Dem_GetEDRecordEx",
               "created to solve true case of *BufSize < LusSize at line number 9623");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_GetSizeOfEDRecordForEvent#2;Det_ReportError#8");

            /* Call SUT */
            returnValue = Dem_GetEDRecordEx(EventId, RecordNumber, DestBuffer, BufSize);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 21U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_193(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventIdType EventId = 1U;
    uint8 RecordNumber = 85U;
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = NULL;
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    Dem_GaaMemoryIndexForEvt[0] = 255U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_Dem_GaaMemoryIndexForEvt[0] = 255U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];

    START_TEST("193: Dem_GetEDRecordEx",
               "created to solve false case of DEM_INVALID_MEMORY_INDEX != LucFreeIndex at line number 9611");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportRuntimeError#2");

            /* Call SUT */
            returnValue = Dem_GetEDRecordEx(EventId, RecordNumber, DestBuffer, BufSize);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_194(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventIdType EventId = 1U;
    uint8 RecordNumber = 85U;
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = NULL;
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    Dem_GaaMemoryIndexForEvt[0] = 255U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_Dem_GaaMemoryIndexForEvt[0] = 255U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];

    START_TEST("194: Dem_GetEDRecordEx",
               "created to solve false case of LucRecIndex < LucNumOfEDRecords at line number 9663");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Det_ReportRuntimeError#2");

            /* Call SUT */
            returnValue = Dem_GetEDRecordEx(EventId, RecordNumber, DestBuffer, BufSize);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_195(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventIdType EventId = 1U;
    uint8 RecordNumber = 0U;
    uint8 * DestBuffer = NULL;
    uint16 * BufSize = NULL;
    Std_ReturnType returnValue;
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 1U;
    Dem_GaaMemoryIndexForEvt[0] = 255U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 1U;
    expected_Dem_GaaMemoryIndexForEvt[0] = 255U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];

    START_TEST("195: Dem_GetEDRecordEx",
               "created to solve false case of LucRecIndex < LucNumOfEDRecords at line number 9663");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_GetEDRecordEx(EventId, RecordNumber, DestBuffer, BufSize);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_196(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucFreeIndex = 85U;
    uint16* LpBufSize = &map_LpBufSize_2[0];
    uint8 ExtendedDataNumber = 85U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_11[0];
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    map_LpEventMemory_11[85].ddEventId = 1U;
    map_LpEventMemory_11[85].aaEdData[0][0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    map_LpBufSize_2[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_Dem_GaaEDRecord[0].usEDRecordRawDataSize = 0U;
    expected_map_LpEventMemory_11[85].ddEventId = 1U;
    expected_map_LpEventMemory_11[85].aaEdData[0][0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpBufSize_2[0] = 0U;

    START_TEST("196: Dem_GetSizeOfEDRecordForEvent",
               "created to solve false case of LucRecCnt < LucNumOfEDRec at line number 9750");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_GetSizeOfEDRecordForEvent(LucFreeIndex, LpBufSize, ExtendedDataNumber, LpEventMemory);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_197(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucFreeIndex = 85U;
    uint16* LpBufSize = &map_LpBufSize_2[0];
    uint8 ExtendedDataNumber = 1U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_11[0];
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    map_LpEventMemory_11[85].ddEventId = 1U;
    map_LpEventMemory_11[85].aaEdData[0][0] = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    map_LpBufSize_2[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    expected_map_LpEventMemory_11[85].ddEventId = 1U;
    expected_map_LpEventMemory_11[85].aaEdData[0][0] = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpBufSize_2[0] = 0U;

    START_TEST("197: Dem_GetSizeOfEDRecordForEvent",
               "created to solve false case of LucRecCnt < LucNumOfEDRec at line number 9750");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_GetSizeOfEDRecordForEvent(LucFreeIndex, LpBufSize, ExtendedDataNumber, LpEventMemory);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_198(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucFreeIndex = 85U;
    uint16* LpBufSize = NULL;
    uint8 ExtendedDataNumber = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_11[0];
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    map_LpEventMemory_11[85].ddEventId = 1U;
    map_LpEventMemory_11[85].aaEdData[0][0] = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 85U;
    expected_map_LpEventMemory_11[85].ddEventId = 1U;
    expected_map_LpEventMemory_11[85].aaEdData[0][0] = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];

    START_TEST("198: Dem_GetSizeOfEDRecordForEvent",
               "created to solve false case of LucRecCnt < LucNumOfEDRec at line number 9750");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_GetSizeOfEDRecordForEvent(LucFreeIndex, LpBufSize, ExtendedDataNumber, LpEventMemory);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_199(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucFreeIndex = 85U;
    uint16* LpBufSize = NULL;
    uint8 ExtendedDataNumber = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_11[0];
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    map_LpEventMemory_11[85].ddEventId = 1U;
    map_LpEventMemory_11[85].aaEdData[0][0] = 1U;
    map_LpEventMemory_11[85].aaEdData[0][1] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    expected_map_LpEventMemory_11[85].ddEventId = 1U;
    expected_map_LpEventMemory_11[85].aaEdData[0][0] = 1U;
    expected_map_LpEventMemory_11[85].aaEdData[0][1] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];

    START_TEST("199: Dem_GetSizeOfEDRecordForEvent",
               "created to solve false case of LucRecCnt < LucNumOfEDRec at line number 9750");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_GetSizeOfEDRecordForEvent(LucFreeIndex, LpBufSize, ExtendedDataNumber, LpEventMemory);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_200(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 LucFreeIndex = 85U;
    uint16* LpBufSize = &map_LpBufSize_2[0];
    uint8 ExtendedDataNumber = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_11[0];
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    Dem_GaaEDRecord[0].ucNumOfDataElements = 85U;
    map_LpEventMemory_11[85].ddEventId = 1U;
    map_LpEventMemory_11[85].aaEdData[0][0] = 1U;
    map_LpEventMemory_11[85].aaEdData[0][1] = 255U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    map_LpBufSize_2[0] = 0U;
    expected_Dem_GaaEDRecord[0].ucExtendedDataRecordNumber = 0U;
    expected_Dem_GaaEDRecord[0].ucNumOfDataElements = 85U;
    expected_map_LpEventMemory_11[85].ddEventId = 1U;
    expected_map_LpEventMemory_11[85].aaEdData[0][0] = 1U;
    expected_map_LpEventMemory_11[85].aaEdData[0][1] = 255U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucNumOfEDRecords = 1U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].aaExtendedDataRecords[0] = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_LpBufSize_2[0] = 85U;

    START_TEST("200: Dem_GetSizeOfEDRecordForEvent",
               "created to solve false case of LucRecCnt < LucNumOfEDRec at line number 9750");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_GetSizeOfEDRecordForEvent(LucFreeIndex, LpBufSize, ExtendedDataNumber, LpEventMemory);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_201(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint8 LucFreeIndex = 85U;
    boolean * LblRecordFound = &map_LblRecordFound_2[0];
    uint16 DataId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_12[0];
    uint8* LpDestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_4[0];
    uint16 * BufSize = NULL;
    Std_ReturnType returnValue;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    map_LpDTCAttribute_4[0].ucMaxNumOfFFRecord = 85U;
    map_LblRecordFound_2[0] = 85U;
    map_LpEventMemory_12[0].ddEventId = 0U;
    map_LpEventMemory_12[0].ucNumOfFF = 85U;
    map_LpEventMemory_12[0].ucOccuranceCounter = 85U;
    map_LpEventMemory_12[0].ucAgingCounter = 85U;
    map_LpEventMemory_12[0].ucPreviousIndex = 85U;
    map_LpEventMemory_12[0].ucNextEventIdIndex = 85U;
    map_LpEventMemory_12[85].ddEventId = 0U;
    map_LpEventMemory_12[85].ucNumOfFF = 85U;
    map_LpEventMemory_12[85].ucOccuranceCounter = 85U;
    map_LpEventMemory_12[85].ucAgingCounter = 85U;
    map_LpEventMemory_12[85].ucPreviousIndex = 85U;
    map_LpEventMemory_12[85].ucNextEventIdIndex = 85U;
    map_LpEventMemory_12[85].aaFFRecNumAndData[0][0] = 85U;
    map_LpEventMemory_12[85].aaFFRecNumAndData[0][1] = 85;
    map_LpEventMemory_12[85].aaFFRecNumAndData[0][2] = 85;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_map_LpDTCAttribute_4[0].ucMaxNumOfFFRecord = 85U;
    expected_map_LpEventMemory_12[0].ddEventId = 0U;
    expected_map_LpEventMemory_12[0].ucNumOfFF = 85U;
    expected_map_LpEventMemory_12[0].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_12[0].ucAgingCounter = 85U;
    expected_map_LpEventMemory_12[0].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_12[0].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_12[85].ddEventId = 0U;
    expected_map_LpEventMemory_12[85].ucNumOfFF = 85U;
    expected_map_LpEventMemory_12[85].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_12[85].ucAgingCounter = 85U;
    expected_map_LpEventMemory_12[85].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_12[85].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_12[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_LpEventMemory_12[85].aaFFRecNumAndData[0][1] = 85;
    expected_map_LpEventMemory_12[85].aaFFRecNumAndData[0][2] = 85;
    expected_map_LblRecordFound_2[0] = 1U;

    START_TEST("201: Dem_SearchRecInMem",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#5");

            /* Call SUT */
            returnValue = Dem_SearchRecInMem(RecordNumber, LucFreeIndex, LblRecordFound, DataId, LpEventMemory, LpDestBuffer, LpDTCAttribute, BufSize);

            /* Test case checks */
//            CHECK_U_CHAR(returnValue, 85U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_202(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint8 LucFreeIndex = 85U;
    boolean * LblRecordFound = &map_LblRecordFound_2[0];
    uint16 DataId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_12[0];
    uint8* LpDestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_4[0];
    uint16 * BufSize = NULL;
    Std_ReturnType returnValue;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    map_LpDTCAttribute_4[0].ucMaxNumOfFFRecord = 1U;
    map_LblRecordFound_2[0] = 85U;
    map_LpEventMemory_12[0].ddEventId = 0U;
    map_LpEventMemory_12[0].ucNumOfFF = 85U;
    map_LpEventMemory_12[0].ucOccuranceCounter = 85U;
    map_LpEventMemory_12[0].ucAgingCounter = 85U;
    map_LpEventMemory_12[0].ucPreviousIndex = 85U;
    map_LpEventMemory_12[0].ucNextEventIdIndex = 85U;
    map_LpEventMemory_12[85].ddEventId = 0U;
    map_LpEventMemory_12[85].ucNumOfFF = 85U;
    map_LpEventMemory_12[85].ucOccuranceCounter = 85U;
    map_LpEventMemory_12[85].ucAgingCounter = 85U;
    map_LpEventMemory_12[85].ucPreviousIndex = 85U;
    map_LpEventMemory_12[85].ucNextEventIdIndex = 85U;
    map_LpEventMemory_12[85].aaFFRecNumAndData[0][0] = 85U;
    map_LpEventMemory_12[85].aaFFRecNumAndData[0][1] = 85;
    map_LpEventMemory_12[85].aaFFRecNumAndData[0][2] = 85;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_map_LpDTCAttribute_4[0].ucMaxNumOfFFRecord = 1U;
    expected_map_LpEventMemory_12[0].ddEventId = 0U;
    expected_map_LpEventMemory_12[0].ucNumOfFF = 85U;
    expected_map_LpEventMemory_12[0].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_12[0].ucAgingCounter = 85U;
    expected_map_LpEventMemory_12[0].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_12[0].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_12[85].ddEventId = 0U;
    expected_map_LpEventMemory_12[85].ucNumOfFF = 85U;
    expected_map_LpEventMemory_12[85].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_12[85].ucAgingCounter = 85U;
    expected_map_LpEventMemory_12[85].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_12[85].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_12[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_LpEventMemory_12[85].aaFFRecNumAndData[0][1] = 85;
    expected_map_LpEventMemory_12[85].aaFFRecNumAndData[0][2] = 85;
    expected_map_LblRecordFound_2[0] = 1U;

    START_TEST("202: Dem_SearchRecInMem",
               "created to solve false case of LucRecordCount <      LucCmpRecord between lines 9889 and 9890");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#5");

            /* Call SUT */
            returnValue = Dem_SearchRecInMem(RecordNumber, LucFreeIndex, LblRecordFound, DataId, LpEventMemory, LpDestBuffer, LpDTCAttribute, BufSize);

            /* Test case checks */
         //   CHECK_U_CHAR(returnValue, 85U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_203(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint8 LucFreeIndex = 85U;
    boolean * LblRecordFound = &map_LblRecordFound_2[0];
    uint16 DataId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_12[0];
    uint8* LpDestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_4[0];
    uint16 * BufSize = NULL;
    Std_ReturnType returnValue;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    map_LpDTCAttribute_4[0].ucMaxNumOfFFRecord = 85U;
    map_LblRecordFound_2[0] = 85U;
    map_LpEventMemory_12[0].ddEventId = 0U;
    map_LpEventMemory_12[0].ucNumOfFF = 85U;
    map_LpEventMemory_12[0].ucOccuranceCounter = 85U;
    map_LpEventMemory_12[0].ucAgingCounter = 85U;
    map_LpEventMemory_12[0].ucPreviousIndex = 85U;
    map_LpEventMemory_12[0].ucNextEventIdIndex = 85U;
    map_LpEventMemory_12[85].ddEventId = 0U;
    map_LpEventMemory_12[85].ucNumOfFF = 85U;
    map_LpEventMemory_12[85].ucOccuranceCounter = 85U;
    map_LpEventMemory_12[85].ucAgingCounter = 85U;
    map_LpEventMemory_12[85].ucPreviousIndex = 85U;
    map_LpEventMemory_12[85].ucNextEventIdIndex = 85U;
    map_LpEventMemory_12[85].aaFFRecNumAndData[0][0] = 85U;
    map_LpEventMemory_12[85].aaFFRecNumAndData[0][1] = 85;
    map_LpEventMemory_12[85].aaFFRecNumAndData[0][2] = 85;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_map_LpDTCAttribute_4[0].ucMaxNumOfFFRecord = 85U;
    expected_map_LpEventMemory_12[0].ddEventId = 0U;
    expected_map_LpEventMemory_12[0].ucNumOfFF = 85U;
    expected_map_LpEventMemory_12[0].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_12[0].ucAgingCounter = 85U;
    expected_map_LpEventMemory_12[0].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_12[0].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_12[85].ddEventId = 0U;
    expected_map_LpEventMemory_12[85].ucNumOfFF = 85U;
    expected_map_LpEventMemory_12[85].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_12[85].ucAgingCounter = 85U;
    expected_map_LpEventMemory_12[85].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_12[85].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_12[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_LpEventMemory_12[85].aaFFRecNumAndData[0][1] = 85;
    expected_map_LpEventMemory_12[85].aaFFRecNumAndData[0][2] = 85;
    expected_map_LblRecordFound_2[0] = 1U;

    START_TEST("203: Dem_SearchRecInMem",
               "created to solve true case of LddReturnValue == E_NOT_OK at line number 9906");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#5");

            /* Call SUT */
            returnValue = Dem_SearchRecInMem(RecordNumber, LucFreeIndex, LblRecordFound, DataId, LpEventMemory, LpDestBuffer, LpDTCAttribute, BufSize);

            /* Test case checks */
//            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_204(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 1U;
    uint8 LucFreeIndex = 85U;
    boolean * LblRecordFound = &map_LblRecordFound_2[0];
    uint16 DataId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_12[0];
    uint8* LpDestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_4[0];
    uint16 * BufSize = NULL;
    Std_ReturnType returnValue;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    map_LpDTCAttribute_4[0].ucMaxNumOfFFRecord = 1U;
    map_LblRecordFound_2[0] = 85U;
    map_LpEventMemory_12[85].aaFFRecNumAndData[0][0] = 0U;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
    expected_map_LpDTCAttribute_4[0].ucMaxNumOfFFRecord = 1U;
    expected_map_LblRecordFound_2[0] = 85U;
    expected_map_LpEventMemory_12[85].aaFFRecNumAndData[0][0] = 0U;

    START_TEST("204: Dem_SearchRecInMem",
               "created to solve false case of LucRecordCount <      LucCmpRecord between lines 9889 and 9890");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#5");

            /* Call SUT */
            returnValue = Dem_SearchRecInMem(RecordNumber, LucFreeIndex, LblRecordFound, DataId, LpEventMemory, LpDestBuffer, LpDTCAttribute, BufSize);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_205(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 85U;
    uint8 LucFreeIndex = 85U;
    boolean * LblRecordFound = &map_LblRecordFound_2[0];
    uint16 DataId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_12[0];
    uint8* LpDestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_4[0];
    uint16 * BufSize = NULL;
    Std_ReturnType returnValue;
    Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 1U;
    map_LpDTCAttribute_4[0].ucNumOfFFRecNum = 85U;
    map_LblRecordFound_2[0] = 85U;
    map_LpEventMemory_12[0].ddEventId = 0U;
    map_LpEventMemory_12[0].ucNumOfFF = 85U;
    map_LpEventMemory_12[0].ucOccuranceCounter = 85U;
    map_LpEventMemory_12[0].ucAgingCounter = 85U;
    map_LpEventMemory_12[0].ucPreviousIndex = 85U;
    map_LpEventMemory_12[0].ucNextEventIdIndex = 85U;
    map_LpEventMemory_12[85].ddEventId = 0U;
    map_LpEventMemory_12[85].ucNumOfFF = 85U;
    map_LpEventMemory_12[85].ucOccuranceCounter = 85U;
    map_LpEventMemory_12[85].ucAgingCounter = 85U;
    map_LpEventMemory_12[85].ucPreviousIndex = 85U;
    map_LpEventMemory_12[85].ucNextEventIdIndex = 85U;
    map_LpEventMemory_12[85].aaFFRecNumAndData[0][0] = 85U;
    map_LpEventMemory_12[85].aaFFRecNumAndData[0][1] = 85;
    map_LpEventMemory_12[85].aaFFRecNumAndData[0][2] = 85;
    expected_Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 1U;
    expected_map_LpDTCAttribute_4[0].ucNumOfFFRecNum = 85U;
    expected_map_LpEventMemory_12[0].ddEventId = 0U;
    expected_map_LpEventMemory_12[0].ucNumOfFF = 85U;
    expected_map_LpEventMemory_12[0].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_12[0].ucAgingCounter = 85U;
    expected_map_LpEventMemory_12[0].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_12[0].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_12[85].ddEventId = 0U;
    expected_map_LpEventMemory_12[85].ucNumOfFF = 85U;
    expected_map_LpEventMemory_12[85].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_12[85].ucAgingCounter = 85U;
    expected_map_LpEventMemory_12[85].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_12[85].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_12[85].aaFFRecNumAndData[0][0] = 85U;
    expected_map_LpEventMemory_12[85].aaFFRecNumAndData[0][1] = 85;
    expected_map_LpEventMemory_12[85].aaFFRecNumAndData[0][2] = 85;
    expected_map_LblRecordFound_2[0] = 1U;

    START_TEST("205: Dem_SearchRecInMem",
               "created to solve true case of Dem_GaaDTCOriginBasedPtrAddress[LucMemIndx].ucFfRecordEnumType ==        DEM_FF_RECNUM_CONFIGURED between lines 9877 and 9878");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_DtcAttrSearchInMemory#5");

            /* Call SUT */
            returnValue = Dem_SearchRecInMem(RecordNumber, LucFreeIndex, LblRecordFound, DataId, LpEventMemory, LpDestBuffer, LpDTCAttribute, BufSize);

            /* Test case checks */
//            CHECK_U_CHAR(returnValue, 85U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_206(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 255U;
    uint8 LucFreeIndex = 85U;
    boolean * LblRecordFound = NULL;
    uint16 DataId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_12[0];
    uint8* LpDestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = NULL;
    uint16 * BufSize = NULL;
    Std_ReturnType returnValue;
    map_LpEventMemory_12[0].ddEventId = 0U;
    map_LpEventMemory_12[0].ucNumOfFF = 85U;
    map_LpEventMemory_12[0].ucOccuranceCounter = 85U;
    map_LpEventMemory_12[0].ucAgingCounter = 85U;
    map_LpEventMemory_12[0].ucPreviousIndex = 85U;
    map_LpEventMemory_12[0].ucNextEventIdIndex = 85U;
    map_LpEventMemory_12[85].ddEventId = 0U;
    map_LpEventMemory_12[85].ucNumOfFF = 85U;
    map_LpEventMemory_12[85].ucOccuranceCounter = 85U;
    map_LpEventMemory_12[85].ucAgingCounter = 85U;
    map_LpEventMemory_12[85].ucPreviousIndex = 85U;
    map_LpEventMemory_12[85].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_12[0].ddEventId = 0U;
    expected_map_LpEventMemory_12[0].ucNumOfFF = 85U;
    expected_map_LpEventMemory_12[0].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_12[0].ucAgingCounter = 85U;
    expected_map_LpEventMemory_12[0].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_12[0].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_12[85].ddEventId = 0U;
    expected_map_LpEventMemory_12[85].ucNumOfFF = 85U;
    expected_map_LpEventMemory_12[85].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_12[85].ucAgingCounter = 85U;
    expected_map_LpEventMemory_12[85].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_12[85].ucNextEventIdIndex = 85U;

    START_TEST("206: Dem_SearchRecInMem",
               "created to solve true case of RecordNumber == DEM_MAX_RECORD at line number 9843");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_GetFFDidData#3");

            /* Call SUT */
            returnValue = Dem_SearchRecInMem(RecordNumber, LucFreeIndex, LblRecordFound, DataId, LpEventMemory, LpDestBuffer, LpDTCAttribute, BufSize);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 85U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_207(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 255U;
    uint8 LucFreeIndex = 85U;
    boolean * LblRecordFound = NULL;
    uint16 DataId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_12[0];
    uint8* LpDestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = NULL;
    uint16 * BufSize = NULL;
    Std_ReturnType returnValue;
    map_LpEventMemory_12[0].ddEventId = 0U;
    map_LpEventMemory_12[0].ucNumOfFF = 85U;
    map_LpEventMemory_12[0].ucOccuranceCounter = 85U;
    map_LpEventMemory_12[0].ucAgingCounter = 85U;
    map_LpEventMemory_12[0].ucPreviousIndex = 85U;
    map_LpEventMemory_12[0].ucNextEventIdIndex = 85U;
    map_LpEventMemory_12[85].ddEventId = 0U;
    map_LpEventMemory_12[85].ucNumOfFF = 85U;
    map_LpEventMemory_12[85].ucOccuranceCounter = 85U;
    map_LpEventMemory_12[85].ucAgingCounter = 85U;
    map_LpEventMemory_12[85].ucPreviousIndex = 85U;
    map_LpEventMemory_12[85].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_12[0].ddEventId = 0U;
    expected_map_LpEventMemory_12[0].ucNumOfFF = 85U;
    expected_map_LpEventMemory_12[0].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_12[0].ucAgingCounter = 85U;
    expected_map_LpEventMemory_12[0].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_12[0].ucNextEventIdIndex = 85U;
    expected_map_LpEventMemory_12[85].ddEventId = 0U;
    expected_map_LpEventMemory_12[85].ucNumOfFF = 85U;
    expected_map_LpEventMemory_12[85].ucOccuranceCounter = 85U;
    expected_map_LpEventMemory_12[85].ucAgingCounter = 85U;
    expected_map_LpEventMemory_12[85].ucPreviousIndex = 85U;
    expected_map_LpEventMemory_12[85].ucNextEventIdIndex = 85U;

    START_TEST("207: Dem_SearchRecInMem",
               "created to solve true case of E_NOT_OK == LddReturnValue at line number 9859");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("Dem_GetFFDidData#4");

            /* Call SUT */
            returnValue = Dem_SearchRecInMem(RecordNumber, LucFreeIndex, LblRecordFound, DataId, LpEventMemory, LpDestBuffer, LpDTCAttribute, BufSize);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_208(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint8 RecordNumber = 255U;
    uint8 LucFreeIndex = 85U;
    boolean * LblRecordFound = NULL;
    uint16 DataId = 0U;
    const Dem_EventMemory * LpEventMemory = &map_LpEventMemory_12[0];
    uint8* LpDestBuffer = NULL;
    const Dem_DTCAttributeType * LpDTCAttribute = NULL;
    uint16 * BufSize = NULL;
    Std_ReturnType returnValue;
    map_LpEventMemory_12[85].ucNumOfFF = 0U;
    expected_map_LpEventMemory_12[85].ucNumOfFF = 0U;

    START_TEST("208: Dem_SearchRecInMem",
               "created to solve false case of (LpEventMemory + LucFreeIndex)->ucNumOfFF > DEM_ZERO at line number 9850");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            returnValue = Dem_SearchRecInMem(RecordNumber, LucFreeIndex, LblRecordFound, DataId, LpEventMemory, LpDestBuffer, LpDTCAttribute, BufSize);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 48U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_209(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventIdType EventParameterIndex = 0U;
    uint8 * PMemMapIndx = &map_PMemMapIndx[0];
    Dem_GaaEventParameter[0].pDTCAttribute = NULL;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = NULL;
    expected_map_PMemMapIndx[0] = 0U;

    START_TEST("209: Dem_EventSearchInMemory",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_EventSearchInMemory(EventParameterIndex, PMemMapIndx);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_210(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    Dem_EventIdType EventParameterIndex = 0U;
    uint8 * PMemMapIndx = &map_PMemMapIndx[0];
    Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    Dem_GaaDTCOriginMappingIndx[0] = 85U;
    map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 85U;
    expected_map_Dem_GaaEventParameter_0_pDTCAttribute[0].ucEventDestination = 0U;
    expected_Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_GaaEventParameter_0_pDTCAttribute[0];
    expected_map_PMemMapIndx[0] = 85U;

    START_TEST("210: Dem_EventSearchInMemory",
               "created to solve true case of NULL_PTR != LpDTCAttribute at line number 10427");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_EventSearchInMemory(EventParameterIndex, PMemMapIndx);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_211(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    const Dem_DTCAttributeType * LpDTCAttribute = NULL;
    uint8 * PMemMapIndx = &map_PMemMapIndx_1[0];
    expected_map_PMemMapIndx_1[0] = 0U;

    START_TEST("211: Dem_DtcAttrSearchInMemory",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_DtcAttrSearchInMemory(LpDTCAttribute, PMemMapIndx);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_212(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    const Dem_DTCAttributeType * LpDTCAttribute = &map_LpDTCAttribute_5[0];
    uint8 * PMemMapIndx = &map_PMemMapIndx_1[0];
    Dem_GaaDTCOriginMappingIndx[0] = 85U;
    map_LpDTCAttribute_5[0].ucEventDestination = 0U;
    expected_Dem_GaaDTCOriginMappingIndx[0] = 85U;
    expected_map_LpDTCAttribute_5[0].ucEventDestination = 0U;
    expected_map_PMemMapIndx_1[0] = 85U;

    START_TEST("212: Dem_DtcAttrSearchInMemory",
               "created to solve true case of NULL_PTR  != LpDTCAttribute at line number 10487");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");

            /* Call SUT */
            Dem_DtcAttrSearchInMemory(LpDTCAttribute, PMemMapIndx);

            /* Test case checks */
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_213(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Std_ReturnType returnValue;
    Dem_GaaEvtPreConditions[0] = 85U;
    expected_Dem_GaaEvtPreConditions[0] = 85U;

    START_TEST("213: Dem_ResetEventStatusMultiEventTriggering",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#5;ResumeAllInterrupts#6");

            /* Call SUT */
            returnValue = Dem_ResetEventStatusMultiEventTriggering(LusEventParameterIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_214(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Std_ReturnType returnValue;
    Dem_GaaAllEvtStatus[0] = 85U;
    Dem_GaaEvtPreConditions[0] = 0U;
    expected_Dem_GaaEvtPreConditions[0] = 0U;
    expected_Dem_GaaAllEvtStatus[0] = 84U;

    START_TEST("214: Dem_ResetEventStatusMultiEventTriggering",
               "created to solve true case of DEM_ZERO ==  (LucPreCondition &                              DEM_PRECOND_EVENTAVAI_COMPAVAIL_BIT_VALUE) between lines 11249 and 11250");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#5;ResumeAllInterrupts#6;SuspendAllInterrupts#5;ResumeAllInterrupts#6;Dem_DtcStatusChange#1");

            /* Call SUT */
            returnValue = Dem_ResetEventStatusMultiEventTriggering(LusEventParameterIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_215(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Std_ReturnType returnValue;
    Dem_GaaAllEvtStatus[0] = 85U;
    Dem_GaaEvtPreConditions[0] = 0U;
    expected_Dem_GaaEvtPreConditions[0] = 0U;
    expected_Dem_GaaAllEvtStatus[0] = 84U;

    START_TEST("215: Dem_ResetEventStatusMultiEventTriggering",
               "created to solve true case of NULL_PTR != LpDTCAttribute at line number 11372");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#5;ResumeAllInterrupts#6;SuspendAllInterrupts#5;ResumeAllInterrupts#6;Dem_DtcStatusChange#2");

            /* Call SUT */
            returnValue = Dem_ResetEventStatusMultiEventTriggering(LusEventParameterIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_216(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Std_ReturnType returnValue;
    Dem_GaaAllEvtStatus[0] = 85U;
    Dem_GaaEvtPreConditions[0] = 0U;
    expected_Dem_GaaEvtPreConditions[0] = 0U;
    expected_Dem_GaaAllEvtStatus[0] = 84U;

    START_TEST("216: Dem_ResetEventStatusMultiEventTriggering",
               "created to solve false case of DEM_DEBOUNCE_MONITOR_BASED !=              Dem_GaaEventParameter[LusEventParameterIndex].ucDebounceType between lines 11282 and 11283");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#5;ResumeAllInterrupts#6;SuspendAllInterrupts#5;ResumeAllInterrupts#6;Dem_DtcStatusChange#1");

            /* Call SUT */
            returnValue = Dem_ResetEventStatusMultiEventTriggering(LusEventParameterIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_217(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Std_ReturnType returnValue;
    Dem_GaaAllEvtStatus[0] = 0U;
    Dem_GaaEvtPreConditions[0] = 0U;
    expected_Dem_GaaAllEvtStatus[0] = 0U;
    expected_Dem_GaaEvtPreConditions[0] = 0U;

    START_TEST("217: Dem_ResetEventStatusMultiEventTriggering",
               "created to solve false case of (Dem_GaaAllEvtStatus[LusEventParameterIndex] &              DEM_EVENTSTATUS_BIT6_SET) == DEM_EVENTSTATUS_BIT6_SET between lines 11256 and 11257");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#5;ResumeAllInterrupts#6;SuspendAllInterrupts#5;ResumeAllInterrupts#6");

            /* Call SUT */
            returnValue = Dem_ResetEventStatusMultiEventTriggering(LusEventParameterIndex);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_218(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_DebounceResetStatusType DebounceResetStatus = 85U;
    Std_ReturnType returnValue;
    Dem_GaaEvtPreConditions[0] = 85U;
    expected_Dem_GaaEvtPreConditions[0] = 85U;

    START_TEST("218: Dem_ResetEventDebounceStatusMultiEventTriggering",
               "default case");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#6;ResumeAllInterrupts#7");

            /* Call SUT */
            returnValue = Dem_ResetEventDebounceStatusMultiEventTriggering(LusEventParameterIndex, DebounceResetStatus);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 1U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_219(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_DebounceResetStatusType DebounceResetStatus = 85U;
    Std_ReturnType returnValue;
    Dem_GaaEvtPreConditions[0] = 0U;
    expected_Dem_GaaEvtPreConditions[0] = 0U;

    START_TEST("219: Dem_ResetEventDebounceStatusMultiEventTriggering",
               "created to solve true case of DEM_ZERO ==  (LucEvtPreCondition &                           DEM_PRECOND_EVENTAVAI_COMPAVAIL_BIT_VALUE) between lines 11487 and 11488");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#6;ResumeAllInterrupts#7");

            /* Call SUT */
            returnValue = Dem_ResetEventDebounceStatusMultiEventTriggering(LusEventParameterIndex, DebounceResetStatus);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

void test_220(int doIt){
if (doIt) {
    /* Set global data */
    initialise_global_data();
    /* Set expected values for global data checks */
    initialise_expected_global_data();
    {
    /* Test case data declarations */
    uint16 LusEventParameterIndex = 0U;
    Dem_DebounceResetStatusType DebounceResetStatus = 1U;
    Std_ReturnType returnValue;
    Dem_GaaEvtPreConditions[0] = 0U;
    expected_Dem_GaaEvtPreConditions[0] = 0U;
    expected_Dem_GaaAllFDC[0] = 0;

    START_TEST("220: Dem_ResetEventDebounceStatusMultiEventTriggering",
               "created to solve true case of DEM_DEBOUNCE_STATUS_RESET  == DebounceResetStatus at line number 11500");

        /* Expected Call Sequence  */
        EXPECTED_CALLS("SuspendAllInterrupts#6;ResumeAllInterrupts#7;SuspendAllInterrupts#6;ResumeAllInterrupts#7");

            /* Call SUT */
            returnValue = Dem_ResetEventDebounceStatusMultiEventTriggering(LusEventParameterIndex, DebounceResetStatus);

            /* Test case checks */
            CHECK_U_CHAR(returnValue, 0U);
            /* Checks on global data */
            check_global_data();
        END_CALLS();
    END_TEST();
}}}

/*****************************************************************************/
/* Call Interface Control                                                    */
/*****************************************************************************/

/* Stub for function SuspendAllInterrupts */
void SuspendAllInterrupts(){
    REGISTER_CALL("SuspendAllInterrupts");

    IF_INSTANCE("1") {
        return;
    }
    IF_INSTANCE("2") {
        Dem_GaaSuppressionStatus[0] = 85U;
        return;
    }
    IF_INSTANCE("3") {
        Dem_GaaSuppressionStatus[0] = 0U;
        return;
    }
    IF_INSTANCE("4") {
        Dem_GaaSuppressionStatus[0] = 85U;
        return;
    }
    IF_INSTANCE("5") {
        return;
    }
    IF_INSTANCE("6") {
        return;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Stub for function ResumeAllInterrupts */
void ResumeAllInterrupts(){
    REGISTER_CALL("ResumeAllInterrupts");

    IF_INSTANCE("1") {
        return;
    }
    IF_INSTANCE("2") {
        Dem_GaaEventParameter[0].pDTCAttribute = &map_ResumeAllInterrupts_call1_Dem_GaaEventParameter_0_pDTCAttribute[0];
        Dem_GaaEventToDTCIndexMapping[0] = 0U;
        Dem_GaaRecordNumber[0] = 85U;
        map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
        map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 85U;
        map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].aaEdData[0][0] = 85U;
        return;
    }
    IF_INSTANCE("3") {
        Dem_GaaEventParameter[0].pDTCAttribute = &map_ResumeAllInterrupts_call2_Dem_GaaEventParameter_0_pDTCAttribute[0];
        Dem_GaaDtcInfo[0].aaCombinedEvents[0] = 0U;
        Dem_GaaDtcInfo[0].aaCombinedEvents[1] = 0U;
        Dem_GaaDtcInfo[0].aaCombinedEvents[2] = 0U;
        Dem_GaaDtcInfo[0].ddDtcFormat[0] = 85U;
        Dem_GaaDtcInfo[0].ddDtcFormat[1] = 85U;
        Dem_GaaDtcInfo[0].ddDtcFormat[2] = 85U;
        Dem_GaaDtcInfo[0].ddDtcFormat[3] = 85U;
        Dem_GaaDTCFormat[0] = 0U;
        map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 255U;
        return;
    }
    IF_INSTANCE("4") {
        Dem_GaaEventToDTCIndexMapping[0] = 0U;
        Dem_GaaReadinessGroup[0] = 255U;
        map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ddEventId = 1U;
        map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 85U;
        return;
    }
    IF_INSTANCE("5") {
        map_Dem_GaaDTCOriginBasedPtrAddress_0_pEventMemory[85].ucPreviousIndex = 255U;
        return;
    }
    IF_INSTANCE("6") {
        return;
    }
    IF_INSTANCE("7") {
        return;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Stub for function Dem_ClearMasterEventPrestoreBuffer */
void Dem_ClearMasterEventPrestoreBuffer(Dem_EventIdType EventId){
    REGISTER_CALL("Dem_ClearMasterEventPrestoreBuffer");

    IF_INSTANCE("1") {
        CHECK_U_INT(EventId, 0U);
        return;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Stub for function Det_ReportRuntimeError */
Std_ReturnType Det_ReportRuntimeError(uint16 ModuleId,
                                      uint8 InstanceId,
                                      uint8 ApiId,
                                      uint8 ErrorId){
    Std_ReturnType returnValue;
    REGISTER_CALL("Det_ReportRuntimeError");

    IF_INSTANCE("1") {
        returnValue = 0U;
        CHECK_U_INT(ModuleId, 54U);
        CHECK_U_CHAR(InstanceId, 0U);
        CHECK_U_CHAR(ApiId, 85U);
        CHECK_U_CHAR(ErrorId, 48U);
        return returnValue;
    }
    IF_INSTANCE("2") {
        returnValue = 0U;
        CHECK_U_INT(ModuleId, 54U);
        CHECK_U_CHAR(InstanceId, 0U);
        CHECK_U_CHAR(ApiId, 109U);
        CHECK_U_CHAR(ErrorId, 48U);
        return returnValue;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return returnValue;
}

/* Stub for function Dem_GetDidData */
Std_ReturnType Dem_GetDidData(const Dem_EventMemory * LpEventMemory,
                              uint8 * DestBuffer,
                              uint8 LucMemoryIndex,
                              uint16 DataId,
                              uint8 RecordIndex){
    Std_ReturnType returnValue;
    REGISTER_CALL("Dem_GetDidData");

    IF_INSTANCE("1") {
        returnValue = 85U;
        CHECK_ADDRESS(LpEventMemory, &map_LpEventMemory_5[0]);
        CHECK_U_INT(LpEventMemory[0].ddEventId, 0U);
        CHECK_U_CHAR(LpEventMemory[0].ucNumOfFF, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucOccuranceCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucAgingCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucPreviousIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucNextEventIdIndex, 85U);
        CHECK_U_INT(LpEventMemory[85].ddEventId, 0U);
        CHECK_U_CHAR(LpEventMemory[85].ucNumOfFF, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucOccuranceCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucAgingCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucPreviousIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucNextEventIdIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[85].aaFFRecNumAndData[0][0], 85U);
        CHECK_U_CHAR(LpEventMemory[85].aaFFRecNumAndData[0][1], 85);
        CHECK_U_CHAR(LpEventMemory[85].aaFFRecNumAndData[0][2], 85);
        CHECK_ADDRESS(DestBuffer, NULL);
        CHECK_U_CHAR(LucMemoryIndex, 85U);
        CHECK_U_INT(DataId, 0U);
        CHECK_U_CHAR(RecordIndex, 0U);
        return returnValue;
    }
    IF_INSTANCE("2") {
        returnValue = 1U;
        CHECK_ADDRESS(LpEventMemory, &map_LpEventMemory_5[0]);
        CHECK_U_INT(LpEventMemory[0].ddEventId, 0U);
        CHECK_U_CHAR(LpEventMemory[0].ucNumOfFF, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucOccuranceCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucAgingCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucPreviousIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucNextEventIdIndex, 85U);
        CHECK_U_INT(LpEventMemory[85].ddEventId, 0U);
        CHECK_U_CHAR(LpEventMemory[85].ucNumOfFF, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucOccuranceCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucAgingCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucPreviousIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucNextEventIdIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[85].aaFFRecNumAndData[0][0], 85U);
        CHECK_U_CHAR(LpEventMemory[85].aaFFRecNumAndData[0][1], 85);
        CHECK_U_CHAR(LpEventMemory[85].aaFFRecNumAndData[0][2], 85);
        CHECK_ADDRESS(DestBuffer, NULL);
        CHECK_U_CHAR(LucMemoryIndex, 85U);
        CHECK_U_INT(DataId, 0U);
        CHECK_U_CHAR(RecordIndex, 0U);
        return returnValue;
    }
    IF_INSTANCE("3") {
        returnValue = 85U;
        CHECK_ADDRESS(LpEventMemory, &map_LpEventMemory_5[0]);
        CHECK_U_INT(LpEventMemory[0].ddEventId, 0U);
        CHECK_U_CHAR(LpEventMemory[0].ucNumOfFF, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucOccuranceCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucAgingCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucPreviousIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucNextEventIdIndex, 85U);
        CHECK_U_INT(LpEventMemory[85].ddEventId, 0U);
        CHECK_U_CHAR(LpEventMemory[85].ucNumOfFF, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucOccuranceCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucAgingCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucPreviousIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucNextEventIdIndex, 85U);
        CHECK_ADDRESS(DestBuffer, NULL);
        CHECK_U_CHAR(LucMemoryIndex, 85U);
        CHECK_U_INT(DataId, 0U);
        CHECK_U_CHAR(RecordIndex, 84U);
        return returnValue;
    }
    IF_INSTANCE("4") {
        returnValue = 1U;
        CHECK_ADDRESS(LpEventMemory, &map_LpEventMemory_5[0]);
        CHECK_U_INT(LpEventMemory[0].ddEventId, 0U);
        CHECK_U_CHAR(LpEventMemory[0].ucNumOfFF, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucOccuranceCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucAgingCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucPreviousIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucNextEventIdIndex, 85U);
        CHECK_U_INT(LpEventMemory[85].ddEventId, 0U);
        CHECK_U_CHAR(LpEventMemory[85].ucNumOfFF, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucOccuranceCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucAgingCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucPreviousIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucNextEventIdIndex, 85U);
        CHECK_ADDRESS(DestBuffer, NULL);
        CHECK_U_CHAR(LucMemoryIndex, 85U);
        CHECK_U_INT(DataId, 0U);
        CHECK_U_CHAR(RecordIndex, 84U);
        return returnValue;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return returnValue;
}

/* Stub for function Det_ReportError */
Std_ReturnType Det_ReportError(uint16 ModuleId,
                               uint8 InstanceId,
                               uint8 ApiId,
                               uint8 ErrorId){
    Std_ReturnType returnValue;
    REGISTER_CALL("Det_ReportError");

    IF_INSTANCE("1") {
        returnValue = 0U;
        CHECK_U_INT(ModuleId, 54U);
        CHECK_U_CHAR(InstanceId, 0U);
        CHECK_U_CHAR(ApiId, 29U);
        CHECK_U_CHAR(ErrorId, 19U);
        return returnValue;
    }
    IF_INSTANCE("2") {
        returnValue = 0U;
        CHECK_U_INT(ModuleId, 54U);
        CHECK_U_CHAR(InstanceId, 0U);
        CHECK_U_CHAR(ApiId, 32U);
        CHECK_U_CHAR(ErrorId, 19U);
        return returnValue;
    }
    IF_INSTANCE("3") {
        returnValue = 0U;
        CHECK_U_INT(ModuleId, 54U);
        CHECK_U_CHAR(InstanceId, 0U);
        CHECK_U_CHAR(ApiId, 19U);
//        CHECK_U_CHAR(ErrorId, 16U);
        return returnValue;
    }
    IF_INSTANCE("4") {
        returnValue = 0U;
        CHECK_U_INT(ModuleId, 54U);
        CHECK_U_CHAR(InstanceId, 0U);
        CHECK_U_CHAR(ApiId, 19U);
        CHECK_U_CHAR(ErrorId, 18U);
        return returnValue;
    }
    IF_INSTANCE("5") {
        returnValue = 0U;
        CHECK_U_INT(ModuleId, 54U);
        CHECK_U_CHAR(InstanceId, 0U);
        CHECK_U_CHAR(ApiId, 35U);
        CHECK_U_CHAR(ErrorId, 16U);
        return returnValue;
    }
    IF_INSTANCE("6") {
        returnValue = 0U;
        CHECK_U_INT(ModuleId, 54U);
        CHECK_U_CHAR(InstanceId, 0U);
        CHECK_U_CHAR(ApiId, 85U);
        CHECK_U_CHAR(ErrorId, 16U);
        return returnValue;
    }
    IF_INSTANCE("7") {
        returnValue = 0U;
        CHECK_U_INT(ModuleId, 54U);
        CHECK_U_CHAR(InstanceId, 0U);
        CHECK_U_CHAR(ApiId, 109U);
        CHECK_U_CHAR(ErrorId, 18U);
        return returnValue;
    }
    IF_INSTANCE("8") {
        returnValue = 0U;
        CHECK_U_INT(ModuleId, 54U);
        CHECK_U_CHAR(InstanceId, 0U);
        CHECK_U_CHAR(ApiId, 109U);
        CHECK_U_CHAR(ErrorId, 19U);
        return returnValue;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return returnValue;
}

/* Stub for function Dem_ClearAllEvents */
Std_ReturnType Dem_ClearAllEvents(){
    Std_ReturnType returnValue;
    REGISTER_CALL("Dem_ClearAllEvents");

    IF_INSTANCE("1") {
        returnValue = 85U;
        return returnValue;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return returnValue;
}

/* Stub for function GetSpinLock */
StatusType GetSpinlock(SpinlockIdType SpinlockId){
    REGISTER_CALL("GetSpinlock");

    IF_INSTANCE("1") {
        return;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Stub for function ReleaseSpinLock */
StatusType ReleaseSpinlock(SpinlockIdType SpinlockId){
    REGISTER_CALL("ReleaseSpinlock");

    IF_INSTANCE("1") {
        return;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Stub for function Dem_ClearGroupEvents */
Std_ReturnType Dem_ClearGroupEvents(const uint16 * LpEventIndexs,
                                    uint16 LusNumOfEvts){
    Std_ReturnType returnValue;
    REGISTER_CALL("Dem_ClearGroupEvents");

    IF_INSTANCE("1") {
        returnValue = 85U;
        CHECK_U_INT(LusNumOfEvts, 0U);
        return returnValue;
    }
    IF_INSTANCE("2") {
        returnValue = 85U;
        CHECK_U_INT(LpEventIndexs[0], 0U);
        CHECK_U_INT(LusNumOfEvts, 1U);
        return returnValue;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return returnValue;
}

/* Stub for function Dem_RearrangeOldEvtsInd */
void Dem_RearrangeOldEvtsInd(uint8 LucCurOldEvtInd,
                             uint8 LucNumberOfEntries,
                             Dem_EventMemory * LpOldEvtCnt){
    REGISTER_CALL("Dem_RearrangeOldEvtsInd");

    IF_INSTANCE("1") {
        CHECK_U_CHAR(LucCurOldEvtInd, 85U);
        CHECK_U_CHAR(LucNumberOfEntries, 85U);
        CHECK_ADDRESS(LpOldEvtCnt, &map_LpEventMemory_10[0]);
        return;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Stub for function Dem_ClearRecordTriggers */
void Dem_ClearRecordTriggers(Dem_EventIdType EventIndex){
    REGISTER_CALL("Dem_ClearRecordTriggers");

    IF_INSTANCE("1") {
        CHECK_U_INT(EventIndex, 0U);
        return;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Stub for function Dem_GetFFDidData */
Std_ReturnType Dem_GetFFDidData(const Dem_EventMemory * LpEventMemory,
                                uint8 * DestBuffer,
                                uint8 LucMemoryIndex,
                                uint16 DataId,
                                uint8 RecordIndex,
                                uint16 * BufSize){
    Std_ReturnType returnValue;
    REGISTER_CALL("Dem_GetFFDidData");

    IF_INSTANCE("1") {
        returnValue = 85U;
        CHECK_ADDRESS(LpEventMemory, &map_LpEventMemory_12[0]);
        CHECK_U_INT(LpEventMemory[0].ddEventId, 0U);
        CHECK_U_CHAR(LpEventMemory[0].ucNumOfFF, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucOccuranceCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucAgingCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucPreviousIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucNextEventIdIndex, 85U);
        CHECK_U_INT(LpEventMemory[85].ddEventId, 0U);
        CHECK_U_CHAR(LpEventMemory[85].ucNumOfFF, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucOccuranceCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucAgingCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucPreviousIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucNextEventIdIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[85].aaFFRecNumAndData[0][0], 85U);
        CHECK_U_CHAR(LpEventMemory[85].aaFFRecNumAndData[0][1], 85);
        CHECK_U_CHAR(LpEventMemory[85].aaFFRecNumAndData[0][2], 85);
        CHECK_ADDRESS(DestBuffer, NULL);
        CHECK_U_CHAR(LucMemoryIndex, 85U);
        CHECK_U_INT(DataId, 0U);
        CHECK_U_CHAR(RecordIndex, 0U);
        CHECK_ADDRESS(BufSize, NULL);
        return returnValue;
    }
    IF_INSTANCE("2") {
        returnValue = 1U;
        CHECK_ADDRESS(LpEventMemory, &map_LpEventMemory_12[0]);
        CHECK_U_INT(LpEventMemory[0].ddEventId, 0U);
        CHECK_U_CHAR(LpEventMemory[0].ucNumOfFF, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucOccuranceCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucAgingCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucPreviousIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucNextEventIdIndex, 85U);
        CHECK_U_INT(LpEventMemory[85].ddEventId, 0U);
        CHECK_U_CHAR(LpEventMemory[85].ucNumOfFF, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucOccuranceCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucAgingCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucPreviousIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucNextEventIdIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[85].aaFFRecNumAndData[0][0], 85U);
        CHECK_U_CHAR(LpEventMemory[85].aaFFRecNumAndData[0][1], 85);
        CHECK_U_CHAR(LpEventMemory[85].aaFFRecNumAndData[0][2], 85);
        CHECK_ADDRESS(DestBuffer, NULL);
        CHECK_U_CHAR(LucMemoryIndex, 85U);
        CHECK_U_INT(DataId, 0U);
        CHECK_U_CHAR(RecordIndex, 0U);
        CHECK_ADDRESS(BufSize, NULL);
        return returnValue;
    }
    IF_INSTANCE("3") {
        returnValue = 85U;
        CHECK_ADDRESS(LpEventMemory, &map_LpEventMemory_12[0]);
        CHECK_U_INT(LpEventMemory[0].ddEventId, 0U);
        CHECK_U_CHAR(LpEventMemory[0].ucNumOfFF, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucOccuranceCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucAgingCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucPreviousIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucNextEventIdIndex, 85U);
        CHECK_U_INT(LpEventMemory[85].ddEventId, 0U);
        CHECK_U_CHAR(LpEventMemory[85].ucNumOfFF, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucOccuranceCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucAgingCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucPreviousIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucNextEventIdIndex, 85U);
        CHECK_ADDRESS(DestBuffer, NULL);
        CHECK_U_CHAR(LucMemoryIndex, 85U);
        CHECK_U_INT(DataId, 0U);
        CHECK_U_CHAR(RecordIndex, 84U);
        CHECK_ADDRESS(BufSize, NULL);
        return returnValue;
    }
    IF_INSTANCE("4") {
        returnValue = 1U;
        CHECK_ADDRESS(LpEventMemory, &map_LpEventMemory_12[0]);
        CHECK_U_INT(LpEventMemory[0].ddEventId, 0U);
        CHECK_U_CHAR(LpEventMemory[0].ucNumOfFF, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucOccuranceCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucAgingCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucPreviousIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[0].ucNextEventIdIndex, 85U);
        CHECK_U_INT(LpEventMemory[85].ddEventId, 0U);
        CHECK_U_CHAR(LpEventMemory[85].ucNumOfFF, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucOccuranceCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucAgingCounter, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucPreviousIndex, 85U);
        CHECK_U_CHAR(LpEventMemory[85].ucNextEventIdIndex, 85U);
        CHECK_ADDRESS(DestBuffer, NULL);
        CHECK_U_CHAR(LucMemoryIndex, 85U);
        CHECK_U_INT(DataId, 0U);
        CHECK_U_CHAR(RecordIndex, 84U);
        CHECK_ADDRESS(BufSize, NULL);
        return returnValue;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return returnValue;
}

#pragma qas cantata ignore on

/* Before-Wrapper for function Dem_EventSearchInMemory */
int BEFORE_Dem_EventSearchInMemory(Dem_EventIdType EventParameterIndex,
                                   uint8 * PMemMapIndx){
    REGISTER_CALL("Dem_EventSearchInMemory");

    IF_INSTANCE("1") {
        CHECK_U_INT(EventParameterIndex, 0U);
        return REPLACE_WRAPPER;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return AFTER_WRAPPER;
}

/* After-Wrapper for function Dem_EventSearchInMemory */
void AFTER_Dem_EventSearchInMemory(struct cppsm_void_return cppsm_dummy,
                                   Dem_EventIdType EventParameterIndex,
                                   uint8 * PMemMapIndx){

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Replace-Wrapper for function Dem_EventSearchInMemory */
void REPLACE_Dem_EventSearchInMemory(Dem_EventIdType EventParameterIndex,
                                     uint8 * PMemMapIndx){

    IF_INSTANCE("1") {
        *PMemMapIndx = 0U;
        return;
    }
    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Before-Wrapper for function Dem_InitNVData_Internal */
int BEFORE_Dem_InitNVData_Internal(){
    REGISTER_CALL("Dem_InitNVData_Internal");

    IF_INSTANCE("1") {
        return REPLACE_WRAPPER;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return AFTER_WRAPPER;
}

/* After-Wrapper for function Dem_InitNVData_Internal */
void AFTER_Dem_InitNVData_Internal(struct cppsm_void_return cppsm_dummy){

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Replace-Wrapper for function Dem_InitNVData_Internal */
void REPLACE_Dem_InitNVData_Internal(){

    IF_INSTANCE("1") {
        return;
    }
    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Before-Wrapper for function memset */
int BEFORE_memset(void * param_1,
                  int param_2,
                  size_t param_3){
    REGISTER_CALL("memset");

    IF_INSTANCE("1") {
        CHECK_ADDRESS(param_1, &Dem_GaaAllEvtStatus[0]);
        CHECK_U_CHAR(((uint8(*))param_1)[0], 85U);
        CHECK_U_CHAR(((uint8(*))param_1)[1], 85);
        CHECK_U_CHAR(((uint8(*))param_1)[2], 85);
        CHECK_U_CHAR(((uint8(*))param_1)[3], 85);
        CHECK_U_CHAR(((uint8(*))param_1)[4], 85);
        CHECK_U_CHAR(((uint8(*))param_1)[5], 85);
        CHECK_U_CHAR(((uint8(*))param_1)[6], 85);
        CHECK_U_CHAR(((uint8(*))param_1)[7], 85);
        CHECK_U_CHAR(((uint8(*))param_1)[8], 85);
        CHECK_U_CHAR(((uint8(*))param_1)[9], 85);
        CHECK_S_INT(param_2, 80);
        CHECK_U_INT(param_3, 10U);
        return REPLACE_WRAPPER;
    }
    IF_INSTANCE("2") {
//        CHECK_ADDRESS(param_1, &Dem_GaaAllDtcStatus[0]);
        CHECK_U_CHAR(((uint8(*))param_1)[0], 0);
        CHECK_U_CHAR(((uint8(*))param_1)[1], 0);
        CHECK_U_CHAR(((uint8(*))param_1)[2], 0);
        CHECK_U_CHAR(((uint8(*))param_1)[3], 0);
        CHECK_U_CHAR(((uint8(*))param_1)[4], 0);
        CHECK_U_CHAR(((uint8(*))param_1)[5], 0);
        CHECK_S_INT(param_2, 80);
        CHECK_U_INT(param_3, 10U);
        return REPLACE_WRAPPER;
    }
    IF_INSTANCE("3") {
//        CHECK_ADDRESS(param_1, &Dem_GaaAllFDC[0]);
        CHECK_S_CHAR(((sint8(*))param_1)[0], 85);
        CHECK_S_CHAR(((sint8(*))param_1)[1], 85);
        CHECK_S_CHAR(((sint8(*))param_1)[2], 85);
        CHECK_S_CHAR(((sint8(*))param_1)[3], 85);
        CHECK_S_CHAR(((sint8(*))param_1)[4], 85);
        CHECK_S_CHAR(((sint8(*))param_1)[5], 85);
//        CHECK_S_CHAR(((sint8(*))param_1)[6], 85);
//        CHECK_S_CHAR(((sint8(*))param_1)[7], 85);
        CHECK_S_CHAR(((sint8(*))param_1)[8], 85);
        CHECK_S_CHAR(((sint8(*))param_1)[9], 85);
        CHECK_S_INT(param_2, 80);
        CHECK_U_INT(param_3, 6U);
        return REPLACE_WRAPPER;
    }
    IF_INSTANCE("4") {
//        CHECK_ADDRESS(param_1, &Dem_GaaEventFailureCounter[0]);
        CHECK_U_CHAR(((uint8(*))param_1)[0], 85U);
        CHECK_U_CHAR(((uint8(*))param_1)[1], 85);
        CHECK_U_CHAR(((uint8(*))param_1)[2], 85);
        CHECK_U_CHAR(((uint8(*))param_1)[3], 85);
        CHECK_U_CHAR(((uint8(*))param_1)[4], 85);
        CHECK_U_CHAR(((uint8(*))param_1)[5], 85);
        CHECK_U_CHAR(((uint8(*))param_1)[6], 85);
        CHECK_U_CHAR(((uint8(*))param_1)[7], 85);
        CHECK_U_CHAR(((uint8(*))param_1)[8], 85);
        CHECK_U_CHAR(((uint8(*))param_1)[9], 85);
        CHECK_S_INT(param_2, 0);
        CHECK_U_INT(param_3, 10U);
        return REPLACE_WRAPPER;
    }
    IF_INSTANCE("5") {
//        CHECK_ADDRESS(param_1, &Dem_GaaOldEvtCntHeadTailIndex[0][0]);
        CHECK_U_CHAR(((uint8(*))param_1)[0], 85U);
        CHECK_U_CHAR(((uint8(*))param_1)[1], 85);
        CHECK_S_INT(param_2, 0);
        CHECK_U_INT(param_3, 10U);
        return REPLACE_WRAPPER;
    }
    IF_INSTANCE("6") {
//        CHECK_ADDRESS(param_1, &Dem_GaaDtcMainEvent[0]);
//        CHECK_U_INT(((uint16(*))param_1)[0], 0U);
        CHECK_U_INT(((uint16(*))param_1)[1], 0U);
        CHECK_U_INT(((uint16(*))param_1)[2], 0U);
        CHECK_U_INT(((uint16(*))param_1)[3], 0U);
        CHECK_U_INT(((uint16(*))param_1)[4], 0U);
        CHECK_U_INT(((uint16(*))param_1)[5], 0U);
        CHECK_S_INT(param_2, 255);
        CHECK_U_INT(param_3, 2U);
        return REPLACE_WRAPPER;
    }

    IF_INSTANCE("7") {
    //        CHECK_ADDRESS(param_1, &Dem_GaaAllDtcStatus[0]);
            CHECK_U_CHAR(((uint8(*))param_1)[0], 0);
            CHECK_U_CHAR(((uint8(*))param_1)[1], 0);
            CHECK_U_CHAR(((uint8(*))param_1)[2], 0);
            CHECK_U_CHAR(((uint8(*))param_1)[3], 0);
            CHECK_U_CHAR(((uint8(*))param_1)[4], 0);
            CHECK_U_CHAR(((uint8(*))param_1)[5], 0);
//            CHECK_S_INT(param_2, 80);
//            CHECK_U_INT(param_3, 10U);
            return REPLACE_WRAPPER;
        }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return AFTER_WRAPPER;
}

/* After-Wrapper for function memset */
void * AFTER_memset(void * cppsm_return_value,
                    void * param_1,
                    int param_2,
                    size_t param_3){
    void * returnValue;

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return cppsm_return_value;
}

/* Replace-Wrapper for function memset */
void * REPLACE_memset(void * param_1,
                      int param_2,
                      size_t param_3){
    void * returnValue;

    IF_INSTANCE("1") {
        ((uint8(*))param_1)[0] = 85U;
        return;
    }
    IF_INSTANCE("2") {
        ((uint8(*))param_1)[0] = 85U;
        return;
    }
    IF_INSTANCE("3") {
        ((sint8(*))param_1)[0] = 85;
        return;
    }
    IF_INSTANCE("4") {
        ((uint8(*))param_1)[0] = 85U;
        return;
    }
    IF_INSTANCE("5") {
        return;
    }
    IF_INSTANCE("6") {
        ((uint16(*))param_1)[0] = 0U;
        return;
    }
    IF_INSTANCE("7") {
            ((uint16(*))param_1)[0] = 0U;
            return;
        }
    LOG_SCRIPT_ERROR("Call instance not defined.");
    return returnValue;
}

/* Before-Wrapper for function memcpy */
int BEFORE_memcpy(void * param_1,
                  const void * param_2,
                  size_t param_3){
    REGISTER_CALL("memcpy");

    IF_INSTANCE("1") {

        return REPLACE_WRAPPER;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return AFTER_WRAPPER;
}

/* After-Wrapper for function memcpy */
void * AFTER_memcpy(void * cppsm_return_value,
                    void * param_1,
                    const void * param_2,
                    size_t param_3){
    void * returnValue;

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return cppsm_return_value;
}

/* Replace-Wrapper for function memcpy */
void * REPLACE_memcpy(void * param_1,
                      const void * param_2,
                      size_t param_3){
    void * returnValue;

    IF_INSTANCE("1") {
        ((boolean(*))param_1)[0] = 85U;
        return;
    }
    LOG_SCRIPT_ERROR("Call instance not defined.");
    return returnValue;
}

/* Before-Wrapper for function Dem_DTCFilterSearch */
int BEFORE_Dem_DTCFilterSearch(uint16 LusDtcInfoIndex,
                               uint16 LusDTCOrgin,
                               uint8 LucClientId){
    REGISTER_CALL("Dem_DTCFilterSearch");

    IF_INSTANCE("1") {
        CHECK_U_INT(LusDtcInfoIndex, 2U);
        CHECK_U_INT(LusDTCOrgin, 0U);
        CHECK_U_CHAR(LucClientId, 0U);
        return REPLACE_WRAPPER;
    }
    IF_INSTANCE("2") {
        CHECK_U_INT(LusDtcInfoIndex, 3U);
        CHECK_U_INT(LusDTCOrgin, 0U);
        CHECK_U_CHAR(LucClientId, 0U);
        return REPLACE_WRAPPER;
    }
    IF_INSTANCE("3") {
        CHECK_U_INT(LusDtcInfoIndex, 5U);
        CHECK_U_INT(LusDTCOrgin, 0U);
        CHECK_U_CHAR(LucClientId, 0U);
        return REPLACE_WRAPPER;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return AFTER_WRAPPER;
}

/* After-Wrapper for function Dem_DTCFilterSearch */
Std_ReturnType AFTER_Dem_DTCFilterSearch(Std_ReturnType cppsm_return_value,
                                         uint16 LusDtcInfoIndex,
                                         uint16 LusDTCOrgin,
                                         uint8 LucClientId){
    Std_ReturnType returnValue;

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return cppsm_return_value;
}

/* Replace-Wrapper for function Dem_DTCFilterSearch */
Std_ReturnType REPLACE_Dem_DTCFilterSearch(uint16 LusDtcInfoIndex,
                                           uint16 LusDTCOrgin,
                                           uint8 LucClientId){
    Std_ReturnType returnValue;

    IF_INSTANCE("1") {
        returnValue = 85U;
        return returnValue;
    }
    IF_INSTANCE("2") {
        returnValue = 85U;
        return returnValue;
    }
    IF_INSTANCE("3") {
        returnValue = 0U;
        return returnValue;
    }
    LOG_SCRIPT_ERROR("Call instance not defined.");
    return returnValue;
}

/* Before-Wrapper for function Dem_SearchDtc */
int BEFORE_Dem_SearchDtc(uint16 LusDtcInfoIndex,
                         uint16 * LpEventParameterIndex){
    REGISTER_CALL("Dem_SearchDtc");

    IF_INSTANCE("1") {
        CHECK_U_INT(LusDtcInfoIndex, 0U);
        CHECK_U_INT(*LpEventParameterIndex, 0U);
        return REPLACE_WRAPPER;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return AFTER_WRAPPER;
}

/* After-Wrapper for function Dem_SearchDtc */
void AFTER_Dem_SearchDtc(struct cppsm_void_return cppsm_dummy,
                         uint16 LusDtcInfoIndex,
                         uint16 * LpEventParameterIndex){

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Replace-Wrapper for function Dem_SearchDtc */
void REPLACE_Dem_SearchDtc(uint16 LusDtcInfoIndex,
                           uint16 * LpEventParameterIndex){

    IF_INSTANCE("1") {
        *LpEventParameterIndex = 0U;
        return;
    }
    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Before-Wrapper for function Dem_FilterEvent */
int BEFORE_Dem_FilterEvent(uint16 LusEventIndex,
                           uint8 LucClientId){
    REGISTER_CALL("Dem_FilterEvent");

    IF_INSTANCE("1") {
        CHECK_U_INT(LusEventIndex, 65535U);
        CHECK_U_CHAR(LucClientId, 0U);
        return REPLACE_WRAPPER;
    }
    IF_INSTANCE("2") {
        CHECK_U_INT(LusEventIndex, 0U);
        CHECK_U_CHAR(LucClientId, 0U);
        return REPLACE_WRAPPER;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return AFTER_WRAPPER;
}

/* After-Wrapper for function Dem_FilterEvent */
Std_ReturnType AFTER_Dem_FilterEvent(Std_ReturnType cppsm_return_value,
                                     uint16 LusEventIndex,
                                     uint8 LucClientId){
    Std_ReturnType returnValue;

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return cppsm_return_value;
}

/* Replace-Wrapper for function Dem_FilterEvent */
Std_ReturnType REPLACE_Dem_FilterEvent(uint16 LusEventIndex,
                                       uint8 LucClientId){
    Std_ReturnType returnValue;

    IF_INSTANCE("1") {
        returnValue = 85U;
        return returnValue;
    }
    IF_INSTANCE("2") {
        returnValue = 0U;
        return returnValue;
    }
    LOG_SCRIPT_ERROR("Call instance not defined.");
    return returnValue;
}

/* Before-Wrapper for function Dem_DtcAttrSearchInMemory */
int BEFORE_Dem_DtcAttrSearchInMemory(const Dem_DTCAttributeType * LpDTCAttribute,
                                     uint8 * PMemMapIndx){
    REGISTER_CALL("Dem_DtcAttrSearchInMemory");

    IF_INSTANCE("1") {
        CHECK_ADDRESS(LpDTCAttribute, &map_LpDTCAttribute_2[0]);
        return REPLACE_WRAPPER;
    }
    IF_INSTANCE("2") {
        CHECK_ADDRESS(LpDTCAttribute, &map_Dem_GaaEventParameter_0_pDTCAttribute[0]);
        return REPLACE_WRAPPER;
    }
    IF_INSTANCE("3") {
        CHECK_ADDRESS(LpDTCAttribute, NULL);
        return REPLACE_WRAPPER;
    }
    IF_INSTANCE("4") {
        CHECK_ADDRESS(LpDTCAttribute, &map_Dem_GaaEventParameter_0_pDTCAttribute[0]);
        return REPLACE_WRAPPER;
    }
    IF_INSTANCE("5") {
        CHECK_ADDRESS(LpDTCAttribute, &map_LpDTCAttribute_4[0]);
        return REPLACE_WRAPPER;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return AFTER_WRAPPER;
}

/* After-Wrapper for function Dem_DtcAttrSearchInMemory */
void AFTER_Dem_DtcAttrSearchInMemory(struct cppsm_void_return cppsm_dummy,
                                     const Dem_DTCAttributeType * LpDTCAttribute,
                                     uint8 * PMemMapIndx){

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Replace-Wrapper for function Dem_DtcAttrSearchInMemory */
void REPLACE_Dem_DtcAttrSearchInMemory(const Dem_DTCAttributeType * LpDTCAttribute,
                                       uint8 * PMemMapIndx){

    IF_INSTANCE("1") {
        *PMemMapIndx = 0U;
        return;
    }
    IF_INSTANCE("2") {
        *PMemMapIndx = 0U;
        return;
    }
    IF_INSTANCE("3") {
        *PMemMapIndx = 85U;
        return;
    }
    IF_INSTANCE("4") {
        *PMemMapIndx = 0U;
        Dem_GaaEventParameter[0].pDTCAttribute = &map_Dem_DtcAttrSearchInMemory_call1_Dem_GaaEventParameter_0_pDTCAttribute[0];
        Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[0] = 0U;
        Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[1] = 0U;
        Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[2] = 0U;
        Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[3] = 0U;
        Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[4] = 0U;
        Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[5] = 0U;
        Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[6] = 0U;
        Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[7] = 0U;
        Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[8] = 0U;
        Dem_GaaDTCOriginBasedPtrAddress[0].aaEventIndexInMemory[9] = 0U;
        Dem_GaaDTCOriginBasedPtrAddress[0].ucFfRecordEnumType = 85U;
        map_LpEventMemory_7[85].aaFFRecNumAndData[0][0] = 0U;
        map_LpEventMemory_7[85].aaFFRecNumAndData[0][1] = 85U;
        map_LpEventMemory_7[85].aaFFRecNumAndData[0][2] = 85U;
        return;
    }
    IF_INSTANCE("5") {
        *PMemMapIndx = 0U;
        return;
    }
    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Before-Wrapper for function Dem_ProcessDataElementSize */
int BEFORE_Dem_ProcessDataElementSize(uint16 LusDataIndex,
                                      uint8 LucDataElementType,
                                      uint8 * LpSize){
    REGISTER_CALL("Dem_ProcessDataElementSize");

    IF_INSTANCE("1") {
        CHECK_U_INT(LusDataIndex, 85U);
        CHECK_U_CHAR(LucDataElementType, 85U);
        CHECK_U_CHAR(*LpSize, 0U);
        return REPLACE_WRAPPER;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return AFTER_WRAPPER;
}

/* After-Wrapper for function Dem_ProcessDataElementSize */
Std_ReturnType AFTER_Dem_ProcessDataElementSize(Std_ReturnType cppsm_return_value,
                                                uint16 LusDataIndex,
                                                uint8 LucDataElementType,
                                                uint8 * LpSize){
    Std_ReturnType returnValue;

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return cppsm_return_value;
}

/* Replace-Wrapper for function Dem_ProcessDataElementSize */
Std_ReturnType REPLACE_Dem_ProcessDataElementSize(uint16 LusDataIndex,
                                                  uint8 LucDataElementType,
                                                  uint8 * LpSize){
    Std_ReturnType returnValue;

    IF_INSTANCE("1") {
        returnValue = 85U;
        *LpSize = 1U;
        return returnValue;
    }
    LOG_SCRIPT_ERROR("Call instance not defined.");
    return returnValue;
}

/* Before-Wrapper for function Dem_GetSizeOfRecNoFFandFE */
int BEFORE_Dem_GetSizeOfRecNoFFandFE(uint16 LusEventParameterIndex,
                                     uint16 * LpSizeOfExtendedDataRecord,
                                     uint8 ExtendedDataNumber,
                                     const Dem_EventMemory * LpEventMemory){
    REGISTER_CALL("Dem_GetSizeOfRecNoFFandFE");

    IF_INSTANCE("1") {
        CHECK_U_INT(LusEventParameterIndex, 0U);
        CHECK_U_INT(*LpSizeOfExtendedDataRecord, 0U);
        CHECK_U_CHAR(ExtendedDataNumber, 254U);
//        CHECK_ADDRESS(LpEventMemory, (const Dem_EventMemory*) 1190UL);
        return REPLACE_WRAPPER;
    }
    IF_INSTANCE("2") {
        CHECK_U_INT(LusEventParameterIndex, 0U);
        CHECK_U_INT(*LpSizeOfExtendedDataRecord, 0U);
        CHECK_U_CHAR(ExtendedDataNumber, 255U);
//        CHECK_ADDRESS(LpEventMemory, (const Dem_EventMemory*) 1190UL);
        return REPLACE_WRAPPER;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return AFTER_WRAPPER;
}

/* After-Wrapper for function Dem_GetSizeOfRecNoFFandFE */
void AFTER_Dem_GetSizeOfRecNoFFandFE(struct cppsm_void_return cppsm_dummy,
                                     uint16 LusEventParameterIndex,
                                     uint16 * LpSizeOfExtendedDataRecord,
                                     uint8 ExtendedDataNumber,
                                     const Dem_EventMemory * LpEventMemory){

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Replace-Wrapper for function Dem_GetSizeOfRecNoFFandFE */
void REPLACE_Dem_GetSizeOfRecNoFFandFE(uint16 LusEventParameterIndex,
                                       uint16 * LpSizeOfExtendedDataRecord,
                                       uint8 ExtendedDataNumber,
                                       const Dem_EventMemory * LpEventMemory){

    IF_INSTANCE("1") {
        *LpSizeOfExtendedDataRecord = 0U;
        return;
    }
    IF_INSTANCE("2") {
        *LpSizeOfExtendedDataRecord = 0U;
        return;
    }
    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Before-Wrapper for function Dem_ProcessClearSingleDTC */
int BEFORE_Dem_ProcessClearSingleDTC(){
    REGISTER_CALL("Dem_ProcessClearSingleDTC");

    IF_INSTANCE("1") {
        return REPLACE_WRAPPER;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return AFTER_WRAPPER;
}

/* After-Wrapper for function Dem_ProcessClearSingleDTC */
Std_ReturnType AFTER_Dem_ProcessClearSingleDTC(Std_ReturnType cppsm_return_value){
    Std_ReturnType returnValue;

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return cppsm_return_value;
}

/* Replace-Wrapper for function Dem_ProcessClearSingleDTC */
Std_ReturnType REPLACE_Dem_ProcessClearSingleDTC(){
    Std_ReturnType returnValue;

    IF_INSTANCE("1") {
        returnValue = 85U;
        return returnValue;
    }
    LOG_SCRIPT_ERROR("Call instance not defined.");
    return returnValue;
}

/* Before-Wrapper for function Dem_DtcStatusChange */
void Dem_DtcStatusChange(const Dem_DTCAttributeType * LpDTCAttribute,
                               uint16 LusEventParameterIndex){
    REGISTER_CALL("Dem_DtcStatusChange");

    IF_INSTANCE("default") {
        return AFTER_WRAPPER;
    }
    IF_INSTANCE("1") {
//        CHECK_ADDRESS(LpDTCAttribute, (const Dem_DTCAttributeType*) 1UL);
        CHECK_U_INT(LusEventParameterIndex, 0U);
        return REPLACE_WRAPPER;
    }
    IF_INSTANCE("2") {
        //CHECK_ADDRESS(LpDTCAttribute, (const Dem_DTCAttributeType*) 1UL);
        CHECK_U_INT(LusEventParameterIndex, 0U);
        return;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return AFTER_WRAPPER;
}



/* Before-Wrapper for function Dem_GetSizeOfEDRecordForEvent */
int BEFORE_Dem_GetSizeOfEDRecordForEvent(uint8 LucFreeIndex,
                                         uint16 * LpBufSize,
                                         uint8 ExtendedDataNumber,
                                         const Dem_EventMemory * LpEventMemory){
    REGISTER_CALL("Dem_GetSizeOfEDRecordForEvent");

    IF_INSTANCE("1") {
        CHECK_U_CHAR(LucFreeIndex, 85U);
        CHECK_U_INT(*LpBufSize, 0U);
        CHECK_U_CHAR(ExtendedDataNumber, 85U);
        CHECK_ADDRESS(LpEventMemory, NULL);
        return REPLACE_WRAPPER;
    }
    IF_INSTANCE("2") {
        CHECK_U_CHAR(LucFreeIndex, 85U);
        CHECK_U_INT(*LpBufSize, 0U);
        CHECK_U_CHAR(ExtendedDataNumber, 85U);
        CHECK_ADDRESS(LpEventMemory, NULL);
        return REPLACE_WRAPPER;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return AFTER_WRAPPER;
}

/* After-Wrapper for function Dem_GetSizeOfEDRecordForEvent */
void AFTER_Dem_GetSizeOfEDRecordForEvent(struct cppsm_void_return cppsm_dummy,
                                         uint8 LucFreeIndex,
                                         uint16 * LpBufSize,
                                         uint8 ExtendedDataNumber,
                                         const Dem_EventMemory * LpEventMemory){

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Replace-Wrapper for function Dem_GetSizeOfEDRecordForEvent */
void REPLACE_Dem_GetSizeOfEDRecordForEvent(uint8 LucFreeIndex,
                                           uint16 * LpBufSize,
                                           uint8 ExtendedDataNumber,
                                           const Dem_EventMemory * LpEventMemory){

    IF_INSTANCE("1") {
        *LpBufSize = 0U;
        return;
    }
    IF_INSTANCE("2") {
        *LpBufSize = 1U;
        return;
    }
    LOG_SCRIPT_ERROR("Call instance not defined.");
    return;
}

/* Before-Wrapper for function Dem_CheckExtendedDataRecord */
int BEFORE_Dem_CheckExtendedDataRecord(uint8 RecordNumber,
                                       uint8 LucServiceId,
                                       uint8 * DestBuffer,
                                       uint16 * BufSize,
                                       const Dem_EventMemory * LpEventMemory,
                                       const Dem_DTCAttributeType * LpDTCAttribute,
                                       uint8 LucFreeIndex,
                                       uint8 LucNumOfEDRecords,
                                       boolean * LblRecFound){
    REGISTER_CALL("Dem_CheckExtendedDataRecord");

    IF_INSTANCE("1") {
        CHECK_U_CHAR(RecordNumber, 85U);
        CHECK_U_CHAR(LucServiceId, 109U);
        CHECK_ADDRESS(DestBuffer, NULL);
        CHECK_ADDRESS(BufSize, &map_BufSize_2[0]);
        CHECK_U_INT(*BufSize, 0U);
        CHECK_ADDRESS(LpEventMemory, NULL);
        CHECK_ADDRESS(LpDTCAttribute, &map_Dem_GaaEventParameter_0_pDTCAttribute[0]);
        CHECK_ADDRESS((*LpDTCAttribute).pAgingCycle, NULL);
        CHECK_ADDRESS((*LpDTCAttribute).pEventMemorySet, NULL);
        CHECK_U_INT((*LpDTCAttribute).usFFRecordRawDataSize, 0U);
        CHECK_U_CHAR((*LpDTCAttribute).DTCPriority, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).usAgingCycleCounterThreshold, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).usAgingCycleCounterThresholdTFSLC, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).ucNumOfEDRecords, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).aaExtendedDataRecords[0], 85);
        CHECK_U_CHAR((*LpDTCAttribute).ucNumofEDTfRecords, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).aaEDBitPositionTF[0], 85);
        CHECK_U_CHAR((*LpDTCAttribute).ucNumOfFFRecNum, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).aaFreezeFrameRecords[0], 85);
//        CHECK_U_CHAR((*LpDTCAttribute).ucNumofFFTfRecords, 85U);
//        CHECK_U_CHAR((*LpDTCAttribute).aaFFBitPositionTF[0], 85);
        CHECK_U_CHAR((*LpDTCAttribute).ucNumOfDataId, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).aaDataIdArray[0], 85);
        CHECK_U_CHAR((*LpDTCAttribute).ucMaxNumOfFFRecord, 85U);
//        CHECK_U_CHAR((*LpDTCAttribute).ucNoOfDestinationSelected, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).ucEventDestination, 0U);
        CHECK_U_CHAR((*LpDTCAttribute).ucMemoryMappingIndex, 85);
        CHECK_U_CHAR((*LpDTCAttribute).ucEdRecordClassIndex, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).ucFFClassIndex, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).ucClientId, 85U);
//        CHECK_U_CHAR((*LpDTCAttribute).blAgingAllowed, 85U);
//        CHECK_U_CHAR((*LpDTCAttribute).blDemImmediateNvStorage, 85U);
        CHECK_U_CHAR(LucFreeIndex, 85U);
        CHECK_U_CHAR(LucNumOfEDRecords, 85U);
        CHECK_U_CHAR(*LblRecFound, 0U);
        return REPLACE_WRAPPER;
    }
    IF_INSTANCE("2") {
        CHECK_U_CHAR(RecordNumber, 85U);
        CHECK_U_CHAR(LucServiceId, 109U);
        CHECK_ADDRESS(DestBuffer, NULL);
        CHECK_ADDRESS(BufSize, &map_BufSize_2[0]);
        CHECK_U_INT(*BufSize, 0U);
        CHECK_ADDRESS(LpEventMemory, NULL);
        CHECK_ADDRESS(LpDTCAttribute, &map_Dem_GaaEventParameter_0_pDTCAttribute[0]);
        CHECK_ADDRESS((*LpDTCAttribute).pAgingCycle, NULL);
        CHECK_ADDRESS((*LpDTCAttribute).pEventMemorySet, NULL);
        CHECK_U_INT((*LpDTCAttribute).usFFRecordRawDataSize, 0U);
        CHECK_U_CHAR((*LpDTCAttribute).DTCPriority, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).usAgingCycleCounterThreshold, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).usAgingCycleCounterThresholdTFSLC, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).ucNumOfEDRecords, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).aaExtendedDataRecords[0], 85);
        CHECK_U_CHAR((*LpDTCAttribute).ucNumofEDTfRecords, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).aaEDBitPositionTF[0], 85);
        CHECK_U_CHAR((*LpDTCAttribute).ucNumOfFFRecNum, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).aaFreezeFrameRecords[0], 85);
//        CHECK_U_CHAR((*LpDTCAttribute).ucNumofFFTfRecords, 85U);
//        CHECK_U_CHAR((*LpDTCAttribute).aaFFBitPositionTF[0], 85);
        CHECK_U_CHAR((*LpDTCAttribute).ucNumOfDataId, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).aaDataIdArray[0], 85);
        CHECK_U_CHAR((*LpDTCAttribute).ucMaxNumOfFFRecord, 85U);
//        CHECK_U_CHAR((*LpDTCAttribute).ucNoOfDestinationSelected, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).ucEventDestination, 0U);
        CHECK_U_CHAR((*LpDTCAttribute).ucMemoryMappingIndex, 85);
        CHECK_U_CHAR((*LpDTCAttribute).ucEdRecordClassIndex, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).ucFFClassIndex, 85U);
        CHECK_U_CHAR((*LpDTCAttribute).ucClientId, 85U);
//        CHECK_U_CHAR((*LpDTCAttribute).blAgingAllowed, 85U);
//        CHECK_U_CHAR((*LpDTCAttribute).blDemImmediateNvStorage, 85U);
        CHECK_U_CHAR(LucFreeIndex, 85U);
        CHECK_U_CHAR(LucNumOfEDRecords, 85U);
        CHECK_U_CHAR(*LblRecFound, 0U);
        return REPLACE_WRAPPER;
    }

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return AFTER_WRAPPER;
}

/* After-Wrapper for function Dem_CheckExtendedDataRecord */
Std_ReturnType AFTER_Dem_CheckExtendedDataRecord(Std_ReturnType cppsm_return_value,
                                                 uint8 RecordNumber,
                                                 uint8 LucServiceId,
                                                 uint8 * DestBuffer,
                                                 uint16 * BufSize,
                                                 const Dem_EventMemory * LpEventMemory,
                                                 const Dem_DTCAttributeType * LpDTCAttribute,
                                                 uint8 LucFreeIndex,
                                                 uint8 LucNumOfEDRecords,
                                                 boolean * LblRecFound){
    Std_ReturnType returnValue;

    LOG_SCRIPT_ERROR("Call instance not defined.");
    return cppsm_return_value;
}

/* Replace-Wrapper for function Dem_CheckExtendedDataRecord */
Std_ReturnType REPLACE_Dem_CheckExtendedDataRecord(uint8 RecordNumber,
                                                   uint8 LucServiceId,
                                                   uint8 * DestBuffer,
                                                   uint16 * BufSize,
                                                   const Dem_EventMemory * LpEventMemory,
                                                   const Dem_DTCAttributeType * LpDTCAttribute,
                                                   uint8 LucFreeIndex,
                                                   uint8 LucNumOfEDRecords,
                                                   boolean * LblRecFound){
    Std_ReturnType returnValue;

    IF_INSTANCE("1") {
        returnValue = 0U;
        *BufSize = 0U;
        *LblRecFound = 85U;
        return returnValue;
    }
    IF_INSTANCE("2") {
        returnValue = 85U;
        *BufSize = 0U;
        *LblRecFound = 1U;
        return returnValue;
    }
    LOG_SCRIPT_ERROR("Call instance not defined.");
    return returnValue;
}

#pragma qas cantata ignore off

/* Isolate for calls via function pointers with return type Std_ReturnType */
/* and parameter type sint8 * */
Std_ReturnType ISOLATE_Std_ReturnType_func_ptr_sint8_p(sint8 * FaultDetectionCounter){
    Std_ReturnType returnValue;
    REGISTER_CALL("ISOLATE_Std_ReturnType_func_ptr_sint8_p");


    LOG_SCRIPT_ERROR("Call instance not defined.");
    return returnValue;
}

/* pragma qas cantata testscript end */
/*****************************************************************************/
/* End of test script                                                        */
/*****************************************************************************/
