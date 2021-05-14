/**
* @file srcsl_filter.c
* @brief �����˲���
* @author Silonca
*/
#include "include/srcsl_filter.h"


float srcsl_filter_kalman(SrcslFilterKalman * kal, float input)
{
	//Ԥ��Э����̣�kʱ��ϵͳ����Э���� = k-1ʱ�̵�ϵͳЭ���� + ��������Э����
	kal->now = kal->last + kal->process_noise;
	//���������淽�̣����������� = kʱ��ϵͳ����Э���� / ��kʱ��ϵͳ����Э���� + �۲�����Э���
	kal->kalman_gain = kal->now / (kal->now + kal->ob_noise);

	kal->last = (1 - kal->kalman_gain) * kal->now;
	kal->out = kal->out + kal->kalman_gain * (input - kal->out);
	return kal->out;

}
