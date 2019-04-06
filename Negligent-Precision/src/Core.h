#ifdef NP_PLATFORM_WINDOWS
#ifdef NP_BUILD_DLL
	#define NP_API __declspec(dllexport)
#else
	#define NP_API __declspec(dllimport) 
#endif
#else
	#error "Negligent Precision only supports Windows at the moment"
#endif