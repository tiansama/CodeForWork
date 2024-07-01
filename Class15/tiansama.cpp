#include"tiansama.h"

#define version "1.0"

int ave(int a, int b) {
	return (a + b) / 2;
}

namespace tian {
	const char* getversion() {
		const char* str = version;
		return str;
	}
}