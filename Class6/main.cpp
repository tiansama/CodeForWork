#include<iostream>

char* readref(const char* ref, const char* cmds) {
	for (int i = 0; cmds[i]; i++) {
		if (cmds[i] == ref[0]) {
			bool bfind = true;
			int x;
			for (x = 0; ref[x]; x++) {
				
				if (ref[x] != cmds[i + x]) {
					bfind = false;
					break;
				}
			}
			if (bfind) {
				return (char*)&cmds[i + x];  //返回的是一个指针
			}
		}
	}
	return nullptr;
}

int main(int argc, char* argv[]) {
    // 打印所有命令行参数以进行调试
    std::cout << "Command line arguments:" << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
    }

    char* id = nullptr;
    char* pass = nullptr;
    char* country = nullptr;
    const char* idref = "id:";
    const char* passref = "pass:";
    const char* countryref = "country:";

    for (int i = 1; i < argc; i++) {
        if (id == nullptr) {
            id = readref(idref, argv[i]);
            if (id != nullptr) continue;
        }
        if (pass == nullptr) {
            pass = readref(passref, argv[i]);
            if (pass != nullptr) continue;
        }
        if (country == nullptr) {
            country = readref(countryref, argv[i]);
            if (country != nullptr) continue;
        }
    }

    std::cout << "id: " << (id ? id : "Not found") << std::endl;
    std::cout << "pass: " << (pass ? pass : "Not found") << std::endl;
    std::cout << "country: " << (country ? country : "Not found") << std::endl;

    return 0;
}