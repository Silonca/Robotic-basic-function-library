#ifndef SRCSL_FILTER_H_INCLUDED
#define SRCSL_FILTER_H_INCLUDED

typedef struct SrcslFilterKalman {
	float process_noise;			//��������Э���� 
	float ob_noise;					//�۲�����Э����
	float last;						//�ϴι���Э���� 
	float now;						//��ǰ����Э���� ��ʼ��ֵΪ0
	float kalman_gain;				//���������� ��ʼ��ֵΪ0
	float out;						//�������˲������ ��ʼ��ֵΪ0
} SrcslFilterKalman;

/**
* @brief �������˲���
* @param *kal	�������˲���ʵ��ָ��
* @param input	����
* @return �˲������
*/
float srcsl_filter_kalman(SrcslFilterKalman * kal, float input);




#endif