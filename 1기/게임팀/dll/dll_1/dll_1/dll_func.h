//�Ͻ���
#pragma once

#ifdef DLL_EXPORTS
#define KK1DLL __declspec(dllexport)
#else
#define KK1DLL __declspec(dllimport)
#endif
/* 
���� DLL_EXPORTS�� ���ǵǾ� �ִٸ�
KK1DLL�� __declspec(dllexport)�� ġȯ�ǰ�
DLL_EXPORTS�� ���ǵǾ� ���� �ʴٸ�
KK1DLL�� __declspec(dllimport)�� ġȯ�ȴ�.

__declspec(dllexport)���� dllexport��?
	�ܺο��� �� �Լ��� ����� �� �ֵ��� dll�� �������ڴٴ� �ǹ��̰�
__declspec(dllimport)���� dllimport��?
	�ܺο��� dll ������ ����� �� �����Ͽ� dll�κ��� �� �Լ��� �����ͼ� ����ϰڴٴ� �ǹ�


*/

extern "C" KK1DLL int Add(int a, int b);
extern "C" KK1DLL int Sub(int a, int b);