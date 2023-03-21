// practice 1
// XMVECTOR 객체의 기초적인 사용법을 알아본다.
// 객체를 함수에 전달할 때에는 호출규약, 인자 전달 방식을 준수
// 객체 원소를 활요할 때에는 XMFLOATn 객체를 이용
// XMVECTOR 객체의 초기화 방법들

#include <windows.h> // hardware check
#include <DirectXMath.h>	// calculating vector, matrix, ...
#include <DirectXPackedVector.h> // container for calculating vector
#include <iostream>	// stream object

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

// overloading << operator to print XMVECTOR
// 호출 규약 지시자	XM_CALLCONV 필수
ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v) { // 인자로 벡터를 전달할 때에는 FXMVECTOR 등을 이용해야 함.
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);	// 출력을 위해서 v를 dest에 save
	
	os << "(" << dest.x << "," << dest.y << "," << dest.z << ")";
	return os;	// output stream 반환
}

int main() {
	cout.setf(ios_base::boolalpha);	// print bool value literally

	// SSE2 지원 여부를 확인함
	if (!XMVerifyCPUSupport()) { // 지원하지 않는 경우 실행
		cout << "DirectXMath를 지원하지 않음" << endl;
		return 0;
	}

	XMVECTOR p = XMVectorZero();	// 0벡터
	XMVECTOR q = XMVectorSplatOne();	// 1,1,1
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f); // 1,2,3
	XMVECTOR v = XMVectorReplicate(-2.0f); // -2,-2,-2
	XMVECTOR w = XMVectorSplatZ(u); // u.z로 초기화, 즉 3,3,3

	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "u = " << u << endl;
	cout << "v = " << v << endl;
	cout << "w = " << w << endl;

	return 0;
}
