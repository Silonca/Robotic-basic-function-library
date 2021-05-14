#ifndef SRCSL_LOG_H_INCLUDED
#define SRCSL_LOG_H_INCLUDED

#ifdef __cplusplus
extern "C"{
#endif

#include "srcslsys.h"
#include <stdarg.h>


/// ��־ģ��
typedef struct 
{
    int8_t msg[SRCSL_STRING_LENGTH_MAX];			//!< �����ݴ���Ϣ
	void (*output_func)(int8_t *msg);				//!< ���������ָ��
} SrcslLog;

/**
* @brief ��־ģ��ʵ����ʼ��
* @param *log			��־ģ��ʵ����ָ��
* @param *output_func	�Զ�������������ָ�룬ͨ�����������ʵ��ͳһ�������ʽ������ض���
*/
void srcsl_log_init( SrcslLog *log, void ( *output_func)(int8_t *msg));

/**
* @brief ���Զ��������������������
* @param *log	��־ģ��ʵ����ָ��
* @param *fmt	Ҫ������ݵĸ�ʽ��ͬprintf��
* @param ...	Ҫ��ʽ��������ͬprintf��
*/
void srcsl_log_write( SrcslLog *log, int8_t *fmt, ...);




#ifdef __cplusplus
}
#endif

#endif
