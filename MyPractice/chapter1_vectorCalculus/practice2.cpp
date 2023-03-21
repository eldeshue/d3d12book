// practice 2
// 벡터(XMVECTOR)객체에 대한 기본적인 연산을 실습한다.

#include <windows.h> // hardware check
#include <DirectXMath.h>	// calculating vector, matrix, ...
#include <DirectXPackedVector.h> // container for calculating vector
#include <iostream>	// stream object

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v) { // 인자로 벡터를 전달할 때에는 FXMVECTOR 등을 이용해야 함.
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);	// 출력을 위해서 v를 dest에 save
	
	os << "(" << dest.x << "," << dest.y << "," << dest.z << ")";
	return os;	// output stream 반환
}

int main() {
	cout.setf(ios_base::boolalpha);

	if (!XMVerifyCPUSupport()) {
		cout << "DirectMath를 지원하지 않음" << endl;
		return 0;
	}

	XMVECTOR n = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	XMVECTOR v = XMVectorSet(-2.0f, 1.0f, -3.0f, 0.0f);
	XMVECTOR w = XMVectorSet(0.707f, 0.707f, 0.0f, 0.0f);

	XMVECTOR a = u + v;
	XMVECTOR b = u - v;
	XMVECTOR c = 10.0f * u;
	XMVECTOR L = XMVector3Length(u);
	XMVECTOR d = XMVector3Normalize(u);
	XMVECTOR s = XMVector3Dot(u, v);
	XMVECTOR e = XMVector3Cross(u, v);

	XMVECTOR projW;	// projection, 정사영
	XMVECTOR perpW;	// perpendicular, w와 동일한 평면상에서 n과 수직
	XMVector3ComponentsFromNormal(&projW, &perpW, w, n);

	// decide equal or not
	bool equal = XMVector3Equal(projW + perpW, w) != 0;
	bool notEqual = XMVector3NotEqual(projW + perpW, w) != 0;

	// get angle between vectors
	XMVECTOR angleVec = XMVector3AngleBetweenVectors(projW, perpW);
	float angleRadians = XMVectorGetX(angleVec);
	float angleDegrees = XMConvertToDegrees(angleRadians);

	// show
	cout << "u = " << u << endl;
	cout << "v = " << v << endl;
	cout << "w = " << w << endl;
	cout << "n = " << n << endl;
	cout << "a = u + v = " << a << endl;
	cout << "b = u - v = " << b << endl;
	cout << "c = 10 * u = " << c << endl;
	cout << "d = u / ||u|| = " << d << endl;
	cout << "e = u X v = " << e << endl;
	cout << "L = ||u|| = " << L << endl;
	cout << "s = u.v = " << s << endl;
	cout << "projW = " << projW << endl;
	cout << "perpW = " << perpW << endl;
	cout << "projW + perpW == w = " << equal << endl;
	cout << "projW + perpW == w = " << notEqual << endl;
	cout << "angle = " << angleDegrees << endl;

	return 0;
}
