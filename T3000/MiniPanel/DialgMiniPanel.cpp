// DialgMiniPanel.cpp : implementation file
//

#include "stdafx.h"
#include "DialgMiniPanel.h"
#include "../globle_function.h"
#include "../T3000.h"

static BOOL ifminidb = TRUE;
CString AINPUT_Range[6]={_T("RAW DATA"),_T("10KC"),_T("10KF"),_T("0-100%"),_T("ON/OFF"),_T("OFF/ON")};
CString SWITCH_DA[3]={_T("OFF"),_T("HAND"),_T("AUTO")};
// CDialgMiniPanel

IMPLEMENT_DYNCREATE(CDialgMiniPanel, CFormView)


CDialgMiniPanel::CDialgMiniPanel()
	: CFormView(CDialgMiniPanel::IDD)
	, m_inaddress(0)
	, m_inSerialNum(0)
	, m_flFirmware(0)
	, m_inHardware(0)
	, m_CStrModel(_T(""))
	, m_inBaudrate(0)
	, m_datetime(_T(""))
	, m_nListenPort(_T(""))
{

}

CDialgMiniPanel::~CDialgMiniPanel()
{
}

void CDialgMiniPanel::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MSFLEXGRID_INPUT, m_msflexgridinput);
	DDX_Control(pDX, IDC_MSFLEXGRID_OUTPUT_DO, m_msflexgridDO);
	DDX_Control(pDX, IDC_MSFLEXGRID_OUTPUT_AO, m_msflexgridAO);
	DDX_Text(pDX, IDC_EDIT1, m_inaddress);
	DDX_Text(pDX, IDC_EDIT3, m_inSerialNum);
	DDX_Text(pDX, IDC_EDIT2, m_flFirmware);
	DDX_Text(pDX, IDC_EDIT4, m_inHardware);
	DDX_Text(pDX, IDC_EDIT5, m_CStrModel);
	DDX_Text(pDX, IDC_EDIT6, m_inBaudrate);
	DDX_Text(pDX, IDC_STATIC1, m_datetime);
	DDX_Text(pDX, IDC_STATIC1, m_datetime);
	DDX_Control(pDX, IDC_EDIT_INPUT, m_editinput);
	DDX_Control(pDX, IDC_EDITOUTPUTDO, m_editoutputdo);
	DDX_Control(pDX, IDC_EDIT_OUTPUTAO, m_editoutputao);
	DDX_Control(pDX, IDC_IPMODEL_COMBO, m_ipModelComBox);

	DDX_Text(pDX, IDC_EDIT8, m_nListenPort);
	DDX_Control(pDX, IDC_MAC_ADDRESS, m_Mac_Address);
	DDX_Control(pDX, IDC_IPADDRESS1, m_ip_addressCtrl);
	DDX_Control(pDX, IDC_IPADDRESS2, m_subnet_addressCtrl);
	DDX_Control(pDX, IDC_IPADDRESS3, m_gateway_addressCtrl);
	DDX_Control(pDX, IDC_ADDBUILDING_MSFLEXGRID, m_Output_GridCM5_);
	DDX_Control(pDX, IDC_COMBO_RANGE, m_combox_range);
	DDX_Control(pDX, IDC_PROGRESS, m_prgoressctrl);
}

BEGIN_MESSAGE_MAP(CDialgMiniPanel, CFormView)
	ON_WM_TIMER()
	ON_EN_KILLFOCUS(IDC_EDIT_INPUT, &CDialgMiniPanel::OnEnKillfocusEditInput)
	ON_EN_KILLFOCUS(IDC_EDITOUTPUTDO, &CDialgMiniPanel::OnEnKillfocusEditoutputdo)
	ON_EN_KILLFOCUS(IDC_EDIT_OUTPUTAO, &CDialgMiniPanel::OnEnKillfocusEditOutputao)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialgMiniPanel::OnBnClickedButtonSyncwithpc)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialgMiniPanel::OnBnClickedButtonweeklyschedule)
	ON_BN_CLICKED(IDC_BUTTON3, &CDialgMiniPanel::OnBnClickedButtonannualschedule)
	ON_BN_CLICKED(IDC_BUTTON4, &CDialgMiniPanel::OnBnClickedButtonidschedule)
	ON_BN_CLICKED(IDC_BUTTON9, &CDialgMiniPanel::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_REFRESH_ALL, &CDialgMiniPanel::OnBnClickedButtonRefreshAll)
	ON_CBN_SELCHANGE(IDC_COMBO_RANGE, &CDialgMiniPanel::OnCbnSelchangeRange)

END_MESSAGE_MAP()


// CDialgMiniPanel diagnostics

#ifdef _DEBUG
void CDialgMiniPanel::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDialgMiniPanel::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

int  CDialgMiniPanel::Get_RegID(CString Name)
{
	Name.TrimLeft();
	Name.TrimRight();
	int regid=-1;
	vector<T3Register>::iterator iter;
	for (iter=m_vecT3Register.begin();iter!=m_vecT3Register.end();iter++)
	{
		if (iter->regName==Name)
		{
			regid=iter->regID;
			break;
		}
	}
	return regid;
}
void CDialgMiniPanel::Initial_RegisterList(){
#if 1
	SN_LOW	=	0	;

	SN_HI	=	2	;

	FIRMWARE_VER_NUMBER_0	=	4	;
	FIRMWARE_VER_NUMBER_1	=	5	;
	MODBUS_ID	=	6	;
	PRODUCT_MODEL	=	7	;
	HARDWARE_VER_NUMBER	=	8	;
	BAUDRATE	=	9	;
	CALIBRATION	=	10	;
	PLUG_N_PLAY	=	13	;
	VER_ISP	=	14	;

	UPDATE_STATUS	=	16	;
	PROTOCAL_TYPE	=	17	;
	DIGITAL_OUTPUT1	=	100	;
	DIGITAL_OUTPUT2	=	101	;
	DIGITAL_OUTPUT3	=	102	;
	DIGITAL_OUTPUT4	=	103	;
	DIGITAL_OUTPUT5	=	104	;
	DIGITAL_OUTPUT6	=	105	;
	DIGITAL_OUTPUT7	=	106	;
	DIGITAL_OUTPUT8	=	107	;
	DIGITAL_OUTPUT9	=	108	;
	DIGITAL_OUTPUT10	=	109	;
	DIGITAL_OUTPUT11	=	110	;
	DIGITAL_OUTPUT12	=	111	;
	ANALOG_OUTPUT1	=	112	;
	ANALOG_OUTPUT2	=	113	;
	ANALOG_OUTPUT3	=	114	;
	ANALOG_OUTPUT4	=	115	;
	ANALOG_OUTPUT5	=	116	;
	ANALOG_OUTPUT6	=	117	;
	ANALOG_OUTPUT7	=	118	;
	ANALOG_OUTPUT8	=	119	;
	ANALOG_OUTPUT9	=	120	;
	ANALOG_OUTPUT10	=	121	;
	ANALOG_OUTPUT11	=	122	;
	ANALOG_OUTPUT12	=	123	;
	SWITCH_STATUS1	=	124	;
	SWITCH_STATUS2	=	125	;
	SWITCH_STATUS3	=	126	;
	SWITCH_STATUS4	=	127	;
	SWITCH_STATUS5	=	128	;
	SWITCH_STATUS6	=	129	;
	SWITCH_STATUS7	=	130	;
	SWITCH_STATUS8	=	131	;
	SWITCH_STATUS9	=	132	;
	SWITCH_STATUS10	=	133	;
	SWITCH_STATUS11	=	134	;
	SWITCH_STATUS12	=	135	;
	SWITCH_STATUS13	=	136	;
	SWITCH_STATUS14	=	137	;
	SWITCH_STATUS15	=	138	;
	SWITCH_STATUS16	=	139	;
	SWITCH_STATUS17	=	140	;
	SWITCH_STATUS18	=	141	;
	SWITCH_STATUS19	=	142	;
	SWITCH_STATUS20	=	143	;
	SWITCH_STATUS21	=	144	;
	SWITCH_STATUS22	=	145	;
	SWITCH_STATUS23	=	146	;
	SWITCH_STATUS24	=	147	;
	INPUT1	=	148	;
	INPUT2	=	149	;
	INPUT3	=	150	;
	INPUT4	=	151	;
	INPUT5	=	152	;
	INPUT6	=	153	;
	INPUT7	=	154	;
	INPUT8	=	155	;
	INPUT9	=	156	;
	INPUT10	=	157	;
	INPUT11	=	158	;
	INPUT12	=	159	;
	INPUT13	=	160	;
	INPUT14	=	161	;
	INPUT15	=	162	;
	INPUT16	=	163	;
	INPUT17	=	164	;
	INPUT18	=	165	;
	INPUT19	=	166	;
	INPUT20	=	167	;
	INPUT21	=	168	;
	INPUT22	=	169	;
	INPUT23	=	170	;
	INPUT24	=	171	;
	INPUT25	=	172	;
	INPUT26	=	173	;
	INPUT27	=	174	;
	INPUT28	=	175	;
	INPUT29	=	176	;
	INPUT30	=	177	;
	INPUT31	=	178	;
	INPUT32	=	179	;
	LOW_VOLTAGE	=	180	;
	INPUT_UNIT1	=	181	;
	INPUT_UNIT2	=	182	;
	INPUT_UNIT3	=	183	;
	INPUT_UNIT4	=	184	;
	INPUT_UNIT5	=	185	;
	INPUT_UNIT6	=	186	;
	INPUT_UNIT7	=	187	;
	INPUT_UNIT8	=	188	;
	INPUT_UNIT9	=	189	;
	INPUT_UNIT10	=	190	;
	INPUT_UNIT11	=	191	;
	INPUT_UNIT12	=	192	;
	INPUT_UNIT13	=	193	;
	INPUT_UNIT14	=	194	;
	INPUT_UNIT15	=	195	;
	INPUT_UNIT16	=	196	;
	INPUT_UNIT17	=	197	;
	INPUT_UNIT18	=	198	;
	INPUT_UNIT19	=	199	;
	INPUT_UNIT20	=	200	;
	INPUT_UNIT21	=	201	;
	INPUT_UNIT22	=	202	;
	INPUT_UNIT23	=	203	;
	INPUT_UNIT24	=	204	;
	INPUT_UNIT25	=	205	;
	INPUT_UNIT26	=	206	;
	INPUT_UNIT27	=	207	;
	INPUT_UNIT28	=	208	;
	INPUT_UNIT29	=	209	;
	INPUT_UNIT30	=	210	;
	INPUT_UNIT31	=	211	;
	INPUT_UNIT32	=	212	;
	LOW_VOLTAGE_UNIT	=	213	;
	HIGHER_BYTE_YEAR	=	300	;
	LOWER_BYTE_YEAR	=	301	;
	MONTH	=	302	;
	WEEK	=	303	;
	DAY	=	304	;
	HOUR	=	305	;
	MINUTE	=	306	;
	SECOND	=	307	;
	WEEKLY_ROUTINE_620	=	308	;
	ANNUAL_ROUTINE_464	=	928	;
	ID_SCHEDULE_762	=	1392	;
	ANNUAL_ROUTINE_TIME_736	=	2154	;
	WEEKLY_ROUTINE_ONTIME_1440	=	2890	;
	WEEKLY_ROUTINE_OFFTIME_1440	=	4330	;
	TSTAT_OCCUPIEDSTATUS_SUBTSTATS	=	5670	;
	TSTAT_COOLINGSETPOINT_SUBTSTATS	=	5671	;
	TSTAT_HEATINGSETPOINT_SUBTSTATS	=	5679	;
	TSTAT_SETPOINT_SUBTSTATS	=	5687	;
	TSTAT_TEMPERATURE_SUBTSTATS	=	5695	;
	TSTAT_MODE_SUBTSTATS	=	5703	;
	TSTAT_OUTPUTSTATE_SUBTSTATS	=	5711	;
	TSTAT_NIGHT_HEATTINGDB_SUBTSTATS	=	5719	;
	TSTAT_NIGHT_COOLINGDB_SUBTSTATS	=	5727	;
	TSTAT_NIGHT_HEATTINGSETPOINT_SUBTSTATS	=	5735	;
	TSTAT_NIGHT_COOLINGSETPOINT_SUBTSTATS	=	5743	;
	TSTAT_PRODUCTMODEL_SUBTSTATS	=	5751	;
	TSTAT_OVERRIDE_SUBTSTATS	=	5759	;
	TSTAT_SERIALNO_SUBTSTATS	=	5767	;
	TSTAT_OFFTIME_SUBTSTATS	=	5800	;
	TSTAT_ONTIME_SUBTSTATS	=	6100	;
	TEST50	=	7000	;
	VALUEINPUT1TO34	=	8000	;
	RANGE_INPUT1TO32	=	8034	;
	FILTER_INPUT1TO32	=	8066	;
	CALIBRATION_INPUT1TO32	=	8098	;
	TOTAL_TSTAT0	=	8200	;
	TOTAL_TSTAT1	=	8201	;
	TOTAL_TSTAT2	=	8202	;
	TSTAT_ADD_BOTH_CHANNEL_UART0	=	8203	;
	TSTAT_ADD_BOTH_CHANNEL_UART1	=	8303	;
	TSTAT_ADD_BOTH_CHANNEL_UART2	=	8403	;
	
#endif
		T3Register temp;
		CADO m_ado;
		m_ado.OnInitADOConn();
#if 1
		CString SQL = _T("select * from MiniPanel_Registerlist");
		m_ado.m_pRecordset = m_ado.OpenRecordset(SQL);
		_variant_t vartemp;
		while(!m_ado.m_pRecordset->EndOfFile)
		{
			temp.regID=m_ado.m_pRecordset->GetCollect(_T("RegID"));
			vartemp =m_ado.m_pRecordset->GetCollect(_T("Reg_Name"));
			if (vartemp.vt==VT_NULL)
				temp.regName=_T("");
			else
				temp.regName =vartemp;
			m_ado.m_pRecordset->MoveNext();
			m_vecT3Register.push_back(temp);
		}
		m_ado.CloseRecordset();
		m_ado.CloseConn();
#endif 


#if 1
		SN_LOW	=	Get_RegID(_T("	SN_LOW	"))	;
	
		SN_HI	=	Get_RegID(_T("	SN_HI	"))	;
	
		FIRMWARE_VER_NUMBER_0	=	Get_RegID(_T("	FIRMWARE_VER_NUMBER_0	"))	;
		FIRMWARE_VER_NUMBER_1	=	Get_RegID(_T("	FIRMWARE_VER_NUMBER_1	"))	;
		MODBUS_ID	=	Get_RegID(_T("	MODBUS_ID	"))	;
		PRODUCT_MODEL	=	Get_RegID(_T("	PRODUCT_MODEL	"))	;
		HARDWARE_VER_NUMBER	=	Get_RegID(_T("	HARDWARE_VER_NUMBER	"))	;
		BAUDRATE	=	Get_RegID(_T("	BAUDRATE	"))	;
		CALIBRATION	=	Get_RegID(_T("	CALIBRATION	"))	;
		PLUG_N_PLAY	=	Get_RegID(_T("	PLUG_N_PLAY	"))	;
		VER_ISP	=	Get_RegID(_T("	VER_ISP	"))	;
	
		UPDATE_STATUS	=	Get_RegID(_T("	UPDATE_STATUS	"))	;
		PROTOCAL_TYPE	=	Get_RegID(_T("	PROTOCAL_TYPE	"))	;
		DIGITAL_OUTPUT1	=	Get_RegID(_T("	DIGITAL_OUTPUT1	"))	;
		DIGITAL_OUTPUT2	=	Get_RegID(_T("	DIGITAL_OUTPUT2	"))	;
		DIGITAL_OUTPUT3	=	Get_RegID(_T("	DIGITAL_OUTPUT3	"))	;
		DIGITAL_OUTPUT4	=	Get_RegID(_T("	DIGITAL_OUTPUT4	"))	;
		DIGITAL_OUTPUT5	=	Get_RegID(_T("	DIGITAL_OUTPUT5	"))	;
		DIGITAL_OUTPUT6	=	Get_RegID(_T("	DIGITAL_OUTPUT6	"))	;
		DIGITAL_OUTPUT7	=	Get_RegID(_T("	DIGITAL_OUTPUT7	"))	;
		DIGITAL_OUTPUT8	=	Get_RegID(_T("	DIGITAL_OUTPUT8	"))	;
		DIGITAL_OUTPUT9	=	Get_RegID(_T("	DIGITAL_OUTPUT9	"))	;
		DIGITAL_OUTPUT10	=	Get_RegID(_T("	DIGITAL_OUTPUT10	"))	;
		DIGITAL_OUTPUT11	=	Get_RegID(_T("	DIGITAL_OUTPUT11	"))	;
		DIGITAL_OUTPUT12	=	Get_RegID(_T("	DIGITAL_OUTPUT12	"))	;
		ANALOG_OUTPUT1	=	Get_RegID(_T("	ANALOG_OUTPUT1	"))	;
		ANALOG_OUTPUT2	=	Get_RegID(_T("	ANALOG_OUTPUT2	"))	;
		ANALOG_OUTPUT3	=	Get_RegID(_T("	ANALOG_OUTPUT3	"))	;
		ANALOG_OUTPUT4	=	Get_RegID(_T("	ANALOG_OUTPUT4	"))	;
		ANALOG_OUTPUT5	=	Get_RegID(_T("	ANALOG_OUTPUT5	"))	;
		ANALOG_OUTPUT6	=	Get_RegID(_T("	ANALOG_OUTPUT6	"))	;
		ANALOG_OUTPUT7	=	Get_RegID(_T("	ANALOG_OUTPUT7	"))	;
		ANALOG_OUTPUT8	=	Get_RegID(_T("	ANALOG_OUTPUT8	"))	;
		ANALOG_OUTPUT9	=	Get_RegID(_T("	ANALOG_OUTPUT9	"))	;
		ANALOG_OUTPUT10	=	Get_RegID(_T("	ANALOG_OUTPUT10	"))	;
		ANALOG_OUTPUT11	=	Get_RegID(_T("	ANALOG_OUTPUT11	"))	;
		ANALOG_OUTPUT12	=	Get_RegID(_T("	ANALOG_OUTPUT12	"))	;
		SWITCH_STATUS1	=	Get_RegID(_T("	SWITCH_STATUS1	"))	;
		SWITCH_STATUS2	=	Get_RegID(_T("	SWITCH_STATUS2	"))	;
		SWITCH_STATUS3	=	Get_RegID(_T("	SWITCH_STATUS3	"))	;
		SWITCH_STATUS4	=	Get_RegID(_T("	SWITCH_STATUS4	"))	;
		SWITCH_STATUS5	=	Get_RegID(_T("	SWITCH_STATUS5	"))	;
		SWITCH_STATUS6	=	Get_RegID(_T("	SWITCH_STATUS6	"))	;
		SWITCH_STATUS7	=	Get_RegID(_T("	SWITCH_STATUS7	"))	;
		SWITCH_STATUS8	=	Get_RegID(_T("	SWITCH_STATUS8	"))	;
		SWITCH_STATUS9	=	Get_RegID(_T("	SWITCH_STATUS9	"))	;
		SWITCH_STATUS10	=	Get_RegID(_T("	SWITCH_STATUS10	"))	;
		SWITCH_STATUS11	=	Get_RegID(_T("	SWITCH_STATUS11	"))	;
		SWITCH_STATUS12	=	Get_RegID(_T("	SWITCH_STATUS12	"))	;
		SWITCH_STATUS13	=	Get_RegID(_T("	SWITCH_STATUS13	"))	;
		SWITCH_STATUS14	=	Get_RegID(_T("	SWITCH_STATUS14	"))	;
		SWITCH_STATUS15	=	Get_RegID(_T("	SWITCH_STATUS15	"))	;
		SWITCH_STATUS16	=	Get_RegID(_T("	SWITCH_STATUS16	"))	;
		SWITCH_STATUS17	=	Get_RegID(_T("	SWITCH_STATUS17	"))	;
		SWITCH_STATUS18	=	Get_RegID(_T("	SWITCH_STATUS18	"))	;
		SWITCH_STATUS19	=	Get_RegID(_T("	SWITCH_STATUS19	"))	;
		SWITCH_STATUS20	=	Get_RegID(_T("	SWITCH_STATUS20	"))	;
		SWITCH_STATUS21	=	Get_RegID(_T("	SWITCH_STATUS21	"))	;
		SWITCH_STATUS22	=	Get_RegID(_T("	SWITCH_STATUS22	"))	;
		SWITCH_STATUS23	=	Get_RegID(_T("	SWITCH_STATUS23	"))	;
		SWITCH_STATUS24	=	Get_RegID(_T("	SWITCH_STATUS24	"))	;
		INPUT1	=	Get_RegID(_T("	INPUT1	"))	;
		INPUT2	=	Get_RegID(_T("	INPUT2	"))	;
		INPUT3	=	Get_RegID(_T("	INPUT3	"))	;
		INPUT4	=	Get_RegID(_T("	INPUT4	"))	;
		INPUT5	=	Get_RegID(_T("	INPUT5	"))	;
		INPUT6	=	Get_RegID(_T("	INPUT6	"))	;
		INPUT7	=	Get_RegID(_T("	INPUT7	"))	;
		INPUT8	=	Get_RegID(_T("	INPUT8	"))	;
		INPUT9	=	Get_RegID(_T("	INPUT9	"))	;
		INPUT10	=	Get_RegID(_T("	INPUT10	"))	;
		INPUT11	=	Get_RegID(_T("	INPUT11	"))	;
		INPUT12	=	Get_RegID(_T("	INPUT12	"))	;
		INPUT13	=	Get_RegID(_T("	INPUT13	"))	;
		INPUT14	=	Get_RegID(_T("	INPUT14	"))	;
		INPUT15	=	Get_RegID(_T("	INPUT15	"))	;
		INPUT16	=	Get_RegID(_T("	INPUT16	"))	;
		INPUT17	=	Get_RegID(_T("	INPUT17	"))	;
		INPUT18	=	Get_RegID(_T("	INPUT18	"))	;
		INPUT19	=	Get_RegID(_T("	INPUT19	"))	;
		INPUT20	=	Get_RegID(_T("	INPUT20	"))	;
		INPUT21	=	Get_RegID(_T("	INPUT21	"))	;
		INPUT22	=	Get_RegID(_T("	INPUT22	"))	;
		INPUT23	=	Get_RegID(_T("	INPUT23	"))	;
		INPUT24	=	Get_RegID(_T("	INPUT24	"))	;
		INPUT25	=	Get_RegID(_T("	INPUT25	"))	;
		INPUT26	=	Get_RegID(_T("	INPUT26	"))	;
		INPUT27	=	Get_RegID(_T("	INPUT27	"))	;
		INPUT28	=	Get_RegID(_T("	INPUT28	"))	;
		INPUT29	=	Get_RegID(_T("	INPUT29	"))	;
		INPUT30	=	Get_RegID(_T("	INPUT30	"))	;
		INPUT31	=	Get_RegID(_T("	INPUT31	"))	;
		INPUT32	=	Get_RegID(_T("	INPUT32	"))	;
		LOW_VOLTAGE	=	Get_RegID(_T("	LOW_VOLTAGE	"))	;
		INPUT_UNIT1	=	Get_RegID(_T("	INPUT_UNIT1	"))	;
		INPUT_UNIT2	=	Get_RegID(_T("	INPUT_UNIT2	"))	;
		INPUT_UNIT3	=	Get_RegID(_T("	INPUT_UNIT3	"))	;
		INPUT_UNIT4	=	Get_RegID(_T("	INPUT_UNIT4	"))	;
		INPUT_UNIT5	=	Get_RegID(_T("	INPUT_UNIT5	"))	;
		INPUT_UNIT6	=	Get_RegID(_T("	INPUT_UNIT6	"))	;
		INPUT_UNIT7	=	Get_RegID(_T("	INPUT_UNIT7	"))	;
		INPUT_UNIT8	=	Get_RegID(_T("	INPUT_UNIT8	"))	;
		INPUT_UNIT9	=	Get_RegID(_T("	INPUT_UNIT9	"))	;
		INPUT_UNIT10	=	Get_RegID(_T("	INPUT_UNIT10	"))	;
		INPUT_UNIT11	=	Get_RegID(_T("	INPUT_UNIT11	"))	;
		INPUT_UNIT12	=	Get_RegID(_T("	INPUT_UNIT12	"))	;
		INPUT_UNIT13	=	Get_RegID(_T("	INPUT_UNIT13	"))	;
		INPUT_UNIT14	=	Get_RegID(_T("	INPUT_UNIT14	"))	;
		INPUT_UNIT15	=	Get_RegID(_T("	INPUT_UNIT15	"))	;
		INPUT_UNIT16	=	Get_RegID(_T("	INPUT_UNIT16	"))	;
		INPUT_UNIT17	=	Get_RegID(_T("	INPUT_UNIT17	"))	;
		INPUT_UNIT18	=	Get_RegID(_T("	INPUT_UNIT18	"))	;
		INPUT_UNIT19	=	Get_RegID(_T("	INPUT_UNIT19	"))	;
		INPUT_UNIT20	=	Get_RegID(_T("	INPUT_UNIT20	"))	;
		INPUT_UNIT21	=	Get_RegID(_T("	INPUT_UNIT21	"))	;
		INPUT_UNIT22	=	Get_RegID(_T("	INPUT_UNIT22	"))	;
		INPUT_UNIT23	=	Get_RegID(_T("	INPUT_UNIT23	"))	;
		INPUT_UNIT24	=	Get_RegID(_T("	INPUT_UNIT24	"))	;
		INPUT_UNIT25	=	Get_RegID(_T("	INPUT_UNIT25	"))	;
		INPUT_UNIT26	=	Get_RegID(_T("	INPUT_UNIT26	"))	;
		INPUT_UNIT27	=	Get_RegID(_T("	INPUT_UNIT27	"))	;
		INPUT_UNIT28	=	Get_RegID(_T("	INPUT_UNIT28	"))	;
		INPUT_UNIT29	=	Get_RegID(_T("	INPUT_UNIT29	"))	;
		INPUT_UNIT30	=	Get_RegID(_T("	INPUT_UNIT30	"))	;
		INPUT_UNIT31	=	Get_RegID(_T("	INPUT_UNIT31	"))	;
		INPUT_UNIT32	=	Get_RegID(_T("	INPUT_UNIT32	"))	;
		LOW_VOLTAGE_UNIT	=	Get_RegID(_T("	LOW_VOLTAGE_UNIT	"))	;
		HIGHER_BYTE_YEAR	=	Get_RegID(_T("	HIGHER_BYTE_YEAR	"))	;
		LOWER_BYTE_YEAR	=	Get_RegID(_T("	LOWER_BYTE_YEAR	"))	;
		MONTH	=	Get_RegID(_T("	MONTH	"))	;
		WEEK	=	Get_RegID(_T("	WEEK	"))	;
		DAY	=	Get_RegID(_T("	DAY	"))	;
		HOUR	=	Get_RegID(_T("	HOUR	"))	;
		MINUTE	=	Get_RegID(_T("	MINUTE	"))	;
		SECOND	=	Get_RegID(_T("	SECOND	"))	;
		WEEKLY_ROUTINE_620	=	Get_RegID(_T("	WEEKLY_ROUTINE_620	"))	;
		ANNUAL_ROUTINE_464	=	Get_RegID(_T("	ANNUAL_ROUTINE_464	"))	;
		ID_SCHEDULE_762	=	Get_RegID(_T("	ID_SCHEDULE_762	"))	;
		ANNUAL_ROUTINE_TIME_736	=	Get_RegID(_T("	ANNUAL_ROUTINE_TIME_736	"))	;
		WEEKLY_ROUTINE_ONTIME_1440	=	Get_RegID(_T("	WEEKLY_ROUTINE_ONTIME_1440	"))	;
		WEEKLY_ROUTINE_OFFTIME_1440	=	Get_RegID(_T("	WEEKLY_ROUTINE_OFFTIME_1440	"))	;
		TSTAT_OCCUPIEDSTATUS_SUBTSTATS	=	Get_RegID(_T("	TSTAT_OCCUPIEDSTATUS_SUBTSTATS	"))	;
		TSTAT_COOLINGSETPOINT_SUBTSTATS	=	Get_RegID(_T("	TSTAT_COOLINGSETPOINT_SUBTSTATS	"))	;
		TSTAT_HEATINGSETPOINT_SUBTSTATS	=	Get_RegID(_T("	TSTAT_HEATINGSETPOINT_SUBTSTATS	"))	;
		TSTAT_SETPOINT_SUBTSTATS	=	Get_RegID(_T("	TSTAT_SETPOINT_SUBTSTATS	"))	;
		TSTAT_TEMPERATURE_SUBTSTATS	=	Get_RegID(_T("	TSTAT_TEMPERATURE_SUBTSTATS	"))	;
		TSTAT_MODE_SUBTSTATS	=	Get_RegID(_T("	TSTAT_MODE_SUBTSTATS	"))	;
		TSTAT_OUTPUTSTATE_SUBTSTATS	=	Get_RegID(_T("	TSTAT_OUTPUTSTATE_SUBTSTATS	"))	;
		TSTAT_NIGHT_HEATTINGDB_SUBTSTATS	=	Get_RegID(_T("	TSTAT_NIGHT_HEATTINGDB_SUBTSTATS	"))	;
		TSTAT_NIGHT_COOLINGDB_SUBTSTATS	=	Get_RegID(_T("	TSTAT_NIGHT_COOLINGDB_SUBTSTATS	"))	;
		TSTAT_NIGHT_HEATTINGSETPOINT_SUBTSTATS	=	Get_RegID(_T("	TSTAT_NIGHT_HEATTINGSETPOINT_SUBTSTATS	"))	;
		TSTAT_NIGHT_COOLINGSETPOINT_SUBTSTATS	=	Get_RegID(_T("	TSTAT_NIGHT_COOLINGSETPOINT_SUBTSTATS	"))	;
		TSTAT_PRODUCTMODEL_SUBTSTATS	=	Get_RegID(_T("	TSTAT_PRODUCTMODEL_SUBTSTATS	"))	;
		TSTAT_OVERRIDE_SUBTSTATS	=	Get_RegID(_T("	TSTAT_OVERRIDE_SUBTSTATS	"))	;
		TSTAT_SERIALNO_SUBTSTATS	=	Get_RegID(_T("	TSTAT_SERIALNO_SUBTSTATS	"))	;
		TSTAT_OFFTIME_SUBTSTATS	=	Get_RegID(_T("	TSTAT_OFFTIME_SUBTSTATS	"))	;
		TSTAT_ONTIME_SUBTSTATS	=	Get_RegID(_T("	TSTAT_ONTIME_SUBTSTATS	"))	;
		TEST50	=	Get_RegID(_T("	TEST50	"))	;
		VALUEINPUT1TO34	=	Get_RegID(_T("	VALUEINPUT1TO34	"))	;
		RANGE_INPUT1TO32	=	Get_RegID(_T("	RANGE_INPUT1TO32	"))	;
		FILTER_INPUT1TO32	=	Get_RegID(_T("	FILTER_INPUT1TO32	"))	;
		CALIBRATION_INPUT1TO32	=	Get_RegID(_T("	CALIBRATION_INPUT1TO32	"))	;
		TOTAL_TSTAT0	=	Get_RegID(_T("	TOTAL_TSTAT0	"))	;
		TOTAL_TSTAT1	=	Get_RegID(_T("	TOTAL_TSTAT1	"))	;
		TOTAL_TSTAT2	=	Get_RegID(_T("	TOTAL_TSTAT2	"))	;
		TSTAT_ADD_BOTH_CHANNEL_UART0	=	Get_RegID(_T("	TSTAT_ADD_BOTH_CHANNEL_UART0	"))	;
		TSTAT_ADD_BOTH_CHANNEL_UART1	=	Get_RegID(_T("	TSTAT_ADD_BOTH_CHANNEL_UART1	"))	;
		TSTAT_ADD_BOTH_CHANNEL_UART2	=	Get_RegID(_T("	TSTAT_ADD_BOTH_CHANNEL_UART2	"))	;


#endif




	}

 
// CDialgMiniPanel message handlers

void CDialgMiniPanel::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

#if 0
     UpdateGrid();
	//显示横标题
	m_msflexgridinput.put_TextMatrix(0,1,_T("Input Name"));
	m_msflexgridinput.put_TextMatrix(0,2,_T("Value"));
	//m_msflexgridinput.put_TextMatrix(0,3,_T("Auto/Manual"));
	m_msflexgridinput.put_TextMatrix(0,3,_T("Range"));
	m_msflexgridinput.put_TextMatrix(0,4,_T("Function"));


	//设置排/行数量
	m_msflexgridinput.put_Cols(5);
	m_msflexgridinput.put_Rows(33);//包括标题栏


	//设置列宽	
	m_msflexgridinput.put_ColWidth(0,400);
	m_msflexgridinput.put_ColWidth(3,1500);
	m_msflexgridinput.put_ColWidth(4,1000);
	//居中显示
	for (int col=0;col<5;col++)
	{ 
		m_msflexgridinput.put_ColAlignment(col,4);
	}

	//彩色显示
	for(int i=1;i<33;i++)		//排数量
	{

		for(int k=0;k<5;k++)	//列数量
		{
			if (i%2==1)
			{
				m_msflexgridinput.put_Row(i);m_msflexgridinput.put_Col(k);m_msflexgridinput.put_CellBackColor(RGB(255,255,255));
			}
			else
			{
				m_msflexgridinput.put_Row(i);m_msflexgridinput.put_Col(k);m_msflexgridinput.put_CellBackColor(COLOR_CELL);
			}
		}
	}




	//第3，4列11-26灰色显示
	// 	for (int i=1;i<33;i++)
	// 	{
	// 
	// 		m_msflexgridinput.put_TextMatrix(i,4,_T("°C"));	  
	// 		m_msflexgridinput.put_Row(i);
	// 		m_msflexgridinput.put_Col(4);
	// 		m_msflexgridinput.put_CellBackColor(FLEXGRID_CELL_GRAY_COLOR);	   //灰色
	// 	}


	//显示纵标题
	CString str;
	for(int i=1;i<33;i++)
	{

		str.Format(_T("%d"),i);

		m_msflexgridinput.put_TextMatrix(i,0,str);	 

// 		str = _T("Input ")+str;
// 		m_msflexgridinput.put_TextMatrix(i,1,str);
		m_msflexgridinput.put_TextMatrix(i,4,_T("Default"));	

	}

	//显示结果值
	//	str =_T("");
	//	for(int i=1;i<33;i++)
	//	{

	// 		str.Format(_T("%d"),i);
	// 
	// 		m_msflexgridinput.put_TextMatrix(i,0,str);
	// 		str = _T("Input ")+str;
	// 		m_msflexgridinput.put_TextMatrix(i,1,str);
	// 
	// 		//m_msflexgridinput.put_TextMatrix(i,3,_T("Auto"));
	// 		m_msflexgridinput.put_TextMatrix(i,3,_T("On/Off"));
	//		m_msflexgridinput.put_TextMatrix(i,4,_T("Default"));	


	//	}


	//unsigned char writevalue[1];
	//writevalue[0] = 0;
	//int flg = Write_Multi(g_tstat_id,writevalue,144,10);
	//TRACE(_T("flg=%d\n"),flg);
	//ASSERT(flg>0);


	//============================================================================================================界面Output DO部份列表框

	//设置行/列数量
	m_msflexgridDO.put_Rows(13);
	m_msflexgridDO.put_Cols(6);
	//设置列宽	
	m_msflexgridDO.put_ColWidth(0,400);
	m_msflexgridDO.put_ColWidth(3,1500);

	//显示横标题
	m_msflexgridDO.put_TextMatrix(0,1,_T("Input Name"));
	m_msflexgridDO.put_TextMatrix(0,2,_T("Value"));
	m_msflexgridDO.put_TextMatrix(0,3,_T("Auto/Manual"));
	m_msflexgridDO.put_TextMatrix(0,4,_T("Range"));
	m_msflexgridDO.put_TextMatrix(0,5,_T("Function"));



	//居中显示
	for (int col=0;col<6;col++)
	{ 
		m_msflexgridDO.put_ColAlignment(col,4);
	}

	//彩色显示
	for(int i=1;i<13;i++)		//排数量
	{

		for(int k=0;k<6;k++)	//列数量
		{
			if (i%2==1)
			{
				m_msflexgridDO.put_Row(i);m_msflexgridDO.put_Col(k);m_msflexgridDO.put_CellBackColor(RGB(255,255,255));
			}
			else
			{
				m_msflexgridDO.put_Row(i);m_msflexgridDO.put_Col(k);m_msflexgridDO.put_CellBackColor(COLOR_CELL);
			}
		}
	}
	//显示纵标题
	CString str_output;
	for(int i=1;i<13;i++)
	{

		str_output.Format(_T("%d"),i);
		m_msflexgridDO.put_TextMatrix(i,0,str_output);	
// 		str_output = _T("Output ")+str_output;
// 		m_msflexgridDO.put_TextMatrix(i,1,str_output);
// 
// 		//m_msflexgrid_output.put_TextMatrix(i,3,_T("Off"));
// 		m_msflexgridDO.put_TextMatrix(i,4,_T("On/Off"));
 		m_msflexgridDO.put_TextMatrix(i,5,_T("Default"));
		m_msflexgridDO.put_Row(i);
		m_msflexgridDO.put_Col(4);
		m_msflexgridDO.put_CellBackColor(FLEXGRID_CELL_GRAY_COLOR);
	}



	//============================================================================================================界面Output AO部份列表框

	//设置行/列数量
	m_msflexgridAO.put_Rows(13);
	m_msflexgridAO.put_Cols(6);
	//设置列宽	
	m_msflexgridAO.put_ColWidth(0,400);
	m_msflexgridAO.put_ColWidth(3,1500);

	//显示横标题
	m_msflexgridAO.put_TextMatrix(0,1,_T("Input Name"));
	m_msflexgridAO.put_TextMatrix(0,2,_T("Value"));
	m_msflexgridAO.put_TextMatrix(0,3,_T("Auto/Manual"));
	m_msflexgridAO.put_TextMatrix(0,4,_T("Range"));
	m_msflexgridAO.put_TextMatrix(0,5,_T("Function"));



	//居中显示
	for (int col=0;col<6;col++)
	{ 
		m_msflexgridAO.put_ColAlignment(col,4);
	}

	//彩色显示
	for(int i=1;i<13;i++)		//排数量
	{

		for(int k=0;k<6;k++)	//列数量
		{
			if (i%2==1)
			{
				m_msflexgridAO.put_Row(i);m_msflexgridAO.put_Col(k);m_msflexgridAO.put_CellBackColor(RGB(255,255,255));
			}
			else
			{
				m_msflexgridAO.put_Row(i);m_msflexgridAO.put_Col(k);m_msflexgridAO.put_CellBackColor(COLOR_CELL);
			}
		}
	}
	//显示纵标题
	CString str_outputAO;
	for(int i=1;i<13;i++)
	{

		str_outputAO.Format(_T("%d"),i);
		m_msflexgridAO.put_TextMatrix(i,0,str_outputAO);	
 
		m_msflexgridAO.put_TextMatrix(i,5,_T("Default"));
		m_msflexgridAO.put_Row(i);
		m_msflexgridAO.put_Col(4);
		m_msflexgridAO.put_CellBackColor(FLEXGRID_CELL_GRAY_COLOR);
	}

#endif 
}
void CDialgMiniPanel::DrawGrid(){
#if 1

	if (multi_register_value_tcp[34]==1)
	{
		input_rows=32;
		output_AO=12;
		output_DO=12;
	} 
	else
	{
		input_rows=16;
		output_AO=6;
		output_DO=4;
	}


	//设置排/行数量
	//m_msflexgridinput.Clear();
	m_msflexgridinput.put_Cols(7);
	m_msflexgridinput.put_Rows(input_rows+1);//包括标题栏

	//显示横标题
	m_msflexgridinput.put_TextMatrix(0,1,_T("Name"));
	m_msflexgridinput.put_TextMatrix(0,2,_T("Enable"));
	m_msflexgridinput.put_TextMatrix(0,3,_T("Value"));
	m_msflexgridinput.put_TextMatrix(0,4,_T("Range"));
	m_msflexgridinput.put_TextMatrix(0,5,_T("Filter"));
	m_msflexgridinput.put_TextMatrix(0,6,_T("Calibration"));

	//设置列宽	
	m_msflexgridinput.put_ColWidth(0,400);
	m_msflexgridinput.put_ColWidth(1,1500);
	m_msflexgridinput.put_ColWidth(2,1000);
	m_msflexgridinput.put_ColWidth(3,600);
	//居中显示
	for (int col=0;col<7;col++)
	{ 
		m_msflexgridinput.put_ColAlignment(col,4);
	}

	//彩色显示
	for(int i=1;i<input_rows+1;i++)		//排数量
	{

		for(int k=0;k<7;k++)	//列数量
		{
			if (i%2==1)
			{
				m_msflexgridinput.put_Row(i);m_msflexgridinput.put_Col(k);m_msflexgridinput.put_CellBackColor(RGB(255,255,255));
			}
			else
			{
				m_msflexgridinput.put_Row(i);m_msflexgridinput.put_Col(k);m_msflexgridinput.put_CellBackColor(COLOR_CELL);
			}
		}
	}







	//显示纵标题
	CString str;
	for(int i=1;i<input_rows+1;i++)
	{
		str.Format(_T("%d"),i);
		m_msflexgridinput.put_TextMatrix(i,0,str);	 
		str.Format(_T("Input%d"),i);
		m_msflexgridinput.put_TextMatrix(i,1,str);	

	}




	//============================================================================================================界面Output DO部份列表框

	//设置行/列数量
	//m_msflexgridDO.Clear();
	m_msflexgridDO.put_Rows(output_DO+1);
	m_msflexgridDO.put_Cols(5);
	//设置列宽	
	m_msflexgridDO.put_ColWidth(0,400);
	m_msflexgridDO.put_ColWidth(3,1500);

	//显示横标题
	m_msflexgridDO.put_TextMatrix(0,1,_T("Name"));
	m_msflexgridDO.put_TextMatrix(0,2,_T("Value"));
	m_msflexgridDO.put_TextMatrix(0,3,_T("Switch"));
	m_msflexgridDO.put_TextMatrix(0,4,_T("Enable"));




	//居中显示
	for (int col=0;col<5;col++)
	{ 
		m_msflexgridDO.put_ColAlignment(col,4);
	}

	//彩色显示
	for(int i=1;i<output_DO+1;i++)		//排数量
	{

		for(int k=0;k<5;k++)	//列数量
		{
			if (i%2==1)
			{
				m_msflexgridDO.put_Row(i);m_msflexgridDO.put_Col(k);m_msflexgridDO.put_CellBackColor(RGB(255,255,255));
			}
			else
			{
				m_msflexgridDO.put_Row(i);m_msflexgridDO.put_Col(k);m_msflexgridDO.put_CellBackColor(COLOR_CELL);
			}
		}
	}
	//显示纵标题

	for(int i=1;i<output_DO+1;i++)
	{

		str.Format(_T("%d"),i);
		m_msflexgridDO.put_TextMatrix(i,0,str);	 
		str.Format(_T("DO%d"),i);
		m_msflexgridDO.put_TextMatrix(i,1,str);


	}



	//============================================================================================================界面Output AO部份列表框

	//设置行/列数量
	//m_msflexgridAO.Clear();
	m_msflexgridAO.put_Rows(output_AO+1);
	m_msflexgridAO.put_Cols(5);
	//设置列宽	
	m_msflexgridAO.put_ColWidth(0,400);
	m_msflexgridAO.put_ColWidth(3,1500);

	//显示横标题
	m_msflexgridAO.put_TextMatrix(0,1,_T("Name"));
	m_msflexgridAO.put_TextMatrix(0,2,_T("Value"));
	m_msflexgridAO.put_TextMatrix(0,3,_T("Switch"));
	m_msflexgridAO.put_TextMatrix(0,4,_T("Enable"));




	//居中显示
	for (int col=0;col<5;col++)
	{ 
		m_msflexgridAO.put_ColAlignment(col,4);
	}

	//彩色显示
	for(int i=1;i<output_AO+1;i++)		//排数量
	{

		for(int k=0;k<5;k++)	//列数量
		{
			if (i%2==1)
			{
				m_msflexgridAO.put_Row(i);m_msflexgridAO.put_Col(k);m_msflexgridAO.put_CellBackColor(RGB(255,255,255));
			}
			else
			{
				m_msflexgridAO.put_Row(i);m_msflexgridAO.put_Col(k);m_msflexgridAO.put_CellBackColor(COLOR_CELL);
			}
		}
	}
	//显示纵标题
	CString str_outputAO;
	for(int i=1;i<output_AO+1;i++)
	{

		str.Format(_T("%d"),i);
		m_msflexgridAO.put_TextMatrix(i,0,str);	 
		str.Format(_T("AO%d"),i);
		m_msflexgridAO.put_TextMatrix(i,1,str);
	}
	UpdateGrid();
#endif 
}
void CDialgMiniPanel::Fresh()
{
	 SetTimer(MiniPanelTimer,1000,NULL);
	 DrawGrid();
	 ShowMinipDialog();
 //OnBnClickedButtonRefreshAll();
}
void CDialgMiniPanel::UpdateGrid(){
	CString index;

	//============================================================================================列表框设置（界面中间部份列表框）
	m_Output_GridCM5_.put_Rows(9); //行
	m_Output_GridCM5_.put_Cols(16);
	//set row high
	m_Output_GridCM5_.put_WordWrap(TRUE);
	m_Output_GridCM5_.put_RowHeight(0,500);
	//title middle show
	for (int n=0;n<=9;n++)
	{
		m_Output_GridCM5_.put_ColAlignment(n,4);
	}
	//设置列宽
	m_Output_GridCM5_.put_ColWidth(0,400);
	m_Output_GridCM5_.put_ColWidth(1,800);
	m_Output_GridCM5_.put_ColWidth(2,1200);
	m_Output_GridCM5_.put_ColWidth(3 ,800);
	m_Output_GridCM5_.put_ColWidth(4 ,1000);
	m_Output_GridCM5_.put_ColWidth(5 ,1000);
	m_Output_GridCM5_.put_ColWidth(6 ,1000);
	m_Output_GridCM5_.put_ColWidth(7 ,1000);
	m_Output_GridCM5_.put_ColWidth(8 ,1000);
	m_Output_GridCM5_.put_ColWidth(9 ,1200);
	m_Output_GridCM5_.put_ColWidth(10,1200);
	m_Output_GridCM5_.put_ColWidth(11,1200);
	m_Output_GridCM5_.put_ColWidth(12,1200);
	m_Output_GridCM5_.put_ColWidth(13,1200);
	m_Output_GridCM5_.put_ColWidth(14,1200);

	m_Output_GridCM5_.put_TextMatrix(0,0,_T("No"));
	m_Output_GridCM5_.put_TextMatrix(0,1,_T("Device\nName"));
	m_Output_GridCM5_.put_TextMatrix(0,2,_T("Modbus ID\nAddress"));
	m_Output_GridCM5_.put_TextMatrix(0,3,_T("SN"));
	m_Output_GridCM5_.put_TextMatrix(0,4 ,_T("Cooling\nSetpoint"));
	m_Output_GridCM5_.put_TextMatrix(0,5 ,_T("Heating\nSetpoint"));
	m_Output_GridCM5_.put_TextMatrix(0,6 ,_T("Setpoint"));
	m_Output_GridCM5_.put_TextMatrix(0,7 ,_T("Room\nTemperture"));
	m_Output_GridCM5_.put_TextMatrix(0,8 ,_T("Mode"));
	m_Output_GridCM5_.put_TextMatrix(0,9 ,_T("Night Heating\nSetpoint"));
	m_Output_GridCM5_.put_TextMatrix(0,10 ,_T("Night Cooling\nSetpoint"));
	m_Output_GridCM5_.put_TextMatrix(0,11,_T("Occupied"));
	m_Output_GridCM5_.put_TextMatrix(0,12,_T("Output Status"));
	m_Output_GridCM5_.put_TextMatrix(0,13,_T("Night Heating\n DB"));
	m_Output_GridCM5_.put_TextMatrix(0,14,_T("Night Cooling\n DB"));
	m_Output_GridCM5_.put_TextMatrix(0,15,_T("Override Value"));
	//彩色显示
	for(int i=1;i<9;i++)
	{

		//		for(int k=0;k<=12;k++)
		index.Format(_T("%d"),i);
		m_Output_GridCM5_.put_TextMatrix(i,0,index);
		for(int k=0;k<=15;k++)
		{


			if (i%2==1)
			{
				m_Output_GridCM5_.put_Row(i);
				m_Output_GridCM5_.put_Col(k);
				m_Output_GridCM5_.put_CellBackColor(RGB(255,255,255));
			}
			else
			{
				m_Output_GridCM5_.put_Row(i);
				m_Output_GridCM5_.put_Col(k);
				m_Output_GridCM5_.put_CellBackColor(COLOR_CELL);
			}
		}
	} 
}
void CDialgMiniPanel::ShowMinipDialog()
{

	

	int cooling_temp;
	int coasting_temp;
	int heating_temp;
#if 1

	//============================================================System Parameters===============================================================

	m_CStrModel = _T("Mini Panel");
	//6	1	Modbus device address
	m_inaddress =multi_register_value_tcp[6];// _wtoi(vecminipanel.at(6).CStvalue);

	UINT nSelectSerialNumber = multi_register_value_tcp[0]+multi_register_value_tcp[1]*256+multi_register_value_tcp[2]*256*256+multi_register_value_tcp[3]*256*256*256;
	m_inSerialNum=nSelectSerialNumber;

	m_flFirmware = (float)(multi_register_value_tcp[5]*256+multi_register_value_tcp[4])/10;

	m_inHardware = multi_register_value_tcp[8];
	if (multi_register_value_tcp[12]==1)
	{
	m_inBaudrate = 19200;
	} 
	else
	{
	m_inBaudrate = 9600;
	}
	 
	/*
	Comment by:Alex
	Date:2013/04/10
	Purpose:
	Tcp infomation
	*/
	if(multi_register_value_tcp[106]==0)
	{
		m_ipModelComBox.SetCurSel(0);
	}
	if(multi_register_value_tcp[106]==1)
	{
		m_ipModelComBox.SetCurSel(1);
	}
	m_nListenPort.Format(_T("%d"),multi_register_value_tcp[120]);

	CString mac_address;
	mac_address.Format(_T("%02x-%02x-%02x-%02x-%02x-%02x"),multi_register_value_tcp[100],multi_register_value_tcp[101],multi_register_value_tcp[102],multi_register_value_tcp[103],multi_register_value_tcp[104],multi_register_value_tcp[105]);
	m_Mac_Address.SetWindowText(mac_address);

	m_ip_addressCtrl.SetAddress((BYTE)multi_register_value_tcp[107],(BYTE)multi_register_value_tcp[108],(BYTE)multi_register_value_tcp[109],(BYTE)multi_register_value_tcp[110]);
	m_subnet_addressCtrl.SetAddress((BYTE)multi_register_value_tcp[111],(BYTE)multi_register_value_tcp[112],(BYTE)multi_register_value_tcp[113],(BYTE)multi_register_value_tcp[114]);
	m_gateway_addressCtrl.SetAddress((BYTE)multi_register_value_tcp[115],(BYTE)multi_register_value_tcp[116],(BYTE)multi_register_value_tcp[117],(BYTE)multi_register_value_tcp[118]);
	
	UpdateData(FALSE);

	//==========================================显示界面中间列表框中的数据==============================================

	//	    5671 to 5678	8	cooling setpoint value of Sub Tstats(register380)
	//		5679 to 5686	8	heating setpoint value of Sub Tstats(register136)
	//		5687 to 5694	8	setpoint value of Sub Tstats(register135)
	//		5695 to 5702	8	room temperture value of Sub Tstats(register101)
	//		5703 to 5710	8	mode of Sub Tstats(register107)
	//		5711 to 5718	8	output state of Sub Tstats(register108)

	//		5735 to 5742	8	night heatting setpoint value of Sub Tstats(register182)
	//		5743 to 5750	8	night cooling setpoint value of Sub Tstats(register183)
	//		5751 to 5758	8	tstat product model of Sub Tstats(register7)

	/*if (multi_register_value_tcp[8200]>0)
	{*/
		_subnetwork.clear();
		for (int i = 0;i<8;i++)
		{

			m_subetwork.m_Occupied=(multi_register_value_tcp[5670]&(unsigned short)pow((double)2,i));//1,2,4,8,16,32,64,128
			m_subetwork.m_coolingSet.Format(_T("%.1f°C"),(float)multi_register_value_tcp[5671+i]/10);
			m_subetwork.m_heatingSet.Format(_T("%.1f°C"),(float)multi_register_value_tcp[5671+i+8]);
			m_subetwork.m_setpoint.Format(_T("%.1f°C"),(float)multi_register_value_tcp[5671+i+16]); 
			m_subetwork.m_roomTemper.Format(_T("%.1f°C"),(float)multi_register_value_tcp[5671+i+24]/10); 
			m_subetwork.m_mode = multi_register_value_tcp[5671+i+32];     
			m_subetwork.m_outputState.Format(_T("%.1f"),(float)multi_register_value_tcp[5671+i+40]/10); 
			m_subetwork.m_nightHeatingDB.Format(_T("%.1f°C"),(float)multi_register_value_tcp[5671+i+48]);
			m_subetwork.m_nightCoolingDB.Format(_T("%.1f°C"),(float)multi_register_value_tcp[5671+i+56]); 
			m_subetwork.m_nightHeating.Format(_T("%.1f°C"),(float)multi_register_value_tcp[5671+i+64]);
			m_subetwork.m_nightCooling.Format(_T("%.1f°C"),(float)multi_register_value_tcp[5671+i+72]); 
			m_subetwork.m_tstatProduct = multi_register_value_tcp[5671+i+80];
			m_subetwork.m_overridevalue.Format(_T("%d"),multi_register_value_tcp[5671+i+88]);
			m_subetwork.m_SerialNumber.Format(_T("%d"),multi_register_value_tcp[5671+i+96]+multi_register_value_tcp[5671+i+96+1]*256+multi_register_value_tcp[5671+i+96+2]*256*256+multi_register_value_tcp[5671+i+96+3]*256*256*256);
    		m_subetwork.m_modbusaddr.Format(_T("%d"),multi_register_value_tcp[8203+i]);
			_subnetwork.push_back(m_subetwork);

		}


		CString m_num,strtemp1,strtemp2;
		coasting_temp = 0;
		heating_temp = 0;
		cooling_temp = 0;
		//m_Output_GridCM5_.Clear();
		 
		UpdateGrid();
		//int type;
		for (int i=1;i<9;i++)
		{

			/*type=multi_register_value_tcp[173+i];
			if (type!=1)
			{
				continue;
			}*/
			int ret = _subnetwork.at(i-1).m_modbusaddr.Compare(_T("0"));
			if(ret == 0)
				continue;
			m_num.Format(_T("%d"),i);
			m_Output_GridCM5_.put_TextMatrix(i,0,m_num);//第一列：序号

			switch(_subnetwork.at(i-1).m_tstatProduct)
			{
			case 1:strtemp1=g_strTstat5b;break;
			case 2:strtemp1=g_strTstat5a;break;
			case 3:strtemp1=g_strTstat5b;break;
			case 4:strtemp1=g_strTstat5c;break;
			case 12:			strtemp1=g_strTstat5d;break;
			case 100:		strtemp1=g_strnetWork;break;
			case NET_WORK_OR485_PRODUCT_MODEL:strtemp1=g_strOR485;break;
			case 17:strtemp1=g_strTstat5f;break;
			case 18:strtemp1=g_strTstat5g;break;
			case 16:strtemp1=g_strTstat5e;break;
			case 19:strtemp1=g_strTstat5h;break;
			case 6:strtemp1=g_strTstat6;break;
			case 7:strtemp1=g_strTstat7;break;
			case 13:
			case 14:break;
			default:strtemp1=_T("Tstat");break;
			}
			m_Output_GridCM5_.put_TextMatrix(i,1,strtemp1);//Device Name
			m_Output_GridCM5_.put_TextMatrix(i,2,_subnetwork.at(i-1).m_modbusaddr);//Address
			m_Output_GridCM5_.put_TextMatrix(i,3,_subnetwork.at(i-1).m_SerialNumber);//SN
			m_Output_GridCM5_.put_TextMatrix(i,4,_subnetwork.at(i-1).m_coolingSet);
			m_Output_GridCM5_.put_TextMatrix(i,5,_subnetwork.at(i-1).m_heatingSet);
			m_Output_GridCM5_.put_TextMatrix(i,6,_subnetwork.at(i-1).m_setpoint);
			m_Output_GridCM5_.put_TextMatrix(i,7,_subnetwork.at(i-1).m_roomTemper);

			switch (_subnetwork.at(i-1).m_mode)		 
			{
			case 0:
				strtemp2.Format(_T("%s"),_T("COASTING"));
				coasting_temp++;
				break;
			case 1:
				strtemp2.Format(_T("%s"),_T("COOLING1"));
				cooling_temp++;
				break;
			case 2:
				strtemp2.Format(_T("%s"),_T("COOLING2"));	
				cooling_temp++;
				break;
			case 3:
				strtemp2.Format(_T("%s"),_T("COOLING3"));
				cooling_temp++;
				break;
			case 4:
				strtemp2.Format(_T("%s"),_T("HEATING1"));
				heating_temp++;
				break;
			case 5:
				strtemp2.Format(_T("%s"),_T("HEATING2"));
				heating_temp++;
				break;
			case 6:
				strtemp2.Format(_T("%s"),_T("HEATING3"));
				heating_temp++;
				break;

			default:
				strtemp2.Format(_T("%s"),_T("COASTING"));
				coasting_temp++;
				break;
			}
			m_Output_GridCM5_.put_TextMatrix(i,8,strtemp2);

			m_Output_GridCM5_.put_TextMatrix(i,9,_subnetwork.at(i-1).m_nightHeating);
			m_Output_GridCM5_.put_TextMatrix(i,10,_subnetwork.at(i-1).m_nightCooling);
			if  (
				(_subnetwork.at(i-1).m_Occupied==1)
				||(_subnetwork.at(i-1).m_Occupied==2)
				||(_subnetwork.at(i-1).m_Occupied==4)
				||(_subnetwork.at(i-1).m_Occupied==8)
				||(_subnetwork.at(i-1).m_Occupied==16)
				||(_subnetwork.at(i-1).m_Occupied==32)
				||(_subnetwork.at(i-1).m_Occupied==64)
				||(_subnetwork.at(i-1).m_Occupied==128)
				)   
			{
				m_Output_GridCM5_.put_TextMatrix(i,11,_T("Online"));
			} 
			else
			{
				m_Output_GridCM5_.put_TextMatrix(i,11,_T("Offline"));
			}
			m_Output_GridCM5_.put_TextMatrix(i,12,_subnetwork.at(i-1).m_outputState);
			m_Output_GridCM5_.put_TextMatrix(i,13,_subnetwork.at(i-1).m_nightHeatingDB);
			m_Output_GridCM5_.put_TextMatrix(i,14,_subnetwork.at(i-1).m_nightCoolingDB);
			m_Output_GridCM5_.put_TextMatrix(i,15,_subnetwork.at(i-1).m_overridevalue);
		}
	/*}*/


	 

#endif
UpdateData_Input();
UpdateData_AO();
UpdateData_DO();
}

BOOL CDialgMiniPanel::GetDatabase()
{ 
	CADO m_ado;
	m_ado.OnInitADOConn();

	if(ifminidb)
	{

	//判断MiniPanel数据库是否存在,Auto/Manual text,Range text

	CString temptable = _T("MiniPanel");
	CString tempsql = _T("create table MiniPanel(Address Number Primary Key,Name text,Data text,AutoManual text,Range text)");//
		
	bool m_judge = m_ado.IsHaveTable(m_ado,temptable);

	//不存在 创建数据库表
	if (!m_judge) 
	{	
 		m_ado.m_pRecordset = m_ado.OpenRecordset(tempsql);
		//初始化表
		CString sql = _T("select * from MiniPanel");
		m_ado.m_pRecordset = m_ado.OpenRecordset(sql);
		if (m_ado.m_pRecordset->EndOfFile)
		{

		for(int i = 0;i<230;i++)
		{
			try 
			{
				m_ado.m_pRecordset->AddNew();
				m_ado.m_pRecordset->PutCollect("Address",(_bstr_t)(i+1));
				m_ado.m_pRecordset->PutCollect("Name",(_bstr_t)_T("Unused"));
				m_ado.m_pRecordset->PutCollect("Data",(_bstr_t)"On");
				m_ado.m_pRecordset->PutCollect("Range",(_bstr_t)_T("On/Off"));
				m_ado.m_pRecordset->PutCollect("AutoManual",(_bstr_t)"Auto");

				m_ado.m_pRecordset->Update();

			}


			catch(...)
			{

			}
		}
		}
		

	}

	ifminidb = FALSE;
	}

#if 1
	vecminipanel.clear();
 	CString SQL = _T("select * from MiniPanel"); 
 	m_ado.m_pRecordset = m_ado.OpenRecordset(SQL);
	_variant_t vartemp;
	while(!m_ado.m_pRecordset->EndOfFile)
	{
		MINImini.iaddress =m_ado.m_pRecordset->GetCollect(_T("Address"));
		vartemp =m_ado.m_pRecordset->GetCollect(_T("Name"));
		if (vartemp.vt==VT_NULL)
			MINImini.CStName =_T("");
		else
			MINImini.CStName =vartemp;


		vartemp =m_ado.m_pRecordset->GetCollect(_T("Data"));
		if (vartemp.vt==VT_NULL)
			MINImini.CStvalue =_T("");
		else
			MINImini.CStvalue =vartemp;


		vartemp =m_ado.m_pRecordset->GetCollect(_T("AutoManual"));
		if (vartemp.vt==VT_NULL)
			MINImini.CStautomannel =_T("");
		else
			MINImini.CStautomannel =vartemp;


		vartemp =m_ado.m_pRecordset->GetCollect(_T("Range"));
		if (vartemp.vt==VT_NULL)
			MINImini.CStrange =_T("");
		else
			MINImini.CStrange =vartemp;

		m_ado.m_pRecordset->MoveNext();

		vecminipanel.push_back(MINImini);
	}

//读取本电脑当前正在使用的串口。
	CString CSTcompot;
	BOOL BOdefault;
	SQL = _T("select * from Building");
	m_ado.m_pRecordset = m_ado.OpenRecordset(SQL);
	while(!m_ado.m_pRecordset->EndOfFile)
	{
		CSTcompot =(_variant_t)m_ado.m_pRecordset->GetCollect(_T("Com_Port"));
		BOdefault =(_variant_t)m_ado.m_pRecordset->GetCollect(_T("Default_SubBuilding"));//TRUE = -1即非0，FALSE就是0
		m_ado.m_pRecordset->MoveNext();

		if (BOdefault)
		{
			comnum = _wtoi(CSTcompot.Mid(3));
		}

	}



	m_ado.CloseRecordset();
	m_ado.CloseConn();





#endif 



	return TRUE;



}

BOOL CDialgMiniPanel::MiniUpdateData()
{
	KillTimer(MiniPanelTimer);
#if 1
	m_prgoressctrl.ShowWindow(TRUE);
	m_prgoressctrl.SetRange(0,86);
	m_prgoressctrl.SetPos(0);
	register_critical_section.Lock();
	for(int i=0;i<86;i++)
	{	
		Read_Multi(g_tstat_id,&multi_register_value_tcp[i*100],i*100,100);
		m_prgoressctrl.SetPos(i);	
	}
	register_critical_section.Unlock();
	m_prgoressctrl.SetPos(86);
	m_prgoressctrl.ShowWindow(FALSE);
	DrawGrid();
	ShowMinipDialog();

	SetTimer(MiniPanelTimer,1000,NULL);
#endif
	return TRUE; 
}



void CDialgMiniPanel::OnTimer(UINT_PTR nIDEvent)
{

	CMainFrame* pMain = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CView* pNewView = pMain->m_pViews[6];
	CView* pActiveView = pMain->GetActiveView();

	if ( pNewView != pActiveView )    // current is minipanel dialog
	{
		KillTimer(MiniPanelTimer);
	}

#if 1
	static int nCount = 0,nCount2 = 0;

	nCount++;
	nCount2++;

	if (MiniPanelTimer == nIDEvent)
	{
		//CTime now;
		//now = CTime::GetCurrentTime();
		//m_datetime = now.Format(_T("%A,%B %d,%Y  %H:%M:%S"));		// "Saturday, April 12, 2012"		



		CTime time = CTime::GetCurrentTime();

		CString strtime = time.Format(_T("%I:%M:%S %p"));
		//CString strtime = time.Format(_T("%m/%d/%Y %H:%M:%S %a"));
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TIME);
		pEdit->SetWindowText(strtime);

		CString strDate = time.Format(_T("%A, %b %d, %Y"));
		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_DATE);
		pEdit->SetWindowText(strDate);

		UpdateData(FALSE);

		if (nCount%30 == 0)
		{
	        if (is_connect())
	        {
				nCount = 0;
				MiniUpdateData(); 
				SetPaneString(2,_T("Online!"));
	        } 
	        else
	        {
				nCount = 0;
				 
				SetPaneString(2,_T("Offline!"));
	        }
		
		}
		


	}

#endif
	CFormView::OnTimer(nIDEvent);
}

void CDialgMiniPanel::Updatedatabase()
{
	TRACE(_T("Updatedatabase()start!\n"));
	KillTimer(MiniPanelTimer);
	//存入数据库中
	CADO saveADO;
	saveADO.OnInitADOConn();
	CString sql = _T("select * from MiniPanel");
	saveADO.m_pRecordset = saveADO.OpenRecordset(sql);
	if (!saveADO.m_pRecordset->EndOfFile)
	{
		saveADO.m_pRecordset->MoveFirst();

	for(int i = 0;i<230;i++)
	{
		try 
		{

			//saveADO.m_pRecordset->AddNew();
			//saveADO.m_pRecordset->Move(pos,vtMissing);
			// 			cstnum.Format(_T("%d"),i+1);
			// 			saveADO.m_pRecordset->PutCollect("Address",(_bstr_t)cstnum);
			// 			saveADO.m_pRecordset->PutCollect("Name",(_bstr_t)_T("output"));

			saveADO.m_pRecordset->PutCollect("Address",(_bstr_t)i);
			saveADO.m_pRecordset->PutCollect("Name",(_bstr_t)vecminipanel.at(i).CStName);
			saveADO.m_pRecordset->PutCollect("Data",(_bstr_t)shmPRegister[i]);
			saveADO.m_pRecordset->PutCollect("Range",(_bstr_t)vecminipanel.at(i).CStrange);
			

			if (i>=124&&i<=147)
			{
				switch ((int)(_variant_t)shmPRegister[i])
				{
				case 0:   //0- off 1 - mannel 2 - auto
					saveADO.m_pRecordset->PutCollect("AutoManual",(_bstr_t)"OFF");
					break;
				case 1:
					saveADO.m_pRecordset->PutCollect("AutoManual",(_bstr_t)"Manual");
					break;
				case 2:
					saveADO.m_pRecordset->PutCollect("AutoManual",(_bstr_t)"Auto");
					break;
				default:
					break;

				}
			}


			//  		saveADO.m_pRecordset->PutCollect("Auto/Manual",(_bstr_t)"auto");
			//  		saveADO.m_pRecordset->PutCollect("Range",(_bstr_t)"10%-100%");
			saveADO.m_pRecordset->Update();
			saveADO.m_pRecordset->MoveNext();
		}


		catch(...)
		{
			//MessageBox(_T("Write dababase false!"));
			
			SetPaneString(2,_T("Write dababase false!"));
			return ;
		}
	}
	}
	else
	{
		for(int i = 0;i<230;i++)
		{
			try 
			{

				//saveADO.m_pRecordset->AddNew();
				//saveADO.m_pRecordset->Move(pos,vtMissing);
				// 			cstnum.Format(_T("%d"),i+1);
				// 			saveADO.m_pRecordset->PutCollect("Address",(_bstr_t)cstnum);
				// 			saveADO.m_pRecordset->PutCollect("Name",(_bstr_t)_T("output"));
				saveADO.m_pRecordset->AddNew();
				saveADO.m_pRecordset->PutCollect("Address",(_bstr_t)i);
				saveADO.m_pRecordset->PutCollect("Name",(_bstr_t)vecminipanel.at(i).CStName);
				saveADO.m_pRecordset->PutCollect("Data",(_bstr_t)shmPRegister[i]);
				saveADO.m_pRecordset->PutCollect("Range",(_bstr_t)vecminipanel.at(i).CStrange);


				if (i>=124&&i<=147)
				{
					switch ((int)(_variant_t)shmPRegister[i])
					{
					case 0:   //0- off 1 - mannel 2 - auto
						saveADO.m_pRecordset->PutCollect("AutoManual",(_bstr_t)"OFF");
						break;
					case 1:
						saveADO.m_pRecordset->PutCollect("AutoManual",(_bstr_t)"Manual");
						break;
					case 2:
						saveADO.m_pRecordset->PutCollect("AutoManual",(_bstr_t)"Auto");
						break;
					default:
						break;

					}
				}


				//  		saveADO.m_pRecordset->PutCollect("Auto/Manual",(_bstr_t)"auto");
				//  		saveADO.m_pRecordset->PutCollect("Range",(_bstr_t)"10%-100%");
				saveADO.m_pRecordset->Update();

			}


			catch(...)
			{
				//MessageBox(_T("Write dababase false!"));

				SetPaneString(2,_T("Write dababase false!"));
				return ;
			}
		}

	}

	saveADO.CloseRecordset();
	saveADO.CloseConn(); 

	SetTimer(MiniPanelTimer,1000,NULL);

}
void CDialgMiniPanel::OnEnKillfocusEditInput()
{

	 CString strText;
	m_editinput.GetWindowText(strText); 
	m_editinput.ShowWindow(SW_HIDE);  
	 
	 int value=_wtoi(strText);
	 
	if (5==m_curCol)
	{   
	if (multi_register_value_tcp[8065+m_curRow]!=value)
	{
		int ret=write_one(g_tstat_id,8065+m_curRow,value);
		if (ret>0)
		{
			multi_register_value_tcp[8065+m_curRow]=value;
			UpdateData_Input();

		}
		else
		{
			AfxMessageBox(_T("Fail"));
		}
	}
	else
	{
	return;
	}
	}
	else if (6==m_curCol)
	{
	   if (multi_register_value_tcp[8097+m_curRow]!=value)
	   {
		   int ret=write_one(g_tstat_id,8097+m_curRow,value);
		   if (ret>0)
		   {
			   multi_register_value_tcp[8097+m_curRow]=value;
			   UpdateData_Input();
		   }
		   else
		   {
			   AfxMessageBox(_T("Fail"));
		   }
	   } 
	   else
	   {
	   return;
	   }

	     
		
	}


	 
	
 

}
BEGIN_EVENTSINK_MAP(CDialgMiniPanel, CFormView)
	ON_EVENT(CDialgMiniPanel, IDC_MSFLEXGRID_INPUT, DISPID_CLICK, CDialgMiniPanel::ClickMsflexgridInput, VTS_NONE)
	ON_EVENT(CDialgMiniPanel, IDC_MSFLEXGRID_OUTPUT_DO, DISPID_CLICK, CDialgMiniPanel::ClickMsflexgridOutputDo, VTS_NONE)
	ON_EVENT(CDialgMiniPanel, IDC_MSFLEXGRID_OUTPUT_AO, DISPID_CLICK, CDialgMiniPanel::ClickMsflexgridOutputAo, VTS_NONE)
END_EVENTSINK_MAP()

void CDialgMiniPanel::ClickMsflexgridInput()
{

	//使用edition控件形式显示

	long lRow,lCol;
	lRow = m_msflexgridinput.get_RowSel();
	lCol = m_msflexgridinput.get_ColSel(); 
	m_curCol=lCol;
	m_curRow=lRow;
	m_Table=1;
	CRect rect;
	m_msflexgridinput.GetWindowRect(rect); //
	ScreenToClient(rect); //
	CDC* pDC =GetDC();

	int nTwipsPerDotX = 1440 / pDC->GetDeviceCaps(LOGPIXELSX) ;
	int nTwipsPerDotY = 1440 / pDC->GetDeviceCaps(LOGPIXELSY) ;

	long y = m_msflexgridinput.get_RowPos(lRow)/nTwipsPerDotY;
	long x = m_msflexgridinput.get_ColPos(lCol)/nTwipsPerDotX;

	long width = m_msflexgridinput.get_ColWidth(lCol)/nTwipsPerDotX+1;
	long height = m_msflexgridinput.get_RowHeight(lRow)/nTwipsPerDotY+1;

	CRect rcCell(x,y,x+width,y+height);

	rcCell.OffsetRect(rect.left+1,rect.top+1);
	ReleaseDC(pDC);
	CString strValue = m_msflexgridinput.get_TextMatrix(lRow,lCol);
	 
		

		if(5==lCol||6==lCol)		
		{	
			
			TRACE(_T("ClickMsflexgridInput()start!\nKillTimer()start\n"));
			m_editinput.MoveWindow(&rcCell,1);
			m_editinput.ShowWindow(SW_SHOW);	
			m_editinput.SetWindowText(strValue);	
			m_editinput.SetFocus();
			m_editinput.SetCapture();//使随后的鼠标输入都被发送到这个CWnd 
			int nLenth=strValue.GetLength();	
			m_editinput.SetSel(nLenth,nLenth); 
			

		}	

		else if (4==lCol)
		{
		  m_combox_range.ResetContent();
		  for(int i=0;i<6;i++)
		  {
			  m_combox_range.AddString(AINPUT_Range[i]);
		  }
		  m_combox_range.MoveWindow(rcCell); //移动到选中格的位置，覆盖
		  m_combox_range.ShowWindow(SW_SHOW);
		  m_combox_range.BringWindowToTop();
		  
		  m_combox_range.SetFocus(); //获取焦点
		  m_combox_range.SetWindowText(strValue);
		}
		else if (2==lCol)
		{
		  m_combox_range.ResetContent();
		  m_combox_range.AddString(_T("Enable"));
		  m_combox_range.AddString(_T("Disable"));
		  m_combox_range.MoveWindow(rcCell); //移动到选中格的位置，覆盖
		  m_combox_range.ShowWindow(SW_SHOW);
		  m_combox_range.BringWindowToTop();
		  m_combox_range.SetFocus(); //获取焦点
		  m_combox_range.SetWindowText(strValue);
		}

	 
	 

}

void CDialgMiniPanel::OnEnKillfocusEditoutputdo()
{
	/*CString strText;
	m_editoutputdo.GetWindowText(strText); 
	m_editoutputdo.ShowWindow(SW_HIDE);  
	int lRow = m_msflexgridDO.get_RowSel();	
	int lCol = m_msflexgridDO.get_ColSel(); 

	m_msflexgridDO.put_TextMatrix(lRow,lCol,strText);
	CString strrow;
	strrow.Format(_T("%d"),lRow);
	CString stremp;
	stremp = _T("CM5_INPUT");
	int passvalue = lRow+99;
	writedbinputname(passvalue,strText);

	CRect rcCell(0,0,1,1);
	m_editoutputdo.MoveWindow(&rcCell,1);
	SetTimer(MiniPanelTimer,1000,NULL);*/
}

void CDialgMiniPanel::OnEnKillfocusEditOutputao()
{

	//CString strText;
	//m_editoutputao.GetWindowText(strText); 
	//m_editoutputao.ShowWindow(SW_HIDE);  
	//int lRow = m_msflexgridAO.get_RowSel();	
	//int lCol = m_msflexgridAO.get_ColSel(); 

	//m_msflexgridAO.put_TextMatrix(lRow,lCol,strText);
	//CString strrow;
	//strrow.Format(_T("%d"),lRow);
	//CString stremp;
	//stremp = _T("CM5_INPUT");
	//int passvalue = lRow+111;
	//writedbinputname(passvalue,strText);

	//CRect rcCell(0,0,1,1);
	//m_editoutputao.MoveWindow(&rcCell,1);
	//SetTimer(MiniPanelTimer,1000,NULL);
}

void CDialgMiniPanel::ClickMsflexgridOutputDo()
{

	//使用edition控件形式显示

	long lRow,lCol;
	lRow = m_msflexgridDO.get_RowSel();
	lCol = m_msflexgridDO.get_ColSel(); 
	 
	m_curCol=lCol;
	m_curRow=lRow;
	m_Table=2;
		CRect rect;
		m_msflexgridDO.GetWindowRect(rect); //
		ScreenToClient(rect); //
		CDC* pDC =GetDC();

		int nTwipsPerDotX = 1440 / pDC->GetDeviceCaps(LOGPIXELSX) ;
		int nTwipsPerDotY = 1440 / pDC->GetDeviceCaps(LOGPIXELSY) ;

		long y = m_msflexgridDO.get_RowPos(lRow)/nTwipsPerDotY;
		long x = m_msflexgridDO.get_ColPos(lCol)/nTwipsPerDotX;

		long width = m_msflexgridDO.get_ColWidth(lCol)/nTwipsPerDotX+1;
		long height = m_msflexgridDO.get_RowHeight(lRow)/nTwipsPerDotY+1;

		CRect rcCell(x,y,x+width,y+height);

		rcCell.OffsetRect(rect.left+1,rect.top+1);
		ReleaseDC(pDC);
		CString strValue = m_msflexgridDO.get_TextMatrix(lRow,lCol);

		if (3==lCol)
		{
			m_combox_range.ResetContent();
			m_combox_range.AddString(_T("OFF"));
			m_combox_range.AddString(_T("HAND"));
			m_combox_range.AddString(_T("AUTO"));
			m_combox_range.MoveWindow(rcCell); //移动到选中格的位置，覆盖
			m_combox_range.ShowWindow(SW_SHOW);
			m_combox_range.BringWindowToTop();

			m_combox_range.SetFocus(); //获取焦点
			m_combox_range.SetWindowText(strValue);
		}
		else if (4==lCol)
		{
			m_combox_range.ResetContent();
			m_combox_range.AddString(_T("Enable"));
			m_combox_range.AddString(_T("Disable"));
			m_combox_range.MoveWindow(rcCell); //移动到选中格的位置，覆盖
			m_combox_range.ShowWindow(SW_SHOW);
			m_combox_range.BringWindowToTop();
			m_combox_range.SetFocus(); //获取焦点
			m_combox_range.SetWindowText(strValue);
		}

	 
	 
}

void CDialgMiniPanel::ClickMsflexgridOutputAo()
{

	//使用edition控件形式显示

	long lRow,lCol;
	lRow = m_msflexgridAO.get_RowSel();
	lCol = m_msflexgridAO.get_ColSel(); 
	m_curCol=lCol;
	m_curRow=lRow;
	m_Table=3;
		CRect rect;
		m_msflexgridAO.GetWindowRect(rect); //
		ScreenToClient(rect); //
		CDC* pDC =GetDC();

		int nTwipsPerDotX = 1440 / pDC->GetDeviceCaps(LOGPIXELSX) ;
		int nTwipsPerDotY = 1440 / pDC->GetDeviceCaps(LOGPIXELSY) ;

		long y = m_msflexgridAO.get_RowPos(lRow)/nTwipsPerDotY;
		long x = m_msflexgridAO.get_ColPos(lCol)/nTwipsPerDotX;

		long width = m_msflexgridAO.get_ColWidth(lCol)/nTwipsPerDotX+1;
		long height = m_msflexgridAO.get_RowHeight(lRow)/nTwipsPerDotY+1;

		CRect rcCell(x,y,x+width,y+height);

		rcCell.OffsetRect(rect.left+1,rect.top+1);
		ReleaseDC(pDC);
		CString strValue = m_msflexgridAO.get_TextMatrix(lRow,lCol);

		 
		if (3==lCol)
		{
			m_combox_range.ResetContent();
			m_combox_range.AddString(_T("OFF"));
			m_combox_range.AddString(_T("HAND"));
			m_combox_range.AddString(_T("AUTO"));
			m_combox_range.MoveWindow(rcCell); //移动到选中格的位置，覆盖
			m_combox_range.ShowWindow(SW_SHOW);
			m_combox_range.BringWindowToTop();

			m_combox_range.SetFocus(); //获取焦点
			m_combox_range.SetWindowText(strValue);
		}
		else if (4==lCol)
		{
			m_combox_range.ResetContent();
			m_combox_range.AddString(_T("Enable"));
			m_combox_range.AddString(_T("Disable"));
			m_combox_range.MoveWindow(rcCell); //移动到选中格的位置，覆盖
			m_combox_range.ShowWindow(SW_SHOW);
			m_combox_range.BringWindowToTop();
			m_combox_range.SetFocus(); //获取焦点
			m_combox_range.SetWindowText(strValue);
		}
 
 
}

void CDialgMiniPanel::writedbinputname( int& num,CString& str )
{


	//存入数据库中
	CADO saveADO;
	saveADO.OnInitADOConn();
	CString sql = _T("select * from MiniPanel");
	saveADO.m_pRecordset = saveADO.OpenRecordset(sql);
	CString cstnum;
		try 
		{
			saveADO.m_pRecordset->Move(num,vtMissing);
			saveADO.m_pRecordset->PutCollect("Name",(_bstr_t)str);
			saveADO.m_pRecordset->Update();

		}
		catch(...)
		{
			SetPaneString(2,_T("'Input Name' Write dababase false!"));
			return ;
		}


	vecminipanel.at(num).CStName = str;
	saveADO.CloseRecordset();
	saveADO.CloseConn(); 


}

void CDialgMiniPanel::OnBnClickedButtonweeklyschedule()
{
	KillTimer(MiniPanelTimer);
	if(g_NetWorkLevel==1)
		return;

	g_bPauseMultiRead=TRUE;
	Weekly_Routines dlg;
	dlg.DoModal();

	g_bPauseMultiRead=FALSE;
	SetTimer(MiniPanelTimer,1000,NULL);


}
void CDialgMiniPanel::OnBnClickedButtonannualschedule()
{
	KillTimer(MiniPanelTimer);
	if(g_NetWorkLevel==1)
		return;
	g_bPauseMultiRead=TRUE;
	Annual_Routines dlg;
	dlg.DoModal();
	g_bPauseMultiRead=FALSE;
	SetTimer(MiniPanelTimer,1000,NULL);


}

void CDialgMiniPanel::OnBnClickedButtonidschedule()
{
	KillTimer(MiniPanelTimer);
	if(g_NetWorkLevel==1)
		return;

	g_bPauseMultiRead=TRUE;
	CConfig_Routines dlg;
	dlg.DoModal();
	g_bPauseMultiRead=FALSE;
	SetTimer(MiniPanelTimer,1000,NULL);
}

void CDialgMiniPanel::OnBnClickedButtonClear(){
	if ( AfxMessageBox(_T("Are you sure clear schedules?"),MB_YESNO ,4) == IDYES )
	{
		// 	if (timeserve.CompareNoCase(strTemp)!= 0)
		// 	{

		int iRet = write_one(g_tstat_id,15,85);
		if (iRet>0)

			AfxMessageBox(_T("Clear schedules successful!"));
		else
			AfxMessageBox(_T("Clear schedules failure!\nPlease try again."));

	}
}
//手动刷新
void CDialgMiniPanel::OnBnClickedButtonRefreshAll()
{   if (!is_connect())
     AfxMessageBox(_T("Please check your connection!"));
     return;
    m_prgoressctrl.ShowWindow(TRUE);
    m_prgoressctrl.SetRange(0,86);
	m_prgoressctrl.SetPos(0);

	register_critical_section.Lock();
	for(int i=0;i<86;i++)
	{	
		Read_Multi(g_tstat_id,&multi_register_value_tcp[i*100],i*100,100);
		m_prgoressctrl.SetPos(i);	
	}
	register_critical_section.Unlock();
	m_prgoressctrl.SetPos(86);
	m_prgoressctrl.ShowWindow(FALSE);
	ShowMinipDialog();
}
//获取一个第八位数据，s:system:进制，n;num:这个数是几位的，第N位是1还是0
//n>=N
BOOL CDialgMiniPanel::Get_Data_Bit(UINT Data,int n,int N)
{
	//Data=Data&0FFx;//去掉高八位数据
	//下面是算幂 2的N
	//最大的num位数的数是？ 2~num-1
	// AfxMessageBox(_T("OK"));
	UINT num=1;
	for (int i=1;i<=n;i++)
	{
		num=num*2;
	}
	num=num-1;//最大的num位数
	Data=Data&num;//取得这个n位数是什么 ？
	num=1;
	for (int i=1;i<N;i++)
	{
		num=num*2;
	}
	if (num==(Data&num))//说明是1 
	{
		return TRUE;
	} 
	else
	{
		return FALSE;
	}
}

void CDialgMiniPanel::UpdateData_Input(){
BOOL bit;int i=0;
CString temp;
int value;
UINT reg171=multi_register_value_tcp[171];
UINT reg172=multi_register_value_tcp[172];
//col=2;Enable
if (input_rows<=16)
{
	for( i=1;i<17;i++)
	{
		bit=Get_Data_Bit(reg171,16,i);
		if (bit)
		{
			m_msflexgridinput.put_TextMatrix(i,2,_T("Enable"));
		} 
		else
		{
			m_msflexgridinput.put_TextMatrix(i,2,_T("Disable"));
		}

	}
} 
else
{
	for( i=1;i<17;i++)
	{
		bit=Get_Data_Bit(reg171,16,i);
		if (bit)
		{
			m_msflexgridinput.put_TextMatrix(i,2,_T("Enable"));
		} 
		else
		{
			m_msflexgridinput.put_TextMatrix(i,2,_T("Disable"));
		}

	}
	for ( i=17;i<33;i++)
	{
		bit=Get_Data_Bit(reg172,16,i);
		if (bit)
		{
			m_msflexgridinput.put_TextMatrix(i,2,_T("Enable"));
		} 
		else
		{
			m_msflexgridinput.put_TextMatrix(i,2,_T("Disable"));
		}
	}
}

	//col=3;value,RANGE
	for (i=1;i<=input_rows;i++)
	{
	value=multi_register_value_tcp[8000];
	temp.Format(_T("%d"),value);
	m_msflexgridinput.put_TextMatrix(i,3,temp);
	if (multi_register_value_tcp[8033+i]>=0&&multi_register_value_tcp[8033+i]<=5)
	{
	temp=AINPUT_Range[multi_register_value_tcp[8033+i]];
	} 
	else
	{
	temp=_T("Default");
	}
	m_msflexgridinput.put_TextMatrix(i,4,temp);
	temp.Format(_T("%d"),multi_register_value_tcp[8065+i]);
	m_msflexgridinput.put_TextMatrix(i,5,temp);
	temp.Format(_T("%d"),multi_register_value_tcp[8097+i]);
	m_msflexgridinput.put_TextMatrix(i,6,temp); 
    }
}
void CDialgMiniPanel::UpdateData_AO(){
BOOL bit;int i=0;
CString temp=_T("Default");

 
UINT reg174=multi_register_value_tcp[174];
for (i=1;i<=output_AO;i++)
{
	 temp.Format(_T("%d"),multi_register_value_tcp[134+i]);
	 m_msflexgridAO.put_TextMatrix(i,2,temp);
	int swtch=multi_register_value_tcp[146+12+i];
	if (swtch>=0&&swtch<=2)
	{
		temp=SWITCH_DA[swtch];
	}
	else
	{
		temp=_T("Default");
	}
	m_msflexgridAO.put_TextMatrix(i,3,temp);

	bit=Get_Data_Bit(reg174,12,i);
	if (bit)
	{
		m_msflexgridAO.put_TextMatrix(i,4,_T("Enable"));
	} 
	else
	{
		m_msflexgridAO.put_TextMatrix(i,4,_T("Disable"));
	}
}


}
void CDialgMiniPanel::UpdateData_DO(){
	BOOL bit;int i=0;
	CString temp=_T("Default");

	UINT reg134=multi_register_value_tcp[134];
	UINT reg173=multi_register_value_tcp[173];
	for (i=1;i<=output_DO;i++)
	{
		bit=Get_Data_Bit(reg134,12,i);
		if (bit)
		{
			m_msflexgridDO.put_TextMatrix(i,2,_T("ON"));
		} 
		else
		{
			m_msflexgridDO.put_TextMatrix(i,2,_T("OFF"));
		}
		int swtch=multi_register_value_tcp[146+i];
		if (swtch>=0&&swtch<=2)
		{
			temp=SWITCH_DA[swtch];
		}
		else
		{
			temp=_T("Default");
		}
		m_msflexgridDO.put_TextMatrix(i,3,temp);

		bit=Get_Data_Bit(reg173,12,i);
		if (bit)
		{
			m_msflexgridDO.put_TextMatrix(i,4,_T("Enable"));
		} 
		else
		{
			m_msflexgridDO.put_TextMatrix(i,4,_T("Disable"));
		}
}
}

void CDialgMiniPanel::OnCbnSelchangeRange(){
if (m_Table==1)//input table
{
  if (2==m_curCol)
  {
	  unsigned short temp =1;				
	 
	  int ret =m_combox_range.GetCurSel();/* m_stron.Collate(strValue);*/

	  //参数写入设备
	  //1-代表ON            0-代表OFF
	  //1-代表手动Manual    0-代表自动Auto
	  //174	1	Digital output1 - 8, valves/pumps
	  
	  
	  //temp = temp<<m_lRow;
	  UINT num=1;
	  for (int i=1;i<m_curRow;i++)
	  {
		  num=num*2;
	  }
	  if (m_curRow<=16)
	  {
		  if (ret == 1)//Disable->ENable
		  {

			  temp=multi_register_value_tcp[171];
			  temp=temp+num;//对应的位0->1

			  int ww = write_one(g_tstat_id,171,temp);
			  //TRACE(_T("No:%d = write_one(on/off) is %d\n"),lRow,ww);
			  if (ww>0)
			  {

				  multi_register_value_tcp[171]=temp;
			  }else
			  {

			  }
		  }

		  else//Enable->Disable
		  {

			  temp=multi_register_value_tcp[171];
			  temp=temp-num;//对应的位1->0

			  int ww = write_one(g_tstat_id,171,temp,1);
			  //TRACE(_T("No:%d = write_one(on/off) is %d\n"),lRow,temp);
			  if (ww>0)
			  {

				  multi_register_value_tcp[171]=temp;
			  }
			  else
			  {

			  }
		  }
	  }
	  else
	  {
		  if (ret == 0)//Disable->ENable
		  {

			  temp=multi_register_value_tcp[172];
			  temp=temp+num;//对应的位0->1

			  int ww = write_one(g_tstat_id,172,temp);
			  //TRACE(_T("No:%d = write_one(on/off) is %d\n"),lRow,ww);
			  if (ww>0)
			  {

				  multi_register_value_tcp[172]=temp;
			  }else
			  {

			  }
		  }

		  else//Enable->Disable
		  {

			  temp=multi_register_value_tcp[172];
			  temp=temp-num;//对应的位1->0

			  int ww = write_one(g_tstat_id,172,temp,1);
			  //TRACE(_T("No:%d = write_one(on/off) is %d\n"),lRow,temp);
			  if (ww>0)
			  {

				  multi_register_value_tcp[172]=temp;
			  }
			  else
			  {

			  }
		  }
	  }
	  UpdateData_Input();
  }
  else if (4==m_curCol)
  {
     int sel=m_combox_range.GetCurSel();
	 int ww = write_one(g_tstat_id,8033+m_curRow,sel);
	 //TRACE(_T("No:%d = write_one(on/off) is %d\n"),lRow,ww);
	 if (ww>0)
	 {

		 multi_register_value_tcp[8033+m_curRow]=sel;
	 }else
	 {

	 }

	  UpdateData_Input();
  }

} 
else if (m_Table==2)
{

	if (4==m_curCol)
	{
		 			
		unsigned short temp =1;				

		int ret =m_combox_range.GetCurSel();/* m_stron.Collate(strValue);*/


		//参数写入设备
		//1-代表ON            0-代表OFF
		//1-代表手动Manual    0-代表自动Auto
		//174	1	Digital output1 - 8, valves/pumps


		//temp = temp<<m_lRow;
		UINT num=1;
		for (int i=1;i<m_curRow;i++)
		{
			num=num*2;
		}
		 
			if (ret == 1)//Disable->ENable
			{

				temp=multi_register_value_tcp[173];
				temp=temp+num;//对应的位0->1

				int ww = write_one(g_tstat_id,173,temp);
				//TRACE(_T("No:%d = write_one(on/off) is %d\n"),lRow,ww);
				if (ww>0)
				{

					multi_register_value_tcp[173]=temp;
				}else
				{

				}
			}

			else//Enable->Disable
			{

				temp=multi_register_value_tcp[173];
				temp=temp-num;//对应的位1->0

				int ww = write_one(g_tstat_id,173,temp,1);
				//TRACE(_T("No:%d = write_one(on/off) is %d\n"),lRow,temp);
				if (ww>0)
				{

					multi_register_value_tcp[173]=temp;
				}
				else
				{

				}
			}
		 
	 
		UpdateData_DO();
	}
	else if (3==m_curCol)
	{
		int sel=m_combox_range.GetCurSel();
		int ww = write_one(g_tstat_id,146+m_curRow,sel);
		//TRACE(_T("No:%d = write_one(on/off) is %d\n"),lRow,ww);
		if (ww>0)
		{

			multi_register_value_tcp[146+m_curRow]=sel;
		}else
		{

		}

		UpdateData_DO();
	}


}
else if (m_Table==3)
{
	if (4==m_curCol)
	{

		unsigned short temp =1;				

		int ret =m_combox_range.GetCurSel();/* m_stron.Collate(strValue);*/


		//参数写入设备
		//1-代表ON            0-代表OFF
		//1-代表手动Manual    0-代表自动Auto
		//174	1	Digital output1 - 8, valves/pumps


		//temp = temp<<m_lRow;
		UINT num=1;
		for (int i=1;i<m_curRow;i++)
		{
			num=num*2;
		}

		if (ret == 1)//Disable->ENable
		{

			temp=multi_register_value_tcp[174];
			temp=temp+num;//对应的位0->1

			int ww = write_one(g_tstat_id,174,temp);
			//TRACE(_T("No:%d = write_one(on/off) is %d\n"),lRow,ww);
			if (ww>0)
			{

				multi_register_value_tcp[174]=temp;
			}else
			{

			}
		}

		else//Enable->Disable
		{

			temp=multi_register_value_tcp[174];
			temp=temp-num;//对应的位1->0

			int ww = write_one(g_tstat_id,174,temp,1);
			//TRACE(_T("No:%d = write_one(on/off) is %d\n"),lRow,temp);
			if (ww>0)
			{

				multi_register_value_tcp[174]=temp;
			}
			else
			{

			}
		}


		UpdateData_AO();
	}
	else if (3==m_curCol)
	{
		int sel=m_combox_range.GetCurSel();
		int ww = write_one(g_tstat_id,158+m_curRow,sel);
		//TRACE(_T("No:%d = write_one(on/off) is %d\n"),lRow,ww);
		if (ww>0)
		{

			multi_register_value_tcp[158+m_curRow]=sel;
		}else
		{

		}

		UpdateData_AO();
	}
}
 
}

void CDialgMiniPanel::OnBnClickedButtonSyncwithpc()
{
	// 		200	1	second
	// 		201	1	minute
	// 		202	1	hour
	// 		203	1	day
	// 		204	1	week, 0=Sunday; 1=Monday; and so on.
	// 		205	1	month
	// 		206	1	lower byte of the year, for example, here should be 98 in year 1998
	// 		207	1	higher byte of the year, for example, here should be 19 in the year 1998

	KillTimer(MiniPanelTimer);
	//179 180 181 182
	CString tempyear,tempmonth,tempday,temptime,tempminute;
	CTime now;
	now = CTime::GetCurrentTime();
	tempyear = now.Format(_T("%Y"));
	tempmonth = now.Format(_T("%m"));
	tempday   = now.Format(_T("%d"));
	temptime  = now.Format(_T("%H"));
	tempminute= now.Format(_T("%M"));

	int year,month,day,time,minute;

	year  = atoi((char*)LPCTSTR(tempyear));
	month = atoi((char*)LPCTSTR(tempmonth));
	day   = atoi((char*)LPCTSTR(tempday));
	time  = atoi((char*)LPCTSTR(temptime));
	minute = atoi((char*)LPCTSTR(tempminute));


	year = _ttoi(tempyear);
	month = _ttoi(tempmonth);
	day   = _ttoi(tempday);
	time  = _ttoi(temptime);
	minute = _ttoi(tempminute);

	int yearh,yearl;
	yearl = year%100;
	int tempy = year&0xFF00;
	tempy = tempy>>16;
	yearh = tempy;

	//write_one(g_tstat_id,201,20);
	write_one(g_tstat_id,201,yearl);
	write_one(g_tstat_id,202,month);
	write_one(g_tstat_id,204,day);

	write_one(g_tstat_id,205,time);
	write_one(g_tstat_id,206,minute);

	SetTimer(MiniPanelTimer,1000,NULL);
}