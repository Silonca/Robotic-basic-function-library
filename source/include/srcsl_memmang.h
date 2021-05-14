#ifndef SRCSL_MEMMANG_H_INCLUDED
#define SRCSL_MEMMANG_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "srcslsys.h"

typedef struct SrcslMemBlock
{
	uint8_t *next;						//!< ��һ���ָ��
	unsigned int size;					//!< ��ǰ��Ĵ�С
} SrcslMemBlock;

typedef struct SrcslMemMang
{
	uint8_t *base;						//!< ��ַ
	unsigned int size;					//!< �ܴ�С
										  
	SrcslMemBlock *start;				//!< ָ���һ���ָ��
	SrcslMemBlock *end;					//!< ָ�����һ���ָ��
										  
	unsigned int consumption;			//!< ʹ����
} SrcslMemMang;


/**
* @brief �ڴ�����ܳ�ʼ��
* @param *m		�ڴ����ṹ��ָ��
* @param *base	�ڴ�ռ�ָ�룬���û�ͨ��uint8_t������ʽ����������
* @paramm size	�ڴ�ռ��С�����û��Խ�����Ĵ�С
*/
void srcsl_memmang_init(SrcslMemMang *m, uint8_t *base, unsigned int size);


/**
* @brief �ڴ���亯�����������malloc
* @param *m		�ڴ����ģ��ָ�룬��ΪNULL�����malloc
* @param size	��Ҫ���ڴ��С����λ���ֽڣ�
* @return ������ڴ�飬����ʧ��ʱ����NULL
*/
void* srcsl_malloc(SrcslMemMang *m, unsigned int size);

/**
* @brief �ڴ��ط��亯����ʵ���������ģ��������realloc
* @attention �÷���realloc��ͬ
* @param *m		�ڴ����ģ��ָ�룬��ΪNULL�����malloc
* @param *pre	Ҫ���·���ռ���ڴ���ָ��
* @param size	��Ҫ���ڴ��С����λ���ֽڣ�
* @return ���·�����ڴ�飬����ʧ��ʱ����NULL
*/
void* srcsl_realloc(SrcslMemMang *m, void *pre, unsigned int size);

/**
* @brief �ڴ��ͷź������������free
* @param *m		�ڴ����ģ��ָ�룬��ΪNULL�����free
* @param *p		֮ǰ������ڴ���ָ��
*/
void srcsl_free(SrcslMemMang *m, void *p);


/**
* @brief ��ȡ�ڴ�ռ�ʹ����
* @param *m		�ڴ����ģ��ָ�룬��ΪNULL�򷵻�0
* @return �ڴ�ռ��ʹ����
*/
float srcsl_get_usage(SrcslMemMang *m);

#ifdef __cplusplus
}
#endif


#endif 

