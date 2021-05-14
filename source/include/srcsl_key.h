#ifndef SRCSL_KEY_H_INCLUDED
#define SRCSL_KEY_H_INCLUDED


#ifdef __cplusplus
extern "C"{
#endif

#include "srcslsys.h"

///����״̬
enum SRCSL_KEY_STATE 
{
	SRCSL_KEY_STATE_PRESS,			//!< ��������״̬
	SRCSL_KEY_STATE_UNPRESS			//!< ����̧��״̬
};
///��������
enum SRCSL_KEY_ACTION 
{
	SRCSL_KEY_ACTION_NONE,			//!< �����޶���
	SRCSL_KEY_ACTION_PRESS,			//!< �������¶���
	SRCSL_KEY_ACTION_UNPRESS		//!< ����̧����
};

///��������ģ��
typedef struct
{
    uint8_t state;					//!< ����״̬
	uint8_t last_state;				//!< ��һ�εİ���״̬
    uint8_t action;					//!< ��������
    uint8_t last_real_state;		//!< ��һ�ε�ʵ�ʰ���״̬
} SrcslKey;

/**
* @brief ����ģ���ʼ��
* @param *key ����ģ��ʵ����ָ��
*/
void srcsl_key_init( SrcslKey *key);


/**
* @brief �������£�ͨ����¼״̬���������ü��Ӧ����20ms��ȷ������Ч����
* @param *key		����ģ��ʵ����ָ��
* @param key_state	����״̬����Ӳ����ȡ��ԭʼ���ݣ�
*/
void srcsl_key_update( SrcslKey *key, uint8_t newstate);

/**
* @brief ��ȡ����״̬
* @param *key ����ģ��ʵ����ָ��
*/
uint8_t srcsl_key_get_state( SrcslKey *key);

/**
* @brief ��ȡ��������
* @param *key ����ģ��ʵ����ָ��
*/
uint8_t srcsl_key_get_action( SrcslKey *key);


#ifdef __cplusplus
}
#endif


#endif

