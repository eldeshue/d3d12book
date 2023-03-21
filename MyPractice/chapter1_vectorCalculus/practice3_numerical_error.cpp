// practice 3, numerical error
// 부동 소수점 실수가 정확하게 액면가와 동일하지 않음을 보인다.
// 액면가와 다르므로, 연산을 거치면서 오차가 누적됨을 확인한다.

#include <windows.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

int main() {
	cout.precision(8);

	if (!XMVerifyCPUSupport()) {
		cout << "DirectXMath unavailable." << endl;
		return 0;
	}

	// set
	XMVECTOR u = XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f);
	XMVECTOR n = XMVector3Normalize(u);

	float LU = XMVectorGetX(XMVector3Length(n));

	cout << LU << endl;
	if (LU == 1.0f)
		cout << " length is 1 " << endl;
	else
		cout << " lengthe is not 1 " << endl;

	// 1.0f 를 million 승 하면...
	float powLU = powf(LU, 1.0e6f);
	cout << "LU^(10^6) = " << powLU << endl;

	return 0;
	
}