#ifndef _GLOBLE_FUNCTION_H
#define _GLOBLE_FUNCTION_H

#pragma region For_Bacnet
#include "CM5/ud_str.h"
#include "Bacnet_Include.h"
#include "T3000RegAddress.h"
#include "msflexgrid1.h"

#pragma endregion For_Bacnet


#include "global_variable_extern.h"
#define FLEXGRID_CELL_COLOR RGB(128,128,128) 
#define GREEN_COLOR RGB(0,255,0)
#define YELLOW_COLOR RGB(255,255,0)
#define ORANGE_COLOR RGB(255,165,0)

#include "global_variable_extern.h"

void FLEX_GRID_PUT_STR(CMsflexgrid m_FlexGri,int row,int col,CString str);
int Set_Communication_Count(bool b_transmission,int bac_instanceid);
int modbus_read_one_value( 
				int& value, 
				unsigned char device_var,
				unsigned short address, 
				int retry_times );

int modbus_read_multi_value( 
		unsigned short *put_data_into_here,
		unsigned char device_var,
		unsigned short start_address,
		int length,
		int retry_times );

int read_one(unsigned char device_var,unsigned short address,int retry_times=3);
int write_one(unsigned char device_var,unsigned short address,short value,int retry_times=3);
int Write_Multi(unsigned char device_var,unsigned char *to_write,unsigned short start_address,int length,int retry_times=3);
int Write_Multi_short(unsigned char device_var,unsigned short *to_write,unsigned short start_address,int length,int retry_times=3);
int Read_Multi(unsigned char device_var,unsigned short *put_data_into_here,unsigned short start_address,int length,int retry_times=3);
int write_one_org(unsigned char device_var,unsigned short address,short value,int retry_times=3);
int Write_Multi_org(unsigned char device_var,unsigned char *to_write,unsigned short start_address,int length,int retry_times=3);
int Write_Multi_org_short(unsigned char device_var,unsigned short *to_write,unsigned short start_address,int length,int retry_times=3);
int turn_hex_str_to_ten_num(char *str);
bool turn_hex_file_line_to_unsigned_char(char *str);
int turn_hex_char_to_int(char c);
void turn_int_to_unsigned_char(char *source,int length_source,unsigned char *aim);

float get_tstat_version(unsigned short tstat_id);

float get_curtstat_version();

int make_sure_isp_mode(int the_tstat_id);
bool get_serialnumber(long & serial,int the_id_of_product=-1);
bool multi_read_tstat(int id);

//
void SetPaneString(int nIndext,CString str);

UINT get_serialnumber();
bool can_be_writed_hex_file(int product_model,int hex_file_product_model);
CString get_product_name_by_product_model(int product_model);

//CString GetTempUnit(int analog1_or_analog2=-1);
CString GetTempUnit(int nRange=-1,int nPIDNO = 0);
CString get_product_class_name_by_model_ID(int nModelID);

extern int Read_One_t(unsigned char device_var,unsigned short address, int slot);
extern int Write_One_t(unsigned char device_var, unsigned short address, unsigned short val, int slot);
extern int read_multi_t(unsigned char device_var,unsigned short *put_data_into_here,unsigned short start_address,int length, int slot);
extern int write_multi_t(unsigned char device_var,unsigned char *to_write,unsigned short start_address,int length, int slot);


BOOL GetSerialComPortNumber1(vector<CString>& szComm);

BOOL Post_Thread_Message(UINT MsgType,
	unsigned char device_id,
	unsigned short address,
	short new_value,
	short old_value,
	HWND Dlg_hwnd,
	UINT CTRL_ID,
	CString Changed_Name);


BOOL Post_Read_one_Thread_Message(
	unsigned char device_id,
	unsigned short address,
	HWND Dlg_hwnd);

BOOL Post_Invoke_ID_Monitor_Thread(UINT MsgType,
	int Invoke_ID,
	HWND hwnd,
	CString Show_Detail = _T(""),
	int nRow = 0,
	int nCol = 0
	);
BOOL Post_Refresh_One_Message(uint32_t deviceid,int8_t command,int8_t start_instance,int8_t end_instance,unsigned short entitysize);
BOOL Post_Refresh_Message(uint32_t deviceid,int8_t command,int8_t start_instance,int8_t end_instance,unsigned short entitysize,int block_size);
BOOL Post_Write_Message(uint32_t deviceid,int8_t command,int8_t start_instance,int8_t end_instance,unsigned short entitysize,HWND hWnd,CString Task_Info = _T(""),int nRow = 0,int nCol = 0);
int GetPrivateData(uint32_t deviceid,int8_t command,int8_t start_instance,int8_t end_instance,int16_t entitysize);
int GetMonitorBlockData(uint32_t deviceid,int8_t command,int8_t index,int8_t ntype,int8_t nspecial,MonitorUpdateData* up_data);
int WritePrivateData(uint32_t deviceid,int8_t command,int8_t start_instance,int8_t end_instance/*,int8_t entitysize*/ );

int CM5ProcessPTA(	BACNET_PRIVATE_TRANSFER_DATA * data);
void local_handler_conf_private_trans_ack(
	uint8_t * service_request,
	uint16_t service_len,
	BACNET_ADDRESS * src,
	BACNET_CONFIRMED_SERVICE_ACK_DATA * service_data);

void LocalIAmHandler(	uint8_t * service_request,	uint16_t service_len,	BACNET_ADDRESS * src);

void SplitCStringA(CStringArray &saArray, CString sSource, CString sToken);
char * intervaltotext(char *textbuf, long seconds , unsigned minutes , unsigned hours, char *c =":");
char * intervaltotextfull(char *textbuf, long seconds , unsigned minutes , unsigned hours,char *c =":");
 DWORD WINAPI   MSTP_Receive(LPVOID lpVoid);
 void Localhandler_read_property_ack(
	 uint8_t * service_request,
	 uint16_t service_len,
	 BACNET_ADDRESS * src,
	 BACNET_CONFIRMED_SERVICE_ACK_DATA * service_data);
  void local_rp_ack_print_data(	BACNET_READ_PROPERTY_DATA * data);
 void Initial_bac(int comport = 1);
  bool Open_bacnetSocket2(CString strIPAdress,short nPort,SOCKET &mysocket);
  unsigned char Str_to_Byte(CString need_conver);
  void Init_Service_Handlers(void);
CString GetProductName(int ModelID);

CString Get_Table_Name(int SerialNo,CString Type ,int Row);
void    Insert_Update_Table_Name(int SerialNo,CString Type,int Row,CString TableName); 
int Get_Unit_Process(CString Unit);
BOOL Get_Bit_FromRegister(unsigned short RegisterValue,unsigned short Position);
#endif