#ifndef SRCSL_ENCODER_H_INCLUDED
#define SRCSL_ENCODER_H_INCLUDED

#ifdef __cplusplus
extern "C"{
#endif

#include "srcslsys.h"

///����������
enum SRCSL_ENCODER_TYPE 
{
	SRCSL_ENCODER_ABSOLUTE,				//!< ���Ա�����
	SRCSL_ENCODER_INCREMENTAL			//!< ����������
};

///������ģ��
typedef struct
{
    uint32_t encoder_type;

    int32_t angle_abs;				//!< ���ԽǶȣ���������ʽ������������ڿ�ʼʱ��λ�ã�
    int32_t angle_sum;				//!< �ۼƽǶ�
    int32_t rounds;					//!< Ȧ��
    int32_t d_value;				//!< ���λ�ȡֵ�Ĳ�ֵ
    int32_t range;					//!< �Ƕȷ�Χ

} SrcslEncoder;

/**
* @brief ��������ʼ��
* @param *encoder		������ʵ����ָ��
* @param encoder_type	����������
* - SRCSL_ENCODER_ABSOLUTE		���Ա�����
* - SRCSL_ENCODER_INCREMENTAL	����������
* @param range			���뷶Χ
*/
void srcsl_encoder_init( SrcslEncoder *encoder, uint32_t encoder_type, uint32_t range);

/**
* @brief ���ñ��������ԽǶ�
* @param *encoder	������ʵ����ָ��
* @param angle_abs	���ԽǶ�
*/
void srcsl_encoder_set_angle_abs( SrcslEncoder *encoder, int32_t angle_abs);

/**
* @brief ���±���������
* @param *encoder	������ʵ����ָ��
* @param angle		��ȡ����ʵ�ʱ������Ƕ�
*/
void srcsl_encoder_updata( SrcslEncoder *encoder, uint32_t angle);

/**
* @brief ��ȡ���������ԽǶ�
* @param *encoder ������ʵ����ָ��
*/
uint32_t srcsl_encoder_get_angle_abs( SrcslEncoder *encoder);

/**
* @brief ��ȡ�������ۻ��Ƕ�
* @param *encoder ������ʵ����ָ��
*/
int32_t srcsl_encoder_get_angle_sum( SrcslEncoder *encoder);

/**
* @brief ��ȡ�������仯��
* @param *encoder ������ʵ����ָ��
*/
int32_t srcsl_encoder_get_d_value( SrcslEncoder *encoder);

/**
* @brief ��¡�����������Ʋ�����
* @param *des Ŀ���������ָ��
* @param *scr Դ��������ָ��
*/
void srcsl_encoder_clone( SrcslEncoder *des, SrcslEncoder *src);

#ifdef __cplusplus
}
#endif

#endif
