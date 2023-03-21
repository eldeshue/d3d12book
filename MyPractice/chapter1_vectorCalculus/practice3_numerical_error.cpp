// practice 3, numerical error
// �ε� �Ҽ��� �Ǽ��� ��Ȯ�ϰ� �׸鰡�� �������� ������ ���δ�.
// �׸鰡�� �ٸ��Ƿ�, ������ ��ġ�鼭 ������ �������� Ȯ���Ѵ�.

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

	// 1.0f �� million �� �ϸ�...
	float powLU = powf(LU, 1.0e6f);
	cout << "LU^(10^6) = " << powLU << endl;

	return 0;
	
}