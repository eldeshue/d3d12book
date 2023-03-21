// practice 1
// XMVECTOR ��ü�� �������� ������ �˾ƺ���.
// ��ü�� �Լ��� ������ ������ ȣ��Ծ�, ���� ���� ����� �ؼ�
// ��ü ���Ҹ� Ȱ���� ������ XMFLOATn ��ü�� �̿�
// XMVECTOR ��ü�� �ʱ�ȭ �����

#include <windows.h> // hardware check
#include <DirectXMath.h>	// calculating vector, matrix, ...
#include <DirectXPackedVector.h> // container for calculating vector
#include <iostream>	// stream object

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

// overloading << operator to print XMVECTOR
// ȣ�� �Ծ� ������	XM_CALLCONV �ʼ�
ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v) { // ���ڷ� ���͸� ������ ������ FXMVECTOR ���� �̿��ؾ� ��.
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);	// ����� ���ؼ� v�� dest�� save
	
	os << "(" << dest.x << "," << dest.y << "," << dest.z << ")";
	return os;	// output stream ��ȯ
}

int main() {
	cout.setf(ios_base::boolalpha);	// print bool value literally

	// SSE2 ���� ���θ� Ȯ����
	if (!XMVerifyCPUSupport()) { // �������� �ʴ� ��� ����
		cout << "DirectXMath�� �������� ����" << endl;
		return 0;
	}

	XMVECTOR p = XMVectorZero();	// 0����
	XMVECTOR q = XMVectorSplatOne();	// 1,1,1
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f); // 1,2,3
	XMVECTOR v = XMVectorReplicate(-2.0f); // -2,-2,-2
	XMVECTOR w = XMVectorSplatZ(u); // u.z�� �ʱ�ȭ, �� 3,3,3

	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "u = " << u << endl;
	cout << "v = " << v << endl;
	cout << "w = " << w << endl;

	return 0;
}
