#ifndef SRCSL_PID_H_INCLUDED
#define SRCSL_PID_H_INCLUDED

#ifdef __cplusplus
extern "C"{
#endif

#include "srcslsys.h"
#include "srcsl_timer.h"

/// pid����ģʽ
enum SRCSL_PID_MODE
{
    SRCSL_PID_POSITION,					//!< λ��ʽpid
    SRCSL_PID_DELTA						//!< ����ʽpid
};



///pidģ��
typedef struct
{
    uint8_t srcsl_pid_mode;				//!< pid����ģʽ

	float p;							//!< ����
    float i;							//!< ����
    float d;							//!< ΢��
    
    float set;						    //!< Ŀ��ֵ
    float get;						    //!< ����ֵ
	  
    float pout;							//!< ���������
    float iout;							//!< ���������
    float dout;							//!< ΢�������
    float out;                          //!< �����

    float max_out;					    //!< ������������ֵ
    float max_iout;	                    //!< ���ƻ�������������ֵ
	float max_error;                    //!< �����������ֵ
	float deadband;						//!< ������С������������Сֵ��
	
    float error[3];						//!< ��ʷ���ֵ
			
} SrcslPID;


/**
* @brief pidģ���ʼ��
* @param *pid		pidģ��ʵ����ָ��
* @param mode		pid����ģʽ
* - SRCSL_PID_POSITION	λ��ʽpid
* - SRCSL_PID_DELTA		����ʽpid
* @param max_out	������
* @param max_iout	������������
* @param p,i,d		p��i��d��ֵ
*/
void  srcsl_pid_init( SrcslPID *pid, uint8_t mode, float max_out, float max_iout, float p, float i, float d);

/**
* @brief ��pidʵ���ļ��������
* @param *pid pidģ��ʵ����ָ��
*/
void  srcsl_pid_clear( SrcslPID *pid);

/**
* @brief pid����
* @param *pid	pidģ��ʵ����ָ��
* @param get	��ȡֵ
* @param set	�趨ֵ
* @return pid������
*/
float srcsl_pid_calc( SrcslPID *pid, float get, float set);

/**
* @brief �����趨pid����
* @param *pid	pidģ��ʵ����ָ��
* @param p,i,d	p��i��d��ֵ
*/
void  srcsl_pid_reset( SrcslPID *pid, float p, float i, float d);																			


/**
* @brief �������������ֵ
* @param *pid		pidģ��ʵ����ָ��
* @param max_error	���������ֵ�����λ�ȡֵ�Ĳ�ֵ������ͻ�䣩
*/
void srcsl_pid_set_maxerror( SrcslPID *pid, float max_error);  

/**
* @brief ����pid����ʱ��
* @param *pid pidģ��ʵ����ָ��
* @param deadband �����Ĵ�С
*/
void srcsl_pid_set_deadband( SrcslPID *pid, float deadband);

/**
* @brief ��¡pid�����������Ƹ���һ��pidʵ����
* @param *des ���Ƶ�Ŀ��
* @param *scr ���Ƶ���Դ
*/
void srcsl_pid_clone( SrcslPID *des, SrcslPID *src);



#ifdef __cplusplus
}
#endif

#endif // SRCSL_PID_H_INCLUDED
