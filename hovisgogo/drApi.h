#ifndef _DRAPI_H
#define _DRAPI_H

#ifdef __cplusplus
extern "C" {
#endif

// �� Ŭ������ drApi.dll���� ������ ���Դϴ�.
#include <windows.h>
#include <limits.h>

typedef enum EDrModule_t{
	_DR_MODULE_NONE					= 0,
	_DR_MODULE_MOTOR,
	_DR_MODULE_HEADLED,
	_DR_MODULE_CONTROLLER,
	_DR_MODULE_SENSOR,

	_DR_MODULE_MIN			= _DR_MODULE_MOTOR,
	_DR_MODULE_MAX			= _DR_MODULE_SENSOR,
} EDrModule_t;

typedef enum EDrResult_t
{
	_DR_SUCCESS									= 0,
	_DR_NULL_HANDLE,
	_DR_COM_OPEN_FAIL,
	_DR_NULL_DATA_ARG,
	_DR_WRONG_AXIS,

	_DR_SEND_INVALID_ARG_MODULE					= 10,
	_DR_SEND_INVALID_ARG_SIZE,
	_DR_SEND_INVALID_ARG_ID,
	_DR_SEND_INVALID_ARG_CMD,
	_DR_SEND_INVALID_ARG_DATA,
	_DR_SEND_FAIL,

	_DR_RECV_ERR_TIMEOUT						= 20,
	_DR_RECV_ERR_CHECKSUM,
	_DR_RECV_ERR_PACKET_SIZE_TOO_BIG,
	_DR_RECV_ERR_MOTOR_INVALID_CMD,
	_DR_RECV_ERR_MOTOR_INVALID_ID,
	_DR_RECV_ERR_MOTOR_INVALID_SIZE,
	_DR_RECV_ERR_MOTOR_INVALID_REG_RANGE,
	_DR_RECV_ERR_HEADLED_INVALID_CMD,
	_DR_RECV_ERR_HEADLED_INVALID_ID,
	_DR_RECV_ERR_HEADLED_INVALID_SIZE,
	_DR_RECV_ERR_HEADLED_INVALID_REG_RANGE,
	_DR_RECV_ERR_CONTROLLER_INVALID_CMD,
	_DR_RECV_ERR_CONTROLLER_INVALID_ID,
	_DR_RECV_ERR_CONTROLLER_INVALID_SIZE,
	_DR_RECV_ERR_CONTROLLER_INVALID_REG_RANGE,
	_DR_RECV_ERR_SENSOR_INVALID_CMD,
	_DR_RECV_ERR_SENSOR_INVALID_ID,
	_DR_RECV_ERR_SENSOR_INVALID_SIZE,
	_DR_RECV_ERR_SENSOR_INVALID_REG_RANGE,
} EDrResult_t;

// << Common >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> //
__declspec(dllimport) EDrResult_t	dr_common_initialize( HANDLE* hDr );
__declspec(dllimport) EDrResult_t	dr_common_destroy( HANDLE hDr );
__declspec(dllimport) EDrResult_t	dr_common_get_connection( HANDLE hDr, BOOL* pbConnection );
__declspec(dllimport) EDrResult_t	dr_common_connect( HANDLE hDr, const TCHAR* pszPort, DWORD dwBaudRate );
__declspec(dllimport) EDrResult_t	dr_common_disconnect( HANDLE hDr );
__declspec(dllimport) EDrResult_t	dr_common_send( HANDLE hDr, EDrModule_t ETargetModule, BYTE byPacketSize, BYTE byId, BYTE byCmd, BYTE* pbyData );
// << Controller >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> //
////////////////////////////////////////////////////////////////////////////////
// Controller
////////////////////////////////////////////////////////////////////////////////

typedef enum EDrControllerAxis_t
{
	_DR_CONTROLLER_AXIS_X,
	_DR_CONTROLLER_AXIS_Y,
	_DR_CONTROLLER_AXIS_Z,
	_DR_CONTROLLER_AXIS_ALL

} EDrControllerAxis_t;

__declspec(dllimport) EDrResult_t	dr_controller_receive_rom( HANDLE hDr, BYTE byId, BYTE byAddress, BYTE byLength );
__declspec(dllimport) EDrResult_t	dr_controller_get_rom( HANDLE hDr, BYTE byAddress, BYTE byLength, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_send_rom( HANDLE hDr, BYTE byId, BYTE byAddress, BYTE byLength, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram( HANDLE hDr, BYTE byId, BYTE byAddress, BYTE byLength );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram( HANDLE hDr, BYTE byAddress, BYTE byLength, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_send_ram( HANDLE hDr, BYTE byId, BYTE byAddress, BYTE byLength, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_connection_check( HANDLE hDr, BYTE byId, BYTE byLength, BYTE* pbyMotorId );
__declspec(dllimport) EDrResult_t	dr_controller_get_connection_check( HANDLE hDr, BYTE* pbyLength, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_send_play_motion( HANDLE hDr, BYTE byId, BYTE byMotion, BYTE byReady );
__declspec(dllimport) EDrResult_t	dr_controller_send_stop_motion( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_send_play_task( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_send_stop_task( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_receive_debug_task_start( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_receive_debug_task_step( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_debug_task_counter( HANDLE hDr, WORD* pwData );
__declspec(dllimport) EDrResult_t	dr_controller_send_play_ledbuzz( HANDLE hDr, BYTE byId, BYTE byLed, BYTE byBuzz );
__declspec(dllimport) EDrResult_t	dr_controller_receive_stat( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_stat( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_send_rollback( HANDLE hDr, BYTE byId, BYTE byIdSkip, BYTE byBaudSkip );
__declspec(dllimport) EDrResult_t	dr_controller_send_reboot( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_receive_zigbee( HANDLE hDr, BYTE byId, BYTE byInst );
__declspec(dllimport) EDrResult_t	dr_controller_get_zigbee( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_send_remocon( HANDLE hDr, BYTE byId, BYTE byChannel, BYTE byLength, BYTE byData );
__declspec(dllimport) EDrResult_t	dr_controller_send_fw_update( HANDLE hDr, BYTE byId );

__declspec(dllimport) EDrResult_t	dr_controller_receive_rom_version( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_rom_version( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_rom_id( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_rom_id( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_send_rom_id( HANDLE hDr, BYTE byId, BYTE byNewId );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_id( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_id( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_send_ram_id( HANDLE hDr, BYTE byId, BYTE byNewId );
__declspec(dllimport) EDrResult_t	dr_controller_receive_rom_rmc_channel( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_rom_rmc_channel( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_send_rom_rmc_channel( HANDLE hDr, BYTE byId, BYTE byNewChannel );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_rmc_channel( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_rmc_channel( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_send_ram_rmc_channel( HANDLE hDr, BYTE byId, BYTE byNewChannel );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_status( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_status( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_clear_ram_status( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_led_control( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_led_control( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_send_ram_led_control( HANDLE hDr, BYTE byId, BYTE byNewControl );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_zigbee_channel( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_zigbee_channel( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_send_ram_zigbee_channel( HANDLE hDr, BYTE byId, BYTE byNewChannel );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_zigbee_panid( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_zigbee_panid( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_send_ram_zigbee_panid( HANDLE hDr, BYTE byId, WORD wNewPANID );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_zigbee_saddr( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_zigbee_saddr( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_send_ram_zigbee_saddr( HANDLE hDr, BYTE byId, WORD wNewSADDR );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_zigbee_dstaddr( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_zigbee_dstaddr( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_send_ram_zigbee_dstaddr( HANDLE hDr, BYTE byId, WORD wNewDSTADDR );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_zigbee_ackreq( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_zigbee_ackreq( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_send_ram_zigbee_ackreq( HANDLE hDr, BYTE byId, BYTE byNewACKREQ );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_zigbee_backoff( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_zigbee_backoff( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_send_ram_zigbee_backoff( HANDLE hDr, BYTE byId, BYTE byNewBACKOFF );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_servo_count( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_servo_count( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_servo_id( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_servo_id( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_playing_motion( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_playing_motion( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_playing_task( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_playing_task( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_button_status( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_button_status( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_rmc_length( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_rmc_length( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_rmc_data( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_rmc_data( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_voltage( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_voltage( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_temperature( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_temperature( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_light_sensor( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_light_sensor( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_adc1_type( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_adc1_type( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_adc2_type( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_adc2_type( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_adc1_value( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_adc1_value( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_adc2_value( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_adc2_value( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_accgyro_connected( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_accgyro_connected( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_acc_value( HANDLE hDr, BYTE byId, EDrControllerAxis_t EDrAxis );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_acc_value( HANDLE hDr, BYTE* pbyData, EDrControllerAxis_t EDrAxis );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_gyro_value( HANDLE hDr, BYTE byId, EDrControllerAxis_t EDrAxis );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_gyro_value( HANDLE hDr, BYTE* pbyData, EDrControllerAxis_t EDrAxis );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_sound_detection( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_sound_detection( HANDLE hDr, BYTE* pbyData );
__declspec(dllimport) EDrResult_t	dr_controller_receive_ram_sound_direction( HANDLE hDr, BYTE byId );
__declspec(dllimport) EDrResult_t	dr_controller_get_ram_sound_direction( HANDLE hDr, BYTE* pbyData );

// << Timer >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> //
/* ���� - �ݵ�� Init �� �ؾ� ��� �����ϴ� - */
////////////////////////////////////////////////////////////////////////////////
// Timer(Init, Destroy, Set, Get) - Init �� �ؾ� �� �� �ִ� �Լ���...
////////////////////////////////////////////////////////////////////////////////
__declspec(dllimport) char			dr_wait_timer_init(int nCnt);										// ���� ����� ��ŭ(nCnt)�� Ÿ�̸Ӹ� �����Ѵ�. (ex:nCnt = 3 -> 0 ~ 2 ������ Ÿ�̸� ��밡��)
__declspec(dllimport) void			dr_wait_timer_destroy();											// Ÿ�̸� �޸� ���� - �������� �۵� �ȵ�
__declspec(dllimport) void			dr_wait_timer_set(int nIndex);										// timer_get �� ������ set �� �������� �ð��� 0 ���� ����.
__declspec(dllimport) unsigned long	dr_wait_timer_get(int nIndex);										// timer_set �� �� �󸶳� �����°��� Ȯ���ϴ� Ÿ�̸�
__declspec(dllimport) char			dr_wait_timer_check(int nIndex, unsigned long t);					// timer_set �� �� ������ �ð��� �Ǹ� true �� ��ȯ, ��, ���� �߻��� Ȥ�� �ð��� �ȵǸ� false

/* Init �� �ʿ� ����. */
////////////////////////////////////////////////////////////////////////////////
// Time(��,��,��,��,��,��,����ð� ��
// ���� �ð��� 1970�� 1�� 1�� 0�� 0�� 0�� ����... (���н� Ÿ��)
////////////////////////////////////////////////////////////////////////////////
__declspec(dllimport) unsigned long	dr_wait_timer_curr();												// ������ �ð��� ms �� �����ϴ� �Լ�
__declspec(dllimport) int			dr_wait_timer_year();												// ��ǻ���� year �� ����(4�ڸ� ex:2012)
__declspec(dllimport) int			dr_wait_timer_month();												// ��ǻ���� month �� ����
__declspec(dllimport) int			dr_wait_timer_day();												// ��ǻ���� ��¥ �� ����
__declspec(dllimport) int			dr_wait_timer_week();												// ��ǻ���� ���� �� ����(��(0), ��(1), ȭ(2), ��(3), ��(4), ��(5), ��(6))
__declspec(dllimport) int			dr_wait_timer_hour();												// ��ǻ���� �ð� �� ����
__declspec(dllimport) int			dr_wait_timer_minute();												// ��ǻ���� minute �� ����
__declspec(dllimport) int			dr_wait_timer_second();												// ��ǻ���� second �� ����
__declspec(dllimport) int			dr_wait_timer_millisecond();										// ��ǻ���� millisecond �� ����

/* ���� - dr_wait_break �� ��� �� �ݵ�� dr_wait_reset �� �ؾ߸� �ٽ� ����� �����ϴ� - */
////////////////////////////////////////////////////////////////////////////////
// Delay
////////////////////////////////////////////////////////////////////////////////
__declspec(dllimport) void			dr_wait_delay_break();												// ��� ���(wait - dr_wait_delay) �Լ��� Ż���ϵ��� �Ѵ�.
__declspec(dllimport) void			dr_wait_delay_break_once();											// �����ϰ� �ִ� ���(wait - dr_wait_delay) �Լ��� �ѹ� Ż���ϵ��� �Ѵ�.
__declspec(dllimport) void			dr_wait_delay_reset();												// break ������� ����� �� ���� �� delay �Լ��� �ٽ� ��� �����ϰ� �� �ش�.
__declspec(dllimport) void			dr_wait_delay(unsigned long);										// ������ �ð�(ms) ��ŭ �Լ��� ����Ų��.

////////////////////////////////////////////////////////////////////////////////
// Wait Busy
////////////////////////////////////////////////////////////////////////////////
__declspec(dllimport) EDrResult_t	dr_wait_busy( HANDLE hDr, DWORD dwMilliSecond );

// << Motor >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> //
//////// Data ////////
////////////////////////////////////////////////////////////////////////////////
// �ʱ�ȭ �Լ�
////////////////////////////////////////////////////////////////////////////////
__declspec(dllimport) EDrResult_t dr_motor_init(HANDLE hDr);											// ���� ���� �� �ݵ�� �ѹ� ȣ�� �ϴ� �Լ��� ���� �ѹ��� ������ �ָ� �ȴ�.
__declspec(dllimport) void dr_motor_destroy();															// ���� ��� ������ ��, Ȥ�� ���α׷��� �����ϱ� ���� �ݵ�� �ѹ� ȣ�� �� �־�� �ϴ� �Լ�
////////////////////////////////////////////////////////////////////////////////
// �Ķ���� ���� �Լ�
////////////////////////////////////////////////////////////////////////////////
// ���� ID �� ������ AliasID �� �ο�
__declspec(dllimport) void dr_motor_set_param_alias_id(int nID, int nAliasID);							// Ư�� ���̵� AliasID �� �ο��ϴ� �Լ�
__declspec(dllimport) int dr_motor_get_param_alias_id_by_id(int nID);									// �ش� ���̵� �� �Ǿ� �ִ� AliasID�� �������� �Լ�
__declspec(dllimport) void dr_motor_set_param_dir(int nID, char cReverse);								// cReverse = 0(������), cReverse = 1(������)
__declspec(dllimport) char dr_motor_get_param_dir(int nID);												// return value = 0(������), return value = 1(������)
__declspec(dllimport) int dr_motor_get_param_id_by_alias_id(int nAliasID);								// AliasID �� �̿��ؼ� ���� ���̵� ���� ��������

////////////////////////////////////////////////////////////////////////////////
// motor ���� �Լ� ����(led(default-off), mode(default-��ġ����), stop(default-false), evd/angle, 
// noaction(default-true) => ��, dr_motor_set_command_position/angle �� ��ġ�����Լ��� ���� �ڵ����� NoAction = false �� �Ǿ� ���Ͱ� �����Ѵ�.(��, ��ġ���� �ִ� ���� ���ʹ� ���� ���ɻ��°� �ȴ�.)
////////////////////////////////////////////////////////////////////////////////
// ������ �ʱ�ȭ �Լ�
__declspec(dllimport) void dr_motor_set_command_init();													// �������� ��� ���� �ݵ�� ȣ���� �־�� �ϴ� �Լ�. �� �Լ��� ȣ���ϸ� ������ü�� ���µǰ�, Stop ����� �÷��װ� Ŭ���� �ȴ�.
// Data
__declspec(dllimport) void dr_motor_set_command_position(int nID, int nPos);							// Evd ��ġ����� ����ϴ� �Լ�
__declspec(dllimport) void dr_motor_set_command_angle(int nID, float fAngle);							// ������ �̿��� ��ġ����� ����ϴ� �Լ�
__declspec(dllimport) int dr_motor_get_command_position(int nID);										// ���� ����� ������ Evd ���� �о�´�.
__declspec(dllimport) float dr_motor_get_command_angle(int nID);										// ���� ����� ������ Angle ���� �о�´�.
__declspec(dllimport) void dr_motor_set_command_flag(int nID, BOOL bStop, BOOL bMode_Speed, BOOL bLed_Green, BOOL bLed_Blue, BOOL bLed_Red, BOOL bNoAction); // flag ������ �ѹ��� ���� �Ҽ� �ִ� ���(����, ��弳��, LED, NoAction)
__declspec(dllimport) int dr_motor_get_command_flag(int nID);											// ���� ������ flag ������ �ѹ��� �������� ��ɾ�
__declspec(dllimport) void dr_motor_set_command_flag_stop(int nID, BOOL bStop);							// flag ���: ���͵��� ������ �� �Լ��� set(bStop = true) �ϸ� ������ ������ "����"�� ����ȴ�.(��, m_bStop ���κ����� �µǴ� ����� �ƴϴ�. ������ �ϳ��� ����� �����ϴ� �Լ�)
__declspec(dllimport) void dr_motor_set_command_flag_mode(int nID, BOOL bMode_Speed);					// flag ���: ���͵��� ������ �� �Լ��� call �ϸ� ������ �������(0-��ġ, 1-�ӵ�)�� �ٲ��.
__declspec(dllimport) void dr_motor_set_command_flag_led(int nID, BOOL bGreen, BOOL bBlue, BOOL bRed);	// flag ���: ���͵��� ������ �� �Լ��� call �ϸ� ������ LED ���¸� ������ �� �ִ�.
__declspec(dllimport) void dr_motor_set_command_flag_led_green(int nID, BOOL bGreen);					// flag ���: ���͵��� ������ �� �Լ��� call �ϸ� ������ LED ����(���)�� ������ �� �ִ�.
__declspec(dllimport) void dr_motor_set_command_flag_led_blue(int nID, BOOL bBlue);						// flag ���: ���͵��� ������ �� �Լ��� call �ϸ� ������ LED ����(û��)�� ������ �� �ִ�.
__declspec(dllimport) void dr_motor_set_command_flag_led_red(int nID, BOOL bRed);						// flag ���: ���͵��� ������ �� �Լ��� call �ϸ� ������ LED ����(����)�� ������ �� �ִ�.
__declspec(dllimport) void dr_motor_set_command_flag_noaction(int nID, BOOL bNoAction);					// flag ���: ���͵��� ������ �� �Լ��� set(bNoAction = true) �ϸ� ���Ͱ� �������� �ʴ´�.

__declspec(dllimport) BOOL dr_motor_get_command_flag_led_green(int nID);								// flag: ������ LED ���ɻ���(������� �ƴ�) �� ��� ���� ���θ� Ȯ���Ѵ�.
__declspec(dllimport) BOOL dr_motor_get_command_flag_led_blue(int nID);									// flag: ������ LED ���ɻ���(������� �ƴ�) �� û�� ���� ���θ� Ȯ���Ѵ�.
__declspec(dllimport) BOOL dr_motor_get_command_flag_led_red(int nID);									// flag: ������ LED ���ɻ���(������� �ƴ�) �� ���� ���� ���θ� Ȯ���Ѵ�.

__declspec(dllimport) void dr_motor_send_move(HANDLE hDr, int nTime);									// ���� ����: ���� ������ ����, �� ������ ��ɵ��� ���͸� ���۽�Ű�� ���, nTime ms(1/1000s) �� �ӵ��� ����(���� ���۽�)

/* �ʱ�ȭ �Լ� ���� �� ������ �⺻ �������� ���� */
////////////////////////////////////////////////////////////////////////////////
// ����Լ� ����
////////////////////////////////////////////////////////////////////////////////
///////// calc /////////////
__declspec(dllimport) int dr_motor_calc_angle2evd(int nID, float fValue);								// �ش� ������ �������� Evd ������ ������ �ִ� �Լ�
__declspec(dllimport) float dr_motor_calc_evd2angle(int nID, int nValue);								// �ش� ������ Evd ���� ���������� ������ �ִ� �Լ�
__declspec(dllimport) int dr_motor_calc_time2tick(int nTime);											// �ش� ������ �ð���(ms)�� ���� ���Ϳ��� ����ϴ� Tick ������ �����ϴ� �Լ�(1 Tick �� 11.2 ms)
////////////////////////////////////////////////////////////////////////////////
// �� ���� �Լ� ����
////////////////////////////////////////////////////////////////////////////////
//////// Limit ////////
__declspec(dllimport) void dr_motor_set_limit_en(BOOL bOn);												// �� �Լ��� bOn = off(Default On) �� ��� ������ limit �Ķ���� ������ �����Ѵ�. ��, ����Ʈ ���� �����Ѵ�.(������ �� �ⱸ�� �浹 ���� �ʿ�)
__declspec(dllimport) BOOL dr_motor_get_limit_en();														// Limit ������ �Ǿ� �ִ����� Ȯ���ϴ� �Լ�
__declspec(dllimport) int Clip(int nLimitValue_Up, int nLimitValue_Dn, int nData);						// ���������� ����ϴ� �Լ��� clipping �Լ�(����)
__declspec(dllimport) float Clipf(float fLimitValue_Up, float fLimitValue_Dn, float fData);				// ���������� ����ϴ� �Լ��� clipping �Լ�(�Ǽ�)
__declspec(dllimport) int dr_motor_calc_limit_evd(int nID, int nValue);									// evd �� limit ���� ���� �ʰ� Ŭ�����ϴ� �Լ���(�Ķ���� �� �ʿ�-Init �Լ� �ݽ� �⺻ ������ �ȴ�.) nValue �� ���� ������ ������� ���Ϲ޴´�.
__declspec(dllimport) float dr_motor_calc_limit_angle(int nID, float fValue);							// ������ limit ���� ���� �ʰ� Ŭ�����ϴ� �Լ���(�Ķ���� �� �ʿ�-Init �Լ� �ݽ� �⺻ ������ �ȴ�.) fValue �� ���� ������ ������� ���Ϲ޴´�.
/////////////////////

////////////////////////////////////////////////////////////////////////////////
// Stop & Ems & Reset
////////////////////////////////////////////////////////////////////////////////
__declspec(dllimport) BOOL dr_motor_get_status_stop();													// ���� ����� �����Ǿ� �ִ��� Ȯ��(init �Լ� call ��, Ȥ�� ���°����Լ� call �� ���� ��)
__declspec(dllimport) BOOL dr_motor_get_status_Ems();													// ���� ����� �����Ǿ� �ִ��� Ȯ��(���� �� ���� ��)

////////////////////////////////////////////////////////////////////////////////
// Reset ���� �Լ�
////////////////////////////////////////////////////////////////////////////////
__declspec(dllimport) void dr_motor_send_reset(HANDLE hDr, int nID);									// ���Ϳ� reset ����� ������ �Լ�, stop/ems(�������) �� �ʱ�ȭ �ȴ�.
__declspec(dllimport) void dr_motor_set_reset_stop();													// stop �÷��׸� reset �ϴ� �Լ�
__declspec(dllimport) void dr_motor_set_reset_ems();													// ������� ���¸� �����ϴ� �Լ�, �� �Լ��� call �ϸ� ���� ���� ���������� �����ϴ�. ��, ������ ���������� ���ִ� ���� ���� �ʿ��ϴ�.(�ⱸ�� �浹 ��)
__declspec(dllimport) void dr_motor_send_rollback(int nID, BOOL bIgnoreID, BOOL bIgnoreBaudrate);		// ���Ϳ� �����ʱ�ȭ ����� ������ �Լ�, �� �Լ��� call �ϸ� ���� �ǸŻ��·� ���Ͱ� ������ �ȴ�.

////////////////////////////////////////////////////////////////////////////////
__declspec(dllimport) EDrResult_t dr_motor_receive_rom( HANDLE hDr, BYTE byId, BYTE byAddress, BYTE byLength );						// (rom)���Ϳ� �������: �ش� ����(byID)�� byAddress ���� byLength ��ŭ�� �������� ���������� �����ϴ� �Լ� 
__declspec(dllimport) EDrResult_t dr_motor_get_rom( HANDLE hDr, BYTE byAddress, BYTE byLength, BYTE* pbyData );						// (rom)�ö�� ���Ͱ��� Ȯ���ϴ� �Լ�, byAddress ���� byLength ��ŭ�� �������� pbyData �� ����Ͽ� �ش�.
__declspec(dllimport) EDrResult_t dr_motor_send_rom( HANDLE hDr, BYTE byId, BYTE byAddress, BYTE byLength, BYTE* pbyData );			// (rom)���Ϳ� byAddress ���� byLength ��ŭ�� �������� ���� �� �־��ִ� �Լ�
__declspec(dllimport) EDrResult_t dr_motor_receive_ram( HANDLE hDr, BYTE byId, BYTE byAddress, BYTE byLength );						// (ram)���Ϳ� �������: �ش� ����(byID)�� byAddress ���� byLength ��ŭ�� �������� ���������� �����ϴ� �Լ� 
__declspec(dllimport) EDrResult_t dr_motor_get_ram( HANDLE hDr, BYTE byAddress, BYTE byLength, BYTE* pbyData );						// (ram)�ö�� ���Ͱ��� Ȯ���ϴ� �Լ�, byAddress ���� byLength ��ŭ�� �������� pbyData �� ����Ͽ� �ش�.
__declspec(dllimport) EDrResult_t dr_motor_send_ram( HANDLE hDr, BYTE byId, BYTE byAddress, BYTE byLength, BYTE* pbyData );			// (ram)���Ϳ� byAddress ���� byLength ��ŭ�� �������� ���� �� �־��ִ� �Լ�
__declspec(dllimport) EDrResult_t dr_motor_send_command( HANDLE hDr, BYTE byId, BYTE byCommand );									// ���Ϳ� ���� ���: command ��� �ϳ��� ���� �� ���
__declspec(dllimport) EDrResult_t dr_motor_send_ram_one_data( HANDLE hDr, BYTE byId, BYTE byAddress, BYTE byData );					// ���Ϳ� ���� ���: command, �ϳ��� data ����� ���� �� ���
__declspec(dllimport) EDrResult_t dr_motor_send_ram_two_data( HANDLE hDr, BYTE byId, BYTE byAddress, BYTE byData0, BYTE byData1 );	// ���Ϳ� ���� ���: command, �ΰ��� data ����� ���� �� ���
__declspec(dllimport) EDrResult_t dr_motor_send_data( HANDLE hDr, BYTE byId, BYTE byCommand, BYTE byLength, BYTE* pbyData );		// ���Ϳ� ���� ���: command, �������� data ����� ���� �� ���
__declspec(dllimport) EDrResult_t dr_motor_send_driver_servo_on_off(HANDLE hDr, int nID, BYTE byDriverOn, BYTE byServoOn);			// ���Ϳ� ���� ���: Servo/Driver �� On/Off ����

#ifdef __cplusplus
}
#endif

#endif