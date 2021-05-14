#ifndef SRCSL_TIMER_H_INCLUDED
#define SRCSL_TIMER_H_INCLUDED

#ifdef __cplusplus
extern "C"{
#endif

#include "srcslsys.h"

/**
* @struct SrcslTimer
* @brief ��ʱ��
*/
typedef struct
{
    uint32_t time;			//!< ����srcsl_timer_set�ĵ���ʱ��
} SrcslTimer;

/**
* @brief ����ȫ��ʱ��
*/
void srcsl_timer_updata(void);                                   

/**
* @brief ��ʱ��ʼ
* @param ��ʱ��ģ��ָ��
*/
void srcsl_timer_set( SrcslTimer *timer);						 

/**
* @brief ��ȡ�Կ�ʼ������ʱ��
* @param ��ʱ��ģ��ָ��
* @return �ϴε���srcsl_timer_set������ʱ��
*/
uint32_t srcsl_timer_get( SrcslTimer *timer);					 




//-----------------------------------------------------------


enum SRCSL_PLAYER_LIST
{
	SRCSL_PLAYER_LIST_FRAME_OK,					//!< �������б����֡������������
	SRCSL_PLAYER_LIST_END,						//!< �������б������ĩβ
	SRCSL_PLAYER_LIST_FORMAT_ERROR,				//!< �������б������ʽ����
};


enum SRCSL_PLAYER_STATE
{
	SRCSL_PLAYER_PLAYING,						//!< ����������������
	SRCSL_PLAYER_PAUSE,							//!< ��������ͣ
	SRCSL_PLAYER_STOP							//!< ��������ֹ
};


/**
* @struct SrcslActionPlayer
* @brief ����������
*/
typedef struct
{
    SrcslTimer timer;							//!< ��ʱ��
    const char *list;                           //!< ֡��ʽ: ��������(1~255),�ӳ�(1~2^32);

    uint8_t player_state;						//!< ������״̬
	uint8_t analyse_state;						//!< ����״̬
    uint8_t timer_flag;							//!< ��ʱ��������־
    uint16_t list_process;						//!< ���ڽ������ַ���λ��
    uint32_t processing_action;					//!< �����Ķ���
    uint32_t processing_time;					//!< ������ʱ��

    uint8_t ( *analyse_func)( void *);			//!< ����list�ĺ���
    void ( *act_func)(int32_t action_code);		//!< ִ�в����ĺ����������ǷǶ����ͺ�����
} SrcslActionPlayer;


/**
* @brief ������������ʼ��
* @param *player	����������ģ��ָ��
* @param *list		������������
* @param *act_func	ִ�ж����ĺ�����ָ��
*/
void srcsl_player_init( SrcslActionPlayer *player, const char *list, void ( *act_func)( int32_t action_code));

/**
* @brief �������Ž����������ã������Զ������
* @param ����������ģ��ָ��
* @param �Զ���Ľ���������ָ��
*/
void srcsl_player_set_analyse_func( SrcslActionPlayer *player, uint8_t ( *analyse_func)(void *));


/**
* @brief ������������ʼ���źͼ�������
* @param ����������ģ��ָ��
*/
void srcsl_player_start( SrcslActionPlayer *player);                       

/**
* @brief ����������ͣ���ٴο�ʼ��ֱ����ת����һ֡��
* @param ����������ģ��ָ��
*/
void srcsl_player_pause( SrcslActionPlayer *player);                       

/**
* @brief ����������ֹ
* @param ����������ģ��ָ��
*/
void srcsl_player_stop( SrcslActionPlayer *player);                        

/**
* @brief �����������¿�ʼ
* @param ����������ģ��ָ��
*/
void srcsl_player_restart( SrcslActionPlayer *player);                     


/**
* @brief ��������������������Ҫ����������
* @param ����������ģ��ָ��
* @return �������
* @retval SRCSL_PLAYER_LIST_FRAME_OK		 �������б����֡������������
* @retval SRCSL_PLAYER_LIST_END				 �������б������ĩβ
* @retval SRCSL_PLAYER_LIST_FORMAT_ERROR	 �������б������ʽ����
*/
uint8_t srcsl_player_server( SrcslActionPlayer *player);                      

#ifdef __cplusplus
}
#endif


#endif
