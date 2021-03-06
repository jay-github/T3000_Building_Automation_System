   /*  define.h */
#ifndef COMMON_H
#define COMMON_H

#include "define.h"

OUTPUT int Write_One(TS_UC device_var,TS_US address,TS_US value);
OUTPUT int Read_One(TS_UC device_var,TS_US address);
OUTPUT int write_multi(TS_UC device_var,TS_UC *to_write,TS_US start_address,int length);
OUTPUT int read_multi(TS_UC device_var,TS_US *put_data_into_here,TS_US start_address,int length);
//OUTPUT bool open_com(TS_UC m_com);
OUTPUT bool open_com(int m_com);
OUTPUT void close_com();
OUTPUT bool is_connect();
OUTPUT int CheckTstatOnline(TS_UC devLo=1,TS_UC devHi=254);
OUTPUT bool Change_BaudRate(TS_US new_baudrate);
OUTPUT bool SetComm_Timeouts(LPCOMMTIMEOUTS lpCommTimeouts);
OUTPUT int CheckTstatOnline2(TS_UC devLo,TS_UC devHi);


//Socket
OUTPUT bool Open_Socket(CString strIPAdress);
OUTPUT void SetCommunicationType(int nType);
OUTPUT bool Open_Socket2(CString strIPAdress,short nPort);

//for scan network controller
OUTPUT int NetController_CheckTstatOnline(TS_UC devLo=1,TS_UC devHi=254);
OUTPUT int NetController_CheckTstatOnline2(TS_UC devLo,TS_UC devHi);

//read multible bytes to check is there more than one tstates have the same id. 

OUTPUT HANDLE GetCommunicationHandle();
OUTPUT BOOL bTCPDisconnected();
OUTPUT void SetComnicationHandle(int nType,HANDLE hCommunication);


//////////////////////////////////////////////////////////////////////////
OUTPUT int NetController_CheckTstatOnline_a(TS_UC devLo,TS_UC devHi, bool bComm_Type);
OUTPUT int NetController_CheckTstatOnline2_a(TS_UC devLo,TS_UC devHi, bool bComm_Type);
OUTPUT int CheckTstatOnline_a(TS_UC devLo,TS_UC devHi, bool bComm_Type);
OUTPUT int CheckTstatOnline2_a(TS_UC devLo,TS_UC devHi, bool bComm_Type);

OUTPUT int Read_One2(TS_UC device_var,TS_US address, bool bComm_Type);
OUTPUT int Write_One2(TS_UC device_var,TS_US address,TS_US value, bool bComm_Type);
//OUTPUT int write_multi(TS_UC device_var,TS_UC *to_write,TS_US start_address,int length);
OUTPUT int read_multi2(TS_UC device_var,TS_US *put_data_into_here,TS_US start_address,int length, bool bComm_Type);

CStdioFile*					m_pFile;
CString						m_strFileINI;

OUTPUT void closefile();
OUTPUT void writefile(CString strip,CString strport);
OUTPUT void Createfile();


#ifndef _DEBUG
void SaveBufferToLogFile(TS_UC* pBuffer, int nSize);
#endif




#endif
